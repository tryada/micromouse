#pragma once

#include <QtWidgets/QMainWindow>
#include <qlayout.h>
#include <qlabel.h>
#include <qslider.h>
#include <qpushbutton.h>
#include <qcheckbox.h>
#include "ui_Micromouse.h"

class Micromouse : public QMainWindow
{
	Q_OBJECT

public:
	Micromouse(QWidget *parent = Q_NULLPTR);
	~Micromouse();

private:
	Ui::MicromouseClass ui;

	// layouts
	QGridLayout *mainLayout;
	QVBoxLayout *controlsLayout;

	// labels
	QLabel *mazerSizeLabel;
	QLabel *mazerSizeResultLabel;
	QLabel *algorithmPickerLabel;
	QLabel *speedLabel;
	QLabel *pathLabel;
	QLabel *mazerReviewLabel;
	QLabel *mazerReviewTimeLabel;
	QLabel *mazerRunLabel;
	QLabel *mazerRunTimeLabel;

	// inputs
	QSlider *mazerSizeSlider;
	QSlider *speedSlider;
	QCheckBox *pathCheckBox;

	// buttons
	QPushButton *generateMazerButton;
	QPushButton *startMazerReviewButton;
	QPushButton *runButton;

	// methods
	void setupLayout();
	void setupLabels();
	void setupInputs();
	void setupButtons();

};
