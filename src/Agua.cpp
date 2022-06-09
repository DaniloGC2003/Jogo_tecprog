#include "../headers/Agua.h"

Entities::Agua::Agua(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, Gerenciadores::Gerenciador_colisoes* pGC, const char* caminho):
	Obstaculo(pos,pGraf,pGC,caminho)
{
	getAnimacao()->getCorpo()->setFillColor(sf::Color::Green);
}

Entities::Agua::Agua()
{
}

Entities::Agua::~Agua()
{
}
