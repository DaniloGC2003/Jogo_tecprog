#pragma once
#include "Entidade.h"

namespace Entities {

	class Obstaculo : public Entidade
	{
	protected:
	public:
		Obstaculo(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* caminho);
		Obstaculo();
		~Obstaculo();
	};
}


