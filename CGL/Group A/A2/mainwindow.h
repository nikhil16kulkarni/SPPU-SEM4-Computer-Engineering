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

private slots:
    void on_pushButton_clicked();
    void circleb(int x1,int y1, int r);
    void circled(int xc,int yc,int r);
    void Bresenham(int x1,int y1,int x2,int y2);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
