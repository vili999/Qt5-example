#ifndef IMAGECHANGER_H
#define IMAGECHANGER_H


#include <QImage>

class ImageChecker

{
public:

    static QImage addMedianFilter(const QImage & image);
    static QImage addMedianFilterMP(const QImage & image);
    static QImage addMedianFilterTest(const QImage & image);
    static QImage addMedianFilterFrame(const QImage & image);

    static QList<bool> checkPoint10_10(const QImage & image, const QImage & image_2);
};


#endif // IMAGECHANGER_H
