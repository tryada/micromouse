#include "ControlPanel.h"

ControlPanel::ControlPanel(QWidget *parent)
	: QWidget(parent)
{
	this->setupLayout();
}

ControlPanel::~ControlPanel()
{
	delete(layout);
	delete(mazerSizeLabel);
	delete(mazerSizeSlider);
	delete(mazerSizeResultLabel);
	delete(generateMazerButton);
	delete(algorithmPickerLabel);
	delete(speedLabel);
	delete(speedSlider);
	delete(pathLabel);
	delete(pathCheckBox);
	delete(startMazerReviewButton);
	delete(mazerReviewLabel);
	delete(mazerReviewTimeLabel);
	delete(runButton);
	delete(mazerRunLabel);
	delete(mazerRunTimeLabel);
}

void ControlPanel::setupLayout()
{
	setupLabels();
	setupInputs();
	setupButtons();

	layout = new QVBoxLayout();

	layout->addWidget(mazerSizeLabel);
	layout->addWidget(mazerSizeSlider);
	layout->addWidget(mazerSizeResultLabel);
	layout->addWidget(generateMazerButton);
	layout->addWidget(algorithmPickerLabel);
	layout->addWidget(speedLabel);
	layout->addWidget(speedSlider);
	layout->addWidget(pathLabel);
	layout->addWidget(pathCheckBox);
	layout->addWidget(startMazerReviewButton);
	layout->addWidget(mazerReviewLabel);
	layout->addWidget(mazerReviewTimeLabel);
	layout->addWidget(runButton);
	layout->addWidget(mazerRunLabel);
	layout->addWidget(mazerRunTimeLabel);

	this->setLayout(layout);
}

void ControlPanel::setupLabels()
{
	mazerSizeLabel = new QLabel("Rozmiar planszy");
	mazerSizeResultLabel = new QLabel("100 x 100");
	algorithmPickerLabel = new QLabel("Algorytm");
	speedLabel = new QLabel("Prędkość myszy");
	pathLabel = new QLabel("Ślad");
	mazerReviewLabel = new QLabel("Czas analizy toru");
	mazerReviewTimeLabel = new QLabel("00:00");
	mazerRunLabel = new QLabel("Czas przejścia");
	mazerRunTimeLabel = new QLabel("00:00");
}

void ControlPanel::setupInputs()
{
	mazerSizeSlider = new QSlider(Qt::Horizontal);
	speedSlider = new QSlider(Qt::Horizontal);
	pathCheckBox = new QCheckBox("Pokaż");
}

void ControlPanel::setupButtons()
{
	generateMazerButton = new QPushButton("Generuj labirynt");
	startMazerReviewButton = new QPushButton("Rozpocznij analizę");
	runButton = new QPushButton("Start");
}
