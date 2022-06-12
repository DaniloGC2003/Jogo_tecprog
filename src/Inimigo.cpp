#include "../headers/Inimigo.h"
namespace Entities
{
	Inimigo::Inimigo(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* pathImagem, Jogador* pJ, Gerenciadores::Gerenciador_colisoes* pGC, int pontosVida)
		: Personagem(pos, pGraf, pGC, pathImagem, pontosVida), pJogador(pJ)
	{
	}
	Inimigo::Inimigo() : Personagem(), pJogador(nullptr)
	{
	}
	Inimigo::~Inimigo()
	{
		pJogador = nullptr;
	}
}
