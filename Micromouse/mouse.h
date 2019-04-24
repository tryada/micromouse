#pragma once

#include <QObject>
#include <QGraphicsItem>
#include <qpainter.h>
#include "directionEnum.h"

class Mouse : public QGraphicsItem
{
public:
	Mouse();
	~Mouse();

	void analyze();
	void run();

	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
		QWidget *widget) override;

	inline long getAnalyzeTime() { return this->analyzeTime; }
	inline long getRunTime() { return this->runTime; }

private:
	bool isAnalyzeFinished;
	DirectionEnum direction;

	long analyzeTime;
	long runTime;
};
