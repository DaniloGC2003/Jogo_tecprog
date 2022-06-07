#include "../headers/PrimeiraFase.h"

PrimeiraFase::PrimeiraFase(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* caminho):
	Fase(pos, pGraf, caminho), numLesmas(rand() % 3 + 3), numMonstros(rand() % 3 + 3), numBarris(rand() % 3 + 3), numLagos(rand() % 3 + 3),
	lesma (coordenadas::vetorfloat(300.f, 110.f), getAnimacao()->getpGraf(), "texturas_e_fontes/Lesma.png", &jogador, &Colisoes)
	//cada entidade pode ter de 3 a 5 instancias
{
	personagens.pushEntidade(&lesma);
}

PrimeiraFase::PrimeiraFase() : Fase(), numLesmas(0), numMonstros(0), numBarris(0), numLagos(0)
{
}

PrimeiraFase::~PrimeiraFase()
{


}

void PrimeiraFase::executar()
{
	getAnimacao()->render();//background

	Colisoes.colidir();

	personagens.percorrer();
	estaticas.percorrer();
	projeteis.percorrer();

	//HP.render();

	getAnimacao()->getpGraf()->getJanela()->setView(camera);
	camera.setCenter(jogador.getPos().getX(), jogador.getPos().getY());
}
