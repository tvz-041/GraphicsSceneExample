#include <QGraphicsScene>

#include "GraphicsRectItem.h"

#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
  , m_scene(new QGraphicsScene(this))
{
  ui->setupUi(this);
  ui->graphicsView->setScene(m_scene);

  connect(ui->pushButton_clear, &QPushButton::clicked, m_scene, &QGraphicsScene::clear);
  connect(ui->pushButton_addRect, &QPushButton::clicked, this, [this]() {
      addRectangle(ui->lineEdit_rectText->text());
  });
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::addRectangle(const QString &text)
{
  GraphicsRectItem *rect = new GraphicsRectItem(text);

  rect->setMargins(QMargins(5, 5, 5, 5));
  rect->setBorderWidth(2);
  rect->setBorderColor(QColor(rand() % 256, rand() % 256, rand() % 256));

  int posX = rand() % int(m_scene->width() - rect->boundingRect().width());
  int posY = rand() % int(m_scene->height() - rect->boundingRect().height());
  rect->setPos(posX, posY);

  m_scene->addItem(rect);
}

void MainWindow::show()
{
  QMainWindow::show();
  _updateSceneRect();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
  QMainWindow::resizeEvent(event);
  _updateSceneRect();
}

void MainWindow::_updateSceneRect()
{
  m_scene->setSceneRect(QRect(
      0, 0,
      ui->graphicsView->viewport()->width(),
      ui->graphicsView->viewport()->height()
  ));

  ui->statusbar->showMessage(tr("Scene size: [%1 x %2]").
                             arg(m_scene->width()).
                             arg(m_scene->height()));
}
