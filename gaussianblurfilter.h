#ifndef GAUSSIANBLURFILTER_H
#define GAUSSIANBLURFILTER_H

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
class GaussianBlurFilter : public IFilter
{
public:
    GaussianBlurFilter();
    ~GaussianBlurFilter();

    void SetParam1(int param) override;

    void SetParam2(int param) override;

    int GetParam1() override;

    int GetParam2() override;

    QImage CvMatToQImage(cv::Mat cvImage);;

    cv::Mat QImageToCvMat(QImage& img);

    QImage progress(QImage& image) override;;

private:
    int ksizeWidth,ksizeHeight;
};
Q_DECLARE_METATYPE(GaussianBlurFilter*)
Q_DECLARE_METATYPE(quint64)
#endif // GAUSSIANBLURFILTER_H
