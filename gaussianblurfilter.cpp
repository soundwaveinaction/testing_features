#include "gaussianblurfilter.h"

GaussianBlurFilter::GaussianBlurFilter()
{

}

GaussianBlurFilter::~GaussianBlurFilter()
{

}

int GaussianBlurFilter::param1(int param)
{
    ksizeHeight=param;
    return ksizeHeight;
}

int GaussianBlurFilter::param2(int param)
{
    ksizeWidth=param;
    return ksizeWidth;
}

QImage GaussianBlurFilter::CvMatToQImage(cv::Mat cvImage) {
    if (cvImage.type() == CV_8UC4) {
        qDebug() << "32 bit image";
        cvtColor(cvImage, cvImage, cv::COLOR_BGR2RGB);
        return QImage(cvImage.data, cvImage.cols, cvImage.rows,
                      static_cast<int>(cvImage.step), QImage::Format_RGBA8888);
    } else if (cvImage.type() == CV_8UC3) {
        qDebug() << "24 bit image";
        cvtColor(cvImage, cvImage, cv::COLOR_BGR2RGB);
        return QImage(cvImage.data, cvImage.cols, cvImage.rows,
                      static_cast<int>(cvImage.step), QImage::Format_RGB888);
    } else if (cvImage.type() == CV_8UC1) {
        qDebug() << "8 bit image";
        return QImage(cvImage.data, cvImage.cols, cvImage.rows,
                      static_cast<int>(cvImage.step), QImage::Format_Grayscale8);
    }
}

cv::Mat GaussianBlurFilter::QImageToCvMat(QImage &img)
{
    img = img.convertToFormat(QImage::Format_RGB888, Qt::ColorOnly).rgbSwapped();
    return cv::Mat(img.height(), img.width(), CV_8UC3, img.bits(), img.bytesPerLine());
}

QImage GaussianBlurFilter::progress(QImage &image)
{
    qDebug()<<"ksize.width = "<<ksizeWidth<<"\nksize.height = "<<ksizeHeight;
    cv::Mat mat=QImageToCvMat(image);
    cv::GaussianBlur(mat,mat,cv::Size(ksizeWidth,ksizeHeight),0);
    return CvMatToQImage(mat);
}
