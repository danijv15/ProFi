#pragma once

#include "OperadorUnario.h"
#include "Operando.h"

class OperadorSeno :
	public OperadorUnario {

protected:
	virtual void imprimir(ostream&);

public:
	OperadorSeno();
	~OperadorSeno();

	virtual Elemento * operar(DoublyLinkedList<Elemento>&);

};
