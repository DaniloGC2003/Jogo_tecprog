#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Gerenciador_grafico.h"
#include "ListaEntidades.h"
#include "Entidade.h"
#include "Gerenciador_colisoes.h"
#include "Personagem.h"
#include "Jogador.h"
#include "Ente.h"
class Jogo
{
private:
	sf::Clock relogio;
	Gerenciadores::Gerenciador_grafico graficos;
	Gerenciadores::Gerenciador_colisoes colisoes;
	sf::RenderWindow* window;
	Lists::ListaEntidades personagens;
	Lists::ListaEntidades estaticas;

	Entities::Jogador jogador;
	Entities::Entidade plataforma;
	Entities::Ente background;
public:
	Jogo();
	~Jogo();
	Lists::ListaEntidades* getPersonagens();
	Lists::ListaEntidades* getEstaticas();
	void Executar();
};