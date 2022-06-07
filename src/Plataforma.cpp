#include "../headers/Plataforma.h"

Entities::Plataforma::Plataforma(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, Gerenciadores::Gerenciador_colisoes* pGC, const char* caminho)
	: Obstaculo(pos, pGraf, pGC, caminho)

{
}

Entities::Plataforma::Plataforma()
{
}

Entities::Plataforma::~Plataforma()
{
}

