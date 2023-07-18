#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define TAM 150

int menu(); int instruc(); int jogar(); int config(); int endscreen(int ptsj1, int ptsj2);

int main(){

    int cont = 1, sel, selmodo, optipogame, dificuldade;
    system("color 6");
    while (cont == 1){
        menu();
        scanf("%i", &sel);

        if (sel == 0){
            break;
        }
        else if (sel == 2){
            instruc();
        }
        else if (sel == 1){
            jogar();

            printf("\n> ");
            scanf("%i", &optipogame);

            if (optipogame == 0){
                menu();
            }
            else if(optipogame == 2){                   //CONTRA COMPUTADOR//
                config();
                scanf("%i", &dificuldade);
                if (dificuldade == 1){                  //DIFICULDADE FÁCIL

                    system("cls");

                    int jogatinas, forabug, rodada = 0, repeticao;
                    char jogador[10];
                    printf("\n\n\t\tInsira seu nome, jogador: ");
                    scanf("%s", &jogador);

                    PLAYAGAIN:                          //GOTO - IR PARA
                    rodada = 0;
                    system("cls");
                    printf("\n\t\t    BEM VINDO, %s!", jogador);
                    printf("\n\t Quantas vezes o MasterMind sera jogado?\n\tInsira a quantidade de vezes que voce quer jogar: ");
                    scanf("%d", &jogatinas);
                    forabug = jogatinas;

                    system("cls");
                    printf("\n\n\t%s, a senha tera numeros repetidos? \n", jogador);
                    printf("\n\n| Aperte 1 para NAO repetir os numeros da senha |");
                    printf("\n\n|   Aperte 2 para REPETIR os numeros da senha   |");
                    printf("\n\n> ");
                    scanf("%d", &repeticao);


                    int l = 0, matriz[TAM][TAM], pontuacao = 10, ptotal = 0;
                    int i = 0, j, vet[TAM], igual;

                    if (repeticao == 1 || repeticao == 2){

                        for(int o = 0; o < jogatinas; o++){

                            srand(time(NULL));              //GERA OS NÚMEROS ALEATÓRIOS COM BASE NO HORÁRIO DO PC

                            if(repeticao == 1){

                            i = 0;
                                do{                             //VERIFICA SE HÁ ALGUM NÚMERO REPETIDO E ARMAZENA APENAS NÚMEROS SEM REPETIÇÃO
                                    vet[i] = rand()%7;
                                    igual = 0;
                                    for (j = 0; j < i; j++){
                                        if (vet[j] == vet[i]){
                                            igual = 1;
                                        }
                                    }

                                    if (igual == 0){
                                        i++;
                                    }

                                } while(i < 4);
                            }

                            if(repeticao == 2){

                                i = 0;

                                vet[0] = rand()%7;
                                vet[1] = rand()%7;
                                vet[2] = rand()%7;
                                vet[3] = rand()%7;
                            }


                            while (l < jogatinas){
                                system("cls");

                                    // for (i = 0; i < 4; i++){
                                    // printf("%d ", vet[i]);
                                    // }

                                printf("\n\n\t\t\t%s, voce jogara por %d rodadas!", jogador, forabug);
                                rodada++;
                                printf("\n\t\t\t            Rodada %d", rodada);
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || - - - - ||         |\n");
                                printf("        || - - - - ||         |\n");
                                printf("        || - - - - ||         |\n");
                                printf("        || - - - - ||         |\n");
                                printf("        || - - - - ||         |\t\tSEJA BEM-VINDO!\n");
                                printf("        || - - - - ||         |\t\tMASTERMIND GAME\n");
                                printf("        || - - - - ||         |\n");
                                printf("        || - - - - ||         |\n");
                                printf("        || - - - - ||         |\n");

                                printf("\n\ndigite a combinacao:  ");
                                scanf("%i%i%i%i",&matriz[10][0],&matriz[10][1],&matriz[10][2],&matriz[10][3]);

                                if (vet[0] == matriz[10][0] && vet[1] == matriz[10][1] && vet[2] == matriz[10][2] && vet[3] == matriz[10][3]){
                                    printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    ptotal = ptotal + pontuacao;
                                    system("pause");
                                    pontuacao = 10;
                                    break;
                                }

                                int aux3[TAM], b[TAM],p[TAM], veta[TAM];

                                    b[0]=0;
                                    p[0]=0;

                                    for(int i=0; i<4; i++){
                                    veta[i]=0;
                                    aux3[i]=0;
                                    }

                                    for(int i=0; i<4; i++){
                                        if(matriz[10][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[0]++;
                                        }
                                    }
                                    for(int i=0; i<4; i++){
                                        for(int j=0; j<4; j++){
                                            if(matriz[10][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[0]++;
                                            }
                                        }
                                    }

                                system("cls");
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || - - - - ||         |\n");
                                printf("        || - - - - ||         |\n");
                                printf("        || - - - - ||         |\t\t %d = BRANCO.\n", b[0]);
                                printf("        || - - - - ||         |\t\t %d = PRETO.\n", p[0]);
                                printf("        || - - - - ||         |\n");
                                printf("        || - - - - ||         |\n");
                                printf("        || - - - - ||         |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n");
                                printf("        || - - - - ||         |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n");
                                printf("        || - - - - ||         |\n");
                                printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],b[0],p[0]);

                                printf("\n\ndigite a combinacao:  ");
                                scanf("%i%i%i%i",&matriz[9][0],&matriz[9][1],&matriz[9][2],&matriz[9][3]);
                                pontuacao--;

                                if (vet[0] == matriz[9][0] && vet[1] == matriz[9][1] && vet[2] == matriz[9][2] && vet[3] == matriz[9][3]){
                                    printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    ptotal = ptotal + pontuacao;
                                    system("pause");
                                    pontuacao = 10;
                                    break;
                                }

                                    b[1]=0;
                                    p[1]=0;

                                    for(int i=0; i<4; i++){
                                    veta[i]=0;
                                    aux3[i]=0;
                                    }

                                    for(int i=0; i<4; i++){
                                        if(matriz[9][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[1]++;
                                        }
                                    }
                                    for(int i=0; i<4; i++){
                                        for(int j=0; j<4; j++){
                                            if(matriz[9][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[1]++;
                                            }
                                        }
                                    }

                                system("cls");
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || - - - - ||         |\n");
                                printf("        || - - - - ||         |\n");
                                printf("        || - - - - ||         |\t\t %d = BRANCO.\n", b[1]);
                                printf("        || - - - - ||         |\t\t %d = PRETO.\n", p[1]);
                                printf("        || - - - - ||         |\n");
                                printf("        || - - - - ||         |\n");
                                printf("        || - - - - ||         |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n");
                                printf("        || - - - - ||         |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n");
                                printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],b[1],p[1]);
                                printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],b[0],p[0]);

                                printf("\n\ndigite a combinacao:  ");
                                scanf("%i%i%i%i",&matriz[8][0],&matriz[8][1],&matriz[8][2],&matriz[8][3]);
                                pontuacao--;

                                if (vet[0] == matriz[8][0] && vet[1] == matriz[8][1] && vet[2] == matriz[8][2] && vet[3] == matriz[8][3]){
                                    printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    ptotal = ptotal + pontuacao;
                                    system("pause");
                                    pontuacao = 10;
                                    break;
                                }

                                    b[2]=0;
                                    p[2]=0;

                                    for(int i=0; i<4; i++){
                                    veta[i]=0;
                                    aux3[i]=0;
                                }

                                for(int i=0; i<4; i++){
                                        if(matriz[8][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[2]++;
                                        }
                                    }
                                    for(int i=0; i<4; i++){
                                        for(int j=0; j<4; j++){
                                            if(matriz[8][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[2]++;
                                            }
                                        }
                                    }

                                system("cls");
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || - - - - ||         |\n");
                                printf("        || - - - - ||         |\n");
                                printf("        || - - - - ||         |\t\t %d = BRANCO.\n", b[2]);
                                printf("        || - - - - ||         |\t\t %d = PRETO.\n", p[2]);
                                printf("        || - - - - ||         |\n");
                                printf("        || - - - - ||         |\n");
                                printf("        || - - - - ||         |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n");
                                printf("        || %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],b[2],p[2]);
                                printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],b[1],p[1]);
                                printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],b[0],p[0]);

                                printf("\n\ndigite a combinacao:  ");
                                scanf("%i%i%i%i",&matriz[7][0],&matriz[7][1],&matriz[7][2],&matriz[7][3]);
                                pontuacao--;

                                if (vet[0] == matriz[7][0] && vet[1] == matriz[7][1] && vet[2] == matriz[7][2] && vet[3] == matriz[7][3]){
                                    printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    ptotal = ptotal + pontuacao;
                                    system("pause");
                                    pontuacao = 10;
                                    break;
                                }

                                    b[3]=0;
                                    p[3]=0;

                                for(int i=0; i<4; i++){
                                    veta[i]=0;
                                    aux3[i]=0;
                                }


                                for(int i=0; i<4; i++){
                                        if(matriz[7][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[3]++;
                                        }
                                    }
                                    for(int i=0; i<4; i++){
                                        for(int j=0; j<4; j++){
                                            if(matriz[7][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[3]++;
                                            }
                                        }
                                    }

                                system("cls");
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || - - - - ||         |\n");
                                printf("        || - - - - ||         |\n");
                                printf("        || - - - - ||         |\t\t %d = BRANCO.\n", b[3]);
                                printf("        || - - - - ||         |\t\t %d = PRETO.\n", p[3]);
                                printf("        || - - - - ||         |\n");
                                printf("        || - - - - ||         |\n");
                                printf("        || %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],b[3],p[3]);
                                printf("        || %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],b[2],p[2]);
                                printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],b[1],p[1]);
                                printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],b[0],p[0]);

                                printf("\n\ndigite a combinacao:  ");
                                scanf("%i%i%i%i",&matriz[6][0],&matriz[6][1],&matriz[6][2],&matriz[6][3]);
                                pontuacao--;

                                if (vet[0] == matriz[6][0] && vet[1] == matriz[6][1] && vet[2] == matriz[6][2] && vet[3] == matriz[6][3]){
                                    printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    ptotal = ptotal + pontuacao;
                                    system("pause");
                                    pontuacao = 10;
                                    break;
                                }

                                    b[4]=0;
                                    p[4]=0;

                                    for(int i=0; i<4; i++){
                                    veta[i]=0;
                                    aux3[i]=0;
                                }

                                for(int i=0; i<4; i++){
                                        if(matriz[6][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[4]++;
                                        }
                                    }
                                    for(int i=0; i<4; i++){
                                        for(int j=0; j<4; j++){
                                            if(matriz[6][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[4]++;
                                            }
                                        }
                                    }

                                system("cls");
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || - - - - ||         |\n");
                                printf("        || - - - - ||         |\n");
                                printf("        || - - - - ||         |\t\t %d = BRANCO.\n", b[4]);
                                printf("        || - - - - ||         |\t\t %d = PRETO.\n", p[4]);
                                printf("        || - - - - ||         |\n");
                                printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[6][0],matriz[6][1],matriz[6][2],matriz[6][3],b[4],p[4]);
                                printf("        || %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],b[3],p[3]);
                                printf("        || %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],b[2],p[2]);
                                printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],b[1],p[1]);
                                printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],b[0],p[0]);

                                printf("\n\ndigite a combinacao:  ");
                                scanf("%i%i%i%i",&matriz[5][0],&matriz[5][1],&matriz[5][2],&matriz[5][3]);
                                pontuacao--;

                                if (vet[0] == matriz[5][0] && vet[1] == matriz[5][1] && vet[2] == matriz[5][2] && vet[3] == matriz[5][3]){
                                    printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    ptotal = ptotal + pontuacao;
                                    system("pause");
                                    pontuacao = 10;
                                    break;
                                }

                                    b[5]=0;
                                    p[5]=0;


                                    for(int i=0; i<4; i++){
                                    veta[i]=0;
                                    aux3[i]=0;
                                }



                                for(int i=0; i<4; i++){
                                        if(matriz[5][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[5]++;
                                        }
                                    }
                                    for(int i=0; i<4; i++){
                                        for(int j=0; j<4; j++){
                                            if(matriz[5][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[5]++;
                                            }
                                        }
                                    }

                                system("cls");
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || - - - - ||         |\n");
                                printf("        || - - - - ||         |\n");
                                printf("        || - - - - ||         |\t\t %d = BRANCO.\n", b[5]);
                                printf("        || - - - - ||         |\t\t %d = PRETO.\n", p[5]);
                                printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[5][0],matriz[5][1],matriz[5][2],matriz[5][3],b[5],p[5]);
                                printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[6][0],matriz[6][1],matriz[6][2],matriz[6][3],b[4],p[4]);
                                printf("        || %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],b[3],p[3]);
                                printf("        || %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],b[2],p[2]);
                                printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],b[1],p[1]);
                                printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],b[0],p[0]);

                                printf("\n\ndigite a combinacao:  ");
                                scanf("%i%i%i%i",&matriz[4][0],&matriz[4][1],&matriz[4][2],&matriz[4][3]);
                                pontuacao--;

                                if (vet[0] == matriz[4][0] && vet[1] == matriz[4][1] && vet[2] == matriz[4][2] && vet[3] == matriz[4][3]){
                                    printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    ptotal = ptotal + pontuacao;
                                    system("pause");
                                    pontuacao = 10;
                                    break;
                                }


                                    b[6]=0;
                                    p[6]=0;

                                    for(int i=0; i<4; i++){
                                    veta[i]=0;
                                    aux3[i]=0;
                                }

                                for(int i=0; i<4; i++){
                                        if(matriz[4][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[6]++;
                                        }
                                    }
                                    for(int i=0; i<4; i++){
                                        for(int j=0; j<4; j++){
                                            if(matriz[4][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[6]++;
                                            }
                                        }
                                    }

                                system("cls");
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || - - - - ||         |\n");
                                printf("        || - - - - ||         |\n");
                                printf("        || - - - - ||         |\t\t %d = BRANCO.\n", b[6]);
                                printf("        || %i %i %i %i || B:%i P:%i |\t\t %d = PRETO.\n",matriz[4][0],matriz[4][1],matriz[4][2],matriz[4][3],b[6],p[6], p[6]);
                                printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[5][0],matriz[5][1],matriz[5][2],matriz[5][3],b[5],p[5]);
                                printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[6][0],matriz[6][1],matriz[6][2],matriz[6][3],b[4],p[4]);
                                printf("        || %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],b[3],p[3]);
                                printf("        || %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],b[2],p[2]);
                                printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],b[1],p[1]);
                                printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],b[0],p[0]);

                                printf("\n\ndigite a combinacao:  ");
                                scanf("%i%i%i%i",&matriz[3][0],&matriz[3][1],&matriz[3][2],&matriz[3][3]);
                                pontuacao--;

                                if (vet[0] == matriz[3][0] && vet[1] == matriz[3][1] && vet[2] == matriz[3][2] && vet[3] == matriz[3][3]){
                                    printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    ptotal = ptotal + pontuacao;
                                    system("pause");
                                    pontuacao = 10;
                                    break;
                                }

                                    b[7]=0;
                                    p[7]=0;

                                    for(int i=0; i<4; i++){
                                    veta[i]=0;
                                    aux3[i]=0;
                                }

                                for(int i=0; i<4; i++){
                                        if(matriz[3][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[7]++;
                                        }
                                    }
                                    for(int i=0; i<4; i++){
                                        for(int j=0; j<4; j++){
                                            if(matriz[3][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[7]++;
                                            }
                                        }
                                    }

                                system("cls");
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || - - - - ||         |\n");
                                printf("        || - - - - ||         |\n");
                                printf("        || %i %i %i %i || B:%i P:%i |\t\t %d = BRANCO.\n",matriz[3][0],matriz[3][1],matriz[3][2],matriz[3][3],b[7],p[7],b[7]);
                                printf("        || %i %i %i %i || B:%i P:%i |\t\t %d = PRETO.\n",matriz[4][0],matriz[4][1],matriz[4][2],matriz[4][3],b[6],p[6], p[7]);
                                printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[5][0],matriz[5][1],matriz[5][2],matriz[5][3],b[5],p[5]);
                                printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[6][0],matriz[6][1],matriz[6][2],matriz[6][3],b[4],p[4]);
                                printf("        || %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],b[3],p[3]);
                                printf("        || %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],b[2],p[2]);
                                printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],b[1],p[1]);
                                printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],b[0],p[0]);

                                printf("\n\ndigite a combinacao:  ");
                                scanf("%i%i%i%i",&matriz[2][0],&matriz[2][1],&matriz[2][2],&matriz[2][3]);
                                pontuacao--;

                                if (vet[0] == matriz[2][0] && vet[1] == matriz[2][1] && vet[2] == matriz[2][2] && vet[3] == matriz[2][3]){
                                    printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    ptotal = ptotal + pontuacao;
                                    system("pause");
                                    pontuacao = 10;
                                    break;
                                }

                                    b[8]=0;
                                    p[8]=0;

                                    for(int i=0; i<4; i++){
                                    veta[i]=0;
                                    aux3[i]=0;
                                }

                                for(int i=0; i<4; i++){
                                        if(matriz[2][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[8]++;
                                        }
                                    }
                                    for(int i=0; i<4; i++){
                                        for(int j=0; j<4; j++){
                                            if(matriz[2][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[8]++;
                                            }
                                        }
                                    }

                                system("cls");
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || - - - - ||         |\n");
                                printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[2][0],matriz[2][1],matriz[2][2],matriz[2][3],b[8],p[8]);
                                printf("        || %i %i %i %i || B:%i P:%i |\t\t %d = BRANCO.\n",matriz[3][0],matriz[3][1],matriz[3][2],matriz[3][3],b[7],p[7], b[8]);
                                printf("        || %i %i %i %i || B:%i P:%i |\t\t %d = PRETO.\n",matriz[4][0],matriz[4][1],matriz[4][2],matriz[4][3],b[6],p[6],p[8]);
                                printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[5][0],matriz[5][1],matriz[5][2],matriz[5][3],b[5],p[5]);
                                printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[6][0],matriz[6][1],matriz[6][2],matriz[6][3],b[4],p[4]);
                                printf("        || %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],b[3],p[3]);
                                printf("        || %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],b[2],p[2]);
                                printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],b[1],p[1]);
                                printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],b[0],p[0]);

                                printf("\n\ndigite a combinacao:  ");
                                scanf("%i%i%i%i",&matriz[1][0],&matriz[1][1],&matriz[1][2],&matriz[1][3]);
                                pontuacao--;

                                if (vet[0] == matriz[1][0] && vet[1] == matriz[1][1] && vet[2] == matriz[1][2] && vet[3] == matriz[1][3]){
                                    printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    ptotal = ptotal + pontuacao;
                                    system("pause");
                                    pontuacao = 10;
                                    break;
                                }

                                    b[9]=0;
                                    p[9]=0;

                                    for(int i=0; i<4; i++){
                                    veta[i]=0;
                                    aux3[i]=0;
                                }

                                for(int i=0; i<4; i++){
                                        if(matriz[1][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[9]++;
                                        }
                                    }
                                    for(int i=0; i<4; i++){
                                        for(int j=0; j<4; j++){
                                            if(matriz[1][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[9]++;
                                            }
                                        }
                                    }

                                system("cls");
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[1][0],matriz[1][1],matriz[1][2],matriz[1][3],b[9],p[9]);
                                printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[2][0],matriz[2][1],matriz[2][2],matriz[2][3],b[8],p[8]);
                                printf("        || %i %i %i %i || B:%i P:%i |\t\t %d = BRANCO.\n",matriz[3][0],matriz[3][1],matriz[3][2],matriz[3][3],b[7],p[7], b[9]);
                                printf("        || %i %i %i %i || B:%i P:%i |\t\t %d = PRETO.\n",matriz[4][0],matriz[4][1],matriz[4][2],matriz[4][3],b[6],p[6], p[9]);
                                printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[5][0],matriz[5][1],matriz[5][2],matriz[5][3],b[5],p[5]);
                                printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[6][0],matriz[6][1],matriz[6][2],matriz[6][3],b[4],p[4]);
                                printf("        || %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],b[3],p[3]);
                                printf("        || %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],b[2],p[2]);
                                printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],b[1],p[1]);
                                printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],b[0],p[0]);


                                printf("\n\n\t\t\tGAME OVER!\n\n");
                                printf("\t       A senha gerada foi:  ");

                                for (i = 0; i < 4; i++){
                                printf("%d ", vet[i]);
                                }

                                printf("\n\n");

                                pontuacao--;

                                printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                printf("\n\n");
                                getchar();
                                ptotal = ptotal + pontuacao;
                                pontuacao = 10;

                                l++;
                                system("pause");
                                break;
                            }

                            if (jogatinas == rodada){
                                int replay;
                                system("cls");
                                printf("\n\n");
                                printf("\t\t\t\t  FIM DE JOGO!\n\t\t\t       OBRIGADO POR JOGAR!\n");
                                printf("\n\n\t\t\tA pontuacao total eh %d pontos!\n\n", ptotal);

                                printf("\t\t\t     Deseja jogar novamente? ");
                                ALTERRADA:
                                printf("\n\n\n| Aperte 1 para jogar novamente |\n\n| Aperte 0 para voltar ao menu  |\n\n");
                                printf("> ");
                                scanf("%d", &replay);

                                if (replay == 1){
                                    rodada = 1;
                                    goto PLAYAGAIN;
                                }
                                else if (replay == 0){
                                    menu();
                                }
                                else if (replay != 0 || replay != 1){
                                    system("cls");
                                    printf("\n\n\t\t\tDigite uma alternativa valida!");
                                    goto ALTERRADA;
                                }
                            }
                        }
                    }
                }
                else if (dificuldade == 2){             //DIFICULDADE MÉDIA
                    
                    system("cls");

                    int jogatinas, forabug, rodada = 0, repeticao;
                    char jogador[10];
                    printf("\n\n\t\tInsira seu nome, jogador: ");
                    scanf("%s", &jogador);

                    PLAYAGAINDIF2:                          
                    rodada = 0;
                    system("cls");
                    printf("\n\t\t    BEM VINDO, %s!", jogador);
                    printf("\n\t Quantas vezes o MasterMind sera jogado?\n\tInsira a quantidade de vezes que voce quer jogar: ");
                    scanf("%d", &jogatinas);
                    forabug = jogatinas;

                    system("cls");
                    printf("\n\n\t%s, a senha tera numeros repetidos? \n", jogador);
                    printf("\n\n| Aperte 1 para NAO repetir os numeros da senha |");
                    printf("\n\n|   Aperte 2 para REPETIR os numeros da senha   |");
                    printf("\n\n> ");
                    scanf("%d", &repeticao);


                    int l = 0, matriz[TAM][TAM], pontuacao = 12, ptotal = 0;
                    int i = 0, j, vet[TAM], igual;

                    if (repeticao == 1 || repeticao == 2){

                        for(int o = 0; o < jogatinas; o++){

                            srand(time(NULL));              

                            if(repeticao == 1){

                                i = 0;
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

                                } while(i < 5);
                            }

                            if(repeticao == 2){

                                i = 0;

                                vet[0] = rand()%8;
                                vet[1] = rand()%8;
                                vet[2] = rand()%8;
                                vet[3] = rand()%8;
                                vet[4] = rand()%8;
                            }


                            while (l < jogatinas){
                                system("cls");

                                    // for (i = 0; i < 5; i++){
                                    // printf("%d ", vet[i]);
                                    // }

                                printf("\n\n\t\t\t%s, voce jogara por %d rodadas!", jogador, forabug);
                                rodada++;
                                printf("\n\t\t\t            Rodada %d", rodada);
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\t\tSEJA BEM-VINDO!\n");
                                printf("        || - - - - - ||         |\t\tMASTERMIND GAME\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");

                                printf("\n\ndigite a combinacao:  ");
                                scanf("%i%i%i%i%i",&matriz[12][0],&matriz[12][1],&matriz[12][2],&matriz[12][3],&matriz[12][4]);

                                if (vet[0] == matriz[12][0] && vet[1] == matriz[12][1] && vet[2] == matriz[12][2] && vet[3] == matriz[12][3] && vet[4] == matriz[12][4]){
                                    printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    ptotal = ptotal + pontuacao;
                                    system("pause");
                                    pontuacao = 12;
                                    break;
                                }

                                int aux3[TAM], b[TAM],p[TAM], veta[TAM];

                                    b[0]=0;
                                    p[0]=0;

                                    for(int i=0; i<5; i++){
                                    veta[i]=0;
                                    aux3[i]=0;
                                    }

                                    for(int i=0; i<5; i++){
                                        if(matriz[12][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[0]++;
                                        }
                                    }
                                    for(int i=0; i<5; i++){
                                        for(int j=0; j<5; j++){
                                            if(matriz[12][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[0]++;
                                            }
                                        }
                                    }

                                system("cls");
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\t\t %d = BRANCO.\n", b[0]);
                                printf("        || - - - - - ||         |\t\t %d = PRETO.\n", p[0]);
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n");
                                printf("        || - - - - - ||         |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],b[0],p[0]);

                                printf("\n\ndigite a combinacao:  ");
                                scanf("%i%i%i%i%i",&matriz[11][0],&matriz[11][1],&matriz[11][2],&matriz[11][3],&matriz[11][4]);
                                pontuacao--;

                                if (vet[0] == matriz[11][0] && vet[1] == matriz[11][1] && vet[2] == matriz[11][2] && vet[3] == matriz[11][3] && vet[4] == matriz[11][4]){
                                    printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    ptotal = ptotal + pontuacao;
                                    system("pause");
                                    pontuacao = 12;
                                    break;
                                }

                                    b[1]=0;
                                    p[1]=0;

                                    for(int i=0; i<5; i++){
                                    veta[i]=0;
                                    aux3[i]=0;
                                    }

                                    for(int i=0; i<5; i++){
                                        if(matriz[11][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[1]++;
                                        }
                                    }
                                    for(int i=0; i<5; i++){
                                        for(int j=0; j<5; j++){
                                            if(matriz[11][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[1]++;
                                            }
                                        }
                                    }

                                system("cls");
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\t\t %d = BRANCO.\n", b[1]);
                                printf("        || - - - - - ||         |\t\t %d = PRETO.\n", p[1]);
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n");
                                printf("        || - - - - - ||         |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n");
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],b[1],p[1]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],b[0],p[0]);

                                printf("\n\ndigite a combinacao:  ");
                                scanf("%i%i%i%i%i",&matriz[10][0],&matriz[10][1],&matriz[10][2],&matriz[10][3],&matriz[10][4]);
                                pontuacao--;

                                if (vet[0] == matriz[10][0] && vet[1] == matriz[10][1] && vet[2] == matriz[10][2] && vet[3] == matriz[10][3] && vet[4] == matriz[10][4]){
                                    printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    ptotal = ptotal + pontuacao;
                                    system("pause");
                                    pontuacao = 12;             
                                    break;
                                }

                                    b[2]=0;
                                    p[2]=0;

                                    for(int i=0; i<5; i++){
                                    veta[i]=0;
                                    aux3[i]=0;
                                }

                                for(int i=0; i<5; i++){
                                        if(matriz[10][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[2]++;
                                        }
                                    }
                                    for(int i=0; i<5; i++){
                                        for(int j=0; j<5; j++){
                                            if(matriz[10][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[2]++;
                                            }
                                        }
                                    }

                                system("cls");
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\t\t %d = BRANCO.\n", b[2]);
                                printf("        || - - - - - ||         |\t\t %d = PRETO.\n", p[2]);
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n");
                                printf("        || %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],b[2],p[2]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],b[1],p[1]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],b[0],p[0]);

                                printf("\n\ndigite a combinacao:  ");
                                scanf("%i%i%i%i%i",&matriz[9][0],&matriz[9][1],&matriz[9][2],&matriz[9][3],&matriz[9][4]);
                                pontuacao--;

                                if (vet[0] == matriz[9][0] && vet[1] == matriz[9][1] && vet[2] == matriz[9][2] && vet[3] == matriz[9][3] && vet[4] == matriz[9][4]){
                                    printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    ptotal = ptotal + pontuacao;
                                    system("pause");
                                    pontuacao = 12;
                                    break;
                                }

                                    b[3]=0;
                                    p[3]=0;

                                for(int i=0; i<5; i++){
                                    veta[i]=0;
                                    aux3[i]=0;
                                }


                                for(int i=0; i<5; i++){
                                        if(matriz[9][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[3]++;
                                        }
                                    }
                                    for(int i=0; i<5; i++){
                                        for(int j=0; j<5; j++){
                                            if(matriz[9][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[3]++;
                                            }
                                        }
                                    }

                                system("cls");
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\t\t %d = BRANCO.\n", b[3]);
                                printf("        || - - - - - ||         |\t\t %d = PRETO.\n", p[3]);
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || %i %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],matriz[9][4],b[3],p[3]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],b[2],p[2]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],b[1],p[1]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],b[0],p[0]);

                                printf("\n\ndigite a combinacao:  ");
                                scanf("%i%i%i%i%i",&matriz[8][0],&matriz[8][1],&matriz[8][2],&matriz[8][3],&matriz[8][4]);
                                pontuacao--;

                                if (vet[0] == matriz[8][0] && vet[1] == matriz[8][1] && vet[2] == matriz[8][2] && vet[3] == matriz[8][3] && vet[4] == matriz[8][4]){
                                    printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    ptotal = ptotal + pontuacao;
                                    system("pause");
                                    pontuacao = 12;
                                    break;
                                }

                                    b[4]=0;
                                    p[4]=0;

                                    for(int i=0; i<5; i++){
                                    veta[i]=0;
                                    aux3[i]=0;
                                }

                                for(int i=0; i<5; i++){
                                        if(matriz[8][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[4]++;
                                        }
                                    }
                                    for(int i=0; i<5; i++){
                                        for(int j=0; j<5; j++){
                                            if(matriz[8][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[4]++;
                                            }
                                        }
                                    }

                                system("cls");
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\t\t %d = BRANCO.\n", b[4]);
                                printf("        || - - - - - ||         |\t\t %d = PRETO.\n", p[4]);
                                printf("        || - - - - - ||         |\n");
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],matriz[8][4],b[4],p[4]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],matriz[9][4],b[3],p[3]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],b[2],p[2]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],b[1],p[1]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],b[0],p[0]);

                                printf("\n\ndigite a combinacao:  ");
                                scanf("%i%i%i%i%i",&matriz[7][0],&matriz[7][1],&matriz[7][2],&matriz[7][3],&matriz[7][4]);
                                pontuacao--;

                                if (vet[0] == matriz[7][0] && vet[1] == matriz[7][1] && vet[2] == matriz[7][2] && vet[3] == matriz[7][3] && vet[4] == matriz[7][4]){
                                    printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    ptotal = ptotal + pontuacao;
                                    system("pause");
                                    pontuacao = 12;
                                    break;
                                }

                                    b[5]=0;
                                    p[5]=0;


                                    for(int i=0; i<5; i++){
                                    veta[i]=0;
                                    aux3[i]=0;
                                }



                                for(int i=0; i<5; i++){
                                        if(matriz[7][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[5]++;
                                        }
                                    }
                                    for(int i=0; i<5; i++){
                                        for(int j=0; j<5; j++){
                                            if(matriz[7][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[5]++;
                                            }
                                        }
                                    }

                                system("cls");
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\t\t %d = BRANCO.\n", b[5]);
                                printf("        || - - - - - ||         |\t\t %d = PRETO.\n", p[5]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],matriz[7][4],b[5],p[5]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],matriz[8][4],b[4],p[4]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],matriz[9][4],b[3],p[3]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],b[2],p[2]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],b[1],p[1]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],b[0],p[0]);

                                printf("\n\ndigite a combinacao:  ");
                                scanf("%i%i%i%i%i",&matriz[6][0],&matriz[6][1],&matriz[6][2],&matriz[6][3],&matriz[6][4]);
                                pontuacao--;

                                if (vet[0] == matriz[6][0] && vet[1] == matriz[6][1] && vet[2] == matriz[6][2] && vet[3] == matriz[6][3] && vet[4] == matriz[6][4]){
                                    printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    ptotal = ptotal + pontuacao;
                                    system("pause");
                                    pontuacao = 12;
                                    break;
                                }


                                    b[6]=0;
                                    p[6]=0;

                                    for(int i=0; i<5; i++){
                                    veta[i]=0;
                                    aux3[i]=0;
                                }

                                for(int i=0; i<5; i++){
                                        if(matriz[6][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[6]++;
                                        }
                                    }
                                    for(int i=0; i<5; i++){
                                        for(int j=0; j<5; j++){
                                            if(matriz[6][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[6]++;
                                            }
                                        }
                                    }

                                system("cls");
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\t\t %d = BRANCO.\n", b[6]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\t\t %d = PRETO.\n",matriz[6][0],matriz[6][1],matriz[6][2],matriz[6][3],matriz[6][4],b[6],p[6], p[6]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],matriz[7][4],b[5],p[5]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],matriz[8][4],b[4],p[4]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],matriz[9][4],b[3],p[3]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],b[2],p[2]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],b[1],p[1]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],b[0],p[0]);

                                printf("\n\ndigite a combinacao:  ");
                                scanf("%i%i%i%i%i",&matriz[5][0],&matriz[5][1],&matriz[5][2],&matriz[5][3],&matriz[5][4]);
                                pontuacao--;

                                if (vet[0] == matriz[5][0] && vet[1] == matriz[5][1] && vet[2] == matriz[5][2] && vet[3] == matriz[5][3] && vet[4] == matriz[5][4]){
                                    printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    ptotal = ptotal + pontuacao;
                                    system("pause");
                                    pontuacao = 12;
                                    break;
                                }

                                    b[7]=0;
                                    p[7]=0;

                                    for(int i=0; i<5; i++){
                                    veta[i]=0;
                                    aux3[i]=0;
                                }

                                for(int i=0; i<5; i++){
                                        if(matriz[5][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[7]++;
                                        }
                                    }
                                    for(int i=0; i<5; i++){
                                        for(int j=0; j<5; j++){
                                            if(matriz[5][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[7]++;
                                            }
                                        }
                                    }

                                system("cls");
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || %i %i %i %i %i || B:%i P:%i |\t\t %d = BRANCO.\n",matriz[5][0],matriz[5][1],matriz[5][2],matriz[5][3],matriz[5][4],b[7],p[7],b[7]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\t\t %d = PRETO.\n",matriz[6][0],matriz[6][1],matriz[6][2],matriz[6][3],matriz[6][4],b[6],p[6], p[7]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],matriz[7][4],b[5],p[5]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],matriz[8][4],b[4],p[4]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],matriz[9][4],b[3],p[3]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],b[2],p[2]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],b[1],p[1]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],b[0],p[0]);

                                printf("\n\ndigite a combinacao:  ");
                                scanf("%i%i%i%i%i",&matriz[4][0],&matriz[4][1],&matriz[4][2],&matriz[4][3],&matriz[4][4]);
                                pontuacao--;

                                if (vet[0] == matriz[4][0] && vet[1] == matriz[4][1] && vet[2] == matriz[4][2] && vet[3] == matriz[4][3] && vet[4] == matriz[4][4]){
                                    printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    ptotal = ptotal + pontuacao;
                                    system("pause");
                                    pontuacao = 12;
                                    break;
                                }

                                    b[8]=0;
                                    p[8]=0;

                                    for(int i=0; i<5; i++){
                                    veta[i]=0;
                                    aux3[i]=0;
                                }

                                for(int i=0; i<5; i++){
                                        if(matriz[4][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[8]++;
                                        }
                                    }
                                    for(int i=0; i<5; i++){
                                        for(int j=0; j<5; j++){
                                            if(matriz[4][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[8]++;
                                            }
                                        }
                                    }

                                system("cls");
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[4][0],matriz[4][1],matriz[4][2],matriz[4][3],matriz[4][4],b[8],p[8]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\t\t %d = BRANCO.\n",matriz[5][0],matriz[5][1],matriz[5][2],matriz[5][3],matriz[5][4],b[7],p[7],b[8]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\t\t %d = PRETO.\n",matriz[6][0],matriz[6][1],matriz[6][2],matriz[6][3],matriz[6][4],b[6],p[6], p[8]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],matriz[7][4],b[5],p[5]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],matriz[8][4],b[4],p[4]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],matriz[9][4],b[3],p[3]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],b[2],p[2]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],b[1],p[1]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],b[0],p[0]);

                                printf("\n\ndigite a combinacao:  ");
                                scanf("%i%i%i%i%i",&matriz[3][0],&matriz[3][1],&matriz[3][2],&matriz[3][3],&matriz[3][4]);
                                pontuacao--;

                                if (vet[0] == matriz[3][0] && vet[1] == matriz[3][1] && vet[2] == matriz[3][2] && vet[3] == matriz[3][3] && vet[4] == matriz[3][4]){
                                    printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    ptotal = ptotal + pontuacao;
                                    system("pause");
                                    pontuacao = 12;
                                    break;
                                }

                                    b[9]=0;
                                    p[9]=0;

                                    for(int i=0; i<5; i++){
                                    veta[i]=0;
                                    aux3[i]=0;
                                }

                                for(int i=0; i<5; i++){
                                        if(matriz[3][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[9]++;
                                        }
                                    }
                                    for(int i=0; i<5; i++){
                                        for(int j=0; j<5; j++){
                                            if(matriz[3][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[9]++;
                                            }
                                        }
                                    }

                                system("cls");
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || - - - - - ||         |\n");
                                printf("        || - - - - - ||         |\n");
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[3][0],matriz[3][1],matriz[3][2],matriz[3][3],matriz[3][4],b[9],p[9]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[4][0],matriz[4][1],matriz[4][2],matriz[4][3],matriz[4][4],b[8],p[8]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\t\t %d = BRANCO.\n",matriz[5][0],matriz[5][1],matriz[5][2],matriz[5][3],matriz[5][4],b[7],p[7],b[9]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\t\t %d = PRETO.\n",matriz[6][0],matriz[6][1],matriz[6][2],matriz[6][3],matriz[6][4],b[6],p[6], p[9]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],matriz[7][4],b[5],p[5]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],matriz[8][4],b[4],p[4]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],matriz[9][4],b[3],p[3]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],b[2],p[2]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],b[1],p[1]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],b[0],p[0]);

                                printf("\n\ndigite a combinacao:  ");
                                scanf("%i%i%i%i%i",&matriz[2][0],&matriz[2][1],&matriz[2][2],&matriz[2][3],&matriz[2][4]);
                                pontuacao--;

                                if (vet[0] == matriz[2][0] && vet[1] == matriz[2][1] && vet[2] == matriz[2][2] && vet[3] == matriz[2][3] && vet[4] == matriz[2][4]){
                                    printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    ptotal = ptotal + pontuacao;
                                    system("pause");
                                    pontuacao = 12;
                                    break;
                                }

                                    b[10]=0;
                                    p[10]=0;

                                    for(int i=0; i<5; i++){
                                    veta[i]=0;
                                    aux3[i]=0;
                                }

                                for(int i=0; i<5; i++){
                                        if(matriz[2][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[10]++;
                                        }
                                    }
                                    for(int i=0; i<5; i++){
                                        for(int j=0; j<5; j++){
                                            if(matriz[2][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[10]++;
                                            }
                                        }
                                    }

                                system("cls");
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || - - - - - ||         |\n");
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[2][0],matriz[2][1],matriz[2][2],matriz[2][3],matriz[2][4],b[10],p[10]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[3][0],matriz[3][1],matriz[3][2],matriz[3][3],matriz[3][4],b[9],p[9]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[4][0],matriz[4][1],matriz[4][2],matriz[4][3],matriz[4][4],b[8],p[8]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\t\t %d = BRANCO.\n",matriz[5][0],matriz[5][1],matriz[5][2],matriz[5][3],matriz[5][4],b[7],p[7],b[10]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\t\t %d = PRETO.\n",matriz[6][0],matriz[6][1],matriz[6][2],matriz[6][3],matriz[6][4],b[6],p[6], p[10]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],matriz[7][4],b[5],p[5]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],matriz[8][4],b[4],p[4]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],matriz[9][4],b[3],p[3]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],b[2],p[2]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],b[1],p[1]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],b[0],p[0]);

                                printf("\n\ndigite a combinacao:  ");
                                scanf("%i%i%i%i%i",&matriz[1][0],&matriz[1][1],&matriz[1][2],&matriz[1][3],&matriz[1][4]);
                                pontuacao--;

                                if (vet[0] == matriz[1][0] && vet[1] == matriz[1][1] && vet[2] == matriz[1][2] && vet[3] == matriz[1][3] && vet[4] == matriz[1][4]){
                                    printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    ptotal = ptotal + pontuacao;
                                    system("pause");
                                    pontuacao = 12;
                                    break;
                                }

                                    b[11]=0;
                                    p[11]=0;

                                    for(int i=0; i<5; i++){
                                    veta[i]=0;
                                    aux3[i]=0;
                                }

                                for(int i=0; i<5; i++){
                                        if(matriz[1][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[11]++;
                                        }
                                    }
                                    for(int i=0; i<5; i++){
                                        for(int j=0; j<5; j++){
                                            if(matriz[1][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[11]++;
                                            }
                                        }
                                    }

                                system("cls");
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[1][0],matriz[1][1],matriz[1][2],matriz[1][3],matriz[1][4],b[11],p[11]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[2][0],matriz[2][1],matriz[2][2],matriz[2][3],matriz[2][4],b[10],p[10]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[3][0],matriz[3][1],matriz[3][2],matriz[3][3],matriz[3][4],b[9],p[9]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[4][0],matriz[4][1],matriz[4][2],matriz[4][3],matriz[4][4],b[8],p[8]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\t\t %d = BRANCO.\n",matriz[5][0],matriz[5][1],matriz[5][2],matriz[5][3],matriz[5][4],b[7],p[7],b[11]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\t\t %d = PRETO.\n",matriz[6][0],matriz[6][1],matriz[6][2],matriz[6][3],matriz[6][4],b[6],p[6], p[11]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],matriz[7][4],b[5],p[5]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],matriz[8][4],b[4],p[4]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],matriz[9][4],b[3],p[3]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],b[2],p[2]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],b[1],p[1]);
                                printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],b[0],p[0]);

                                printf("\n\n\t\t\tGAME OVER!\n\n");
                                printf("\t       A senha gerada foi:  ");

                                for (i = 0; i < 5; i++){
                                    printf("%d ", vet[i]);
                                }

                                printf("\n\n");

                                pontuacao--;

                                printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                printf("\n\n");
                                getchar();
                                ptotal = ptotal + pontuacao;
                                pontuacao = 12;

                                l++;
                                system("pause");
                                break;
                            }

                            if (jogatinas == rodada){
                                int replay;
                                system("cls");
                                printf("\n\n");
                                printf("\t\t\t\t  FIM DE JOGO!\n\t\t\t       OBRIGADO POR JOGAR!\n");
                                printf("\n\n\t\t\tA pontuacao total eh %d pontos!\n\n", ptotal);

                                printf("\t\t\t     Deseja jogar novamente? ");
                                ALTERRADADIF2:
                                printf("\n\n\n| Aperte 1 para jogar novamente |\n\n| Aperte 0 para voltar ao menu  |\n\n");
                                printf("> ");
                                scanf("%d", &replay);

                                if (replay == 1){
                                    rodada = 1;
                                    goto PLAYAGAINDIF2;
                                }
                                else if (replay == 0){
                                    menu();
                                }
                                else if (replay != 0 || replay != 1){
                                    system("cls");
                                    printf("\n\n\t\t\tDigite uma alternativa valida!");
                                    goto ALTERRADADIF2;
                                }
                            }
                        }
                    }
                }
                else if (dificuldade == 3){             //DIFICULDADE DIFÍCIL
                    
                    system("cls");

                    int jogatinas, forabug, rodada = 0, repeticao;
                    char jogador[10];
                    printf("\n\n\t\tInsira seu nome, jogador: ");
                    scanf("%s", &jogador);

                    PLAYAGAINDIF3:
                    rodada = 0;
                    system("cls");
                    printf("\n\t\t    BEM VINDO, %s!", jogador);
                    printf("\n\t Quantas vezes o MasterMind sera jogado?\n\tInsira a quantidade de vezes que voce quer jogar: ");
                    scanf("%d", &jogatinas);
                    forabug = jogatinas;

                    system("cls");
                    printf("\n\n\t%s, a senha tera numeros repetidos? \n", jogador);
                    printf("\n\n| Aperte 1 para NAO repetir os numeros da senha |");
                    printf("\n\n|   Aperte 2 para REPETIR os numeros da senha   |");
                    printf("\n\n> ");
                    scanf("%d", &repeticao);

                    int l = 0, matriz[TAM][TAM], pontuacao = 14, ptotal = 0;
                    int i = 0, j, vet[TAM], igual;

                    if (repeticao == 1 || repeticao == 2){

                        for(int o = 0; o < jogatinas; o++){

                            srand(time(NULL));              

                            if(repeticao == 1){
                                i = 0;
                                do{                             
                                    vet[i] = rand()%9;
                                    igual = 0;
                                    for (j = 0; j < i; j++){
                                        if (vet[j] == vet[i]){
                                            igual = 1;
                                        }
                                    }

                                    if (igual == 0){
                                        i++;
                                    }

                                } while(i < 6);
                            }

                            if(repeticao == 2){
                                i = 0;

                                vet[0] = rand()%9;
                                vet[1] = rand()%9;
                                vet[2] = rand()%9;
                                vet[3] = rand()%9;
                                vet[4] = rand()%9;
                                vet[5] = rand()%9;
                            }

                            while (l < jogatinas){
                                
                                system("cls");

                                    // for (i = 0; i < 6; i++){
                                    //     printf("%d ", vet[i]);
                                    // }

                                printf("\n\n\t\t\t%s, voce jogara por %d rodadas!", jogador, forabug);
                                rodada++;
                                printf("\n\t\t\t            Rodada %d", rodada);
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\t\tSEJA BEM-VINDO!\n");
                                printf("        || - - - - - - ||         |\t\tMASTERMIND GAME\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("\n\ndigite a combinacao:  ");
                                scanf("%i%i%i%i%i%i",&matriz[14][0],&matriz[14][1],&matriz[14][2],&matriz[14][3],&matriz[14][4],&matriz[14][5]);

                                if (vet[0] == matriz[14][0] && vet[1] == matriz[14][1] && vet[2] == matriz[14][2] && vet[3] == matriz[14][3] && vet[4] == matriz[14][4] && vet[5] == matriz[14][5]){
                                    printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    ptotal = ptotal + pontuacao;
                                    system("pause");
                                    pontuacao = 14;
                                    break;
                                }

                                int aux3[TAM], b[TAM],p[TAM], veta[TAM];

                                    b[0]=0;
                                    p[0]=0;

                                    for(int i=0; i<6; i++){
                                    veta[i]=0;
                                    aux3[i]=0;
                                    }

                                    for(int i=0; i<6; i++){
                                        if(matriz[14][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[0]++;
                                        }
                                    }
                                    for(int i=0; i<6; i++){
                                        for(int j=0; j<6; j++){
                                            if(matriz[14][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[0]++;
                                            }
                                        }
                                    }

                                system("cls");
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\t\t %d = BRANCO.\n", b[0]);
                                printf("        || - - - - - - ||         |\t\t %d = PRETO.\n", p[0]);
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n");
                                printf("        || - - - - - - ||         |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[14][0],matriz[14][1],matriz[14][2],matriz[14][3],matriz[14][4],matriz[14][5],b[0],p[0]);

                                printf("\n\ndigite a combinacao:  ");
                                scanf("%i%i%i%i%i%i",&matriz[13][0],&matriz[13][1],&matriz[13][2],&matriz[13][3],&matriz[13][4],&matriz[13][5]);
                                pontuacao--;

                                if (vet[0] == matriz[13][0] && vet[1] == matriz[13][1] && vet[2] == matriz[13][2] && vet[3] == matriz[13][3] && vet[4] == matriz[13][4] && vet[5] == matriz[13][5]){
                                    printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    ptotal = ptotal + pontuacao;
                                    system("pause");
                                    pontuacao = 14;
                                    break;
                                }

                                    b[1]=0;
                                    p[1]=0;

                                    for(int i=0; i<6; i++){
                                    veta[i]=0;
                                    aux3[i]=0;
                                    }

                                    for(int i=0; i<6; i++){
                                        if(matriz[13][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[1]++;
                                        }
                                    }
                                    for(int i=0; i<6; i++){
                                        for(int j=0; j<6; j++){
                                            if(matriz[13][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[1]++;
                                            }
                                        }
                                    }

                                system("cls");
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\t\t %d = BRANCO.\n", b[1]);
                                printf("        || - - - - - - ||         |\t\t %d = PRETO.\n", p[1]);
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n");
                                printf("        || - - - - - - ||         |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[13][0],matriz[13][1],matriz[13][2],matriz[13][3],matriz[13][4],matriz[13][5],b[1],p[1]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[14][0],matriz[14][1],matriz[14][2],matriz[14][3],matriz[14][4],matriz[14][5],b[0],p[0]);

                                printf("\n\ndigite a combinacao:  ");
                                scanf("%i%i%i%i%i%i",&matriz[12][0],&matriz[12][1],&matriz[12][2],&matriz[12][3],&matriz[12][4],&matriz[12][5]);
                                pontuacao--;

                                if (vet[0] == matriz[12][0] && vet[1] == matriz[12][1] && vet[2] == matriz[12][2] && vet[3] == matriz[12][3] && vet[4] == matriz[12][4] && vet[5] == matriz[12][5]){
                                    printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    ptotal = ptotal + pontuacao;
                                    system("pause");
                                    pontuacao = 14;
                                    break;
                                }

                                    b[2]=0;
                                    p[2]=0;

                                    for(int i=0; i<6; i++){
                                    veta[i]=0;
                                    aux3[i]=0;
                                    }

                                    for(int i=0; i<6; i++){
                                        if(matriz[12][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[2]++;
                                        }
                                    }
                                    for(int i=0; i<6; i++){
                                        for(int j=0; j<6; j++){
                                            if(matriz[12][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[2]++;
                                            }
                                        }
                                    }

                                system("cls");
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\t\t %d = BRANCO.\n", b[2]);
                                printf("        || - - - - - - ||         |\t\t %d = PRETO.\n", p[2]);
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n");
                                printf("        || - - - - - - ||         |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],matriz[12][5],b[2],p[2]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[13][0],matriz[13][1],matriz[13][2],matriz[13][3],matriz[13][4],matriz[13][5],b[1],p[1]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[14][0],matriz[14][1],matriz[14][2],matriz[14][3],matriz[14][4],matriz[14][5],b[0],p[0]);

                                printf("\n\ndigite a combinacao:  ");
                                scanf("%i%i%i%i%i%i",&matriz[11][0],&matriz[11][1],&matriz[11][2],&matriz[11][3],&matriz[11][4],&matriz[11][5]);
                                pontuacao--;

                                if (vet[0] == matriz[11][0] && vet[1] == matriz[11][1] && vet[2] == matriz[11][2] && vet[3] == matriz[11][3] && vet[4] == matriz[11][4] && vet[5] == matriz[11][5]){
                                    printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    ptotal = ptotal + pontuacao;
                                    system("pause");
                                    pontuacao = 14;
                                    break;
                                }

                                    b[3]=0;
                                    p[3]=0;

                                    for(int i=0; i<6; i++){
                                    veta[i]=0;
                                    aux3[i]=0;
                                    }

                                    for(int i=0; i<6; i++){
                                        if(matriz[11][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[3]++;
                                        }
                                    }
                                    for(int i=0; i<6; i++){
                                        for(int j=0; j<6; j++){
                                            if(matriz[11][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[3]++;
                                            }
                                        }
                                    }

                                system("cls");
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\t\t %d = BRANCO.\n", b[3]);
                                printf("        || - - - - - - ||         |\t\t %d = PRETO.\n", p[3]);
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n");
                                printf("        || - - - - - - ||         |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],matriz[11][5],b[3],p[3]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],matriz[12][5],b[2],p[2]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[13][0],matriz[13][1],matriz[13][2],matriz[13][3],matriz[13][4],matriz[13][5],b[1],p[1]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[14][0],matriz[14][1],matriz[14][2],matriz[14][3],matriz[14][4],matriz[14][5],b[0],p[0]);

                                printf("\n\ndigite a combinacao:  ");
                                scanf("%i%i%i%i%i%i",&matriz[10][0],&matriz[10][1],&matriz[10][2],&matriz[10][3],&matriz[10][4],&matriz[10][5]);
                                pontuacao--;

                                if (vet[0] == matriz[10][0] && vet[1] == matriz[10][1] && vet[2] == matriz[10][2] && vet[3] == matriz[10][3] && vet[4] == matriz[10][4] && vet[5] == matriz[10][5]){
                                    printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    ptotal = ptotal + pontuacao;
                                    system("pause");
                                    pontuacao = 14;
                                    break;
                                }

                                    b[4]=0;
                                    p[4]=0;

                                    for(int i=0; i<6; i++){
                                    veta[i]=0;
                                    aux3[i]=0;
                                    }

                                    for(int i=0; i<6; i++){
                                        if(matriz[10][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[4]++;
                                        }
                                    }
                                    for(int i=0; i<6; i++){
                                        for(int j=0; j<6; j++){
                                            if(matriz[10][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[4]++;
                                            }
                                        }
                                    }

                                system("cls");
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\t\t %d = BRANCO.\n", b[4]);
                                printf("        || - - - - - - ||         |\t\t %d = PRETO.\n", p[4]);
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n");
                                printf("        || - - - - - - ||         |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n");
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[11][3],matriz[10][4],matriz[10][5],b[4],p[4]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],matriz[11][5],b[3],p[3]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],matriz[12][5],b[2],p[2]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[13][0],matriz[13][1],matriz[13][2],matriz[13][3],matriz[13][4],matriz[13][5],b[1],p[1]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[14][0],matriz[14][1],matriz[14][2],matriz[14][3],matriz[14][4],matriz[14][5],b[0],p[0]);

                                printf("\n\ndigite a combinacao:  ");
                                scanf("%i%i%i%i%i%i",&matriz[9][0],&matriz[9][1],&matriz[9][2],&matriz[9][3],&matriz[9][4],&matriz[9][5]);
                                pontuacao--;

                                if (vet[0] == matriz[9][0] && vet[1] == matriz[9][1] && vet[2] == matriz[9][2] && vet[3] == matriz[9][3] && vet[4] == matriz[9][4] && vet[5] == matriz[9][5]){
                                    printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    ptotal = ptotal + pontuacao;
                                    system("pause");
                                    pontuacao = 14;
                                    break;
                                }

                                    b[5]=0;
                                    p[5]=0;

                                    for(int i=0; i<6; i++){
                                    veta[i]=0;
                                    aux3[i]=0;
                                    }

                                    for(int i=0; i<6; i++){
                                        if(matriz[9][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[5]++;
                                        }
                                    }
                                    for(int i=0; i<6; i++){
                                        for(int j=0; j<6; j++){
                                            if(matriz[9][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[5]++;
                                            }
                                        }
                                    }

                                system("cls");
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\t\t %d = BRANCO.\n", b[5]);
                                printf("        || - - - - - - ||         |\t\t %d = PRETO.\n", p[5]);
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n");
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],matriz[9][4],matriz[9][5],b[5],p[5]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],matriz[10][5],b[4],p[4]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],matriz[11][5],b[3],p[3]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],matriz[12][5],b[2],p[2]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[13][0],matriz[13][1],matriz[13][2],matriz[13][3],matriz[13][4],matriz[13][5],b[1],p[1]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[14][0],matriz[14][1],matriz[14][2],matriz[14][3],matriz[14][4],matriz[14][5],b[0],p[0]);

                                printf("\n\ndigite a combinacao:  ");
                                scanf("%i%i%i%i%i%i",&matriz[8][0],&matriz[8][1],&matriz[8][2],&matriz[8][3],&matriz[8][4],&matriz[8][5]);
                                pontuacao--;

                                if (vet[0] == matriz[8][0] && vet[1] == matriz[8][1] && vet[2] == matriz[8][2] && vet[3] == matriz[8][3] && vet[4] == matriz[8][4] && vet[5] == matriz[8][5]){
                                    printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    ptotal = ptotal + pontuacao;
                                    system("pause");
                                    pontuacao = 14;
                                    break;
                                }

                                    b[6]=0;
                                    p[6]=0;

                                    for(int i=0; i<6; i++){
                                    veta[i]=0;
                                    aux3[i]=0;
                                    }

                                    for(int i=0; i<6; i++){
                                        if(matriz[8][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[6]++;
                                        }
                                    }
                                    for(int i=0; i<6; i++){
                                        for(int j=0; j<6; j++){
                                            if(matriz[8][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[6]++;
                                            }
                                        }
                                    }   

                                system("cls");
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\t\t %d = BRANCO.\n", b[6]);
                                printf("        || - - - - - - ||         |\t\t %d = PRETO.\n", p[6]);
                                printf("        || - - - - - - ||         |\n");
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],matriz[8][4],matriz[8][5],b[6],p[6]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],matriz[9][4],matriz[9][5],b[5],p[5]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],matriz[10][5],b[4],p[4]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],matriz[11][5],b[3],p[3]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],matriz[12][5],b[2],p[2]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[13][0],matriz[13][1],matriz[13][2],matriz[13][3],matriz[13][4],matriz[13][5],b[1],p[1]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[14][0],matriz[14][1],matriz[14][2],matriz[14][3],matriz[14][4],matriz[14][5],b[0],p[0]);

                                printf("\n\ndigite a combinacao:  ");
                                scanf("%i%i%i%i%i%i",&matriz[7][0],&matriz[7][1],&matriz[7][2],&matriz[7][3],&matriz[7][4],&matriz[7][5]);
                                pontuacao--;

                                if (vet[0] == matriz[7][0] && vet[1] == matriz[7][1] && vet[2] == matriz[7][2] && vet[3] == matriz[7][3] && vet[4] == matriz[7][4] && vet[5] == matriz[7][5]){
                                    printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    ptotal = ptotal + pontuacao;
                                    system("pause");
                                    pontuacao = 14;
                                    break;
                                }

                                    b[7]=0;
                                    p[7]=0;

                                    for(int i=0; i<6; i++){
                                    veta[i]=0;
                                    aux3[i]=0;
                                    }

                                    for(int i=0; i<6; i++){
                                        if(matriz[7][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[7]++;
                                        }
                                    }
                                    for(int i=0; i<6; i++){
                                        for(int j=0; j<6; j++){
                                            if(matriz[7][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[7]++;
                                            }
                                        }
                                    } 

                                system("cls");
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\t\t %d = BRANCO.\n", b[7]);
                                printf("        || - - - - - - ||         |\t\t %d = PRETO.\n", p[7]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],matriz[7][4],matriz[7][5],b[7],p[7]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],matriz[8][4],matriz[8][5],b[6],p[6]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],matriz[9][4],matriz[9][5],b[5],p[5]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],matriz[10][5],b[4],p[4]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],matriz[11][5],b[3],p[3]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],matriz[12][5],b[2],p[2]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[13][0],matriz[13][1],matriz[13][2],matriz[13][3],matriz[13][4],matriz[13][5],b[1],p[1]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[14][0],matriz[14][1],matriz[14][2],matriz[14][3],matriz[14][4],matriz[14][5],b[0],p[0]);

                                printf("\n\ndigite a combinacao:  ");
                                scanf("%i%i%i%i%i%i",&matriz[6][0],&matriz[6][1],&matriz[6][2],&matriz[6][3],&matriz[6][4],&matriz[6][5]);
                                pontuacao--;

                                if (vet[0] == matriz[6][0] && vet[1] == matriz[6][1] && vet[2] == matriz[6][2] && vet[3] == matriz[6][3] && vet[4] == matriz[6][4] && vet[5] == matriz[6][5]){
                                    printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    ptotal = ptotal + pontuacao;
                                    system("pause");
                                    pontuacao = 14;
                                    break;
                                }

                                    b[8]=0;
                                    p[8]=0;

                                    for(int i=0; i<6; i++){
                                    veta[i]=0;
                                    aux3[i]=0;
                                    }

                                    for(int i=0; i<6; i++){
                                        if(matriz[6][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[8]++;
                                        }
                                    }
                                    for(int i=0; i<6; i++){
                                        for(int j=0; j<6; j++){
                                            if(matriz[6][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[8]++;
                                            }
                                        }
                                    }

                                system("cls");
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\t\t %d = BRANCO.\n", b[8]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t %d = PRETO.\n",matriz[6][0],matriz[6][1],matriz[6][2],matriz[6][3],matriz[6][4],matriz[6][5],b[8],p[8],p[8]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],matriz[7][4],matriz[7][5],b[7],p[7]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],matriz[8][4],matriz[8][5],b[6],p[6]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],matriz[9][4],matriz[9][5],b[5],p[5]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],matriz[10][5],b[4],p[4]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],matriz[11][5],b[3],p[3]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],matriz[12][5],b[2],p[2]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[13][0],matriz[13][1],matriz[13][2],matriz[13][3],matriz[13][4],matriz[13][5],b[1],p[1]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[14][0],matriz[14][1],matriz[14][2],matriz[14][3],matriz[14][4],matriz[14][5],b[0],p[0]);

                                printf("\n\ndigite a combinacao:  ");
                                scanf("%i%i%i%i%i%i",&matriz[5][0],&matriz[5][1],&matriz[5][2],&matriz[5][3],&matriz[5][4],&matriz[5][5]);
                                pontuacao--;

                                if (vet[0] == matriz[5][0] && vet[1] == matriz[5][1] && vet[2] == matriz[5][2] && vet[3] == matriz[5][3] && vet[4] == matriz[5][4] && vet[5] == matriz[5][5]){
                                    printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    ptotal = ptotal + pontuacao;
                                    system("pause");
                                    pontuacao = 14;
                                    break;
                                }

                                    b[9]=0;
                                    p[9]=0;

                                    for(int i=0; i<6; i++){
                                    veta[i]=0;
                                    aux3[i]=0;
                                    }

                                    for(int i=0; i<6; i++){
                                        if(matriz[5][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[9]++;
                                        }
                                    }
                                    for(int i=0; i<6; i++){
                                        for(int j=0; j<6; j++){
                                            if(matriz[5][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[9]++;
                                            }
                                        }
                                    }

                                system("cls");
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t %d = BRANCO.\n",matriz[5][0],matriz[5][1],matriz[5][2],matriz[5][3],matriz[5][4],matriz[5][5],b[9],p[9],b[9]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t %d = PRETO.\n",matriz[6][0],matriz[6][1],matriz[6][2],matriz[6][3],matriz[6][4],matriz[6][5],b[8],p[8],p[9]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],matriz[7][4],matriz[7][5],b[7],p[7]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],matriz[8][4],matriz[8][5],b[6],p[6]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],matriz[9][4],matriz[9][5],b[5],p[5]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],matriz[10][5],b[4],p[4]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],matriz[11][5],b[3],p[3]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],matriz[12][5],b[2],p[2]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[13][0],matriz[13][1],matriz[13][2],matriz[13][3],matriz[13][4],matriz[13][5],b[1],p[1]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[14][0],matriz[14][1],matriz[14][2],matriz[14][3],matriz[14][4],matriz[14][5],b[0],p[0]);

                                printf("\n\ndigite a combinacao:  ");
                                scanf("%i%i%i%i%i%i",&matriz[4][0],&matriz[4][1],&matriz[4][2],&matriz[4][3],&matriz[4][4],&matriz[4][5]);
                                pontuacao--;

                                if (vet[0] == matriz[4][0] && vet[1] == matriz[4][1] && vet[2] == matriz[4][2] && vet[3] == matriz[4][3] && vet[4] == matriz[4][4] && vet[5] == matriz[4][5]){
                                    printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    ptotal = ptotal + pontuacao;
                                    system("pause");
                                    pontuacao = 14;
                                    break;
                                }

                                    b[10]=0;
                                    p[10]=0;

                                    for(int i=0; i<6; i++){
                                    veta[i]=0;
                                    aux3[i]=0;
                                    }

                                    for(int i=0; i<6; i++){
                                        if(matriz[4][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[10]++;
                                        }
                                    }
                                    for(int i=0; i<6; i++){
                                        for(int j=0; j<6; j++){
                                            if(matriz[4][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[10]++;
                                            }
                                        }
                                    }

                                system("cls");
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[4][0],matriz[4][1],matriz[4][2],matriz[4][3],matriz[4][4],matriz[4][5],b[10],p[10]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t %d = BRANCO.\n",matriz[5][0],matriz[5][1],matriz[5][2],matriz[5][3],matriz[5][4],matriz[5][5],b[9],p[9],b[10]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t %d = PRETO.\n",matriz[6][0],matriz[6][1],matriz[6][2],matriz[6][3],matriz[6][4],matriz[6][5],b[8],p[8],p[10]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],matriz[7][4],matriz[7][5],b[7],p[7]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],matriz[8][4],matriz[8][5],b[6],p[6]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],matriz[9][4],matriz[9][5],b[5],p[5]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],matriz[10][5],b[4],p[4]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],matriz[11][5],b[3],p[3]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],matriz[12][5],b[2],p[2]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[13][0],matriz[13][1],matriz[13][2],matriz[13][3],matriz[13][4],matriz[13][5],b[1],p[1]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[14][0],matriz[14][1],matriz[14][2],matriz[14][3],matriz[14][4],matriz[14][5],b[0],p[0]);

                                printf("\n\ndigite a combinacao:  ");
                                scanf("%i%i%i%i%i%i",&matriz[3][0],&matriz[3][1],&matriz[3][2],&matriz[3][3],&matriz[3][4],&matriz[3][5]);
                                pontuacao--;

                                if (vet[0] == matriz[3][0] && vet[1] == matriz[3][1] && vet[2] == matriz[3][2] && vet[3] == matriz[3][3] && vet[4] == matriz[3][4] && vet[5] == matriz[3][5]){
                                    printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    ptotal = ptotal + pontuacao;
                                    system("pause");
                                    pontuacao = 14;
                                    break;
                                }

                                    b[11]=0;
                                    p[11]=0;

                                    for(int i=0; i<6; i++){
                                    veta[i]=0;
                                    aux3[i]=0;
                                    }

                                    for(int i=0; i<6; i++){
                                        if(matriz[3][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[11]++;
                                        }
                                    }
                                    for(int i=0; i<6; i++){
                                        for(int j=0; j<6; j++){
                                            if(matriz[3][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[11]++;
                                            }
                                        }
                                    }

                                system("cls");
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || - - - - - - ||         |\n");
                                printf("        || - - - - - - ||         |\n");
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[3][0],matriz[3][1],matriz[3][2],matriz[3][3],matriz[3][4],matriz[3][5],b[11],p[11]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[4][0],matriz[4][1],matriz[4][2],matriz[4][3],matriz[4][4],matriz[4][5],b[10],p[10]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t %d = BRANCO.\n",matriz[5][0],matriz[5][1],matriz[5][2],matriz[5][3],matriz[5][4],matriz[5][5],b[9],p[9],b[11]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t %d = PRETO.\n",matriz[6][0],matriz[6][1],matriz[6][2],matriz[6][3],matriz[6][4],matriz[6][5],b[8],p[8],p[11]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],matriz[7][4],matriz[7][5],b[7],p[7]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],matriz[8][4],matriz[8][5],b[6],p[6]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],matriz[9][4],matriz[9][5],b[5],p[5]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],matriz[10][5],b[4],p[4]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],matriz[11][5],b[3],p[3]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],matriz[12][5],b[2],p[2]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[13][0],matriz[13][1],matriz[13][2],matriz[13][3],matriz[13][4],matriz[13][5],b[1],p[1]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[14][0],matriz[14][1],matriz[14][2],matriz[14][3],matriz[14][4],matriz[14][5],b[0],p[0]);

                                printf("\n\ndigite a combinacao:  ");
                                scanf("%i%i%i%i%i%i",&matriz[2][0],&matriz[2][1],&matriz[2][2],&matriz[2][3],&matriz[2][4],&matriz[2][5]);
                                pontuacao--;

                                if (vet[0] == matriz[2][0] && vet[1] == matriz[2][1] && vet[2] == matriz[2][2] && vet[3] == matriz[2][3] && vet[4] == matriz[2][4] && vet[5] == matriz[2][5]){
                                    printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    ptotal = ptotal + pontuacao;
                                    system("pause");
                                    pontuacao = 14;
                                    break;
                                }

                                    b[12]=0;
                                    p[12]=0;

                                    for(int i=0; i<6; i++){
                                    veta[i]=0;
                                    aux3[i]=0;
                                    }

                                    for(int i=0; i<6; i++){
                                        if(matriz[2][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[12]++;
                                        }
                                    }
                                    for(int i=0; i<6; i++){
                                        for(int j=0; j<6; j++){
                                            if(matriz[2][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[12]++;
                                            }
                                        }
                                    }

                                system("cls");
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || - - - - - - ||         |\n");
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[2][0],matriz[2][1],matriz[2][2],matriz[2][3],matriz[2][4],matriz[2][5],b[12],p[12]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[3][0],matriz[3][1],matriz[3][2],matriz[3][3],matriz[3][4],matriz[3][5],b[11],p[11]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[4][0],matriz[4][1],matriz[4][2],matriz[4][3],matriz[4][4],matriz[4][5],b[10],p[10]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t %d = BRANCO.\n",matriz[5][0],matriz[5][1],matriz[5][2],matriz[5][3],matriz[5][4],matriz[5][5],b[9],p[9],b[12]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t %d = PRETO.\n",matriz[6][0],matriz[6][1],matriz[6][2],matriz[6][3],matriz[6][4],matriz[6][5],b[8],p[8],p[12]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],matriz[7][4],matriz[7][5],b[7],p[7]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],matriz[8][4],matriz[8][5],b[6],p[6]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],matriz[9][4],matriz[9][5],b[5],p[5]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],matriz[10][5],b[4],p[4]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],matriz[11][5],b[3],p[3]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],matriz[12][5],b[2],p[2]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[13][0],matriz[13][1],matriz[13][2],matriz[13][3],matriz[13][4],matriz[13][5],b[1],p[1]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[14][0],matriz[14][1],matriz[14][2],matriz[14][3],matriz[14][4],matriz[14][5],b[0],p[0]);

                                printf("\n\ndigite a combinacao:  ");
                                scanf("%i%i%i%i%i%i",&matriz[1][0],&matriz[1][1],&matriz[1][2],&matriz[1][3],&matriz[1][4],&matriz[1][5]);
                                pontuacao--;

                                if (vet[0] == matriz[1][0] && vet[1] == matriz[1][1] && vet[2] == matriz[1][2] && vet[3] == matriz[1][3] && vet[4] == matriz[1][4] && vet[5] == matriz[1][5]){
                                    printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    ptotal = ptotal + pontuacao;
                                    system("pause");
                                    pontuacao = 14;
                                    break;
                                }

                                    b[13]=0;
                                    p[13]=0;

                                    for(int i=0; i<6; i++){
                                    veta[i]=0;
                                    aux3[i]=0;
                                    }

                                    for(int i=0; i<6; i++){
                                        if(matriz[1][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[13]++;
                                        }
                                    }
                                    for(int i=0; i<6; i++){
                                        for(int j=0; j<6; j++){
                                            if(matriz[1][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[13]++;
                                            }
                                        }
                                    }

                                system("cls");
                                printf("\n\n");
                                if (repeticao == 1){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    printf("OFF\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                else if(repeticao == 2){
                                    printf("\t\t\t\t\t REPETICAO: ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                    printf("ON\n");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                }
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[1][0],matriz[1][1],matriz[1][2],matriz[1][3],matriz[1][4],matriz[1][5],b[13],p[13]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[2][0],matriz[2][1],matriz[2][2],matriz[2][3],matriz[2][4],matriz[2][5],b[12],p[12]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[3][0],matriz[3][1],matriz[3][2],matriz[3][3],matriz[3][4],matriz[3][5],b[11],p[11]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[4][0],matriz[4][1],matriz[4][2],matriz[4][3],matriz[4][4],matriz[4][5],b[10],p[10]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t %d = BRANCO.\n",matriz[5][0],matriz[5][1],matriz[5][2],matriz[5][3],matriz[5][4],matriz[5][5],b[9],p[9],b[13]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t %d = PRETO.\n",matriz[6][0],matriz[6][1],matriz[6][2],matriz[6][3],matriz[6][4],matriz[6][5],b[8],p[8],p[13]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],matriz[7][4],matriz[7][5],b[7],p[7]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],matriz[8][4],matriz[8][5],b[6],p[6]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],matriz[9][4],matriz[9][5],b[5],p[5]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],matriz[10][5],b[4],p[4]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],matriz[11][5],b[3],p[3]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],matriz[12][5],b[2],p[2]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[13][0],matriz[13][1],matriz[13][2],matriz[13][3],matriz[13][4],matriz[13][5],b[1],p[1]);
                                printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[14][0],matriz[14][1],matriz[14][2],matriz[14][3],matriz[14][4],matriz[14][5],b[0],p[0]);

                                printf("\n\ndigite a combinacao:  ");
                                scanf("%i%i%i%i%i%i",&matriz[1][0],&matriz[1][1],&matriz[1][2],&matriz[1][3],&matriz[1][4],&matriz[1][5]);
                                pontuacao--;

                                printf("\n\n\t\t\tGAME OVER!\n\n");
                                printf("\t       A senha gerada foi:  ");

                                for (i = 0; i < 6; i++){
                                    printf("%d ", vet[i]);
                                }

                                printf("\n\n");

                                printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                printf("\n\n");
                                getchar();
                                ptotal = ptotal + pontuacao;
                                pontuacao = 14;

                                l++;
                                system("pause");
                                break;
                            }

                            if (jogatinas == rodada){

                                int replay;
                                system("cls");
                                printf("\n\n");
                                printf("\t\t\t\t  FIM DE JOGO!\n\t\t\t       OBRIGADO POR JOGAR!\n");
                                printf("\n\n\t\t\tA pontuacao total eh %d pontos!\n\n", ptotal);

                                printf("\t\t\t     Deseja jogar novamente? ");
                                ALTERRADADIF3:
                                printf("\n\n\n| Aperte 1 para jogar novamente |\n\n| Aperte 0 para voltar ao menu  |\n\n");
                                printf("> ");
                                scanf("%d", &replay);

                                if (replay == 1){
                                    rodada = 1;
                                    goto PLAYAGAINDIF3;
                                }
                                else if (replay == 0){
                                    menu();
                                }
                                else if (replay != 0 || replay != 1){
                                    system("cls");
                                    printf("\n\n\t\t\tDigite uma alternativa valida!");
                                    goto ALTERRADADIF3;
                                }
                            }
                        }
                    }               
                }
            }
            else if (optipogame == 1){               //JOGADOR CONTRA JOGADOR//
                config();
                scanf("%i", &dificuldade);
                if (dificuldade == 1){                  //DIFICULDADE FÁCIL
                    PLAYAGAINJOGADORES:
                    system("cls");

                    int jogatinas, forabug, rodada = 0, repeticao, ptsj1 = 0, ptsj2 = 0;

                    rodada = 0;
                    system("cls");
                    printf("\n\t\t BEM VINDOS, JOGADORES!");
                    printf("\n\t Quantas vezes o MasterMind sera jogado?\n\tInsira a quantidade de vezes em numero par: ");
                    scanf("%d", &jogatinas);
                    forabug = jogatinas;

                    system("cls");
                    printf("\n\n\tJogadores, a senha tera numeros repetidos? \n");
                    printf("\n\n| Aperte 1 para NAO repetir os numeros da senha |");
                    printf("\n\n|   Aperte 2 para REPETIR os numeros da senha   |");
                    printf("\n\n> ");
                    scanf("%d", &repeticao);

                    int l = 0, matriz[TAM][TAM], pontuacao = 10, ptotal = 0, auxptotal = 0, parador = 0;
                    int i = 0, vet[TAM], senhaj1[TAM], jogador = 0;            

                    if (repeticao == 1 || repeticao == 2){

                        while(parador < jogatinas){

                            parador++;
                            jogador++;
                            rodada=0;

                            for(int o = 0; o < jogatinas; o++){

                                if (jogador == 1){
                                    system("cls");
                                    printf("\n\n\t\t\t   ATENCAO!");
                                    printf("\n\n\t\t JOGADOR 2 colocara uma senha! \n\t\tJOGADOR 1, NAO olhe para a tela!");
                                    printf("\n\n");
                                    system("pause");
                                }

                                if(jogador == 2){
                                    system("cls");
                                    printf("\n\n\t\t\t   ATENCAO!");
                                    printf("\n\n\t\t JOGADOR 1 colocara uma senha! \n\t\tJOGADOR 2, NAO olhe para a tela!");
                                    printf("\n\n");
                                    system("pause");
                                }
                                SENHANOREPEAT:
                                system("cls");
                                if (repeticao == 1){
                                    printf("\n\n\t        Insira uma senha SEM REPETICAO: ");
                                }
                                else if (repeticao == 2){
                                    printf("\n\n\t        Insira uma senha de sua escolha: ");
                                }
                                printf("\n\tPS: coloque os numeros entre espacos. EX: 0 1 2 3 ");
                                printf("\n\t          Numeros validos de 0 a 5");
                                printf("\n\n> ");
                                scanf("%d%d%d%d", &vet[0], &vet[1], &vet[2], &vet[3]);

                                if (vet[0] > 5 || vet[1] > 5 || vet[2] > 5 || vet[3] > 5){
                                    printf("\n\n\t\tDigite uma senha entre 0 e 5!\n\n\n");
                                    system("pause");
                                    goto SENHANOREPEAT;
                                }

                                if (repeticao == 1){
                                    if (vet[0] == vet[1] || vet[0] == vet[2] || vet[0] == vet[3] || vet[1] == vet[2] || vet[1] == vet[3] || vet[2] == vet[3]){
                                        printf("\n\n\t\tDigite uma senha SEM REPETICAO!\n\n\n");
                                        system("pause");
                                        goto SENHANOREPEAT;
                                    }
                                }

                                while (l < jogatinas){
                                    system("cls");

                                    printf("\n\n\t\t\tJOGADOR %d, voce jogara por %d rodadas!", jogador, forabug);
                                    rodada++;
                                    printf("\n\t\t\t            Rodada %d", rodada);
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || - - - - ||         |\n");
                                    printf("        || - - - - ||         |\n");
                                    printf("        || - - - - ||         |\n");
                                    printf("        || - - - - ||         |\n");
                                    printf("        || - - - - ||         |\t\tSEJA BEM-VINDO!\n");
                                    printf("        || - - - - ||         |\t\tMASTERMIND GAME\n");
                                    printf("        || - - - - ||         |\n");
                                    printf("        || - - - - ||         |\n");
                                    printf("        || - - - - ||         |\n");

                                    printf("\n\ndigite a combinacao:  ");
                                    scanf("%i%i%i%i",&matriz[10][0],&matriz[10][1],&matriz[10][2],&matriz[10][3]);

                                    if (vet[0] == matriz[10][0] && vet[1] == matriz[10][1] && vet[2] == matriz[10][2] && vet[3] == matriz[10][3]){
                                        printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                        printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                        printf("\n\n");
                                        
                                        if (jogador == 1){
                                            ptsj1 += pontuacao;
                                        }
                                        if (jogador == 2){
                                            ptsj2 += pontuacao;
                                        }
                                        
                                        pontuacao = 10;
                                        system("pause");
                                        break;
                                    }

                                    int aux3[TAM], b[TAM],p[TAM], veta[TAM];

                                        b[0]=0;
                                        p[0]=0;

                                        for(int i=0; i<4; i++){
                                        veta[i]=0;
                                        aux3[i]=0;
                                        }

                                        for(int i=0; i<4; i++){
                                            if(matriz[10][i]==vet[i]){

                                                veta[i]=1;
                                                aux3[i]=1;
                                                p[0]++;
                                            }
                                        }
                                        for(int i=0; i<4; i++){
                                            for(int j=0; j<4; j++){
                                                if(matriz[10][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                    aux3[i]=0;
                                                    veta[i]=1;
                                                    b[0]++;
                                                }
                                            }
                                        }

                                    system("cls");
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || - - - - ||         |\n");
                                    printf("        || - - - - ||         |\n");
                                    printf("        || - - - - ||         |\t\t %d = BRANCO.\n", b[0]);
                                    printf("        || - - - - ||         |\t\t %d = PRETO.\n", p[0]);
                                    printf("        || - - - - ||         |\n");
                                    printf("        || - - - - ||         |\n");
                                    printf("        || - - - - ||         |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n");
                                    printf("        || - - - - ||         |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n");
                                    printf("        || - - - - ||         |\n");
                                    printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],b[0],p[0]);

                                    printf("\n\ndigite a combinacao:  ");
                                    scanf("%i%i%i%i",&matriz[9][0],&matriz[9][1],&matriz[9][2],&matriz[9][3]);
                                    pontuacao--;

                                    if (vet[0] == matriz[9][0] && vet[1] == matriz[9][1] && vet[2] == matriz[9][2] && vet[3] == matriz[9][3]){
                                        printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                        printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                        printf("\n\n");

                                        if (jogador == 1){
                                            ptsj1 += pontuacao;
                                        }
                                        if (jogador == 2){
                                            ptsj2 += pontuacao;
                                        }

                                        system("pause");
                                        pontuacao = 10;
                                        break;
                                    }

                                        b[1]=0;
                                        p[1]=0;

                                        for(int i=0; i<4; i++){
                                        veta[i]=0;
                                        aux3[i]=0;
                                        }

                                        for(int i=0; i<4; i++){
                                            if(matriz[9][i]==vet[i]){

                                                veta[i]=1;
                                                aux3[i]=1;
                                                p[1]++;
                                            }
                                        }
                                        for(int i=0; i<4; i++){
                                            for(int j=0; j<4; j++){
                                                if(matriz[9][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                    aux3[i]=0;
                                                    veta[i]=1;
                                                    b[1]++;
                                                }
                                            }
                                        }

                                    system("cls");
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || - - - - ||         |\n");
                                    printf("        || - - - - ||         |\n");
                                    printf("        || - - - - ||         |\t\t %d = BRANCO.\n", b[1]);
                                    printf("        || - - - - ||         |\t\t %d = PRETO.\n", p[1]);
                                    printf("        || - - - - ||         |\n");
                                    printf("        || - - - - ||         |\n");
                                    printf("        || - - - - ||         |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n");
                                    printf("        || - - - - ||         |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n");
                                    printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],b[1],p[1]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],b[0],p[0]);

                                    printf("\n\ndigite a combinacao:  ");
                                    scanf("%i%i%i%i",&matriz[8][0],&matriz[8][1],&matriz[8][2],&matriz[8][3]);
                                    pontuacao--;

                                    if (vet[0] == matriz[8][0] && vet[1] == matriz[8][1] && vet[2] == matriz[8][2] && vet[3] == matriz[8][3]){
                                        printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                        printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                        printf("\n\n");
                                        
                                        if (jogador == 1){
                                            ptsj1 += pontuacao;
                                        }
                                        if (jogador == 2){
                                            ptsj2 += pontuacao;
                                        }
                                        
                                        system("pause");
                                        pontuacao = 10;
                                        break;
                                    }

                                        b[2]=0;
                                        p[2]=0;

                                        for(int i=0; i<4; i++){
                                        veta[i]=0;
                                        aux3[i]=0;
                                    }

                                    for(int i=0; i<4; i++){
                                            if(matriz[8][i]==vet[i]){

                                                veta[i]=1;
                                                aux3[i]=1;
                                                p[2]++;
                                            }
                                        }
                                        for(int i=0; i<4; i++){
                                            for(int j=0; j<4; j++){
                                                if(matriz[8][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                    aux3[i]=0;
                                                    veta[i]=1;
                                                    b[2]++;
                                                }
                                            }
                                        }

                                    system("cls");
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || - - - - ||         |\n");
                                    printf("        || - - - - ||         |\n");
                                    printf("        || - - - - ||         |\t\t %d = BRANCO.\n", b[2]);
                                    printf("        || - - - - ||         |\t\t %d = PRETO.\n", p[2]);
                                    printf("        || - - - - ||         |\n");
                                    printf("        || - - - - ||         |\n");
                                    printf("        || - - - - ||         |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n");
                                    printf("        || %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],b[2],p[2]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],b[1],p[1]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],b[0],p[0]);

                                    printf("\n\ndigite a combinacao:  ");
                                    scanf("%i%i%i%i",&matriz[7][0],&matriz[7][1],&matriz[7][2],&matriz[7][3]);
                                    pontuacao--;

                                    if (vet[0] == matriz[7][0] && vet[1] == matriz[7][1] && vet[2] == matriz[7][2] && vet[3] == matriz[7][3]){
                                        printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                        printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                        printf("\n\n");
                                        
                                        if (jogador == 1){
                                            ptsj1 += pontuacao;
                                        }
                                        if (jogador == 2){
                                            ptsj2 += pontuacao;
                                        }
                                        
                                        system("pause");
                                        pontuacao = 10;
                                        break;
                                    }

                                        b[3]=0;
                                        p[3]=0;

                                    for(int i=0; i<4; i++){
                                        veta[i]=0;
                                        aux3[i]=0;
                                    }


                                    for(int i=0; i<4; i++){
                                            if(matriz[7][i]==vet[i]){

                                                veta[i]=1;
                                                aux3[i]=1;
                                                p[3]++;
                                            }
                                        }
                                        for(int i=0; i<4; i++){
                                            for(int j=0; j<4; j++){
                                                if(matriz[7][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                    aux3[i]=0;
                                                    veta[i]=1;
                                                    b[3]++;
                                                }
                                            }
                                        }

                                    system("cls");
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || - - - - ||         |\n");
                                    printf("        || - - - - ||         |\n");
                                    printf("        || - - - - ||         |\t\t %d = BRANCO.\n", b[3]);
                                    printf("        || - - - - ||         |\t\t %d = PRETO.\n", p[3]);
                                    printf("        || - - - - ||         |\n");
                                    printf("        || - - - - ||         |\n");
                                    printf("        || %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],b[3],p[3]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],b[2],p[2]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],b[1],p[1]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],b[0],p[0]);

                                    printf("\n\ndigite a combinacao:  ");
                                    scanf("%i%i%i%i",&matriz[6][0],&matriz[6][1],&matriz[6][2],&matriz[6][3]);
                                    pontuacao--;

                                    if (vet[0] == matriz[6][0] && vet[1] == matriz[6][1] && vet[2] == matriz[6][2] && vet[3] == matriz[6][3]){
                                        printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                        printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                        printf("\n\n");
                                        
                                        if (jogador == 1){
                                            ptsj1 += pontuacao;
                                        }
                                        if (jogador == 2){
                                            ptsj2 += pontuacao;
                                        }
                                        
                                        system("pause");
                                        pontuacao = 10;
                                        break;
                                    }

                                        b[4]=0;
                                        p[4]=0;

                                        for(int i=0; i<4; i++){
                                        veta[i]=0;
                                        aux3[i]=0;
                                    }

                                    for(int i=0; i<4; i++){
                                            if(matriz[6][i]==vet[i]){

                                                veta[i]=1;
                                                aux3[i]=1;
                                                p[4]++;
                                            }
                                        }
                                        for(int i=0; i<4; i++){
                                            for(int j=0; j<4; j++){
                                                if(matriz[6][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                    aux3[i]=0;
                                                    veta[i]=1;
                                                    b[4]++;
                                                }
                                            }
                                        }

                                    system("cls");
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || - - - - ||         |\n");
                                    printf("        || - - - - ||         |\n");
                                    printf("        || - - - - ||         |\t\t %d = BRANCO.\n", b[4]);
                                    printf("        || - - - - ||         |\t\t %d = PRETO.\n", p[4]);
                                    printf("        || - - - - ||         |\n");
                                    printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[6][0],matriz[6][1],matriz[6][2],matriz[6][3],b[4],p[4]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],b[3],p[3]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],b[2],p[2]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],b[1],p[1]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],b[0],p[0]);

                                    printf("\n\ndigite a combinacao:  ");
                                    scanf("%i%i%i%i",&matriz[5][0],&matriz[5][1],&matriz[5][2],&matriz[5][3]);
                                    pontuacao--;

                                    if (vet[0] == matriz[5][0] && vet[1] == matriz[5][1] && vet[2] == matriz[5][2] && vet[3] == matriz[5][3]){
                                        printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                        printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                        printf("\n\n");
                                        
                                        if (jogador == 1){
                                            ptsj1 += pontuacao;
                                        }
                                        if (jogador == 2){
                                            ptsj2 += pontuacao;
                                        }
                                        
                                        system("pause");
                                        pontuacao = 10;
                                        break;
                                    }

                                        b[5]=0;
                                        p[5]=0;


                                        for(int i=0; i<4; i++){
                                        veta[i]=0;
                                        aux3[i]=0;
                                    }



                                    for(int i=0; i<4; i++){
                                            if(matriz[5][i]==vet[i]){

                                                veta[i]=1;
                                                aux3[i]=1;
                                                p[5]++;
                                            }
                                        }
                                        for(int i=0; i<4; i++){
                                            for(int j=0; j<4; j++){
                                                if(matriz[5][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                    aux3[i]=0;
                                                    veta[i]=1;
                                                    b[5]++;
                                                }
                                            }
                                        }

                                    system("cls");
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || - - - - ||         |\n");
                                    printf("        || - - - - ||         |\n");
                                    printf("        || - - - - ||         |\t\t %d = BRANCO.\n", b[5]);
                                    printf("        || - - - - ||         |\t\t %d = PRETO.\n", p[5]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[5][0],matriz[5][1],matriz[5][2],matriz[5][3],b[5],p[5]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[6][0],matriz[6][1],matriz[6][2],matriz[6][3],b[4],p[4]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],b[3],p[3]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],b[2],p[2]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],b[1],p[1]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],b[0],p[0]);

                                    printf("\n\ndigite a combinacao:  ");
                                    scanf("%i%i%i%i",&matriz[4][0],&matriz[4][1],&matriz[4][2],&matriz[4][3]);
                                    pontuacao--;

                                    if (vet[0] == matriz[4][0] && vet[1] == matriz[4][1] && vet[2] == matriz[4][2] && vet[3] == matriz[4][3]){
                                        printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                        printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                        printf("\n\n");
                                        
                                        if (jogador == 1){
                                            ptsj1 += pontuacao;
                                        }
                                        if (jogador == 2){
                                            ptsj2 += pontuacao;
                                        }
                                        
                                        system("pause");
                                        pontuacao = 10;
                                        break;
                                    }


                                        b[6]=0;
                                        p[6]=0;

                                        for(int i=0; i<4; i++){
                                        veta[i]=0;
                                        aux3[i]=0;
                                    }

                                    for(int i=0; i<4; i++){
                                            if(matriz[4][i]==vet[i]){

                                                veta[i]=1;
                                                aux3[i]=1;
                                                p[6]++;
                                            }
                                        }
                                        for(int i=0; i<4; i++){
                                            for(int j=0; j<4; j++){
                                                if(matriz[4][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                    aux3[i]=0;
                                                    veta[i]=1;
                                                    b[6]++;
                                                }
                                            }
                                        }

                                    system("cls");
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || - - - - ||         |\n");
                                    printf("        || - - - - ||         |\n");
                                    printf("        || - - - - ||         |\t\t %d = BRANCO.\n", b[6]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\t\t %d = PRETO.\n",matriz[4][0],matriz[4][1],matriz[4][2],matriz[4][3],b[6],p[6], p[6]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[5][0],matriz[5][1],matriz[5][2],matriz[5][3],b[5],p[5]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[6][0],matriz[6][1],matriz[6][2],matriz[6][3],b[4],p[4]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],b[3],p[3]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],b[2],p[2]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],b[1],p[1]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],b[0],p[0]);

                                    printf("\n\ndigite a combinacao:  ");
                                    scanf("%i%i%i%i",&matriz[3][0],&matriz[3][1],&matriz[3][2],&matriz[3][3]);
                                    pontuacao--;

                                    if (vet[0] == matriz[3][0] && vet[1] == matriz[3][1] && vet[2] == matriz[3][2] && vet[3] == matriz[3][3]){
                                        printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                        printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                        printf("\n\n");
                                        
                                        if (jogador == 1){
                                            ptsj1 += pontuacao;
                                        }
                                        if (jogador == 2){
                                            ptsj2 += pontuacao;
                                        }
                                        
                                        system("pause");
                                        pontuacao = 10;
                                        break;
                                    }

                                        b[7]=0;
                                        p[7]=0;

                                        for(int i=0; i<4; i++){
                                        veta[i]=0;
                                        aux3[i]=0;
                                    }

                                    for(int i=0; i<4; i++){
                                            if(matriz[3][i]==vet[i]){

                                                veta[i]=1;
                                                aux3[i]=1;
                                                p[7]++;
                                            }
                                        }
                                        for(int i=0; i<4; i++){
                                            for(int j=0; j<4; j++){
                                                if(matriz[3][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                    aux3[i]=0;
                                                    veta[i]=1;
                                                    b[7]++;
                                                }
                                            }
                                        }

                                    system("cls");
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || - - - - ||         |\n");
                                    printf("        || - - - - ||         |\n");
                                    printf("        || %i %i %i %i || B:%i P:%i |\t\t %d = BRANCO.\n",matriz[3][0],matriz[3][1],matriz[3][2],matriz[3][3],b[7],p[7],b[7]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\t\t %d = PRETO.\n",matriz[4][0],matriz[4][1],matriz[4][2],matriz[4][3],b[6],p[6], p[7]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[5][0],matriz[5][1],matriz[5][2],matriz[5][3],b[5],p[5]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[6][0],matriz[6][1],matriz[6][2],matriz[6][3],b[4],p[4]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],b[3],p[3]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],b[2],p[2]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],b[1],p[1]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],b[0],p[0]);

                                    printf("\n\ndigite a combinacao:  ");
                                    scanf("%i%i%i%i",&matriz[2][0],&matriz[2][1],&matriz[2][2],&matriz[2][3]);
                                    pontuacao--;

                                    if (vet[0] == matriz[2][0] && vet[1] == matriz[2][1] && vet[2] == matriz[2][2] && vet[3] == matriz[2][3]){
                                        printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                        printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                        printf("\n\n");
                                        
                                        if (jogador == 1){
                                            ptsj1 += pontuacao;
                                        }
                                        if (jogador == 2){
                                            ptsj2 += pontuacao;
                                        }
                                        
                                        system("pause");
                                        pontuacao = 10;
                                        break;
                                    }

                                        b[8]=0;
                                        p[8]=0;

                                        for(int i=0; i<4; i++){
                                        veta[i]=0;
                                        aux3[i]=0;
                                    }

                                    for(int i=0; i<4; i++){
                                            if(matriz[2][i]==vet[i]){

                                                veta[i]=1;
                                                aux3[i]=1;
                                                p[8]++;
                                            }
                                        }
                                        for(int i=0; i<4; i++){
                                            for(int j=0; j<4; j++){
                                                if(matriz[2][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                    aux3[i]=0;
                                                    veta[i]=1;
                                                    b[8]++;
                                                }
                                            }
                                        }

                                    system("cls");
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || - - - - ||         |\n");
                                    printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[2][0],matriz[2][1],matriz[2][2],matriz[2][3],b[8],p[8]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\t\t %d = BRANCO.\n",matriz[3][0],matriz[3][1],matriz[3][2],matriz[3][3],b[7],p[7], b[8]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\t\t %d = PRETO.\n",matriz[4][0],matriz[4][1],matriz[4][2],matriz[4][3],b[6],p[6],p[8]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[5][0],matriz[5][1],matriz[5][2],matriz[5][3],b[5],p[5]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[6][0],matriz[6][1],matriz[6][2],matriz[6][3],b[4],p[4]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],b[3],p[3]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],b[2],p[2]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],b[1],p[1]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],b[0],p[0]);

                                    printf("\n\ndigite a combinacao:  ");
                                    scanf("%i%i%i%i",&matriz[1][0],&matriz[1][1],&matriz[1][2],&matriz[1][3]);
                                    pontuacao--;

                                    if (vet[0] == matriz[1][0] && vet[1] == matriz[1][1] && vet[2] == matriz[1][2] && vet[3] == matriz[1][3]){
                                        printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                        printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                        printf("\n\n");
                                        
                                        if (jogador == 1){
                                            ptsj1 += pontuacao;
                                        }
                                        if (jogador == 2){
                                            ptsj2 += pontuacao;
                                        }
                                        
                                        system("pause");
                                        pontuacao = 10;
                                        break;
                                    }

                                        b[9]=0;
                                        p[9]=0;

                                        for(int i=0; i<4; i++){
                                        veta[i]=0;
                                        aux3[i]=0;
                                    }

                                    for(int i=0; i<4; i++){
                                            if(matriz[1][i]==vet[i]){

                                                veta[i]=1;
                                                aux3[i]=1;
                                                p[9]++;
                                            }
                                        }
                                        for(int i=0; i<4; i++){
                                            for(int j=0; j<4; j++){
                                                if(matriz[1][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                    aux3[i]=0;
                                                    veta[i]=1;
                                                    b[9]++;
                                                }
                                            }
                                        }

                                    system("cls");
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[1][0],matriz[1][1],matriz[1][2],matriz[1][3],b[9],p[9]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[2][0],matriz[2][1],matriz[2][2],matriz[2][3],b[8],p[8]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\t\t %d = BRANCO.\n",matriz[3][0],matriz[3][1],matriz[3][2],matriz[3][3],b[7],p[7], b[9]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\t\t %d = PRETO.\n",matriz[4][0],matriz[4][1],matriz[4][2],matriz[4][3],b[6],p[6], p[9]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[5][0],matriz[5][1],matriz[5][2],matriz[5][3],b[5],p[5]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[6][0],matriz[6][1],matriz[6][2],matriz[6][3],b[4],p[4]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],b[3],p[3]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],b[2],p[2]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],b[1],p[1]);
                                    printf("        || %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],b[0],p[0]);


                                    printf("\n\n\t\t\tGAME OVER!\n\n");
                                    printf("\t       A senha gerada foi:  ");

                                    for (i = 0; i < 4; i++){
                                    printf("%d ", vet[i]);
                                    }

                                    printf("\n\n");

                                    pontuacao--;

                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    getchar();

                                    pontuacao = 10;
                                    l++;
                                    system("pause");
                                    break;
                                }
                            }
                            
                            if(parador == 2){
                                break;
                            }

                        }

                        int comeback;

                        system("cls");
                        endscreen(ptsj1, ptsj2);
                        scanf("%d", &comeback);

                        ALTERRADAJ2:
                        printf("\n\n\n| Aperte 1 para jogar novamente |\n\n| Aperte 0 para voltar ao menu  |\n\n");
                        printf("> ");
                        getchar();


                        if (comeback == 1){
                            rodada = 1;
                            goto PLAYAGAINJOGADORES;
                        }
                        else if (comeback == 0){
                            menu();
                        }
                        else if (comeback != 0 || comeback != 1){
                            system("cls");
                            printf("\n\n\t\t\tDigite uma alternativa valida!");
                            goto ALTERRADAJ2;
                        }
                    }
                }
                else if (dificuldade == 2){             //DIFICULDADE MÉDIA
                    PLAYAGAINJOGADORESDIF2:
                    system("cls");

                    int jogatinas, forabug, rodada = 0, repeticao, ptsj1 = 0, ptsj2 = 0;

                    rodada = 0;
                    system("cls");
                    printf("\n\t\t BEM VINDOS, JOGADORES!");
                    printf("\n\t Quantas vezes o MasterMind sera jogado?\n\tInsira a quantidade de vezes em numero par: ");
                    scanf("%d", &jogatinas);
                    forabug = jogatinas;

                    system("cls");
                    printf("\n\n\tJogadores, a senha tera numeros repetidos? \n");
                    printf("\n\n| Aperte 1 para NAO repetir os numeros da senha |");
                    printf("\n\n|   Aperte 2 para REPETIR os numeros da senha   |");
                    printf("\n\n> ");
                    scanf("%d", &repeticao);

                    int l = 0, matriz[TAM][TAM], pontuacao = 12, ptotal = 0, auxptotal = 0, parador = 0;
                    int i = 0, vet[TAM], senhaj1[TAM], jogador = 0;            

                    if (repeticao == 1 || repeticao == 2){

                        
                        while(parador < jogatinas){

                            parador++;
                            jogador++;
                            rodada=0;

                            for(int o = 0; o < jogatinas; o++){

                                if (jogador == 1){
                                    system("cls");
                                    printf("\n\n\t\t\t   ATENCAO!");
                                    printf("\n\n\t\t JOGADOR 2 colocara uma senha! \n\t\tJOGADOR 1, NAO olhe para a tela!");
                                    printf("\n\n");
                                    system("pause");
                                }

                                if(jogador == 2){
                                    system("cls");
                                    printf("\n\n\t\t\t   ATENCAO!");
                                    printf("\n\n\t\t JOGADOR 1 colocara uma senha! \n\t\tJOGADOR 2, NAO olhe para a tela!");
                                    printf("\n\n");
                                    system("pause");
                                }
                                SENHANOREPEATDIF2:
                                system("cls");
                                if (repeticao == 1){
                                    printf("\n\n\t        Insira uma senha SEM REPETICAO: ");
                                }
                                else if (repeticao == 2){
                                    printf("\n\n\t        Insira uma senha de sua escolha: ");
                                }
                                printf("\n\tPS: coloque os numeros entre espacos. EX: 0 1 2 3 4");
                                printf("\n\t          Numeros validos de 0 a 6");
                                printf("\n\n> ");
                                scanf("%d%d%d%d%d", &vet[0], &vet[1], &vet[2], &vet[3], &vet[4]);

                                if (vet[0] > 6 || vet[1] > 6 || vet[2] > 6 || vet[3] > 6 || vet[4] > 6){
                                    printf("\n\n\t\tDigite uma senha entre 0 e 6!\n\n\n");
                                    system("pause");
                                    goto SENHANOREPEATDIF2;
                                }

                                if (repeticao == 1){
                                    if (vet[0] == vet[1] || vet[0] == vet[2] || vet[0] == vet[3] || vet[0] == vet[4] || vet[1] == vet[2] || vet[1] == vet[3] || vet[1] == vet[4] || vet[2] == vet[3] || vet[2] == vet[4] || vet[3] == vet[4]){
                                        printf("\n\n\t\tDigite uma senha SEM REPETICAO!\n\n\n");
                                        system("pause");
                                        goto SENHANOREPEATDIF2;
                                    }
                                }

                                while (l < jogatinas){
                                    system("cls");

                                    printf("\n\n\t\t\tJOGADOR %d, voce jogara por %d rodadas!", jogador, forabug);
                                    rodada++;
                                    printf("\n\t\t\t            Rodada %d", rodada);
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\t\tSEJA BEM-VINDO!\n");
                                    printf("        || - - - - - ||         |\t\tMASTERMIND GAME\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");

                                    printf("\n\ndigite a combinacao:  ");
                                    scanf("%i%i%i%i%i",&matriz[12][0],&matriz[12][1],&matriz[12][2],&matriz[12][3],&matriz[12][4]);

                                    if (vet[0] == matriz[12][0] && vet[1] == matriz[12][1] && vet[2] == matriz[12][2] && vet[3] == matriz[12][3] && vet[4] == matriz[12][4]){
                                        printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                        printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                        printf("\n\n");
                                        
                                        if (jogador == 1){
                                            ptsj1 += pontuacao;
                                        }
                                        if (jogador == 2){
                                            ptsj2 += pontuacao;
                                        }
                                        
                                        pontuacao = 12;
                                        system("pause");
                                        break;
                                    }

                                    int aux3[TAM], b[TAM],p[TAM], veta[TAM];

                                        b[0]=0;
                                        p[0]=0;

                                    for(int i=0; i<5; i++){
                                        veta[i]=0;
                                        aux3[i]=0;
                                    }

                                    for(int i=0; i<5; i++){
                                        if(matriz[12][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[0]++;
                                        }
                                    }
                                    for(int i=0; i<5; i++){
                                        for(int j=0; j<5; j++){
                                            if(matriz[12][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[0]++;
                                            }
                                        }
                                    }

                                    system("cls");
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\t\t %d = BRANCO.\n", b[0]);
                                    printf("        || - - - - - ||         |\t\t %d = PRETO.\n", p[0]);
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n");
                                    printf("        || - - - - - ||         |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],b[0],p[0]);

                                    printf("\n\ndigite a combinacao:  ");
                                    scanf("%i%i%i%i%i",&matriz[11][0],&matriz[11][1],&matriz[11][2],&matriz[11][3],&matriz[11][4]);
                                    pontuacao--;

                                    if (vet[0] == matriz[11][0] && vet[1] == matriz[11][1] && vet[2] == matriz[11][2] && vet[3] == matriz[11][3] && vet[4] == matriz[11][4]){
                                        printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                        printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                        printf("\n\n");

                                        if (jogador == 1){
                                            ptsj1 += pontuacao;
                                        }
                                        if (jogador == 2){
                                            ptsj2 += pontuacao;
                                        }

                                        system("pause");
                                        pontuacao = 12;
                                        break;
                                    }

                                        b[1]=0;
                                        p[1]=0;

                                    for(int i=0; i<5; i++){
                                        veta[i]=0;
                                        aux3[i]=0;
                                    }

                                    for(int i=0; i<5; i++){
                                        if(matriz[11][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[1]++;
                                        }
                                    }
                                    for(int i=0; i<5; i++){
                                        for(int j=0; j<5; j++){
                                            if(matriz[11][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[1]++;
                                            }
                                        }
                                    }

                                    system("cls");
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\t\t %d = BRANCO.\n", b[1]);
                                    printf("        || - - - - - ||         |\t\t %d = PRETO.\n", p[1]);
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n");
                                    printf("        || - - - - - ||         |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n");
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],b[1],p[1]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],b[0],p[0]);

                                    printf("\n\ndigite a combinacao:  ");
                                    scanf("%i%i%i%i%i",&matriz[10][0],&matriz[10][1],&matriz[10][2],&matriz[10][3],&matriz[10][4]);
                                    pontuacao--;

                                    if (vet[0] == matriz[10][0] && vet[1] == matriz[10][1] && vet[2] == matriz[10][2] && vet[3] == matriz[10][3] && vet[4] == matriz[10][4]){
                                        printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                        printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                        printf("\n\n");

                                        if (jogador == 1){
                                            ptsj1 += pontuacao;
                                        }
                                        if (jogador == 2){
                                            ptsj2 += pontuacao;
                                        }

                                        system("pause");
                                        pontuacao = 12;
                                        break;
                                    }

                                        b[2]=0;
                                        p[2]=0;

                                    for(int i=0; i<5; i++){
                                        veta[i]=0;
                                        aux3[i]=0;
                                    }

                                    for(int i=0; i<5; i++){
                                        if(matriz[10][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[2]++;
                                        }
                                    }
                                    for(int i=0; i<5; i++){
                                        for(int j=0; j<5; j++){
                                            if(matriz[10][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[2]++;
                                            }
                                        }
                                    }

                                    system("cls");
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\t\t %d = BRANCO.\n", b[2]);
                                    printf("        || - - - - - ||         |\t\t %d = PRETO.\n", p[2]);
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n");
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],b[2],p[2]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],b[1],p[1]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],b[0],p[0]);

                                    printf("\n\ndigite a combinacao:  ");
                                    scanf("%i%i%i%i%i",&matriz[9][0],&matriz[9][1],&matriz[9][2],&matriz[9][3],&matriz[9][4]);
                                    pontuacao--;

                                    if (vet[0] == matriz[9][0] && vet[1] == matriz[9][1] && vet[2] == matriz[9][2] && vet[3] == matriz[9][3] && vet[4] == matriz[9][4]){
                                        printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                        printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                        printf("\n\n");
                                        
                                        if (jogador == 1){
                                            ptsj1 += pontuacao;
                                        }
                                        if (jogador == 2){
                                            ptsj2 += pontuacao;
                                        }
                                        
                                        system("pause");
                                        pontuacao = 12;
                                        break;
                                    }

                                        b[3]=0;
                                        p[3]=0;

                                    for(int i=0; i<5; i++){
                                        veta[i]=0;
                                        aux3[i]=0;
                                    }

                                    for(int i=0; i<5; i++){
                                        if(matriz[9][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[3]++;
                                        }
                                    }
                                    for(int i=0; i<5; i++){
                                        for(int j=0; j<5; j++){
                                            if(matriz[9][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[3]++;
                                            }
                                        }
                                    }

                                    system("cls");
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\t\t %d = BRANCO.\n", b[3]);
                                    printf("        || - - - - - ||         |\t\t %d = PRETO.\n", p[3]);
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],matriz[9][4],b[3],p[3]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],b[2],p[2]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],b[1],p[1]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],b[0],p[0]);

                                    printf("\n\ndigite a combinacao:  ");
                                    scanf("%i%i%i%i%i",&matriz[8][0],&matriz[8][1],&matriz[8][2],&matriz[8][3],&matriz[8][4]);
                                    pontuacao--;

                                    if (vet[0] == matriz[8][0] && vet[1] == matriz[8][1] && vet[2] == matriz[8][2] && vet[3] == matriz[8][3] && vet[4] == matriz[8][4]){
                                        printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                        printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                        printf("\n\n");
                                        
                                        if (jogador == 1){
                                            ptsj1 += pontuacao;
                                        }
                                        if (jogador == 2){
                                            ptsj2 += pontuacao;
                                        }
                                        
                                        system("pause");
                                        pontuacao = 12;
                                        break;
                                    }

                                        b[4]=0;
                                        p[4]=0;

                                    for(int i=0; i<5; i++){
                                        veta[i]=0;
                                        aux3[i]=0;
                                    }

                                    for(int i=0; i<5; i++){
                                        if(matriz[8][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[4]++;
                                        }
                                    }
                                    for(int i=0; i<5; i++){
                                        for(int j=0; j<5; j++){
                                            if(matriz[8][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[4]++;
                                            }
                                        }
                                    }
                                    
                                    system("cls");
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\t\t %d = BRANCO.\n", b[4]);
                                    printf("        || - - - - - ||         |\t\t %d = PRETO.\n", p[4]);
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],matriz[8][4],b[4],p[4]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],matriz[9][4],b[3],p[3]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],b[2],p[2]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],b[1],p[1]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],b[0],p[0]);

                                    printf("\n\ndigite a combinacao:  ");
                                    scanf("%i%i%i%i%i",&matriz[7][0],&matriz[7][1],&matriz[7][2],&matriz[7][3],&matriz[7][4]);
                                    pontuacao--;

                                    if (vet[0] == matriz[7][0] && vet[1] == matriz[7][1] && vet[2] == matriz[7][2] && vet[3] == matriz[7][3] && vet[4] == matriz[7][4]){
                                        printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                        printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                        printf("\n\n");
                                        
                                        if (jogador == 1){
                                            ptsj1 += pontuacao;
                                        }
                                        if (jogador == 2){
                                            ptsj2 += pontuacao;
                                        }
                                        
                                        system("pause");
                                        pontuacao = 12;
                                        break;
                                    }

                                        b[5]=0;
                                        p[5]=0;


                                    for(int i=0; i<5; i++){
                                        veta[i]=0;
                                        aux3[i]=0;
                                    }

                                    for(int i=0; i<5; i++){
                                        if(matriz[7][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[5]++;
                                        }
                                    }
                                    for(int i=0; i<5; i++){
                                        for(int j=0; j<5; j++){
                                            if(matriz[7][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[5]++;
                                            }
                                        }
                                    }

                                    system("cls");
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\t\t %d = BRANCO.\n", b[5]);
                                    printf("        || - - - - - ||         |\t\t %d = PRETO.\n", p[5]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],matriz[7][4],b[5],p[5]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],matriz[8][4],b[4],p[4]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],matriz[9][4],b[3],p[3]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],b[2],p[2]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],b[1],p[1]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],b[0],p[0]);

                                    printf("\n\ndigite a combinacao:  ");
                                    scanf("%i%i%i%i%i",&matriz[6][0],&matriz[6][1],&matriz[6][2],&matriz[6][3],&matriz[6][4]);
                                    pontuacao--;
                                    
                                    if (vet[0] == matriz[6][0] && vet[1] == matriz[6][1] && vet[2] == matriz[6][2] && vet[3] == matriz[6][3] && vet[4] == matriz[6][4]){
                                        printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                        printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                        printf("\n\n");
                                        
                                        if (jogador == 1){
                                            ptsj1 += pontuacao;
                                        }
                                        if (jogador == 2){
                                            ptsj2 += pontuacao;
                                        }
                                        
                                        system("pause");
                                        pontuacao = 12;
                                        break;
                                    }

                                        b[6]=0;
                                        p[6]=0;

                                    for(int i=0; i<5; i++){
                                        veta[i]=0;
                                        aux3[i]=0;
                                    }

                                    for(int i=0; i<5; i++){
                                        if(matriz[6][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[6]++;
                                        }
                                    }
                                    for(int i=0; i<5; i++){
                                        for(int j=0; j<5; j++){
                                            if(matriz[6][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[6]++;
                                            }
                                        }
                                    }

                                    system("cls");
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\t\t %d = BRANCO.\n", b[6]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\t\t %d = PRETO.\n",matriz[6][0],matriz[6][1],matriz[6][2],matriz[6][3],matriz[6][4],b[6],p[6], p[6]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],matriz[7][4],b[5],p[5]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],matriz[8][4],b[4],p[4]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],matriz[9][4],b[3],p[3]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],b[2],p[2]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],b[1],p[1]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],b[0],p[0]);

                                    printf("\n\ndigite a combinacao:  ");
                                    scanf("%i%i%i%i%i",&matriz[5][0],&matriz[5][1],&matriz[5][2],&matriz[5][3],&matriz[5][4]);
                                    pontuacao--;

                                    if (vet[0] == matriz[5][0] && vet[1] == matriz[5][1] && vet[2] == matriz[5][2] && vet[3] == matriz[5][3] && vet[4] == matriz[5][4]){
                                        printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                        printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                        printf("\n\n");
                                        
                                        if (jogador == 1){
                                            ptsj1 += pontuacao;
                                        }
                                        if (jogador == 2){
                                            ptsj2 += pontuacao;
                                        }
                                        
                                        system("pause");
                                        pontuacao = 12;
                                        break;
                                    }

                                        b[7]=0;
                                        p[7]=0;

                                    for(int i=0; i<5; i++){
                                        veta[i]=0;
                                        aux3[i]=0;
                                    }

                                    for(int i=0; i<5; i++){
                                        if(matriz[5][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[7]++;
                                        }
                                    }
                                    for(int i=0; i<5; i++){
                                        for(int j=0; j<5; j++){
                                            if(matriz[5][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[7]++;
                                            }
                                        }
                                    }

                                    system("cls");
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\t\t %d = BRANCO.\n",matriz[5][0],matriz[5][1],matriz[5][2],matriz[5][3],matriz[5][4],b[7],p[7],b[7]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\t\t %d = PRETO.\n",matriz[6][0],matriz[6][1],matriz[6][2],matriz[6][3],matriz[6][4],b[6],p[6], p[7]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],matriz[7][4],b[5],p[5]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],matriz[8][4],b[4],p[4]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],matriz[9][4],b[3],p[3]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],b[2],p[2]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],b[1],p[1]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],b[0],p[0]);

                                    printf("\n\ndigite a combinacao:  ");
                                    scanf("%i%i%i%i%i",&matriz[4][0],&matriz[4][1],&matriz[4][2],&matriz[4][3],&matriz[4][4]);
                                    pontuacao--;

                                    if (vet[0] == matriz[4][0] && vet[1] == matriz[4][1] && vet[2] == matriz[4][2] && vet[3] == matriz[4][3] && vet[4] == matriz[4][4]){
                                        printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                        printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                        printf("\n\n");
                                        
                                        if (jogador == 1){
                                            ptsj1 += pontuacao;
                                        }
                                        if (jogador == 2){
                                            ptsj2 += pontuacao;
                                        }
                                        
                                        system("pause");
                                        pontuacao = 12;
                                        break;
                                    }

                                        b[8]=0;
                                        p[8]=0;

                                    for(int i=0; i<5; i++){
                                        veta[i]=0;
                                        aux3[i]=0;
                                    }

                                    for(int i=0; i<5; i++){
                                        if(matriz[4][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[8]++;
                                        }
                                    }
                                    for(int i=0; i<5; i++){
                                        for(int j=0; j<5; j++){
                                            if(matriz[4][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[8]++;
                                            }
                                        }
                                    }

                                    system("cls");
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[4][0],matriz[4][1],matriz[4][2],matriz[4][3],matriz[4][4],b[8],p[8]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\t\t %d = BRANCO.\n",matriz[5][0],matriz[5][1],matriz[5][2],matriz[5][3],matriz[5][4],b[7],p[7],b[8]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\t\t %d = PRETO.\n",matriz[6][0],matriz[6][1],matriz[6][2],matriz[6][3],matriz[6][4],b[6],p[6], p[8]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],matriz[7][4],b[5],p[5]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],matriz[8][4],b[4],p[4]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],matriz[9][4],b[3],p[3]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],b[2],p[2]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],b[1],p[1]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],b[0],p[0]);

                                    printf("\n\ndigite a combinacao:  ");
                                    scanf("%i%i%i%i%i",&matriz[3][0],&matriz[3][1],&matriz[3][2],&matriz[3][3],&matriz[3][4]);
                                    pontuacao--;

                                    if (vet[0] == matriz[3][0] && vet[1] == matriz[3][1] && vet[2] == matriz[3][2] && vet[3] == matriz[3][3] && vet[4] == matriz[3][4]){
                                        printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                        printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                        printf("\n\n");
                                        
                                        if (jogador == 1){
                                            ptsj1 += pontuacao;
                                        }
                                        if (jogador == 2){
                                            ptsj2 += pontuacao;
                                        }
                                        
                                        system("pause");
                                        pontuacao = 12;
                                        break;
                                    }

                                        b[9]=0;
                                        p[9]=0;

                                    for(int i=0; i<5; i++){
                                        veta[i]=0;
                                        aux3[i]=0;
                                    }

                                    for(int i=0; i<5; i++){
                                        if(matriz[3][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[9]++;
                                        }
                                    }
                                    for(int i=0; i<5; i++){
                                        for(int j=0; j<5; j++){
                                            if(matriz[3][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[9]++;
                                            }
                                        }
                                    }

                                    system("cls");
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[3][0],matriz[3][1],matriz[3][2],matriz[3][3],matriz[3][4],b[9],p[9]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[4][0],matriz[4][1],matriz[4][2],matriz[4][3],matriz[4][4],b[8],p[8]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\t\t %d = BRANCO.\n",matriz[5][0],matriz[5][1],matriz[5][2],matriz[5][3],matriz[5][4],b[7],p[7],b[9]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\t\t %d = PRETO.\n",matriz[6][0],matriz[6][1],matriz[6][2],matriz[6][3],matriz[6][4],b[6],p[6], p[9]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],matriz[7][4],b[5],p[5]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],matriz[8][4],b[4],p[4]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],matriz[9][4],b[3],p[3]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],b[2],p[2]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],b[1],p[1]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],b[0],p[0]);

                                    printf("\n\ndigite a combinacao:  ");
                                    scanf("%i%i%i%i%i",&matriz[2][0],&matriz[2][1],&matriz[2][2],&matriz[2][3],&matriz[2][4]);
                                    pontuacao--;

                                    if (vet[0] == matriz[2][0] && vet[1] == matriz[2][1] && vet[2] == matriz[2][2] && vet[3] == matriz[2][3] && vet[4] == matriz[2][4]){
                                        printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                        printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                        printf("\n\n");
                                        
                                        if (jogador == 1){
                                            ptsj1 += pontuacao;
                                        }
                                        if (jogador == 2){
                                            ptsj2 += pontuacao;
                                        }
                                        
                                        system("pause");
                                        pontuacao = 12;
                                        break;
                                    }

                                        b[10]=0;
                                        p[10]=0;

                                    for(int i=0; i<5; i++){
                                        veta[i]=0;
                                        aux3[i]=0;
                                    }

                                    for(int i=0; i<5; i++){
                                        if(matriz[2][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[10]++;
                                        }
                                    }
                                    for(int i=0; i<5; i++){
                                        for(int j=0; j<5; j++){
                                            if(matriz[2][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[10]++;
                                            }
                                        }
                                    }

                                    system("cls");
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || - - - - - ||         |\n");
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[2][0],matriz[2][1],matriz[2][2],matriz[2][3],matriz[2][4],b[10],p[10]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[3][0],matriz[3][1],matriz[3][2],matriz[3][3],matriz[3][4],b[9],p[9]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[4][0],matriz[4][1],matriz[4][2],matriz[4][3],matriz[4][4],b[8],p[8]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\t\t %d = BRANCO.\n",matriz[5][0],matriz[5][1],matriz[5][2],matriz[5][3],matriz[5][4],b[7],p[7],b[10]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\t\t %d = PRETO.\n",matriz[6][0],matriz[6][1],matriz[6][2],matriz[6][3],matriz[6][4],b[6],p[6], p[10]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],matriz[7][4],b[5],p[5]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],matriz[8][4],b[4],p[4]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],matriz[9][4],b[3],p[3]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],b[2],p[2]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],b[1],p[1]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],b[0],p[0]);

                                    printf("\n\ndigite a combinacao:  ");
                                    scanf("%i%i%i%i%i",&matriz[1][0],&matriz[1][1],&matriz[1][2],&matriz[1][3],&matriz[1][4]);
                                    pontuacao--;

                                    if (vet[0] == matriz[1][0] && vet[1] == matriz[1][1] && vet[2] == matriz[1][2] && vet[3] == matriz[1][3] && vet[4] == matriz[1][4]){
                                        printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                        printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                        printf("\n\n");
                                        
                                        if (jogador == 1){
                                            ptsj1 += pontuacao;
                                        }
                                        if (jogador == 2){
                                            ptsj2 += pontuacao;
                                        }
                                        
                                        system("pause");
                                        pontuacao = 12;
                                        break;
                                    }

                                        b[11]=0;
                                        p[11]=0;

                                    for(int i=0; i<5; i++){
                                        veta[i]=0;
                                        aux3[i]=0;
                                    }

                                    for(int i=0; i<5; i++){
                                        if(matriz[1][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[11]++;
                                        }
                                    }
                                    for(int i=0; i<5; i++){
                                        for(int j=0; j<5; j++){
                                            if(matriz[1][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[11]++;
                                            }
                                        }
                                    }

                                    system("cls");
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[1][0],matriz[1][1],matriz[1][2],matriz[1][3],matriz[1][4],b[11],p[11]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[2][0],matriz[2][1],matriz[2][2],matriz[2][3],matriz[2][4],b[10],p[10]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[3][0],matriz[3][1],matriz[3][2],matriz[3][3],matriz[3][4],b[9],p[9]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[4][0],matriz[4][1],matriz[4][2],matriz[4][3],matriz[4][4],b[8],p[8]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\t\t %d = BRANCO.\n",matriz[5][0],matriz[5][1],matriz[5][2],matriz[5][3],matriz[5][4],b[7],p[7],b[11]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\t\t %d = PRETO.\n",matriz[6][0],matriz[6][1],matriz[6][2],matriz[6][3],matriz[6][4],b[6],p[6], p[11]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],matriz[7][4],b[5],p[5]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],matriz[8][4],b[4],p[4]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],matriz[9][4],b[3],p[3]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],b[2],p[2]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],b[1],p[1]);
                                    printf("        || %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],b[0],p[0]);

                                    printf("\n\n\t\t\tGAME OVER!\n\n");
                                    printf("\t       A senha gerada foi:  ");

                                    for (i = 0; i < 5; i++){
                                        printf("%d ", vet[i]);
                                    }

                                    printf("\n\n");

                                    pontuacao--;

                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    getchar();
                                    ptotal = ptotal + pontuacao;
                                    pontuacao = 12;

                                    l++;
                                    system("pause");
                                    break;
                                }
                            }

                            if(parador == 2){
                                break;
                            }

                        }

                        int comeback;

                        system("cls");
                        endscreen(ptsj1, ptsj2);
                        scanf("%d", &comeback);

                        ALTERRADAJ3:
                        printf("\n\n\n| Aperte 1 para jogar novamente |\n\n| Aperte 0 para voltar ao menu  |\n\n");
                        printf("> ");
                        getchar();


                        if (comeback == 1){
                            rodada = 1;
                            goto PLAYAGAINJOGADORESDIF2;
                        }
                        else if (comeback == 0){
                            menu();
                        }
                        else if (comeback != 0 || comeback != 1){
                            system("cls");
                            printf("\n\n\t\t\tDigite uma alternativa valida!");
                            goto ALTERRADAJ3;
                        }
                    }
                }
                else if (dificuldade == 3){             //DIFICULDADE DIFÍCIL
                    PLAYAGAINJOGADORESDIF3:
                    system("cls");

                    int jogatinas, forabug, rodada = 0, repeticao, ptsj1 = 0, ptsj2 = 0;

                    rodada = 0;
                    system("cls");
                    printf("\n\t\t BEM VINDOS, JOGADORES!");
                    printf("\n\t Quantas vezes o MasterMind sera jogado?\n\tInsira a quantidade de vezes em numero par: ");
                    scanf("%d", &jogatinas);
                    forabug = jogatinas;

                    system("cls");
                    printf("\n\n\tJogadores, a senha tera numeros repetidos? \n");
                    printf("\n\n| Aperte 1 para NAO repetir os numeros da senha |");
                    printf("\n\n|   Aperte 2 para REPETIR os numeros da senha   |");
                    printf("\n\n> ");
                    scanf("%d", &repeticao);

                    int l = 0, matriz[TAM][TAM], pontuacao = 14, ptotal = 0, auxptotal = 0, parador = 0;
                    int i = 0, vet[TAM], senhaj1[TAM], jogador = 0;

                    if (repeticao == 1 || repeticao == 2){

                        while(parador < jogatinas){

                            parador++;
                            jogador++;
                            rodada=0;

                            for(int o = 0; o < jogatinas; o++){

                                if (jogador == 1){
                                    system("cls");
                                    printf("\n\n\t\t\t   ATENCAO!");
                                    printf("\n\n\t\t JOGADOR 2 colocara uma senha! \n\t\tJOGADOR 1, NAO olhe para a tela!");
                                    printf("\n\n");
                                    system("pause");
                                }

                                if(jogador == 2){
                                    system("cls");
                                    printf("\n\n\t\t\t   ATENCAO!");
                                    printf("\n\n\t\t JOGADOR 1 colocara uma senha! \n\t\tJOGADOR 2, NAO olhe para a tela!");
                                    printf("\n\n");
                                    system("pause");
                                }
                                SENHANOREPEATDIF3:
                                system("cls");
                                if (repeticao == 1){
                                    printf("\n\n\t        Insira uma senha SEM REPETICAO: ");
                                }
                                else if (repeticao == 2){
                                    printf("\n\n\t        Insira uma senha de sua escolha: ");
                                }
                                printf("\n\tPS: coloque os numeros entre espacos. EX: 0 1 2 3 4 5");
                                printf("\n\t          Numeros validos de 0 a 7");
                                printf("\n\n> ");
                                scanf("%d%d%d%d%d%d", &vet[0], &vet[1], &vet[2], &vet[3], &vet[4], &vet[5]);

                                if (vet[0] > 7 || vet[1] > 7 || vet[2] > 7 || vet[3] > 7 || vet[4] > 7 || vet[5] > 7){
                                    printf("\n\n\t\tDigite uma senha entre 0 e 7!\n\n\n");
                                    system("pause");
                                    goto SENHANOREPEATDIF3;
                                }

                                if (repeticao == 1){
                                    if (vet[0] == vet[1] || vet[0] == vet[2] || vet[0] == vet[3] || vet[0] == vet[4] || vet[0] == vet[5] || vet[1] == vet[2] || vet[1] == vet[3] || vet[1] == vet[4] || vet[1] == vet[5] || vet[2] == vet[3] || vet[2] == vet[4] || vet[2] == vet[5] || vet[3] == vet[4] || vet[3] == vet[5] || vet[4] == vet[5]){
                                        printf("\n\n\t\tDigite uma senha SEM REPETICAO!\n\n\n");
                                        system("pause");
                                        goto SENHANOREPEATDIF3;
                                    }
                                }

                                while (l < jogatinas){
                                    system("cls");

                                    printf("\n\n\t\t\tJOGADOR %d, voce jogara por %d rodadas!", jogador, forabug);
                                    rodada++;
                                    printf("\n\t\t\t            Rodada %d", rodada);
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\t\tSEJA BEM-VINDO!\n");
                                    printf("        || - - - - - - ||         |\t\tMASTERMIND GAME\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("\n\ndigite a combinacao:  ");
                                    scanf("%i%i%i%i%i%i",&matriz[14][0],&matriz[14][1],&matriz[14][2],&matriz[14][3],&matriz[14][4],&matriz[14][5]);

                                    if (vet[0] == matriz[14][0] && vet[1] == matriz[14][1] && vet[2] == matriz[14][2] && vet[3] == matriz[14][3] && vet[4] == matriz[14][4] && vet[5] == matriz[14][5]){
                                        printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                        printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                        printf("\n\n");
                                        
                                        if (jogador == 1){
                                            ptsj1 += pontuacao;
                                        }
                                        if (jogador == 2){
                                            ptsj2 += pontuacao;
                                        }
                                        
                                        pontuacao = 14;
                                        system("pause");
                                        break;
                                    }

                                    int aux3[TAM], b[TAM],p[TAM], veta[TAM];

                                        b[0]=0;
                                        p[0]=0;

                                    for(int i=0; i<6; i++){
                                        veta[i]=0;
                                        aux3[i]=0;
                                    }

                                    for(int i=0; i<6; i++){
                                        if(matriz[14][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[0]++;
                                        }
                                    }
                                    for(int i=0; i<6; i++){
                                        for(int j=0; j<6; j++){
                                            if(matriz[14][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[0]++;
                                            }
                                        }
                                    }

                                    system("cls");
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\t\t %d = BRANCO.\n", b[0]);
                                    printf("        || - - - - - - ||         |\t\t %d = PRETO.\n", p[0]);
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n");
                                    printf("        || - - - - - - ||         |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[14][0],matriz[14][1],matriz[14][2],matriz[14][3],matriz[14][4],matriz[14][5],b[0],p[0]);

                                    printf("\n\ndigite a combinacao:  ");
                                    scanf("%i%i%i%i%i%i",&matriz[13][0],&matriz[13][1],&matriz[13][2],&matriz[13][3],&matriz[13][4],&matriz[13][5]);
                                    pontuacao--;

                                    if (vet[0] == matriz[13][0] && vet[1] == matriz[13][1] && vet[2] == matriz[13][2] && vet[3] == matriz[13][3] && vet[4] == matriz[13][4] && vet[5] == matriz[13][5]){
                                        printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                        printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                        printf("\n\n");

                                        if (jogador == 1){
                                            ptsj1 += pontuacao;
                                        }
                                        if (jogador == 2){
                                            ptsj2 += pontuacao;
                                        }

                                        system("pause");
                                        pontuacao = 14;
                                        break;
                                    }

                                        b[1]=0;
                                        p[1]=0;

                                    for(int i=0; i<6; i++){
                                        veta[i]=0;
                                        aux3[i]=0;
                                    }

                                    for(int i=0; i<6; i++){
                                        if(matriz[13][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[1]++;
                                        }
                                    }
                                    for(int i=0; i<6; i++){
                                        for(int j=0; j<6; j++){
                                            if(matriz[13][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[1]++;
                                            }
                                        }
                                    }

                                    system("cls");
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\t\t %d = BRANCO.\n", b[1]);
                                    printf("        || - - - - - - ||         |\t\t %d = PRETO.\n", p[1]);
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n");
                                    printf("        || - - - - - - ||         |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[13][0],matriz[13][1],matriz[13][2],matriz[13][3],matriz[13][4],matriz[13][5],b[1],p[1]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[14][0],matriz[14][1],matriz[14][2],matriz[14][3],matriz[14][4],matriz[14][5],b[0],p[0]);

                                    printf("\n\ndigite a combinacao:  ");
                                    scanf("%i%i%i%i%i%i",&matriz[12][0],&matriz[12][1],&matriz[12][2],&matriz[12][3],&matriz[12][4],&matriz[12][5]);
                                    pontuacao--;

                                    if (vet[0] == matriz[12][0] && vet[1] == matriz[12][1] && vet[2] == matriz[12][2] && vet[3] == matriz[12][3] && vet[4] == matriz[12][4] && vet[5] == matriz[12][5]){
                                        printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                        printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                        printf("\n\n");
                                        
                                        if (jogador == 1){
                                            ptsj1 += pontuacao;
                                        }
                                        if (jogador == 2){
                                            ptsj2 += pontuacao;
                                        }
                                        
                                        system("pause");
                                        pontuacao = 14;
                                        break;
                                    }

                                        b[2]=0;
                                        p[2]=0;

                                    for(int i=0; i<6; i++){
                                        veta[i]=0;
                                        aux3[i]=0;
                                    }

                                    for(int i=0; i<6; i++){
                                        if(matriz[12][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[2]++;
                                        }
                                    }
                                    for(int i=0; i<6; i++){
                                        for(int j=0; j<6; j++){
                                            if(matriz[12][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[2]++;
                                            }
                                        }
                                    }

                                    system("cls");
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\t\t %d = BRANCO.\n", b[2]);
                                    printf("        || - - - - - - ||         |\t\t %d = PRETO.\n", p[2]);
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n");
                                    printf("        || - - - - - - ||         |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],matriz[12][5],b[2],p[2]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[13][0],matriz[13][1],matriz[13][2],matriz[13][3],matriz[13][4],matriz[13][5],b[1],p[1]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[14][0],matriz[14][1],matriz[14][2],matriz[14][3],matriz[14][4],matriz[14][5],b[0],p[0]);

                                    printf("\n\ndigite a combinacao:  ");
                                    scanf("%i%i%i%i%i%i",&matriz[11][0],&matriz[11][1],&matriz[11][2],&matriz[11][3],&matriz[11][4],&matriz[11][5]);
                                    pontuacao--;

                                    if (vet[0] == matriz[11][0] && vet[1] == matriz[11][1] && vet[2] == matriz[11][2] && vet[3] == matriz[11][3] && vet[4] == matriz[11][4] && vet[5] == matriz[11][5]){
                                        printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                        printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                        printf("\n\n");
                                        
                                        if (jogador == 1){
                                            ptsj1 += pontuacao;
                                        }
                                        if (jogador == 2){
                                            ptsj2 += pontuacao;
                                        }
                                        
                                        system("pause");
                                        pontuacao = 14;
                                        break;
                                    }

                                        b[3]=0;
                                        p[3]=0;

                                    for(int i=0; i<6; i++){
                                        veta[i]=0;
                                        aux3[i]=0;
                                    }

                                    for(int i=0; i<6; i++){
                                        if(matriz[11][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[3]++;
                                        }
                                    }
                                    for(int i=0; i<6; i++){
                                        for(int j=0; j<6; j++){
                                            if(matriz[11][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[3]++;
                                            }
                                        }
                                    }

                                    system("cls");
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\t\t %d = BRANCO.\n", b[3]);
                                    printf("        || - - - - - - ||         |\t\t %d = PRETO.\n", p[3]);
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n");
                                    printf("        || - - - - - - ||         |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],matriz[11][5],b[3],p[3]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],matriz[12][5],b[2],p[2]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[13][0],matriz[13][1],matriz[13][2],matriz[13][3],matriz[13][4],matriz[13][5],b[1],p[1]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[14][0],matriz[14][1],matriz[14][2],matriz[14][3],matriz[14][4],matriz[14][5],b[0],p[0]);

                                    printf("\n\ndigite a combinacao:  ");
                                    scanf("%i%i%i%i%i%i",&matriz[10][0],&matriz[10][1],&matriz[10][2],&matriz[10][3],&matriz[10][4],&matriz[10][5]);
                                    pontuacao--;

                                    if (vet[0] == matriz[10][0] && vet[1] == matriz[10][1] && vet[2] == matriz[10][2] && vet[3] == matriz[10][3] && vet[4] == matriz[10][4] && vet[5] == matriz[10][5]){
                                        printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                        printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                        printf("\n\n");
                                        
                                        if (jogador == 1){
                                            ptsj1 += pontuacao;
                                        }
                                        if (jogador == 2){
                                            ptsj2 += pontuacao;
                                        }
                                        
                                        system("pause");
                                        pontuacao = 14;
                                        break;
                                    }

                                        b[4]=0;
                                        p[4]=0;

                                    for(int i=0; i<6; i++){
                                        veta[i]=0;
                                        aux3[i]=0;
                                    }

                                    for(int i=0; i<6; i++){
                                        if(matriz[10][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[4]++;
                                        }
                                    }
                                    for(int i=0; i<6; i++){
                                        for(int j=0; j<6; j++){
                                            if(matriz[10][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[4]++;
                                            }
                                        }
                                    }
                                    
                                    system("cls");
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\t\t %d = BRANCO.\n", b[4]);
                                    printf("        || - - - - - - ||         |\t\t %d = PRETO.\n", p[4]);
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n");
                                    printf("        || - - - - - - ||         |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n");
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[11][3],matriz[10][4],matriz[10][5],b[4],p[4]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],matriz[11][5],b[3],p[3]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],matriz[12][5],b[2],p[2]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[13][0],matriz[13][1],matriz[13][2],matriz[13][3],matriz[13][4],matriz[13][5],b[1],p[1]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[14][0],matriz[14][1],matriz[14][2],matriz[14][3],matriz[14][4],matriz[14][5],b[0],p[0]);

                                    printf("\n\ndigite a combinacao:  ");
                                    scanf("%i%i%i%i%i%i",&matriz[9][0],&matriz[9][1],&matriz[9][2],&matriz[9][3],&matriz[9][4],&matriz[9][5]);
                                    pontuacao--;

                                    if (vet[0] == matriz[9][0] && vet[1] == matriz[9][1] && vet[2] == matriz[9][2] && vet[3] == matriz[9][3] && vet[4] == matriz[9][4] && vet[5] == matriz[9][5]){
                                        printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                        printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                        printf("\n\n");
                                        
                                        if (jogador == 1){
                                            ptsj1 += pontuacao;
                                        }
                                        if (jogador == 2){
                                            ptsj2 += pontuacao;
                                        }
                                        
                                        system("pause");
                                        pontuacao = 14;
                                        break;
                                    }

                                        b[5]=0;
                                        p[5]=0;

                                    for(int i=0; i<6; i++){
                                        veta[i]=0;
                                        aux3[i]=0;
                                    }

                                    for(int i=0; i<6; i++){
                                        if(matriz[9][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[5]++;
                                        }
                                    }
                                    for(int i=0; i<6; i++){
                                        for(int j=0; j<6; j++){
                                            if(matriz[9][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[5]++;
                                            }
                                        }
                                    }

                                    system("cls");
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\t\t %d = BRANCO.\n", b[5]);
                                    printf("        || - - - - - - ||         |\t\t %d = PRETO.\n", p[5]);
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n");
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],matriz[9][4],matriz[9][5],b[5],p[5]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],matriz[10][5],b[4],p[4]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],matriz[11][5],b[3],p[3]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],matriz[12][5],b[2],p[2]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[13][0],matriz[13][1],matriz[13][2],matriz[13][3],matriz[13][4],matriz[13][5],b[1],p[1]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[14][0],matriz[14][1],matriz[14][2],matriz[14][3],matriz[14][4],matriz[14][5],b[0],p[0]);

                                    printf("\n\ndigite a combinacao:  ");
                                    scanf("%i%i%i%i%i%i",&matriz[8][0],&matriz[8][1],&matriz[8][2],&matriz[8][3],&matriz[8][4],&matriz[8][5]);
                                    pontuacao--;
                                    
                                    if (vet[0] == matriz[8][0] && vet[1] == matriz[8][1] && vet[2] == matriz[8][2] && vet[3] == matriz[8][3] && vet[4] == matriz[8][4] && vet[5] == matriz[8][5]){
                                        printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                        printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                        printf("\n\n");
                                        
                                        if (jogador == 1){
                                            ptsj1 += pontuacao;
                                        }
                                        if (jogador == 2){
                                            ptsj2 += pontuacao;
                                        }
                                        
                                        system("pause");
                                        pontuacao = 14;
                                        break;
                                    }

                                        b[6]=0;
                                        p[6]=0;

                                    for(int i=0; i<6; i++){
                                        veta[i]=0;
                                        aux3[i]=0;
                                    }

                                    for(int i=0; i<6; i++){
                                        if(matriz[8][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[6]++;
                                        }
                                    }
                                    for(int i=0; i<6; i++){
                                        for(int j=0; j<6; j++){
                                            if(matriz[8][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[6]++;
                                            }
                                        }
                                    }

                                    system("cls");
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\t\t %d = BRANCO.\n", b[6]);
                                    printf("        || - - - - - - ||         |\t\t %d = PRETO.\n", p[6]);
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],matriz[8][4],matriz[8][5],b[6],p[6]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],matriz[9][4],matriz[9][5],b[5],p[5]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],matriz[10][5],b[4],p[4]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],matriz[11][5],b[3],p[3]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],matriz[12][5],b[2],p[2]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[13][0],matriz[13][1],matriz[13][2],matriz[13][3],matriz[13][4],matriz[13][5],b[1],p[1]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[14][0],matriz[14][1],matriz[14][2],matriz[14][3],matriz[14][4],matriz[14][5],b[0],p[0]);

                                    printf("\n\ndigite a combinacao:  ");
                                    scanf("%i%i%i%i%i%i",&matriz[7][0],&matriz[7][1],&matriz[7][2],&matriz[7][3],&matriz[7][4],&matriz[7][5]);
                                    pontuacao--;

                                    if (vet[0] == matriz[7][0] && vet[1] == matriz[7][1] && vet[2] == matriz[7][2] && vet[3] == matriz[7][3] && vet[4] == matriz[7][4] && vet[5] == matriz[7][5]){
                                        printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                        printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                        printf("\n\n");
                                        
                                        if (jogador == 1){
                                            ptsj1 += pontuacao;
                                        }
                                        if (jogador == 2){
                                            ptsj2 += pontuacao;
                                        }
                                        
                                        system("pause");
                                        pontuacao = 14;
                                        break;
                                    }

                                        b[7]=0;
                                        p[7]=0;

                                    for(int i=0; i<6; i++){
                                        veta[i]=0;
                                        aux3[i]=0;
                                    }

                                    for(int i=0; i<6; i++){
                                        if(matriz[7][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[7]++;
                                        }
                                    }
                                    for(int i=0; i<6; i++){
                                        for(int j=0; j<6; j++){
                                            if(matriz[7][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[7]++;
                                            }
                                        }
                                    }

                                    system("cls");
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\t\t %d = BRANCO.\n", b[7]);
                                    printf("        || - - - - - - ||         |\t\t %d = PRETO.\n", p[7]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],matriz[7][4],matriz[7][5],b[7],p[7]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],matriz[8][4],matriz[8][5],b[6],p[6]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],matriz[9][4],matriz[9][5],b[5],p[5]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],matriz[10][5],b[4],p[4]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],matriz[11][5],b[3],p[3]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],matriz[12][5],b[2],p[2]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[13][0],matriz[13][1],matriz[13][2],matriz[13][3],matriz[13][4],matriz[13][5],b[1],p[1]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[14][0],matriz[14][1],matriz[14][2],matriz[14][3],matriz[14][4],matriz[14][5],b[0],p[0]);

                                    printf("\n\ndigite a combinacao:  ");
                                    scanf("%i%i%i%i%i%i",&matriz[6][0],&matriz[6][1],&matriz[6][2],&matriz[6][3],&matriz[6][4],&matriz[6][5]);
                                    pontuacao--;

                                    if (vet[0] == matriz[6][0] && vet[1] == matriz[6][1] && vet[2] == matriz[6][2] && vet[3] == matriz[6][3] && vet[4] == matriz[6][4] && vet[5] == matriz[6][5]){
                                        printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                        printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                        printf("\n\n");
                                        
                                        if (jogador == 1){
                                            ptsj1 += pontuacao;
                                        }
                                        if (jogador == 2){
                                            ptsj2 += pontuacao;
                                        }
                                        
                                        system("pause");
                                        pontuacao = 14;
                                        break;
                                    }

                                        b[8]=0;
                                        p[8]=0;

                                    for(int i=0; i<6; i++){
                                        veta[i]=0;
                                        aux3[i]=0;
                                    }

                                    for(int i=0; i<6; i++){
                                        if(matriz[6][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[8]++;
                                        }
                                    }
                                    for(int i=0; i<6; i++){
                                        for(int j=0; j<6; j++){
                                            if(matriz[6][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[8]++;
                                            }
                                        }
                                    }

                                    system("cls");
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\t\t %d = BRANCO.\n", b[8]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t %d = PRETO.\n",matriz[6][0],matriz[6][1],matriz[6][2],matriz[6][3],matriz[6][4],matriz[6][5],b[8],p[8],p[8]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],matriz[7][4],matriz[7][5],b[7],p[7]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],matriz[8][4],matriz[8][5],b[6],p[6]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],matriz[9][4],matriz[9][5],b[5],p[5]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],matriz[10][5],b[4],p[4]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],matriz[11][5],b[3],p[3]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],matriz[12][5],b[2],p[2]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[13][0],matriz[13][1],matriz[13][2],matriz[13][3],matriz[13][4],matriz[13][5],b[1],p[1]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[14][0],matriz[14][1],matriz[14][2],matriz[14][3],matriz[14][4],matriz[14][5],b[0],p[0]);

                                    printf("\n\ndigite a combinacao:  ");
                                    scanf("%i%i%i%i%i%i",&matriz[5][0],&matriz[5][1],&matriz[5][2],&matriz[5][3],&matriz[5][4],&matriz[5][5]);
                                    pontuacao--;

                                    if (vet[0] == matriz[5][0] && vet[1] == matriz[5][1] && vet[2] == matriz[5][2] && vet[3] == matriz[5][3] && vet[4] == matriz[5][4] && vet[5] == matriz[5][5]){
                                        printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                        printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                        printf("\n\n");
                                        
                                        if (jogador == 1){
                                            ptsj1 += pontuacao;
                                        }
                                        if (jogador == 2){
                                            ptsj2 += pontuacao;
                                        }
                                        
                                        system("pause");
                                        pontuacao = 14;
                                        break;
                                    }

                                        b[9]=0;
                                        p[9]=0;

                                    for(int i=0; i<6; i++){
                                        veta[i]=0;
                                        aux3[i]=0;
                                    }

                                    for(int i=0; i<6; i++){
                                        if(matriz[5][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[9]++;
                                        }
                                    }
                                    for(int i=0; i<6; i++){
                                        for(int j=0; j<6; j++){
                                            if(matriz[5][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[9]++;
                                            }
                                        }
                                    }

                                    system("cls");
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t %d = BRANCO.\n",matriz[5][0],matriz[5][1],matriz[5][2],matriz[5][3],matriz[5][4],matriz[5][5],b[9],p[9],b[9]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t %d = PRETO.\n",matriz[6][0],matriz[6][1],matriz[6][2],matriz[6][3],matriz[6][4],matriz[6][5],b[8],p[8],p[9]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],matriz[7][4],matriz[7][5],b[7],p[7]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],matriz[8][4],matriz[8][5],b[6],p[6]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],matriz[9][4],matriz[9][5],b[5],p[5]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],matriz[10][5],b[4],p[4]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],matriz[11][5],b[3],p[3]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],matriz[12][5],b[2],p[2]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[13][0],matriz[13][1],matriz[13][2],matriz[13][3],matriz[13][4],matriz[13][5],b[1],p[1]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[14][0],matriz[14][1],matriz[14][2],matriz[14][3],matriz[14][4],matriz[14][5],b[0],p[0]);

                                    printf("\n\ndigite a combinacao:  ");
                                    scanf("%i%i%i%i%i%i",&matriz[4][0],&matriz[4][1],&matriz[4][2],&matriz[4][3],&matriz[4][4],&matriz[4][5]);
                                    pontuacao--;

                                    if (vet[0] == matriz[4][0] && vet[1] == matriz[4][1] && vet[2] == matriz[4][2] && vet[3] == matriz[4][3] && vet[4] == matriz[4][4] && vet[5] == matriz[4][5]){
                                        printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                        printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                        printf("\n\n");
                                        
                                        if (jogador == 1){
                                            ptsj1 += pontuacao;
                                        }
                                        if (jogador == 2){
                                            ptsj2 += pontuacao;
                                        }
                                        
                                        system("pause");
                                        pontuacao = 14;
                                        break;
                                    }

                                        b[10]=0;
                                        p[10]=0;

                                    for(int i=0; i<6; i++){
                                        veta[i]=0;
                                        aux3[i]=0;
                                    }

                                    for(int i=0; i<6; i++){
                                        if(matriz[4][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[10]++;
                                        }
                                    }
                                    for(int i=0; i<6; i++){
                                        for(int j=0; j<6; j++){
                                            if(matriz[4][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[10]++;
                                            }
                                        }
                                    }

                                    system("cls");
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[4][0],matriz[4][1],matriz[4][2],matriz[4][3],matriz[4][4],matriz[4][5],b[10],p[10]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t %d = BRANCO.\n",matriz[5][0],matriz[5][1],matriz[5][2],matriz[5][3],matriz[5][4],matriz[5][5],b[9],p[9],b[10]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t %d = PRETO.\n",matriz[6][0],matriz[6][1],matriz[6][2],matriz[6][3],matriz[6][4],matriz[6][5],b[8],p[8],p[10]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],matriz[7][4],matriz[7][5],b[7],p[7]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],matriz[8][4],matriz[8][5],b[6],p[6]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],matriz[9][4],matriz[9][5],b[5],p[5]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],matriz[10][5],b[4],p[4]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],matriz[11][5],b[3],p[3]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],matriz[12][5],b[2],p[2]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[13][0],matriz[13][1],matriz[13][2],matriz[13][3],matriz[13][4],matriz[13][5],b[1],p[1]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[14][0],matriz[14][1],matriz[14][2],matriz[14][3],matriz[14][4],matriz[14][5],b[0],p[0]);

                                    printf("\n\ndigite a combinacao:  ");
                                    scanf("%i%i%i%i%i%i",&matriz[3][0],&matriz[3][1],&matriz[3][2],&matriz[3][3],&matriz[3][4],&matriz[3][5]);
                                    pontuacao--;

                                    if (vet[0] == matriz[3][0] && vet[1] == matriz[3][1] && vet[2] == matriz[3][2] && vet[3] == matriz[3][3] && vet[4] == matriz[3][4] && vet[5] == matriz[3][5]){
                                        printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                        printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                        printf("\n\n");
                                        
                                        if (jogador == 1){
                                            ptsj1 += pontuacao;
                                        }
                                        if (jogador == 2){
                                            ptsj2 += pontuacao;
                                        }
                                        
                                        system("pause");
                                        pontuacao = 14;
                                        break;
                                    }

                                        b[11]=0;
                                        p[11]=0;

                                    for(int i=0; i<6; i++){
                                        veta[i]=0;
                                        aux3[i]=0;
                                    }

                                    for(int i=0; i<6; i++){
                                        if(matriz[3][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[11]++;
                                        }
                                    }
                                    for(int i=0; i<6; i++){
                                        for(int j=0; j<6; j++){
                                            if(matriz[3][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[11]++;
                                            }
                                        }
                                    }

                                    system("cls");
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[3][0],matriz[3][1],matriz[3][2],matriz[3][3],matriz[3][4],matriz[3][5],b[11],p[11]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[4][0],matriz[4][1],matriz[4][2],matriz[4][3],matriz[4][4],matriz[4][5],b[10],p[10]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t %d = BRANCO.\n",matriz[5][0],matriz[5][1],matriz[5][2],matriz[5][3],matriz[5][4],matriz[5][5],b[9],p[9],b[11]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t %d = PRETO.\n",matriz[6][0],matriz[6][1],matriz[6][2],matriz[6][3],matriz[6][4],matriz[6][5],b[8],p[8],p[11]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],matriz[7][4],matriz[7][5],b[7],p[7]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],matriz[8][4],matriz[8][5],b[6],p[6]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],matriz[9][4],matriz[9][5],b[5],p[5]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],matriz[10][5],b[4],p[4]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],matriz[11][5],b[3],p[3]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],matriz[12][5],b[2],p[2]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[13][0],matriz[13][1],matriz[13][2],matriz[13][3],matriz[13][4],matriz[13][5],b[1],p[1]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[14][0],matriz[14][1],matriz[14][2],matriz[14][3],matriz[14][4],matriz[14][5],b[0],p[0]);

                                    printf("\n\ndigite a combinacao:  ");
                                    scanf("%i%i%i%i%i%i",&matriz[2][0],&matriz[2][1],&matriz[2][2],&matriz[2][3],&matriz[2][4],&matriz[2][5]);
                                    pontuacao--;

                                    if (vet[0] == matriz[2][0] && vet[1] == matriz[2][1] && vet[2] == matriz[2][2] && vet[3] == matriz[2][3] && vet[4] == matriz[2][4] && vet[5] == matriz[2][5]){
                                        printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                        printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                        printf("\n\n");
                                        
                                        if (jogador == 1){
                                            ptsj1 += pontuacao;
                                        }
                                        if (jogador == 2){
                                            ptsj2 += pontuacao;
                                        }
                                        
                                        system("pause");
                                        pontuacao = 14;
                                        break;
                                    }

                                        b[12]=0;
                                        p[12]=0;

                                    for(int i=0; i<6; i++){
                                        veta[i]=0;
                                        aux3[i]=0;
                                    }

                                    for(int i=0; i<6; i++){
                                        if(matriz[2][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[12]++;
                                        }
                                    }
                                    for(int i=0; i<6; i++){
                                        for(int j=0; j<6; j++){
                                            if(matriz[2][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[12]++;
                                            }
                                        }
                                    }

                                    system("cls");
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || - - - - - - ||         |\n");
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[2][0],matriz[2][1],matriz[2][2],matriz[2][3],matriz[2][4],matriz[2][5],b[12],p[12]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[3][0],matriz[3][1],matriz[3][2],matriz[3][3],matriz[3][4],matriz[3][5],b[11],p[11]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[4][0],matriz[4][1],matriz[4][2],matriz[4][3],matriz[4][4],matriz[4][5],b[10],p[10]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t %d = BRANCO.\n",matriz[5][0],matriz[5][1],matriz[5][2],matriz[5][3],matriz[5][4],matriz[5][5],b[9],p[9],b[12]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t %d = PRETO.\n",matriz[6][0],matriz[6][1],matriz[6][2],matriz[6][3],matriz[6][4],matriz[6][5],b[8],p[8],p[12]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],matriz[7][4],matriz[7][5],b[7],p[7]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],matriz[8][4],matriz[8][5],b[6],p[6]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],matriz[9][4],matriz[9][5],b[5],p[5]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],matriz[10][5],b[4],p[4]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],matriz[11][5],b[3],p[3]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],matriz[12][5],b[2],p[2]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[13][0],matriz[13][1],matriz[13][2],matriz[13][3],matriz[13][4],matriz[13][5],b[1],p[1]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[14][0],matriz[14][1],matriz[14][2],matriz[14][3],matriz[14][4],matriz[14][5],b[0],p[0]);

                                    printf("\n\ndigite a combinacao:  ");
                                    scanf("%i%i%i%i%i%i",&matriz[1][0],&matriz[1][1],&matriz[1][2],&matriz[1][3],&matriz[1][4],&matriz[1][5]);
                                    pontuacao--;

                                    if (vet[0] == matriz[1][0] && vet[1] == matriz[1][1] && vet[2] == matriz[1][2] && vet[3] == matriz[1][3] && vet[4] == matriz[1][4] && vet[5] == matriz[1][5]){
                                        printf("\n\n\t\t  PARABENS, VOCE VENCEU!\n\n");
                                        printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                        printf("\n\n");
                                        ptotal = ptotal + pontuacao;
                                        system("pause");
                                        pontuacao = 14;
                                        break;
                                    }

                                        b[13]=0;
                                        p[13]=0;

                                    for(int i=0; i<6; i++){
                                        veta[i]=0;
                                        aux3[i]=0;
                                    }

                                    for(int i=0; i<6; i++){
                                        if(matriz[1][i]==vet[i]){

                                            veta[i]=1;
                                            aux3[i]=1;
                                            p[13]++;
                                        }
                                    }
                                    for(int i=0; i<6; i++){
                                        for(int j=0; j<6; j++){
                                            if(matriz[1][j]==vet[i] && veta[i]==0 && aux3[i]==0){

                                                aux3[i]=0;
                                                veta[i]=1;
                                                b[13]++;
                                            }
                                        }
                                    }

                                    system("cls");
                                    printf("\n\n");
                                    if (repeticao == 1){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                        printf("OFF\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    else if(repeticao == 2){
                                        printf("\t\t\t\t\t REPETICAO: ");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                                        printf("ON\n");
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                                    }
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[1][0],matriz[1][1],matriz[1][2],matriz[1][3],matriz[1][4],matriz[1][5],b[13],p[13]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[2][0],matriz[2][1],matriz[2][2],matriz[2][3],matriz[2][4],matriz[2][5],b[12],p[12]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[3][0],matriz[3][1],matriz[3][2],matriz[3][3],matriz[3][4],matriz[3][5],b[11],p[11]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[4][0],matriz[4][1],matriz[4][2],matriz[4][3],matriz[4][4],matriz[4][5],b[10],p[10]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t %d = BRANCO.\n",matriz[5][0],matriz[5][1],matriz[5][2],matriz[5][3],matriz[5][4],matriz[5][5],b[9],p[9],b[13]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t %d = PRETO.\n",matriz[6][0],matriz[6][1],matriz[6][2],matriz[6][3],matriz[6][4],matriz[6][5],b[8],p[8],p[13]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[7][0],matriz[7][1],matriz[7][2],matriz[7][3],matriz[7][4],matriz[7][5],b[7],p[7]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t BRANCO > POSSUI, MAS ESTA NO LUGAR INCORRETO.\n",matriz[8][0],matriz[8][1],matriz[8][2],matriz[8][3],matriz[8][4],matriz[8][5],b[6],p[6]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\t\t PRETO > POSSUI E ESTA NO LOCAL CORRETO.\n",matriz[9][0],matriz[9][1],matriz[9][2],matriz[9][3],matriz[9][4],matriz[9][5],b[5],p[5]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[10][0],matriz[10][1],matriz[10][2],matriz[10][3],matriz[10][4],matriz[10][5],b[4],p[4]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[11][0],matriz[11][1],matriz[11][2],matriz[11][3],matriz[11][4],matriz[11][5],b[3],p[3]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[12][0],matriz[12][1],matriz[12][2],matriz[12][3],matriz[12][4],matriz[12][5],b[2],p[2]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[13][0],matriz[13][1],matriz[13][2],matriz[13][3],matriz[13][4],matriz[13][5],b[1],p[1]);
                                    printf("        || %i %i %i %i %i %i || B:%i P:%i |\n",matriz[14][0],matriz[14][1],matriz[14][2],matriz[14][3],matriz[14][4],matriz[14][5],b[0],p[0]);

                                    printf("\n\ndigite a combinacao:  ");
                                    scanf("%i%i%i%i%i%i",&matriz[1][0],&matriz[1][1],&matriz[1][2],&matriz[1][3],&matriz[1][4],&matriz[1][5]);
                                    pontuacao--;

                                    printf("\n\n\t\t\tGAME OVER!\n\n");
                                    printf("\t       A senha gerada foi:  ");

                                    for (i = 0; i < 6; i++){
                                        printf("%d ", vet[i]);
                                    }

                                    printf("\n\n");
                                    printf("\t         Voce conseguiu %d pontos!\n", pontuacao);
                                    printf("\n\n");
                                    getchar();
                                    ptotal = ptotal + pontuacao;
                                    pontuacao = 14;

                                    l++;
                                    system("pause");
                                    break;
                                }
                            }

                            if(parador == 2){
                                break;
                            }

                        }

                        int comeback;

                        system("cls");
                        endscreen(ptsj1, ptsj2);
                        scanf("%d", &comeback);

                        ALTERRADAJ4:
                        printf("\n\n\n| Aperte 1 para jogar novamente |\n\n| Aperte 0 para voltar ao menu  |\n\n");
                        printf("> ");
                        getchar();


                        if (comeback == 1){
                            rodada = 1;
                            goto PLAYAGAINJOGADORESDIF3;
                        }
                        else if (comeback == 0){
                            menu();
                        }
                        else if (comeback != 0 || comeback != 1){
                            system("cls");
                            printf("\n\n\t\t\tDigite uma alternativa valida!");
                            goto ALTERRADAJ4;
                        }
                    }
                }
            }
        }
    }
}

int menu(){

    system("cls");
    printf("\n\n\n");
    printf("    888b     d888        d8888  .d8888b. 88888888888 8888888888 8888888b.  888b     d888 8888888 888b    888 8888888b.  \n");
    printf("    8888b   d8888       d88888 d88P  Y88b    888     888        888   Y88b 8888b   d8888   888   8888b   888 888  'Y88b \n");
    printf("    88888b.d88888      d88P888 Y88b.         888     888        888    888 88888b.d88888   888   88888b  888 888    888 \n");
    printf("    888Y88888P888     d88P 888  'Y888b.      888     8888888    888   d88P 888Y88888P888   888   888Y88b 888 888    888 \n");
    printf("    888 Y888P 888    d88P  888     'Y88b.    888     888        8888888P'  888 Y888P 888   888   888 Y88b888 888    888 \n");
    printf("    888  Y8P  888   d88P   888       '888    888     888        888 T88b   888  Y8P  888   888   888  Y88888 888    888 \n");
    printf("    888   '   888  d8888888888 Y88b  d88P    888     888        888  T88b  888   '   888   888   888   Y8888 888  .d88P \n");
    printf("    888       888 d88P     888  'Y8888P'     888     8888888888 888   T88b 888       888 8888888 888    Y888 8888888P'  \n\n");
    printf("                                                                                 Equipe: Claudio M., Luann C., Lucas G.\n\n\n");

    printf("                                                            >JOGAR<\n");
    printf("                                                          >INSTRUCOES<\n");

    printf("\n\n| Aperte 1 para jogar\t\t  |\n\n| Aperte 2 para ler as instrucoes |\n\n| Aperte 0 para sair do jogo      |\n");
    printf("\n> ");

}

int instruc(){

    system("cls");
    printf("Antes de jogar, os jogadores decidem o numero de partidas que vao jogar, considerando\n que eh preciso jogar um numero par de partidas para que os dois jogadores tenham o\n mesmo numero de oportunidade como desafiante e desafiado.\n");
    printf("A senha pode ser formada por numeros imputados pelo usuario ou gerada automaticamente.\n Os jogadores decidem, com antecedencia, se eh permitido repetir cores\n na senha. Note que isso aumenta a dificuldade do jogo.\n");
    printf("O outro jogador, o desafiado, tem ate 10 tentativas para reproduzir exatamente a senha,\n sem nunca ve-la. Cada tentativa eh feita colocando uma fila de pinos no tabuleiro. Cada fila\n colocada deve permanecer na mesma posicao durante todo o jogo.\n");
    printf("Depois de cada tentativa, o jogo 'responde' ao desafiado se ele esta no caminho certo,\n colocando os pinos brancos ou pretos da seguinte forma:\n");
    printf("\n> Pino Branco: indica que um dos numeros colocados pelo desafiado coincide com numero\n de um dos numeros da senha, mas a sua posicao nao esta correta;");
    printf("\n> Pino Preto: indica que um dos numeros colocados pelo desafiado coincide com um dos\n numeros da senha, em posicao correta;\n");
    printf("\nCaso nao apareca nenhum pino: significa que nem o numero e nem a posicao estao\n corretas. Nao existe ordem para a colocacao dos pinos brancos e pretos.\n");
    printf("Eh nessa colocacao aleatoria dos pinos brancos e pretos que esta o verdadeiro desafio do\n jogo, pois o desafiado tentara deduzir, por suas jogadas anteriores, qual eh a sequencia\n correta da senha.\n");
    printf("Quando o desafiado reproduzir a sequencia exata da senha, o jogo conhecera a vitoria do\n jogador e contara os pontos que obteve nesta partida.\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    printf("\nATENCAO: A senha eh formada por digitos de 0 a 7, podendo variar conforme a dificuldade!\nAo colocar a sequencia desejada, separe os numeros por espacos!\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    system("pause");
    menu();
}

int jogar(){

    system("cls");

    printf("\n\t\t\tSelecione o Tipo de Jogo: ");
    printf("\n\n\n |  Aperte 1 para jogar contra outro JOGADOR  |\n\n |  Aperte 2 para jogar contra o COMPUTADOR   |\n\n |      Aperte 0 para retornar ao menu\t     |\n\n");

    getchar();

}

int config(){

    system("cls");

    printf("\n\t\t\tSelecione a dificuldade: \n\n\n");
    printf(" |  Aperte 1 para FACIL  |\n\n");
    printf(" |  Aperte 2 para MEDIO  |\n\n");
    printf(" | Aperte 3 para DIFICIL |\n\n");

    printf("\n> ");
    getchar();
}

int endscreen(int ptsj1, int ptsj2){

    printf("\n\n\t\t\tFIM DE JOGO!\n\t\t     OBRIGADO POR JOGAR!\n\n");
    printf("\n\n\tO JOGADOR 1 ficou com a pontuacao total de %d pontos!", ptsj1);
    printf("\n\n\tO JOGADOR 2 ficou com a pontuacao total de %d pontos!", ptsj2);

    if (ptsj1 > ptsj2){
        printf("\n\n   O JOGADOR 1 ficou com a pontuacao maior! PARABENS, JOGADOR 1!");
    }
    else if (ptsj1 < ptsj2){
        printf("\n\n   O JOGADOR 2 ficou com a pontuacao maior! PARABENS, JOGADOR 2!");
    }
    else if (ptsj1 == ptsj2){
        printf("\n\n\t   A PONTUACAO FICOU EMPATADA ENTRE OS JOGADORES!");
    }

    printf("\n\n\n| Aperte 1 para jogar novamente |\n\n| Aperte 0 para voltar ao menu  |\n\n");
    printf("> ");

    getchar();

}