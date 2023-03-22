#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Field.h"
#include <QPainter>
#include <QApplication>
#include <QWidget>

MainWindow::MainWindow( QWidget *parent )
    : QWidget (parent) , ui(new Ui::MainWindow) {
    ui->setupUi(this);


    // loadFloors
    const int boardHeight = 10;
    const int boardWidth = 10;
    Field fields[ boardHeight * boardWidth ];

}

MainWindow::~MainWindow()
{
    delete ui;
}

