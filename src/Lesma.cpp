#include "../headers/Lesma.h"
namespace Entities
{
	Lesma::Lesma(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* pathImagem, Jogador* pJ, Gerenciadores::Gerenciador_colisoes* pGC)
		: Inimigo(pos, pGraf, pathImagem, pJ, pGC)
	{
	}

	Lesma::Lesma() : Inimigo()
	{
	}

	Lesma::~Lesma()
	{
	}

	void Lesma::executar()
	{
		bool flagEliminado = false;
		coordenadas::vetorfloat vetVel(0.f, (float)GRAVITY);
		float distancia = pJogador->getPos().getX() - this->getPos().getX();
		if (fabs(distancia) < 200.f)//se a distancia entre inimigo e jogador for menor que 200
		{
			if (distancia > 0.f)
				vetVel += coordenadas::vetorfloat((float)SPEED_LESMA, 0.f);
			else
				vetVel -= coordenadas::vetorfloat((float)SPEED_LESMA, 0.f);
		}
		if (pColisoes->verifica_colisao(pJogador, static_cast<Entidade*>(this)))
		{//se ha colisao, jogador sofre dano
			if (pJogador->getVida() > DANO_LESMA)
			{
				pJogador->tomaDano(DANO_LESMA);
			}
			else
			{
				pJogador->setVida(0);

			}
			flagEliminado = true;
		}
		if (vida == 0)
		{
			flagEliminado = true;
		}
		Move(vetVel);

		getAnimacao()->render();
		if (flagEliminado)//se flag tiver valor true, lesma sera deletada
		{
			pColisoes->getpPersonagens()->removeEntidade(static_cast<Entidade*>(this));
		}

	}

}
