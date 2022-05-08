#pragma once
#include <SFML/Graphics.hpp>

class Gerenciador_grafico
{
private:
	sf::RenderWindow* janela;
public:
	Gerenciador_grafico();
	~Gerenciador_grafico();
	void setWindow(sf::RenderWindow* pW);
	void desenhar(sf::RectangleShape* hitbox);
};

