#ifndef LIVRO_H
#define LIVRO_H

#include <QObject>

class Livro
{
private:

    QString nLivro;
    double valor;


public:

    Livro();
    QString getnomeLivro() const;
    void setnomeLivro(const QString &value);
    double getValor() const;
    void setValor(double value);

    };



#endif
