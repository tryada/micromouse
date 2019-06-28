#pragma once

#include <qobject.h>
#include <qgraphicsitem.h>
#include <qpainter.h>
#include <qrect.h>
#include <qpainterpath.h>
#include <qcolor.h>
#include <vector>
#include "mazeBlock.h"
#include "directionEnum.h"
#include "qgraphicsscene.h"

class Mouse : public QGraphicsItem
{
public:
	Mouse();
	~Mouse();

	void analyze();
	void run();

	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
		QWidget *widget) override;


	QRectF boundingRect() const override;

	inline long getAnalyzeTime() { return this->analyzeTime; }
	inline long getRunTime() { return this->runTime; }

protected:
	void advance(int step) override;

private:
	bool isAnalyzeFinished;
	DirectionEnum direction;
	QPolygonF leftSensor, topSensor, rightSensor, bottomSensor;

	long analyzeTime;
	long runTime;

	std::vector<MazeBlock*> getWalls(QPolygonF sensor);

	void resetSensors();
};
