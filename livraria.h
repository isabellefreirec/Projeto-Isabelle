#ifndef LIVRARIA_H
#define LIVRARIA_H
#include "livro.h"
#include <QObject>
#include <QVector>
#include <algorithm>
#include <QFile>

class Livraria
{
    private:
    QVector <Livro> livraria;

    public:
    Livraria();
    void inserirLivro(Livro a);
    Livro operator[](int i);
    double getValor();
    double getMaiorValor();
    double getMenorValor();
    void ordenarPorNome();
    void ordenarPorValor();
    int size();
    bool salvarLivraria(QString arquivo);
    bool carregarLivraria(QString arquivo);

};

bool compararPorValor(Livro a, Livro b);
bool compararPorNome(Livro a, Livro b);

#endif // LIVRARIA_H
