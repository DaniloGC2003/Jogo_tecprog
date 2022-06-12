#include "../headers/Plataforma.h"

Entities::Obstaculos::Plataforma::Plataforma(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, Gerenciadores::Gerenciador_colisoes* pGC, const char* caminho)
	: Obstaculo(pos, pGraf, pGC, caminho)

{
}

Entities::Obstaculos::Plataforma::Plataforma()
{
}

Entities::Obstaculos::Plataforma::~Plataforma()
{
}

