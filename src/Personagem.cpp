#include "../headers/Personagem.h"
namespace Entities
{
	Personagem::Personagem(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* pathImagem, coordenadas::vetorfloat velocidade) :
		Entidade(pos, pGraf, pathImagem), velocidade(velocidade), vida(100)
	{
	}
	Personagem::Personagem() : Entidade(), vida(0), velocidade(0.f, 0.f)
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
