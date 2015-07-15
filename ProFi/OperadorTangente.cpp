
#include "stdafx.h"
#include "OperadorTangente.h"

OperadorTangente::OperadorTangente() {
}

OperadorTangente::~OperadorTangente() {
}

void OperadorTangente::imprimir(ostream & out) {
	out << 't' << endl;
}

Elemento * OperadorTangente::operar(DoublyLinkedList<Elemento>& valores) {
	IteradorLista<Elemento *> iterador = valores.begin;
	Operando * valor = dynamic_cast<Operando *>(*iterador);
	return new Operando(sin(valor->getValor()));
}

