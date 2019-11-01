//Aicha Mohamad Tassa - 1905268
//Carolina Aluá Soinegg - 1905276

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define IND 100
#define MAX 5

void aluno();
void listagem();
void procura();
void atualiza();
void remover();

int tam;

struct Cadastro {
    int id;
    char nome[IND];
    int data;
    double cpf;
    int situacao;
};
typedef struct Cadastro TCadastro;

int main() {

    TCadastro cadastro[MAX];

    int menu, tam=0;

    do {

        printf("\n\nCadastro de aluno:\n");
        printf("1- Cadastrar um aluno - minimo de 5 cadastros\n");
        printf("2- Listar os alunos\n");
        printf("3- Pesquisar um aluno\n");
        printf("4- Atualizar um aluno\n");
        printf("5- Remover um aluno\n");
        printf("6- Sair\n");
        scanf("%d", &menu);

        switch(menu)
        {
            case 1:

                if(tam<MAX) {

                aluno(cadastro);

                }

                else {

                    printf("ja foi cadastrado o maximo de alunos possiveis\n");
                }

                break;

            case 2:

                listagem(cadastro);

                break;

            case 3:

                procura(cadastro);

                break;

            case 4:

                atualiza(cadastro);

                break;

            case 5:

                remover(cadastro);

                break;
        }
    }while(menu!=6);
}

void aluno(TCadastro cadastro[MAX]) {

    cadastro[tam].situacao = 1;

    cadastro[tam].id = tam;

    printf("Digite seu nome:\n");
    fgets(cadastro[tam].nome, IND-1, stdin);
    gets(cadastro[tam].nome);

    printf("Digite a sua data de nascimento:\n");
    scanf("%d", &cadastro[tam].data);
    getchar();

    printf("Digite o seu CPF:\n");
    scanf("%lf", &cadastro[tam].cpf);

    tam++;
}



void listagem(TCadastro cadastro[MAX]){

    int i;

    for(i=0;i<tam;i++){
        if(cadastro[i].situacao == 1){
            printf("\nID: %d\n", cadastro[i].id);
            printf("Nome: %s\n", cadastro[i].nome);
            printf("Data: %d\n", cadastro[i].data);
            printf("CPF: %.0lf\n", cadastro[i].cpf);
        }
    }
}

void procura(TCadastro cadastro[MAX]) {

    char nome[20];
    int tamanho, i, j;

    printf("Digite o nome de quem procura:\n");
    scanf("%s", nome);

    tamanho = strlen(nome);

    for (i=0; i<tamanho; i++) {
    	if(cadastro[i].situacao == 1)
		{
        	if (strcmp (cadastro[i].nome,nome)==0)
        	{
        		printf("ID: %d\n", cadastro[i].id);
            	printf("Nome: %s\n", cadastro[i].nome);
            	printf("Data: %d\n", cadastro[i].data);
            	printf("CPF: %.0lf\n", cadastro[i].cpf);
        	}
        	
        	else
     		{
     			printf("Aluno nao encontrado.\n");	
			}
     	}  	
	}
}

void atualiza(TCadastro cadastro[MAX]) {

    int num, cont=0, i;

    printf("Digite o ID de quem voce quer atualizar:\n");
    scanf("%d", &num);

    for (i=0; i<tam; i++){

        if(num == cadastro[i].id){

            cadastro[i].situacao = 1;

            cadastro[i].id = i;

            printf("Digite o nome:\n");
            fgets(cadastro[i].nome, IND-1, stdin);
            gets(cadastro[i].nome);

            printf("Digite a data de nascimento:\n");
            scanf("%d", &cadastro[i].data);
            getchar();

            printf("Digite o CPF:\n");
            scanf("%lf", &cadastro[i].cpf);

            cont++;
        }
    }
    if(cont==0) {

        printf("nao existe essa id\n");

    }
}

void remover(TCadastro cadastro[MAX]) {

   
    int i, num;
    printf("Digite o ID de quem voce quer remover:\n");
    scanf("%d", &num);
    for(i=-1; i<tam;i++) {
    	if(i == num){
			
    	    cadastro[i].situacao = 0;
    	}
    }
    
    printf("Remocao concluida!\n");
}
