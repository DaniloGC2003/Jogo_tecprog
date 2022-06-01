#include "../headers/Personagem.h"
namespace Entities
{
	Personagem::Personagem(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, Gerenciadores::Gerenciador_colisoes* pGC, const char* pathImagem) :
		Entidade(pos, pGraf, pGC, pathImagem), vida(100)
	{
	}
	Personagem::Personagem() : Entidade(), vida(0)
	{
	}
	Personagem::~Personagem()
	{
	}
	void Personagem::executar()
	{
        MoveCorpo(coordenadas::vetorfloat(0.f, 0.4f));//gravidade
        getAnimacao()->render();
	}
}
