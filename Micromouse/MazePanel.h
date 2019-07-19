#pragma once

#include <QWidget>
#include <qgraphicsitem.h>
#include <qgraphicsscene.h>
#include <qgraphicsview.h>
#include <qlayout.h>
#include <qstring.h>
#include "maze.h"
#include "mouse.h"

class MazePanel : public QGraphicsView
{
	Q_OBJECT

public:
	MazePanel(QWidget *parent);
	~MazePanel();

private:
	Maze *maze;

	const int mazeSceneSize = 660;
	Mouse* mouse = nullptr;

	// methods
	void setup();

public slots:
	void templateChanged(QString name);
	void run();
	void analyze();
};
