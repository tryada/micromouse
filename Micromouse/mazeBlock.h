#pragma once

#include <QGraphicsRectItem>

//! Klasa reprezentująca pojedynczy element planszy.
/*!
	Umożliwia określienie elemento jako ścianę, wejście, wyjście oraz korytarz.
	Jest to podstawowy element labiryntu.
*/
class MazeBlock : public QGraphicsRectItem
{
public:
	//! Konstruktor.
	/*!
		Ustawia domyślne wartości.
		\param x współrzędna na osi x.
		\param y współrzędna na osi y.
	*/
	MazeBlock(int x, int y);

	//! Destruktor.
	~MazeBlock();

	//! Publiczna metoda.
	/*!
		Zwraca informację czy dany element jest określony jako start.
	*/
	bool getIsStart();

	//! Publiczna metoda.
	/*!
		Ustawia pole isStart.
		\sa isStart.
		\param isStart nowa wartość pola isStart.
	*/
	void setIsStart(bool isStart);

	//! Publiczna metoda.
	/*!
		Zwraca informację czy dany element jest określony jako koniec.
	*/
	bool getIsFinish();

	//! Publiczna metoda.
	/*!
		Ustawia pole isFinish.
		\sa isFinish.
		\param isFinish nowa wartość pola isFinish.
	*/
	void setIsFinish(bool isFinish);

	//! Publiczna metoda.
	/*!
		Zwraca informację czy dany element jest określony jako ściana.
	*/
	bool getIsWall();

	//! Publiczna metoda.
	/*!
		Ustawia pole isWall.
		\sa isWall.
		\param isFinish nowa wartość pola isWall.
	*/
	void setIsWall(bool isWall);

	//! Publiczna metoda.
	/*!
		Zwraca informację czy dany element jest określony jako start, koniec, lub ściana.
	*/
	bool IsUsed();

	//! Publiczna metoda.
	/*!
		Ustawia domyślny kolor oraz resetuje parametry.
	*/
	void clear();

private:
	//! Prywatna zmienna.
	/*!
		Flaga zawierająca informację czy dany element jest określony jako start.
	*/
	bool isStart;

	//! Prywatna zmienna.
	/*!
		Flaga zawierająca informację czy dany element jest określony jako koniec.
	*/
	bool isFinish;

	//! Prywatna zmienna.
	/*!
		Flaga zawierająca informację czy dany element jest określony jako ściana.
	*/
	bool isWall;

	//! Prywatna zmienna.
	/*!
		Współrzędna x.
	*/
	int x;

	//! Prywatna zmienna.
	/*!
		Współrzędna y.
	*/
	int y;
};
