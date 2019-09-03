#include "mazeBlock.h"
#include <qbrush.h>
#include <qpen.h>

MazeBlock::MazeBlock(int x, int y) : 
	QGraphicsRectItem(nullptr), 
	isWall(false), 
	isFinish(false), 
	isStart(false),
	x(x),
	y(y)
{
}

MazeBlock::~MazeBlock()
{

}

bool MazeBlock::getIsStart()
{
	return isStart;
}

void MazeBlock::setIsStart(bool isStart)
{
	this->isStart = isStart;
	if (this->isStart) {
		this->setBrush(QBrush(Qt::green));
	}
}

bool MazeBlock::getIsFinish()
{
	return isFinish;
}

void MazeBlock::setIsFinish(bool isFinish)
{
	this->isFinish = isFinish;
	if (this->isFinish) {
		this->setBrush(QBrush(Qt::red));
	}
}

bool MazeBlock::getIsWall()
{
	return isWall;
}

void MazeBlock::setIsWall(bool isWall)
{
	this->isWall = isWall;
	if (this->isWall) {
		this->setBrush(QBrush(Qt::black));
	}
}

bool MazeBlock::IsUsed()
{
	return isStart || isFinish || isWall;
}

void MazeBlock::clear()
{
	this->isStart = this->isFinish = this->isWall = false;
	this->setBrush(QBrush(Qt::lightGray));
}
