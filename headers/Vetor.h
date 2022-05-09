#pragma once
namespace coordenadas
{
    template <typename TL>
    class Vetor
    {
    private:
        TL x;
        TL y;
    public:
        Vetor(TL x, TL y);
        Vetor();
        ~Vetor();
        TL getX();
        TL getY();

        Vetor<TL> operator+ (Vetor<TL> v);
        Vetor<TL> operator- (Vetor<TL> v);
        TL operator* (Vetor<TL> v);//produto escalar
        Vetor<TL> operator* (double num);
        Vetor<TL> operator/ (double num);
        void operator= (Vetor<TL> v);//set coordenadas
        void operator+= (Vetor<TL> v);
        void operator-= (Vetor<TL> v);






    };

    template<typename TL>
    inline Vetor<TL>::Vetor(TL x, TL y) : x(x), y(y)
    {
    }

    template<typename TL>
    inline Vetor<TL>::Vetor()
    {
        x = 0;
        y = 0;
    }
    template<typename TL>
    inline Vetor<TL>::~Vetor()
    {
        x = 0;
        y = 0;
    }
    template<typename TL>
    inline TL Vetor<TL>::getX()
    {
        return x;
    }
    template<typename TL>
    inline TL Vetor<TL>::getY()
    {
        return y;
    }
    template<typename TL>
    inline Vetor<TL> Vetor<TL>::operator+(Vetor<TL> v)
    {
        return Vetor<TL>(this->x + v.getX(), this->y + v.getY());
    }
    template<typename TL>
    inline Vetor<TL> Vetor<TL>::operator-(Vetor<TL> v)
    {
        return Vetor<TL>(this->x - v.getX(), this->y - v.getY());
    }
    template<typename TL>
    inline TL Vetor<TL>::operator*(Vetor<TL> v)
    {
        return this->getX() * v.getX() + this->getY() * v.getY();
    }
    template<typename TL>
    inline Vetor<TL> Vetor<TL>::operator*(double num)
    {
        return Vetor<TL>(this->getX() * num, this->getY() * num);
    }
    template<typename TL>
    inline Vetor<TL> Vetor<TL>::operator/(double num)
    {
        return Vetor<TL>(this->getX()/num, this->getY()/num);
    }
    template<typename TL>
    inline void Vetor<TL>::operator=(Vetor<TL> v)
    {
        this->x = v.getX();
        this->y = v.getY();
    }
    template<typename TL>
    inline void Vetor<TL>::operator+=(Vetor<TL> v)
    {
        this->x += v.getX();
        this->y += v.getY();
    }
    template<typename TL>
    inline void Vetor<TL>::operator-=(Vetor<TL> v)
    {
        this->x -= v.getX();
        this->y -= v.getY();
    }
}