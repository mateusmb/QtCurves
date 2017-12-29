#include "renderarea.h"
#include <QPaintEvent>
#include <QPainter>
#include <QtMath>

RenderArea::RenderArea(QWidget *parent) : QWidget(parent),
    mBackgroundColor (0,0,255),
    mShapeColor (255,255,255),
    mShape(Astroid)
{
    on_shape_changed();
}

QSize RenderArea::minimumSizeHint() const {
    return QSize(100, 400);
}

QSize RenderArea::sizeHint() const {
    return QSize(400, 400);
}

void RenderArea::on_shape_changed() {
    switch (mShape) {
    case Astroid:
        mScale = 90;
        mIntervalLength = 2 * M_PI;
        mStepCount = 256;
        break;
    case Cycloid:
        mScale = 10;
        mIntervalLength = 4 * M_PI;
        mStepCount = 128;
        break;
    case HuygensCycloid:
        mScale = 4;
        mIntervalLength = 4 * M_PI;
        mStepCount = 256;
        break;
    case Hypocycloid:
        mScale = 40;
        mIntervalLength = 2 * M_PI;
        mStepCount = 256;
        break;
    case Line:
        mIntervalLength = 2;
        mScale = 100;
        mStepCount = 128;
        break;
    default:
        break;
    }
}

QPointF RenderArea::compute(float t) {
    switch (mShape) {
    case Astroid:
        return compute_astroid(t);
        break;
    case Cycloid:
        return compute_cycloid(t);
        break;
    case HuygensCycloid:
        return compute_huygens(t);
        break;
    case Hypocycloid:
        return compute_hypo(t);
        break;
    case Line:
        return compute_line(t);
        break;
    default:
        break;
    }
    return QPointF(0,0);
}

QPointF RenderArea::compute_astroid(float t) {
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x = 2 * cos_t * cos_t * cos_t;
    float y = 2 * sin_t * sin_t * sin_t;
    return QPointF(x, y);
}

QPointF RenderArea::compute_cycloid(float t) {
    return QPointF(
                1.5 * (1 - cos(t)),
                1.5 * (t - sin(t))
                );
}

QPointF RenderArea::compute_huygens(float t) {
    return QPointF(
                4 * (3 * cos(t) - cos(3*t)),
                4 * (3 * sin(t) - sin(3*t))
                );
}

QPointF RenderArea::compute_hypo(float t) {
    return QPointF(
                1.5 * (2 * cos(t) + cos(2*t)),
                1.5 * (2 * sin(t) - sin(2*t))
                );
}

QPointF RenderArea::compute_line(float t) {
    return QPointF(1-t,1-t);
}

void RenderArea::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.setBrush(mBackgroundColor);
    painter.setPen(mShapeColor);
    // draw area
    painter.drawRect(this->rect());

    QPoint center = this->rect().center();
    QPointF previousPoint = compute(0);
    QPoint previousPixel;
    previousPixel.setX(previousPoint.x() * mScale + center.x());
    previousPixel.setY(previousPoint.y() * mScale + center.y());
    float intervalLength = 2 * M_PI;
    float step = mIntervalLength / mStepCount;
    for(float t = 0; t < mIntervalLength; t += step) {
        QPointF point = compute(t);

        QPoint pixel;
        pixel.setX(point.x() * mScale + center.x());
        pixel.setY(point.y() * mScale + center.y());
//        painter.drawPoint(pixel);
        painter.drawLine(pixel, previousPixel);
        previousPixel = pixel;
    }
}
