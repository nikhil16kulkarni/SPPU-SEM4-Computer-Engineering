#include "mainwindow.h"
#include "ui_mainwindow.h"

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

int sign(int x2,int x1){
    if(x2>x1)   return 1;
    else if(x2<x1)  return -1;
    else    return 0;
}
/*void MainWindow::bresenham(int x1, int y1, int x2, int y2){

}*/


/*void MainWindow::on_pushButton_3_clicked()
{
    QImage image(300, 300, QImage::Format_RGB888);
    QRgb value;
    //draws pixel in white color at x,y
    //position.

    //shows pixel on screen

    QString X1=ui->textEdit->toPlainText();
    QString Y1=ui->textEdit_2->toPlainText();
    QString X2=ui->textEdit_3->toPlainText();
    QString Y2=ui->textEdit_4->toPlainText();

    int x_1=X1.toInt();
    int y_1=Y1.toInt();
    int x_2=X2.toInt();
    int y_2=Y2.toInt();

    float dx=abs(x_2-x_1);
    float dy=abs(y_1-y_2);

    float length;
    if(dx>=dy)  length=dx;
    else    length=dy;

    float ddx=(x_2-x_1)/length;
    float ddy=(y_2-y_1)/length;

    float x=x_1+0.5;
    float y=y_1+0.5;

    int i=1;
    while(i<=length){
        int X=x;
        int Y=y;
        value=qRgb(0,255,0); //set color of pixel as green
        //image.setPixel(50,50,value); //draws pixel with value

        image.setPixel(X,Y,value);
    //    image.setPixel(150,150,qRgb(255,255,255));
        x=x+ddx;
        y=y+ddy;
        i++;
    }


    ui->label_5->setPixmap(QPixmap::fromImage(image));
    ui->label->show();





}*/

void MainWindow::on_pushButton_clicked()
{
    QImage image(300, 300, QImage::Format_RGB888);
    QRgb value;

    QString x_1=ui->textEdit->toPlainText();
    QString y_1=ui->textEdit_2->toPlainText();
    QString x_2=ui->textEdit_3->toPlainText();
    QString y_2=ui->textEdit_4->toPlainText();

    int x1=x_1.toInt();
    int y1=y_1.toInt();
    int x2=x_2.toInt();
    int y2=y_2.toInt();

    int dx=abs(x2-x1);
    int dy=abs(y2-y1);
    int s1=sign(x2,x1);
    int s2=sign(y2,y1);

    int interchange=0;

    if(dy>dx){
        int temp=dx;
        dx=dy;
        dy=temp;
        interchange=1;
    }
    else    interchange=0;

    int e=2*dy-dx;
    int x=x1;
    int y=y1;
    for(int i=1;i<=dx;i++){
        value=qRgb(0,255,0);
        image.setPixel(x,y,value);
        while(e>0){
            if(interchange=1)   x=x+s1;
            else    y=y+s2;
            e=e-2*dx;
        }
        if(interchange==1)  y=y+s2;
        else    x=x+s1;
        e=e+2*dy;
    }
}
