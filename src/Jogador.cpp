#include "../headers/Jogador.h"

namespace Entities
{
	Entities::Jogador::Jogador(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* pathImagem, coordenadas::vetorfloat velocidade)
		: Personagem(pos, pGraf, pathImagem, velocidade)
	{
	}

	Entities::Jogador::Jogador() : Personagem()
	{
	}

	Entities::Jogador::~Jogador()
	{
	}

	void Jogador::executar()
	{
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            Move(coordenadas::vetorfloat(velocidade.getX(), 0.f));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            Move(coordenadas::vetorfloat(-velocidade.getX(), 0.f));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            Move(coordenadas::vetorfloat(0.f, velocidade.getY()));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            Move(coordenadas::vetorfloat(0.f, -velocidade.getY()));
        }
        MoveCorpo(coordenadas::vetorfloat(0.f, 0.4f));//gravidade
        getAnimacao()->render();
	}
}
