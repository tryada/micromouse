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
	QLabel *mazeSizeLabel;
	QLabel *mazeSizeResultLabel;
	QLabel *algorithmPickerLabel;
	QLabel *speedLabel;
	QLabel *pathLabel;
	QLabel *mazeReviewLabel;
	QLabel *mazeReviewTimeLabel;
	QLabel *mazeRunLabel;
	QLabel *mazeRunTimeLabel;

	// inputs
	QSlider *mazeSizeSlider;
	QSlider *speedSlider;
	QCheckBox *pathCheckBox;

	// buttons
	QPushButton *generateMazeButton;
	QPushButton *startMazeReviewButton;
	QPushButton *runButton;

	// methods
	void setupLayout();
	void setupLabels();
	void setupInputs();
	void setupButtons();
};
