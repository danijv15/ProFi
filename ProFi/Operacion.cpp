
#include "stdafx.h"
#include "Operacion.h"

const char Operacion::OPERADORES[Operacion::NUM_OPERADORES] = { '+', '-', '/', '*', '^', 's', 'c', 't', 'l', 'F' };

Operacion::Operacion(string operacion) {
	this->operacion = operacion;
	eliminarEspaciosEnBlanco();
	eliminarParentesisInnecesarios(this->operacion);
}

Operacion::~Operacion() {
}


NodoArbol<Elemento*> * Operacion::descomponer() {

	NodoArbol<Elemento*> * resultado;
	Elemento * res;
	int indice = indiceMenorPrecedencia(operacion);
	string centro = operacion.substr(indice, 1);

	if (indice == -1) {
		res = new Operando(stod(operacion)); //convierto el string a double para poder procesarlo
		resultado = new NodoArbol<Elemento*>(res);
		return resultado;
	} 
	else if (indice == 0 && centro == "F") {
		res = new OperadorFuncion();
		resultado = new NodoArbol<Elemento *>(res);
		string derecha = operacion.substr(indice + 2, operacion.length() - indice - 2);
		istringstream strDer(derecha); //Procesarlo como objeto string
		string marcador;
		while (getline(strDer, marcador, ',')) {
			resultado->agregarHijo(procesarStringHijo(marcador));
			return resultado;
		}
	}
	else if (indice == 0){
		string centro = operacion.substr(indice, 1);
		string derecha = operacion.substr(indice + 1, operacion.length() - indice - 1);

		switch (centro[0]) {
		case 's':
			res = new OperadorSeno();
			resultado = new NodoArbol<Elemento *>(res);
			break;
		case 'c':
			res = new OperadorCoseno();
			resultado = new NodoArbol<Elemento *>(res);
			break;
		case 't':
			res = new OperadorTangente();
			resultado = new NodoArbol<Elemento *>(res);
			break;
		case 'l':
			res = new OperadorLogaritmo();
			resultado = new NodoArbol<Elemento *>(res);
			break;
		default:
			resultado = NULL;
			break;
		}

		resultado->agregarHijo(procesarStringHijo(derecha));
		return resultado;
	}
	else {

		string izquierda = operacion.substr(0, indice);
		string centro = operacion.substr(indice, 1);
		string derecha = operacion.substr(indice + 1, operacion.length() - indice - 1);

		switch (centro[0]) {
		case '+':
			res = new OperadorSuma();
			resultado = new NodoArbol<Elemento*>(res);
			break;
		case '-':
			res = new OperadorResta();
			resultado = new NodoArbol<Elemento*>(res);
			break;
		case '/':
			res = new OperadorDivision();
			resultado = new NodoArbol<Elemento*>(res);
			break;
		case'*':
			res = new OperadorMultiplicacion();
			resultado = new NodoArbol<Elemento*>(res);
			break;
		default:
			resultado = NULL;
			break;
		}

		resultado->agregarHijo(procesarStringHijo(izquierda));
		resultado->agregarHijo(procesarStringHijo(derecha));
		return resultado;
	}
}

void Operacion::eliminarEspaciosEnBlanco() {
	for (unsigned int i = 0; i < operacion.length(); ++i) {
		switch (operacion[i]) {
		case ' ':
		case '\t':
		case '\n':
			operacion.erase(i, 1);
			--i;
		default:
			break;
		}
	}
}

void Operacion::eliminarParentesisInnecesarios(string & string) {
	bool continuar = true;
	while (continuar) {
		continuar = false;
		if (string[0] == LEFT_PARENTHESIS && string[string.length() - 1] == RIGHT_PARENTHESIS) {
			int parentesis = 1;
			bool quitarParentesis = true;
			for (unsigned int i = 1; i < string.length() - 1 && quitarParentesis; ++i) {
				char c = string[i];
				if (c == LEFT_PARENTHESIS) {
					parentesis++;
				} else if (c == RIGHT_PARENTHESIS) {
					parentesis--;
				}
				if (parentesis < 1) {
					quitarParentesis = false;
				}
			}
			if (quitarParentesis) {
				string = string.substr(1, string.length() - 2);
				continuar = true;
			}
		}
	}
}


int Operacion::indiceMenorPrecedencia(string string) {
	int index = -1;
	int parentesis = 0;
	for (int k = 0; k < NUM_OPERADORES && index == -1; k++) {
		for (unsigned int i = 0; i < string.length() && index == -1; ++i) {
			char c = string[i];
			if (c == LEFT_PARENTHESIS) {
				parentesis++;
			} else if (c == RIGHT_PARENTHESIS) {
				parentesis--;
			} else if (parentesis == 0 && c == OPERADORES[k]) {
				index = i;
			}
		}
	}
	return index;
}

Elemento * Operacion::procesarStringHijo(string string) {
	Elemento * resultado;
	eliminarParentesisInnecesarios(string);
	if (indiceMenorPrecedencia(string) == -1) {
		resultado = new Operando(stod(string));
	} else {
		resultado = new Operacion(string);
	}
	return resultado;
}

string Operacion::getValor() {
	return operacion;
}

void Operacion::imprimir(ostream & out) {
	out << operacion;
}

