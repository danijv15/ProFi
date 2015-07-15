#pragma once

#include "OperadorUnario.h"
#include "Operando.h"

class OperadorCoseno :
	public OperadorUnario {

protected:
	virtual void imprimir(ostream&);

public:
	OperadorCoseno();
	~OperadorCoseno();

	virtual Elemento * operar(DoublyLinkedList<Elemento>&);

};
