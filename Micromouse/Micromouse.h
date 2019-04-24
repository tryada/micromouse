#pragma once

#include <QtWidgets/QMainWindow>
#include <qlayout.h>
#include "ui_Micromouse.h"
#include "controlPanel.h"
#include "mazePanel.h"

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
	ControlPanel *controlPanel;
	MazePanel *mazePanel;

	// methods
	void setupLayout();
};
