/*
    Jogo interativo Tetris implementado em linguagem C para uso
    no console(terminal de comandos)

    Para executar:
        > start programa.exe
    
    Autor: Irwing Seiji Ato
    Data: 28/08/2019
    
*/

#include "tetris.h"

/*
    Parte principal do programa, responsável por iniciar e 
    chamar as funções auxiliares.
*/
int main(){
    char matrix[ROWS][COLUMNS];
    int posI, posJ;

    //posição inicial do personagem
    posI = ROWS/2;
    posJ =  COLUMNS/2;
    //Inicializando matriz
    init(matrix);

    while(1){
    system("cls");

    matrix[posI][posJ] = '@';    

    printMatrix(matrix);

    matrix[posI][posJ] = ' ';
    
    if(posJ < COLUMNS) posJ++;
   
    }
    system("pause");


    return 0;
}

