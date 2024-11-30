#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//void* malloc(sizeT)

typedef struct{
	
}Info;

void acessoAdmin(){
	
}

void acessoCatador(){
	
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
			printf("1");
			break;
			
		case 2: //Menu de Admin
		
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