#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<bits/stdc++.h>
#include<QPixmap>
#include<QLabel>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pic.load("C:/Users/pc/Documents/TowerOfHanoi/untitled2.png");
    pic1.load("C:/Users/pc/Documents/TowerOfHanoi/untitled3.png");
    pic2.load("C:/Users/pc/Documents/TowerOfHanoi/untitled4.png");
    pic3.load("C:/Users/pc/Desktop/Assignment #3(ID-20180285)(G-14)/Tower of hanoi/TowerOfHanoi Game/untitled5.png");
    MoveNumber=0;
}

void MainWindow::MoveTower(int n, char start, char finish, char temp){
     if (n == 1)
        MoveSingleDisk(start, finish);
     else {
          MoveTower(n - 1, start, temp, finish);
          MoveSingleDisk(start, finish);
          MoveTower(n - 1, temp, finish, start);
     }
}

void MainWindow::MoveSingleDisk(char start, char finish) {
    Move.push_back(make_pair(start,finish));
}

MainWindow::~MainWindow()
{
    delete ui;
}

char* StringtoChArray(string& s){
    char* s2=new char[s.size()+1];
    for(int i=0;i<(int)s.size();i++)
        s2[i]=s[i];
    s2[s.size()]='\0';
    return s2;
}

void MainWindow::moveRock(char start,char end){
    if(start=='A'){
        RemovedData=A.back();
        A.pop_back();
    }else if(start=='B'){
        RemovedData=B.back();
        B.pop_back();
    }else if(start=='C'){
        RemovedData=C.back();
        C.pop_back();
    }

    if(end=='A')
        A.push_back(RemovedData);
    else if(end=='B')
        B.push_back(RemovedData);
    else if(end=='C')
        C.push_back(RemovedData);

}


void MainWindow::UpdateGUI(){
    if(A.size()>=2)
            ui->label3->setPixmap(QPixmap(StringtoChArray(A[1])));
    else ui->label3->setPixmap(QPixmap(""));
    if(A.size()>=3)
        ui->label2->setPixmap(QPixmap(StringtoChArray(A[2])));
    else ui->label2->setPixmap(QPixmap(""));
    if(A.size()>=4)
        ui->label1->setPixmap(QPixmap(StringtoChArray(A[3])));
    else ui->label1->setPixmap(QPixmap(""));
    if(A.size()>=1)
        ui->label4->setPixmap(QPixmap(StringtoChArray(A[0])));
    else ui->label4->setPixmap(QPixmap(""));
    if(B.size()>=2)
        ui->label3_2->setPixmap(QPixmap(StringtoChArray(B[1])));
    else ui->label3_2->setPixmap(QPixmap(""));
    if(B.size()>=3)
        ui->label2_2->setPixmap(QPixmap(StringtoChArray(B[2])));
    else ui->label2_2->setPixmap(QPixmap(""));
    if(B.size()>=4)
        ui->label1_2->setPixmap(QPixmap(StringtoChArray(B[3])));
    else ui->label1_2->setPixmap(QPixmap(""));
    if(B.size()>=1)
        ui->label4_2->setPixmap(QPixmap(StringtoChArray(B[0])));
    else ui->label4_2->setPixmap(QPixmap(""));
    if(C.size()>=2)
        ui->label3_3->setPixmap(QPixmap(StringtoChArray(C[1])));
    else ui->label3_3->setPixmap(QPixmap(""));
    if(C.size()>=3)
        ui->label2_3->setPixmap(QPixmap(StringtoChArray(C[2])));
    else ui->label2_3->setPixmap(QPixmap(""));
    if(C.size()>=4)
        ui->label1_3->setPixmap(QPixmap(StringtoChArray(C[3])));
    else ui->label1_3->setPixmap(QPixmap(""));
    if(C.size()>=1)
        ui->label4_3->setPixmap(QPixmap(StringtoChArray(C[0])));
    else ui->label4_3->setPixmap(QPixmap(""));
}
void MainWindow::on_pushButton_clicked()
{
    if(MoveNumber<(int)Move.size()){
        moveRock(Move[MoveNumber].first,Move[MoveNumber].second);
        MoveNumber++;
    }
    UpdateGUI();
}

void MainWindow::on_action1_2_triggered()
{
    MoveNumber=0;
    Move.clear();
    MoveTower(1, 'A', 'C', 'B');

    A.clear();
    B.clear();
    C.clear();
    A.push_back("C:/Users/pc/Documents/TowerOfHanoi/untitled4.png");
    UpdateGUI();
}

void MainWindow::on_action2_2_triggered()
{
    MoveNumber=0;
    Move.clear();
    MoveTower(2, 'A', 'C', 'B');

    A.clear();
    B.clear();
    C.clear();
    A.push_back("C:/Users/pc/Documents/TowerOfHanoi/untitled4.png");
    A.push_back("C:/Users/pc/Documents/TowerOfHanoi/untitled3.png");
    UpdateGUI();
}

void MainWindow::on_action3_2_triggered()
{
    MoveNumber=0;
    Move.clear();
    MoveTower(3, 'A', 'C', 'B');
    A.clear();
    B.clear();
    C.clear();
    A.push_back("C:/Users/pc/Documents/TowerOfHanoi/untitled4.png");
    A.push_back("C:/Users/pc/Documents/TowerOfHanoi/untitled3.png");
    A.push_back("C:/Users/pc/Documents/TowerOfHanoi/untitled2.png");
    UpdateGUI();
}

void MainWindow::on_action4_triggered()
{
    MoveNumber=0;
    Move.clear();
    MoveTower(4, 'A', 'C', 'B');
    A.clear();
    B.clear();
    C.clear();
    A.push_back("C:/Users/pc/Documents/TowerOfHanoi/untitled4.png");
    A.push_back("C:/Users/pc/Documents/TowerOfHanoi/untitled3.png");
    A.push_back("C:/Users/pc/Documents/TowerOfHanoi/untitled2.png");
    A.push_back("C:/Users/pc/Desktop/Assignment #3(ID-20180285)(G-14)/Tower of hanoi/TowerOfHanoi Game/untitled5.png");
    UpdateGUI();
}
