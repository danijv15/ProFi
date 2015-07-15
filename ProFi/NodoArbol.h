#pragma once

#include "DoublyLinkedList.h"

template <class T>
class NodoArbol {

	template <class T>
	friend class ArbolBinario;

	template<class T>
	friend ostream & operator<<(ostream &, NodoLista<T> &);

private:
	T actual;
	DoublyLinkedList<T> * hijos; 

public:
	NodoArbol(T act) {
		this->actual = act;
		hijos = new DoublyLinkedList<T>();
	}

	~NodoArbol() {
	}
	
	
	T & getNodoArbol() {
		return actual;
	}

	
	DoublyLinkedList<T> & getNodoArbolHijos() {
		return hijos;
	}


	void agregarHijo(T nuevoHijo) {
		hijos.insertarFinal(nuevoHijo);
	}

	
	int getCantidadHijos() {
		return hijos->cantidadElementos();
	}


private:
	void imprimir(ostream & out) {
		out << actual;
	}

};


template<class T>
ostream & operator<<(ostream & out, NodoArbol<Elemento*> & a) {
	a.imprimir(out);
	return out;
}
