#include "mainwindow.h"
#include "ui_mainwindow.h"
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
#include <QFileDialog>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QMessageBox>

//filtersMap.insert("gaussian blur",qVariantCanny);
//filtersMap.insert("canny",qVariantGaussian);
//QVariant qVariant3 =filtersMap.value("canny");
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene=new QGraphicsScene(this);
    pCannyFilter=new CannyFilter();
    pGaussianBlurFilter=new GaussianBlurFilter();
    qVariantGaussian.setValue(reinterpret_cast<quint64>(pGaussianBlurFilter));
    qVariantCanny.setValue(reinterpret_cast<quint64>(pCannyFilter));
    ui->filterComboBox->addItem("Gaussian Blur",qVariantGaussian);
    ui->filterComboBox->addItem("Canny",qVariantCanny);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_triggered()
{
    QString fileName=QFileDialog::getOpenFileName(this,"Open file","C://");
    inputImage=QImage(fileName);
    scene->addPixmap(QPixmap::fromImage(inputImage));
    ui->graphicsView->setScene(scene);
}


void MainWindow::on_pushButton_clicked()
{
    QVariant variant = this->ui->filterComboBox->currentData();
    IFilter* filter=reinterpret_cast<IFilter*>(variant.value<quint64>());
    scene->addPixmap(QPixmap::fromImage(filter->progress(inputImage)));
    ui->graphicsView->setScene(scene);
}


void MainWindow::on_param1Spinox_valueChanged(int arg1)
{
    QVariant variant = this->ui->filterComboBox->currentData();
    IFilter* filter=reinterpret_cast<IFilter*>(variant.value<quint64>());
    filter->SetParam1((int)arg1);
}


void MainWindow::on_param2Spinox_valueChanged(int arg1)
{
    QVariant variant = this->ui->filterComboBox->currentData();
    IFilter* filter=reinterpret_cast<IFilter*>(variant.value<quint64>());
    filter->SetParam2((int)arg1);

}

