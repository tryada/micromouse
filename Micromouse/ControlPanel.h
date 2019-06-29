#pragma once

#include <qwidget.h>
#include <qlayout.h>
#include <qlabel.h>
#include <qslider.h>
#include <qpushbutton.h>
#include <qcheckbox.h>
#include <qcombobox.h>
#include <qstring.h>

class ControlPanel : public QWidget
{
	Q_OBJECT

public:
	ControlPanel(QWidget *parent);
	~ControlPanel();

private:
	QVBoxLayout *layout = Q_NULLPTR;

	// labels
	QLabel *mazeLabel;
	QLabel *speedLabel;
	QLabel *pathLabel;
	QLabel *mazeReviewLabel;
	QLabel *mazeReviewTimeLabel;
	QLabel *mazeRunLabel;
	QLabel *mazeRunTimeLabel;

	// inputs
	QComboBox *mazeComboBox;
	QSlider *speedSlider;
	QCheckBox *pathCheckBox;

	// buttons
	QPushButton *loadMazeButton;
	QPushButton *startMazeReviewButton;
	QPushButton *runButton;

	// methods
	void setupLayout();
	void setupLabels();
	void setupInputs();
	void setupButtons();
	void setupSignalsAndSlots();

private slots:
	void loadMazeButtonClick();

signals:
	void sampleChange(QString name);
};
