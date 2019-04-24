#pragma once

#include <qgraphicsscene.h>
#include <qgraphicsitem.h>
#include <vector>
#include <qfile.h>
#include <qtextstream.h>
#include <string>

class MazeLoader
{

public:
	MazeLoader();
	~MazeLoader();

	void loadFromTemplate(std::string templateName, std::vector<std::vector<QGraphicsRectItem*>>* blocks);
};