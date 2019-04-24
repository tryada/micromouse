#include "maze.h"

Maze::Maze(QObject *parent)
	: QGraphicsScene(parent)
{
}

Maze::~Maze()
{
}

void Maze::setup()
{
	this->setupGrid();
	// tymczasowo
	this->loadFromTemplate(":/maze/maze_2");
}

void Maze::loadFromTemplate(std::string templateName)
{
	MazeLoader loader;
	loader.loadFromTemplate(templateName, this->blocks);
}

void Maze::setupGrid()
{
	blocks = new std::vector<std::vector<QGraphicsRectItem*>>();

	int height = this->height();
	int step = height / size;
	int lenght = size * step;

	for (int i = 0; i < lenght; i += step)
	{
		std::vector<QGraphicsRectItem*> temp;
		for (int j = 0; j < lenght; j += step)
		{
			QRect rect(j, i, step, step);
			temp.push_back(this->addRect(rect, QPen(Qt::lightGray)));
		}
		blocks->push_back(temp);
	}
}
