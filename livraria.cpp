#include "livraria.h"
#include "livro.h"


Livraria::Livraria()
{

}

void Livraria::inserirLivro(Livro a)
{
    livraria.push_back(a);
}

Livro Livraria::operator[](int i)
{
    return livraria[i];
}
double Livraria::getValor(){
    double valor=0;
    for(Livro a: livraria){
        valor+=a.getValor();
    }
    return valor/livraria.size();

}

double Livraria::getMenorValor(){
    Livro *menor=std::min_element(livraria.begin(),livraria.end(),compararPorValor);
    return menor ->getValor();
}

double Livraria::getMaiorValor(){
    Livro *maior=std::max_element(livraria.begin(),livraria.end(),compararPorValor);
    return maior->getValor();
}
void Livraria::ordenarPorNome(){

    std::sort(livraria.begin(),livraria.end(),compararPorNome);
}
void Livraria:: ordenarPorValor(){
    std::sort(livraria.begin(),livraria.end(),compararPorValor);
}
int Livraria::size(){
    return livraria.size();
}
bool Livraria::salvarLivraria(QString arquivo){
    QFile file(arquivo);
    QString linha;
    if(!file.open(QIODevice::WriteOnly))
        return false;
    for(Livro a: livraria){
        linha =a.getnomeLivro()+','+QString::number(a.getValor())+'\n';
        file.write(linha.toLocal8Bit());
    }
    file.close();
    return  true;
}

bool Livraria::carregarLivraria(QString arquivo){
    QFile file(arquivo);
    if(!file.open(QIODevice::ReadOnly))
        return false;
    QString linha;
    Livro a;
    while (!file.atEnd()) {
        linha=file.readLine();
        QStringList dados=linha.split(",");
        a.setnomeLivro(dados[0]);
        a.setValor(dados[1].toDouble());
        bool find = false;
        for(int i=0; i<livraria.size() and !find; i++){
            if(livraria[i].getnomeLivro()==a.getnomeLivro())
                find = true;
        }
        if(!find)
            inserirLivro(a);

    }
    file.close();
    return true;
}

bool compararPorValor(Livro a, Livro b){
    return a.getValor()>b.getValor();
}
bool compararPorNome(Livro a, Livro b){
    return a.getnomeLivro().toUpper()<b.getnomeLivro().toUpper();
}

