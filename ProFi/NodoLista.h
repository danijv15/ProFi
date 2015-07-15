#pragma once

template<class T>
class NodoLista {

	template <class T>
	friend class Lista;

	template <class T>
	friend class IteradorLista;

private:
	T actual;
	

public:
	NodoLista<T> *siguiente, *anterior;

	NodoLista(T elemento) {
		this->actual = elemento;
		siguiente = NULL;
		anterior = NULL;
	}

	
	~NodoLista() {
	}

	T * NodoLista::getNodoLista(){
		return actual;
	}


private:
	void imprimir(ostream & out) {
		out << actual;
	}

};
