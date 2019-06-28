#pragma once

#include <QGraphicsRectItem>

class MazeBlock : public QGraphicsRectItem
{
public:
	MazeBlock(QGraphicsItem *parent);
	~MazeBlock();

	bool getIsStart();
	void setIsStart(bool isStart);
	bool getIsFinish();
	void setIsFinish(bool isFinish);
	bool getIsWall();
	void setIsWall(bool isWall);
	bool IsUsed();

private:
	bool isStart;
	bool isFinish;
	bool isWall;
};
