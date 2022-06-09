#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Gerenciador_grafico.h"
#include "ListaEntidades.h"
#include "Entidade.h"
#include "Gerenciador_colisoes.h"
#include "Menu.h"
#include "PrimeiraFase.h"
#include "SegundaFase.h"


class Jogo
{
private:
	sf::View camera;

	Gerenciadores::Gerenciador_grafico grafico;


	Menu menu;
	

	sf::Text mostraVida;
	sf::Font* fonte;

	bool noMenu;
	bool naPrimeiraFase;
	bool naSegundaFase;

	PrimeiraFase fase1;
	SegundaFase fase2;

public:
	Jogo();
	~Jogo();
	Lists::ListaEntidades* getPersonagens();
	Lists::ListaEntidades* getEstaticas();
	void Executar();


	void setnoMenu(bool nomenu) { noMenu = nomenu; }
	bool getnoMenu() { return noMenu; }

	void setnaPrimeiraFase(bool nafase) { naPrimeiraFase = nafase; }
	bool getnaPrimeiraFase() { return naPrimeiraFase; }
};