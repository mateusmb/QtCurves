#include "renderarea.h"
#include <QPaintEvent>
#include <QPainter>
#include <QtMath>

RenderArea::RenderArea(QWidget *parent) : QWidget(parent),
    mBackgroundColor (0,0,255),
    mPen(Qt::white),
    mShape(Astroid)
{
    mPen.setWidth(2);
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
    case Circle:
        mIntervalLength = 2 * M_PI;
        mScale = 100;
        mStepCount = 128;
    case Ellipse:
        mIntervalLength = 2 * M_PI;
        mScale = 75;
        mStepCount = 256;
    case Fancy:
        mIntervalLength = 12 * M_PI;
        mScale = 10;
        mStepCount = 512;
    case StarFish:
        mIntervalLength = 6 * M_PI;
        mScale = 25;
        mStepCount = 256;
    case Cloud:
        mIntervalLength = 28 * M_PI;
        mScale = 10;
        mStepCount = 128;
    case Cloud2:
        mIntervalLength = 28 * M_PI;
        mScale = 10;
        mStepCount = 128;
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
    case Circle:
        return compute_circle(t);
    case Ellipse:
        return compute_ellipse(t);
    case Fancy:
        return compute_fancy(t);
    case StarFish:
        return compute_starfish(t);
    case Cloud:
        return compute_cloud(t);
    case Cloud2:
        return compute_cloud2(t);
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

QPointF RenderArea::compute_circle(float t) {
    return QPointF(cos(t), sin(t));
}

QPointF RenderArea::compute_ellipse(float t) {
    float a = 2.0f;
    float b = 1.1f;
    return QPointF(a*cos(t), b*sin(t));
}

QPointF RenderArea::compute_fancy(float t) {
    return QPointF(
                11.0f * cos(t) - 6.0f * cos((11.0f/6.0f)*t),
                11.0f * sin(t) - 6.0f * sin((11.0f/6.0f)*t)
                );
}

QPointF RenderArea::compute_starfish(float t) {
    float R = 5.0f;
    float r = 3.0f;
    float d = 5.0f;
    return QPointF(
                (R-r) * cos(t) + d * cos(t*((R-r)/r)),
                (R-r) * sin(t) - d * sin(t*((R-r)/r))
                );
}

QPointF RenderArea::compute_cloud(float t) {
    return compute_cloud_with_sign(t, -1);
}


QPointF RenderArea::compute_cloud2(float t) {
    return compute_cloud_with_sign(t, 1);
}


QPointF RenderArea::compute_cloud_with_sign(float t, float sign) {
    float a = 14.0f;
    float b = 1.0f;
    return QPointF(
                (a+b) * cos(t*(b/a)) + sign * b * cos(t*((a+b)/a)),
                (a+b) * sin(t*(b/a)) - b * sin(t*((a+b)/a))
                );
}

void RenderArea::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.setBrush(mBackgroundColor);
    painter.setPen(mPen);
    // draw area
    painter.drawRect(this->rect());

    QPoint center = this->rect().center();
    QPointF previousPoint = compute(0);
    QPoint previousPixel;
    previousPixel.setX(previousPoint.x() * mScale + center.x());
    previousPixel.setY(previousPoint.y() * mScale + center.y());

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
    QPointF point = compute(mIntervalLength);
    QPoint pixel;
    pixel.setX(point.x() * mScale + center.x());
    pixel.setY(point.y() * mScale + center.y());
    painter.drawLine(pixel, previousPixel);
}
