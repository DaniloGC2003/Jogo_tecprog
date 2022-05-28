#pragma once
#include "Personagem.h"
#define SPEED_X 0.2
#define PULO 80
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
		Jogador(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* pathImagem, coordenadas::vetorfloat velocidade);
		Jogador();
		~Jogador();

		void setPodePular(bool valor) { podePular = valor; }
		bool getPodePular() { return podePular; }
		void executar();
	};
}


