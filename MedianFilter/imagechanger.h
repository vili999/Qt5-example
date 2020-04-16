#ifndef IMAGECHANGER_H
#define IMAGECHANGER_H


#include <QImage>

class ImageChanger

{
public:

    static QImage addMedianFilter(const QImage & image); //For one core Processor
    static QImage addMedianFilterMP(const QImage & image); //For multiple core Processor
    static QImage addMedianFilterTest(const QImage & image); //For test to MainWindow
    static QImage addMedianFilterFrame(const QImage & image); //For frame if there is multiple core Processor

};

#endif // IMAGECHANGER_H
