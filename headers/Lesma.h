#pragma once
#include "Inimigo.h"
#define DANO_LESMA 30
#define SPEED_LESMA 0.1

namespace Entities
{
	class Lesma : public Inimigo
	{
	private:

	public:
		Lesma(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* pathImagem, Jogador* pJ, Gerenciadores::Gerenciador_colisoes* pGC);
		Lesma();
		~Lesma();
		void executar();
	};
}


