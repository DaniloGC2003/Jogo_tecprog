#include "../headers/Barril.h"

Entities::Obstaculos::Barril::Barril(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, Gerenciadores::Gerenciador_colisoes* pGC, const char* caminho) :
	Obstaculo(pos, pGraf, pGC, caminho)
{
}

Entities::Obstaculos::Barril::Barril() : Obstaculo()
{
}

Entities::Obstaculos::Barril::~Barril()
{
}
