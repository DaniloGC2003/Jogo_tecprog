#pragma once
#include "Obstaculo.h"
namespace Entities {
	namespace Obstaculos
	{
		class Plataforma : public Obstaculo
		{
		private:
		public:
			Plataforma(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, Gerenciadores::Gerenciador_colisoes* pGC, const char* caminho);
			Plataforma();
			~Plataforma();
		};
	}

}
