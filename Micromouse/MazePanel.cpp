#include "mazePanel.h"

MazePanel::MazePanel(QWidget *parent)
	: QGraphicsView(parent)
{
	this->setup();
}	

MazePanel::~MazePanel()
{
}

void MazePanel::setup()
{
	maze = new Maze(this);

	maze->setSceneRect(0, 0, 660, 660);
	maze->setItemIndexMethod(QGraphicsScene::NoIndex);
	maze->setup();

	this->setScene(maze);
	this->setBackgroundBrush(Qt::lightGray);
}