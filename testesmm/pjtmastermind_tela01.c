#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(){
    system("color 2");

    int cont = 1;
    while (cont = 1){

        random_full();
        printf("\n");  

        getchar();

    }

}


int random_no_repeat(){

    int i = 0, j, vet[8], igual;

    srand(time(NULL));

    do{
        vet[i] = rand()%8;
        igual = 0;
        for (j = 0; j < i; j++){
            if (vet[j] == vet[i]){
                igual = 1;
            }
        }
            
        if (igual == 0){
            i++;
        }
        
    } while(i < 8);

    for (i = 0; i < 8; i++){
        printf("%d ", vet[i]);
    }
}

int random_full(){
    
    int i = 0;
    srand(time(NULL));  

    for (i = 0; i < 8; i++){
    printf("%d ", rand()%10);
    }

}
