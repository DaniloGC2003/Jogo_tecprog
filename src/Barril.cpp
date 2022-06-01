#include "../headers/Barril.h"

Entities::Barril::Barril(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, Gerenciadores::Gerenciador_colisoes* pGC, const char* caminho) :
	Obstaculo(pos, pGraf, pGC, caminho)
{
}

Entities::Barril::Barril() : Obstaculo()
{
}

Entities::Barril::~Barril()
{
}
