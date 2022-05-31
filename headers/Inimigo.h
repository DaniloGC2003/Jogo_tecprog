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
		Gerenciadores::Gerenciador_colisoes* pColisoes;
	public:
		Inimigo(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* pathImagem, Jogador* pJ, Gerenciadores::Gerenciador_colisoes* pGC);
		Inimigo();
		virtual ~Inimigo();

		virtual void executar();
	};

}

