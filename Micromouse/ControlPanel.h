#pragma once

#include <qwidget.h>
#include <qlayout.h>
#include <qlabel.h>
#include <qslider.h>
#include <qpushbutton.h>
#include <qcheckbox.h>

class ControlPanel : public QWidget
{
	Q_OBJECT

public:
	ControlPanel(QWidget *parent);
	~ControlPanel();

private:
	QVBoxLayout *layout = Q_NULLPTR;

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
