#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Gerenciador_grafico.h"
#include "ListaEntidades.h"
#include "Entidade.h"
#include "Gerenciador_colisoes.h"
class Jogo
{
private:
	sf::Clock relogio;
	Gerenciador_grafico graficos;
	Gerenciador_colisoes colisoes;
	sf::RenderWindow* window;
	ListaEntidades personagens;
	ListaEntidades estaticas;

	Entities::Entidade jogador;
	Entities::Entidade plataforma;
public:
	Jogo();
	~Jogo();
	ListaEntidades* getPersonagens();
	ListaEntidades* getEstaticas();
	void Executar();
};