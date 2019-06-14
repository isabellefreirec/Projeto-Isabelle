#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "livro.h"
#include "livraria.h"
#include <QMainWindow>
#include <QVector>
#include <QDebug>
#include <QFileDialog>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Livraria livraria;
    void atualizarDados();
    void atualizarTabela();
    void inserirLivroNaTabela(Livro a, int linha);
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_cadastrar_clicked();

    void on_ordenarNome_clicked();

    void on_ordenarValor_clicked();

    void salvar();

    void carregar();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
