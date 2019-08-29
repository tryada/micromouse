#include "maze.h"
#include <qfile.h>
#include <qtextstream.h>
#include <iostream>

template<typename T>
Maze<T>::Maze(QObject *parent)
	: QGraphicsScene(parent)
{
	item = nullptr; 
	startBlock = nullptr;
}

template<typename T>
Maze<T>::~Maze()
{
	delete blocks;
}

template<typename T>
void Maze<T>::setup()
{
	this->setupGrid();
}

template<typename T>
void Maze<T>::loadFromResources(QString name)
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

template<typename T>
void Maze<T>::setItem(T * item)
{
	if (startBlock != nullptr) {
		QRectF rect = this->startBlock->rect();
		this->item = item;
		this->item->setPos(rect.x() + rect.width() / 2, rect.y() + rect.height() / 2);
		this->addItem(this->item);
	}
}

template<typename T>
void Maze<T>::setupGrid()
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
			MazeBlock* rect = new MazeBlock(j / step, i / step);
			rect->setRect(QRect(j, i, step, step));
			temp.push_back(rect);
			this->addItem(rect);
		}
		blocks->push_back(temp);
	}
}

template<typename T>
void Maze<T>::clearGrid()
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
	if (item != nullptr) {
		this->removeItem(item);
		item = nullptr;
	}
}
