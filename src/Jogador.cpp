#include "../headers/Jogador.h"

namespace Entities
{
	Entities::Jogador::Jogador(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* pathImagem)
		: Personagem(pos, pGraf, pathImagem), podePular(false), pulando(false), 
         vetVel(0.f,(float)GRAVITY), maxAltura(0.f)
	{
	}

	Entities::Jogador::Jogador() : Personagem(), podePular(false), pulando(false), 
         vetVel(0.f, (float)GRAVITY), maxAltura(0.f)
	{
	}

	Entities::Jogador::~Jogador()
	{
	}

	void Jogador::executar()
	{
        vetVel = coordenadas::vetorfloat(0.f, vetVel.getY());
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            vetVel = coordenadas::vetorfloat((float)SPEED_X, vetVel.getY());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            vetVel = coordenadas::vetorfloat((float) - SPEED_X, vetVel.getY());

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && podePular)
        {
            maxAltura = (float)PULO;
            vetVel += coordenadas::vetorfloat(0.f, -0.4f);
            maxAltura -= 0.2f;
            podePular = false;
            pulando = true;
        }
        if (pulando)
        {
            maxAltura -= 0.2f;
            if (maxAltura <= 0)
            {
                pulando = false;
                vetVel = coordenadas::vetorfloat(vetVel.getX(), (float)GRAVITY);//gravidade
            }
        }
        //std::cout << (int)podePular << std::endl;
        Move(vetVel);
        getAnimacao()->render();
	}
}
