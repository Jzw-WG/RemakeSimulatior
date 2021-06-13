#include "remakemain.h"
#include "ui_remakemain.h"

RemakeMain::RemakeMain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RemakeMain)
{
    ui->setupUi(this);
}

RemakeMain::~RemakeMain()
{
    delete ui;
}

void RemakeMain::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    int radius = 150;
    int arcHeight = 30;

    // >> 1（右移1位）相当于width() / 2
    painter.translate(width() >> 1, height() >> 1);

    painter.rotate(m_nRotationAngle);
    /**
     * 参数二：半径
     * 参数三：开始的角度
     * 参数四：指扫取的角度-顺时针（360度 / 8 = 45度）
     * 参数五：圆环的高度
     * 参数六：填充色
    **/
    gradientArc(&painter, radius, 0,  45, arcHeight, qRgb(200, 200, 0));
    gradientArc(&painter, radius, 45, 45, arcHeight, qRgb(200, 0, 200));
    gradientArc(&painter, radius, 90, 45, arcHeight, qRgb(0, 200, 200));
    gradientArc(&painter, radius, 135, 45, arcHeight, qRgb(200, 0, 0));
    gradientArc(&painter, radius, 225, 45, arcHeight, qRgb(0, 200, 0));
    gradientArc(&painter, radius, 180, 45, arcHeight, qRgb(0, 0, 200));
    gradientArc(&painter, radius, 270, 45, arcHeight, qRgb(0, 0, 0));
    gradientArc(&painter, radius, 315, 45, arcHeight, qRgb(150, 150, 150));


}

void RemakeMain::gradientArc(QPainter *painter, int radius, int startAngle, int angleLength, int arcHeight, QRgb color)
{
    // 渐变色
    QRadialGradient gradient(0, 0, radius);
    gradient.setColorAt(0, Qt::white);
    gradient.setColorAt(1.0, color);
    painter->setBrush(gradient);

    // << 1（左移1位）相当于radius*2 即：150*2=300
    //QRectF(-150, -150, 300, 300)
    QRectF rect(-radius, -radius, radius << 1, radius << 1);
    QPainterPath path;
    path.arcTo(rect, startAngle, angleLength);

    painter->setPen(Qt::NoPen);
    painter->drawPath(path);
}

// 改变角度，进行旋转
void RemakeMain::updatePaint()
{
    m_nRotationAngle++;
    if (m_nRotationAngle > 360)
        m_nRotationAngle = 0;
    update();
}


void RemakeMain::on_remakeButton_clicked()
{
    // 利用定时器，定时变换角度，进行旋转。
    pTimer->setInterval(1);
    connect(pTimer, SIGNAL(timeout()), this, SLOT(updatePaint()));
    pTimer->start();
}
