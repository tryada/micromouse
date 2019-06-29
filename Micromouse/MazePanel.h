#pragma once

#include <QWidget>
#include <qgraphicsitem.h>
#include <qgraphicsscene.h>
#include <qgraphicsview.h>
#include <qlayout.h>
#include <qstring.h>
#include "maze.h"
#include "qtimer.h"

class MazePanel : public QGraphicsView
{
	Q_OBJECT

public:
	MazePanel(QWidget *parent);
	~MazePanel();

private:
	Maze *maze;
	QTimer timer;

	const int mazeSceneSize = 660;

	// methods
	void setup();

public slots:
	void templateChanged(QString name);
};
