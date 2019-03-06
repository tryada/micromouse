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

	if (!validateSize(size))
	{
		size = 80;
	}

	int step = height / size;
	int lenght = size * step;

	for (int i = 0; i <= lenght; i += step)
	{
		std::vector<QGraphicsRectItem*> temp;
		for (int j = 0; j <= lenght; j += step)
		{
			QRect rect(i, j, step, step);
			temp.push_back(scene->addRect(rect));
		}
		blocks->push_back(temp);
	}

	//setColors();
}

bool MazeGenerator::validateSize(int size)
{
	return scene->height() / size >= 4;
}

void MazeGenerator::colorVector(std::vector<QGraphicsRectItem*> vectors)
{

}

void MazeGenerator::setColors()
{
	for (int i = 0; i < this->blocks->size(); i++)
	{
		if (i % 2)
		{
			auto vector = this->blocks->at(i);
			for (int j = 0; j < vector.size(); j++)
			{
				vector.at(j)->setBrush(QBrush(Qt::black));
				vector.at(j)->setPen(QPen(Qt::black));
			}
		}
	}
}
