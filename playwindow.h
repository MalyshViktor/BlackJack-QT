#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QMediaPlayer>

namespace Ui {
class PlayWindow;
}
class MainWindow;

class PlayWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlayWindow(MainWindow *parent = nullptr);
    ~PlayWindow();

private slots:
    void dealer();
    void end();
    void on_dealButton_clicked();

    void on_hitButton_clicked();

    void on_standButton_clicked();

    void on_actionquit_triggered();

private:
    Ui::PlayWindow *ui;
    MainWindow* parent;

};

#endif // PLAYWINDOW_H
