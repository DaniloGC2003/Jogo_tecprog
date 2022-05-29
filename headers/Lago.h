#pragma once
#include "Obstaculo.h"
namespace Entities {

	class Lago : public Obstaculo
	{
	private:
	public:
		Lago(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* caminho);
		Lago();
		~Lago();
	};
}


