#include "maze.h"
#include <qfile.h>
#include <qtextstream.h>
#include <iostream>

Maze::Maze(QObject *parent)
	: QGraphicsScene(parent)
{
	mouse = nullptr;
	startBlock = nullptr;
}

Maze::~Maze()
{
	delete blocks;
}

void Maze::setup()
{
	this->setupGrid();
}

void Maze::loadFromResources(QString name)
{
	clearGrid();
	if (!name.isEmpty()) {
		QFile f(name);
		if (f.open(QFile::ReadOnly | QFile::Text))
		{
			QTextStream in(&f);
			int index = 0;
			while (!in.atEnd())
			{
				std::string line = in.readLine().toStdString();
				for (int i = 0; i < line.length(); i++)
				{
					MazeBlock* block = blocks->at(index)[i];
					if (line[i] == '#')
					{
						block->setIsWall(true);
					}
					else if (line[i] == 'S') {
						this->startBlock = block;
						block->setIsStart(true);
					}
					else if (line[i] == 'M') {
						block->setIsFinish(true);
					}
					block = nullptr;
				}
				index++;
			}
		}
	}
}

void Maze::setMouse(Mouse * mouse)
{
	if (startBlock != nullptr) {
		QRectF rect = this->startBlock->rect();
		this->mouse = mouse;
		this->mouse->setPos(rect.x() + rect.width() / 2, rect.y() + rect.height() / 2);
		this->addItem(this->mouse);
	}
}

void Maze::setupGrid()
{
	blocks = new std::vector<std::vector<MazeBlock*>>();

	int height = this->height();
	int step = height / size;
	int lenght = size * step;

	for (int i = 0; i < lenght; i += step)
	{
		std::vector<MazeBlock*> temp;
		for (int j = 0; j < lenght; j += step)
		{
			MazeBlock* rect = new MazeBlock(nullptr);
			rect->setRect(QRect(j, i, step, step));
			temp.push_back(rect);
			this->addItem(rect);
		}
		blocks->push_back(temp);
	}
}

void Maze::clearGrid()
{
	for (std::vector<std::vector<MazeBlock*>>::iterator it = blocks->begin(); it != blocks->end(); it++)
	{
		for (std::vector<MazeBlock*>::iterator inner_it = it->begin(); inner_it != it->end(); inner_it++)
		{
			auto pointer = *inner_it;
			pointer->clear();
		}
	}

	startBlock = nullptr;
	if (mouse != nullptr) {
		this->removeItem(mouse);
		mouse = nullptr;
	}
}
