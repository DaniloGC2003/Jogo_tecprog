#pragma once
#include "Entidade.h"
#include "Gerenciador_colisoes.h"
#include "Jogador.h"
#define VEL_PROJETIL 0.3

namespace Gerenciadores
{
	class Gerenciador_colisoes;
}

namespace Entities
{
	namespace Personagens
	{
		class Jogador;
	}


	class Projetil :
		public Entidade
	{
	private:
		int dano;
		Personagens::Jogador* pJogador;
		coordenadas::vetorfloat posicaoInicial;
		bool paraFrente;//se for verdadeiro, ira com velocidade positiva.
	public:
		Projetil(Personagens::Jogador* pJ, Gerenciadores::Gerenciador_colisoes* pGC, coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, bool frente, const char* pathImagem = "texturas_e_fontes/Bolt.png", int dano = 100);
		Projetil();
		~Projetil();
		int getDano() { return dano; }

		bool verificaColisao_personagens();
		void executar();
	};
}


