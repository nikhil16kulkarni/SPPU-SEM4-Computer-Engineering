#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
void mousePressEvent(QMouseEvent *ev);
void bres(int x1,int y1,int x2,int y2);
int sign(int x);
void seedfill(int x,int y,QRgb old,QRgb col);
void mouseDoubleClickEvent(QMouseEvent *ev);

private:
    Ui::MainWindow *ui;
    bool start;
    int a[100],b[100];
    int ver;
};

#endif // MAINWINDOW_H
