#include "../headers/Gerenciador_grafico.h"
Gerenciador_grafico::Gerenciador_grafico() : janela(sf::VideoMode(450, 450), "SFML works!")
{
	
}

Gerenciador_grafico::~Gerenciador_grafico() 
{
}

Gerenciador_grafico* Gerenciador_grafico::getInstance()
{
	return this;
}

sf::RenderWindow* Gerenciador_grafico::getJanela()
{
	return &janela;
}

void Gerenciador_grafico::desenhar(sf::RectangleShape* hitbox)
{
	janela.draw(*hitbox);
}
