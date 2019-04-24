#include "Micromouse.h"

Micromouse::Micromouse(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QWidget * central = new QWidget();
	setCentralWidget(central);
	this->setupLayout();
}

Micromouse::~Micromouse()
{
	delete(controlPanel);
	delete(mainLayout);
	delete(centralWidget());
}

void Micromouse::setupLayout()
{
	mainLayout = new QGridLayout();
	controlPanel = new ControlPanel(this);
	mazePanel = new MazePanel(this);

	mainLayout->setColumnStretch(0, 1);
	mainLayout->setColumnStretch(1, 5);
	mainLayout->addWidget(controlPanel, 0, 0);
	mainLayout->addWidget(mazePanel, 0, 1);
	centralWidget()->setLayout(mainLayout);
}
