#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "imagechanger.h"
#include "QPixmap"
#include "QImage"
#include "QFileDialog"
#include "QList"
#include <QtConcurrent>
#include <QtConcurrentMap>
#include <QProgressDialog>
#include <qtconcurrentmap.h>
#include <QRect>
#include <QTimer>
#include <QMessageBox>
#include <QThread>
#include <QDebug>
#include <QGuiApplication>
#include <QtTest>

QImage operation(const QImage &image)
{
    const int work = 1000 * 1000 * 20;
    volatile int v = 0;
    for (int j = 0; j < work; ++j)
        ++v;

    return ImageChanger::addMedianFilterMP(image);
    //For Test next row
    //return ImageChanger::addMedianFilterTest(image);
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->applyFilterButton ->setEnabled(false);
    ui->saveAsButton ->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_openButton_pressed()
{
    QString fname = QFileDialog::getOpenFileName(this, "Open", qApp->applicationDirPath(), "Images (*.jpg *.bmp *.tif *.png *.gif)");
    if(!QFile(fname).exists())
        return;

    QImage image(fname);
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->applyFilterButton ->setEnabled(true);
    ui->saveAsButton ->setEnabled(true);

}

void MainWindow::on_applyFilterButton_pressed()
{


QImage image = ui->label->pixmap()->toImage();

if(image.isNull())
    return;

    int threadCount = QThread::idealThreadCount();

    if (threadCount == 1 ) {

        QImage resultImage = ImageChanger::addMedianFilter(image);

        ui->label_2->setPixmap(QPixmap::fromImage(resultImage));

    } else
    {

    int u = image.width()/31;
    int v = image.width() - u;

    QImage image0  = image.copy(0,0,u+1,image.height());
    QImage image1  = image.copy(u-1,0,2*u+2,image.height());
    QImage image2  = image.copy(2*u-1,0,3*u+2,image.height());
    QImage image3  = image.copy(3*u-1,0,4*u+2,image.height());
    QImage image4  = image.copy(4*u-1,0,5*u+2,image.height());
    QImage image5  = image.copy(5*u-1,0,6*u+2,image.height());
    QImage image6  = image.copy(6*u-1,0,7*u+2,image.height());
    QImage image7  = image.copy(7*u-1,0,8*u+2,image.height());
    QImage image8  = image.copy(8*u-1,0,9*u+2,image.height());
    QImage image9  = image.copy(9*u-1,0,10*u+2,image.height());
    QImage image10  = image.copy(10*u-1,0,11*u+2,image.height());
    QImage image11  = image.copy(11*u-1,0,12*u+2,image.height());
    QImage image12  = image.copy(12*u-1,0,13*u+2,image.height());
    QImage image13  = image.copy(13*u-1,0,14*u+2,image.height());
    QImage image14  = image.copy(14*u-1,0,15*u+2,image.height());
    QImage image15  = image.copy(15*u-1,0,16*u+2,image.height());
    QImage image16  = image.copy(16*u-1,0,17*u+2,image.height());
    QImage image17  = image.copy(17*u-1,0,18*u+2,image.height());
    QImage image18  = image.copy(18*u-1,0,19*u+2,image.height());
    QImage image19  = image.copy(19*u-1,0,20*u+2,image.height());
    QImage image20  = image.copy(20*u-1,0,21*u+2,image.height());
    QImage image21  = image.copy(21*u-1,0,22*u+2,image.height());
    QImage image22  = image.copy(22*u-1,0,23*u+2,image.height());
    QImage image23  = image.copy(23*u-1,0,24*u+2,image.height());
    QImage image24  = image.copy(24*u-1,0,25*u+2,image.height());
    QImage image25  = image.copy(25*u-1,0,26*u+2,image.height());
    QImage image26  = image.copy(26*u-1,0,27*u+2,image.height());
    QImage image27  = image.copy(27*u-1,0,28*u+2,image.height());
    QImage image28  = image.copy(28*u-1,0,29*u+2,image.height());
    QImage image29  = image.copy(29*u-1,0,30*u+2,image.height());
    QImage image30  = image.copy(30*u-1,0,31*u+2,image.height());
    QImage image31  = image.copy(31*u-1,0,v+1,image.height());


    QList<QImage> listImages;

    listImages.append(image0);
    listImages.append(image1);
    listImages.append(image2);
    listImages.append(image3);
    listImages.append(image4);
    listImages.append(image5);
    listImages.append(image6);
    listImages.append(image7);
    listImages.append(image8);
    listImages.append(image9);
    listImages.append(image10);
    listImages.append(image11);
    listImages.append(image12);
    listImages.append(image13);
    listImages.append(image14);
    listImages.append(image15);
    listImages.append(image16);
    listImages.append(image17);
    listImages.append(image18);
    listImages.append(image19);
    listImages.append(image20);
    listImages.append(image21);
    listImages.append(image22);
    listImages.append(image23);
    listImages.append(image24);
    listImages.append(image25);
    listImages.append(image26);
    listImages.append(image27);
    listImages.append(image28);
    listImages.append(image29);
    listImages.append(image30);
    listImages.append(image31);





//++++++++++++++++++++++++++++++++++++++++++++++

    QProgressDialog dialog;
    dialog.setLabelText(QString("Progressing using %1 thread(s)...").arg(QThread::idealThreadCount()));



    // Create a QFutureWatcher and connect signals and slots.
    QFutureWatcher<void> futureWatcher;
    QObject::connect(&futureWatcher, SIGNAL(finished()), &dialog, SLOT(reset()));
    QObject::connect(&dialog, SIGNAL(canceled()), &futureWatcher, SLOT(cancel()));
    QObject::connect(&futureWatcher, SIGNAL(progressRangeChanged(int,int)), &dialog, SLOT(setRange(int,int)));
    QObject::connect(&futureWatcher, SIGNAL(progressValueChanged(int)), &dialog, SLOT(setValue(int)));

    // Start the computation.

    futureWatcher.setFuture(QtConcurrent::map(listImages, operation));

    //QFuture<void> future = QtConcurrent::map(listImages, operation);???????????


    QList<QImage> thumbnails = QtConcurrent::blockingMapped<QList<QImage> >(listImages, operation);

    // Display the dialog and start the event loop.
    dialog.exec();

    futureWatcher.waitForFinished();

//++++++++++++++++++++++++++++++++++++++++++++++


    thumbnails[0] = thumbnails[0].copy(0,0,u,image.height());

    for(int i=1; i<30; i++){
        thumbnails[i] = thumbnails[i].copy(1,0,u,image.height());
    }

    thumbnails[31] = thumbnails[31].copy(1,0,v,image.height());

    QImage result(image.width(), image.height(),QImage::Format_RGB32);

    QPainter painter;
    painter.begin(&result);
    painter.drawImage(0, 0, thumbnails[0]);

    for(int i=0; i<31; i++){
        painter.drawImage((i*u), 0, thumbnails[i]);
    }

    painter.end();

    QImage fullResult = ImageChanger::addMedianFilterFrame(result);

    ui->label_2->setPixmap(QPixmap::fromImage(fullResult));

    };
}

void MainWindow::on_saveAsButton_pressed()
{
    QString imagePath = QFileDialog::getSaveFileName(
                this,
                tr("Save File"),
                "",
                tr("JPEG (*.jpg *.jpeg);;PNG (*.png);;BMP (*.bmp);;TIF (*.tif)")
                );

    QImage result = ui->label_2->pixmap()->toImage();

    result.save(imagePath);
}

void MainWindow::on_quitButton_pressed()
{
    qApp->quit();
}
