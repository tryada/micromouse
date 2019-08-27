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
#include "enums.h"

typedef std::vector<MazeBlock*> Blocks;

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
	QPolygonF leftSensor, frontSensor, rightSensor, backSensor;
	MazeBlock* currentBlock;
	MazeBlock* currentCrossroads;

	long analyzeTime;
	long runTime;

	int step = 1;
	int sensorDistance = 15;

	QTimer* timer;

	Blocks getCollidingBlocks(QPolygonF sensor);
	Blocks getWalls(Blocks blocks);

	void resetSensors();

	void turnLeft();
	void turnRight();
	void makeUTurn();
	bool makeRandomTurn(bool leftClear, bool frontClear, bool rightClear, bool backClear);

	bool isNodeBlock(bool leftClear, bool frontClear, bool rightClear, bool backClear);

	int getDistanceFromHead(MazeBlock* block);
	int getDistanceFromLeftSide(MazeBlock* block);
	int getDistanceFromRightSide(MazeBlock* block);
	int getCorrection(MazeBlock* leftBlock, MazeBlock* rightBlock);

	Blocks visitedBlocks;
	void addToVisitedBlock(MazeBlock* block);
	bool isVisitedBlock(MazeBlock* block);
	MazeBlock* getCurrentBlock();
};
