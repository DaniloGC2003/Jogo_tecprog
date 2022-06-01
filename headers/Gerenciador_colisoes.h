#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include "ListaEntidades.h"
#include "Vetor.h"
#include "Entidade.h"
#include "Jogador.h"
namespace Gerenciadores
{
	class Gerenciador_colisoes
	{
	private:
		Lists::ListaEntidades* pPersonagens;
		Lists::ListaEntidades* pEstaticos;
	public:
		Gerenciador_colisoes(Lists::ListaEntidades* pP, Lists::ListaEntidades* pE);
		Gerenciador_colisoes();
		~Gerenciador_colisoes();

		Gerenciador_colisoes* getInstance() { return this; }

		void setpPersonagens(Lists::ListaEntidades* pP);
		void setpEstaticos(Lists::ListaEntidades* pE);
		Lists::ListaEntidades* getpPersonagens() { return pPersonagens; }
		Lists::ListaEntidades* getpEstaticos() { return pEstaticos; }

		coordenadas::vetorfloat getMeioTamanho(Entities::Entidade* ent);
		coordenadas::vetorfloat getDistancia(Entities::Entidade* body1, Entities::Entidade* body2);
		coordenadas::vetorfloat getIntersecao(Entities::Entidade* body1, Entities::Entidade* body2);

		bool verifica_colisao(Entities::Entidade* ent1, Entities::Entidade* ent2);
		bool verifica_colisao_estaticos(Entities::Entidade* pEnt);//verifica colisao de uma entidade com qualquer obstaculo
		bool verifica_projetil_personagens(Entities::Entidade* pEnt);
		void colidir();//(Lists::ListaEntidades* characters, Lists::ListaEntidades* statics);
	};

}
