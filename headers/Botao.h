#pragma once
#include "Ente.h"
#include "Texto.h"

using namespace Entities;

class Botao: public Ente
{
private:
	Texto text;
	sf::Texture* texturapadrao; //textura para o botão não selecionado
	sf::Texture* texturaselecionada; // textura para o botão selecionado

	bool selecionado;
public:

	Botao(coordenadas::vetorfloat pos = coordenadas::vetorfloat(0, 0), Gerenciadores::Gerenciador_grafico* pGraf= nullptr, std::string info = "", const char* Pathtexturapadrao="");
	~Botao();

	Texto* getTexto() { return &text; }
	void setTexto(Texto* t) { text = *t; }
	void seleciona(const bool selecionado);
	void render();

	bool getSelecionado() { return selecionado; }
};

