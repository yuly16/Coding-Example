//
// Created by yuliangyong on 2022-02-18.
//

#ifndef QTEXAMPLE_RASTERWINDOW_H
#define QTEXAMPLE_RASTERWINDOW_H
#include "QtGui/QtGui"

class RasterWindow : public QWindow
{
Q_OBJECT
public:
    explicit RasterWindow(QWindow *parent = 0);

    virtual void render(QPainter *painter);

public slots:
    void renderLater();
    void renderNow();

protected:
    bool event(QEvent *event) override;

    void resizeEvent(QResizeEvent *event) override;
    void exposeEvent(QExposeEvent *event) override;

private:
    QBackingStore *m_backingStore;
};

#endif //QTEXAMPLE_RASTERWINDOW_H
