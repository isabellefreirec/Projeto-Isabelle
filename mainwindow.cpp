#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionSalvar,SIGNAL(triggered()),this,SLOT(salvar()));
    connect(ui->actionCarregar,SIGNAL(triggered()),this,SLOT(carregar()));
}



void MainWindow::atualizarDados(){

    double mediaValor = livraria.getValor();
    double menorValor = livraria.getMenorValor();
    double maiorValor = livraria.getMaiorValor();

       ui->mediaValor->setText(QString::number(mediaValor));
       ui->menorValor->setText(QString::number(menorValor));
       ui->maiorValor->setText(QString::number(maiorValor));

}

void MainWindow::atualizarTabela()
{
    ui->tabela->clearContents();
    for(int i=0;i<livraria.size();i++){
    inserirLivroNaTabela(livraria[i],i);
    }
}

void MainWindow::inserirLivroNaTabela(Livro a, int linha){
    ui->tabela->setItem(linha,0,new QTableWidgetItem(a.getnomeLivro()));
    ui->tabela->setItem(linha,1,new QTableWidgetItem(QString::number(a.getValor())));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_cadastrar_clicked()
{

   Livro livro;
   if(ui->nomeLivro->text().size()>3 && ui->nomeLivro->text().size() != ui->nomeLivro->text().toDouble() && ui->valorLivro->text().toDouble()>0){
       livro.setnomeLivro(ui->nomeLivro->text());
       livro.setValor(ui->valorLivro->text().toDouble());

       for(int i=0; i<livraria.size();i++)
           if(livraria[i].getnomeLivro()==livro.getnomeLivro())
               return;

       int linha=ui->tabela->rowCount();
       ui->tabela->insertRow(linha);
       inserirLivroNaTabela(livro, linha);
   }


   livraria.inserirLivro(livro);
   atualizarDados();

   ui->nomeLivro->clear();
   ui->valorLivro->clear();
}



void MainWindow::on_ordenarNome_clicked()
{
 livraria.ordenarPorNome();
 atualizarTabela();

}

void MainWindow::on_ordenarValor_clicked()
{
    livraria.ordenarPorValor();
    atualizarTabela();
}

void MainWindow::salvar(){

    QString nomeArquivo = QFileDialog::getSaveFileName(this,"Lista de livro","","CSV(*csv)");
    livraria.salvarLivraria(nomeArquivo);
    ui->tabela->clearContents();

}

void MainWindow::carregar(){

    QString nomeArquivo = QFileDialog::getOpenFileName(this,"Lista de livro","","CSV(*csv)");
    livraria.carregarLivraria(nomeArquivo);

    ui->tabela->clearContents();

    for(int i=0;i<livraria.size();i++){
        if(ui->tabela->rowCount()<=i)
            ui->tabela->insertRow(i);
        inserirLivroNaTabela(livraria[i],i);
    }
}



