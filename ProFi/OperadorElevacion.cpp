#include "stdafx.h"
#include "OperadorElevacion.h"

OperadorElevacion::OperadorElevacion() {
}

OperadorElevacion::~OperadorElevacion() {
}

void OperadorElevacion::imprimir(ostream & out) {
	out << '^' << endl;
}

Elemento * OperadorElevacion::operar(DoublyLinkedList<Elemento>& valores) {
	IteradorLista<Elemento *> iterador = valores.begin;
	Operando * izq = dynamic_cast<Operando *>(*iterador);
	Operando * der = dynamic_cast<Operando *>(*++iterador);
	return new Operando(pow((izq->getValor()), (der->getValor())));
}

