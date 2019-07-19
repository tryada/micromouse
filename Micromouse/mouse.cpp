#include "mouse.h"
#include <qdebug.h>

Mouse::Mouse() : direction(Left)
{
	timer = new QTimer();
	timer->setInterval(50);
}

Mouse::~Mouse()
{
}

void Mouse::analyze()
{
	if (timer->isActive())
		return;

	QObject::connect(timer, &QTimer::timeout, this, &Mouse::analyzeIteration);
	timer->start();
}

void Mouse::run()
{
	if (timer->isActive())
		return;

	QObject::connect(timer, &QTimer::timeout, this, &Mouse::runIteration);
	timer->start();
}

void Mouse::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	painter->setBrush(Qt::red);
	painter->drawEllipse(QRectF(-5, -5, 10, 10));
	painter->drawLine(-15, 0, 0, 0);
	painter->drawLine(0, 15, 0, 0);
	painter->drawLine(15, 0, 0, 0);
	painter->drawLine(0, -15, 0, 0);
}

QRectF Mouse::boundingRect() const
{
	return QRectF(-15, -15, 30, 30);
}

void Mouse::runIteration()
{

}

void Mouse::analyzeIteration()
{
	this->resetSensors();

	std::vector<MazeBlock*> leftSensorItems = this->getWalls(leftSensor);
	std::vector<MazeBlock*> upSensorItems = this->getWalls(topSensor);
	std::vector<MazeBlock*> rightSensorItems = this->getWalls(rightSensor);
	std::vector<MazeBlock*> bottomSensorItems = this->getWalls(bottomSensor);

	qDebug()
		<< "left: " << leftSensorItems.size() << ";"
		<< "top: " << upSensorItems.size() << ";"
		<< "right: " << rightSensorItems.size() << ";"
		<< "bottom: " << bottomSensorItems.size() << ";";

	int step_x = 0;
	int step_y = 0;

	if (direction == Left) {
		if (leftSensorItems.size() == 0) {
			step_x = -1;
		}
		else {
			direction = Up;
		}
	}

	if (direction == Up) {
		if (upSensorItems.size() == 0) {
			step_y = -1;
		}
		else {
			direction = Right;

		}
	}

	if (direction == Right) {
		if (rightSensorItems.size() == 0) {
			step_x = 1;
		}
		else {
			direction = Down;
		}
	}

	if (direction == Down) {
		if (bottomSensorItems.size() == 0) {
			step_y = 1;
		}
		else {
			direction = Left;
		}
	}

	setPos(mapToParent(step_x, step_y));
}

std::vector<MazeBlock*> Mouse::getWalls(QPolygonF sensor)
{
	QList<QGraphicsItem*> items = scene()->items(sensor);

	std::vector<MazeBlock*> walls;
	for (int i = 0; i < items.size(); i++) {
		MazeBlock* it = qgraphicsitem_cast<MazeBlock *>(items[i]);
		if (it != nullptr && !it->getIsStart() && it->IsUsed()) {
			it->setBrush(QBrush(Qt::yellow));
			walls.push_back(it);
		}
	}

	return walls;
}

void Mouse::resetSensors()
{
	this->leftSensor.clear();
	this->topSensor.clear();
	this->rightSensor.clear();
	this->bottomSensor.clear();

	this->leftSensor
		<< mapToScene(0, 0)
		<< mapToScene(-15, 0);
	this->topSensor
		<< mapToScene(0, 0)
		<< mapToScene(0, -15);
	this->rightSensor
		<< mapToScene(0, 0)
		<< mapToScene(15, 0);
	this->bottomSensor
		<< mapToScene(0, 0)
		<< mapToScene(0, 15);
}
