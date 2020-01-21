#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<cmath>
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
QImage image(300,300,QImage::Format_RGB888);



void MainWindow::on_pushButton_2_clicked()
{
    QImage image(300,300,QImage::Format_RGB888);
    QRgb value;
    QString x1=ui->textEdit->toPlainText();
    QString y1=ui->textEdit_2->toPlainText();
    QString x2=ui->textEdit_3->toPlainText();
    QString y2=ui->textEdit_4->toPlainText();
    float x_o=x1.toFloat();
    float y_o=y1.toFloat();
    float x_s=x2.toFloat();
    float y_s=y2.toFloat();
    float dx=abs(x_s-x_o);
    float dy=abs(y_s-y_o);
    float length;
    if(dx>dy)
    {
        length=dx;
    }
    else
    {
        length=dy;
    }
    dx=dx/length;
    dy=dy/length;
    float x=x_o+0.5;
    float y=y_o+0.5;
    int i=1;
    int flag=0;
    while(i<=length)
    {
        int X=x;
        int Y=y;
        if(flag==0||flag==1||flag==2)
        {
            value=qRgb(0,255,0);
            image.setPixel(X,Y,value);
            flag++;
        }
        else
        {
            flag=0;
        }
        x=x+dx;
        y=y+dy;
        i++;
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    QImage image(700,700,QImage::Format_RGB888);
    QRgb value;
    QString x1=ui->textEdit->toPlainText();
    QString y1=ui->textEdit_2->toPlainText();
    QString x2=ui->textEdit_3->toPlainText();
    QString y2=ui->textEdit_4->toPlainText();
    float x_o=x1.toFloat();
    float y_o=y1.toFloat();
    float x_s=x2.toFloat();
    float y_s=y2.toFloat();
    float dx=abs(x_s-x_o);
    float dy=abs(y_s-y_o);
    float length;
    if(dx>dy)
    {
        length=dx;
    }
    else
    {
        length=dy;
    }
    dx=dx/length;
    dy=dy/length;
    float x=x_o+0.5;
    float y=y_o+0.5;
    int i=1;
    int flag=0,flag1=0;
    while(i<=length)
    {
        int X=x;
        int Y=y;
        if(flag==0||flag==1||(flag==2&&flag1==0))
        {
            value=qRgb(0,255,0);
            image.setPixel(X,Y,value);
            flag++;
        }
        else if(flag1==0)
        {
            flag1++;
        }
        else if(flag1==1&&flag==3)
        {
            value=qRgb(0,255,0);
            image.setPixel(X,Y,value);
            flag1=0;
            flag++;
        }
       else
        {
            flag=0;
            flag1=0;
        }
        x=x+dx;
        y=y+dy;
        i++;
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    QImage image(300,300,QImage::Format_RGB888);
    QRgb value;
    QString x1=ui->textEdit->toPlainText();
    QString y1=ui->textEdit_2->toPlainText();
    QString x2=ui->textEdit_3->toPlainText();
    QString y2=ui->textEdit_4->toPlainText();
    float x_o=x1.toFloat();
    float y_o=y1.toFloat();
    float x_s=x2.toFloat();
    float y_s=y2.toFloat();
    float dx=abs(x_s-x_o);
    float dy=abs(y_s-y_o);
    float length;
    if(dx>dy)
    {
        length=dx;
    }
    else
    {
        length=dy;
    }
    dx=dx/length;
    dy=dy/length;
    float x=x_o+0.5;
    float y=y_o+0.5;
    int i=1;
    while(i<=length)
    {
        int X=x;
        int Y=y;
        value=qRgb(0,255,0);
        image.setPixel(X,Y,value);
        x=x+dx;
        y=y+dy;
        i++;
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}
int MainWindow:: sign(int x1,int x2)
{
    if(x2-x1<0)
    {
        return -1;
    }
    else if(x2-x1==0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void MainWindow::Bresenham(int x1,int y1,int x2,int y2)
{

    QRgb value;
    int dx=abs(x2-x1);
    int dy=abs(y2-y1);
    int s1=sign(x1,x2);
    int s2=sign(y1,y2);
    int Interchange=0;
    if(dy>dx)
    {
        int temp=dx;
        dx=dy;
        dy=temp;
        Interchange=1;
    }
    int e=2*dy-dx;
    int x=x1;
    int y=y1;
    for(int i=1;i<=dx;i++)
    {
        value=qRgb(0,255,0);
        image.setPixel(x,y,value);
        while(e>0)
        {
            if(Interchange==1)
            {
                x=x+s1;
            }
            else
            {
                y=y+s2;
            }
            e=e-2*dx;
        }
        if(Interchange==1)
        {
            y=y+s2;
        }
        else
        {
            x=x+s1;
        }
        e=e+2*dy;
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}


void MainWindow::on_pushButton_clicked()
{
    QImage image(300,300,QImage::Format_RGB888);
    QRgb value;
    QString x1=ui->textEdit->toPlainText();
    QString y1=ui->textEdit_2->toPlainText();
    QString x2=ui->textEdit_3->toPlainText();
    QString y2=ui->textEdit_4->toPlainText();
    float x_o=x1.toFloat();
    float y_o=y1.toFloat();
    float x_s=x2.toFloat();
    float y_s=y2.toFloat();
    float dx=abs(x_s-x_o);
    float dy=abs(y_s-y_o);
    float length;
    if(dx>dy)
    {
        length=dx;
    }
    else
    {
        length=dy;
    }
    dx=dx/length;
    dy=dy/length;
    float x=x_o+0.5;
    float y=y_o+0.5;
    int i=1;
    int flag=0;
    while(i<=length)
    {
        int X=x;
        int Y=y;
        if(flag==0)
        {
            value=qRgb(0,255,0);
            image.setPixel(X,Y,value);
            flag=1;
        }
        else
        {
            flag=0;
        }
        x=x+dx;
        y=y+dy;
        i++;
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}

void MainWindow::on_pushButton_5_clicked()
{
    QRgb value;
        QString x1=ui->textEdit->toPlainText();
        QString y1=ui->textEdit_2->toPlainText();
        QString x2=ui->textEdit_3->toPlainText();
        QString y2=ui->textEdit_4->toPlainText();
        QString w1=ui->textEdit_5->toPlainText();
        float x_o=x1.toFloat();
        float y_o=y1.toFloat();
        float x_s=x2.toFloat();
        float y_s=y2.toFloat();
        float dx=abs(x_s-x_o);
        float dy=abs(y_s-y_o);
        int w = w1.toInt();
        float length;
        if(dx>dy)
        {
            length=dx;
        }
        else
        {
            length=dy;
        }
        Bresenham(x_o,y_o,x_s,y_s);
        int wy,wx;
        if((y_s-y_o)/(x_s-x_o)<1)
           {
               wy=(w-1)*sqrt(pow((x_s-x_o),2)+pow((y_s-y_o),2))/(2*abs(x_s-x_o));
               for(int i=0;i<wy;i++)
               {
                   Bresenham(x_o,y_o-i,x_s,y_s-i);
                   Bresenham(x_o,y_o+i,x_s,y_s+i);
               }
           }
            else
           {
               wx=(w-1)*sqrt(pow((x_s-x_o),2)+pow((y_s-y_o),2))/(2*abs(y_s-y_o));
               for(int i=0;i<wx;i++)
               {
                   Bresenham(x_o-i,y_o,x_s-i,y_s);
                   Bresenham(x_o+i,y_o,x_s+i,y_s);
               }
       }

        ui->label->setPixmap(QPixmap::fromImage(image));
        ui->label->show();
}
