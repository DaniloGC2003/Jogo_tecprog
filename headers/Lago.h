#pragma once
#include "Obstaculo.h"
namespace Entities {

	class Lago : public Obstaculo
	{
	private:
	public:
		Lago(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, Gerenciadores::Gerenciador_colisoes* pGC, const char* caminho);
		Lago();
		~Lago();
	};
}


