
#include "../headers/Texto.h"


Texto::Texto(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, std::string info, const char* path) :
	Ente(),
	info(info) {

	getAnimacao()->setGerenciadorGrafico(pGraf);
	
	texto.setString(info);
	texto.setCharacterSize(24);
	setAlinhamento(AlinhamentoTexto::centro);
	texto.setPosition(sf::Vector2f(pos.getX(), pos.getY()));
	texto.setFillColor(sf::Color::Black);
	getAnimacao()->setGerenciadorGrafico(pGraf);

}

Texto::~Texto(){ }

void Texto::setPosicao(coordenadas::vetorfloat pos) {

	texto.setPosition(sf::Vector2f(pos.getX(), pos.getY()));
}

void Texto::setTextoInfo(std::string info) {

	this->info = info;
	texto.setString(this->info);
}

void Texto::inicializarFonte(Gerenciadores::Gerenciador_grafico* pGraf, const char* caminho, coordenadas::vetorfloat pos) {

	pGraf->carregaFonte(caminho);
	texto.setCharacterSize(24);
	setAlinhamento(AlinhamentoTexto::centro);
	texto.setFillColor(sf::Color::Black);
	texto.setPosition(pos.getX(), pos.getY());
}

void Texto::setTextColor(const unsigned int R, const unsigned int G, const unsigned int B) {

	texto.setFillColor(sf::Color(R, G, B));
}

void Texto::setFontSize(const unsigned int size) {

	texto.setCharacterSize(size);
}

void Texto::setAlinhamento(AlinhamentoTexto opcao) {

	switch (opcao) {

	case AlinhamentoTexto::esquerda:
		texto.setOrigin(0, 0);
		break;
	case AlinhamentoTexto::centro:
		texto.setOrigin(getSize().getX() / 2, getSize().getY());
		break;
	case AlinhamentoTexto::direita:
		texto.setOrigin(getSize().getX(), 0);
		break;
	default:
		texto.setOrigin(getSize().getX() / 2, getSize().getY());
	}
}

coordenadas::vetorfloat Texto::getSize() const {

	sf::FloatRect textRect = texto.getLocalBounds();
	return coordenadas::vetorfloat(textRect.width, textRect.height);
}

void Texto::render() {

	getAnimacao()->getpGraf()->desenhar(&texto);
	
}

std::string Texto::getInfo() const {

	return info;
}

coordenadas::vetorfloat Texto::getPosition() const {

	return coordenadas::vetorfloat(texto.getPosition().x, texto.getPosition().y);
}