#pragma once

#include <qobject.h>
#include <qgraphicsitem.h>
#include <qpainter.h>
#include <qrect.h>
#include <qpainterpath.h>
#include <qcolor.h>
#include <vector>
#include <qgraphicsscene.h>
#include <qtimer.h>
#include "mazeBlock.h"
#include "directionEnum.h"

class Mouse : public QGraphicsItem, public QObject
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
	
	void runIteration();
	void analyzeIteration();

private:
	bool isAnalyzeFinished;
	DirectionEnum direction;
	QPolygonF leftSensor, frontSensor, rightSensor;

	long analyzeTime;
	long runTime;

	int step = 1;
	int sensorDistance = 15;

	QTimer* timer;

	std::vector<MazeBlock*> getWalls(QPolygonF sensor);

	void resetSensors();

	void turnLeft();
	void turnRight();
	void makeUTurn();

	int getDistanceFromHead(MazeBlock* block);
	int getDistanceFromLeftSide(MazeBlock* block);
	int getDistanceFromRightSide(MazeBlock* block);
	int getCorrection(MazeBlock* leftBlock, MazeBlock* rightBlock);

	std::vector<MazeBlock*> visitedBlocks;
	void addToVisitedBlock(MazeBlock* block);
	MazeBlock* getCurrentBlock();
};
