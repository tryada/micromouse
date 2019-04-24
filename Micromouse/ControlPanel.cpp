#include "controlPanel.h"

ControlPanel::ControlPanel(QWidget *parent)
	: QWidget(parent)
{
	this->setupLayout();
}

ControlPanel::~ControlPanel()
{
	delete(layout);
	delete(mazeLabel);
	delete(mazeComboBox);
	delete(loadMazeButton);
	delete(speedLabel);
	delete(speedSlider);
	delete(pathLabel);
	delete(pathCheckBox);
	delete(startMazeReviewButton);
	delete(mazeReviewLabel);
	delete(mazeReviewTimeLabel);
	delete(runButton);
	delete(mazeRunLabel);
	delete(mazeRunTimeLabel);
}

void ControlPanel::setupLayout()
{
	setupLabels();
	setupInputs();
	setupButtons();

	layout = new QVBoxLayout();

	layout->addWidget(mazeLabel);
	layout->addWidget(mazeComboBox);
	layout->addWidget(loadMazeButton);
	layout->addWidget(speedLabel);
	layout->addWidget(speedSlider);
	layout->addWidget(pathLabel);
	layout->addWidget(pathCheckBox);
	layout->addWidget(startMazeReviewButton);
	layout->addWidget(mazeReviewLabel);
	layout->addWidget(mazeReviewTimeLabel);
	layout->addWidget(runButton);
	layout->addWidget(mazeRunLabel);
	layout->addWidget(mazeRunTimeLabel);

	this->setLayout(layout);
}

void ControlPanel::setupLabels()
{
	mazeLabel = new QLabel("Wybierz labirynt");
	speedLabel = new QLabel("Prędkość myszy");
	pathLabel = new QLabel("Ślad");
	mazeReviewLabel = new QLabel("Czas analizy toru");
	mazeReviewTimeLabel = new QLabel("00:00");
	mazeRunLabel = new QLabel("Czas przejścia");
	mazeRunTimeLabel = new QLabel("00:00");
}

void ControlPanel::setupInputs()
{
	mazeComboBox = new QComboBox();
	mazeComboBox->addItem(QString("Pierwszy"));
	mazeComboBox->addItem(QString("Drugi"));
	speedSlider = new QSlider(Qt::Horizontal);
	pathCheckBox = new QCheckBox("Pokaż");
}

void ControlPanel::setupButtons()
{
	loadMazeButton = new QPushButton("Wczytaj labirynt");
	startMazeReviewButton = new QPushButton("Rozpocznij analizę");
	runButton = new QPushButton("Start");
}
