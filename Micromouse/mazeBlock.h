#pragma once

#include <QGraphicsRectItem>

class MazeBlock : public QGraphicsRectItem
{
public:
	MazeBlock(int x, int y);
	~MazeBlock();

	bool getIsStart();
	void setIsStart(bool isStart);
	bool getIsFinish();
	void setIsFinish(bool isFinish);
	bool getIsWall();
	void setIsWall(bool isWall);
	bool IsUsed();

	void clear();

private:
	bool isStart;
	bool isFinish;
	bool isWall;

	int x;
	int y;
};
