#include "mymainwindow.h"
#include "ui_mymainwindow.h"

#include "dialog.h"
#include "ui_dialog.h"

#include "pendialog.h"
#include "ui_pendialog.h"



#include <qfiledialog.h>
#include <qpainter.h>
#include <qmessagebox.h>
#include <QMenuBar>
#include<QBuffer>


#include <QtWidgets>

#include <functional>
#include <utility>

#include <string>
#include"QWidget"
#include <QtGui>
#include "QPixmap"
#include <Qcolor>

MyMainWindow::MyMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyMainWindow)
{
    ui->setupUi(this);





    if(resizeFlag==false)
    {
        height=1600;
        width=1000;
    }


  image33 = new QImage(height,width,QImage::Format_ARGB32);
      image33->fill(Qt::white);





        update();
}

MyMainWindow::~MyMainWindow()
{
    delete ui;
}


void MyMainWindow::paintEvent(QPaintEvent* e)
{
    QPainter paint(this);





    if (! image33->isNull() && loadFlag==false)
        {

        paint.drawImage(0,0,*image33);

         }

    if (! image->isNull() && loadFlag==false)
        {


        paint.drawImage(0,0,*image);


        }

    if (! image99.isNull() && loadFlag==true && undoFlag==false)
        {

        paint.drawImage(0,0,image99);
         image=new QImage();
          image33=new QImage();




        }







}


void MyMainWindow::on_actionNew_triggered()
{
    image=new QImage();
    if(loadFlag==true)
    {
     QImage* img=&image99;
     delete img;
     image33 = new QImage(1600,1200,QImage::Format_ARGB32);
         image33->fill(Qt::white);
         loadFlag = false;
         update();
         this->repaint();



    }
    else
    {
        image33=new QImage();
     image33 = new QImage(1600,1200,QImage::Format_ARGB32);
         image33->fill(Qt::white);

         update();
         this->repaint();
}
}

void MyMainWindow::on_actionLoad_triggered()
{
    QString s = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/home",
                                                    tr("Images (*.bmp)"));
    if (! s.isNull())
    {

       image->load(s);
       image99=createImageWithOverlay(*image33,*image);

       loadFlag=true;

    }

     this->repaint();


}

QImage MyMainWindow::createImageWithOverlay(const QImage& image1, const QImage& image2)
{
    QImage mergedImage = QImage(image1.size(), QImage::Format_ARGB32_Premultiplied);
    QPainter painter(&mergedImage);

    painter.setCompositionMode(QPainter::CompositionMode_Source);
    painter.fillRect(mergedImage.rect(), Qt::transparent);

    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter.drawImage(0, 0, image1);

    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter.drawImage(0, 0, image2);

    painter.end();

    return mergedImage;
}

void MyMainWindow::on_actionSave_triggered()
{
    QByteArray fileFormat="bmp";

    QString initialPath = QDir::currentPath() + "/untitled." + fileFormat;

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),
                               initialPath,
                               tr("%1 Files (*.%2);;All Files (*)")
                               .arg(QString("fileFormat"))
                               .arg(QString(fileFormat)));
    if (fileName.isEmpty()) {

    } else {


         if (! image33->isNull() && loadFlag==false)
         {

        QImage visibleImage = *image33;


        visibleImage.save(fileName, fileFormat);
         }
          if (! image->isNull() && loadFlag==false)
          {

            QImage visibleImage = *image;


           visibleImage.save(fileName, fileFormat);
          }

          if(! image99.isNull() && loadFlag==true)
          {


              image99.save(fileName,fileFormat);



          }


    }

}

void MyMainWindow::on_actionClear_All_triggered()
{
    image=new QImage();
    if(loadFlag==true)
    {

     QImage* img=&image99;
     delete img;

    }
     image33 = new QImage(1600,1200,QImage::Format_ARGB32);
         image33->fill(Qt::white);

         update();
         squareFlag=false;
         EraserFlag=false;
         PenFlag=false;
         lineFlag=false;
         polyFlag=false;
         polyFlag2=false;
         loadFlag=false;
                this->repaint();
}

void MyMainWindow::on_actionPen_triggered()
{
    if(frontColor==false)
    {
    myPenColor=Qt::black;
    }
     myPenWidth=7;
       PenFlag=true;
       squareFlag=false;
      EraserFlag=false;

       lineFlag=false;
       polyFlag=false;
       dialogInt=2;


}


void MyMainWindow::mousePressEvent(QMouseEvent *event)
{
    if(polyFlag!=true)
    {
        if(PenFlag==true || EraserFlag==true || lineFlag==true)
        {
    if (event->button() == Qt::LeftButton) {

        press=event->pos();
}
        }
    }
    if(polyFlag==true  && polyFlag2==false)
    {
            press=event->pos();
            start=press;
    }

    if(polyFlag==true  && polyFlag2==true)
    {

    }
 if(dialogInt==1)
 {
    if (event->button() == Qt::RightButton) {

        Dialog *lineDialog=new Dialog();
         lineDialog->show();
         dialogInt=0;
         d2=true;
             }
}

 if(dialogInt==2)
 {
    if (event->button() == Qt::RightButton) {

        PenDialog *penDialog=new PenDialog();
         penDialog->show();
         dialogInt=0;
         d1=true;

    }

}


}

void MyMainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(polyFlag!=true)
    {
if(PenFlag==true || EraserFlag==true)
{
        doErase(event->pos());
}
    }


}

void MyMainWindow::mouseReleaseEvent(QMouseEvent *event)
{

     if(polyFlag!=true)
    {
        if(PenFlag==true || EraserFlag==true || lineFlag==true)
        {
if (event->button() == Qt::LeftButton) {
 doErase(event->pos());
}

        }
    }
    if(polyFlag==true && polyFlag2==false)
    {
        if (event->button() == Qt::LeftButton) {
            lineFlag=true;
         doErase(event->pos());

        }

    }

    if(polyFlag==true && polyFlag2==true)
    {
        if (event->button() == Qt::LeftButton) {
            lineFlag=true;
         doErase(event->pos());

        }

    }

    if(rectangleFlag==true)
    {
        QPainter painter(image33);
        QColor(text);
        text = QColorDialog::getColor(text,this,tr("Choose Your Color..."));

        painter.setBrush(text);
         height = QInputDialog::getInt(this,tr("Integer"),tr("Enter Height Of Your Rectangle:"));
         width = QInputDialog::getInt(this,tr("Integer"),tr("Enter Width Of Your Rectangle:"));


        painter.drawRect(event->pos().x(),event->pos().y(),width,height);

        update();
        rectangleFlag=false;

    }


}

void MyMainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
if (event->button() == Qt::LeftButton) {

    if(loadFlag==false)
    {
   QPainter paint(image33);
   paint.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
                       Qt::RoundJoin));
   paint.drawLine(start,press);
   update();
    }
    if(loadFlag==true)
    {
   QPainter paint(&image99);
   paint.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
                       Qt::RoundJoin));
   paint.drawLine(start,press);
   update();
    }
}

if(d1=true || d2==true)
{
    d1=false;
    d2=false;
}
}

void MyMainWindow::doErase(const QPoint &endPoint)
{

    if(loadFlag==false)
    {
  if(PenFlag==true || EraserFlag==true)

  {
      if (! image->isNull())
      {

      QPainter painter(image);



      painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
                          Qt::RoundJoin));

      painter.drawLine(press, endPoint);


      int rad = (myPenWidth / 2) + 2;
      update(QRect(press, endPoint).normalized()
                                       .adjusted(-rad, -rad, +rad, +rad));
      press = endPoint;
      }

      if (! image33->isNull())
      {
      QPainter painter(image33);

           if(d1==false)
           {
           painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,Qt::RoundJoin));
           painter.drawLine(press, endPoint);
}
           if(d1==true)
           {
           painter.setPen(QPen(myPenColor,15, Qt::DashDotDotLine, Qt::RoundCap,Qt::RoundJoin));

           painter.drawLine(press, endPoint);
           }



           int rad = (myPenWidth / 2) + 2;
           update(QRect(press, endPoint).normalized()
                                            .adjusted(-rad, -rad, +rad, +rad));





      press = endPoint;
      }


  }





  if(lineFlag==true)
  {
    if (! image->isNull())
    {
    QPainter painter(image);
    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));
    painter.drawLine(press.x(),press.y(), endPoint.x(),endPoint.y());


    int rad = (myPenWidth / 2) + 2;
    update(QRect(press, endPoint).normalized()
                                     .adjusted(-rad, -rad, +rad, +rad));
    press = endPoint;

    }

    if (! image33->isNull())
    {
        QPainter painter(image33);
        if(d2==false)
        {

    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));
    painter.drawLine(press.x(),press.y(), endPoint.x(),endPoint.y());
        }

        if(d2==true)
        {

    painter.setPen(QPen(myPenColor, 9, Qt::DotLine, Qt::RoundCap,
                        Qt::RoundJoin));
    painter.drawLine(press.x(),press.y(), endPoint.x(),endPoint.y());
        }


    int rad = (myPenWidth / 2) + 2;
    update(QRect(press, endPoint).normalized()
                                     .adjusted(-rad, -rad, +rad, +rad));
    press = endPoint;

    }
  }

  if(lineFlag==true && polyFlag==true)
  {
    if (! image->isNull())
    {
    QPainter painter(image);
    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));
    painter.drawLine(press.x(),press.y(), endPoint.x(),endPoint.y());


    int rad = (myPenWidth / 2) + 2;
    update(QRect(press, endPoint).normalized()
                                     .adjusted(-rad, -rad, +rad, +rad));
    press = endPoint;
    polyFlag=true;
    polyFlag2=true;

    }

    if (! image33->isNull())
    {
    QPainter painter(image33);
    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));
    painter.drawLine(press.x(),press.y(), endPoint.x(),endPoint.y());


    int rad = (myPenWidth / 2) + 2;
    update(QRect(press, endPoint).normalized()
                                     .adjusted(-rad, -rad, +rad, +rad));
    press = endPoint;
    polyFlag=true;
    polyFlag2=true;

    }
  }

}

    if(loadFlag==true)
    {
  if(PenFlag==true || EraserFlag==true)

  {
      if (! image99.isNull())
      {

      QPainter painter(&image99);
      painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
                          Qt::RoundJoin));
      painter.drawLine(press, endPoint);


      int rad = (myPenWidth / 2) + 2;
      update(QRect(press, endPoint).normalized()
                                       .adjusted(-rad, -rad, +rad, +rad));
      press = endPoint;
      }



  }





  if(lineFlag==true)
  {
    if (! image99.isNull())
    {
    QPainter painter(&image99);
    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));
    painter.drawLine(press.x(),press.y(), endPoint.x(),endPoint.y());


    int rad = (myPenWidth / 2) + 2;
    update(QRect(press, endPoint).normalized()
                                     .adjusted(-rad, -rad, +rad, +rad));
    press = endPoint;

    }


  }

  if(lineFlag==true && polyFlag==true)
  {
    if (! image99.isNull())
    {
    QPainter painter(&image99);
    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));
    painter.drawLine(press.x(),press.y(), endPoint.x(),endPoint.y());


    int rad = (myPenWidth / 2) + 2;
    update(QRect(press, endPoint).normalized()
                                     .adjusted(-rad, -rad, +rad, +rad));
    press = endPoint;
    polyFlag=true;
    polyFlag2=true;

    }


  }

}
}

void MyMainWindow::on_actionEraser_triggered()
{

    myPenColor=Qt::white;
    myPenWidth=7;
    EraserFlag=true;
    squareFlag=false;

    PenFlag=false;
    lineFlag=false;
    polyFlag=false;
    frontColor=false;

}

void MyMainWindow::on_actionLine_triggered()
{

    if(frontColor==false)
    {
    myPenColor=Qt::black;
    }
     myPenWidth=7;

 lineFlag=true;
 squareFlag=false;
 EraserFlag=false;
 PenFlag=false;
 polyFlag=false;

 dialogInt=1;



}

void MyMainWindow::on_actionFront_Color_triggered()
{
    QColor(text);
    text = QColorDialog::getColor(text,this,tr("Choose Your Color..."));

    if(text.isValid())
    {
        myPenColor=text;
        myPenWidth=7;
        PenFlag=true;
        lineFlag=false;
        EraserFlag=false;
        squareFlag=false;
        frontColor=true;
    }
}

void MyMainWindow::on_actionBackground_Color_triggered()
{
    QColor(text);
    text = QColorDialog::getColor(text,this,tr("Choose Your Color..."));

    if(text.isValid())
    {

    image33->fill(text);



     update();

     this->repaint();
  }


}

void MyMainWindow::on_actionPoly_Line_triggered()
{
    if(frontColor==false)
    {
    myPenColor=Qt::black;
    }
     myPenWidth=7;

 squareFlag=false;

 EraserFlag=false;
 PenFlag=false;
 lineFlag=false;
 polyFlag=true;

}





void MyMainWindow::on_actionResize_triggered()
{

    height = QInputDialog::getInt(this,tr("Integer"),tr("Enter Height to resize window:"));
     width = QInputDialog::getInt(this,tr("Integer"),tr("Enter Width to resize window:"));

    resizeFlag=true;
    QImage* temp=&image99;
    delete temp;


    image33 = new QImage(width,height,QImage::Format_ARGB32);
        image33->fill(Qt::white);
        update();

}

void MyMainWindow::on_actionRectangle_triggered()


{

   rectangleFlag=true;
}

void MyMainWindow::on_actionUndo_triggered()
{
        image22=image99;
        delete &image99;
    image33 = new QImage(height,width,QImage::Format_ARGB32);
        image33->fill(Qt::white);


    repaint();
}

void MyMainWindow::on_actionRedo_triggered()
{
      image99=image22;
      delete image33;
      delete image;
      update();
}
