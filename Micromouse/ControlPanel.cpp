#include "controlPanel.h"
#include <qdir.h>

ControlPanel::ControlPanel(QWidget *parent)
	: QWidget(parent)
{
	this->setFixedHeight(400);
	this->setupLayout();
	this->setupSignalsAndSlots();
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

	auto mazeCount = QDir(":/maze/").entryList().size();
	mazeComboBox->addItem(QString("<pusty>"));
	for (int i = 1; i <= mazeCount; i++)
	{
		mazeComboBox->addItem(QString("Przykład: " + QString::number(i)));
	}
	speedSlider = new QSlider(Qt::Horizontal);
	speedSlider->setDisabled(true);
	pathCheckBox = new QCheckBox("Pokaż");
	pathCheckBox->setDisabled(true);
}

void ControlPanel::setupButtons()
{
	loadMazeButton = new QPushButton("Wczytaj labirynt");
	startMazeReviewButton = new QPushButton("Rozpocznij analizę");
	runButton = new QPushButton("Start");
}

void ControlPanel::setupSignalsAndSlots()
{
	QObject::connect(loadMazeButton, &QPushButton::released, this, &ControlPanel::loadMazeButtonClick);
	QObject::connect(startMazeReviewButton, &QPushButton::released, this, &ControlPanel::analyzeButtonClick);
	QObject::connect(runButton, &QPushButton::released, this, &ControlPanel::runButtonClick);
}

void ControlPanel::analyzeButtonClick()
{
	analyze();
}

void ControlPanel::runButtonClick() 
{
	run();
}

void ControlPanel::loadMazeButtonClick()
{
	auto currentIndex = mazeComboBox->currentIndex();
	QString arg;
	if (currentIndex > 0) {
		arg = ":/maze/maze_" + QString::number(currentIndex);
	}
	sampleChange(arg);
}
