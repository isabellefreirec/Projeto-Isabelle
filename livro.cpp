#include "livro.h"

Livro::Livro()
{

}


QString Livro::getnomeLivro() const
{
    return nLivro;
}

void Livro::setnomeLivro(const QString &value)
{
    nLivro = value;
}

double Livro::getValor() const
{
    return valor;
}

void Livro::setValor(double value)
{
    valor = value;
}

