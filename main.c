#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//DECLARANDO ESTRUTURA ALUNO QUE ARMAZENA NOME, EMAIL, PESO E ALTURA
struct aluno {
    char nome[100];
    char email[100];
    float altura;
    float peso;
};

//VETOR DE 20 POSI�OES QUE ARMAZENA AS ESTRUTURAS
struct aluno info[20];

//FUN��O SEPARADA QUE RECEBE PESO E ALTURA E RETORNA O IMC
float calculaImc(struct aluno *al) {
    float resultado;
    resultado = al->peso / (al->altura * al->altura);
    return resultado;
}

//FUN��O PRICIPAL
int main() {

    setlocale(LC_ALL,"portuguese");

    //DECLARANDO OUTRAS VARIAVEIS NECESSARIAS
    int i, op, posicao, excluir, excluir2;

    do{
        system("cls");
        printf("+----------------------------------+\n");
        printf("|      CADASTRANDO ALUNOS NA       |\n");
        printf("|       ACAD�MIA UNICESUMAR        |\n");
        printf("+----------------------------------+\n");
        printf("\n\t MENU \n");
        printf("\n1. Cadastrar aluno.\n");
        printf("2. Listar alunos.\n");
        printf("3. Apagar aluno.\n");
        printf("4. Listar IMC de alunos.\n");
        printf("0. Sair.\n");

        printf("\nEscolha uma das op��es do menu: ");
        scanf("%i", &op);
        printf("\n");

        switch(op) {

            case(0):
                break;

            //CADASTRANDO 1 ALUNO POR VEZ, PODENDO ESCOLHER A POSI��O
            case(1):
                //MOSTRANDO QUAIS POSI�OES J� POSSUEM CADASTRO
                printf("Posi��es que j� possuem cadastro: ");
                for(i=0; i<=19; i++) {
                    if (info[i].nome[0] == '\0'){ //SE A PRIMEIRA POSI��O DA STRING FOR IGUAL A \0
                        continue;                 //ENT�O PULA PARA O PROXIMO
                    }
                    printf("%d " , i+1);
                }
                printf("\nVoc� pode cadastrar apenas 1 aluno por vez. Escolha a posi��o de 1 a 20: ");
                scanf("%d", &posicao);
                i = posicao - 1; //-1 PORQUE O VETOR VAI DE 0 AT� 19 TOTALIZANDO 20 POSI�OES
                if(posicao == 0 || posicao > 20){
                    printf("\nVoc� digitou um valor invalido, tente novamente!\n");
                }else{

                    printf("\n Cadastrando aluno na posi��o %d. \n", i+1);
                    printf("\n");

                    printf("Nome : ");
                    fflush(stdin);
                    gets(info[i].nome);

                    printf("Email : ");
                    fflush(stdin);
                    gets(info[i].email);

                    printf("Altura (m): ");
                    scanf("%f", &info[i].altura);
                    fflush(stdin);

                    printf("Peso (kg): ");
                    scanf("%f", &info[i].peso);
                    fflush(stdin);

                    if(info[i].nome[0] == '\0') {
                        printf("\nErro. Voc� n�o preencheu o campo Nome.\n"); //PELO MENOS O CAMPO NOME TEM QUE ESTAR PREENCHIDO
                    }else{
                    printf("\nAluno cadastrado com sucesso!\n");
                    }
                }
                break;

            //MOSTRANDO TODOS OS ALUNOS
            case(2):
                printf("Listando alunos cadastrados.\n");
                for(i=0; i<=19 ; i++){
                    if (info[i].nome[0] == '\0'){
                        continue;
                    }
                    printf("\nAluno %d \n", i+1);
                    printf("Nome: %s \n" , info[i].nome);
                    printf("Email: %s \n" , info[i].email);
                    printf("Altura: %.2f m \n", info[i].altura);
                    printf("Peso: %.2f kg \n", info[i].peso);
                }
                break;

            //APAGANDO ALUNOS
            case(3):
                printf("Digite a posi��o do aluno que deseja apagar: ");
                scanf("%d", &excluir);
                excluir = excluir - 1; //-1 PORQUE O VETOR VAI DE 0 AT� 19 TOTALIZANDO 20 POSI�OES
                if(info[excluir].nome[0] != '\0') {
                    printf("\nEssa posi��o corresponde ao seguinte aluno: %s.\n", info[excluir].nome);
                    printf("\nTem certeza que deseja apaga-lo?\n");
                    printf("\n [1] para SIM \n [0] para N�O.\n");
                    printf("\nSua escolha: ");
                    scanf("%d", &excluir2);

                    if(excluir2 == 1){
                        info[excluir].nome[0] = '\0';
                        printf("\nAluno deletado com sucesso!\n");
                    }else{printf("\nOpera��o cancelada! O aluno n�o foi apagado.\n");}
                }else{printf("\nAluno n�o encontrado, por favor tente novamente!\n");}
                break;

            //LISTA NOME, IMC E CONDI��O DE TODOS OS ALUNO
            case(4):
                printf("Listando NOME, IMC e CONDI��O dos alunos.\n");
                for(i=0; i<=19; i++) {
                    if (info[i].nome[0] == '\0'){ //SE A PRIMEIRA POSI��O DA STRING FOR IGUAL A \0
                        continue;                 //ENT�O PULA PARA O PROXIMO
                    }
                    printf("\nAluno %d \n", i+1);
                    printf("Nome: %s\n", info[i].nome);
                    printf("IMC: %.1f\n", calculaImc(&info[i]));

                    if(calculaImc(&info[i]) < 18.5){
                        printf("Condi��o: BAIXO PESO\n");
                    }
                    else if(calculaImc(&info[i]) >= 18.5 && calculaImc(&info[i]) < 25) {
                        printf("Condi��o: PESO IDEAL\n");
                    }
                    else if(calculaImc(&info[i]) >= 25 && calculaImc(&info[i]) < 30) {
                        printf("Condi��o: SOBREPESO\n");
                    }
                    else if(calculaImc(&info[i]) >= 30 && calculaImc(&info[i]) < 35) {
                        printf("Condi��o: OBESIDADE GRAU 1\n");
                    }
                    else if(calculaImc(&info[i]) >= 35 && calculaImc(&info[i]) < 40) {
                        printf("Condi��o: OBESIDADE GRAU 2\n");
                    }
                    else{
                        printf("Condi��o: OBESIDADE GRAU 3\n");
                    }
                }
                break;

            default:
                printf("Voc� digitou um valor inv�lido!\n");
        }

        if (op != 0) {
            printf("\nPressione qualquer tecla para voltar ao MENU."); //Volta ao menu
            getch();
        }
    }while(op!=0);

   return 0;
}


