#pragma once

#include <QWidget>
#include <qgraphicsitem.h>
#include <qgraphicsscene.h>
#include <qgraphicsview.h>
#include <qlayout.h>
#include "MazeGenerator.h"

class MazePanel : public QWidget
{
	Q_OBJECT

public:
	MazePanel(QWidget *parent);
	~MazePanel();

	void generate();

	QGraphicsView* getView();

private:
	QGraphicsScene *scene;
	QGraphicsView *view;

	// methods
	void setup();
};
