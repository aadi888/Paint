#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>



namespace Ui {
class MyMainWindow;
}

class MyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyMainWindow(QWidget *parent = 0);
    ~MyMainWindow();
    void paintEvent(QPaintEvent *event);
    bool resizeFlag=false;
    int height;
    int width;
    bool rectangleFlag=false;
    bool undoFlag=false;
    bool redoFlag=false;
    bool d1=false;
    bool d2=false;




private slots:
    void on_actionNew_triggered();

    void on_actionLoad_triggered();
    void on_actionSave_triggered();

    void on_actionClear_All_triggered();

    void on_actionPen_triggered();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
 void mouseDoubleClickEvent(QMouseEvent *event);

 void on_actionEraser_triggered();

 void on_actionLine_triggered();

 void on_actionFront_Color_triggered();

 void on_actionBackground_Color_triggered();

 void on_actionPoly_Line_triggered();

 void on_actionResize_triggered();


 void on_actionRectangle_triggered();

 void on_actionUndo_triggered();

 void on_actionRedo_triggered();

public slots:
QImage createImageWithOverlay(const QImage& baseImage, const QImage& overlayImage);
void doErase(const QPoint &endPoint);

private:
    Ui::MyMainWindow *ui;
private:
QImage* image;
QImage* image33;

int myPenWidth;





QImage image22;
QImage image99;

//QPixmap image12;
//QPixmap image44;
//QPixmap image55;
QImage  imageObject;
QWidget *m_pMyWidget;
QPalette* palette;
QPixmap newPixmap;
int dialogInt=0;
bool save(const QByteArray &file);
QPoint press;
QPoint start;
QPoint release;
QColor myPenColor;

bool squareFlag=false;
bool EraserFlag=false;
bool PenFlag=false;
bool lineFlag=false;
bool polyFlag=false;
bool polyFlag2=false;
bool loadFlag=false;
bool frontColor=false;






};

#endif // MYMAINWINDOW_H
