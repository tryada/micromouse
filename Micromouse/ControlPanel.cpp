#include "ControlPanel.h"

ControlPanel::ControlPanel(QWidget *parent)
	: QWidget(parent)
{
	this->setupLayout();
}

ControlPanel::~ControlPanel()
{
	delete(layout);
	delete(mazeSizeLabel);
	delete(mazeSizeSlider);
	delete(mazeSizeResultLabel);
	delete(generateMazeButton);
	delete(algorithmPickerLabel);
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

	layout->addWidget(mazeSizeLabel);
	layout->addWidget(mazeSizeSlider);
	layout->addWidget(mazeSizeResultLabel);
	layout->addWidget(generateMazeButton);
	layout->addWidget(algorithmPickerLabel);
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
	mazeSizeLabel = new QLabel("Rozmiar planszy");
	mazeSizeResultLabel = new QLabel("100 x 100");
	algorithmPickerLabel = new QLabel("Algorytm");
	speedLabel = new QLabel("Prędkość myszy");
	pathLabel = new QLabel("Ślad");
	mazeReviewLabel = new QLabel("Czas analizy toru");
	mazeReviewTimeLabel = new QLabel("00:00");
	mazeRunLabel = new QLabel("Czas przejścia");
	mazeRunTimeLabel = new QLabel("00:00");
}

void ControlPanel::setupInputs()
{
	mazeSizeSlider = new QSlider(Qt::Horizontal);
	speedSlider = new QSlider(Qt::Horizontal);
	pathCheckBox = new QCheckBox("Pokaż");
}

void ControlPanel::setupButtons()
{
	generateMazeButton = new QPushButton("Generuj labirynt");
	startMazeReviewButton = new QPushButton("Rozpocznij analizę");
	runButton = new QPushButton("Start");
}
