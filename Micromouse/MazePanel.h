#pragma once

#include <QWidget>
#include <qgraphicsitem.h>
#include <qgraphicsscene.h>
#include <qgraphicsview.h>
#include <qlayout.h>
#include "mazeLoader.h"
#include "maze.h"

class MazePanel : public QGraphicsView
{
	Q_OBJECT

public:
	MazePanel(QWidget *parent);
	~MazePanel();

private:
	Maze *maze;

	// methods
	void setup();
};
