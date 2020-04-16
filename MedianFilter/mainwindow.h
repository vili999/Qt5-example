#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:

    void on_openButton_pressed();

    void on_applyFilterButton_pressed();

    void on_saveAsButton_pressed();

    void on_quitButton_pressed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
