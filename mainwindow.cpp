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


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene=new QGraphicsScene(this);
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
    if(ui->comboBox->currentText()=="GaussianBlur")
    {
        if(!(gaussianBlurFilter.ksizeHeight%2==0 && gaussianBlurFilter.ksizeWidth%2==0))
        {
            scene->addPixmap(QPixmap::fromImage(gaussianBlurFilter.progress(inputImage)));
        }
        else
        {
            QMessageBox::information(this,"Ошибка","Введите нечетное число");
        }
    }
    else if(ui->comboBox->currentText()=="Canny")
    {
        scene->addPixmap(QPixmap::fromImage(cannyFilter.progress(inputImage)));
    }
    ui->graphicsView->setScene(scene);
}


void MainWindow::on_param1Spinox_valueChanged(int arg1)
{
    if(ui->comboBox->currentText()=="GaussianBlur")
    {
         gaussianBlurFilter.param1((int)arg1);
    }
    else if(ui->comboBox->currentText()=="Canny")
    {
         cannyFilter.param1((int)arg1);
    }
}


void MainWindow::on_param2Spinox_valueChanged(int arg1)
{
    if(ui->comboBox->currentText()=="GaussianBlur")
    {
         gaussianBlurFilter.param2((int)arg1);
    }
    else if(ui->comboBox->currentText()=="Canny")
    {
         cannyFilter.param2((int)arg1);
    }
}

