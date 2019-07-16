#include "mazePanel.h"
#include "mouse.h"

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

	maze->setSceneRect(0, 0, mazeSceneSize, mazeSceneSize);
	maze->setItemIndexMethod(QGraphicsScene::NoIndex);
	maze->setup();

	this->setScene(maze);
	this->setBackgroundBrush(Qt::lightGray);
}

void MazePanel::templateChanged(QString name)
{
	this->maze->loadFromResources(name);
	this->maze->setMouse(new Mouse());
}

void MazePanel::run()
{
}

void MazePanel::analyze()
{
}