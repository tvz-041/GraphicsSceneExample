#include <QPainter>

#include "GraphicsRectItem.h"

GraphicsRectItem::GraphicsRectItem(const QString &text, QGraphicsItem *parent)
    : QGraphicsSimpleTextItem(text, parent)
{}

QRectF GraphicsRectItem::boundingRect() const
{
    QMargins borderMargins(m_borderWidth, m_borderWidth, m_borderWidth, m_borderWidth);
    return QGraphicsSimpleTextItem::boundingRect() + m_margins + borderMargins;
}

QMargins GraphicsRectItem::margins() const
{
    return m_margins;
}

void GraphicsRectItem::setMargins(const QMargins &margins)
{
    if (m_margins != margins) {
        m_margins = margins;
        update();
    }
}

int GraphicsRectItem::borderWidth()
{
    return m_borderWidth;
}

void GraphicsRectItem::setBorderWidth(int width)
{
    if (m_borderWidth < 0) {
        return;
    }

    if (m_borderWidth != width) {
        m_borderWidth = width;
        update();
    }
}

QColor GraphicsRectItem::textColor() const
{
    return m_textColor;
}

QColor GraphicsRectItem::borderColor() const
{
    return m_borderColor;
}

QColor GraphicsRectItem::backgroundColor() const
{
    return m_backgroundColor;
}

void GraphicsRectItem::setTextColor(const QColor &color)
{
    if (m_textColor != color) {
        m_textColor = color;
        update();
    }
}

void GraphicsRectItem::setBorderColor(const QColor &color)
{
    if (m_borderColor != color) {
        m_borderColor = color;
        update();
    }
}

void GraphicsRectItem::setBackgroundColor(const QColor &color)
{
    if (m_backgroundColor != color) {
        m_backgroundColor = color;
        update();
    }
}

void GraphicsRectItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->fillRect(this->boundingRect(), m_backgroundColor);

    QPen oldPen = painter->pen();
    QPen pen(oldPen);
    pen.setWidth(m_borderWidth);
    pen.setColor(m_borderColor);
    painter->setPen(pen);
    painter->drawRect(this->boundingRect());

    painter->setPen(m_textColor);
    QGraphicsSimpleTextItem::paint(painter, option, widget);

    painter->setPen(oldPen);
}
