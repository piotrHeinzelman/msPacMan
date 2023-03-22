#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Field.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // loadFloors
    const int boardHeight = 10;
    const int boardWidth = 10;

    Field* f1 = new Field();
    Field* f2 = new Field();
    f1->setNeighbour( N, f2 );
    f2->setNeighbour( S, f1 );



}

MainWindow::~MainWindow()
{
    delete ui;
}

