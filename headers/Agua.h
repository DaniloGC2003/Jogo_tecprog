#pragma once
#include "Obstaculo.h"
namespace Entities {

	class Agua : public Obstaculo
	{
	private:
	public:
		Agua(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* caminho);
		Agua();
		~Agua();
	};
}


