#include "../headers/SegundaFase.h"

SegundaFase::SegundaFase(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* caminho):
	Fase(pos, pGraf, caminho), numLesmas(rand() % 2 + 3), numMonstros(rand() % 2 + 3), numBarris(rand() % 2 + 3), numAguas(rand()%2+3),
	lesma1(coordenadas::vetorfloat(350.f, 110.f), getAnimacao()->getpGraf(), "texturas_e_fontes/Lesma.png", &jogador, &Colisoes),
	lesma2(coordenadas::vetorfloat(350.f, 110.f), getAnimacao()->getpGraf(), "texturas_e_fontes/Lesma.png", &jogador, &Colisoes),
	lesma3(coordenadas::vetorfloat(350.f, 110.f), getAnimacao()->getpGraf(), "texturas_e_fontes/Lesma.png", &jogador, &Colisoes),
	lesma4(coordenadas::vetorfloat(350.f, 110.f), getAnimacao()->getpGraf(), "texturas_e_fontes/Lesma.png", &jogador, &Colisoes),
	monstro1(coordenadas::vetorfloat(1500.f, 110.f), getAnimacao()->getpGraf(), "texturas_e_fontes/Monstro.png", &jogador, &Colisoes),
	monstro2(coordenadas::vetorfloat(1500.f, 110.f), getAnimacao()->getpGraf(), "texturas_e_fontes/Monstro.png", &jogador, &Colisoes),
	monstro3(coordenadas::vetorfloat(1500.f, 110.f), getAnimacao()->getpGraf(), "texturas_e_fontes/Monstro.png", &jogador, &Colisoes),
	monstro4(coordenadas::vetorfloat(1500.f, 110.f), getAnimacao()->getpGraf(), "texturas_e_fontes/Monstro.png", &jogador, &Colisoes),
	barril1(coordenadas::vetorfloat(450.f, 265.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/Fishbarrel4.png"),
	barril2(coordenadas::vetorfloat(950.f, 165.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/Fishbarrel4.png"),
	barril3(coordenadas::vetorfloat(1600.f, 65.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/Fishbarrel4.png"),
	barril4(coordenadas::vetorfloat(2440.f, 165.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/Fishbarrel4.png"),
	agua1(coordenadas::vetorfloat(300.f, 290.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/Water.png", &jogador),
	agua2(coordenadas::vetorfloat(800.f, 190.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/Water.png", &jogador),
	agua3(coordenadas::vetorfloat(1450.f, 90.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/Water.png", &jogador),
	agua4(coordenadas::vetorfloat(2600.f, 190.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/Water.png", &jogador),
	tartaruga(coordenadas::vetorfloat(3850.f, 110.f),getAnimacao()->getpGraf(), "texturas_e_fontes/Battle_turtle.png", &jogador, &Colisoes, 500),
	plataforma1(coordenadas::vetorfloat(950.f, 200.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/preview.png"),
	plataforma2(coordenadas::vetorfloat(1600.f, 100.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/preview.png"),
	plataforma3(coordenadas::vetorfloat(3400.f, 200.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/preview.png")
{
	plataforma.mudarPos(coordenadas::vetorfloat(50.f, 300.f));
	plataforma.getAnimacao()->mudaEscala(0.09f, 1.f);

	plataforma1.getAnimacao()->mudaEscala(10.f, 1.f);
	estaticas.pushEntidade(&plataforma1);
	plataforma2.getAnimacao()->mudaEscala(10.f, 1.f);
	estaticas.pushEntidade(&plataforma2);
	plataforma3.getAnimacao()->mudaEscala(50.f, 1.f);
	estaticas.pushEntidade(&plataforma3);

	estaticas.pushEntidade(&barril1);
	estaticas.pushEntidade(&barril2);
	estaticas.pushEntidade(&barril3);
	if (numBarris > 3)
	{
		estaticas.pushEntidade(&barril4);
	}
	estaticas.pushEntidade(&agua1);
	estaticas.pushEntidade(&agua2);
	estaticas.pushEntidade(&agua3);
	if (numAguas > 3)
	{
		estaticas.pushEntidade(&agua4);
	}

	inicializaFase();
}

SegundaFase::SegundaFase() : Fase(), numLesmas(0), numMonstros(0), numBarris(0), numAguas(0)
{
}

SegundaFase::~SegundaFase()
{
}

void SegundaFase::inicializaFase()
{
	jogador.setVida(100);
	jogador.mudarPos(coordenadas::vetorfloat(50.f, 110.f));

	lesma1.setVida(100);
	lesma1.mudarPos(coordenadas::vetorfloat(398.f, 110.f));
	personagens.pushEntidade(&lesma1);
	lesma2.setVida(100);
	lesma2.mudarPos(coordenadas::vetorfloat(1000.f, 110.f));
	personagens.pushEntidade(&lesma2);
	lesma3.setVida(100);
	lesma3.mudarPos(coordenadas::vetorfloat(1150.f, 50.f));
	personagens.pushEntidade(&lesma3);
	if (numLesmas > 3)
	{
		lesma4.setVida(100);
		lesma4.mudarPos(coordenadas::vetorfloat(2484.f, 110.f));
		personagens.pushEntidade(&lesma4);
	}

	monstro1.setVida(100);
	monstro1.mudarPos(coordenadas::vetorfloat(1550.f, 50.f));
	personagens.pushEntidade(&monstro1);
	monstro2.setVida(100);
	monstro2.mudarPos(coordenadas::vetorfloat(1740.f, 50.f));
	personagens.pushEntidade(&monstro2);
	monstro3.setVida(100);
	monstro3.mudarPos(coordenadas::vetorfloat(2900.f, 50.f));
	personagens.pushEntidade(&monstro3);
	if (numMonstros > 3)
	{
		monstro4.setVida(100);
		monstro4.mudarPos(coordenadas::vetorfloat(3200.f, 110.f));
		personagens.pushEntidade(&monstro4);
	}

	tartaruga.setVida(500);
	tartaruga.mudarPos(coordenadas::vetorfloat(3850.f, 110.f));
	personagens.pushEntidade(&tartaruga);
}

void SegundaFase::executar()
{
	getAnimacao()->render();//background

	Colisoes.colidir();

	personagens.percorrer();
	estaticas.percorrer();
	projeteis.percorrer();

	getAnimacao()->getpGraf()->getJanela()->setView(camera);
	camera.setCenter(jogador.getPos().getX(), jogador.getPos().getY());

	if (jogador.getPos().getY() > 600.f)
	{
		jogador.setVida(0);
	}
	std::cout << jogador.getVida() << std::endl;
}

bool SegundaFase::jogoAtivo()
{
	//se jogador morreu ou se matou a tartaruga
	if (jogador.getVida() == 0 || tartaruga.getVida() == 0)
	{
		return false;
	}
	return true;
}
