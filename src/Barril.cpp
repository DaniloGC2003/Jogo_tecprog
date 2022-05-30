#include "../headers/Barril.h"

Entities::Barril::Barril(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* caminho) :
	Obstaculo(pos, pGraf, caminho)
{
}

Entities::Barril::Barril()
{
}

Entities::Barril::~Barril()
{
}
