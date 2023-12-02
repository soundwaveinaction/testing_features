#ifndef IFILTER_H
#define IFILTER_H
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

class IFilter
{
public:
    IFilter();
    ~IFilter();
    int virtual param1(int param)=0;
    int virtual param2(int param)=0;
    QImage virtual progress(QImage &image)=0;
};

#endif // IFILTER_H
