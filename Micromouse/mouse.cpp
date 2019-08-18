#include "mouse.h"
#include <qdebug.h>

Mouse::Mouse() : direction(North)
{
	timer = new QTimer();
	timer->setInterval(10);
	QObject::connect(timer, &QTimer::timeout, this, &Mouse::analyzeIteration);
}

Mouse::~Mouse()
{
}

void Mouse::analyze()
{
	if (timer->isActive()) {
		timer->stop();
	}
	else {
		timer->start();
	}
}

void Mouse::run()
{
	this->analyzeIteration();
}

void Mouse::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	painter->setBrush(Qt::red);
	painter->drawEllipse(boundingRect());
}

QRectF Mouse::boundingRect() const
{
	return QRectF(-5, -5, 10, 10);
}

void Mouse::runIteration()
{

}

void Mouse::analyzeIteration()
{
	this->resetSensors();

	std::vector<MazeBlock*> leftSensorItems = this->getWalls(leftSensor);
	std::vector<MazeBlock*> frontSensorItems = this->getWalls(frontSensor);
	std::vector<MazeBlock*> rightSensorItems = this->getWalls(rightSensor);

	int leftSensorItemsCount = leftSensorItems.size();
	int rightSensorItemsCount = rightSensorItems.size();

	qDebug()
		<< "left: " << leftSensorItems.size() << ";"
		<< "top: " << frontSensorItems.size() << ";"
		<< "right: " << rightSensorItems.size() << ";";

	int step_x = 0;
	int step_y = 0;

	this->getCurrentBlock();

	bool frontEmpty = frontSensorItems.size() == 0;

	if (!frontEmpty) {
		MazeBlock* item = frontSensorItems[0];
		if (getDistanceFromHead(item) >= 5) {
			frontEmpty = true;
		}
	}

	if (frontEmpty) {
		step_y = -step;
	}
	else {
		if (leftSensorItemsCount == 0) {
			turnLeft();
		}
		else if (rightSensorItemsCount == 0) {
			turnRight();
		}
		else {
			makeUTurn();
		}
	}

	if (leftSensorItemsCount > 0 && rightSensorItemsCount > 0) {
		step_x = getCorrection(leftSensorItems[0], rightSensorItems[0]);
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
			walls.push_back(it);
		}
	}

	return walls;
}

void Mouse::resetSensors()
{
	this->leftSensor.clear();
	this->frontSensor.clear();
	this->rightSensor.clear();

	this->leftSensor
		<< mapToScene(0, 0)
		<< mapToScene(-sensorDistance, 0);
	this->frontSensor
		<< mapToScene(0, 0)
		<< mapToScene(0, -sensorDistance);
	this->rightSensor
		<< mapToScene(0, 0)
		<< mapToScene(sensorDistance, 0);
}

void Mouse::turnLeft()
{
	this->setRotation(this->rotation() - 90);
	if (direction == North) {
		direction = West;
	}
	else {
		direction = (DirectionEnum)(direction - 1);
	}
}

void Mouse::turnRight()
{
	this->setRotation(this->rotation() + 90);
	if (direction == West) {
		direction = North;
	}
	else {
		direction = (DirectionEnum)(direction + 1);
	}
}

void Mouse::makeUTurn()
{
	this->setRotation(this->rotation() + 180);
	switch (direction)
	{
	case North:
		direction = South;
		break;
	case East:
		direction = West;
		break;
	case South:
		direction = North;
		break;
	case West:
		direction = East;
		break;
	default:
		break;
	}
}

int Mouse::getDistanceFromHead(MazeBlock* block)
{
	int distance = -1;
	auto blockRect = block->rect();
	auto mouseRect = this->sceneBoundingRect();

	switch (direction)
	{
	case North:
		distance = mouseRect.y() - (blockRect.y() + blockRect.height());
		break;
	case East:
		distance = blockRect.x() - (mouseRect.x() + mouseRect.width());
		break;
	case South:
		distance = blockRect.y() - (mouseRect.y() + mouseRect.height());
		break;
	case West:
		distance = mouseRect.x() - (blockRect.x() + blockRect.width());
		break;
	default:
		break;
	}
	return distance;
}

int Mouse::getDistanceFromLeftSide(MazeBlock * block)
{
	int distance = -1;
	auto blockRect = block->rect();
	auto mouseRect = this->sceneBoundingRect();

	switch (direction)
	{
	case North:
		distance = mouseRect.x() - (blockRect.x() + blockRect.width());
		break;
	case East:
		distance = mouseRect.y() - (blockRect.y() + blockRect.height());
		break;
	case South:
		distance = blockRect.x() - (mouseRect.x() + mouseRect.width());
		break;
	case West:
		distance = blockRect.y() - (mouseRect.y() + mouseRect.height());
		break;
	default:
		break;
	}
	return distance;
}

int Mouse::getDistanceFromRightSide(MazeBlock * block)
{
	int distance = -1;
	auto blockRect = block->rect();
	auto mouseRect = this->sceneBoundingRect();

	switch (direction)
	{
	case North:
		distance = blockRect.x() - (mouseRect.x() + mouseRect.width());
		break;
	case East:
		distance = blockRect.y() - (mouseRect.y() + mouseRect.height());
		break;
	case South:
		distance = mouseRect.x() - (blockRect.x() + blockRect.width());
		break;
	case West:
		distance = mouseRect.y() - (blockRect.y() + blockRect.height());
		break;
	default:
		break;
	}
	return distance;
}

int Mouse::getCorrection(MazeBlock* leftBlock, MazeBlock* rightBlock)
{
	auto distanceToLeftBlock = getDistanceFromLeftSide(leftBlock);
	auto distanceToRightBlock = getDistanceFromRightSide(rightBlock);

	int correction = abs(distanceToLeftBlock - distanceToRightBlock);
	if (correction <= 1) {
		return 0;
	}
	else {
		return distanceToLeftBlock > distanceToRightBlock ? -1 : 1;
	}
}

void Mouse::addToVisitedBlock(MazeBlock * block)
{
	bool exists = false;

	for each (MazeBlock* vBlock in visitedBlocks)
	{
		if (vBlock == block) {
			exists = true;
			break;
		}
	}

	if (!exists) {
		block->setBrush(QBrush(Qt::blue));
		visitedBlocks.push_back(block);
	}
}

MazeBlock* Mouse::getCurrentBlock()
{
	auto items = scene()->items(mapToParent(boundingRect()));

	for (int i = 0; i < items.size(); i++) {
		MazeBlock* it = qgraphicsitem_cast<MazeBlock *>(items[i]);
		if (it != nullptr) {
			addToVisitedBlock(it);
		}
	}

	return nullptr;
}