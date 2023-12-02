#ifndef CANNYFILTER_H
#define CANNYFILTER_H

#include "ifilter.h"

#include <QtCore>
#include <opencv2/opencv.hpp>
#include <opencv2/video.hpp>
#include<opencv2/videoio.hpp>
#include<opencv2/stitching.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include<QPixmap>
#include <QImage>
#include <QtGlobal>
#include <QGraphicsPixmapItem>
#include <QDebug>
class CannyFilter : public IFilter
{
public:
    CannyFilter();
    ~CannyFilter();
    int param1(int param) override;;

    int param2(int param) override;;

    QImage cvMatToQImage(cv::Mat* cvImage);

    cv::Mat QImageToCvMat(QImage& img);

    QImage progress(QImage& image) override;;
    int treshold1,treshold2;

private:
    //int treshold1,treshold2;
};

#endif // CANNYFILTER_H
