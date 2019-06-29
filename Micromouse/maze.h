#pragma once

#include <QGraphicsScene>
#include <qgraphicsitem.h>
#include <qstring.h>
#include "mazeBlock.h"
#include "mouse.h"

class Maze : public QGraphicsScene
{
	Q_OBJECT

public:
	Maze(QObject *parent);
	~Maze();

	void setup();
	void loadFromResources(QString name);

	void setMouse(Mouse* mouse);

private:
	const int size = 33;
	std::vector<std::vector<MazeBlock*>>* blocks;
	Mouse* mouse;
	MazeBlock* startBlock;

	void setupGrid();
	void clearGrid();
};
