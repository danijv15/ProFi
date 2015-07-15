// ProFi.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "Elemento.h"
#include "Operacion.h"
#include "DoublyLinkedList.h"
#include "Arbol.h"
#include "Operando.h"


int _tmain(int argc, _TCHAR* argv[])
{
	ifstream archivoOperaciones;
	archivoOperaciones.open("operaciones.txt");
	
	DoublyLinkedList<Elemento*> operaciones;
	DoublyLinkedList<Elemento*> resultados;
	string lineaActual;

	if (archivoOperaciones.is_open()){
		while (getline(archivoOperaciones, lineaActual)) {
			operaciones.insertarFinal(new Operacion(lineaActual));
		}
		archivoOperaciones.close();
	}

	IteradorLista<Operacion *> iterador = operaciones.begin();
	while (iterador != operaciones.end()) {
		Operacion * operacion = *(iterador++);
		resultados += operacion->getValor() + "= ";
		ArbolBinario<Operacion *> ar(operacion);
		ar.solucionar();
		resultados.insertarFinal(ar.getRaiz()->getActual());
		stringstream str;
		Operando * a = dynamic_cast<Operando *>(ar.getRaiz()->getActual());
		str << ar->getValor();
		resultados += str.str() + "\n";
		cout << *operacion << " = " << str.str() << endl;

	}

	ofstream archivoResultados("resultados.txt");
	archivoResultados << r; //resultados
	archivoResultados.close();
	
	system("pause");
	return 0;
}

