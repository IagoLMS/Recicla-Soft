#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>

#define MAXMATERIAL 100
#define TAM 50
#define MAX_CATADORES 100

int code = 1;

int numCatadores = 5;  

typedef struct {
	char nome[60];
	char local[100];
	char cpf[12];
	float saldo;

} Catadores;

typedef struct {
	char tipo[30];
	float quantidade[30];
	char cpfCatador[12];
	float preco[30]
} Material;

typedef struct {
	char usuario[40];
	char senha[20];
	Catadores catador;
	Material novoMaterial;

} Cadastro;

Catadores catadores[MAX_CATADORES];  

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

void inicializarCatadores() {

	strcpy(catadores[0].nome, "Moak");
	strcpy(catadores[0].local, "Feira de Santana");
	strcpy(catadores[0].cpf, "12345678901");

	strcpy(catadores[1].nome, "Ikaro");
	strcpy(catadores[1].local, "Jacobina");
	strcpy(catadores[1].cpf, "23456789212");

	strcpy(catadores[2].nome, "Erick");
	strcpy(catadores[2].local, "São Paulo");
	strcpy(catadores[2].cpf, "34567890123");

	strcpy(catadores[3].nome, "Jefite");
	catadores[3].local[0] = "Salvador";  
	strcpy(catadores[3].cpf, "45678901234");

	strcpy(catadores[4].nome, "Ingrid");
	catadores[4].local[0] = "Pernambuco";  
	strcpy(catadores[4].cpf, "56789812345");
}

void carregarDados(Cadastro cadastrado[]) {
	FILE *arquivo = fopen("cadastros.dat", "rb");
	if (arquivo == NULL) {
		printf("Nenhum dado encontrado. Um novo arquivo será criado após salvar.\n");
		return;
	}
	fread(&code, sizeof(int), 1, arquivo);
	fread(cadastrado, sizeof(Cadastro), TAM, arquivo);
	fclose(arquivo);
	printf("Dados carregados com sucesso!\n");
	pausa();
}

void salvarDados(Cadastro cadastrado[]) {
	FILE *arquivo = fopen("cadastros.dat", "wb");
	if (arquivo == NULL) {
		printf("Erro ao abrir o arquivo para salvar os dados.\n");
		return;
	}
	fwrite(&code, sizeof(int), 1, arquivo);
	fwrite(cadastrado, sizeof(Cadastro), TAM, arquivo);
	fclose(arquivo);
	printf("Dados salvos com sucesso!\n");
	pausa();
}

void comprarMaterial (Cadastro cadastrados[]) {
	if (materialQuantidade == 0) {
		printf("Nenhum material disponivel para compra!\n");
		pausa();
		return;
	}
	printf("Materiais disponiveis para compra: \n");
	printf("//==================================================//\n");
	for (int i = 0; i < materialQuantidade; i++) {
		printf("ID: %d\n", i + 1);
		printf("Tipo: %s\n", materiais[i].tipo);
		printf("Quantidade: %.2f\n", materiais[i].quantidade[0]);
		printf("Preço: %.2f", materiais[i].preco[0]);
		//	printf("CPF: %d\n", materiais[i].cpfCatador);
		printf("\n//==================================================//\n");
	}
	printf("Digite o ID do material que deseja comprar (0 para sair): ");
	int escolha;
	scanf("%d", &escolha);
	buffed();

	if(escolha > materialQuantidade) {
		printf("Escolha invalida!\n");
		pausa();
		return 0;

	}
	int compra = escolha -1;

	printf("Comprando %s (%.2f kg) do catador com cpf %s\n", materiais[compra].tipo,
	       materiais[compra].quantidade[0], materiais[compra].cpfCatador);

	float quantidadeCompra;
	printf("Quantos kg deseja comprar? ");
	scanf("%f", &quantidadeCompra);
	buffed();

	if (quantidadeCompra > materiais[compra].quantidade[0]) {
		printf("A quantidade que você solicitou não existe no estoque!\n");
		printf("Quantidade disponivel: %.2f\n", materiais[compra].quantidade[0]);
		pausa();
		return;
	}

	for (int i = 0; i < TAM; i++) {
		if (strcmp(cadastrados[i].catador.cpf, materiais[compra].cpfCatador) == 0) {
			float pagamento = quantidadeCompra * materiais[compra].preco[0];
			materiais[compra].quantidade[0] -= quantidadeCompra;
			cadastrados[i].catador.saldo += pagamento;
			printf("Pagamento de %.2f feito ao catador %s\n", pagamento, cadastrados[i].catador.nome);
			break;
		}
	}

	if(materiais[compra].quantidade[0] == 0) {
		for (int i = compra; i < materialQuantidade -1; i++) {
			materiais[i] = materiais [i + 1];
		}
		materialQuantidade--;
	}

	printf("Compra realizada!\n");
	pausa();
}

void estoqueMaterial(){
	int n, opcao;


	limpa();
	printf("//=================( RECICLA SOFT )=================//\n");
	printf("//===================( ESTOQUE )====================//\n");
	printf("|\n");
	printf("| (1) - Verificar Estoque \n");
	printf("| (2) - Trocar Quantidade\n");
	printf("| (0) - Voltar\n");
	scanf("%i", &n);
	buffed();

	switch(n){
		case 1:
			limpa();
			printf("\nEscolha uma opção: ");
			printf("\nMateriais Reciclaveis disponiveis\n");
			printf("1- %s\n", materiais[0].tipo);
			printf("2- %s\n", materiais[1].tipo);
			printf("3- %s\n", materiais[2].tipo);
			printf("4- %s\n", materiais[3].tipo);
			printf("5- %s\n", materiais[4].tipo);

			scanf("%d", &opcao);
			buffed();
				printf("De %s nós temos: %.2f Kg\n", materiais[opcao - 1].tipo, materiais[opcao - 1].quantidade[0]);

			break;

		case 2:
			limpa();
			printf("\nEscolha uma opção: ");
			printf("Materiais Reciclaveis disponiveis\n");
			printf("1- %s\n", materiais[0].tipo);
			printf("2- %s\n", materiais[1].tipo);
			printf("3- %s\n", materiais[2].tipo);
			printf("4- %s\n", materiais[3].tipo);
			printf("5- %s\n", materiais[4].tipo);

			scanf("%d", &opcao);
			buffed();

			printf("\nDigite a nova quantidade do material: ");
			scanf("%f",&materiais[opcao - 1].quantidade[0]);
			pausa();
			break;
	}

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

void cadastroCatador(Cadastro cadastrado[]) {
	if (numCatadores >= MAX_CATADORES) {
		printf("//====================( Cadastro )==================//\n");
		printf("| Espaço de memória cheio. Por favor, aloque mais espaço.\n");
		pausa();
		return;
	}

	printf("//====================( Cadastro )==================//\n");
	printf("| Insira seu Nome:\n");
	buffed();
	gets(catadores[numCatadores].nome);

	printf("| Insira sua Localizacao:\n");
	buffed();
	gets(catadores[numCatadores].local);

	printf("Informe o cpf: ");
	buffed();
	gets(catadores[numCatadores].cpf);

	printf("Informe o usuario ");
	buffed();
	gets(cadastrado[code].usuario);

	printf("| Insira sua senha:\n");
	buffed();
	gets(cadastrado[code].senha);

	cadastrado[code].catador.saldo = 0.0;

	printf("| Cadastro realizado com sucesso!\n");
	printf("//==================================================//\n");
	pausa();
	code++;
	numCatadores++; 
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
				printf("(2) Saldo");
				printf("(0) Voltar");
				printf("\nEscolha uma opção: ");
				scanf("%d", &opcao);
				buffed();
				pausa();

				switch (opcao) {
					case 1:
						printf("//=================(Escolha Material)=================//\n");
						//estoqueMaterial);
						cadastrarMaterial(cadastrado);
						break;
				case 2:
				for (int i = 0; i < code; i++) {
        		if (strcmp(testeUsuario, cadastrado[i].usuario) == 0) {
           		printf("Saldo atual: R$ %.2f\n", cadastrado[i].catador.saldo);
            	pausa();
            	break;
        }
    }
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
		printf("\n");

		printf("ÁREA DE CADASTRO\n");
		printf("___________________________\n");
		printf("|2- Lista de Materiais\n");
		printf("\n");

		printf("ÁREA DOS CATADORES\n");
		printf("___________________________\n");
		printf("|3- Listar Catadores \n");
		printf("\n");

		printf("ÁREA DOS PAGAMENTO\n");
		printf("___________________________\n");
		printf("|4- Comprar material \n");

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
				estoqueMaterial();
				break;

			case 2: //materiais
			printf("Materiais Reciclaveis disponiveis\n");
				printf("1- Ouro\n");
				printf("2- cobre\n");
				printf("3- Ferro\n");
				printf("4- Aluminio\n");
				printf("5- Plastico\n");
				pausa();
				break;
				break;

			case 3: //listar catadores
				listarCatadores(cadastrados);
				break;
			case 4: //compra de material
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

void listarCatadores() {
	limpa();
	printf("Lista de Catadores:\n");
	printf("====================\n");

	for (int i = 0; i < numCatadores; i++) {
		printf("ID: %d\n", i + 1);
		printf("Nome: %s\n", catadores[i].nome);
		printf("Localização: %s\n", catadores[i].local[0] != '\0' ? catadores[i].local : "Não informado");
		printf("CPF: %s\n", catadores[i].cpf);
		printf("---------------------\n");
	}
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

void cadastrarMaterial(Cadastro *cadastrado) {
	if (materialQuantidade >= MAXMATERIAL) {
		printf("Capacidade máxima de material! ");
		pausa();
		return;
	}
	Material novoMaterial;
	ListarMaterial();
	buffed();
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
			strcpy(novoMaterial.tipo, "Alumínio");
			break;
		case 5:
			strcpy(novoMaterial.tipo, "Plástico");
			break;
		default:
			printf("Informação inválida!\n");
			pausa();
			return;
	}

	printf("Quantos Kg você tem do material? ");
	scanf("%f", &novoMaterial.quantidade[0]);
	buffed();

	printf("Digite o preço por kg: ");
	scanf("%f", &novoMaterial.preco[0]);
	buffed();

	strcpy(novoMaterial.cpfCatador, cadastrado->catador.cpf);
	materiais[materialQuantidade++] = novoMaterial;

	printf("Material cadastrado com sucesso!\n");
	pausa();
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
				//listarCatadores();
				break;

			case 0: //Finalização do programa
				salvarDados(cadastrado);
				limpa();
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
	setlocale(LC_ALL, "Portuguese");

	Cadastro cadastrado[TAM] = {{"senai", "senha"}};
	inicializarCatadores(); 
	carregarDados(cadastrado);

	menuInicial(cadastrado);
	return 0;
}