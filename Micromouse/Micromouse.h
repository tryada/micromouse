#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Micromouse.h"

class Micromouse : public QMainWindow
{
	Q_OBJECT

public:
	Micromouse(QWidget *parent = Q_NULLPTR);

private:
	Ui::MicromouseClass ui;
};
