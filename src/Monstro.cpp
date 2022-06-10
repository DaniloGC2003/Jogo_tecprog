#include "../headers/Monstro.h"
namespace Entities
{
	Monstro::Monstro(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* pathImagem, Jogador* pJ, Gerenciadores::Gerenciador_colisoes* pGC)
		: Inimigo(pos, pGraf, pathImagem, pJ, pGC)
	{
	}

	Monstro::Monstro() : Inimigo()
	{
	}

	Monstro::~Monstro()
	{
	}

	void Monstro::executar()
	{
		bool flagEliminado = false;
		coordenadas::vetorfloat vetVel(0.f, (float)GRAVITY);
		float distancia = pJogador->getPos().getX() - getPos().getX();
		if (fabs(distancia) < 300.f)//se a distancia entre inimigo e jogador for menmor que 300
		{
			if (distancia > 0.f)
				vetVel += coordenadas::vetorfloat((float)SPEED_MONSTRO, 0.f);
			else
				vetVel -= coordenadas::vetorfloat((float)SPEED_MONSTRO, 0.f);
		}
		if (pColisoes->verifica_colisao(pJogador, this))
		{
			if (pJogador->getVida() > DANO_MONSTRO)
				pJogador->tomaDano(DANO_MONSTRO);
			else
				pJogador->setVida(0);
			flagEliminado = true;
		}
		if (vida == 0)
		{
			flagEliminado = true;
		}
		Move(vetVel);
		getAnimacao()->render();
		if (flagEliminado)//se flag tiver valor true, monstro sera deletado
		{
			pColisoes->getpPersonagens()->removeEntidade(static_cast<Entidade*>(this));
		}
	}

}