#include "../headers/PrimeiraFase.h"

PrimeiraFase::PrimeiraFase(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* caminho):
	Fase(pos, pGraf, caminho), numLesmas(rand() % 2 + 3), numMonstros(rand() % 2 + 3), numBarris(rand() % 2 + 3), numLagos(rand() % 2 + 3),	//cada entidade pode ter de 3 a 4 instancias
	lesma1(coordenadas::vetorfloat(350.f, 110.f), getAnimacao()->getpGraf(), "texturas_e_fontes/Lesma.png", &jogador, &Colisoes),
	lesma2(coordenadas::vetorfloat(780.f, 110.f), getAnimacao()->getpGraf(), "texturas_e_fontes/Lesma.png", &jogador, &Colisoes),
	lesma3(coordenadas::vetorfloat(1050.f, 110.f), getAnimacao()->getpGraf(), "texturas_e_fontes/Lesma.png", &jogador, &Colisoes),
	lesma4(coordenadas::vetorfloat(1450.f, 110.f), getAnimacao()->getpGraf(), "texturas_e_fontes/Lesma.png", &jogador, &Colisoes),
	monstro1(coordenadas::vetorfloat(1500.f, 110.f), getAnimacao()->getpGraf(), "texturas_e_fontes/Monstro.png", &jogador, &Colisoes),
	monstro2(coordenadas::vetorfloat(2000.f, 110.f), getAnimacao()->getpGraf(), "texturas_e_fontes/Monstro.png", &jogador, &Colisoes),
	monstro3(coordenadas::vetorfloat(2500.f, 110.f), getAnimacao()->getpGraf(), "texturas_e_fontes/Monstro.png", &jogador, &Colisoes),
	monstro4(coordenadas::vetorfloat(3000.f, 110.f), getAnimacao()->getpGraf(), "texturas_e_fontes/Monstro.png", &jogador, &Colisoes),
	barril1(coordenadas::vetorfloat(100.f, 265.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/Fishbarrel4.png"),
	barril2(coordenadas::vetorfloat(1100.f, 265.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/Fishbarrel4.png"),
	barril3(coordenadas::vetorfloat(2100.f, 265.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/Fishbarrel4.png"),
	barril4(coordenadas::vetorfloat(3100.f, 265.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/Fishbarrel4.png"),
	lago1(coordenadas::vetorfloat(300.f, 290.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/Water.png"),
	lago2(coordenadas::vetorfloat(1300.f, 290.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/Water.png"),
	lago3(coordenadas::vetorfloat(2300.f, 290.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/Water.png"),
	lago4(coordenadas::vetorfloat(3300.f, 290.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/Water.png"),
	plataforma1(coordenadas::vetorfloat(500.f, 200.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/preview.png")
{

	estaticas.pushEntidade(&barril1);
	estaticas.pushEntidade(&barril2);
	estaticas.pushEntidade(&barril3);
	if (numBarris > 3)
	{
		estaticas.pushEntidade(&barril4);
	}
	estaticas.pushEntidade(&lago1);
	estaticas.pushEntidade(&lago2);
	estaticas.pushEntidade(&lago3);
	if (numLagos > 3)
	{
		estaticas.pushEntidade(&lago4);
	}

	plataforma1.getAnimacao()->mudaEscala(10.f, 0.8f);
	estaticas.pushEntidade(&plataforma1);
	
	inicializaFase();
}

PrimeiraFase::PrimeiraFase() : Fase(), numLesmas(0), numMonstros(0), numBarris(0), numLagos(0)
{
}

PrimeiraFase::~PrimeiraFase()
{


}

void PrimeiraFase::inicializaFase()
{
	jogador.setVida(100);
	jogador.mudarPos(coordenadas::vetorfloat(50.f, 110.f));

	lesma1.setVida(100);
	lesma1.mudarPos(coordenadas::vetorfloat(350.f, 110.f));
	personagens.pushEntidade(&lesma1);
	lesma2.setVida(100);
	lesma2.mudarPos(coordenadas::vetorfloat(780.f, 110.f));
	personagens.pushEntidade(&lesma2);
	lesma3.setVida(100);
	lesma3.mudarPos(coordenadas::vetorfloat(1050.f, 110.f));
	personagens.pushEntidade(&lesma3);
	if (numLesmas > 3)
	{
		lesma4.setVida(100);
		lesma4.mudarPos(coordenadas::vetorfloat(1450.f, 110.f));
		personagens.pushEntidade(&lesma4);
	}

	monstro1.setVida(100);
	monstro1.mudarPos(coordenadas::vetorfloat(1500.f, 110.f));
	personagens.pushEntidade(&monstro1);
	monstro2.setVida(100);
	monstro2.mudarPos(coordenadas::vetorfloat(2000.f, 110.f));
	personagens.pushEntidade(&monstro2);
	monstro3.setVida(100);
	monstro3.mudarPos(coordenadas::vetorfloat(2500.f, 110.f));
	personagens.pushEntidade(&monstro3);
	if (numMonstros > 3)
	{
		monstro1.setVida(100);
		monstro1.mudarPos(coordenadas::vetorfloat(3000.f, 110.f));
		personagens.pushEntidade(&monstro1);
	}
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

bool PrimeiraFase::jogoAtivo()
{
	//se morreu ou se chegou ao fim do mapa
	if (jogador.getVida() == 0 || jogador.getPos().getX() > 3500)
	{
		return false;
	}
	return true;
}
