#pragma once
#include "Entidade.h"
#include <SFML/Graphics.hpp>
#define GRAVITY 0.2
namespace Entities
{
	class Personagem : public Entidade
	{
	protected:
		int vida; //health points
		//coordenadas::vetorfloat velocidade;
	public:
		Personagem(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, Gerenciadores::Gerenciador_colisoes* pGC, const char* pathImagem);
		Personagem();
		virtual ~Personagem();

		//coordenadas::vetorfloat getVelocidade() const { return velocidade; }
		//void setVelocidade(coordenadas::vetorfloat vel) { velocidade = vel; }

		int getVida() { return vida; }
		void setVida(int hp) { vida = hp; }

		virtual void executar();
	};
}

