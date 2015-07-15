
#include "stdafx.h"
#include "OperadorMultiplicacion.h"

OperadorMultiplicacion::OperadorMultiplicacion() {
}

OperadorMultiplicacion::~OperadorMultiplicacion() {
}

void OperadorMultiplicacion::imprimir(ostream & out) {
	out << '*' << endl;
}

Elemento * OperadorMultiplicacion::operar(DoublyLinkedList<Elemento>& valores) {
	IteradorLista<Elemento *> iterador = valores.begin;
	Operando * izq = dynamic_cast<Operando *>(*iterador);
	Operando * der = dynamic_cast<Operando *>(*++iterador);
	return new Operando(izq->getValor() + der->getValor());
}

