#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

//void* malloc(sizeT)

typedef struct{
	
}Info;

typedef struct{
	char nome[50][10];
	char senha[50][10];
}Catadores;

void cadastroCatador(Catadores cadastro){
	
	system("cls");
	printf("//=================( RECICLA SOFT )=================//\n");
	printf("|\n");
	printf("| Insira Seu Nome\n");
	printf("|\n");
	printf("//==================================================//\n");
	scanf("%s", &cadastro.nome[1][1]);
	
	
	printf("//=================( RECICLA SOFT )=================//\n");
	printf("|\n");
	printf("| Insira Uma Senha\n");
	printf("|\n");
	printf("//==================================================//\n");
	scanf("%s", &cadastro.senha[1]);
}

typedef struct {
	char name [50][10];
	char password[50][10];
} Admin;
void acessoAdmin(){
	system("cls");
	Admin admins;
	printf("//=================( RECICLA SOFT )=================//\n");
	printf("|\n");
	printf("| Insira Seu Nome\n");
	printf("|\n");
	printf("//==================================================//\n");
	scanf("%s", &admins.name[1][1]);
	
	
	printf("//=================( RECICLA SOFT )=================//\n");
	printf("|\n");
	printf("| Insira Uma Senha\n");
	printf("|\n");
	printf("//==================================================//\n");
	scanf("%s", &admins.password[1]);
	
	int opcaoAdmin;
	
	do {
		system ("cls");
		printf("//=================( MENU DO ADM )=================//\n");
		printf("\n");
		printf("|1- Listar Materiais reciclaveis\n");
		printf("|2- Menu inicial");
		printf("\n");
		printf("//==================================================//\n");
		printf("Escolha uma opção: ");
		scanf("%d", &opcaoAdmin);
		
		switch (opcaoAdmin) {
			case 1: 
			ListarMaterial();
			system("pause");
			break;
			case 2: 
			printf("Voltando para o menu inicial!\n");
			break;
			
			default:
				printf("Opção Invalida");
				system ("pause");
		}
	} while (opcaoAdmin != 2);
		
	
}
void ListarMaterial() {
	printf("Materiais Reciclaveis disponiveis\n");
	printf("1- Ouro\n");
	printf("2- cobre\n");
	printf("3- Ferro\n");
	printf("4- Aluminio\n");
	printf("5- Plastico\n");
}
void acessoCatador(){
	Catadores cadastro;
	int n;
	
	system("cls");
	printf("//=================( RECICLA SOFT )=================//\n");
	printf("|\n");
	printf("|\n");
	printf("| (1) - Cadastrar \n");
	printf("| (2) - Entrar\n");
	printf("|\n");
	printf("| (0) - Sair\n");
	printf("|\n");
	printf("//==================================================//\n");
	
	scanf("%i", &n);
	switch(n){
		case 1: //Cadastro
			cadastroCatador(cadastro);
			break;
			
		case 2: //Entrar
		
			break;
			
		case 0: //Encerrar Função
			system("cls");
			return;
			break;
			
		default: 
			printf("Escolha Invalida");
	}	
}



void menuIncial1(int n){
	
	printf("//=================( RECICLA SOFT )=================//\n");
	printf("|\n");
	printf("|\n");
	printf("| (1) - Menu do Catador \n");
	printf("| (2) - Menu do Administrador\n");
	printf("| (3) - Documentacao\n");
	printf("|\n");
	printf("| (0) - Sair\n");
	printf("|\n");
	printf("//==================================================//\n");
	scanf("%i", &n);
	
	switch(n){
		case 1: //Menu do catador
			acessoCatador();
			break;
			
		case 2: //Menu de Admin
			acessoAdmin();
			break;
			
		case 3: //Documentação
		
			break;
			
		case 0: //Finalização do programa
			system("cls");
			printf("Encerrando o sistema ......................... 100%");
			exit(1);
			break;
			
		default: 
			printf("Escolha Invalida");
	}
	
	system("pause");	
}

int main(void){
	int *numeros;
	int n, i;
	
	int escolha; 
	
	setlocale(LC_ALL, "portuguese");
	
	do{
		system("cls");
		menuIncial1(escolha);
		
		/*numeros = malloc(n*sizeof(int));
		if(numeros == NULL){
			printf("Erro memoria excedida\n");
			exit(1);
		}*/
	
	} while(1);
}