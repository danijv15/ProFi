#pragma once

#include "OperadorUnario.h"
#include "Operando.h"

class OperadorTangente :
	public OperadorUnario {

protected:
	virtual void imprimir(ostream&);

public:
	OperadorTangente();
	~OperadorTangente();

	virtual Elemento * operar(DoublyLinkedList<Elemento>&);

};
