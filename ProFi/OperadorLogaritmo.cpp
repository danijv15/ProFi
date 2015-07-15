
#include "stdafx.h"
#include "OperadorLogaritmo.h"

OperadorLogaritmo::OperadorLogaritmo() {
}

OperadorLogaritmo::~OperadorLogaritmo() {
}

void OperadorLogaritmo::imprimir(ostream & out) {
	out << 'l' << endl;
}

Elemento * OperadorLogaritmo::operar(DoublyLinkedList<Elemento>& valores) {
	IteradorLista<Elemento *> iterador = valores.begin;
	Operando * v1 = dynamic_cast<Operando *>(*iterador);
	return new Operando(log(v1->getValor()));
}

