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

	maze->setSceneRect(0, 0, mazeSceneSize, mazeSceneSize);
	maze->setItemIndexMethod(QGraphicsScene::NoIndex);
	maze->setup();

	this->setScene(maze);
	this->setBackgroundBrush(Qt::lightGray);
}

void MazePanel::templateChanged(QString name)
{
	this->maze->loadFromResources(name);
	if (this->mouse != nullptr) {
		delete mouse;
	}
	mouse = new Mouse();
	this->maze->setMouse(mouse);
}

void MazePanel::move()
{
	mouse->run();
}

void MazePanel::start()
{
	mouse->analyze();
}