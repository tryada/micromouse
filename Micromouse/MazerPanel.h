#pragma once

#include <QWidget>
#include <qgraphicsitem.h>
#include <qgraphicsscene.h>
#include <qgraphicsview.h>
#include <qlayout.h>

class MazerPanel : public QWidget
{
	Q_OBJECT

public:
	MazerPanel(QWidget *parent);
	~MazerPanel();


private:
	QGridLayout *layout;

	QGraphicsScene *scene;
	QGraphicsView *view;

	// methods
	void setup();
};
