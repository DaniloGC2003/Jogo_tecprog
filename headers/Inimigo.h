#pragma once
#include "Personagem.h"
#include "Jogador.h"
#include "Gerenciador_colisoes.h"
namespace Entities
{
	class Inimigo :
		public Personagem
	{
	protected:
		Jogador* pJogador;
	public:
		Inimigo(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* pathImagem, Jogador* pJ, Gerenciadores::Gerenciador_colisoes* pGC, int pontosVida = 100);
		Inimigo();
		virtual ~Inimigo();

		virtual void executar();
	};

}

