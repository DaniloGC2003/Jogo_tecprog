#pragma once
#include "Elemento.h"
namespace Lists
{
	template <class TL> class Lista
	{
	private:
		template <class TE> class Elemento
		{
		private:
			Elemento<TE>* pProx;
			TE* pinfo;

		public:
			Elemento()
			{
				pProx = nullptr;
				pinfo = nullptr;
			}

			~Elemento() { }

			void setpProx(Elemento<TE>* pProx) { this->pProx = pProx; }
			void setpInfo(TE* pinfo) { this->pinfo = pinfo; }

			Elemento<TE>* getpProx() { return pProx; }
			TE* getpInfo() { return pinfo; }
		};

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

			if (pPrimeiro == nullptr) {
				pPrimeiro = new Elemento<TL>;
				pPrimeiro->setpInfo(info);
				pUltimo = pPrimeiro;
			}
			else {
				Elemento<TL>* temp = new Elemento<TL>;
				temp->setpInfo(info);
				pUltimo->setpProx(temp);
				pUltimo = temp;
			}
			len++;
		}

		void pop(TL* info) {

			Elemento<TL>* temp = pPrimeiro;
			Elemento<TL>* tempAnt = nullptr;

			while (temp->getpInfo() != info) {

				tempAnt = temp;
				temp = temp->getpProx();
			}
			if (temp == pPrimeiro) {// Eliminando o primeiro elemento da lista
				pPrimeiro = temp->getpProx();
			}
			else if (temp == pUltimo) {//Eliminando o ultimo elemento da lista
				tempAnt->setpProx(nullptr);
				pUltimo = tempAnt;
			}
			else { //Eliminando elemento do meio da lista
				tempAnt->setpProx(temp->getpProx());
			}
			delete temp;
			len--;
		}

		void remove(TL* info) {

			Elemento<TL>* temp = pPrimeiro;
			Elemento<TL>* tempAnt = nullptr;

			while (temp->getpInfo() != info) {

				tempAnt = temp;
				temp = temp->getpProx();
			}
			if (temp == pPrimeiro) {// Eliminando o primeiro elemento da lista
				pPrimeiro = temp->getpProx();
			}
			else if (temp == pUltimo) {//Eliminando o ultimo elemento da lista
				tempAnt->setpProx(nullptr);
				pUltimo = tempAnt;
			}
			else { //Eliminando elemento do meio da lista

				tempAnt->setpProx(temp->getpProx());
			}
			len--;
		}
	};

	template<class TL>
	inline Lista<TL>::Lista()
	{
		pPrimeiro = nullptr;
		pUltimo = nullptr;
		len = 0;
	}

	template<class TL>
	inline Lista<TL>::~Lista()
	{
	}

}
