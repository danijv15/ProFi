
#include "stdafx.h"
#include "OperadorSeno.h"

OperadorSeno::OperadorSeno() {
}

OperadorSeno::~OperadorSeno() {
}

void OperadorSeno::imprimir(ostream & out) {
	out << 's' << endl;
}

Elemento * OperadorSeno::operar(DoublyLinkedList<Elemento>& valores) {
	IteradorLista<Elemento *> iterador = valores.begin;
	Operando * valor = dynamic_cast<Operando *>(*iterador);
	return new Operando(sin(valor->getValor()));
}

