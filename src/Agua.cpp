#include "../headers/Agua.h"

Entities::Agua::Agua(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* caminho):
	Obstaculo(pos,pGraf,caminho)
{
}

Entities::Agua::Agua()
{
}

Entities::Agua::~Agua()
{
}
