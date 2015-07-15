#pragma once

#include "stdafx.h"
#include "NodoArbol.h"
#include "IteradorLista.h"

using namespace std;

template <class T>
class Arbol {

	template<class T>
	friend ostream & operator<<(ostream &, Arbol<T> &);

private:
	NodoArbol<Elemento *> * raiz;
	
public:
	
	Arbol(T operacion) {
		raiz = new NodoArbol<Elemento *>(operacion);
	}
	
	
	~Arbol() {
		if (raiz != NULL){
			destruirRec(raiz);
		}
	}

	
	void destruirRec(NodoArbol<Elemento *> * actual) {
		if (actual->getNodoArbolHijos() != NULL) {
			destruirRec(actual->getNodoArbolHijos());
		}
		delete actual;
	}
	
	
	void descomponer() {
		descomponerRec(raiz);
	}
	
	
	void descomponerRec(NodoArbol<Elemento *> *& actual) {
		Operacion * operacion = dynamic_cast<Operacion *>(actual->getNodoArbol());
		if (operacion != NULL) {
			NodoArbol<Elemento *> * tmp = actual;
			actual = operacion->descomponer();
			delete tmp;
			DoublyLinkedList<T> * hijos = actual->getNodoArbolHijos;
			if (hijos != NULL) {
				descomponerRec(actual->getNodoArbolHijos());
			}
		}
	}
	
	
	void solucionar() {
		solucionarRec(raiz);
	}
	
	
	void solucionarRec(NodoArbol<Elemento *> *& actual) {
		Operador * op = dynamic_cast<Operador*>(actual->getNodoArbol());
		if (op != NULL) {
			DoublyLinkedList<Elemento*> hijos = actual->getNodoArbolHijos;
			if (hijos != NULL) {
				solucionarRec(actual->getNodoArbolHijos);
			}
			DoublyLinkedList<Elemento*> solucion = op->operar(actual->getNodoArbolHijos());
			delete actual;
			actual = solucion;
		}
	}


	NodoArbol<Elemento *> * getRaiz() {
		return raiz->getNodoArbol();
	}
	
};

template<class T>
ostream & operator<<(ostream & out, Arbol<T> & a) {
	a.imprimir(a.raiz, out, 0);
	return out;
}