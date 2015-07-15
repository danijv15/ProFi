#include "stdafx.h"
#include "OperadorFuncion.h"

OperadorFuncion::OperadorFuncion() {
}

OperadorFuncion::~OperadorFuncion() {
}

void OperadorFuncion::imprimir(ostream & out) {
	out << 'F' << endl;
}

Elemento * OperadorFuncion::operar(DoublyLinkedList<Elemento>& valores) {
	IteradorLista<Elemento *> iterador = valores.begin;
	Operando * v1 = dynamic_cast<Operando *>(*iterador);
	Operando * v2 = dynamic_cast<Operando *>(*++iterador);
	Operando * v3 = dynamic_cast<Operando *>(*++iterador);
	return new Operando(v1->getValor() + v2->getValor() - v3->getValor());
}

