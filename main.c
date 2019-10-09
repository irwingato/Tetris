/*
    Jogo interativo Tetris implementado em linguagem C para uso 
    no console (terminal de comandos)

    Para executar:
        > start programa.exe

    Autor: Irwing Seiji Ato
    Data: 28/08/2019

*/

#include "tetris.h"
#include "display.h"
#define DEBUG 1

/*
    Parte principal do programa, responsável por iniciar e 
    chamar as funções auxiliares.
*/
int main(){
    char matrix[ROWS][COLUMNS];
    Bloco tijolo;
    int keypressed=0;

    //posicao inicial do personagem
    tijolo.i = 0;
    tijolo.j = COLUMNS/2;
    tijolo.tipo = TIPO_I;
    tijolo.orientacao = ORIENTACAO_UP;
    tijolo.width = 1;
    tijolo.height = 4;
    //inicializando matriz
    init(matrix);

    //apagar o cursor da tela
    ShowConsoleCursor(0);
    system("cls");

    //animação do jogo
    while(keypressed != ESC){        
        gotoxy(0,0);

        #if DEBUG == 1
        printf("@ = (%d, %d)\n", tijolo.i, tijolo.j);
        #endif

        //posicionar o @ no meio da tela
        switch(tijolo.orientacao){
            case ORIENTACAO_UP:
                if(tijolo.i-3>=0) matrix[tijolo.i-3][tijolo.j] = PIXEL;
                if(tijolo.i-2>=0) matrix[tijolo.i-2][tijolo.j] = PIXEL;
                if(tijolo.i-1>=0) matrix[tijolo.i-1][tijolo.j] = PIXEL;
                matrix[tijolo.i][tijolo.j] = PIXEL;
                break;
        case ORIENTACAO_DOWN:
                if(tijolo.j-3 >=0) matrix[tijolo.i][tijolo.j-3] = PIXEL;
                if(tijolo.j-2 >=0) matrix[tijolo.i][tijolo.j-2] = PIXEL;
                if(tijolo.j-1 >=0) matrix[tijolo.i][tijolo.j-1] = PIXEL;
                matrix[tijolo.i][tijolo.j] = PIXEL;
                break;              
        case ORIENTACAO_LEFT:
            //Outra orientação de desenho
            break;
        }

        //mostro a matriz na tela
        printMatrix(matrix);
        switch(tijolo.orientacao){
            case ORIENTACAO_UP:
            //faça posição anterior do @ ser apagada
            if(tijolo.i-3>=0) matrix[tijolo.i-3][tijolo.j] = EMPTY;
            if(tijolo.i-2>=0) matrix[tijolo.i-2][tijolo.j] = EMPTY;
            if(tijolo.i-1>=0) matrix[tijolo.i-1][tijolo.j] = EMPTY;
            matrix[tijolo.i][tijolo.j] = EMPTY;

            if(tijolo.i < (ROWS-1)) tijolo.i++;
            break;
            case ORIENTACAO_LEFT:

            break;
        }
        //faço a posição da @ ir para a direita
        

        //lendo teclas
        keypressed = 0;         
        if(kbhit()) keypressed = getch();            
        if(keypressed==ARROWS) keypressed = getch();

        switch(keypressed){
            case TECLA_a:
            case TECLA_A:
            case LEFT: 
                if(tijolo.j > 0) tijolo.j--; //vai para esquerda
            break; 
            case TECLA_d:
            case TECLA_D:
            case RIGHT: 
                if(tijolo.j < (COLUMNS-1)) tijolo.j++; //vai para a direita 
            break; 
        }

    }

    system("pause");

    return 0;
}