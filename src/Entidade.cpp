#include "../headers/Entidade.h"

Entidade::Entidade() : graficos(nullptr)
{
}

Entidade::Entidade(sf::Vector2f tamanho) : graficos(nullptr)
{
}

Entidade::~Entidade()
{
	graficos = nullptr;
}

sf::RectangleShape* Entidade::getHitbox()
{
	return &hitbox;
}

void Entidade::setTamanho(sf::Vector2f tam)
{
	hitbox.setSize(tam);
}
