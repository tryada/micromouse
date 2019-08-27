#include "mouse.h"
#include <qdebug.h>

Mouse::Mouse() : direction(North)
{
	srand(time(NULL));
	timer = new QTimer();
	timer->setInterval(2);
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
	painter->setBrush(Qt::white);
	painter->drawEllipse(QRectF(-5, -5, 3, 3));
	painter->drawEllipse(QRectF(2, -5, 3, 3));
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

	currentBlock = this->getCurrentBlock();

	if (currentBlock != nullptr && currentBlock->getIsFinish()) {
		if (timer->isActive()) {
			timer->stop();
		}
		return;
	}

	Blocks leftSensorItems = this->getCollidingBlocks(leftSensor);
	Blocks frontSensorItems = this->getCollidingBlocks(frontSensor);
	Blocks rightSensorItems = this->getCollidingBlocks(rightSensor);
	Blocks backSensorItems = this->getCollidingBlocks(backSensor);

	int leftSensorItemsCount = leftSensorItems.size();
	int rightSensorItemsCount = rightSensorItems.size();
	int frontSensorItemsCount = frontSensorItems.size();
	int backSensorItemsCount = frontSensorItems.size();

	auto leftWalls = getWalls(leftSensorItems);
	auto frontWalls = getWalls(frontSensorItems);
	auto rightWalls = getWalls(rightSensorItems);

	int step_x = 0;
	int step_y = 0;

	bool leftClear = leftWalls.size() == 0;
	bool frontClear = frontWalls.size() == 0;
	bool rightClear = rightWalls.size() == 0;
	bool backClear = getWalls(backSensorItems).size() == 0;

	bool isNode = isNodeBlock(leftClear, frontClear, rightClear, backClear);

	if (currentBlock != nullptr
		&& currentBlock != currentCrossroads
		&& isNode)
	{
		currentCrossroads = currentBlock;
		currentBlock->setBrush(QBrush(Qt::green));

		bool turned = false;

		bool isRightPathVisited = isVisitedBlock(rightSensorItems[0]);
		bool isFrontPathVisited = isVisitedBlock(frontSensorItems[0]);
		bool isLeftPathVisited = isVisitedBlock(leftSensorItems[0]);
		bool isBackPathVisited = isVisitedBlock(backSensorItems[0]);

		bool isMoveRightPossible = rightClear && !isRightPathVisited;
		bool isMoveHeadPossible = frontClear && !isFrontPathVisited;
		bool isMoveLeftPossible = leftClear && !isLeftPathVisited;

		turned = makeRandomTurn(false, false, isMoveRightPossible, false);

		if (!turned) {
			turned = makeRandomTurn(isMoveLeftPossible, isMoveHeadPossible, false, false);
		}

		if (!turned) {
			makeRandomTurn(leftClear, frontClear, rightClear, backClear);
		}

		step_y = -step;
	}
	else {
		if (isNode == false) {
			currentCrossroads = nullptr;
		}

		if (!frontClear) {
			MazeBlock* item = frontWalls[0];
			if (getDistanceFromHead(item) >= 5) {
				frontClear = true;
			}
		}

		if (frontClear) {
			step_y = -step;
		}
		else if (rightClear) {
			turnRight();
		}
		else if (leftClear) {
			turnLeft();
		}
		else {
			makeUTurn();
		}
	}

	if (leftClear == false && rightClear == false) {
		step_x = getCorrection(leftWalls[0], rightWalls[0]);
	}

	setPos(mapToParent(step_x, step_y));
}

Blocks Mouse::getCollidingBlocks(QPolygonF sensor)
{
	QList<QGraphicsItem*> items = scene()->items(sensor);

	Blocks walls;
	for (int i = 0; i < items.size(); i++) {
		MazeBlock* it = qgraphicsitem_cast<MazeBlock *>(items[i]);
		if (it != nullptr &&  it != this->currentBlock) {
			walls.push_back(it);
		}
	}

	return walls;
}

Blocks Mouse::getWalls(Blocks blocks)
{
	Blocks walls;
	for (int i = 0; i < blocks.size(); i++) {
		MazeBlock* it = qgraphicsitem_cast<MazeBlock *>(blocks[i]);
		if (it != nullptr && it->getIsWall()) {
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
	this->backSensor.clear();

	this->leftSensor
		<< mapToScene(0, 0)
		<< mapToScene(-sensorDistance, 0);
	this->frontSensor
		<< mapToScene(0, 0)
		<< mapToScene(0, -sensorDistance);
	this->rightSensor
		<< mapToScene(0, 0)
		<< mapToScene(sensorDistance, 0);
	this->backSensor
		<< mapToScene(0, 0)
		<< mapToScene(0, sensorDistance);
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

bool Mouse::makeRandomTurn(bool leftClear, bool frontClear, bool rightClear, bool backClear)
{
	if (!leftClear && !frontClear && !rightClear && !backClear) {
		return false;
	}

	bool success = false;
	int turn = -1;
	do {
		turn = rand() % 4;
		switch (turn)
		{
		case Left:
			if (leftClear) {
				turnLeft();
				success = true;
			}
		case Front:
			if (frontClear) {
				success = true;
			}
		case Right:
			if (rightClear) {
				turnRight();
				success = true;
			}
		case Back:
			if (backClear) {
				makeUTurn();
				success = true;
			}
		default:
			break;
		}
	} while (!success);
	return true;
}

bool Mouse::isNodeBlock(bool left, bool front, bool right, bool back)
{
	int wallsCount = 0;
	wallsCount += left ? 0 : 1;
	wallsCount += front ? 0 : 1;
	wallsCount += right ? 0 : 1;
	wallsCount += back ? 0 : 1;
	return wallsCount <= 1;
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
		visitedBlocks.push_back(block);
	}
}

bool Mouse::isVisitedBlock(MazeBlock* block) {
	for each (MazeBlock* vBlock in visitedBlocks)
	{
		if (vBlock == block) {
			return true;
		}
	}
	return false;
}

MazeBlock* Mouse::getCurrentBlock()
{
	auto items = scene()->items(mapToParent(boundingRect()));

	items.removeOne(this);

	if (items.size() > 1) {
		return nullptr;
	}
	else {
		MazeBlock* it = qgraphicsitem_cast<MazeBlock *>(items[0]);
		if (it != nullptr) {
			addToVisitedBlock(it);
			return it;
		}
	}
	return nullptr;
}