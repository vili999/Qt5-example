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

    void on_quitButton_pressed();

    void on_openSourceButton_pressed();

    void on_openResultButton_pressed();

    void on_checkPont0_0Button_pressed();

    void on_checkPont0_10Button_pressed();

    void on_checkPoint10_0Button_pressed();

    void on_checkPoin10_10Button_pressed();

    void on_checkPoint100_100Button_pressed();

    void on_checkRightUpperCornerButton_pressed();

    void on_checkLeftBottomCornerButton_pressed();

    void on_checkRightBottomCornerButton_pressed();

    void on_chekPointRightBoundButton_pressed();

    void on_chekPointBottomBoundButton_pressed();

    void on_checkPoint200_200Button_pressed();

    void on_clearResultsButton_pressed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
