#pragma once
#include "Obstaculo.h"
namespace Entities {

	class Agua : public Obstaculo
	{
	private:
	public:
		Agua(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, Gerenciadores::Gerenciador_colisoes* pGC, const char* caminho);
		Agua();
		~Agua();
	};
}


