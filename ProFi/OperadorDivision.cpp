
#include "stdafx.h"
#include "OperadorDivision.h"

OperadorDivision::OperadorDivision() {
}

OperadorDivision::~OperadorDivision() {
}

void OperadorDivision::imprimir(ostream & out) {
	out << '/' << endl;
}

Elemento * OperadorDivision::operar(DoublyLinkedList<Elemento>& valores) {
	IteradorLista<Elemento *> iterador = valores.begin;
	Operando * izq = dynamic_cast<Operando *>(*iterador);
	Operando * der = dynamic_cast<Operando *>(*++iterador);
	return new Operando(izq->getValor() + der->getValor());
}


