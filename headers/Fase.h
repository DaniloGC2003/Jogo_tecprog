#pragma once
#include "Ente.h"
#include "Gerenciador_colisoes.h"
#include "ListaEntidades.h"
#include "Jogador.h"
#include "Plataforma.h"
#include "Texto.h"
#include "Tartaruga.h"
#include "Lesma.h"
#include "Monstro.h"
class Fase :
	public Entities::Ente
{
protected:
	Gerenciadores::Gerenciador_colisoes Colisoes;

	sf::View camera;
	Lists::ListaEntidades personagens;
	Lists::ListaEntidades estaticas;
	Lists::ListaEntidades projeteis;

	Entities::Jogador jogador;
	Entities::Plataforma plataforma;

	//Texto HP;
public:
	Fase(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* caminho);
	Fase();
	~Fase();

	virtual void executar() = 0;
};


