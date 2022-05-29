#pragma once
#include "Personagem.h"
#define SPEED_X 0.25
#define PULO 150
namespace Entities
{
	class Jogador :
		public Personagem
	{
	private:
		bool podePular;
		bool pulando;
		coordenadas::vetorfloat vetVel;//vetor velocidade. jogador vai se mover no sentido desse vetor
		float maxAltura;
	public:
		Jogador(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* pathImagem);
		Jogador();
		~Jogador();

		void setPodePular(bool valor) { podePular = valor; }
		bool getPodePular() { return podePular; }
		void executar();
	};
}


