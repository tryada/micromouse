#pragma once

//! Typ wyliczeniowy.
/*! Umozliwia identyfikacje globalnych kierunków. */
enum DirectionEnum {
	North = 0, /*!< Północ - góra okna */ 
	East = 1, /*!< Zachód - prawa strona okna */ 
	South = 2, /*!< Południe - dół okna. */ 
	West = 3 /*!< Zachód - lewa strona okna */ 
};

//! Typ wyliczeniowy.
/*! Umozliwia identyfikacje boku wybranego obiektu. */
enum SideEnum {
	Left = 0, /*!< Lewy bok/ krawędź. */ 
	Front = 1, /*!< Przód. */ 
	Right = 2, /*!< Prawy bok/ krawędź. */ 
	Back = 3 /*!< Tył. */ 
};