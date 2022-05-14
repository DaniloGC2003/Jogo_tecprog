#include "../headers/ListaEntidades.h"

ListaEntidades::ListaEntidades() : Entidades()
{

}

ListaEntidades::~ListaEntidades()
{
}

void ListaEntidades::pushEntidade(Entidade* Ent)
{
	Entidades.push(Ent);
}

void ListaEntidades::deleteEntidade(Entidade* ent)
{
	Entidades.pop(ent);
}

Entidade* ListaEntidades::getEntidade(int pos)
{
	return Entidades.getpInfo(pos);
}

int ListaEntidades::getTamanho()
{
	return Entidades.getlen();
}
