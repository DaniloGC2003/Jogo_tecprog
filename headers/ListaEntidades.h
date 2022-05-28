#pragma once
#include "Lista.h"
#include "Entidade.h"
namespace Lists
{
	class ListaEntidades
	{
	private:
		Lista<Entities::Entidade> Entidades;
	public:
		ListaEntidades();
		~ListaEntidades();

		void pushEntidade(Entities::Entidade* Ent);
		void deleteEntidade(Entities::Entidade* ent);
		Entities::Entidade* getEntidade(int pos);
		int getTamanho();
	};
}
