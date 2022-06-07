#pragma once

#include "Ente.h"
#include "Botao.h"
#include "Texto.h"

class Menu: public Ente
{
private:
	int cont;//qual botão esta selecionada
	bool pressionado;
	bool selecionado;
    int max;
    int min;

    Texto titulo;
    std::vector<Botao*> vectordeBotoes;
    
public:
    
    
    Menu(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* background);
    Menu();
    ~Menu();

    Botao* getBotao(int pos); 
    Texto* getTitulo() { return &titulo; }
    void selecionaCima();
    void selecionaBaixo();
    int seleciona();
    void executar();

    int getSelecionado() { return cont; };
};

