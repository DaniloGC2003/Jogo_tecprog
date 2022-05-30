#include "../headers/Inimigo.h"
namespace Entities
{
	Inimigo::Inimigo(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* pathImagem, Jogador* pJ, Gerenciadores::Gerenciador_colisoes* pGC)
		: Personagem(pos, pGraf, pathImagem), pJogador(pJ), pColisoes(pGC)
	{
	}
	Inimigo::Inimigo() : Personagem(), pJogador(nullptr), pColisoes(nullptr)
	{
	}
	Inimigo::~Inimigo()
	{
		pJogador = nullptr;
		pColisoes = nullptr;
	}

	void Inimigo::executar()
	{
		coordenadas::vetorfloat vetVel(0.f, (float)GRAVITY);
		float distancia = pJogador->getPos().getX() - getPos().getX();
		if (fabs(distancia) < 200.f)//se a distancia entre inimigo e jogador for menmor que 200
		{
			if (distancia > 0.f)
				vetVel += coordenadas::vetorfloat((float)SPEED_X, 0.f);
			else
				vetVel -= coordenadas::vetorfloat((float)SPEED_X, 0.f);
		}
		/*if (pColisoes->verifica_colisao(pJogador, this))
			pJogador->setVida(pJogador->getVida() - 5);*/
		Move(vetVel);
		getAnimacao()->render();
	}
}
