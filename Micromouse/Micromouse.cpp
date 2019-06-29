#include "Micromouse.h"

Micromouse::Micromouse(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setupLayout();
	this->setupSignalsAndSlots();
}

Micromouse::~Micromouse()
{
	delete(controlPanel);
	delete(mainLayout);
	delete(centralWidget());
}

void Micromouse::setupLayout()
{
	mainLayout = new QGridLayout(this);
	controlPanel = new ControlPanel(this);
	mazePanel = new MazePanel(this);

	mainLayout->setColumnStretch(0, 1);
	mainLayout->setColumnStretch(1, 5);
	mainLayout->addWidget(controlPanel, 0, 0);
	mainLayout->addWidget(mazePanel, 0, 1);
	mainLayout->setAlignment(controlPanel, Qt::AlignTop);
	centralWidget()->setLayout(mainLayout);
}

void Micromouse::setupSignalsAndSlots()
{
	QObject::connect(controlPanel, &ControlPanel::sampleChange, mazePanel, &MazePanel::templateChanged);
}
 