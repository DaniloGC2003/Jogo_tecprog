#pragma once
#include "Obstaculo.h"
#define GRAVITY 0.2
namespace Entities {

	class Barril : public Obstaculo
	{
	private:
	public:
		Barril(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* caminho);
		Barril();
		~Barril();
	};
}