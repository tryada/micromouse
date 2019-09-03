#pragma once

#include <QGraphicsScene>
#include <qgraphicsitem.h>
#include <qstring.h>
#include "mazeBlock.h"
#include "mouse.h"

//! Generyczna klasa labiryntu.
/*!
	Służy do zarządzania labiryntem.
*/
template<typename T>
class Maze : public QGraphicsScene
{
public:
	//! Konstruktor.
	/*!
		Ustawia domyślne wartości.
	*/
	Maze(QObject *parent);

	//! Destruktor.
	/*!
		Zwalnia pamięć zarezerwowaną przez elementy labiryntu.
	*/
	~Maze();

	//! Publiczna metoda.
	/*!
		Podpina metoda przygotowyjąca grida.
		\sa setupGrid
	*/
	void setup();

	//! Publiczna metoda.
	/*!
		Wczytuje labirynt z podanej lokalizacji.
	*/
	void loadFromResources(QString path);

	//! Publiczna metoda.
	/*!
		Umieszcza obiekt w labiryncie na startowym elemencie.
		\sa item
	*/
	void setItem(T* item);

private:

	//! Prywatna zmienna.
	/*!
		Okresla ilość elementów na bok labiryntu.
	*/
	const int size = 33;

	//! Prywatna zmienna.
	/*!
		Przechowuje składowe labiryntu.
	*/
	std::vector<std::vector<MazeBlock*>>* blocks;

	//! Prywatna zmienna.
	/*!
		Obiekt znajdujący się w labiryncie.
		Wykonuje przejście przez labirynt.
	*/
	T* item;

	//! Prywatna zmienna.
	/*!
		Startowy element.
	*/
	MazeBlock* startBlock;

	//! Prywatna zmienna.
	/*!
		Wypełnia grid pustymi elementami.
	*/
	void setupGrid();

	//! Prywatna zmienna.
	/*!
		Usuwa obiekt (item).
		Czyści elementy labiryntu.
		\sa item
	*/
	void clearGrid();
};
