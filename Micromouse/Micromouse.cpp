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

	mainLayout->addWidget(controlPanel, 0, 0);
	centralWidget()->setLayout(mainLayout);
}
