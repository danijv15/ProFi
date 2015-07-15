
#include "stdafx.h"
#include "OperadorSuma.h"

OperadorSuma::OperadorSuma() {
}

OperadorSuma::~OperadorSuma() {
}

void OperadorSuma::imprimir(ostream & out) {
	out << '+' << endl;
}

Elemento * OperadorSuma::operar(DoublyLinkedList<Elemento>& valores) {
	IteradorLista<Elemento *> iterador = valores.begin;
	Operando * izq = dynamic_cast<Operando *>(*iterador);
	Operando * der = dynamic_cast<Operando *>(*++iterador);
	return new Operando(izq->getValor() + der->getValor());
}

