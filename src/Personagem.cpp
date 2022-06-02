#include "../headers/Personagem.h"
namespace Entities
{
	Personagem::Personagem(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, Gerenciadores::Gerenciador_colisoes* pGC, const char* pathImagem, int pontosVida) :
		Entidade(pos, pGraf, pGC, pathImagem), vida(pontosVida)
	{
	}
	Personagem::Personagem() : Entidade(), vida(0)
	{
	}
	Personagem::~Personagem()
	{
	}
	void Personagem::tomaDano(int hp)
	{
		vida -= hp;
		if (vida < 0)
			vida = 0;
	}
	void Personagem::executar()
	{
        MoveCorpo(coordenadas::vetorfloat(0.f, 0.4f));//gravidade
        getAnimacao()->render();
	}
}
