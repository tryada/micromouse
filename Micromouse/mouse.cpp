#include "mouse.h"

Mouse::Mouse()
{
}

Mouse::~Mouse()
{
}

void Mouse::analyze()
{
}

void Mouse::run()
{
}

void Mouse::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	// Body
	painter->setBrush(Qt::gray);
	painter->drawEllipse(-10, -20, 20, 40);

	// Eyes
	painter->setBrush(Qt::white);
	painter->drawEllipse(-10, -17, 8, 8);
	painter->drawEllipse(2, -17, 8, 8);

	// Nose
	painter->setBrush(Qt::black);
	painter->drawEllipse(QRectF(-2, -22, 4, 4));
}