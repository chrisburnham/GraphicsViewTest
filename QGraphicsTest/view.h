#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QWheelEvent>
#include <QKeyEvent>
#include <QGLWidget>

class View : public QGraphicsView
{
  Q_OBJECT
public:
  explicit View(QWidget *parent = 0) :
    QGraphicsView(parent)
  {
    setDragMode(QGraphicsView::ScrollHandDrag);

    QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(QPixmap(":/images/chart.png"));
    pixmapItem->setTransformationMode(Qt::SmoothTransformation);

    QGraphicsScene *scene = new QGraphicsScene();
    scene->addItem(pixmapItem);
    setScene(scene);
  }

protected Q_SLOTS:
  void wheelEvent(QWheelEvent *event)
  {
    if(event->delta() > 0)
      scale(1.25, 1.25);
    else
      scale(0.8, 0.8);
  }

  void keyPressEvent(QKeyEvent *event)
  {
    if(event->key() == Qt::Key_Left)
      rotate(1);
    else if(event->key() == Qt::Key_Right)
      rotate(-1);
  }
};

#endif // VIEW_H
