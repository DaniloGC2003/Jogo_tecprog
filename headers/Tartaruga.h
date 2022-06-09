#pragma once
#include "Inimigo.h"
#include "Projetil.h"
#define VEL_TARTARUGA 0.05
#define COOLDOWN_TIRO 180
namespace Entities
{
	class Tartaruga :
		public Inimigo
	{
	private:
		bool olhandoParaDireita;
		float cooldownTiro;
	public:
		Tartaruga(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* pathImagem, Jogador* pJ, Gerenciadores::Gerenciador_colisoes* pGC, int pontosVida = 500);
		Tartaruga();
		~Tartaruga();

		void executar();
	};
}


