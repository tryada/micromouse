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
	maze = new Maze<Mouse>(this);

	maze->setSceneRect(0, 0, mazeSceneSize, mazeSceneSize);
	maze->setItemIndexMethod(QGraphicsScene::NoIndex);
	maze->setup();

	this->setScene(maze);
	this->setBackgroundBrush(Qt::lightGray);
}

void MazePanel::templateChanged(QString name)
{
	this->maze->loadFromResources(name);
	if (this->item != nullptr) {
		delete item;
	}
	item = new Mouse();
	this->maze->setItem(item);
}

void MazePanel::move()
{
	item->moveStepByStep();
}

void MazePanel::start()
{
	item->run();
}