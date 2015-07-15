#pragma once

#include "OperadorUnario.h"
#include "Operando.h"

class OperadorLogaritmo :
	public OperadorUnario {

protected:
	virtual void imprimir(ostream&);

public:
	OperadorLogaritmo();
	~OperadorLogaritmo();

	virtual Elemento * operar(DoublyLinkedList<Elemento>&);

};
