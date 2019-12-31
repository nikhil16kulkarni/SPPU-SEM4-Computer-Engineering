#include "mainwindow.h"
#include "ui_mainwindow.h"
QImage image(300, 300, QImage::Format_RGB888);
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

void MainWindow::on_pushButton_clicked()
{

    QString s= ui->textEdit->toPlainText();
    float x1=s.toFloat();
    s= ui->textEdit_3->toPlainText();
    float y1=s.toFloat();
    s=ui->textEdit_2->toPlainText();
    float l=s.toFloat();
    s=ui->textEdit_4->toPlainText();
    float b=s.toFloat();
    DDA(x1,y1+b/2,x1+l/2,y1);
    DDA(x1,y1+b/2,x1+l/2,y1+b);
    DDA(x1+l,y1+b/2,x1+l/2,y1+b);
    DDA(x1+l/2,y1,x1+l,y1+b/2);

 }
void MainWindow::DDA(float x1,float y1,float x2,float y2)
{

    float x,y,dx,dy;

    float length;
    if(abs(x2-x1)>=abs(y2-y1))
      length=abs(x2-x1);
    else
      length=abs(y2-y1);
    dx=(x2-x1)/length;
    dy=(y2-y1)/length;
    x=x1+0.5;
    y=y1+0.5;
    int i=1;
    while(i<=length)
    {
       image.setPixel((int)x,(int)y,qRgb(0,0,255));
       x=x+dx;
       y=y+dy;
       i++;
    }

    ui->label_5->setPixmap(QPixmap::fromImage(image));
    ui->label_5->show();


}
void MainWindow::BA(float x1,float y1,float x2,float y2)
{

    float x,y,dx,dy,e;
    int i=1;
    x=x1;
    y=y1;
    dx=x2-x1;
    dy=y2-y1;
    float temp;
    int inter=0;
    if(dy>dx)
    {
        temp=dx;
        dx=dy;
        dy=temp;
        inter=1;
    }
    e=2*dy-dx;
    while(i<dx)
    {
        image.setPixel((int)x,(int)y,qRgb(0,0,255));
        while(e>0)
        {
           if(inter==1)
               x=x+1;
           else
               y=y+1;

           e=e-2*dx;
        }
        if(inter==1)
        y=y+1;
        else
            x=x+1;

        e=e+2*dy;
        i++;
    }
    ui->label_5->setPixmap(QPixmap::fromImage(image));
    ui->label_5->show();

}
void MainWindow::on_pushButton_2_clicked()
{

   QString s= ui->textEdit->toPlainText();
   float x1=s.toFloat();
   s= ui->textEdit_3->toPlainText();
   float y1=s.toFloat();
   s=ui->textEdit_2->toPlainText();
   float l=s.toFloat();
   s=ui->textEdit_4->toPlainText();
   float b=s.toFloat();
   float x2,y2,x3,y3,x4,y4;
   x2=x1+l;
   y2=y1;
   x3=x1;
   y3=y1+b;
   x4=x1+l;
   y4=y1+b;
   BA(x1,y1,x2,y2);
   BA(x1,y1,x3,y3);
   BA(x3,y3,x4,y4);
   BA(x2,y2,x4,y4);
}

void MainWindow::on_pushButton_3_clicked()
{
    QString s= ui->textEdit->toPlainText();
    float x1=s.toFloat();
    s= ui->textEdit_3->toPlainText();
    float y1=s.toFloat();
    s=ui->textEdit_2->toPlainText();
    float l=s.toFloat();
    s=ui->textEdit_4->toPlainText();
    float b=s.toFloat();
    float x2,y2,x3,y3,x4,y4;
    x2=x1+l;
    y2=y1;
    x3=x1;
    y3=y1+b;
    x4=x1+l;
    y4=y1+b;
    BA(x1,y1,x2,y2);
    BA(x1,y1,x3,y3);
    BA(x3,y3,x4,y4);
    BA(x2,y2,x4,y4);
    DDA(x1,y1+b/2,x1+l/2,y1);
    DDA(x1,y1+b/2,x1+l/2,y1+b);
    DDA(x1+l,y1+b/2,x1+l/2,y1+b);
    DDA(x1+l/2,y1,x1+l,y1+b/2);
    BA(x1+l/4,y1+b/4,x1+3*l/4,y1+b/4);
    BA(x1+l/4,y1+b/4,x1+l/4,y1+3*b/4);
    BA(x1+l/4,y1+3*b/4,x1+3*l/4,y1+3*b/4);
    BA(x1+3*l/4,y1+b/4,x1+3*l/4,y1+3*b/4);

}





