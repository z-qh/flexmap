#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebChannel>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QScriptEngine>
#include <QScriptValue>
#include <QScriptValueList>
#include <QFileDialog>
#include <QLabel>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public:
    QWebChannel* map_channel;
    std::vector<std::vector<double>> node_list;
    int file_node_num;

public:
    void WTM(QString str);
    void record_point(QString lon, QString lat);
    void show_point();
    int read_node_file(QString path);

protected:
    virtual void resizeEvent(QResizeEvent *event) override;

private:
    bool mapStatus = false;

private slots:
    void on_pushButton_reset_clicked();
    void on_pushButton_record_node_clicked();

    void on_pushButton_clear_node_clicked();

    void on_pushButton_clicked();

    void on_pushButton_node_line_clicked();

    void on_pushButton_read_file_and_line_clicked();


public slots:
    void get_posi(QString lon, QString lat);
    void add_posi_to_list(QString lon, QString lat);
};
#endif // MAINWINDOW_H
