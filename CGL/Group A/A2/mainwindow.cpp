#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

QImage image(300,300,QImage::Format_RGB888);

MainWindow::~MainWindow()
{
    delete ui;
}

void mh(int &x,int &y,int &di){
    x++;
    di=di+2*x+1;
}

void md(int &x,int &y,int &di){
    x++;
    y--;
    di=di+2*x-2*y+2;
}

void mv(int &x,int &y,int &di){
    y--;
    di=di-2*y+1;
}

void MainWindow::circleb(int x1,int y1,int r){
    QRgb value;
    int di=2*(1-r);
    int ds=0,ds1;
    int limit=0;
    int x=0;
    int y=r;

    while(y>=limit){
        value=qRgb(0,255,0);
        image.setPixel(x+x1,y+y1,value);
        image.setPixel(x1-x,y1-y,value);
        image.setPixel(x1-x,y1+y,value);
        image.setPixel(x1+x,y1-y,value);

        if(di<0){
            ds=2*di+2*y-1;
            if(ds<=0){
                mh(x,y,di);
            }
            else{
                md(x,y,di);
            }
        }
        else if(di>0){
            ds=2*di-2*x-1;
            if(ds<=0){
                md(x,y,di);
            }
            else{
                mv(x,y,di);
            }
        }
        else{
            md(x,y,di);
        }
    }
    ui->label_4->setPixmap(QPixmap::fromImage(image));
    ui->label_4->show();
}

void MainWindow::circled(int xc,int yc,int r){
    QRgb value;
    float xc1,xc2,yc1,yc2,eps,sx,sy;

      int val,i;

      xc1=r;

      yc1=0;

      sx=xc1;

      sy=yc1;

      i=0;

      do{

          val=pow(2,i);

          i++;

          }while(val<r);

      eps = 1/pow(2,i-1);

      do{

          xc2 = xc1 + yc1*eps;
          yc2 = yc1 - eps*xc2;
        value=qRgb(0,255,0);
          image.setPixel(xc+xc2,yc-yc2,value);

          xc1=xc2;

          yc1=yc2;

         }while((yc1-sy)<eps || (sx-xc1)>eps);

      ui->label_4->setPixmap(QPixmap::fromImage(image));
      ui->label_4->show();

}

int sign(int x1,int x2)
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
{ QRgb value;
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
    ui->label_4->setPixmap(QPixmap::fromImage(image));
    ui->label_4->show();
}


void MainWindow::on_pushButton_clicked()
{
    QString s=ui->textEdit->toPlainText();
    float x1=s.toInt();
    s=ui->textEdit_2->toPlainText();
    float y1=s.toInt();
    s=ui->textEdit_3->toPlainText();
    float r=s.toInt();
    image.setPixel(x1,y1,qRgb(0,0,255));

    circleb(x1,y1,r); //Outer Circle

    Bresenham(x1,y1-r,x1+sqrt(3)*r/2,y1+r/2);//Inscribed Triangle
    Bresenham(x1,y1-r,x1-sqrt(3)*r/2,y1+r/2);//Inscribed Triangle
    Bresenham(x1+sqrt(3)*r/2,y1+r/2,x1-sqrt(3)*r/2,y1+r/2);//Inscribed Triangle

    circled(x1,y1,r/2); //Inner Circle
}
