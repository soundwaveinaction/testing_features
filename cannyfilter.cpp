#include "cannyfilter.h"

CannyFilter::CannyFilter()
{

}

CannyFilter::~CannyFilter()
{

}

void CannyFilter::SetParam1(int param)
{
    treshold2=param;

}

void CannyFilter::SetParam2(int param)
{
    treshold1=param;
}

int CannyFilter::GetParam1()
{
    return treshold1;
}

int CannyFilter::GetParam2()
{
    return treshold2;
}

QImage CannyFilter::cvMatToQImage(cv::Mat *cvImage)
{
    return QImage(cvImage->data, cvImage->cols, cvImage->rows, cvImage->step, QImage::Format_Grayscale8);
}

cv::Mat CannyFilter::QImageToCvMat(QImage &img)
{
    img = img.convertToFormat(QImage::Format_RGB888, Qt::ColorOnly).rgbSwapped();
    return cv::Mat(img.height(), img.width(), CV_8UC3, img.bits(), img.bytesPerLine());
}

QImage CannyFilter::progress(QImage &image)
{
    qDebug()<<" treshold1 = "<<treshold1<<"\ntreshold2 = "<<treshold2;
    cv::Mat *mat=new cv::Mat(QImageToCvMat(image));
    cv::cvtColor(*mat,*mat,cv::COLOR_BGR2GRAY);
    Canny(*mat,*mat,treshold1,treshold2);
    return cvMatToQImage(mat);
}
