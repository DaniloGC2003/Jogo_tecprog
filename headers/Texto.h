#pragma once

#include "Gerenciador_grafico.h"
#include "Vetor.h"
#include "Ente.h"

using namespace Entities;
enum AlinhamentoTexto {

	esquerda,
	centro,
	direita
};

class Texto : public Ente
{
private:
	std::string info;
	sf::Text texto;

	

public:
	Texto(coordenadas::vetorfloat pos = coordenadas::vetorfloat(0, 0), Gerenciadores::Gerenciador_grafico* pGraf = NULL, std::string info = "", const char* path = "caminho.ttf");
	~Texto();

	void setPosicao(coordenadas::vetorfloat pos);
	void setTextoInfo(std::string info);
	void setTextColor(const unsigned int R, const unsigned int G, const unsigned int B);
	void setFontSize(const unsigned int size);
	void setAlinhamento(AlinhamentoTexto opcao);
	void inicializarFonte(Gerenciadores::Gerenciador_grafico* pGraf, const char* caminho, coordenadas::vetorfloat pos);

	coordenadas::vetorfloat getSize() const;

	void render();

	std::string getInfo() const;

	sf::Text* getText() { return &texto; }

	void setFonte(sf::Font* font) { texto.setFont(*font); }

	coordenadas::vetorfloat getPosition() const;
};

