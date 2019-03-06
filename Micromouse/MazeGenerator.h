#pragma once

#include <qgraphicsscene.h>
#include <qgraphicsitem.h>
#include <vector>

class MazeGenerator
{

public:
	MazeGenerator(QGraphicsScene* scene);
	~MazeGenerator();

	void generate(int size);

private:
	QGraphicsScene* scene;

	std::vector<std::vector<QGraphicsRectItem*>>* blocks;
	bool validateSize(int size);
	void colorVector(std::vector<QGraphicsRectItem*> vectors);
	void setColors();
};