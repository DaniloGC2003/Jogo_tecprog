#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include "ListaEntidades.h"
#include "Vetor.h"
#include "Entidade.h"
class Gerenciador_colisoes
{
private:
public:
	Gerenciador_colisoes();
	~Gerenciador_colisoes();

	coordenadas::vetorfloat getMeioTamanho(Entities::Entidade* ent);
	coordenadas::vetorfloat getDistancia(Entities::Entidade* body1, Entities::Entidade* body2);
	coordenadas::vetorfloat getIntersecao(Entities::Entidade* body1, Entities::Entidade* body2);

	bool verifica_colisao(Entities::Entidade* ent1, Entities::Entidade* ent2);
	void colidir(ListaEntidades* characters, ListaEntidades* statics);
};

