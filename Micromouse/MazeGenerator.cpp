#include "MazeGenerator.h"

MazeGenerator::MazeGenerator(QGraphicsScene * scene)
{
	this->scene = scene;
	this->blocks = new std::vector<std::vector<QGraphicsRectItem*>>();
}

MazeGenerator::~MazeGenerator()
{
}

void MazeGenerator::generate(int size)
{
	int height = scene->height();
	int step = height / size;
	int lenght = size * step;

	for (int i = 0; i < lenght; i += step)
	{
		std::vector<QGraphicsRectItem*> temp;
		for (int j = 0; j < lenght; j += step)
		{
			QRect rect(j, i, step, step);
			temp.push_back(scene->addRect(rect, QPen(Qt::lightGray)));
		}
		blocks->push_back(temp);
	}

	this->loadFromFile();
}

void MazeGenerator::loadFromFile()
{
	QFile f(":/maze/maze_2");
	if (f.open(QFile::ReadOnly | QFile::Text))
	{ 
		QTextStream in(&f);
		int index = 0;
		while (!in.atEnd())
		{
			std::string line = in.readLine().toStdString();
			for (int i = 0; i < line.length(); i++)
			{
				if (line[i] == '#')
				{
					blocks->at(index)[i]->setBrush(QBrush(Qt::black));
					blocks->at(index)[i]->setPen(QPen(Qt::black));
				}
			}
			index++;
		}
	}
}
