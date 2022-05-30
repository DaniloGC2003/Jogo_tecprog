#pragma once
#include "Obstaculo.h"
namespace Entities {

	class Plataforma : public Obstaculo
	{
	private:
	public:
		Plataforma(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* caminho);
		Plataforma();
		Plataforma();
	};
}
