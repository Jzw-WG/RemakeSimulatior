#ifndef REMAKEMAIN_H
#define REMAKEMAIN_H

#include <QMainWindow>
#include <QPainter>
#include <QPainterPath>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class RemakeMain; }
QT_END_NAMESPACE

class RemakeMain : public QMainWindow
{
    Q_OBJECT

public:
    RemakeMain(QWidget *parent = nullptr);
    ~RemakeMain();
    void paintEvent(QPaintEvent *);
    void gradientArc(QPainter *painter, int radius, int startAngle, int angleLength, int arcHeight, QRgb color);
    int m_nRotationAngle = 0;

private:
    Ui::RemakeMain *ui;
    QTimer *pTimer = new QTimer(this);

public slots:
    void updatePaint();
private slots:
    void on_remakeButton_clicked();
};
#endif // REMAKEMAIN_H
