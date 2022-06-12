#pragma once
#include "Obstaculo.h"
namespace Entities {
	namespace Obstaculos
	{
		class Barril : public Obstaculo
		{
		private:
		public:
			Barril(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, Gerenciadores::Gerenciador_colisoes* pGC, const char* caminho);
			Barril();
			~Barril();
		};
	}

}