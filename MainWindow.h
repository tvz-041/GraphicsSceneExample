#pragma once

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class QGraphicsScene;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

public slots:
    void addRectangle(const QString &text);
    void show();

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    void _updateSceneRect();

private:
    Ui::MainWindow *ui = nullptr;
    QGraphicsScene *m_scene = nullptr;
};

