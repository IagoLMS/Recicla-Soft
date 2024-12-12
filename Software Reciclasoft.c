#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>

#define MAXMATERIAL 100
#define TAM 50

int code = 1;


typedef struct {
	char nome[60];
	int idade;
	int cpf;
	char local[100];
	float saldo;

} Catadores;

typedef struct {
	char usuario[40];
	char senha[20];
	Catadores catador;

} Cadastro;

typedef struct {
	char tipo[30];
	float quantidade;
	int cpfCatador;
}Material;

Material materiais[MAXMATERIAL];
int materialQuantidade = 0;

void limpa() {
	system("cls");
}
void pausa() {
	system("pause");
}
void buffed() {
	fflush(stdin);
}

/*void listarCatador(Catadores *catador, int quantidade, Catador *predefinidos, int predefinidosQuantidade) {
    printf("Lista de Catadores:\n");
    printf("====================\n");

    for (int i = 0; i < predefinidosQuantidade; i++) {
        printf("ID: %d\n", predefinidos[i].cpf);
        printf("Nome: %s\n", predefinidos[i].nome);
        printf("Localização: %s\n", predefinidos[i].local);
        printf("---------------------\n");
    }

    for (int i = 0; i < quantidade; i++) {
        printf("CPF: %d\n", catador[i].cpf);
        printf("Nome: %s\n", catador[i].nome);
        printf("Localização: %s\n", catador[i].local);
        printf("---------------------\n");
    }
}*/

void cadastroCatador(Cadastro cadastrado[]) {

	if (code >= TAM) {
		printf("//====================( Cadastro )==================//\n");
		printf("| Espaço de memória cheio. Por favor, aloque mais espaço.\n");
		pausa();
		return;
	}

	printf("//====================( Cadastro )==================//\n");
	printf("| Insira seu Nome:\n");
	buffed();
	gets(cadastrado[code].catador.nome);

	/*	printf("| Insira sua Localizacao:\n");
		buffed();
		gets(cadastrado[code].catador.local);
		*/
	printf("Informe o cpf: ");
	scanf("%d", &cadastrado[code].catador.cpf);
	buffed();

	printf("Informe o usuario ");
	buffed();
	gets(cadastrado[code].usuario);

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
	int opcao;
	float kg;
	do {
		printf("//=================( RECICLA SOFT )=================//\n");
		printf("|\n");

		printf("| Usuário:\n");
		buffed();
		gets(testeUsuario);
		printf("|\n");

		printf("| Senha:\n");
		gets(testeSenha);
		printf("|\n");
		printf("//==================================================//\n");

		if (validador(cadastrado, testeUsuario, testeSenha) == -1) {
			printf("Login bem-sucedido! Bem-vindo, %s.\n", testeUsuario);
			pausa();
			do {
				limpa();
				printf("//=================( RECICLA SOFT )=================//\n");
				printf("(1) Cadastrar Materiais\n");
				printf("(0) Voltar");
				printf("\nEscolha uma opção: ");
				scanf("%d", &opcao);
				buffed();
				pausa();

				switch (opcao) {
					case 1:
						printf("//=================(Escolha Material)=================//\n");
						cadastrarMaterial(&cadastrado[0]);
						limpa();
						break;
					
					case 0:
						printf("Voltando...\n");
						return;

					default:
						printf("Opção invalida!\n");
						pausa();
				}
			} while (opcao != 0) ;
		} else {
			printf("Usuário ou senha incorretos. Tente novamente.\n");
		}
	} while (1);
}


void menuCatador(Cadastro cadastrado[]) {
	int n;
	do {
		limpa();
		printf("//===================( Catadores )==================//\n");
		printf("|\n");
		printf("| (1) - Cadastrar \n");
		printf("| (2) - Entrar\n");
		printf("| (0) - Voltar\n");
		scanf("%i", &n);
		buffed();
		printf("|\n");
		printf("//==================================================//\n");
		switch(n) {
			case 1: //Cadastro
				cadastroCatador(cadastrado);
				break;

			case 2: //Entrar
				loginCatador(cadastrado);
				break;

			case 0: //Encerrar Função
				system("cls");
				pausa();
				return;
				
			default:
				printf("Escolha Invalida");
				pausa ();
		}
	} while (n != 0);
}

void menuADM(Cadastro cadastrados[]) {
	int escolha;
	do {
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
		printf("|9- Comprar material \n");

		printf("\n");
		printf("___________________________\n");
		printf("|0- Menu inicial");
		printf("\n");
		printf("//==================================================//\n");
		printf("Escolha uma opção: ");
		scanf("%d", &escolha);
		buffed();
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
				printf("Materiais Reciclaveis disponiveis\n");
				printf("1- Ouro\n");
				printf("2- cobre\n");
				printf("3- Ferro\n");
				printf("4- Aluminio\n");
				printf("5- Plastico\n");
				pausa();
				break;
			case 5:
//				listarCatador(catadores, quantidade, predefinidos, predefinidosQuantidade);
				pausa();
				break;

			case 6:
				//Alterar cadastro
				break;
			case 7:
				//saldo da empresa
				break;
			case 8:
				//pagar catador
			case 9:
				comprarMaterial(cadastrados);
				break;
			case 0:
				printf("___________________________________\n");
				printf("|Voltando para o menu inicial!\n");
				pausa();
				return;
				
			default:
				printf("___________________________________\n");
				printf("Opção Invalida");
				pausa();
				break;
		}
	} while (escolha != 0);
}

void loginAdmin(Cadastro cadastrado[]) {
	char testeUsuario[50];
	char testeSenha[20];

	do {
		printf("//=================( RECICLA SOFT )=================//\n");
		printf("|\n");
		printf("|\n");
		printf("| Usuário:\n");
		buffed();
		gets(testeUsuario);

		printf("|\n");

		printf("| Senha:\n");
		gets(testeSenha);

		printf("|\n");
		printf("//==================================================//\n");
		limpa();
		if (strcmp(testeUsuario, cadastrado[0].usuario) == 0 && strcmp(testeSenha, cadastrado[0].senha) == 0) {
			printf("Login bem-sucedido! Bem-vindo, %s.\n", testeUsuario);
			pausa();
			menuADM(cadastrado);
			return;
		} else {
			printf("Usuário ou senha incorretos. Tente novamente.\n");
		}
	} while (1);
}
void cadastrarMaterial(Cadastro *catador) {
	if (materialQuantidade >= MAXMATERIAL) {
		printf("Capacidade máxima de material! ");
		pausa();
		return;
	}
	
	Material novoMaterial;
	ListarMaterial();
	int escolha;
	scanf("%d", &escolha);
	buffed();
	switch (escolha) {
		case 1:
			strcpy(novoMaterial.tipo, "Ouro");
			break;
		case 2:
			strcpy(novoMaterial.tipo, "Cobre");
			break;
		case 3:
			strcpy(novoMaterial.tipo, "Ferro");
			break;
		case 4:
			strcpy(novoMaterial.tipo, "Aluminio");
			break;
		case 5:
			strcpy(novoMaterial.tipo, "Plástico");
			break;
		default:
			printf("Informação invalida");
			pausa(); 
			return;
	}
	
	printf("Quantos Kg você tem do material? ");
	scanf("%f", &novoMaterial.quantidade);
	buffed();
	
	novoMaterial.cpfCatador = catador->catador.cpf;
	materiais[materialQuantidade++] = novoMaterial;
	
	printf("Material cadastrado!\n");
	pausa();
	
}
void comprarMaterial (Cadastro cadastrados[]) {
	 if (materialQuantidade == 0){
	 	printf("Nenhum material disponivel para compra!\n");
	 	pausa();
	 	return;
	 }
	printf("Materiais disponiveis para compra: \n");
	printf("//==================================================//\n");
	for (int i = 0; i < materialQuantidade; i++) {
		printf("ID: %d\n", i + 1);
		printf("Tipo: %s\n", materiais[i].tipo);
		printf("Quantidade: %.2f\n", materiais[i].quantidade);
		printf("CPF: %d\n", materiais[i].cpfCatador);
		printf("//==================================================//\n");
	}
	printf("Digite o ID do material que deseja comprar (0 para sair): ");
	int escolha;
	scanf("%d", &escolha);
	buffed(); 
	
	int compra = escolha -1;
	
	printf("Comprando %s (%.2f kg) do catador com cpf %d\n", materiais[compra].tipo, 
	materiais[compra].quantidade, materiais[compra].cpfCatador);
	
	float quantidadeCompra;
	printf("Quantos kg deseja comprar? ");
	scanf("%f", &quantidadeCompra);
	buffed();
	
	if (quantidadeCompra > materiais[compra].quantidade) {
		printf("A quantidade que você solicitou não existe no estoque!\n");
		printf("Quantidade disponivel: %.2f", materiais[compra].quantidade);
		pausa();
		return;
	}
	
	for (int i = 0; i < TAM; i++) {
		if (cadastrados[i].catador.cpf == materiais[compra].cpfCatador) {
			float pagamento;
			pagamento = quantidadeCompra * 5;
			cadastrados[i].catador.saldo += pagamento;
			printf("Pagamento de %.2f feita ao catador %s\n", pagamento, cadastrados[i].catador.nome);
			break;
		}
	}
	materiais[compra].quantidade -= quantidadeCompra;
	if(materiais[compra].quantidade == 0){
	for (int i = compra; i < materialQuantidade -1; i++) {
		materiais[i] = materiais [i + 1];
	}
	materialQuantidade--;
	}
	
	printf("Compra realizada!\n");
	pausa(); 
}


void ListarMaterial() {
	limpa();
	printf("Materiais Reciclaveis disponiveis\n");
	printf("1- Ouro\n");
	printf("2- cobre\n");
	printf("3- Ferro\n");
	printf("4- Aluminio\n");
	printf("5- Plastico\n");
}

void menuInicial(Cadastro cadastrado[]) {
	int n;
	do {
		limpa();
		printf("//=================( RECICLA SOFT )=================//\n");
		printf("|\n");
		printf("| (1) - Área dos Catadores \n");
		printf("| (2) - Menu Administrador\n");
		printf("| (0) - Sair\n");
		scanf("%i", &n);
		printf("|\n");
		printf("//==================================================//\n");
		buffed();
		limpa();

		switch(n) {
			case 1: //Menu do catador
				menuCatador(cadastrado);
				break;

			case 2: //Menu de Admin
				loginAdmin(cadastrado);
				break;

			case 3: //Documentação
				//ListarCatadores();
				break;

			case 0: //Finalização do programa
				printf("Encerrando o sistema ............");
				pausa();
				exit(1);
				break;

			default:
				printf("Escolha Invalida");
		}
	} while (n != 0);
}

int main() {
	setlocale(LC_ALL, "portuguese");

	Cadastro cadastrado[TAM] = {{"senai", "senha"}};

	menuInicial(cadastrado);

	/*	 Catador predefinidos[] = {
	        {1, "Moak", "Feira de Santana"},
	        {2, "Ikaro", "Jacobina"},
	        {3, "Erick", "São Paulo"},
	        {4, "Jefite", ""},
	        {5, "Ingrid", ""}
	    };
	    int predefinidosQuantidade = sizeof(predefinidos) / sizeof(predefinidos[0]);

	    Catadores *catador = 0;
	    int quantidade = 0;
	    int maxCatadores = 0;
	    int escolha; */
	return 0;
}