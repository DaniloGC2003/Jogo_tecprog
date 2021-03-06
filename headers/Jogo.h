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

	bool noMenu;
	bool naPrimeiraFase;
	bool naSegundaFase;

	Fases::PrimeiraFase fase1;
	Fases::SegundaFase fase2;

public:
	Jogo();
	~Jogo();
	void Executar();
};