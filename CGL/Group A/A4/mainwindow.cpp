#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
QImage image(361,361,QImage::Format_RGB888);
QImage temp(31,31,QImage::Format_RGB888);
int rvalue,gvalue,bvalue;
int sign(int a)
{
    if(a>0)
        return 1;
    if(a<0)
        return -1;
    return 0;
}
void Bresenhams(float x1,float y1,float x2,float y2)
{
    int x=x1,temp,y=y1;
    int dx=abs(x1-x2),dy=abs(y1-y2);
    int s1=sign(x2-x1),s2=sign(y2-y1),intrch,e,i;
    if(dy>dx)
    {
        temp=dx;
        dx=dy;
        dy=temp;
        intrch=1;
    }
    else
    {
        intrch=0;
    }
    e=2*dy-dx;
    for(i=1;i<=dx;i++)
    {
        image.setPixel(x,y,qRgb(rvalue,gvalue,bvalue));
        while(e>0)
        {
            if(intrch)
                x=x+s1;
            else
                y=y+s2;
            e=e-2*dx;
        }
        if(intrch)
            y=y+s2;
        else
            x=x+s1;
        e=e+2*dy;
    }
}
int ct=0;
float x1[10],y1[10];
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    float erx=ui->label->x(),ery=ui->label->y();
    int i;
    if(event->button()==Qt::LeftButton)
    {
        x1[ct]=(event->pos().x())-erx;
        y1[ct]=(event->pos().y())-ery;
        image.setPixel(x1[ct],y1[ct],qRgb(rvalue,gvalue,bvalue));
        ct++;
    }
    else if(event->button()==Qt::RightButton)
    {
        for(i=0;i<ct-1;i++)
            Bresenhams(x1[i],y1[i],x1[i+1],y1[i+1]);
        if(ct!=1)
            Bresenhams(x1[ct-1],y1[ct-1],x1[0],y1[0]);

        ct=0;
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}

void MainWindow::on_pushButton_clicked()
{
    for(int i=0;i<361;i++)
        for(int j=0;j<361;j++)
            image.setPixel(i,j,qRgb(0,0,0));
    ct=0;
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    rvalue=value;
    for(int i=0;i<31;i++)
        for(int j=0;j<31;j++)
      //     temp.setPixel(i,j,QRgb(rvalue,gvalue,bvalue));
    ui->label_5->setPixmap(QPixmap::fromImage(temp));
    ui->label_5->show();
}

void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    gvalue=value;
    for(int i=0;i<31;i++)
        for(int j=0;j<31;j++)
      //      temp.setPixel(i,j,QRgb(rvalue,gvalue,bvalue));
    ui->label_5->setPixmap(QPixmap::fromImage(temp));
    ui->label_5->show();
}

void MainWindow::on_horizontalSlider_3_valueChanged(int value)
{
    bvalue=value;
    for(int i=0;i<31;i++)
        for(int j=0;j<31;j++)
          //  temp.setPixel(i,j,QRgb(rvalue,gvalue,bvalue));
    ui->label_5->setPixmap(QPixmap::fromImage(temp));
    ui->label_5->show();
}
