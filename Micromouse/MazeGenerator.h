#pragma once

#include <qgraphicsscene.h>
#include <qgraphicsitem.h>
#include <vector>
#include <qfile.h>
#include <qtextstream.h>
#include <string>
#include <qdebug.h>

class MazeGenerator
{

public:
	MazeGenerator(QGraphicsScene* scene);
	~MazeGenerator();

	void generate(int size);

private:
	QGraphicsScene* scene;

	std::vector<std::vector<QGraphicsRectItem*>>* blocks;
	void loadFromFile();
};