QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cannyfilter.cpp \
    gaussianblurfilter.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    cannyfilter.h \
    gaussianblurfilter.h \
    ifilter.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
INCLUDEPATH += D:\opencv\build\include
LIBS += -LD:\opencv\build\bin\ -llibopencv_core480
LIBS += -LD:\opencv\build\bin\ -llibopencv_highgui480
LIBS += -LD:\opencv\build\bin\ -llibopencv_imgcodecs480
LIBS += -LD:\opencv\build\bin\ -llibopencv_imgproc480
LIBS += -LD:\opencv\build\bin\ -llibopencv_features2d480
LIBS += -LD:\opencv\build\bin\ -llibopencv_calib3d480
LIBS += -LD:\opencv\build\bin\ -llibopencv_video480
LIBS += -LD:\opencv\build\bin\ -llibopencv_videoio480
LIBS += -LD:\opencv\build\bin\ -llibopencv_stitching480
LIBS += -LD:\opencv\build\bin\ -llibopencv_photo480
LIBS += -LD:\opencv\build\bin\ -llibopencv_objdetect480
LIBS += -LD:\opencv\build\bin\ -llibopencv_gapi480
LIBS += -LD:\opencv\build\bin\ -llibopencv_flann480
LIBS += -LD:\opencv\build\bin\ -llibopencv_dnn480
