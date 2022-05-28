#pragma once
#include "Personagem.h"

namespace Entities
{
	class Jogador :
		public Personagem
	{
	private:
	public:
		Jogador(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* pathImagem, coordenadas::vetorfloat velocidade);
		Jogador();
		~Jogador();

		void executar();
	};
}


