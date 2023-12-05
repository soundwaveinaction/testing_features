#ifndef IFILTER_H
#define IFILTER_H

#include <QImage>

class IFilter
{
public:

    ~IFilter(){};
    virtual void  SetParam1(int param)=0;
    virtual void  SetParam2(int param)=0;
    virtual int  GetParam1()=0;
    virtual int  GetParam2()=0;
    virtual QImage progress(QImage &image)=0;
};
Q_DECLARE_METATYPE(IFilter*)
#endif // IFILTER_H
