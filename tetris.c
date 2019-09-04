/*
    Jogo interativo Tetris implementado em linguagem C para uso 
    no console (terminal de comandos)

    Autor: Irwing Seiji Ato
    Data: 28/08/2019

*/

#include "tetris.h"

/*
    Inicializa a matriz principal com 'espaços vazios'
*/
void init(char matrix[ROWS][COLUMNS]){
    int i,j;

    for(i=0; i<ROWS; i++){
        for(j=0; j<COLUMNS; j++){
            matrix[i][j] = ' ';
        }
    }
}

/*
    Mostra o conteúdo da matriz principal na tela 
    do computador.
*/
void printMatrix(char matrix[ROWS][COLUMNS]){
    int i,j;

    for(j=0; j<COLUMNS+2; j++)
        {
            printf("*");
        }  

    printf("\n");

    //print do mapa
    for(i=0; i<ROWS; i++)
    {
        //print borda esquerda
        printf("*");
    

        //print mapa
        for(j=0; j<COLUMNS; j++)
        {
            printf("%c", matrix[i][j]);
        }

        //printf borda direita
        printf("*");
        printf("\n");
    }
        
        //print borda debaixo
    for(j=0; j<COLUMNS+2; j++)
        {
            printf("*");
        }
    }

    
