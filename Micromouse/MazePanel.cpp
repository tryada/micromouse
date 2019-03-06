#include "MazePanel.h"

MazePanel::MazePanel(QWidget *parent)
	: QWidget(parent)
{
	this->setup();
}

MazePanel::~MazePanel()
{
}

void MazePanel::generate()
{
	MazeGenerator generator(scene);
	generator.generate(33);
}

QGraphicsView * MazePanel::getView()
{
	return this->view;
}

void MazePanel::setup()
{
	scene = new QGraphicsScene(this);

	scene->setSceneRect(0, 0, 660, 660);
	scene->setItemIndexMethod(QGraphicsScene::NoIndex);

	view = new QGraphicsView(scene);
	view->setBackgroundBrush(Qt::lightGray);
}
