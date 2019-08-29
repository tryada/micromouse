#pragma once

#include <QWidget>
#include <qgraphicsitem.h>
#include <qgraphicsscene.h>
#include <qgraphicsview.h>
#include <qlayout.h>
#include <qstring.h>
#include "maze.h"
#include "maze.cpp"
#include "mouse.h"

//! Klasa podglądu labiryntu.
/*!
	Wyświetla oraz wczytuje labirynt. 
	Umożliwia umiejscowienie w nim obiektu.
*/
class MazePanel : public QGraphicsView
{
	Q_OBJECT

public:
	//! Konstruktor.
	/*!
		Przygotowuje widok.
	*/
	MazePanel(QWidget *parent);

	//! Destruktor.
	/*!
		Zwalnia pamięć.
	*/
	~MazePanel();

private:

	//! Prywatna zmienna.
	/*!
		Scena wyświetlająca labirynt.
	*/
	Maze<Mouse> *maze;

	//! Prywatna zmienna.
	/*!
		Długość boku sceny.
		/sa maze
	*/
	const int mazeSceneSize = 660;

	//! Prywatna zmienna.
	/*!
		Obiekt w labiryncie.
	*/
	Mouse* item = nullptr;

	//! Prywatna metoda.
	/*!
		Przygotowuje labirynt, ustawia kolor tła. Ustawia scene.
		/sa maze
	*/
	void setup();

public slots:

	//! Publiczny slot.
	/*!
		Slot wczytujący labirynt z podanej lokalizacji.
		\param mazePath ścieżka do lokalizacji gdzie znajduje się plik z układem labiryntu.
	*/
	void templateChanged(QString mazePath);

	//! Publiczny slot.
	/*!
		Zmusza obiekt do wykonania pojedynczego ruchu.
		\sa item
	*/
	void move();

	//! Publiczny slot.
	/*!
		Uruchamia wykonanie ruchu przez obiekt.
		\sa item
	*/
	void start();
};
