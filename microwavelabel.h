#ifndef MICROWAVELABEL_H
#define MICROWAVELABEL_H
#include <QWidget>
#include <QLabel>
#include <QObject>

class microWaveLabel : public QLabel
{
 Q_OBJECT
public:
 microWaveLabel( const QString & text, QWidget * parent );
 ~microWaveLabel(){}

signals:
void microWaveClicked();

protected:
 void mousePressEvent ( QMouseEvent * event ) ;

};
#endif // MICROWAVELABEL_H
