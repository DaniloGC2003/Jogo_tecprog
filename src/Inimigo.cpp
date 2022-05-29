#include "../headers/Inimigo.h"
namespace Entities
{
	Inimigo::Inimigo(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* pathImagem, coordenadas::vetorfloat velocidade, Jogador* pJ, Gerenciadores::Gerenciador_colisoes* pGC)
		: Personagem(pos, pGraf, pathImagem, velocidade), pJogador(pJ), pColisoes(pGC)
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
		float distancia = pJogador->getPos().getX() - getPos().getX();
		if (fabs(distancia) < 200.f)//se a distancia entre inimigo e jogador for menmor que 50
		{
			if (distancia > 0.f)
				Move(coordenadas::vetorfloat(0.15f, 0.f));
			else
				Move(coordenadas::vetorfloat(-0.15f, 0.f));
		}
		getAnimacao()->render();
	}
}
