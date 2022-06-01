#include "../headers/Agua.h"

Entities::Agua::Agua(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, Gerenciadores::Gerenciador_colisoes* pGC, const char* caminho):
	Obstaculo(pos,pGraf,pGC,caminho)
{
}

Entities::Agua::Agua()
{
}

Entities::Agua::~Agua()
{
}
