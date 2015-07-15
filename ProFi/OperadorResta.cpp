
#include "stdafx.h"
#include "OperadorResta.h"

OperadorResta::OperadorResta() {
}

OperadorResta::~OperadorResta() {
}

void OperadorResta::imprimir(ostream & out) {
	out << '-' << endl;
}

Elemento * OperadorResta::operar(DoublyLinkedList<Elemento>& valores) {
	IteradorLista<Elemento *> iterador = valores.begin;
	Operando * izq = dynamic_cast<Operando *>(*iterador);
	Operando * der = dynamic_cast<Operando *>(*++iterador);
	return new Operando(izq->getValor() + der->getValor());
}

