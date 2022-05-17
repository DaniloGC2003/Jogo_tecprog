#pragma once
#include <SFML/Graphics.hpp>
#include "Gerenciador_grafico.h"
#include "ListaEntidades.h"
#include "Entidade.h"
class Jogo
{
private:
	sf::Clock relogio;
	Gerenciador_grafico graficos;
	sf::RenderWindow* window;
	ListaEntidades entidades;
	Entities::Entidade jogador;
public:
	Jogo();
	~Jogo();
	void Executar();
};