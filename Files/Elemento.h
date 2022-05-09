#pragma once
template <class TE> class Elemento
{
private:
	Elemento<TE>* pProx;
	TE* pinfo;

public:
	Elemento();
	~Elemento();

	void setpProx(Elemento<TE>* pProx) { this->pProx = pProx }
	void setpInfo(TE* pinfo) { this->pinfo = pinfo }

	Elemento<TE>* getpProx() { return pProx; }
	TE* getpInfo() { return pinfo; }
};

template<class TE>
inline Elemento<TE>::Elemento()
{
	pProx = NULL;
	pinfo = NULL;
}

template<class TE>
inline Elemento<TE>::~Elemento()
{
}

