#include "MazerPanel.h"

MazerPanel::MazerPanel(QWidget *parent)
	: QWidget(parent)
{
	this->setup();
}

MazerPanel::~MazerPanel()
{
}

void MazerPanel::setup()
{
	scene = new QGraphicsScene(this);
	view = new QGraphicsView(scene);

	scene->setSceneRect(0, 0, 1000, 800);
	scene->setItemIndexMethod(QGraphicsScene::NoIndex);

	layout = new QGridLayout();
	layout->addWidget(view, 0, 0, Qt::AlignCenter);

	this->setLayout(layout);
}
