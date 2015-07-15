
#pragma once
#include "stdafx.h"

#include "Elemento.h"
#include "Operando.h"
#include "Operador.h"
#include "OperadorSuma.h"
#include "OperadorResta.h"
#include "OperadorDivision.h"
#include "OperadorMultiplicacion.h"
#include "NodoArbol.h"
#include "DoublyLinkedList.h"
#include "OperadorElevacion.h"
#include "OperadorSeno.h"
#include "OperadorCoseno.h"
#include "OperadorTangente.h"
#include "OperadorLogaritmo.h"
#include "OperadorFuncion.h"
#include "Arbol.h"


using namespace std;

class Operacion : public Elemento {
private:

	static const int NUM_OPERADORES = 10;
	static const char OPERADORES[NUM_OPERADORES];
	static const char LEFT_PARENTHESIS = '(';
	static const char RIGHT_PARENTHESIS = ')';
	static const char LEFT_BRACKET = '[';
	static const char RIGHT_BRACKET = ']';

	string operacion;

	DoublyLinkedList<int> * hijosArbol;
	
	virtual void imprimir(ostream&);
	void eliminarEspaciosEnBlanco();
	void eliminarParentesisInnecesarios(string &);
	int indiceMenorPrecedencia(string);
	Elemento * procesarStringHijo(string);

public:
	Operacion(string);
	
	virtual ~Operacion();

	
	NodoArbol<Elemento*> * descomponer();
	
	string getValor();

};

