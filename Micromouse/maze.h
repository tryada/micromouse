#pragma once

#include <QGraphicsScene>
#include <qgraphicsitem.h>
#include <qstring.h>
#include "mazeBlock.h"
#include "mouse.h"

template<typename T>
class Maze : public QGraphicsScene
{
public:
	Maze(QObject *parent);
	~Maze();

	void setup();
	void loadFromResources(QString name);

	void setItem(T* item);

private:
	const int size = 33;
	std::vector<std::vector<MazeBlock*>>* blocks;
	T* item;
	MazeBlock* startBlock;

	void setupGrid();
	void clearGrid();
};
