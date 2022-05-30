#include "../headers/Plataforma.h"

Entities::Plataforma::Plataforma(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* caminho) :
	Obstaculo(pos, pGraf, caminho)
{
}

Entities::Plataforma::Plataforma()
{
}

Entities::Plataforma::~Plataforma()
{
}

