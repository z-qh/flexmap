#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"

static double x_PI = 3.14159265358979324 * 3000.0 / 180.0;
static double PI = 3.1415926535897932384626;
static double a = 6378245.0;
static double ee = 0.00669342162296594323;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置webchannel
    map_channel = new QWebChannel(this);
    map_channel->registerObject("qtfun", (QObject*)this);
    ui->map->page()->setWebChannel(map_channel);

    //设置HTML
    QString mapPath = "qrc:/webpage/mainmap.html";
    ui->map->setUrl(QUrl(mapPath));
    //显示地图
    ui->map->show();

    file_node_num = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

//重置地图到大连
void MainWindow::on_pushButton_reset_clicked()
{
    //调用js函数
    ui->map->page()->runJavaScript("reset();");
}

//地图单机事件函数，获取坐标
void MainWindow::get_posi(QString lon, QString lat)
{
    ui->lineEdit_lon->setText(lon);
    ui->lineEdit_lat->setText(lat);
}
double transformlat(double lng,double lat)
{
    double ret= -100.0 + 2.0 * lng + 3.0 * lat + 0.2 * lat * lat + 0.1 * lng * lat + 0.2 * sqrt(abs(lng));
    ret += (20.0 * sin(6.0 * lng * PI) + 20.0 * sin(2.0 * lng * PI)) * 2.0 / 3.0;
    ret += (20.0 * sin(lat * PI) + 40.0 * sin(lat / 3.0 * PI)) * 2.0 / 3.0;
    ret += (160.0 * sin(lat / 12.0 * PI) + 320 * sin(lat * PI / 30.0)) * 2.0 / 3.0;
    return ret;
}
double transformlng(double lng,double lat)
{
    double ret = 300.0 + lng + 2.0 * lat + 0.1 * lng * lng + 0.1 * lng * lat + 0.1 * sqrt(abs(lng));
    ret += (20.0 * sin(6.0 * lng * PI) + 20.0 * sin(2.0 * lng * PI)) * 2.0 / 3.0;
    ret += (20.0 * sin(lng * PI) + 40.0 * sin(lng / 3.0 * PI)) * 2.0 / 3.0;
    ret += (150.0 * sin(lng / 12.0 * PI) + 300.0 * sin(lng / 30.0 * PI)) * 2.0 / 3.0;
    return ret;
}
void wgs84tobd09(double& lng, double& lat)
{
    double dlat = transformlat(lng - 105.0, lat - 35.0);
    double dlng = transformlng(lng - 105.0, lat - 35.0);
    double radlat = lat / 180.0 * PI;
    double magic = sin(radlat);
    magic = 1 - ee * magic * magic;
    double sqrtmagic = sqrt(magic);
    dlat = (dlat * 180.0) / ((a * (1 - ee)) / (magic * sqrtmagic) * PI);
    dlng = (dlng * 180.0) / (a / sqrtmagic * cos(radlat) * PI);
    double mglat = lat + dlat;
    double mglng = lng + dlng;
    //第二次转换
    double z = sqrt(mglng * mglng + mglat * mglat) + 0.00002 * sin(mglat * x_PI);
    double theta = atan2(mglat, mglng) + 0.000003 * cos(mglng * x_PI);
    lng = z * cos(theta) + 0.0065;
    lat = z * sin(theta) + 0.006;
}

//将点存到vector中
void MainWindow::record_point(QString lon, QString lat)
{
    using namespace std;
    std::vector<double> temp;
    double dlon = lon.toDouble();
    double dlat = lat.toDouble();
    wgs84tobd09(dlon, dlat);
    if(dlon == 0 || dlat == 0)
        return ;
    temp.push_back(dlon);
    temp.push_back(dlat);
    node_list.push_back(temp);
}
//打印出现在的点
void MainWindow::show_point()
{
    if(node_list.empty())
        return ;
//    std::stringstream info;
//    for(auto i = 0; i < node_list.size(); i++)
//    {
//        info << "lon:" << node_list[i][0] << endl;
//        info << "lat:" << node_list[i][1] << endl;
//    }
//    QString info_str = QString::fromStdString(info.str());

    QString info_str;
    QString info_temp;
    for(auto i = 0; i < node_list.size(); i++)
    {
        info_temp.sprintf("lon:%10.6f\n", node_list[i][0]);
        info_str += info_temp;
        info_temp.sprintf("lat:%10.6f\n", node_list[i][1]);
        info_str += info_temp;
    }
    ui->textEdit_info->setText(info_str);
}

//右击事件函数，添加点到容器中
void MainWindow::add_posi_to_list(QString lon, QString lat)
{
    record_point(lon, lat);
    show_point();
}

//记录路径点到容器中，并显示，这里转换精度有问题，要控制精度
void MainWindow::on_pushButton_record_node_clicked()
{
    record_point(ui->lineEdit_lon->text(), ui->lineEdit_lat->text());
    show_point();
}

void MainWindow::on_pushButton_clear_node_clicked()
{
    node_list.clear();
    ui->map->page()->runJavaScript("clear_all_marker();");
    ui->textEdit_info->setText("");
}



//测试值传递并且返回值，一个函数处理qt按键，另一个函数处理回调返回值
void MainWindow::on_pushButton_clicked()
{
    QString result = "";
    ui->map->page()->runJavaScript("my_sum(100,10);", [this](const QVariant& v){this->WTM(v.toString());});
}
//测试，回调函数
void MainWindow::WTM(QString str)
{
    ui->textEdit_info->setText(str);
}

void MainWindow::on_pushButton_node_line_clicked()
{
    if(node_list.empty())
        return ;
    QString fun_str;
    for(int i = 0; i < node_list.size() - 1; i++)
    {
        qDebug() << node_list[i][0] << node_list[i][1] << node_list[i+1][0] << node_list[i+1][1];
        fun_str.sprintf("my_polyline(%10.6f,%10.6f,%10.6f,%10.6f);", node_list[i][0], node_list[i][1], node_list[i+1][0], node_list[i+1][1]);
        //ui->textEdit_info->setText(fun_str);
        ui->map->page()->runJavaScript(fun_str);
    }
}

int MainWindow::read_node_file(QString path)
{
    QFile node_file(path);
    if(!node_file.open(QIODevice::ReadOnly))
    {
        return -1;
    }
    QTextStream output(&node_file);
    node_list.clear();
    output >> file_node_num;
    std::vector<double> temp_point;
    double posi_temp_lon;
    double posi_temp_lat;
    for(int i = 0; i < file_node_num; i++)
    {
        output >> posi_temp_lon;
        output >> posi_temp_lat;
        wgs84tobd09(posi_temp_lon, posi_temp_lat);
        temp_point.push_back(posi_temp_lon);
        temp_point.push_back(posi_temp_lat);
        node_list.push_back(temp_point);
        temp_point.clear();
    }
    return file_node_num;
}

void MainWindow::on_pushButton_read_file_and_line_clicked()
{
    QString nodepathFilePath = QFileDialog::getOpenFileName(this,tr("选择文件"),"./",tr("*.txt"));
    nodepathFilePath.toLocal8Bit().constData();
    int file_state = read_node_file(nodepathFilePath);
    if(file_state == -1)
    {
        ui->textEdit_info->setText("文件打开失败");
        return ;
    }
    else
    {
        show_point();
    }
}
