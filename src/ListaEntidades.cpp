#include "../headers/ListaEntidades.h"

ListaEntidades::ListaEntidades() : Entidades()
{

}

ListaEntidades::~ListaEntidades()
{
}

void ListaEntidades::pushEntidade(Entities::Entidade* Ent)
{
	Entidades.push(Ent);
}

void ListaEntidades::deleteEntidade(Entities::Entidade* ent)
{
	Entidades.pop(ent);
}

Entities::Entidade* ListaEntidades::getEntidade(int pos)
{
	return Entidades.getpInfo(pos);
}

int ListaEntidades::getTamanho()
{
	return Entidades.getlen();
}
