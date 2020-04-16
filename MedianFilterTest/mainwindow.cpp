#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPixmap"
#include "QImage"
#include "QFileDialog"
#include "QList"
#include <QGuiApplication>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->openResultButton ->setEnabled(false);
    ui->checkPont0_0Button ->setEnabled(false);
    ui->checkPont0_10Button ->setEnabled(false);
    ui->checkPoint10_0Button ->setEnabled(false);
    ui->checkPoin10_10Button ->setEnabled(false);
    ui->checkPoint100_100Button ->setEnabled(false);
    ui->checkPoint200_200Button->setEnabled(false);
    ui->checkRightUpperCornerButton ->setEnabled(false);
    ui->checkLeftBottomCornerButton ->setEnabled(false);
    ui->checkRightBottomCornerButton ->setEnabled(false);
    ui->chekPointRightBoundButton ->setEnabled(false);
    ui->chekPointBottomBoundButton ->setEnabled(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openSourceButton_pressed()
{
    QString fname = QFileDialog::getOpenFileName(this, "Open", qApp->applicationDirPath(), "Images (*.jpg *.bmp *.tif *.png *.gif)");
    if(!QFile(fname).exists())
        return;

    QImage image(fname);
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->openResultButton->setEnabled(true);
    if(!image.isNull()){
        ui->openResultButton ->setEnabled(true);
    };

}

void MainWindow::on_openResultButton_pressed()
{
    QString fname_2 = QFileDialog::getOpenFileName(this, "Open", qApp->applicationDirPath(), "Images (*.jpg *.bmp *.tif *.png)");
    if(!QFile(fname_2).exists())
        return;

    QImage image_2(fname_2);
    ui->label_2->setPixmap(QPixmap::fromImage(image_2));

    if(!image_2.isNull()){
        ui->checkPont0_0Button ->setEnabled(true);
        ui->checkPont0_10Button ->setEnabled(true);
        ui->checkPoint10_0Button ->setEnabled(true);
        ui->checkPoin10_10Button ->setEnabled(true);
        ui->checkRightUpperCornerButton ->setEnabled(true);
        ui->checkLeftBottomCornerButton ->setEnabled(true);
        ui->checkRightBottomCornerButton ->setEnabled(true);
        ui->chekPointRightBoundButton ->setEnabled(true);
        ui->chekPointBottomBoundButton ->setEnabled(true);
        if((image_2.width() > 100) & (image_2.height() > 100)){
            ui->checkPoint100_100Button->setEnabled(true);
        } else {
            ui->checkPoint100_100Button->setEnabled(false);
        };
        if((image_2.width() > 200) & (image_2.height() > 200)){
            ui->checkPoint200_200Button->setEnabled(true);
        } else {
            ui->checkPoint200_200Button->setEnabled(false);
        };
    };
}

void MainWindow::on_quitButton_pressed()
{
    qApp->quit();
}

void MainWindow::on_checkPont0_0Button_pressed()
{
    QImage image1 = ui->label->pixmap()->toImage();

    QImage image2 = ui->label_2->pixmap()->toImage();

    int red1 = 0, green1 = 0, blue1 = 0;

    QList<int> redList;

    redList << qRed(image1.pixel(0, 0))
            << qRed(image1.pixel(0, 0))
            << qRed(image1.pixel(0, 1))

            << qRed(image1.pixel(0, 0))
            << qRed(image1.pixel(0, 0))
            << qRed(image1.pixel(0, 1))

            << qRed(image1.pixel(0, 1))
            << qRed(image1.pixel(0, 1))
            << qRed(image1.pixel(1, 1));

    qSort(redList.begin(), redList.end());

    red1 = redList.at(4);

    // *****************************************************

    QList<int> greenList;

    greenList << qGreen(image1.pixel(0, 0))
              << qGreen(image1.pixel(0, 0))
              << qGreen(image1.pixel(0, 1))

              << qGreen(image1.pixel(0, 0))
              << qGreen(image1.pixel(0, 0))
              << qGreen(image1.pixel(0, 1))

              << qGreen(image1.pixel(0, 1))
              << qGreen(image1.pixel(0, 1))
              << qGreen(image1.pixel(1, 1));


    qSort(greenList.begin(), greenList.end());

    green1 = greenList.at(4);

    // *****************************************************

    QList<int> blueList;

    blueList << qBlue(image1.pixel(0, 0))
             << qBlue(image1.pixel(0, 1))
             << qBlue(image1.pixel(0, 1))

             << qBlue(image1.pixel(0, 0))
             << qBlue(image1.pixel(0, 0))
             << qBlue(image1.pixel(0, 1))

             << qBlue(image1.pixel(0, 1))
             << qBlue(image1.pixel(0, 1))
             << qBlue(image1.pixel(1, 1));

    qSort(blueList.begin(), blueList.end());

    blue1 = blueList.at(4);


    int red2 = 0, green2 = 0, blue2 = 0;
    red2 = qRed(image2.pixel(0, 0));
    green2 = qGreen(image2.pixel(0, 0));
    blue2 = qBlue(image2.pixel(0, 0));

    QString redText, greenText, blueText;

    if (red1 == red2){
        redText = "OK";
    } else {
        redText = "Not Equal";
    };

    if (green1 == green2){
        greenText = "OK";
    } else {
        greenText = "Not Equal";
    };

    if (blue1 == blue2){
        blueText = "OK";
    } else {
        blueText = "Not Equal";
    };

    QString text = " Red - " + redText + ", Green - " + greenText + ", Blue - " + blueText;

    ui->point0_0ResutLabel->setText(text);
}

void MainWindow::on_checkPont0_10Button_pressed()
{
    QImage image1 = ui->label->pixmap()->toImage();

    QImage image2 = ui->label_2->pixmap()->toImage();

    int red1 = 0, green1 = 0, blue1 = 0;

    QList<int> redList;

    redList << qRed(image1.pixel(0, 9))
            << qRed(image1.pixel(0, 9))
            << qRed(image1.pixel(1, 9))

            << qRed(image1.pixel(0, 10))
            << qRed(image1.pixel(0, 10))
            << qRed(image1.pixel(1, 10))

            << qRed(image1.pixel(0, 11))
            << qRed(image1.pixel(0, 11))
            << qRed(image1.pixel(1, 11));

    qSort(redList.begin(), redList.end());

    red1 = redList.at(4);

    // *****************************************************

    QList<int> greenList;

    greenList  << qGreen(image1.pixel(0, 9))
               << qGreen(image1.pixel(0, 9))
               << qGreen(image1.pixel(1, 9))

               << qGreen(image1.pixel(0, 10))
               << qGreen(image1.pixel(0, 10))
               << qGreen(image1.pixel(1, 10))

               << qGreen(image1.pixel(0, 11))
               << qGreen(image1.pixel(0, 11))
               << qGreen(image1.pixel(1, 11));


    qSort(greenList.begin(), greenList.end());

    green1 = greenList.at(4);

    // *****************************************************

    QList<int> blueList;

    blueList << qBlue(image1.pixel(0, 9))
             << qBlue(image1.pixel(0, 9))
             << qBlue(image1.pixel(1, 9))

             << qBlue(image1.pixel(0, 10))
             << qBlue(image1.pixel(0, 10))
             << qBlue(image1.pixel(1, 10))

             << qBlue(image1.pixel(0, 11))
             << qBlue(image1.pixel(0, 11))
             << qBlue(image1.pixel(1, 11));

    qSort(blueList.begin(), blueList.end());

    blue1 = blueList.at(4);


    int red2 = 0, green2 = 0, blue2 = 0;
    red2 = qRed(image2.pixel(0, 10));
    green2 = qGreen(image2.pixel(0, 10));
    blue2 = qBlue(image2.pixel(0, 10));

    QString redText, greenText, blueText;

    if (red1 == red2){
        redText = "OK";
    } else {
        redText = "Not Equal";
    };

    if (green1 == green2){
        greenText = "OK";
    } else {
        greenText = "Not Equal";
    };

    if (blue1 == blue2){
        blueText = "OK";
    } else {
        blueText = "Not Equal";
    };

    QString text = " Red - " + redText + ", Green - " + greenText + ", Blue - " + blueText;

    ui->point0_10ResutLabel->setText(text);
}

void MainWindow::on_checkPoint10_0Button_pressed()
{
    QImage image1 = ui->label->pixmap()->toImage();

    QImage image2 = ui->label_2->pixmap()->toImage();

    int red1 = 0, green1 = 0, blue1 = 0;

    QList<int> redList;

    redList << qRed(image1.pixel(9, 0))
            << qRed(image1.pixel(10, 0))
            << qRed(image1.pixel(11, 0))

            << qRed(image1.pixel(9, 0))
            << qRed(image1.pixel(10, 0))
            << qRed(image1.pixel(11, 0))

            << qRed(image1.pixel(9, 1))
            << qRed(image1.pixel(10, 1))
            << qRed(image1.pixel(11, 1));

    qSort(redList.begin(), redList.end());

    red1 = redList.at(4);

    // *****************************************************

    QList<int> greenList;

    greenList  << qGreen(image1.pixel(9, 0))
               << qGreen(image1.pixel(10, 0))
               << qGreen(image1.pixel(11, 0))

               << qGreen(image1.pixel(9, 0))
               << qGreen(image1.pixel(10, 0))
               << qGreen(image1.pixel(11, 0))

               << qGreen(image1.pixel(9, 1))
               << qGreen(image1.pixel(10, 1))
               << qGreen(image1.pixel(11, 1));


    qSort(greenList.begin(), greenList.end());

    green1 = greenList.at(4);

    // *****************************************************

    QList<int> blueList;

    blueList << qBlue(image1.pixel(9, 0))
             << qBlue(image1.pixel(10, 0))
             << qBlue(image1.pixel(11, 0))

             << qBlue(image1.pixel(9, 0))
             << qBlue(image1.pixel(10, 0))
             << qBlue(image1.pixel(11, 0))

             << qBlue(image1.pixel(9, 1))
             << qBlue(image1.pixel(10, 1))
             << qBlue(image1.pixel(11, 1));

    qSort(blueList.begin(), blueList.end());

    blue1 = blueList.at(4);


    int red2 = 0, green2 = 0, blue2 = 0;
    red2 = qRed(image2.pixel(10, 0));
    green2 = qGreen(image2.pixel(10, 0));
    blue2 = qBlue(image2.pixel(10, 0));

    QString redText, greenText, blueText;

    if (red1 == red2){
        redText = "OK";
    } else {
        redText = "Not Equal";
    };

    if (green1 == green2){
        greenText = "OK";
    } else {
        greenText = "Not Equal";
    };

    if (blue1 == blue2){
        blueText = "OK";
    } else {
        blueText = "Not Equal";
    };

    QString text = " Red - " + redText + ", Green - " + greenText + ", Blue - " + blueText;

    ui->point10_0ResutLabel->setText(text);
}

void MainWindow::on_checkPoin10_10Button_pressed()
{
    QImage image1 = ui->label->pixmap()->toImage();

    QImage image2 = ui->label_2->pixmap()->toImage();

        int red1 = 0, green1 = 0, blue1 = 0;

    QList<int> redList;

    redList << qRed(image1.pixel(9, 9))
            << qRed(image1.pixel(10, 9))
            << qRed(image1.pixel(11, 9))

            << qRed(image1.pixel(9, 10))
            << qRed(image1.pixel(10, 10))
            << qRed(image1.pixel(11, 10))

            << qRed(image1.pixel(9, 11))
            << qRed(image1.pixel(10, 11))
            << qRed(image1.pixel(11, 11));

    qSort(redList.begin(), redList.end());

    red1 = redList.at(4);

    // *****************************************************

    QList<int> greenList;

    greenList << qGreen(image1.pixel(9, 9))
              << qGreen(image1.pixel(10, 9))
              << qGreen(image1.pixel(11, 9))

              << qGreen(image1.pixel(9, 10))
              << qGreen(image1.pixel(10, 10))
              << qGreen(image1.pixel(11, 10))

              << qGreen(image1.pixel(9, 11))
              << qGreen(image1.pixel(10, 11))
              << qGreen(image1.pixel(11, 11));


    qSort(greenList.begin(), greenList.end());

    green1 = greenList.at(4);

    // *****************************************************

    QList<int> blueList;

    blueList << qBlue(image1.pixel(9, 9))
             << qBlue(image1.pixel(10, 9))
             << qBlue(image1.pixel(11, 9))

             << qBlue(image1.pixel(9, 10))
             << qBlue(image1.pixel(10, 10))
             << qBlue(image1.pixel(11, 10))

             << qBlue(image1.pixel(9, 11))
             << qBlue(image1.pixel(10, 11))
             << qBlue(image1.pixel(11, 11));

    qSort(blueList.begin(), blueList.end());

    blue1 = blueList.at(4);


    int red2 = 0, green2 = 0, blue2 = 0;
    red2 = qRed(image2.pixel(10, 10));
    green2 = qGreen(image2.pixel(10, 10));
    blue2 = qBlue(image2.pixel(10, 10));

    QString redText, greenText, blueText;

    if (red1 == red2){
        redText = "OK";
    } else {
        redText = "Not Equal";
    };

    if (green1 == green2){
        greenText = "OK";
    } else {
        greenText = "Not Equal";
    };

    if (blue1 == blue2){
        blueText = "OK";
    } else {
        blueText = "Not Equal";
    };

    QString text = " Red - " + redText + ", Green - " + greenText + ", Blue - " + blueText;

    ui->point10_10ResutLabel->setText(text);
}

void MainWindow::on_checkPoint100_100Button_pressed()
{
    QImage image1 = ui->label->pixmap()->toImage();

    QImage image2 = ui->label_2->pixmap()->toImage();

    int red1 = 0, green1 = 0, blue1 = 0;

    QList<int> redList;

    redList << qRed(image1.pixel(99, 99))
            << qRed(image1.pixel(100, 99))
            << qRed(image1.pixel(101, 99))

            << qRed(image1.pixel(99, 100))
            << qRed(image1.pixel(100, 100))
            << qRed(image1.pixel(101, 100))

            << qRed(image1.pixel(99, 101))
            << qRed(image1.pixel(100, 101))
            << qRed(image1.pixel(101, 101));

    qSort(redList.begin(), redList.end());

    red1 = redList.at(4);

    // *****************************************************

    QList<int> greenList;

    greenList << qGreen(image1.pixel(99, 99))
              << qGreen(image1.pixel(100, 99))
              << qGreen(image1.pixel(101, 99))

              << qGreen(image1.pixel(99, 100))
              << qGreen(image1.pixel(100, 100))
              << qGreen(image1.pixel(101, 100))

              << qGreen(image1.pixel(99, 101))
              << qGreen(image1.pixel(100, 101))
              << qGreen(image1.pixel(101, 101));


    qSort(greenList.begin(), greenList.end());

    green1 = greenList.at(4);

    // *****************************************************

    QList<int> blueList;

    blueList << qBlue(image1.pixel(99, 99))
             << qBlue(image1.pixel(100, 99))
             << qBlue(image1.pixel(101, 99))

             << qBlue(image1.pixel(99, 100))
             << qBlue(image1.pixel(100, 100))
             << qBlue(image1.pixel(101, 100))

             << qBlue(image1.pixel(99, 101))
             << qBlue(image1.pixel(100, 101))
             << qBlue(image1.pixel(101, 101));

    qSort(blueList.begin(), blueList.end());

    blue1 = blueList.at(4);


    int red2 = 0, green2 = 0, blue2 = 0;
    red2 = qRed(image2.pixel(100, 100));
    green2 = qGreen(image2.pixel(100, 100));
    blue2 = qBlue(image2.pixel(100, 100));

    QString redText, greenText, blueText;

    if (red1 == red2){
        redText = "OK";
    } else {
        redText = "Not Equal";
    };

    if (green1 == green2){
        greenText = "OK";
    } else {
        greenText = "Not Equal";
    };

    if (blue1 == blue2){
        blueText = "OK";
    } else {
        blueText = "Not Equal";
    };

    //redText = "Not Equal"; greenText = "Not Equal"; blueText = "Not Equal";

    QString text = " Red - " + redText + ", Green - " + greenText + ", Blue - " + blueText;

    ui->point100_100ResutLabel->setText(text);
}

void MainWindow::on_checkRightUpperCornerButton_pressed()
{
    QImage image1 = ui->label->pixmap()->toImage();

    QImage image2 = ui->label_2->pixmap()->toImage();

    //QImage image1 = image;
    //QImage image2 = image_2;

    int red1 = 0, green1 = 0, blue1 = 0;

    QList<int> redList;

    int l = image1.width()-1, m = 0 ;

    redList << qRed(image1.pixel(l-1, m))
            << qRed(image1.pixel(l, m))
            << qRed(image1.pixel(l, m))

            << qRed(image1.pixel(l-1, m))
            << qRed(image1.pixel(l, m))
            << qRed(image1.pixel(l, m))

            << qRed(image1.pixel(l-1, m+1))
            << qRed(image1.pixel(l, m+1))
            << qRed(image1.pixel(l, m+1));

    qSort(redList.begin(), redList.end());

    red1 = redList.at(4);

    // *****************************************************

    QList<int> greenList;

    greenList << qGreen(image1.pixel(l-1, m))
              << qGreen(image1.pixel(l, m))
              << qGreen(image1.pixel(l, m))

              << qGreen(image1.pixel(l-1, m))
              << qGreen(image1.pixel(l, m))
              << qGreen(image1.pixel(l, m))

              << qGreen(image1.pixel(l-1, m+1))
              << qGreen(image1.pixel(l, m+1))
              << qGreen(image1.pixel(l, m+1));


    qSort(greenList.begin(), greenList.end());

    green1 = greenList.at(4);

    // *****************************************************

    QList<int> blueList;

    blueList << qBlue(image1.pixel(l-1, m))
             << qBlue(image1.pixel(l, m))
             << qBlue(image1.pixel(l, m))

             << qBlue(image1.pixel(l-1, m))
             << qBlue(image1.pixel(l, m))
             << qBlue(image1.pixel(l, m))

             << qBlue(image1.pixel(l-1, m+1))
             << qBlue(image1.pixel(l, m+1))
             << qBlue(image1.pixel(l, m+1));

    qSort(blueList.begin(), blueList.end());

    blue1 = blueList.at(4);


    int red2 = 0, green2 = 0, blue2 = 0;
    red2 = qRed(image2.pixel(l, 0));
    green2 = qGreen(image2.pixel(l, 0));
    blue2 = qBlue(image2.pixel(l, 0));

    QString redText, greenText, blueText;

    if (red1 == red2){
        redText = "OK";
    } else {
        redText = "Not Equal";
    };

    if (green1 == green2){
        greenText = "OK";
    } else {
        greenText = "Not Equal";
    };

    if (blue1 == blue2){
        blueText = "OK";
    } else {
        blueText = "Not Equal";
    };

    QString text = " Red - " + redText + ", Green - " + greenText + ", Blue - " + blueText;

    ui->RightUpCornerLabel->setText(text);
}

void MainWindow::on_checkLeftBottomCornerButton_pressed()
{
    QImage image1 = ui->label->pixmap()->toImage();

    QImage image2 = ui->label_2->pixmap()->toImage();

    int red1 = 0, green1 = 0, blue1 = 0;

    QList<int> redList;

    int l = 0, m = image1.height()-1;

    redList << qRed(image1.pixel(l, m-1))
            << qRed(image1.pixel(l, m-1))
            << qRed(image1.pixel(l+1, m-1))

            << qRed(image1.pixel(l, m))
            << qRed(image1.pixel(l, m))
            << qRed(image1.pixel(l+1, m))

            << qRed(image1.pixel(l, m))
            << qRed(image1.pixel(l, m))
            << qRed(image1.pixel(l+1, m));

    qSort(redList.begin(), redList.end());

    red1 = redList.at(4);

    // *****************************************************

    QList<int> greenList;

    greenList << qGreen(image1.pixel(l, m-1))
              << qGreen(image1.pixel(l, m-1))
              << qGreen(image1.pixel(l+1, m-1))

              << qGreen(image1.pixel(l, m))
              << qGreen(image1.pixel(l, m))
              << qGreen(image1.pixel(l+1, m))

              << qGreen(image1.pixel(l, m))
              << qGreen(image1.pixel(l, m))
              << qGreen(image1.pixel(l+1, m));



    qSort(greenList.begin(), greenList.end());

    green1 = greenList.at(4);

    // *****************************************************

    QList<int> blueList;

    blueList << qBlue(image1.pixel(l, m-1))
             << qBlue(image1.pixel(l, m-1))
             << qBlue(image1.pixel(l+1, m-1))

             << qBlue(image1.pixel(l, m))
             << qBlue(image1.pixel(l, m))
             << qBlue(image1.pixel(l+1, m))

             << qBlue(image1.pixel(l, m))
             << qBlue(image1.pixel(l, m))
             << qBlue(image1.pixel(l+1, m));

    qSort(blueList.begin(), blueList.end());

    blue1 = blueList.at(4);


    int red2 = 0, green2 = 0, blue2 = 0;
    red2 = qRed(image2.pixel(l, m));
    green2 = qGreen(image2.pixel(l, m));
    blue2 = qBlue(image2.pixel(l, m));

    QString redText, greenText, blueText;

    if (red1 == red2){
        redText = "OK";
    } else {
        redText = "Not Equal";
    };

    if (green1 == green2){
        greenText = "OK";
    } else {
        greenText = "Not Equal";
    };

    if (blue1 == blue2){
        blueText = "OK";
    } else {
        blueText = "Not Equal";
    };

    QString text = " Red - " + redText + ", Green - " + greenText + ", Blue - " + blueText;

    ui->LeftBottomCornerLabel->setText(text);
}

void MainWindow::on_checkRightBottomCornerButton_pressed()
{
    QImage image1 = ui->label->pixmap()->toImage();

    QImage image2 = ui->label_2->pixmap()->toImage();

    int red1 = 0, green1 = 0, blue1 = 0;

    QList<int> redList;

    int l = image1.width()-1, m = 0 ;

    l = image1.width()-1, m = image1.height()-1;

    redList << qRed(image1.pixel(l-1, m-1))
            << qRed(image1.pixel(l, m-1))
            << qRed(image1.pixel(l, m-1))

            << qRed(image1.pixel(l-1, m))
            << qRed(image1.pixel(l, m))
            << qRed(image1.pixel(l, m))

            << qRed(image1.pixel(l-1, m))
            << qRed(image1.pixel(l, m))
            << qRed(image1.pixel(l, m));



    qSort(redList.begin(), redList.end());

    red1 = redList.at(4);

    // *****************************************************

    QList<int> greenList;

    greenList << qGreen(image1.pixel(l-1, m-1))
              << qGreen(image1.pixel(l, m-1))
              << qGreen(image1.pixel(l, m-1))

              << qGreen(image1.pixel(l-1, m))
              << qGreen(image1.pixel(l, m))
              << qGreen(image1.pixel(l, m))

              << qGreen(image1.pixel(l-1, m))
              << qGreen(image1.pixel(l, m))
              << qGreen(image1.pixel(l, m));


    qSort(greenList.begin(), greenList.end());

    green1 = greenList.at(4);

    // *****************************************************

    QList<int> blueList;

    blueList << qBlue(image1.pixel(l-1, m-1))
             << qBlue(image1.pixel(l, m-1))
             << qBlue(image1.pixel(l, m-1))

             << qBlue(image1.pixel(l-1, m))
             << qBlue(image1.pixel(l, m))
             << qBlue(image1.pixel(l, m))

             << qBlue(image1.pixel(l-1, m))
             << qBlue(image1.pixel(l, m))
             << qBlue(image1.pixel(l, m));

    qSort(blueList.begin(), blueList.end());

    blue1 = blueList.at(4);


    int red2 = 0, green2 = 0, blue2 = 0;
    red2 = qRed(image2.pixel(l, m));
    green2 = qGreen(image2.pixel(l, m));
    blue2 = qBlue(image2.pixel(l, m));

    QString redText, greenText, blueText;

    if (red1 == red2){
        redText = "OK";
    } else {
        redText = "Not Equal";
    };

    if (green1 == green2){
        greenText = "OK";
    } else {
        greenText = "Not Equal";
    };

    if (blue1 == blue2){
        blueText = "OK";
    } else {
        blueText = "Not Equal";
    };

    QString text = " Red - " + redText + ", Green - " + greenText + ", Blue - " + blueText;

    ui->checkRightBottomLabel->setText(text);
}

void MainWindow::on_chekPointRightBoundButton_pressed()
{
    QImage image1 = ui->label->pixmap()->toImage();

    QImage image2 = ui->label_2->pixmap()->toImage();

    int red1 = 0, green1 = 0, blue1 = 0;

    QList<int> redList;

    int l = image1.width()-1;
    int m = 10;

    redList << qRed(image1.pixel(l-1, m-1))
            << qRed(image1.pixel(l, m-1))
            << qRed(image1.pixel(l, m-1))

            << qRed(image1.pixel(l-1, m))
            << qRed(image1.pixel(l, m))
            << qRed(image1.pixel(l, m))

            << qRed(image1.pixel(l-1, m+1))
            << qRed(image1.pixel(l, m+1))
            << qRed(image1.pixel(l, m+1));



    qSort(redList.begin(), redList.end());

    red1 = redList.at(4);

    // *****************************************************

    QList<int> greenList;

    greenList << qGreen(image1.pixel(l-1, m-1))
              << qGreen(image1.pixel(l, m-1))
              << qGreen(image1.pixel(l, m-1))

              << qGreen(image1.pixel(l-1, m))
              << qGreen(image1.pixel(l, m))
              << qGreen(image1.pixel(l, m))

              << qGreen(image1.pixel(l-1, m+1))
              << qGreen(image1.pixel(l, m+1))
              << qGreen(image1.pixel(l, m+1));


    qSort(greenList.begin(), greenList.end());

    green1 = greenList.at(4);

    // *****************************************************

    QList<int> blueList;

    blueList << qBlue(image1.pixel(l-1, m-1))
             << qBlue(image1.pixel(l, m-1))
             << qBlue(image1.pixel(l, m-1))

             << qBlue(image1.pixel(l-1, m))
             << qBlue(image1.pixel(l, m))
             << qBlue(image1.pixel(l, m))

             << qBlue(image1.pixel(l-1, m+1))
             << qBlue(image1.pixel(l, m+1))
             << qBlue(image1.pixel(l, m+1));

    qSort(blueList.begin(), blueList.end());

    blue1 = blueList.at(4);


    int red2 = 0, green2 = 0, blue2 = 0;
    red2 = qRed(image2.pixel(l, m));
    green2 = qGreen(image2.pixel(l, m));
    blue2 = qBlue(image2.pixel(l, m));

    QString redText, greenText, blueText;

    if (red1 == red2){
        redText = "OK";
    } else {
        redText = "Not Equal";
    };

    if (green1 == green2){
        greenText = "OK";
    } else {
        greenText = "Not Equal";
    };

    if (blue1 == blue2){
        blueText = "OK";
    } else {
        blueText = "Not Equal";
    };

    QString text = " Red - " + redText + ", Green - " + greenText + ", Blue - " + blueText;

    ui->checkPointRightBoundLabel->setText(text);
}

void MainWindow::on_chekPointBottomBoundButton_pressed()
{
    QImage image1 = ui->label->pixmap()->toImage();

    QImage image2 = ui->label_2->pixmap()->toImage();

    int red1 = 0, green1 = 0, blue1 = 0;

    QList<int> redList;

    int l = 10;
    int m = image1.height()-1;


    redList << qRed(image1.pixel(l-1, m-1))
            << qRed(image1.pixel(l, m-1))
            << qRed(image1.pixel(l+1, m-1))

            << qRed(image1.pixel(l-1, m))
            << qRed(image1.pixel(l, m))
            << qRed(image1.pixel(l+1, m))

            << qRed(image1.pixel(l-1, m))
            << qRed(image1.pixel(l, m))
            << qRed(image1.pixel(l+1, m));



    qSort(redList.begin(), redList.end());

    red1 = redList.at(4);

    // *****************************************************

    QList<int> greenList;

    greenList << qGreen(image1.pixel(l-1, m-1))
              << qGreen(image1.pixel(l, m-1))
              << qGreen(image1.pixel(l+1, m-1))

              << qGreen(image1.pixel(l-1, m))
              << qGreen(image1.pixel(l, m))
              << qGreen(image1.pixel(l+1, m))

              << qGreen(image1.pixel(l-1, m))
              << qGreen(image1.pixel(l, m))
              << qGreen(image1.pixel(l+1, m));

    qSort(greenList.begin(), greenList.end());

    green1 = greenList.at(4);

    // *****************************************************

    QList<int> blueList;

    blueList << qBlue(image1.pixel(l-1, m-1))
             << qBlue(image1.pixel(l, m-1))
             << qBlue(image1.pixel(l+1, m-1))

             << qBlue(image1.pixel(l-1, m))
             << qBlue(image1.pixel(l, m))
             << qBlue(image1.pixel(l+1, m))

             << qBlue(image1.pixel(l-1, m))
             << qBlue(image1.pixel(l, m))
             << qBlue(image1.pixel(l+1, m));

    qSort(blueList.begin(), blueList.end());

    blue1 = blueList.at(4);


    int red2 = 0, green2 = 0, blue2 = 0;
    red2 = qRed(image2.pixel(l, m));
    green2 = qGreen(image2.pixel(l, m));
    blue2 = qBlue(image2.pixel(l, m));

    QString redText, greenText, blueText;

    if (red1 == red2){
        redText = "OK";
    } else {
        redText = "Not Equal";
    };

    if (green1 == green2){
        greenText = "OK";
    } else {
        greenText = "Not Equal";
    };

    if (blue1 == blue2){
        blueText = "OK";
    } else {
        blueText = "Not Equal";
    };

    QString text = " Red - " + redText + ", Green - " + greenText + ", Blue - " + blueText;

    ui->checkPointBottomBoundLabel->setText(text);
}

void MainWindow::on_checkPoint200_200Button_pressed()
{
    QImage image1 = ui->label->pixmap()->toImage();

    QImage image2 = ui->label_2->pixmap()->toImage();

    int red1 = 0, green1 = 0, blue1 = 0;

    QList<int> redList;

    redList << qRed(image1.pixel(199, 199))
            << qRed(image1.pixel(200, 199))
            << qRed(image1.pixel(201, 199))

            << qRed(image1.pixel(199, 200))
            << qRed(image1.pixel(200, 200))
            << qRed(image1.pixel(201, 200))

            << qRed(image1.pixel(199, 201))
            << qRed(image1.pixel(200, 201))
            << qRed(image1.pixel(201, 201));

    qSort(redList.begin(), redList.end());

    red1 = redList.at(4);

    // *****************************************************

    QList<int> greenList;

    greenList << qGreen(image1.pixel(199, 199))
              << qGreen(image1.pixel(200, 199))
              << qGreen(image1.pixel(201, 199))

              << qGreen(image1.pixel(199, 200))
              << qGreen(image1.pixel(200, 200))
              << qGreen(image1.pixel(201, 200))

              << qGreen(image1.pixel(199, 201))
              << qGreen(image1.pixel(200, 201))
              << qGreen(image1.pixel(201, 201));


    qSort(greenList.begin(), greenList.end());

    green1 = greenList.at(4);

    // *****************************************************

    QList<int> blueList;

    blueList << qBlue(image1.pixel(199, 199))
             << qBlue(image1.pixel(200, 199))
             << qBlue(image1.pixel(201, 199))

             << qBlue(image1.pixel(199, 200))
             << qBlue(image1.pixel(200, 200))
             << qBlue(image1.pixel(201, 200))

             << qBlue(image1.pixel(199, 201))
             << qBlue(image1.pixel(200, 201))
             << qBlue(image1.pixel(201, 201));

    qSort(blueList.begin(), blueList.end());

    blue1 = blueList.at(4);


    int red2 = 0, green2 = 0, blue2 = 0;
    red2 = qRed(image2.pixel(200, 200));
    green2 = qGreen(image2.pixel(200, 200));
    blue2 = qBlue(image2.pixel(200, 200));

    QString redText, greenText, blueText;

    if (red1 == red2){
        redText = "OK";
    } else {
        redText = "Not Equal";
    };

    if (green1 == green2){
        greenText = "OK";
    } else {
        greenText = "Not Equal";
    };

    if (blue1 == blue2){
        blueText = "OK";
    } else {
        blueText = "Not Equal";
    };

    //redText = "Not Equal"; greenText = "Not Equal"; blueText = "Not Equal";

    QString text = " Red - " + redText + ", Green - " + greenText + ", Blue - " + blueText;

    ui->point200_200ResutLabel->setText(text);
}

void MainWindow::on_clearResultsButton_pressed()
{
    QString text ="";
    ui->point0_0ResutLabel->setText(text);
    ui->point0_10ResutLabel->setText(text);
    ui->point10_0ResutLabel->setText(text);
    ui->point10_10ResutLabel->setText(text);
    ui->point100_100ResutLabel->setText(text);
    ui->RightUpCornerLabel->setText(text);
    ui->LeftBottomCornerLabel->setText(text);
    ui->checkRightBottomLabel->setText(text);
    ui->checkPointRightBoundLabel->setText(text);
    ui->checkPointBottomBoundLabel->setText(text);
    ui->point200_200ResutLabel->setText(text);
}
