#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "cannyfilter.h"
#include "gaussianblurfilter.h"
#include <QMainWindow>
#include <QImage>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <opencv2/opencv.hpp>
#include <opencv2/video.hpp>
#include<opencv2/videoio.hpp>
#include<opencv2/stitching.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_action_triggered();

    void on_pushButton_clicked();

    void on_param1Spinox_valueChanged(int arg1);

    void on_param2Spinox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    QImage inputImage;
    QGraphicsScene* scene;
    GaussianBlurFilter gaussianBlurFilter;
    CannyFilter cannyFilter;
};
#endif // MAINWINDOW_H
