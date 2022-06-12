#pragma once
#include "Personagem.h"
#include "Projetil.h"
#define SPEED_X 0.25
#define PULO 150
namespace Entities
{
	namespace Personagens
	{
		class Jogador :
			public Personagem
		{
		private:

			//valores utilizados para mecanica de pulo do jogador
			bool podePular;
			bool pulando;

			bool olhandoParaDireita;//valor utilizado para determinar sentido do projetil atirado
			coordenadas::vetorfloat vetVel;//vetor velocidade. jogador vai se mover no sentido desse vetor

			float maxAltura;

			float cooldownTiro;
		public:
			Jogador(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, Gerenciadores::Gerenciador_colisoes* pGC, const char* pathImagem);
			Jogador();
			~Jogador();

			void setPodePular(bool valor) { podePular = valor; }
			bool getPodePular() { return podePular; }

			void executar();
		};
	}

}


