#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Gerenciador_grafico.h"
#include "ListaEntidades.h"
#include "Entidade.h"
#include "Gerenciador_colisoes.h"
#include "Personagem.h"
#include "Jogador.h"
#include "Ente.h"
#include "Obstaculo.h"
#include "Lago.h"
#include "Inimigo.h"
#include "Lesma.h"
class Jogo
{
private:
	sf::Clock relogio;
	Gerenciadores::Gerenciador_grafico grafico;
	Gerenciadores::Gerenciador_colisoes colisoes;
	sf::View camera;
	Lists::ListaEntidades personagens;
	Lists::ListaEntidades estaticas;

	Entities::Jogador jogador;
	Entities::Lago lago;
	Entities::Ente background;

	sf::Text mostraVida;
	sf::Font* fonte;
public:
	Jogo();
	~Jogo();
	Lists::ListaEntidades* getPersonagens();
	Lists::ListaEntidades* getEstaticas();
	void Executar();
};