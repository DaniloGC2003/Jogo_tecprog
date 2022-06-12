#include "../headers/PrimeiraFase.h"
namespace Fases
{
	PrimeiraFase::PrimeiraFase(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* caminho) :
		Fase(pos, pGraf, caminho), numLesmas(rand() % 2 + 3), numMonstros(rand() % 2 + 3), numBarris(rand() % 2 + 3), numLagos(rand() % 2 + 3)	//cada entidade pode ter de 3 a 4 instancias
	{

		inicializaFase();
	}

	PrimeiraFase::PrimeiraFase() : Fase(), numLesmas(0), numMonstros(0), numBarris(0), numLagos(0)
	{
	}

	PrimeiraFase::~PrimeiraFase()
	{
		personagens.deletatudo();
		estaticas.deletatudo();
	}

	void PrimeiraFase::inicializaFase()
	{
		//gerando numeros aleatorios para instanciacao de personagens:
		numLesmas = rand() % 2 + 3;
		numMonstros = rand() % 2 + 3;
		numBarris = rand() % 2 + 3;
		numLagos = rand() % 2 + 3;

		jogador->setVida(100);
		jogador->mudarPos(coordenadas::vetorfloat(50.f, 110.f));

		while (personagens.getTamanho() > 1)
		{
			personagens.deleteEntidade(personagens.getEntidade(1));//deleta todos menos o jogador
		}
		estaticas.deletatudo();

		Entities::Entidade* pEnt;

		//inicializando lesmas:
		pEnt = static_cast<Entities::Entidade*>(new Entities::Personagens::Lesma(coordenadas::vetorfloat(350.f, 110.f), getAnimacao()->getpGraf(), "texturas_e_fontes/Lesma.png", jogador, &Colisoes));
		personagens.pushEntidade(pEnt);
		pEnt = static_cast<Entities::Entidade*>(new Entities::Personagens::Lesma(coordenadas::vetorfloat(780.f, 110.f), getAnimacao()->getpGraf(), "texturas_e_fontes/Lesma.png", jogador, &Colisoes));
		personagens.pushEntidade(pEnt);
		pEnt = static_cast<Entities::Entidade*>(new Entities::Personagens::Lesma(coordenadas::vetorfloat(1050.f, 110.f), getAnimacao()->getpGraf(), "texturas_e_fontes/Lesma.png", jogador, &Colisoes));
		personagens.pushEntidade(pEnt);
		if (numLesmas > 3)
		{
			pEnt = static_cast<Entities::Entidade*>(new Entities::Personagens::Lesma(coordenadas::vetorfloat(1450.f, 110.f), getAnimacao()->getpGraf(), "texturas_e_fontes/Lesma.png", jogador, &Colisoes));
			personagens.pushEntidade(pEnt);
		}

		//inicializando monstros:
		pEnt = static_cast<Entities::Entidade*>(new Entities::Personagens::Monstro(coordenadas::vetorfloat(1500.f, 110.f), getAnimacao()->getpGraf(), "texturas_e_fontes/Monstro.png", jogador, &Colisoes));
		personagens.pushEntidade(pEnt);
		pEnt = static_cast<Entities::Entidade*>(new Entities::Personagens::Monstro(coordenadas::vetorfloat(2000.f, 110.f), getAnimacao()->getpGraf(), "texturas_e_fontes/Monstro.png", jogador, &Colisoes));
		personagens.pushEntidade(pEnt);
		pEnt = static_cast<Entities::Entidade*>(new Entities::Personagens::Monstro(coordenadas::vetorfloat(2500.f, 110.f), getAnimacao()->getpGraf(), "texturas_e_fontes/Monstro.png", jogador, &Colisoes));
		personagens.pushEntidade(pEnt);
		if (numMonstros > 3)
		{
			pEnt = static_cast<Entities::Entidade*>(new Entities::Personagens::Monstro(coordenadas::vetorfloat(3000.f, 110.f), getAnimacao()->getpGraf(), "texturas_e_fontes/Monstro.png", jogador, &Colisoes));
			personagens.pushEntidade(pEnt);
		}

		//inicializando plataformas:
		Entities::Obstaculos::Plataforma* pP;
		pP = new Entities::Obstaculos::Plataforma(coordenadas::vetorfloat(1000.f, 300.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/preview.png");
		pP->getAnimacao()->mudaEscala(200.f, 1.f);
		estaticas.pushEntidade(pP);
		pP = new Entities::Obstaculos::Plataforma(coordenadas::vetorfloat(500.f, 200.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/preview.png");
		pP->getAnimacao()->mudaEscala(10.f, 0.8f);
		estaticas.pushEntidade(static_cast<Entities::Entidade*>(pP));

		//inicializando barris:
		pEnt = static_cast<Entities::Entidade*> (new Entities::Obstaculos::Barril(coordenadas::vetorfloat(100.f, 265.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/Fishbarrel4.png"));
		estaticas.pushEntidade(pEnt);
		pEnt = static_cast<Entities::Entidade*> (new Entities::Obstaculos::Barril(coordenadas::vetorfloat(1100.f, 265.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/Fishbarrel4.png"));
		estaticas.pushEntidade(pEnt);
		pEnt = static_cast<Entities::Entidade*> (new Entities::Obstaculos::Barril(coordenadas::vetorfloat(2100.f, 265.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/Fishbarrel4.png"));
		estaticas.pushEntidade(pEnt);
		if (numBarris > 3)
		{
			pEnt = static_cast<Entities::Entidade*> (new Entities::Obstaculos::Barril(coordenadas::vetorfloat(3100.f, 265.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/Fishbarrel4.png"));
			estaticas.pushEntidade(pEnt);
		}

		//inicializando lagos:
		pEnt = static_cast<Entities::Entidade*> (new Entities::Obstaculos::Lago(coordenadas::vetorfloat(300.f, 290.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/Water.png"));
		estaticas.pushEntidade(pEnt);
		pEnt = static_cast<Entities::Entidade*> (new Entities::Obstaculos::Lago(coordenadas::vetorfloat(1300.f, 290.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/Water.png"));
		estaticas.pushEntidade(pEnt);
		pEnt = static_cast<Entities::Entidade*> (new Entities::Obstaculos::Lago(coordenadas::vetorfloat(2300.f, 290.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/Water.png"));
		estaticas.pushEntidade(pEnt);
		if (numLagos > 3)
		{
			pEnt = static_cast<Entities::Entidade*> (new Entities::Obstaculos::Lago(coordenadas::vetorfloat(3300.f, 290.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/Water.png"));
			estaticas.pushEntidade(pEnt);
		}

	}

	void PrimeiraFase::executar()
	{
		getAnimacao()->render();//background

		Colisoes.colidir();

		personagens.percorrer();
		estaticas.percorrer();
		projeteis.percorrer();

		mostraVidaJogador();

		getAnimacao()->getpGraf()->getJanela()->setView(camera);
		camera.setCenter(jogador->getPos().getX(), jogador->getPos().getY());
	}

	bool PrimeiraFase::jogoAtivo()
	{
		//se morreu ou se chegou ao fim do mapa ou se pressionou Esc
		if (jogador->getVida() == 0 || jogador->getPos().getX() > 3500 || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			return false;
		}
		return true;
	}

}
