#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "imagechanger.h"
#include "QPixmap"
#include "QImage"
#include "QFileDialog"
#include "QList"
#include <QtTest>

/* Content
    addMedianFilterTest    row  17
    addMedianFilter        row  42
    addMedianFilterMP      row 789  (for a image divided into multiple parts)
    addMedianFilterFrame   row 878  (for the frame of a divided image)
*/

QImage ImageChanger::addMedianFilterTest(const QImage & image)
{
    if (!image.isNull())
    {
        QImage resultImage = image;

        QRgb col;
        int gray;
        int width = resultImage.width();
        int height = resultImage.height();
        for (int i = 0; i < width; ++i)
        {
            for (int j = 0; j < height; ++j)
            {
                col = resultImage.pixel(i, j);
                gray = qGray(col);
                resultImage.setPixel(i, j, qRgb(gray, gray, gray));
            }
        }
        return resultImage;
    }
    return QImage();
}


QImage ImageChanger::addMedianFilter(const QImage & image)
{
    if (!image.isNull())
    {
        QImage resultImage = image;

        //******Progress bar
        int n = image.width();
        QProgressDialog* pprd = new QProgressDialog("Progressing the data...", "&Cancel", 0, n);
        pprd->setMinimumDuration(0);
        pprd->setWindowTitle("Please Wait");
        //******


        //******Filter for Image without boundary points
        for(int i=1; i<image.width()-1; i++)
        {
            //******Progress bar
            pprd->setValue(i) ;
            qApp->processEvents();
            if (pprd->wasCanceled())
            {
                 break;
            }
            //******

            for(int j=1; j<image.height()-1; j++)
            {
                int red = 0, green = 0, blue = 0;

                QList<int> redList;

                redList << qRed(image.pixel(i+1, j+1))
                        << qRed(image.pixel(i, j+1))
                        << qRed(image.pixel(i-1, j+1))

                        << qRed(image.pixel(i+1, j))
                        << qRed(image.pixel(i, j))
                        << qRed(image.pixel(i-1, j))

                        << qRed(image.pixel(i+1, j-1))
                        << qRed(image.pixel(i, j-1))
                        << qRed(image.pixel(i-1, j-1));

                qSort(redList.begin(), redList.end());

                red = redList.at(4);

                // *****************************************************

                QList<int> greenList;

                greenList << qGreen(image.pixel(i+1, j+1))
                          << qGreen(image.pixel(i, j+1))
                          << qGreen(image.pixel(i-1, j+1))

                          << qGreen(image.pixel(i+1, j))
                          << qGreen(image.pixel(i, j))
                          << qGreen(image.pixel(i-1, j))

                          << qGreen(image.pixel(i+1, j-1))
                          << qGreen(image.pixel(i, j-1))
                          << qGreen(image.pixel(i-1, j-1));

                qSort(greenList.begin(), greenList.end());

                green = greenList.at(4);

                // *****************************************************

                QList<int> blueList;

                blueList << qBlue(image.pixel(i+1, j+1))
                         << qBlue(image.pixel(i, j+1))
                         << qBlue(image.pixel(i-1, j+1))

                         << qBlue(image.pixel(i+1, j))
                         << qBlue(image.pixel(i, j))
                         << qBlue(image.pixel(i-1, j))

                         << qBlue(image.pixel(i+1, j-1))
                         << qBlue(image.pixel(i, j-1))
                         << qBlue(image.pixel(i-1, j-1));

                qSort(blueList.begin(), blueList.end());

                blue = blueList.at(4);

                resultImage.setPixel(i,j, qRgb(red, green, blue));

                redList.clear();
                greenList.clear();
                blueList.clear();

            }
        }
        //******End Filter for Image without boundary points



        //******Filter for edges
        //=====================

        //******Point (0,0)
        /*
                +-------+-------+-------+
                |       |       |       |
                |     <---  ^   |   ^   |
                |       |   |   |   |   |
                +-------+===|===+===|===+
                |       I  Left |       |
                |     <---Upper |       |
                |       I Corner|       |
                +-------+-------+-------+
                |       I       |       |
                |     <---      |       |
                |       I       |       |
                +-------+-------+-------+
         */

        int l = 0;
        int m = 0;
        int red = 0, green = 0, blue = 0;

        QList<int>redList;

        redList << qRed(image.pixel(l, m))
                << qRed(image.pixel(l, m))
                << qRed(image.pixel(l+1, m))

                << qRed(image.pixel(l, m))
                << qRed(image.pixel(l, m))
                << qRed(image.pixel(l+1, m))

                << qRed(image.pixel(l, m+1))
                << qRed(image.pixel(l, m+1))
                << qRed(image.pixel(l+1, m+1));

        qSort(redList.begin(), redList.end());

        red = redList.at(4);

        // *****************************************************

        QList<int> greenList;

        greenList << qGreen(image.pixel(l, m))
                  << qGreen(image.pixel(l, m))
                  << qGreen(image.pixel(l+1, m))

                  << qGreen(image.pixel(l, m))
                  << qGreen(image.pixel(l, m))
                  << qGreen(image.pixel(l+1, m))

                  << qGreen(image.pixel(l, m+1))
                  << qGreen(image.pixel(l, m+1))
                  << qGreen(image.pixel(l+1, m+1));

        qSort(greenList.begin(), greenList.end());

        green = greenList.at(4);

        // *****************************************************

        QList<int> blueList;

        blueList << qBlue(image.pixel(l, m))
                 << qBlue(image.pixel(l, m))
                 << qBlue(image.pixel(l+1, m))

                 << qBlue(image.pixel(l, m))
                 << qBlue(image.pixel(l, m))
                 << qBlue(image.pixel(l+1, m))

                 << qBlue(image.pixel(l, m+1))
                 << qBlue(image.pixel(l, m+1))
                 << qBlue(image.pixel(l+1, m+1));

        qSort(blueList.begin(), blueList.end());

        blue = blueList.at(4);

        resultImage.setPixel(l,m, qRgb(red, green, blue));

        //******End Point (0,0)
        //==========================

        //******Point (0,imageHeight-1)

        /*
                +-------+-------+-------+
                |       I       |       |
                |     <---      |       |
                |       I       |       |
                +-------+-------+-------|
                |       I  Left |       |
                |     <---Bottom|       |
                |       I Corner|       |
                +-------+===|===+===|===+
                |       |   |   |   |   |
                |      <--- \/  |   \/  |
                |       |       |       |
                +-------+-------+-------+
         */

        l = 0, m = image.height()-1;
        red = 0, green = 0, blue = 0;

        redList.clear();

        redList << qRed(image.pixel(l, m-1))
                << qRed(image.pixel(l, m-1))
                << qRed(image.pixel(l+1, m-1))

                << qRed(image.pixel(l, m))
                << qRed(image.pixel(l, m))
                << qRed(image.pixel(l+1, m))

                << qRed(image.pixel(l, m))
                << qRed(image.pixel(l, m))
                << qRed(image.pixel(l+1, m));

        qSort(redList.begin(), redList.end());

        red = redList.at(4);

        // *****************************************************

        greenList.clear();

        greenList << qGreen(image.pixel(l, m-1))
                  << qGreen(image.pixel(l, m-1))
                  << qGreen(image.pixel(l+1, m-1))

                  << qGreen(image.pixel(l, m))
                  << qGreen(image.pixel(l, m))
                  << qGreen(image.pixel(l+1, m))

                  << qGreen(image.pixel(l, m))
                  << qGreen(image.pixel(l, m))
                  << qGreen(image.pixel(l+1, m));

        qSort(greenList.begin(), greenList.end());

        green = greenList.at(4);

        // *****************************************************

        blueList.clear();

        blueList << qBlue(image.pixel(l, m-1))
                 << qBlue(image.pixel(l, m-1))
                 << qBlue(image.pixel(l+1, m-1))

                 << qBlue(image.pixel(l, m))
                 << qBlue(image.pixel(l, m))
                 << qBlue(image.pixel(l+1, m))

                 << qBlue(image.pixel(l, m))
                 << qBlue(image.pixel(l, m))
                 << qBlue(image.pixel(l+1, m));


        qSort(blueList.begin(), blueList.end());

        blue = blueList.at(4);

        resultImage.setPixel(m,l, qRgb(red, green, blue));

        //******End Point (0,imageHeight-1)
        //==========================

        //******Point (imageWidth-1,0)
        /*
                +-------+-------+-------+
                |       |       |       |
                |   ^   |   ^   |   ^   |
                |   |   |   |   |   |   |
                +===|===+===|===+---|---|
                |       | Right I       |
                |       | Upper -->     |
                |       | CornerI       |
                +-------+-------+-------+
                |       |       I       |
                |       |      --->     |
                |       |       I       |
                +-------+-------+-------+
         */

        l = image.width()-1, m = 0 ;
        red = 0, green = 0, blue = 0;

        redList.clear();

        redList << qRed(image.pixel(l-1, m))
                << qRed(image.pixel(l, m))
                << qRed(image.pixel(l, m))

                << qRed(image.pixel(l-1, m))
                << qRed(image.pixel(l, m))
                << qRed(image.pixel(l, m))

                << qRed(image.pixel(l-1, m+1))
                << qRed(image.pixel(l, m+1))
                << qRed(image.pixel(l, m+1));

        qSort(redList.begin(), redList.end());

        red = redList.at(4);

        // *****************************************************

        greenList.clear();

        greenList << qGreen(image.pixel(l-1, m))
                  << qGreen(image.pixel(l, m))
                  << qGreen(image.pixel(l, m))

                  << qGreen(image.pixel(l-1, m))
                  << qGreen(image.pixel(l, m))
                  << qGreen(image.pixel(l, m))

                  << qGreen(image.pixel(l-1, m+1))
                  << qGreen(image.pixel(l, m+1))
                  << qGreen(image.pixel(l, m+1));

        qSort(greenList.begin(), greenList.end());

        green = greenList.at(4);

        // *****************************************************

        blueList.clear();

        blueList << qBlue(image.pixel(l-1, m))
                 << qBlue(image.pixel(l, m))
                 << qBlue(image.pixel(l, m))

                 << qBlue(image.pixel(l-1, m))
                 << qBlue(image.pixel(l, m))
                 << qBlue(image.pixel(l, m))

                 << qBlue(image.pixel(l-1, m+1))
                 << qBlue(image.pixel(l, m+1))
                 << qBlue(image.pixel(l, m+1));

        qSort(blueList.begin(), blueList.end());

        blue = blueList.at(4);

        resultImage.setPixel(l,m, qRgb(red, green, blue));

        //******End Point (imageWidth-1,0)
        //==========================

        //******Point (imageWidth-1,imageHeight-1)
        /*
                +-------+-------+-------+
                |       |       I       |
                |       |      --->     |
                |       |       I       |
                +-------+-------+-------|
                |       | Right I       |
                |       | Bottom-->     |
                |       | CornerI       |
                +===|===+===|===+-------+
                |   |   |   |   I       |
                |   \/  |   \/ --->     |
                |       |       I       |
                +-------+-------+-------+
         */

        l = image.width()-1, m = image.height()-1;
        red = 0, green = 0, blue = 0;

        redList.clear();

        redList << qRed(image.pixel(l-1, m-1))
                << qRed(image.pixel(l, m-1))
                << qRed(image.pixel(l, m-1))

                << qRed(image.pixel(l-1, m))
                << qRed(image.pixel(l, m))
                << qRed(image.pixel(l, m))

                << qRed(image.pixel(l-1, m))
                << qRed(image.pixel(l, m))
                << qRed(image.pixel(l, m));

        qSort(redList.begin(), redList.end());

        red = redList.at(4);

        // *****************************************************

        greenList.clear();

        greenList << qGreen(image.pixel(l-1, m-1))
                  << qGreen(image.pixel(l, m-1))
                  << qGreen(image.pixel(l, m-1))

                  << qGreen(image.pixel(l-1, m))
                  << qGreen(image.pixel(l, m))
                  << qGreen(image.pixel(l, m))

                  << qGreen(image.pixel(l-1, m))
                  << qGreen(image.pixel(l, m))
                  << qGreen(image.pixel(l, m));

        qSort(greenList.begin(), greenList.end());

        green = greenList.at(4);

        // *****************************************************

        blueList.clear();

        blueList << qBlue(image.pixel(l-1, m-1))
                 << qBlue(image.pixel(l, m-1))
                 << qBlue(image.pixel(l, m-1))

                 << qBlue(image.pixel(l-1, m))
                 << qBlue(image.pixel(l, m))
                 << qBlue(image.pixel(l, m))

                 << qBlue(image.pixel(l-1, m))
                 << qBlue(image.pixel(l, m))
                 << qBlue(image.pixel(l, m));

        qSort(blueList.begin(), blueList.end());

        blue = blueList.at(4);

        resultImage.setPixel(l,m, qRgb(red, green, blue));

        //******End Point (imageWidth-1,imageHeight-1)
        //==========================

  // /////////////////////////////////////////////////////////////////////
        //****** Boundary Line From (0,0) to (0,imageHeight-1)
        l = 0;

        for(int m=1; m<image.height()-2; m++)
        {
            red = 0, green = 0, blue = 0;
            redList.clear();

            redList << qRed(image.pixel(l, m-1))
                    << qRed(image.pixel(l, m-1))
                    << qRed(image.pixel(l+1, m-1))

                    << qRed(image.pixel(l, m))
                    << qRed(image.pixel(l, m))
                    << qRed(image.pixel(l+1, m))

                    << qRed(image.pixel(l, m+1))
                    << qRed(image.pixel(l, m+1))
                    << qRed(image.pixel(l+1, m+1));

            qSort(redList.begin(), redList.end());

            red = redList.at(4);

            // *****************************************************

            greenList.clear();

            greenList << qGreen(image.pixel(l, m-1))
                      << qGreen(image.pixel(l, m-1))
                      << qGreen(image.pixel(l+1, m-1))

                      << qGreen(image.pixel(l, m))
                      << qGreen(image.pixel(l, m))
                      << qGreen(image.pixel(l+1, m))

                      << qGreen(image.pixel(l, m+1))
                      << qGreen(image.pixel(l, m+1))
                      << qGreen(image.pixel(l+1, m+1));

            qSort(greenList.begin(), greenList.end());

            green = greenList.at(4);

            // *****************************************************

            blueList.clear();

            blueList  << qBlue(image.pixel(l, m-1))
                      << qBlue(image.pixel(l, m-1))
                      << qBlue(image.pixel(l+1, m-1))

                      << qBlue(image.pixel(l, m))
                      << qBlue(image.pixel(l, m))
                      << qBlue(image.pixel(l+1, m))

                      << qBlue(image.pixel(l, m+1))
                      << qBlue(image.pixel(l, m+1))
                      << qBlue(image.pixel(l+1, m+1));


            qSort(blueList.begin(), blueList.end());

            blue = blueList.at(4);

            resultImage.setPixel(l,m, qRgb(red, green, blue));
        }


        //******End Boundary Line From (0,0) to (0,imageHeight-1)
            //==========================

        //******Begin Boundary Line From (0,imageHeight-1) to (imageWidth-1,imageHeight-1)

        l = 0, m = image.height()-1;



        for(int l=1; l<image.width()-2; l++)
        {

            red = 0, green = 0, blue = 0;

            redList.clear();

            redList << qRed(image.pixel(l-1, m-1))
                    << qRed(image.pixel(l, m-1))
                    << qRed(image.pixel(l+1, m-1))

                    << qRed(image.pixel(l-1, m))
                    << qRed(image.pixel(l, m))
                    << qRed(image.pixel(l+1, m))

                    << qRed(image.pixel(l-1, m))
                    << qRed(image.pixel(l, m))
                    << qRed(image.pixel(l+1, m));

            qSort(redList.begin(), redList.end());

            red = redList.at(4);

            // *****************************************************

            greenList.clear();

            greenList   << qGreen(image.pixel(l-1, m-1))
                        << qGreen(image.pixel(l, m-1))
                        << qGreen(image.pixel(l+1, m-1))

                        << qGreen(image.pixel(l-1, m))
                        << qGreen(image.pixel(l, m))
                        << qGreen(image.pixel(l+1, m))

                        << qGreen(image.pixel(l-1, m))
                        << qGreen(image.pixel(l, m))
                        << qGreen(image.pixel(l+1, m));

            qSort(greenList.begin(), greenList.end());

            green = greenList.at(4);

            // *****************************************************

            blueList.clear();

            blueList  << qBlue(image.pixel(l-1, m-1))
                      << qBlue(image.pixel(l, m-1))
                      << qBlue(image.pixel(l+1, m-1))

                      << qBlue(image.pixel(l-1, m))
                      << qBlue(image.pixel(l, m))
                      << qBlue(image.pixel(l+1, m))

                      << qBlue(image.pixel(l-1, m))
                      << qBlue(image.pixel(l, m))
                      << qBlue(image.pixel(l+1, m));


            qSort(blueList.begin(), blueList.end());

            blue = blueList.at(4);

            resultImage.setPixel(l,m, qRgb(red, green, blue));

        }


        //******End Boundary Line From (0,imageHeight-1) to (imageWidth-1,imageHeight-1)
        //==========================

        //******Boundary Line From (0,0) to (imageWidth-1,0)
           m = 0;

           for(int l=1; l<image.width()-2; l++)
           {
                red = 0, green = 0, blue = 0;

                redList.clear();

                redList << qRed(image.pixel(l-1, m))
                        << qRed(image.pixel(l, m))
                        << qRed(image.pixel(l+1, m))

                        << qRed(image.pixel(l-1, m))
                        << qRed(image.pixel(l, m))
                        << qRed(image.pixel(l+1, m))

                        << qRed(image.pixel(l-1, m+1))
                        << qRed(image.pixel(l, m+1))
                        << qRed(image.pixel(l+1, m+1));

                qSort(redList.begin(), redList.end());

                red = redList.at(4);

                // *****************************************************

                greenList.clear();

                greenList   << qGreen(image.pixel(l-1, m))
                            << qGreen(image.pixel(l, m))
                            << qGreen(image.pixel(l+1, m))

                            << qGreen(image.pixel(l-1, m))
                            << qGreen(image.pixel(l, m))
                            << qGreen(image.pixel(l+1, m))

                            << qGreen(image.pixel(l-1, m+1))
                            << qGreen(image.pixel(l, m+1))
                            << qGreen(image.pixel(l+1, m+1));;

                qSort(greenList.begin(), greenList.end());

                green = greenList.at(4);

                // *****************************************************

                blueList.clear();

                blueList  << qBlue(image.pixel(l-1, m))
                          << qBlue(image.pixel(l, m))
                          << qBlue(image.pixel(l+1, m))

                          << qBlue(image.pixel(l-1, m))
                          << qBlue(image.pixel(l, m))
                          << qBlue(image.pixel(l+1, m))

                          << qBlue(image.pixel(l-1, m+1))
                          << qBlue(image.pixel(l, m+1))
                          << qBlue(image.pixel(l+1, m+1));;


                qSort(blueList.begin(), blueList.end());

                blue = blueList.at(4);

                resultImage.setPixel(l,m, qRgb(red, green, blue));



            //******End Boundary Line From (0,0) to (imageWidth-1,0)
            //======================================================

            //******Begin Boundary Line From (imageWidth-1,0) to (imageWidth-1,imageHeight-1)

            l = image.width()-1,  m = 0;

            for(int m=1; m < image.height()-2; m++)
            {

                red = 0, green = 0, blue = 0;

                redList.clear();

                redList << qRed(image.pixel(l-1, m-1))
                        << qRed(image.pixel(l, m-1))
                        << qRed(image.pixel(l, m-1))

                        << qRed(image.pixel(l-1, m))
                        << qRed(image.pixel(l, m))
                        << qRed(image.pixel(l, m))

                        << qRed(image.pixel(l-1, m+1))
                        << qRed(image.pixel(l, m+1))
                        << qRed(image.pixel(l, m+1));

                qSort(redList.begin(), redList.end());

                red = redList.at(4);

                // *****************************************************

                greenList.clear();

                greenList   << qGreen(image.pixel(l-1, m-1))
                            << qGreen(image.pixel(l, m-1))
                            << qGreen(image.pixel(l, m-1))

                            << qGreen(image.pixel(l-1, m))
                            << qGreen(image.pixel(l, m))
                            << qGreen(image.pixel(l, m))

                            << qGreen(image.pixel(l-1, m+1))
                            << qGreen(image.pixel(l, m+1))
                            << qGreen(image.pixel(l, m+1));

                qSort(greenList.begin(), greenList.end());

                green = greenList.at(4);

                // *****************************************************

                blueList.clear();

                blueList  << qBlue(image.pixel(l-1, m-1))
                          << qBlue(image.pixel(l, m-1))
                          << qBlue(image.pixel(l, m-1))

                          << qBlue(image.pixel(l-1, m))
                          << qBlue(image.pixel(l, m))
                          << qBlue(image.pixel(l, m))

                          << qBlue(image.pixel(l-1, m+1))
                          << qBlue(image.pixel(l, m+1))
                          << qBlue(image.pixel(l, m+1));


                qSort(blueList.begin(), blueList.end());

                blue = blueList.at(4);

                resultImage.setPixel(l,m, qRgb(red, green, blue));
            }
        }
   //******End (0,imageWidth-1) to (imageHeight-1,imageWidth)
   //========================================================

        //*****Progress bar
        pprd->setValue(n) ;
        delete pprd;
        //******
        return resultImage;
    }
    return QImage();
}

//==================================================================
//==================================================================
//===Filter for Image divided into many parts
QImage ImageChanger::addMedianFilterMP(const QImage & image)
{
    if (!image.isNull())
    {
        QImage resultImage = image;


        //******Filter for Image without boundary points
        for(int i=1; i<image.width()-1; i++)
        {
            for(int j=1; j<image.height()-1; j++)
            {
                int red = 0, green = 0, blue = 0;

                QList<int> redList;

                redList << qRed(image.pixel(i+1, j+1))
                        << qRed(image.pixel(i, j+1))
                        << qRed(image.pixel(i-1, j+1))

                        << qRed(image.pixel(i+1, j))
                        << qRed(image.pixel(i, j))
                        << qRed(image.pixel(i-1, j))

                        << qRed(image.pixel(i+1, j-1))
                        << qRed(image.pixel(i, j-1))
                        << qRed(image.pixel(i-1, j-1));

                qSort(redList.begin(), redList.end());

                red = redList.at(4);

                // *****************************************************

                QList<int> greenList;

                greenList << qGreen(image.pixel(i+1, j+1))
                          << qGreen(image.pixel(i, j+1))
                          << qGreen(image.pixel(i-1, j+1))

                          << qGreen(image.pixel(i+1, j))
                          << qGreen(image.pixel(i, j))
                          << qGreen(image.pixel(i-1, j))

                          << qGreen(image.pixel(i+1, j-1))
                          << qGreen(image.pixel(i, j-1))
                          << qGreen(image.pixel(i-1, j-1));

                qSort(greenList.begin(), greenList.end());

                green = greenList.at(4);

                // *****************************************************

                QList<int> blueList;

                blueList << qBlue(image.pixel(i+1, j+1))
                         << qBlue(image.pixel(i, j+1))
                         << qBlue(image.pixel(i-1, j+1))

                         << qBlue(image.pixel(i+1, j))
                         << qBlue(image.pixel(i, j))
                         << qBlue(image.pixel(i-1, j))

                         << qBlue(image.pixel(i+1, j-1))
                         << qBlue(image.pixel(i, j-1))
                         << qBlue(image.pixel(i-1, j-1));

                qSort(blueList.begin(), blueList.end());

                blue = blueList.at(4);

                resultImage.setPixel(i,j, qRgb(red, green, blue));

                redList.clear();
                greenList.clear();
                blueList.clear();
            }
        }
        //******End Filter for Image without boundary points

        return resultImage;
    }
    return QImage();
}

//==================================================================
//==================================================================
//===Filter for Frame of image
QImage ImageChanger::addMedianFilterFrame(const QImage & image)
{
    if (!image.isNull())
    {
        QImage resultImage = image;

        //******Filter for edges
        //======================

        //******Point (0,0)
        /*
                +-------+-------+-------+
                |       |       |       |
                |     <---  ^   |   ^   |
                |       |   |   |   |   |
                +-------+===|===+===|===+
                |       I  Left |       |
                |     <---Upper |       |
                |       I Corner|       |
                +-------+-------+-------+
                |       I       |       |
                |     <---      |       |
                |       I       |       |
                +-------+-------+-------+
         */

        int l = 0;
        int m = 0;
        int red = 0, green = 0, blue = 0;

        QList<int> redList;

        redList << qRed(image.pixel(l, m))
                << qRed(image.pixel(l, m))
                << qRed(image.pixel(l+1, m))

                << qRed(image.pixel(l, m))
                << qRed(image.pixel(l, m))
                << qRed(image.pixel(l+1, m))

                << qRed(image.pixel(l, m+1))
                << qRed(image.pixel(l, m+1))
                << qRed(image.pixel(l+1, m+1));

        qSort(redList.begin(), redList.end());

        red = redList.at(4);

        // *****************************************************

        QList<int> greenList;

        greenList << qGreen(image.pixel(l, m))
                  << qGreen(image.pixel(l, m))
                  << qGreen(image.pixel(l+1, m))

                  << qGreen(image.pixel(l, m))
                  << qGreen(image.pixel(l, m))
                  << qGreen(image.pixel(l+1, m))

                  << qGreen(image.pixel(l, m+1))
                  << qGreen(image.pixel(l, m+1))
                  << qGreen(image.pixel(l+1, m+1));

        qSort(greenList.begin(), greenList.end());

        green = greenList.at(4);

        // *****************************************************

        QList<int> blueList;

        blueList << qBlue(image.pixel(l, m))
                 << qBlue(image.pixel(l, m))
                 << qBlue(image.pixel(l+1, m))

                 << qBlue(image.pixel(l, m))
                 << qBlue(image.pixel(l, m))
                 << qBlue(image.pixel(l+1, m))

                 << qBlue(image.pixel(l, m+1))
                 << qBlue(image.pixel(l, m+1))
                 << qBlue(image.pixel(l+1, m+1));

        qSort(blueList.begin(), blueList.end());

        blue = blueList.at(4);

        resultImage.setPixel(l,m, qRgb(red, green, blue));

        redList.clear();
        greenList.clear();
        blueList.clear();

        //******End Point (0,0)
        //=====================

        //******Point (0,imageHeight-1)

        /*
                +-------+-------+-------+
                |       I       |       |
                |     <---      |       |
                |       I       |       |
                +-------+-------+-------|
                |       I  Left |       |
                |     <---Bottom|       |
                |       I Corner|       |
                +-------+===|===+===|===+
                |       |   |   |   |   |
                |      <--- \/  |   \/  |
                |       |       |       |
                +-------+-------+-------+
         */

        l = 0, m = image.height()-1;
        red = 0, green = 0, blue = 0;

        redList.clear();

        redList << qRed(image.pixel(l, m-1))
                << qRed(image.pixel(l, m-1))
                << qRed(image.pixel(l+1, m-1))

                << qRed(image.pixel(l, m))
                << qRed(image.pixel(l, m))
                << qRed(image.pixel(l+1, m))

                << qRed(image.pixel(l, m))
                << qRed(image.pixel(l, m))
                << qRed(image.pixel(l+1, m));

        qSort(redList.begin(), redList.end());

        red = redList.at(4);

        // *****************************************************

        greenList.clear();

        greenList  << qGreen(image.pixel(l, m-1))
                  << qGreen(image.pixel(l, m-1))
                << qGreen(image.pixel(l+1, m-1))

                << qGreen(image.pixel(l, m))
                << qGreen(image.pixel(l, m))
                << qGreen(image.pixel(l+1, m))

                << qGreen(image.pixel(l, m))
                << qGreen(image.pixel(l, m))
                << qGreen(image.pixel(l+1, m));

        qSort(greenList.begin(), greenList.end());

        green = greenList.at(4);

        // *****************************************************

        blueList.clear();

        blueList << qBlue(image.pixel(l, m-1))
                 << qBlue(image.pixel(l, m-1))
                 << qBlue(image.pixel(l+1, m-1))

                 << qBlue(image.pixel(l, m))
                 << qBlue(image.pixel(l, m))
                 << qBlue(image.pixel(l+1, m))

                 << qBlue(image.pixel(l, m))
                 << qBlue(image.pixel(l, m))
                 << qBlue(image.pixel(l+1, m));

        qSort(blueList.begin(), blueList.end());

        blue = blueList.at(4);

        resultImage.setPixel(m,l, qRgb(red, green, blue));

        //******End Point (0,imageHeight-1)
        //=================================

        //******Point (imageWidth-1,0)
        /*
                +-------+-------+-------+
                |       |       |       |
                |   ^   |   ^   |   ^   |
                |   |   |   |   |   |   |
                +===|===+===|===+---|---|
                |       | Right I       |
                |       | Upper -->     |
                |       | CornerI       |
                +-------+-------+-------+
                |       |       I       |
                |       |      --->     |
                |       |       I       |
                +-------+-------+-------+
         */

        l = image.width()-1, m = 0 ;
        red = 0, green = 0, blue = 0;

        redList.clear();

        redList << qRed(image.pixel(l-1, m))
                << qRed(image.pixel(l, m))
                << qRed(image.pixel(l, m))

                << qRed(image.pixel(l-1, m))
                << qRed(image.pixel(l, m))
                << qRed(image.pixel(l, m))

                << qRed(image.pixel(l-1, m+1))
                << qRed(image.pixel(l, m+1))
                << qRed(image.pixel(l, m+1));

        qSort(redList.begin(), redList.end());

        red = redList.at(4);

        // *****************************************************

        greenList.clear();

        greenList  << qGreen(image.pixel(l-1, m))
                   << qGreen(image.pixel(l, m))
                   << qGreen(image.pixel(l, m))

                   << qGreen(image.pixel(l-1, m))
                   << qGreen(image.pixel(l, m))
                   << qGreen(image.pixel(l, m))

                   << qGreen(image.pixel(l-1, m+1))
                   << qGreen(image.pixel(l, m+1))
                   << qGreen(image.pixel(l, m+1));

        qSort(greenList.begin(), greenList.end());

        green = greenList.at(4);

        // *****************************************************

        blueList.clear();

        blueList << qBlue(image.pixel(l-1, m))
                 << qBlue(image.pixel(l, m))
                 << qBlue(image.pixel(l, m))

                 << qBlue(image.pixel(l-1, m))
                 << qBlue(image.pixel(l, m))
                 << qBlue(image.pixel(l, m))

                 << qBlue(image.pixel(l-1, m+1))
                 << qBlue(image.pixel(l, m+1))
                 << qBlue(image.pixel(l, m+1));

        qSort(blueList.begin(), blueList.end());

        blue = blueList.at(4);

        resultImage.setPixel(l,m, qRgb(red, green, blue));

        //******End Point (imageWidth-1,0)
        //================================

        //******Point (imageWidth-1,imageHeight-1)
        /*
                +-------+-------+-------+
                |       |       I       |
                |       |      --->     |
                |       |       I       |
                +-------+-------+-------|
                |       | Right I       |
                |       | Bottom-->     |
                |       | CornerI       |
                +===|===+===|===+-------+
                |   |   |   |   I       |
                |   \/  |   \/ --->     |
                |       |       I       |
                +-------+-------+-------+
         */

        l = image.width()-1, m = image.height()-1;
        red = 0, green = 0, blue = 0;

        redList.clear();

        redList << qRed(image.pixel(l-1, m-1))
                << qRed(image.pixel(l, m-1))
                << qRed(image.pixel(l, m-1))

                << qRed(image.pixel(l-1, m))
                << qRed(image.pixel(l, m))
                << qRed(image.pixel(l, m))

                << qRed(image.pixel(l-1, m))
                << qRed(image.pixel(l, m))
                << qRed(image.pixel(l, m));

        qSort(redList.begin(), redList.end());

        red = redList.at(4);

        // *****************************************************

        greenList.clear();

        greenList  << qGreen(image.pixel(l-1, m-1))
                   << qGreen(image.pixel(l, m-1))
                   << qGreen(image.pixel(l, m-1))

                   << qGreen(image.pixel(l-1, m))
                   << qGreen(image.pixel(l, m))
                   << qGreen(image.pixel(l, m))

                   << qGreen(image.pixel(l-1, m))
                   << qGreen(image.pixel(l, m))
                   << qGreen(image.pixel(l, m));

        qSort(greenList.begin(), greenList.end());

        green = greenList.at(4);

        // *****************************************************

        blueList.clear();

        blueList << qBlue(image.pixel(l-1, m-1))
                 << qBlue(image.pixel(l, m-1))
                 << qBlue(image.pixel(l, m-1))

                 << qBlue(image.pixel(l-1, m))
                 << qBlue(image.pixel(l, m))
                 << qBlue(image.pixel(l, m))

                 << qBlue(image.pixel(l-1, m))
                 << qBlue(image.pixel(l, m))
                 << qBlue(image.pixel(l, m));

        qSort(blueList.begin(), blueList.end());

        blue = blueList.at(4);

        resultImage.setPixel(l,m, qRgb(red, green, blue));

        //******End Point (imageWidth-1,imageHeight-1)
        //==========================

// /////////////////////////////////////////////////////////////////////
        //******Begin Boundary Line From (0,0) to (0,imageHeight-1)
        l = 0;

        for(int m=1; m<image.height()-2; m++)
        {

            red = 0, green = 0, blue = 0;

            redList.clear();

            redList << qRed(image.pixel(l, m-1))
                    << qRed(image.pixel(l, m-1))
                    << qRed(image.pixel(l+1, m-1))

                    << qRed(image.pixel(l, m))
                    << qRed(image.pixel(l, m))
                    << qRed(image.pixel(l+1, m))

                    << qRed(image.pixel(l, m+1))
                    << qRed(image.pixel(l, m+1))
                    << qRed(image.pixel(l+1, m+1));

            qSort(redList.begin(), redList.end());

            red = redList.at(4);

            // *****************************************************

            greenList.clear();

            greenList   << qGreen(image.pixel(l, m-1))
                        << qGreen(image.pixel(l, m-1))
                        << qGreen(image.pixel(l+1, m-1))

                        << qGreen(image.pixel(l, m))
                        << qGreen(image.pixel(l, m))
                        << qGreen(image.pixel(l+1, m))

                        << qGreen(image.pixel(l, m+1))
                        << qGreen(image.pixel(l, m+1))
                        << qGreen(image.pixel(l+1, m+1));

            qSort(greenList.begin(), greenList.end());

            green = greenList.at(4);

            // *****************************************************

            blueList.clear();

            blueList  << qBlue(image.pixel(l, m-1))
                      << qBlue(image.pixel(l, m-1))
                      << qBlue(image.pixel(l+1, m-1))

                      << qBlue(image.pixel(l, m))
                      << qBlue(image.pixel(l, m))
                      << qBlue(image.pixel(l+1, m))

                      << qBlue(image.pixel(l, m+1))
                      << qBlue(image.pixel(l, m+1))
                      << qBlue(image.pixel(l+1, m+1));


            qSort(blueList.begin(), blueList.end());

            blue = blueList.at(4);

            resultImage.setPixel(l,m, qRgb(red, green, blue));
        }


        //******End Boundary Line From (0,0) to (0,imageHeight-1)
        //=======================================================

        //******Begin Boundary Line From (0,imageHeight-1) to (imageWidth-1,imageHeight-1)

        l = 0, m = image.height()-1;

        for(int l=1; l<image.width()-2; l++)
        {

            red = 0, green = 0, blue = 0;

            redList.clear();

            redList << qRed(image.pixel(l-1, m-1))
                    << qRed(image.pixel(l, m-1))
                    << qRed(image.pixel(l+1, m-1))

                    << qRed(image.pixel(l-1, m))
                    << qRed(image.pixel(l, m))
                    << qRed(image.pixel(l+1, m))

                    << qRed(image.pixel(l-1, m))
                    << qRed(image.pixel(l, m))
                    << qRed(image.pixel(l+1, m));

            qSort(redList.begin(), redList.end());

            red = redList.at(4);

            // *****************************************************

            greenList.clear();

            greenList   << qGreen(image.pixel(l-1, m-1))
                        << qGreen(image.pixel(l, m-1))
                        << qGreen(image.pixel(l+1, m-1))

                        << qGreen(image.pixel(l-1, m))
                        << qGreen(image.pixel(l, m))
                        << qGreen(image.pixel(l+1, m))

                        << qGreen(image.pixel(l-1, m))
                        << qGreen(image.pixel(l, m))
                        << qGreen(image.pixel(l+1, m));

            qSort(greenList.begin(), greenList.end());

            green = greenList.at(4);

            // *****************************************************

            blueList.clear();

            blueList  << qBlue(image.pixel(l-1, m-1))
                      << qBlue(image.pixel(l, m-1))
                      << qBlue(image.pixel(l+1, m-1))

                      << qBlue(image.pixel(l-1, m))
                      << qBlue(image.pixel(l, m))
                      << qBlue(image.pixel(l+1, m))

                      << qBlue(image.pixel(l-1, m))
                      << qBlue(image.pixel(l, m))
                      << qBlue(image.pixel(l+1, m));


            qSort(blueList.begin(), blueList.end());

            blue = blueList.at(4);

            resultImage.setPixel(l,m, qRgb(red, green, blue));
        }

        //******End Boundary Line From (0,imageHeight-1) to (imageWidth-1,imageHeight-1)
        //==============================================================================

        //******Boundary Line From (0,0) to (imageWidth-1,0)
        m = 0;

        for(int l=1; l<image.width()-2; l++)
        {
            red = 0, green = 0, blue = 0;

            redList.clear();

            redList << qRed(image.pixel(l-1, m))
                    << qRed(image.pixel(l, m))
                    << qRed(image.pixel(l+1, m))

                    << qRed(image.pixel(l-1, m))
                    << qRed(image.pixel(l, m))
                    << qRed(image.pixel(l+1, m))

                    << qRed(image.pixel(l-1, m+1))
                    << qRed(image.pixel(l, m+1))
                    << qRed(image.pixel(l+1, m+1));

            qSort(redList.begin(), redList.end());

            red = redList.at(4);

            // *****************************************************

            greenList.clear();

            greenList   << qGreen(image.pixel(l-1, m))
                        << qGreen(image.pixel(l, m))
                        << qGreen(image.pixel(l+1, m))

                        << qGreen(image.pixel(l-1, m))
                        << qGreen(image.pixel(l, m))
                        << qGreen(image.pixel(l+1, m))

                        << qGreen(image.pixel(l-1, m+1))
                        << qGreen(image.pixel(l, m+1))
                        << qGreen(image.pixel(l+1, m+1));;

            qSort(greenList.begin(), greenList.end());

            green = greenList.at(4);

            // *****************************************************

            blueList.clear();

            blueList  << qBlue(image.pixel(l-1, m))
                      << qBlue(image.pixel(l, m))
                      << qBlue(image.pixel(l+1, m))

                      << qBlue(image.pixel(l-1, m))
                      << qBlue(image.pixel(l, m))
                      << qBlue(image.pixel(l+1, m))

                      << qBlue(image.pixel(l-1, m+1))
                      << qBlue(image.pixel(l, m+1))
                      << qBlue(image.pixel(l+1, m+1));;


            qSort(blueList.begin(), blueList.end());

            blue = blueList.at(4);

            resultImage.setPixel(l,m, qRgb(red, green, blue));



            //******End Boundary Line From (0,0) to (imageWidth-1,0)
            //==========================

            //******Begin Boundary Line From (imageWidth-1,0) to (imageWidth-1,imageHeight-1)
            l = image.width()-1,  m = 0;

            for(int m=1; m < image.height()-2; m++)
            {
                red = 0, green = 0, blue = 0;

                redList.clear();

                redList << qRed(image.pixel(l-1, m-1))
                        << qRed(image.pixel(l, m-1))
                        << qRed(image.pixel(l, m-1))

                        << qRed(image.pixel(l-1, m))
                        << qRed(image.pixel(l, m))
                        << qRed(image.pixel(l, m))

                        << qRed(image.pixel(l-1, m+1))
                        << qRed(image.pixel(l, m+1))
                        << qRed(image.pixel(l, m+1));

                qSort(redList.begin(), redList.end());

                red = redList.at(4);

                // *****************************************************

                greenList.clear();

                greenList   << qGreen(image.pixel(l-1, m-1))
                            << qGreen(image.pixel(l, m-1))
                            << qGreen(image.pixel(l, m-1))

                            << qGreen(image.pixel(l-1, m))
                            << qGreen(image.pixel(l, m))
                            << qGreen(image.pixel(l, m))

                            << qGreen(image.pixel(l-1, m+1))
                            << qGreen(image.pixel(l, m+1))
                            << qGreen(image.pixel(l, m+1));

                qSort(greenList.begin(), greenList.end());

                green = greenList.at(4);

                // *****************************************************

                blueList.clear();

                blueList  << qBlue(image.pixel(l-1, m-1))
                          << qBlue(image.pixel(l, m-1))
                          << qBlue(image.pixel(l, m-1))

                          << qBlue(image.pixel(l-1, m))
                          << qBlue(image.pixel(l, m))
                          << qBlue(image.pixel(l, m))

                          << qBlue(image.pixel(l-1, m+1))
                          << qBlue(image.pixel(l, m+1))
                          << qBlue(image.pixel(l, m+1));



                qSort(blueList.begin(), blueList.end());

                blue = blueList.at(4);

                resultImage.setPixel(l,m, qRgb(red, green, blue));

                redList.clear();
                greenList.clear();
                blueList.clear();
            }
        }

        //******End (0,imageWidth-1) to (imageHeight-1,imageWidth)
        //========================================================

        return resultImage;
    }
    return QImage();
}
