#include "microWaveLabel.h"
#include <QDebug>

microWaveLabel::microWaveLabel(const QString &text, QWidget * parent ) :
QLabel(parent)
{

}

void microWaveLabel::mousePressEvent ( QMouseEvent * event )
{
    emit microWaveClicked(); // Hiiren klikkaus lähettää signaalin.
}
