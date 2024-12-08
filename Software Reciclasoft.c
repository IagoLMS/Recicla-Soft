#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>

#define TAM 50

int code = 0;

void limpa(){
	system("cls");
}

void pausa(){
	system("pause");
}

typedef struct{
	
}Info;

typedef struct{
	char nome[50];
	int cpf;
	char senha[20];
}Catadores;

typedef struct {
	char name [50];
	char password[20];
} Admin;

void cadastroCatador(Catadores cadastro[]) {
	
    if (code >= TAM) {
        printf("//====================( Cadastro )==================//\n");
        printf("| Espaço de memória cheio. Por favor, aloque mais espaço.\n");
        pausa();
    }

    printf("//====================( Cadastro )==================//\n");
    printf("| Insira seu nome:\n");
    getchar(); // Limpa o buffer
    gets(cadastro[code].nome); // Uso de `gets` é inseguro, mas mantive para compatibilidade
    printf("| Insira o seu CPF (Somente números):\n");
    scanf("%d", &cadastro[code].cpf);
    getchar(); // Limpa o buffer
    printf("| Insira sua senha:\n");
    gets(cadastro[code].senha);
    printf("| Cadastro realizado com sucesso!\n");
    printf("//==================================================//\n");

    code++;
}

void loginAdmin(){
	
	Admin admins;
	//usuario e senha para acessar login de admin
	char nomeCorreto[] = "Senai";
	char senhaCorreta[] = "1234";
	printf("//=================( RECICLA SOFT )=================//\n");
	printf("|\n");
	printf("| Usuario:\n");
	gets(admins.name);
	printf("|\n");
	printf("| Senha:\n");
	gets(admins.password);                                                             
	printf("|\n");
	printf("//==================================================//\n");
	//comparando se o usuario e a senha estão corretas
	if (strcmp(admins.name, nomeCorreto) == 0 && strcmp(admins.password, senhaCorreta) == 0) {
	
	int opcaoAdmin;
	
	do {
		system ("cls");
		printf("//======================( ADM )=====================//\n");
		printf("\n");
		printf("|1- Estoque\n");
		printf("|2- Listar Materiais reciclaveis\n");
		printf("|3- Área de pagamento\n");
		printf("\n");
		printf("|0- Menu inicial");
		printf("\n");
		printf("//==================================================//\n");
		printf("Escolha uma opção: ");
		scanf("%d", &opcaoAdmin);
		limpa();
		
		switch (opcaoAdmin) {
			case 2: 
//			ListarMaterial();
			system("pause");
			break;
			
			case 0: 
			printf("Voltando para o menu inicial!\n");
			break;
			
			default:
				printf("Opção Invalida");
				system ("pause");
		}
	} while(1);
	
  } else {
	printf("Usuario ou senha incorreto!");
	system ("pause");
	
	}
}
void ListarCatadores () {
	printf("Catadores disponiveis\n");
	printf("1- Moak\n");
	printf("2- Ikaro\n");
	printf("3- Erick\n");
	printf("4- Jefite\n");
	printf("5- Ingrid\n");
}
void ListarMaterial() {
	printf("Materiais Reciclaveis disponiveis\n");
	printf("1- Ouro\n");
	printf("2- cobre\n");
	printf("3- Ferro\n");
	printf("4- Aluminio\n");
	printf("5- Plastico\n");
}
void acessoCatador(Catadores cadastroCatadores[]){
	int n;
	
	system("cls");
	printf("//===================( Catadores )==================//\n");
	printf("|\n");
	printf("| (1) - Cadastrar \n");
	printf("| (2) - Entrar\n");
	printf("|\n");
	printf("| (0) - Sair\n");
	printf("|\n");
	scanf("%i", &n);
	printf("|\n");	
	printf("//==================================================//\n");
	switch(n){
		case 1: //Cadastro
			cadastroCatador(cadastroCatadores);
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



void menuIncial(int n, Catadores cadastroCatadores[]){
	
	printf("//=================( RECICLA SOFT )=================//\n");
	printf("|\n");
	printf("|\n");
	printf("| (1) - Área dos Catador \n");
	printf("| (2) - Menu Administrador\n");
	printf("| (0) - Sair\n");
	scanf("%i", &n);
	printf("|\n");
	printf("//==================================================//\n");
	limpa();
	
	switch(n){
		case 1: //Menu do catador
			acessoCatador(cadastroCatadores);
			break;
			
		case 2: //Menu de Admin
			loginAdmin();
			break;
			
		case 3: //Documentação
//			ListarCatadores();
			break;
			
		case 0: //Finalização do programa
			printf("Encerrando o sistema .............................[100%]");
			pausa();
			exit(1);
			break;
			
		default: 
			printf("Escolha Invalida");
	}
	
	system("pause");	
}

int main(void){
	setlocale(LC_ALL, "Portuguese");
	Catadores cadastroCatadores[code];
	int n, i;
	
	int escolha; 
	
	
	do{
		menuIncial(escolha, cadastroCatadores);
	
	} while(1);
}