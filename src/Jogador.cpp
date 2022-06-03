#include "../headers/Jogador.h"

namespace Entities
{
	Entities::Jogador::Jogador(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, Gerenciadores::Gerenciador_colisoes* pGC, const char* pathImagem)
		: Personagem(pos, pGraf, pGC, pathImagem), podePular(false), pulando(false), olhandoParaDireita(false),
         vetVel(0.f,(float)GRAVITY), maxAltura(0.f), cooldownTiro(150.f)
	{
	}

	Entities::Jogador::Jogador() : Personagem(), podePular(false), pulando(false), olhandoParaDireita(false),
         vetVel(0.f, (float)GRAVITY), maxAltura(0.f), cooldownTiro(150.f)
	{
	}

	Entities::Jogador::~Jogador()
	{
	}

    void Jogador::executar()
	{
        vetVel = coordenadas::vetorfloat(0.f, vetVel.getY());

        //movimentacao a partir de comandos do teclado
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            olhandoParaDireita = true;
            vetVel = coordenadas::vetorfloat((float)SPEED_X, vetVel.getY());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            olhandoParaDireita = false;
            vetVel = coordenadas::vetorfloat((float) - SPEED_X, vetVel.getY());

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && podePular)
        {
            maxAltura = (float)PULO;
            vetVel += coordenadas::vetorfloat(0.f, -0.4f);//velocidade vertical inverte sentido
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


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && cooldownTiro >= 150.f)//atira projetil
        {
            cooldownTiro = 0.f;
            Entidade* pEnt;//projetil alocado dinamicamente
            if (olhandoParaDireita)
            {
                pEnt = static_cast<Entidade*>(new Projetil(this, pColisoes, coordenadas::vetorfloat(getPos().getX() + 50, getPos().getY()), getAnimacao()->getpGraf(), true));
            }
            else
            {
                pEnt = pEnt = static_cast<Entidade*>(new Projetil(this, pColisoes, coordenadas::vetorfloat(getPos().getX() - 50, getPos().getY()), getAnimacao()->getpGraf(), false));
            }
    
            pColisoes->getpProjeteis()->pushEntidade(pEnt);
        }
        if (cooldownTiro < 150.f)
            cooldownTiro += 0.1f;
        else
            cooldownTiro = 150.f;

        if (vida < 0)
            vida = 0;

        Move(vetVel);
        getAnimacao()->render();
	}
}
