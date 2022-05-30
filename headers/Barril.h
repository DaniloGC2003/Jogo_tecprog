#pragma once
#include "Obstaculo.h"
namespace Entities {

	class Barril : public Obstaculo
	{
	private:
	public:
		Barril(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* caminho);
		Barril();
		Barril();
	};
}