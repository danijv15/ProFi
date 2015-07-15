
#include "stdafx.h"
#include "OperadorCoseno.h"

OperadorCoseno::OperadorCoseno() {
}

OperadorCoseno::~OperadorCoseno() {
}

void OperadorCoseno::imprimir(ostream & out) {
	out << 'c' << endl;
}

Elemento * OperadorCoseno::operar(DoublyLinkedList<Elemento>& valores) {
	IteradorLista<Elemento *> iterador = valores.begin;
	Operando * valor = dynamic_cast<Operando *>(*iterador);
	return new Operando(sin(valor->getValor()));
}
