#pragma once
#include <SFML/Graphics.hpp>
#include "Gerenciador_grafico.h"
#include "ListaEntidades.h"
class Jogo
{
private:
	sf::Clock relogio;
	Gerenciador_grafico graficos;
	sf::RenderWindow* window;
	Entidade jogador;
	ListaEntidades entidades;
public:
	Jogo();
	~Jogo();
	void Executar();
};