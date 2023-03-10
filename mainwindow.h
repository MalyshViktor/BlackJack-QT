#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QImage>
#include"playwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    PlayWindow* playwindow;

private:
    Ui::MainWindow *ui;

private slots:

    void on_startButton_clicked();
    void on_quitButton_clicked();
    void on_actionquitaction_triggered();
    void on_quitaction_triggered();
};
#endif // MAINWINDOW_H
