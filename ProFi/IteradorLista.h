#pragma once
#include "NodoLista.h"

template<class T>
class IteradorLista {

private:
	
	NodoLista<T> * actual;

public:

	IteradorLista(NodoLista<T> * actual) {
		this->actual = actual;
	}

	
	~IteradorLista() {
	}

	
	IteradorLista<T>& operator++() {
		this->actual = this->actual->siguiente;
		return *this;
	}


	IteradorLista<T> operator++(int) {
		IteradorLista<T> tmp(this->actual);
		++(*this);
		return tmp;
	}

	
	T operator*() {
		return actual->actual;
	}

	
	void operator=(T & nuevoActual) {
		actual->actual = nuevoActual;
	}

	
	bool operator!=(IteradorLista<T> & otro) {
		return this->actual != otro.actual;
	}

	
	bool operator==(IteradorLista<T> & otro) {
		return this->actual == otro.actual;
	}

};