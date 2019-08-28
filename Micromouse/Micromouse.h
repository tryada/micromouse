#pragma once

#include <QtWidgets/QMainWindow>
#include <qlayout.h>
#include "ui_Micromouse.h"
#include "controlPanel.h"
#include "mazePanel.h"

//! Głowna klasa
/*!
Umożliwia wyświetelnie okna.
Łączy panel sterowania z podglądem labiryntu.
*/
class Micromouse : public QMainWindow
{
	Q_OBJECT

public:
	//! Konstruktor.
	/*!
	Ustawia wysokość okna, przygotowuje widok, oraz łączy panel sterowania z podglądem.
	*/
	Micromouse(QWidget *parent = Q_NULLPTR);

	//! Destruktor.
	/*!
	Zwalnia pamięć.
	*/
	~Micromouse();

private:
	//! Prywatna zmienna.
	/*!
	  Zmienna przechowująca interfejs użytkownia.
	*/
	Ui::MicromouseClass ui;

	//! Prywatna zmienna.
	/*!
	  Głowny układ paneli.
	*/
	QGridLayout *mainLayout;

	//! Prywatna zmienna.
	/*!
	  Panel sterowania, umożliwia sterowanie aplikacją.
	*/
	ControlPanel *controlPanel;

	//! Prywatna zmienna.
	/*!
	  Panel z labiryntem, wyświetla labirynt oraz przechodzącą przez niego mysz.
	*/
	MazePanel *mazePanel;

	//! Prywatna metoda.
	/*!
		Tworzy panele, ustawia ich pozycję na głównym układzie.
		\sa mainLayout
	*/
	void setupLayout();

	//! Prywatna metoda.
	/*!
		Podpina sygnały panelu sterowania z slotami panelem labiryntu. 
	*/
	void setupSignalsAndSlots();
};
