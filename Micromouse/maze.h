#pragma once

#include <QGraphicsScene>
#include <qgraphicsitem.h>
#include <string>
#include "mazeLoader.h"

class Maze : public QGraphicsScene
{
	Q_OBJECT

public:
	Maze(QObject *parent);
	~Maze();

	void setup();
	void loadFromTemplate(std::string templateName);

private:
	const int size = 33;
	std::vector<std::vector<QGraphicsRectItem*>>* blocks;

	void setupGrid();

};
