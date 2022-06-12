#pragma once
#include "Obstaculo.h"
#include "Jogador.h"
#define COOLDOWN_AGUA 100
#define DANO_AGUA 1
namespace Entities {
	namespace Obstaculos
	{
		class Agua : public Obstaculo
		{
		private:
			Personagens::Jogador* pJogador;
			float cooldown;
		public:
			Agua(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, Gerenciadores::Gerenciador_colisoes* pGC, const char* caminho, Personagens::Jogador* pJ);
			Agua();
			~Agua();

			void executar();
		};
	}

}


