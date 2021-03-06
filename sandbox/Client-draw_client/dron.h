#ifndef DRON_H
#define DRON_H

#include <iostream>

#include <QObject>
#include <QVector>
#include <QPainter>
#include <QGraphicsItem>

class DrawClient;
class Bullet;

class Dron : public QObject, public QGraphicsItem {
		
	Q_OBJECT
		
	public:
		explicit Dron (QObject* parent = 0);
		void setManualControl (bool manual);
		void setRectangleArea (qint32 width, qint32 height);
		void setDrawClient    (DrawClient* client);
		~Dron ();
		
		void   id (qint32 id);
		qint32 id ();
		
		QPolygonF boundingPolygon ();
		QPolygonF boundingPolygon (qreal x, qreal y, qreal a);
		
	public slots:
		void slotMove ();
		void slotTarget (QPointF target);
		void slotShot   ();
		
	protected:
		QRectF boundingRect () const;
		void paint (QPainter* painter,
					const QStyleOptionGraphicsItem* option,
					QWidget* widget);
		
	private:
		bool    manual;
		qint32  identificator;
		qint32	width, height;
		qint32	awidth, aheight;
		qint32  shotTimeout;
		qreal   diagonal;
		qreal   speed;
		
		QRectF  bounds;
		QPointF point;
		QPointF target;
		qreal   angle;
		
		qreal rad (qreal angle);
		void normalizeAngle ();
		bool checkBoundsX   (qreal x);
		bool checkBoundsY   (qreal y);
		bool checkDrons     (qreal x, qreal y);
		bool checkObstacles (qreal x, qreal y);
		
		DrawClient* client;
		
};

#endif // DRON_H
