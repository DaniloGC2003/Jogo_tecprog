#include "../headers/Tartaruga.h"
namespace Entities
{
	Tartaruga::Tartaruga(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* pathImagem, Jogador* pJ, Gerenciadores::Gerenciador_colisoes* pGC, int pontosVida)
		: Inimigo (pos, pGraf, pathImagem, pJ, pGC, pontosVida), olhandoParaDireita(true), cooldownTiro((float)COOLDOWN_TIRO)
	{
	}
	Tartaruga::Tartaruga() : Inimigo(), olhandoParaDireita(true), cooldownTiro((float)COOLDOWN_TIRO)
	{
	}
	Tartaruga::~Tartaruga()
	{
	}
	void Tartaruga::executar()
	{
		bool flagEliminado = false;
		coordenadas::vetorfloat vetVel(0.f, (float)GRAVITY);
		float distancia = pJogador->getPos().getX() - this->getPos().getX();
		if (fabs(distancia) < 200.f)//se a distancia entre inimigo e jogador for menor que 200
		{
			if (distancia > 0.f)
			{
				olhandoParaDireita = true;
				vetVel += coordenadas::vetorfloat((float)VEL_TARTARUGA, 0.f);
			}
			else
			{
				olhandoParaDireita = false;
				vetVel -= coordenadas::vetorfloat((float)VEL_TARTARUGA, 0.f);
			}
			if (cooldownTiro >= (float)COOLDOWN_TIRO)
			{
				cooldownTiro = 0.f;
				Entidade* pEnt;
				if (olhandoParaDireita)
				{
					pEnt = static_cast<Entidade*>(new Projetil(pJogador, pColisoes, coordenadas::vetorfloat(getPos().getX() + 50, getPos().getY()), getAnimacao()->getpGraf(), true));
				}
				else
				{
					pEnt = static_cast<Entidade*>(new Projetil(pJogador, pColisoes, coordenadas::vetorfloat(getPos().getX() - 50, getPos().getY()), getAnimacao()->getpGraf(), false));
				}
				pColisoes->getpPersonagens()->pushEntidade(pEnt);
			}
		}


		if (cooldownTiro < 150.f)
			cooldownTiro += 0.1f;
		else
			cooldownTiro = 150.f;


		if (pColisoes->verifica_colisao(pJogador, static_cast<Entidade*>(this)))
		{
			pJogador->setVida(0);
			flagEliminado = true;
		}
		if (vida == 0)
		{
			flagEliminado = true;
		}


		Move(vetVel);

		getAnimacao()->render();
		if (flagEliminado)
		{
			pColisoes->getpPersonagens()->deleteEntidade(static_cast<Entidade*>(this));
		}

	}
}
