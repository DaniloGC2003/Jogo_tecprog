#pragma once
#include "Obstaculo.h"
#include "Jogador.h"
#define COOLDOWN_AGUA 100
#define DANO_AGUA 1
namespace Entities {

	class Agua : public Obstaculo
	{
	private:
		Jogador* pJogador;
		float cooldown;
	public:
		Agua(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, Gerenciadores::Gerenciador_colisoes* pGC, const char* caminho, Jogador* pJ);
		Agua();
		~Agua();

		void executar();
	};
}


