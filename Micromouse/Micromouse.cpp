#include "Micromouse.h"

Micromouse::Micromouse(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QWidget * central = new QWidget();
	setCentralWidget(central);
	this->setupLayout();
}

void Micromouse::setupLayout()
{
	setupLabels();
	setupInputs();
	setupButtons();

	mainLayout = new QGridLayout();
	controlsLayout = new QVBoxLayout();

	controlsLayout->addWidget(mazerSizeLabel);
	controlsLayout->addWidget(mazerSizeSlider);
	controlsLayout->addWidget(mazerSizeResultLabel);
	controlsLayout->addWidget(generateMazerButton);
	controlsLayout->addWidget(algorithmPickerLabel);
	controlsLayout->addWidget(speedLabel);
	controlsLayout->addWidget(speedSlider);
	controlsLayout->addWidget(pathLabel);
	controlsLayout->addWidget(pathCheckBox);
	controlsLayout->addWidget(startMazerReviewButton);
	controlsLayout->addWidget(mazerReviewLabel);
	controlsLayout->addWidget(mazerReviewTimeLabel);
	controlsLayout->addWidget(runButton);
	controlsLayout->addWidget(mazerRunLabel);
	controlsLayout->addWidget(mazerRunTimeLabel);

	mainLayout->addItem(controlsLayout, 0, 0);
	centralWidget()->setLayout(mainLayout);
}

void Micromouse::setupLabels()
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

void Micromouse::setupInputs()
{
	mazerSizeSlider = new QSlider(Qt::Horizontal);
	speedSlider = new QSlider(Qt::Horizontal);
	pathCheckBox = new QCheckBox("Pokaż");
}

void Micromouse::setupButtons()
{
	generateMazerButton = new QPushButton("Generuj labirynt");
	startMazerReviewButton = new QPushButton("Rozpocznij analizę");
	runButton = new QPushButton("Start");
}

Micromouse::~Micromouse()
{
}
