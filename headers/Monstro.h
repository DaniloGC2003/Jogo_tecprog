#pragma once
#include "Inimigo.h"
#define DANO_MONSTRO 20
#define SPEED_MONSTRO 0.2
namespace Entities
{
	class Monstro :
		public Inimigo
	{
	private:
	public:
		Monstro(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* pathImagem, Jogador* pJ, Gerenciadores::Gerenciador_colisoes* pGC);
		Monstro();
		~Monstro();

		void executar();
	};
}
