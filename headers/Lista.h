#pragma once
#include "Elemento.h"

template <class TL> class Lista
{
private:
	Elemento<TL>* pPrimeiro;
	Elemento<TL>* pUltimo;
	int len;
public:

	Lista();
	~Lista();

	int getlen() { return len; }// len = tamanho

	TL* getpInfo(int posicao) {

		Elemento<TL>* temp = pPrimeiro;

		if (posicao == 0)
			return temp->getpInfo();
		else {
			for (int i = 0; i < posicao; i++) {
				if (temp) {
					temp = temp->getpProx();
				}
			}
			return temp->getpInfo();
		}
	}

	void push(TL* info) {

		if (pPrimeiro == NULL) {
			pPrimeiro = new Elemento<TL>;
			pPrimeiro->setpInfo(info);
			pUltimo = pPrimeiro;
		}
		else {
			Elemento<TL>* temp = new Elemento<TL>;
			temp->setpInfo(info);
			pUltimo->getpProx(temp);
			pUltimo = temp;
		}
		len++;
	}

	void pop(TL* info) {

		Elemento<TL>* temp = pPrimeiro;
		Elemento<TL>* tempAnt = NULL;

		while (temp->getpInfo != info) {

			tempAnt = temp;
			temp = temp->getpProx();
		}
		if (temp == pPrimeiro) {// Eliminando o primeiro elemento da lista
			pPrimeiro = temp->getpProx();
		}
		else if (temp == pUltimo) {//Eliminando o ultimo elemento da lista
			tempAnt->setpProx(NULL);
			pUltimo=tempAnt:
		}
		else { //Eliminando elemento do meio da lista
			temp->setpProx(temp->getpProx());
		}
		delete tem;
		len--;
	}
};

template<class TL>
inline Lista<TL>::Lista()
{
	pPrimeiro = NULL;
	pUltimo = NULL;
	len = 0;
}

template<class TL>
inline Lista<TL>::~Lista()
{
}
