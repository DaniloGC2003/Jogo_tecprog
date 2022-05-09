#include "../headers/Gerenciador_grafico.h"
Gerenciador_grafico::Gerenciador_grafico() : janela(nullptr)
{
	
}

Gerenciador_grafico::~Gerenciador_grafico()
{
	janela = nullptr;
}

void Gerenciador_grafico::setWindow(sf::RenderWindow* pW)
{
	janela = pW;
}

void Gerenciador_grafico::desenhar(sf::RectangleShape* hitbox)
{
	janela->draw(*hitbox);
}
