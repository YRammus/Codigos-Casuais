// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>

#include <time.h>

#include <math.h>

#include <string.h>



//Variaveis de escopo global

char answer;
bool negativo;


//prototipos de fun��es 
int pScreen();
int deciToBi(int dec);
int posiOrNegativo(int bi[32]);
int convToDeci(int bi[32]);
int posiOrNego(int dec);


int main() {
    srand(time(0));
//variaveis principais
int d = 17;
//rand()%255;
int vet[32] = {1, 0, 1, 1, 1, 0, 1, 0};
//{rand()%2, rand()%2, rand()%2, rand()%2, rand()%2, rand()%2, rand()%2, rand()%2};

pScreen(answer);
if (answer == 'd'){
   // scanf("%d", &d);
    posiOrNego(d);
    printf("that\'s an example with the number: %d \n", d);
    d = abs(d);
    deciToBi(d);
}
else if (answer == 'b'){
    posiOrNegativo(vet);
    convToDeci(vet);
	if(negativo == false){
        printf("\nit\'s a positive number");
    }
    else {
	    printf("\nIt\'s a negative number.");
      }
    
}

return 0;
}

//fun��o para checar se � positivo ou negativo
int posiOrNegativo(int bi[32]){
        if (bi[0] == 1){
            // entao o numero ser� negativo
            negativo = true;
        }
        else if (bi[0] == 0){
            negativo = false;
        }
        else {
            printf("invalid number, please, use binary\n");
        }
}

//fun��o que inverte os binarios e converte
int convToDeci(int bi[32]){
 int i;
 int j = 7;
 int sum = 0;
 int multiply[32] = {128, 64, 32, 16, 8, 4,  2, 1};
 /*
        //coluna   0  1  2  3   4   5    6   7

 int multiply[8] = {1, 2, 4, 8, 16, 32,  64, 128};
*/
 
         //coluna   0  1  2  3   4   5    6   7
for (i = 0; i<8; i++){
    printf("%d", bi[i]);
}

for (i = 7; i >= 0; i--){
        if (bi[i] == 0){
            bi[i] = 1;
        }
     	else if (bi[i] == 1){
            bi[i]= 0;
        }
    }
for (i = 7; i>0; i--){
    
        if(bi[i] == 1)   {
            bi[i] = 0;
            
        }
    else if(bi[i]== 0){
        bi[i] = 1;
        break;
    }
}
for (i = 7; i>0; i--){
    
        if(bi[i] == 1)   {
            sum += multiply[i];
        }
    else if(bi[i]== 0){
        continue;
    }
}
printf(", and it\'s decimal is: %d", sum);
printf("\n");
}
 //se o numero for 0, ele pula pra proxima interacao do FOR 
 //e se ele for 1, a variavel soma vai receber um valor de acordo 
 //com a posicao atual
 


//fun��o para converter decimais em bi 
int deciToBi(int dec){
    int i, j;
    int bi, ba = 0, vetbi[32];
    ba = dec;
    for (i = 0; i < 8; i++){
        bi = ba%2;
        ba = ba/2;
        if(bi == 1){
            vetbi[i] = 1;
        }
        else{
            vetbi[i] = 0;
        }
    }
  
if(negativo == true){
    for(j = 0; j < 8; j++){
        if(vetbi[j] == 1){
            vetbi[j] = 0;
        }
        else{
        vetbi[j] = 1;
        }
        
    }
    vetbi[0] = 1;
    }

else{
vetbi[7] = 0;
}
  for(i = 7; i >= 0; i--){
        printf("%d", vetbi[i]);
    }
}
// verifica se � positivo ou negativo
int posiOrNego(int dec){
    if(dec < 0){
       // n = abs(dec);
        negativo = true;
    }
    else{
        negativo = false;
    }
    
}


int pScreen(){
    printf("Hello, welcome to the binary and decimal converter. \n");
    printf("What example do you want to see?");
    printf("\nconverting a decimal[d] or a binary[b]?");
    scanf("%c", &answer);
}



