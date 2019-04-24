#include "mazeLoader.h"

MazeLoader::MazeLoader()
{
}

MazeLoader::~MazeLoader()
{
}

void MazeLoader::loadFromTemplate(std::string templateName, std::vector<std::vector<QGraphicsRectItem*>>* blocks)
{
	QFile f(QString::fromStdString(templateName));
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
