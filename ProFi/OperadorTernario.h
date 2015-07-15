#pragma once

#include "stdafx.h"
#include "operador.h"
#include "Operando.h"

class OperadorTernario :public Operador {

protected:
	virtual void imprimir(ostream&) = 0;

public:

	virtual ~OperadorTernario() {
	
	};
	
	virtual Elemento * operar(DoublyLinkedList<Elemento>&) = 0;

};