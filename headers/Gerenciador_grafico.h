#pragma once
#include <SFML/Graphics.hpp>

class Gerenciador_grafico
{
private:
	sf::RenderWindow janela;
public:
	Gerenciador_grafico();
	~Gerenciador_grafico();
	Gerenciador_grafico* getInstance();
	sf::RenderWindow* getJanela();
	void desenhar(sf::RectangleShape* hitbox);
	//void mostrar()
};

