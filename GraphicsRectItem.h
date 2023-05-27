#pragma once

#include <QGraphicsSimpleTextItem>

class GraphicsRectItem : public QGraphicsSimpleTextItem
{
public:
    GraphicsRectItem(const QString &text, QGraphicsItem *parent = nullptr);
    ~GraphicsRectItem() override = default;

    QRectF boundingRect() const override;

    QMargins margins() const;
    void setMargins(const QMargins &margins);

    int borderWidth();
    void setBorderWidth(int width);

    QColor textColor() const;
    QColor borderColor() const;
    QColor backgroundColor() const;

    void setTextColor(const QColor &color);
    void setBorderColor(const QColor &color);
    void setBackgroundColor(const QColor &color);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QMargins m_margins;
    int m_borderWidth = 1;
    QColor m_textColor = Qt::black;
    QColor m_borderColor = Qt::black;
    QColor m_backgroundColor = Qt::white;
};

