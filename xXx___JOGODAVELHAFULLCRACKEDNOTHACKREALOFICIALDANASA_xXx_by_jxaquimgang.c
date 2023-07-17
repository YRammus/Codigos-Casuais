

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int line, colum;
int trys = 0;
int positions[3][3];
int winO =0,  winX = 0;
int escolha = 3;
//Protótipos de função

telaDoJogo();
jogador1();
Computer();
WinCondition();
principal();



//Compiler version gcc  6.3.0
int main()  {
    int a = 2;
    char resp;
    srand(time(0));
    principal();
return 0;
}


principal(){
    int i;
    while(escolha > 1 || escolha < 0){
        printf("Quer ser o X[1] ou o O[0]?");
        scanf("%d", &escolha);
    }
    while(trys < 5) {
        jogador1();
        telaDoJogo();
        WinCondition();
        if (winO == 1){
            printf("\nVitória O!");
            break;
        }
        else if (winX == 1){
            printf("\nVitória X!");
            break;
        }
        Computer();
        telaDoJogo();
        WinCondition();
        if (winO == 1){
            printf("\nVitória O!");
            break;
        }
        else if (winX == 1){
            printf("\nVitória X!");
            break;
        }
        trys++;
    }
}
telaDoJogo() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (positions[i][j] == 1) {
                printf(" X ");
            }
            else if(positions[i][j]== 2) {
                    printf(" O ");
            }
            else {
                printf("   ");
            }
            if(j < 2) {
                printf ("|");
            }
        }
        if (i <2) {
            printf  ("\n-- -- -- --\n");
        }
    }
}
jogador1() {
    int j;
    bool i = false;
    while (i !=true){
        printf("\n In wich line do You want to put?");
        scanf("%d",&line);
       /* int line = (rand()  %3);
          int colum = (rand()  %3);*/
         printf("\n In wich column. do You want to put?");
        scanf ("%d",&colum);
        if (line > 2 || colum > 2) {
            printf("\n linha ou coluna inexistente");
        }
        else if(positions[line][colum] > 0) {
            printf("\nLugar ja ocupado");
        }
        else {
            if (escolha ==1){
                positions[line][colum] = 1;
                i= true;
            }
            else if(escolha ==0){
                positions[line][colum] = 2;{
                i= true;
                }
            }
        }    
    }
}
Computer() {
    int j;
    printf("\nMachine turn\n");
    bool i = false;
    while (i !=true){
        if (trys >= 4){
        printf("\nDRAW\n");
            break;}
        int randA = (rand()  %3);
        int randB = (rand()  %3);
        if(positions[randA][randB] != 1 && positions[randA][randB] !=2){
            if(escolha == 1){
                 positions[randA][randB] = 2;
                 i = true;
            }
            else if(escolha == 0){
                 positions[randA][randB] = 1;
                 i = true;
            }
        

        }
    }
}

WinCondition() {
    if (positions[0][1] == 1 && positions[0][2]==1 && positions[0][0]==1) {
        winX++;
        /*
        XXX
         
          
        */
    }
    else if( positions[1][1] == 1 && positions[2][2] == 1 && positions[0][0]==1) {
        winX++;
    }
 /* X
     X
      X
      */
    else if(positions[0][2] == 1 && positions[1][1]==1 && positions[2][0]==1) {
        winX++;
    } 
    /*      X
          X
        X
        */
    else if(positions[2][0] == 1 && positions[1][0]==1 && positions[0][0]==1) {
        winX++;
    }
        /*  X| |
            X| |
            X| |
             */
    else if(positions[2][1] == 1 && positions[2][2]==1 && positions[2][0]==1) {
        winX++;
    }
    else if(positions[1][1] == 1 && positions[1][2]==1 && positions[1][0]==1) {
        winX++;
    }//
    else if(positions[1][1] == 1 && positions[2][1]==1 && positions[0][1]==1) {
        winX++;
    }//
    else if(positions[0][2] == 1 && positions[1][2]==1 && positions[2][2]==1) {
        winX++;
    }


    if (positions[0][1] == 2 && positions[0][2]==2 && positions[0][0]==2) {
        winO++;
    }
    else if(positions[1][1] == 2 && positions[2][2] == 2 && positions[0][0]==2) {
        winO++;
    }

    else if(positions[0][2] == 2 && positions[1][1]==2 && positions[2][0]==2) {
        winO++;
    }
    else if(positions[2][0] == 2 && positions[1][0]==2 && positions[0][0]==2) {
        winO++;
    }
    else if(positions[2][1] == 2 && positions[2][2]==2 && positions[2][0]==2) {
        winO++;
    }
    else if(positions[1][1] == 2 && positions[1][2]==2 && positions[1][0]==2) {
        winO++;
    }
    else if(positions[0][1] == 2 && positions[1][1]==2 && positions[2][1]==2) {
        winO++;
    }
    else if(positions[0][2] == 2 && positions[1][2]==2 && positions[2][2]==2) {
        winO++;
    }

}
