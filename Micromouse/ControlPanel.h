#pragma once

#include <qwidget.h>
#include <qlayout.h>
#include <qlabel.h>
#include <qslider.h>
#include <qpushbutton.h>
#include <qcheckbox.h>
#include <qcombobox.h>
#include <qstring.h>

//! Klasa panelu sterowania.
/*!
	Umożliwia sterowanie zachowaniem aplikacji: zmiana labiryntu, uruchomienie przejścia.
*/
class ControlPanel : public QWidget
{
	Q_OBJECT

public:
	//! Konstruktor.
	/*!
		Ustawia wysokość panelu, tworzy przyciski, listę rozwijaną.
	*/
	ControlPanel(QWidget *parent);

	//! Destruktor.
	/*!
		Zwalnia pamięć zarezerwowaną przez kontrolki.
	*/
	~ControlPanel();

private:

	//! Prywatna zmienna.
	/*!
		Głowny układ kontrolek.
	*/
	QVBoxLayout *layout = Q_NULLPTR;

	//! Prywatna zmienna.
	/*!
		Label 'Wybierz labirynt'.
	*/
	QLabel *mazeLabel;

	//! Prywatna zmienna.
	/*!
		Label 'Prędkość obiektu'.
	*/
	QLabel *speedLabel;

	//! Prywatna zmienna.
	/*!
		Label 'Ślad'.
	*/
	QLabel *pathLabel;

	//! Prywatna zmienna.
	/*!
		Label 'Czas przejścia'.
	*/
	QLabel *mazeRunLabel;

	//! Prywatna zmienna.
	/*!
		Label wyświetlający czas przejścia obiektu przez labirynt.
	*/
	QLabel *mazeRunTimeLabel;

	//! Prywatna zmienna.
	/*!
		Kontrolka umożliwiająca wybranie labiryntu z listy.
	*/
	QComboBox *mazeComboBox;

	//! Prywatna zmienna.
	/*!
		Kontrolka umożliwiająca ustawienie prędkości poruszania się obiektu.
	*/
	QSlider *speedSlider;

	//! Prywatna zmienna.
	/*!
		Kontrolka umożliwiająca ustawienie wyświetlania przebytej drogi.
	*/
	QCheckBox *pathCheckBox;

	//! Prywatna zmienna.
	/*!
		Przycisk po kliknięci którego następuje wczytanie wybranego labiryntu.
		/sa mazeComboBox
	*/
	QPushButton *loadMazeButton;

	//! Prywatna zmienna.
	/*!
		Przycisk po kliknięci którego następuje włączenie przejścia obiektu przez labirynt.
	*/
	QPushButton *startButton;

	//! Prywatna zmienna.
	/*!
		Przycisk po kliknięci którego następuje wykonanie jednego ruchu przez obiekt. 
	*/
	QPushButton *moveButton;

	//! Prywatna metoda.
	/*!
		Przygotowuje wygląd panelu sterowania
	*/
	void setupLayout();

	//! Prywatna metoda.
	/*!
		Tworzy labelki oraz dodaje je do głownego układu
		/sa layout
	*/
	void setupLabels();

	//! Prywatna metoda.
	/*!
		Tworzy kontrolki umożliwiające wybór parametrów oraz dodaje je do głownego układu.
		/sa layout
	*/
	void setupInputs();

	//! Prywatna metoda.
	/*!
		Tworzy przyciski umożliwiające sterowanie oraz dodaje je do głownego układu.
		/sa layout
	*/
	void setupButtons();

	//! Prywatna metoda.
	/*!
		Podpina sygnały przycisków z slotami panelu sterowania. 
	*/
	void setupSignalsAndSlots();

private slots:

	//! Prywatny slot.
	/*!
		Metoda wyływana w momencie kliknięcia przycisku 'Wczytaj labirynt'.
		/sa loadMazeButton
	*/
	void loadMazeButtonClick();

	//! Prywatny slot.
	/*!
		Metoda wyływana w momencie kliknięcia przycisku 'Start'.
		/sa startButton
	*/
	void startButtonClick();

	//! Prywatny slot.
	/*!
		Metoda wyływana w momencie kliknięcia przycisku 'Krok po kroku'.
		/sa moveButton
	*/
	void moveButtonClick();

signals:

	//! Publiczny sygnał.
	/*!
		Sygnał wywoływany po kliknięciu przycisku 'Wczytaj labirynt'.
		/sa loadMazeButtonClick()
		\param mazePath ścieżka do lokalizacji gdzie znajduje się plik z układem labiryntu.
	*/
	void sampleChange(QString mazePath);

	//! Publiczny sygnał.
	/*!
		Sygnał wywoływany po kliknięciu przycisku 'Krok po kroku'.
		/sa moveButtonClick()
	*/
	void move();

	//! Publiczny sygnał.
	/*!
		Metoda wyływana w momencie kliknięcia przycisku 'Start'.
		/sa startButtonClick()
	*/
	void start();
};
