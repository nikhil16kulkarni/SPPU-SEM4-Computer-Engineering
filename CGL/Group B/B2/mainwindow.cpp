#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QMouseEvent"
#include"QtDebug"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    start=true;
    ver=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

QImage img=QImage(500,500,QImage::Format_RGB888);
void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if(start)
    {
        int p=ev->pos().x();
        int q=ev->pos().y();
        a[ver]=p;
        b[ver]=q;
        if(ev->button()==Qt::RightButton)
        {
            bres(a[ver],b[ver],a[0],b[0]);
            start=false;




        }
        else
        {
            if(ver>0)
            {
                bres(a[ver],b[ver],a[ver-1],b[ver-1]);
            }
        }
        ver++;
    }
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *ev)
{
    int p=ev->pos().x();
    int q=ev->pos().y();
    QRgb old=qRgb(0,0,0);
    QRgb ne=qRgb(255,0,255);
    seedfill(p,q,old,ne);
ui->label->setPixmap(QPixmap::fromImage(img));

}


void MainWindow::bres(int x1,int y1,int x2,int y2)
{
    int sx=sign(x2-x1),sy=sign(y2-y1);
    int dx=abs(x2-x1),dy=abs(y2-y1);
    int x=x1,y=y1;
    int e,inte=0;
    if(dy>dx)
    {
        int temp=dy;
        dy=dx;
        dx=temp;
        inte=1;
    }
    e=2*dy-dx;
    QRgb val=qRgb(0,255,0);
    for(int i=0;i<dx;i++)
    {
     img.setPixel(x-6,y+65,val);
     while(e>=0)
     {
         if(inte)
         {x+=sx;}
         else
         {
             y+=sy;
         }
         e-=2*dx;
     }
     if(inte)
     {
         y+=sy;
     }
     else
     {
         x+=sx;
     }
     e+=2*dy;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

int MainWindow::sign(int x)
{
    if(x==0)
    {
        return 0;
    }
    if(x>0)
    {
        return 1;
    }
    return -1;
}


void MainWindow::seedfill(int x,int y,QRgb old,QRgb col)
{
   if(x<0 || y<0 || x>500 || y>500)
    {
        return ;}

    QRgb curr=img.pixel(x,y);
    if(curr==old)
    {
        img.setPixel(x,y,col);
        seedfill(x-1,y,old,col);
        seedfill(x+1,y,old,col);
        seedfill(x,y+1,old,col);
        seedfill(x,y-1,old,col);
    }
}
