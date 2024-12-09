#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>

#define TAM 50

int code = 1;

typedef struct{
	char nome[60];
	int idade;
	int cpf;
	char status[30];
	float saldo;
	
}Catadores;

typedef struct{
	char usuario[40];
	char senha[20];
	Catadores catador;
	
}Cadastro;

void limpa(){
	system("cls");
}
void pausa(){
	system("pause");
}
void buffed(){
	fflush(stdin);
}

void cadastroCatador(Cadastro cadastrado[]) {
	
    if (code >= TAM) {
        printf("//====================( Cadastro )==================//\n");
        printf("| Espaço de memória cheio. Por favor, aloque mais espaço.\n");
        pausa();
        return;
    }

    printf("//====================( Cadastro )==================//\n");
    printf("| Insira seu Nome:\n");
    gets(cadastrado[code].catador.nome);
	buffed();
    printf("| Insira o seu CPF (Somente números):\n");
    scanf("%d", &cadastrado[code].catador.cpf);
	buffed();
    printf("| Insira sua senha:\n");
    gets(cadastrado[code].senha);
    printf("| Cadastro realizado com sucesso!\n");
    printf("//==================================================//\n");
    code++;
}


int validador(Cadastro cadastrado[], char *testeUsuario, char *testeSenha) {
    for (int i = 0; i < code; i++) {
        if (strcmp(testeUsuario, cadastrado[i].usuario) == 0 && strcmp(testeSenha, cadastrado[i].senha) == 0) {
            return -1;
        }
    }
    return 0; 
}

void loginCatador(Cadastro cadastrado[]) {
    char testeUsuario[50];
    char testeSenha[20];

    do {
        printf("//=================( RECICLA SOFT )=================//\n");
        printf("|\n");
        printf("| Usuário:\n");
        gets(testeUsuario); 
        printf("|\n");
        printf("| Senha:\n");
        gets(testeSenha);
        printf("|\n");
        printf("//==================================================//\n");

        if (validador(cadastrado, testeUsuario, testeSenha) == -1) {
            printf("Login bem-sucedido! Bem-vindo, %s.\n", testeUsuario);
            break;
        } else {
            printf("Usuário ou senha incorretos. Tente novamente.\n");
        }
    } while (1);
}


void menuCatador(Cadastro cadastrado[]){
	int n;
	
	limpa();
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
			cadastroCatador(cadastrado);
			break;
			
		case 2: //Entrar
			loginCatador(cadastrado);
			break;
			
		case 0: //Encerrar Função
			system("cls");
			return;
			break;
			
		default: 
			printf("Escolha Invalida");
	}	
}

void menuADM(Cadastro cadastrados[]){
	int escolha;
	
	printf("//======================( ADM )=====================//\n");
	printf("\n");
	
	printf("MATERIAIS:\n");
	printf("___________________________\n");
	printf("|1- Estoque\n");
	printf("|2- Vender Materias\n");
	printf("\n");
	
	printf("ÁREA DE CADASTRO\n");
	printf("___________________________\n");
	printf("|3- Adicionar Materias \n");
	printf("|4- Lista de Materiais\n");
	printf("\n");
	
	printf("ÁREA DOS CATADORES\n");
	printf("___________________________\n");
	printf("|5- Listar Catadores \n");
	printf("|6- Alterar Cadastro\n");
	printf("\n");
	
	printf("ÁREA DOS PAGAMENTO\n");
	printf("___________________________\n");
	printf("|7- Saldo da Empresa \n");
	printf("|8- Pagar Catador \n");
	
	printf("\n");
	printf("___________________________\n");
	printf("|0- Menu inicial");
	printf("\n");
	printf("//==================================================//\n");
	printf("Escolha uma opção: ");
	scanf("%d", &escolha);
	limpa();
	pausa();
	
	switch (escolha) {
		case 1: // estoque
//			ListarMaterial();
		break;
		
		case 2: //

		break;
		
		case 3: 

		break;
		
		case 4: 

		break;
		
		case 5: 

		break;
		
		case 6: 

		break;
		
		case 0: 
			printf("___________________________________\n");
			printf("|Voltando para o menu inicial!\n");
			pausa();
		break;
		
		default:
			printf("___________________________________\n");
			printf("Opção Invalida");
			pausa();
	}
}

void loginAdmin(Cadastro cadastrados[]){
	char testeUsuario[50];
	char testeSenha[20];
	
	do {
        printf("//=================( RECICLA SOFT )=================//\n");
        printf("|\n");
        printf("| Usuário:\n");
        gets(testeUsuario); 
        printf("|\n");
        printf("| Senha:\n");
        gets(testeSenha);
        printf("|\n");
        printf("//==================================================//\n");
		limpa();

        if (strcmp(testeUsuario, cadastrados[0].usuario) == 0 && strcmp(testeSenha, cadastrados[0].senha) == 0) {
			printf("Login bem-sucedido! Bem-vindo, %s.\n", testeUsuario);
			pausa();
            menuADM(cadastrados);
            
        } else {
            printf("Usuário ou senha incorretos. Tente novamente.\n");
        }
    } while (1); 
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

void menuIncial(int n, Cadastro cadastrado[]){
	
	printf("//=================( RECICLA SOFT )=================//\n");
	printf("|\n");
	
	printf("| (1) - Área dos Catador \n");
	
	printf("| (2) - Menu Administrador\n");
	printf("|\n");
	printf("| (0) - Sair\n");
	scanf("%i", &n);
	printf("|\n");
	printf("//==================================================//\n");
	limpa();
	
	switch(n){
		case 1: //Menu do catador
			menuCatador(cadastrado);
			break;
			
		case 2: //Menu de Admin
			loginAdmin(cadastrado);
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
	Cadastro cadastrado[code];
	int n, i;
	
	int escolha; 
	
	Cadastro cadastrados[1] = {
        {"senai", "senha"} // Login padrão do administrador
    };

	
	do{
		menuIncial(escolha, cadastrado);
	
	} while(1);
}