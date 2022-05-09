#pragma once
#include <SFML/Graphics.hpp>
#include "Gerenciador_grafico.h"
#include "Entidade.h"
class Jogo
{
private:
	sf::RenderWindow window;
	sf::Clock relogio;
	Gerenciador_grafico graficos;
	Entidade jogador;
public:
	Jogo();
	~Jogo();
	void Executar();
};