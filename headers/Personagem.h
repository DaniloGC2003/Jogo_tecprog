#pragma once
#include "Entidade.h"
#include <SFML/Graphics.hpp>
namespace Entities
{
	class Personagem : public Entidade
	{
	protected:
		int vida; //health points
		coordenadas::vetorfloat velocidade;
	public:
		Personagem(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* pathImagem, coordenadas::vetorfloat velocidade);
		Personagem();
		~Personagem();

		coordenadas::vetorfloat getVelocidade() const { return velocidade; }
		void setVelocidade(coordenadas::vetorfloat vel) { velocidade = vel; }

		virtual void executar();
	};
}

