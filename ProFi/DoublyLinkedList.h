#pragma once

#include "stdafx.h"
#include "NodoLista.h"
#include "IteradorLista.h"

using namespace std;

template<class T>
class DoublyLinkedList {

	template<class T>
	friend ostream & operator<<(ostream &, DoublyLinkedList<T> &);

private:
	NodoLista<T> *inicio;
	NodoLista<T> *final;
	int cantidadElementos;

public:
	DoublyLinkedList() {
		inicio = NULL;
		final = NULL;
		cantidadElementos = 0;
	}
	
	virtual ~DoublyLinkedList() {
		if (inicio != NULL) {
			int s = cantidadElementos;
			for (int i = 0; i < s; i++) {
				eliminarInicio();
			}
		}
	}

	void insertarInicio(T elemento) {
		if (inicio == NULL) {
			NodoLista<T> * e = new NodoLista<T>(elemento;)
			this->inicio = e;
			this->final = e;
		}
		else {
			NodoLista<T> * temp = new NodoLista<T>(elemento);
			temp->siguiente = this->inicio;
			if (this->inicio != NULL) {
				this->inicio->anterior = temp;
			}
			this->inicio = temp;
		}
		cantidadElementos++;
	}
	
	
	void insertarFinal(T elemento) {
		if (final == NULL) {
			NodoLista<T> * e = new NodoLista<T>(elemento);
			this->inicio = e;
			this->final = e;
		}
		else {
			NodoLista<T> * temp = new NodoLista<T>(elemento);
			this->final->siguiente = temp;
			temp->anterior = this->final;
			this->final = temp;
		}
		cantidadElementos++;
	}
	
	
	void insertarElemento(T elemento, int posicion) {
		NodoLista<T> * temp1 = new NodoLista<T>(this->inicio);
		while (--posicion != 0) {
			temp1 = temp1->siguiente;
		}
		NodoLista<T> * temp2 = new NodoLista<T>(temp1->siguiente);
		NodoLista<T> * temp = new NodoLista<T>(elemento);
		temp->siguiente = temp2;
		temp2->anterior = temp;
		temp1->siguiente = temp;
		temp->anterior = temp1;
		cantidadElementos++;
	}

	
	void eliminarInicio() {
		NodoLista<T> * temp = inicio;
		this->inicio = this->inicio->siguiente;
		delete temp;
		if (this->inicio != NULL) {
			this->inicio->anterior = NULL;
		}
		cantidadElementos--;
	}
	
	
	void eliminarFinal() {
		NodoLista<T> * temp = new NodoLista<T>(this->final);
		this->final = this->final->anterior;
		this->final->siguiente = NULL;
		delete temp;
		cantidadElemento--;
	}
	
	
	void eliminarElemento(int posicion) {
		NodoLista<T> * cur = new NodoLista<T>(this->inicio);
		while (--posicion != 0) {
			cur = cur->siguiente;
		}
		NodoLista<T> * aEliminar = new NodoLista<T>(cur->siguiente);
		NodoLista<T> * temp = new NodoLista<T>(aEliminar->siguiente);
		delete aEliminar;
		cur->siguiente = temp;
		temp->anterior = cur;
		cantidadElementos--;
	}
	
	
	int getCantidadElementos() {
		return cantidadElementos;
	}


	T * getPrimerElemento() {
		return inicio->getNodoLista();
	}

	
	T * getNodo(int pos) {
		NodoLista<T> * temp1 = new NodoLista<T>(this->inicio);
		int x = cantidadElementos();
		while (--x != 0) {
			if (x == pos) {
				return temp1->getNodoLista();
			}
			temp1 = temp1->siguiente;
		}
	}

	
		IteradorLista<T> begin() {
		return IteradorLista<T>(head);
	}

	IteradorLista<T> end() {
		return IteradorLista<T>(NULL);
	}

private:
	void imprimir(ostream& out) {
		NodoLista<T> * aImprimir = new NodoLista<T>(this->inicio);
		while (aImprimir != NULL) {
			out << aImprimir;
			aImprimir = aImprimir->siguiente;
		}
	}

};

template<class T>
ostream & operator<<(ostream & out, DoublyLinkedList<T> & li) {
	li.imprimir(li.inicio, out);
	return out;
}
