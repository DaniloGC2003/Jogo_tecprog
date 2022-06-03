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
	public:
		Personagem(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, Gerenciadores::Gerenciador_colisoes* pGC, const char* pathImagem, int pontosVida = 100);
		Personagem();
		virtual ~Personagem();

		int getVida() { return vida; }
		void setVida(int hp) { vida = hp; }
		void tomaDano(int hp);

		virtual void executar() = 0;
	};
}

