#include "../headers/SegundaFase.h"

SegundaFase::SegundaFase(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* caminho):
	Fase(pos, pGraf, caminho), numLesmas(rand() % 2 + 3), numMonstros(rand() % 2 + 3), numBarris(rand() % 2 + 3), numAguas(rand()%2+3)	
{
	Entities::Entidade* pEnt;

	//inicializando plataformas:
	Entities::Plataforma* pP;
	pP = new Entities::Plataforma(coordenadas::vetorfloat(250.f, 300.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/preview.png");
	pP->getAnimacao()->mudaEscala(10.f, 1.f);
	estaticas.pushEntidade(static_cast<Entities::Entidade*>(pP));
	pP = new Entities::Plataforma(coordenadas::vetorfloat(950.f, 200.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/preview.png");
	pP->getAnimacao()->mudaEscala(10.f, 1.f);
	estaticas.pushEntidade(static_cast<Entities::Entidade*>(pP));
	pP = new Entities::Plataforma(coordenadas::vetorfloat(1600.f, 100.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/preview.png");
	pP->getAnimacao()->mudaEscala(10.f, 1.f);
	estaticas.pushEntidade(static_cast<Entities::Entidade*>(pP));
	pP = new Entities::Plataforma(coordenadas::vetorfloat(3400.f, 200.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/preview.png");
	pP->getAnimacao()->mudaEscala(50.f, 1.f);
	estaticas.pushEntidade(static_cast<Entities::Entidade*>(pP));
	
	//inicializando barris:
	pEnt = static_cast<Entities::Entidade*> (new Entities::Barril(coordenadas::vetorfloat(450.f, 265.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/Fishbarrel4.png"));
	estaticas.pushEntidade(pEnt);
	pEnt = static_cast<Entities::Entidade*> (new Entities::Barril(coordenadas::vetorfloat(950.f, 165.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/Fishbarrel4.png"));
	estaticas.pushEntidade(pEnt);
	pEnt = static_cast<Entities::Entidade*> (new Entities::Barril(coordenadas::vetorfloat(1600.f, 65.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/Fishbarrel4.png"));
	estaticas.pushEntidade(pEnt);
	if (numBarris > 3)
	{
		pEnt = static_cast<Entities::Entidade*> (new Entities::Barril(coordenadas::vetorfloat(2440.f, 165.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/Fishbarrel4.png"));
		estaticas.pushEntidade(pEnt);
	}

	//inicializando aguas:
	pEnt = static_cast<Entities::Entidade*> (new Entities::Agua(coordenadas::vetorfloat(300.f, 290.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/Water.png", jogador));
	estaticas.pushEntidade(pEnt);
	pEnt = static_cast<Entities::Entidade*> (new Entities::Agua(coordenadas::vetorfloat(800.f, 190.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/Water.png", jogador));
	estaticas.pushEntidade(pEnt);
	pEnt = static_cast<Entities::Entidade*> (new Entities::Agua(coordenadas::vetorfloat(1450.f, 90.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/Water.png", jogador));
	estaticas.pushEntidade(pEnt);
	if (numAguas > 3)
	{
		pEnt = static_cast<Entities::Entidade*> (new Entities::Agua(coordenadas::vetorfloat(2600.f, 190.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/Water.png", jogador));
		estaticas.pushEntidade(pEnt);
	}

	inicializaFase();
}

SegundaFase::SegundaFase() : Fase(), numLesmas(0), numMonstros(0), numBarris(0), numAguas(0), tartaruga(nullptr)
{
}

SegundaFase::~SegundaFase()
{
	personagens.deletatudo();
	estaticas.deletatudo();
}

void SegundaFase::inicializaFase()
{
	jogador->setVida(100);
	jogador->mudarPos(coordenadas::vetorfloat(50.f, 110.f));

	while (personagens.getTamanho() > 1)
	{
		personagens.deleteEntidade(personagens.getEntidade(1));//deleta todos menos o jogador
	}

	Entities::Entidade* pEnt;

	//inicializando lesmas:
	pEnt = static_cast<Entities::Entidade*>(new Entities::Lesma(coordenadas::vetorfloat(398.f, 110.f), getAnimacao()->getpGraf(), "texturas_e_fontes/Lesma.png", jogador, &Colisoes));
	personagens.pushEntidade(pEnt);
	pEnt = static_cast<Entities::Entidade*>(new Entities::Lesma(coordenadas::vetorfloat(1000.f, 110.f), getAnimacao()->getpGraf(), "texturas_e_fontes/Lesma.png", jogador, &Colisoes));
	personagens.pushEntidade(pEnt);
	pEnt = static_cast<Entities::Entidade*>(new Entities::Lesma(coordenadas::vetorfloat(1150.f, 50.f), getAnimacao()->getpGraf(), "texturas_e_fontes/Lesma.png", jogador, &Colisoes));
	personagens.pushEntidade(pEnt);
	if (numLesmas > 3)
	{
		pEnt = static_cast<Entities::Entidade*>(new Entities::Lesma(coordenadas::vetorfloat(2484.f, 110.f), getAnimacao()->getpGraf(), "texturas_e_fontes/Lesma.png", jogador, &Colisoes));
		personagens.pushEntidade(pEnt);
	}

	//inicializando monstros:
	pEnt = static_cast<Entities::Entidade*>(new Entities::Monstro(coordenadas::vetorfloat(1550.f, 50.f), getAnimacao()->getpGraf(), "texturas_e_fontes/Monstro.png", jogador, &Colisoes));
	personagens.pushEntidade(pEnt);
	pEnt = static_cast<Entities::Entidade*>(new Entities::Monstro(coordenadas::vetorfloat(1740.f, 50.f), getAnimacao()->getpGraf(), "texturas_e_fontes/Monstro.png", jogador, &Colisoes));
	personagens.pushEntidade(pEnt);
	pEnt = static_cast<Entities::Entidade*>(new Entities::Monstro(coordenadas::vetorfloat(2900.f, 50.f), getAnimacao()->getpGraf(), "texturas_e_fontes/Monstro.png", jogador, &Colisoes));
	personagens.pushEntidade(pEnt);
	if (numMonstros > 3)
	{
		pEnt = static_cast<Entities::Entidade*>(new Entities::Monstro(coordenadas::vetorfloat(3200.f, 110.f), getAnimacao()->getpGraf(), "texturas_e_fontes/Monstro.png", jogador, &Colisoes));
		personagens.pushEntidade(pEnt);
	}

	//inicializando tartaruga:
	tartaruga = new Entities::Tartaruga(coordenadas::vetorfloat(3850.f, 110.f), getAnimacao()->getpGraf(), "texturas_e_fontes/Battle_turtle.png", jogador, &Colisoes, 500);
	personagens.pushEntidade(static_cast<Entities::Entidade*>(tartaruga));
}

void SegundaFase::executar()
{
	getAnimacao()->render();//background

	Colisoes.colidir();

	personagens.percorrer();
	estaticas.percorrer();
	projeteis.percorrer();

	mostraVidaJogador();

	getAnimacao()->getpGraf()->getJanela()->setView(camera);
	camera.setCenter(jogador->getPos().getX(), jogador->getPos().getY());

	if (jogador->getPos().getY() > 600.f)
	{
		jogador->setVida(0);
	}
}

bool SegundaFase::jogoAtivo()
{
	//se jogador morreu ou se matou a tartaruga
	if (jogador->getVida() == 0 || tartaruga->getVida() == 0 || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		return false;
	}
	return true;
}
