#pragma once
#include "../headers/Lista.h"
#include "../headers/Entidade.h"
class ListaEntidades
{
private:
	Lista<Entidade> Entidades;
public:
	ListaEntidades();
	~ListaEntidades();
	
	void pushEntidade(Entidade* Ent);
	void deleteEntidade(Entidade* ent);
	Entidade* getEntidade(int pos);
	int getTamanho();
};

