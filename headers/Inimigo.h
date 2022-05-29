#pragma once
#include "Personagem.h"
#include "Jogador.h"
#include "Gerenciador_colisoes.h"
#define SPEED_X 0.15
namespace Entities
{
	class Inimigo :
		public Personagem
	{
	private:
		Jogador* pJogador;
		Gerenciadores::Gerenciador_colisoes* pColisoes;
	public:
		Inimigo(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* pathImagem, Jogador* pJ, Gerenciadores::Gerenciador_colisoes* pGC);
		Inimigo();
		~Inimigo();

		virtual void executar();
	};

}

