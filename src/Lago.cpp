#include "../headers/Lago.h"

Entities::Obstaculos::Lago::Lago(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, Gerenciadores::Gerenciador_colisoes* pGC, const char* caminho):
	Obstaculo(pos,pGraf,pGC,caminho)
{
}

Entities::Obstaculos::Lago::Lago()
{
}

Entities::Obstaculos::Lago::~Lago()
{
}
