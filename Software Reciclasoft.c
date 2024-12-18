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
	float preco[30];
} Material;

typedef struct {
	char usuario[40];
	char senha[20];
	Catadores catadores;
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

void carregarDados(Cadastro cadastrado[]) {
	FILE *arquivo = fopen("cadastros.dat", "rb");
	if (arquivo == NULL) {
		printf("| Nenhum dado encontrado. Um novo arquivo sera criado apos salvar.\n");
		pausa();
		return;
	}
	fread(&code, sizeof(int), 1, arquivo);
	fread(cadastrado, sizeof(Cadastro), TAM, arquivo);
	fclose(arquivo);
	printf("| Dados carregados com sucesso!\n");
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

void comprarMaterial (Cadastro cadastrado[]) {
	if (materialQuantidade == 0) {
		printf("\n\nNenhum material disponivel para compra!\n");
		pausa();
		return;
	}
	printf("Materiais disponiveis para compra: \n");
	printf("//==================================================//\n");
	for (int i = 0; i < materialQuantidade; i++) {
		printf("ID: %d\n", i + 1);
		printf("Tipo: %s\n", materiais[i].tipo);
		printf("Quantidade: %.2f\n", materiais[i].quantidade[0]);
		printf("Preço: %.2f\n", materiais[i].preco[0]);
		printf("CPF: %s\n", materiais[i].cpfCatador);
		printf("\n//==================================================//\n");
	}
	printf("Digite o ID do material que deseja comprar (0 para sair): ");
	int escolha;
	scanf("%d", &escolha);
	buffed();

	if(escolha > materialQuantidade) {
		printf("Escolha invalida!\n");
		pausa();
		return;

	}
	int compra = escolha -1;

	printf("Comprando %s (%.2f kg) do catador com cpf %s\n", materiais[compra].tipo,
	       materiais[compra].quantidade[0], materiais[compra].cpfCatador);

	float quantidadeCompra;
	printf("Quantos kg deseja comprar? ");
	scanf("%f", &quantidadeCompra);
	buffed();

	if (quantidadeCompra > materiais[compra].quantidade[0]) {
		printf("A quantidade que voce solicitou nao existe no estoque!\n");
		printf("Quantidade disponivel: %.2f\n", materiais[compra].quantidade[0]);
		pausa();
		return;
	}

	for (int i = 0; i < TAM; i++) {
		if (strcmp(cadastrado[i].catadores.cpf, materiais[compra].cpfCatador) == 0) {
			float pagamento = quantidadeCompra * materiais[compra].preco[0];
			materiais[compra].quantidade[0] -= quantidadeCompra;
			cadastrado[i].catadores.saldo += pagamento;
			printf("Pagamento de %.2f feito ao catador %s\n", pagamento, cadastrado[i].catadores.nome);
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

void estoqueMaterial() {
	int n, opcao;


	limpa();
	printf("//=================( RECICLA SOFT )=================//\n\n");
	printf("//===================( ESTOQUE )====================//\n");
	printf("|\n");
	printf("| (1) - Verificar Estoque \n");
	printf("| (2) - Trocar Quantidade\n");
	printf("| (0) - Voltar\n");
	scanf("%i", &n);
	buffed();

	switch(n) {
		case 1:
			limpa();
			printf("\nEscolha uma opcao: ");
			printf("\nMateriais Reciclaveis disponiveis\n");
			printf("1- %s\n", materiais[0].tipo);
			printf("2- %s\n", materiais[1].tipo);
			printf("3- %s\n", materiais[2].tipo);
			printf("4- %s\n", materiais[3].tipo);
			printf("5- %s\n", materiais[4].tipo);

			scanf("%d", &opcao);
			buffed();
			printf("De %s nos temos: %.2f Kg\n", materiais[opcao - 1].tipo, materiais[opcao - 1].quantidade[0]);

			break;

		case 2:
			limpa();
			printf("\nEscolha uma opcao: ");
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
	printf("Materiais reciclaveis disponiveis:\n");
	printf("1- Ouro\n");
	printf("2- Cobre\n");
	printf("3- Ferro\n");
	printf("4- Aluminio\n");
	printf("5- Plastico\n");
}

void cadastroCatador(Cadastro cadastrado[]) {
	int validacao;

	if (numCatadores >= MAX_CATADORES) {
		printf("//====================( Cadastro )==================//\n");
		printf("| Espaço de memoria cheio. Por favor, aloque mais espaço.\n");
		pausa();
		return;
	}
	do {

		printf("//====================( Cadastro )==================//\n\n");
		printf("| Insira seu Nome e Sobrenome: ");
		buffed();
		gets(cadastrado[code].catadores.nome);

		printf("| Insira sua Localizacao(Atual): ");
		buffed();
		gets(cadastrado[code].catadores.local);

		printf("| Informe o CPF: ");
		buffed();
		gets(cadastrado[code].catadores.cpf);

		if(strlen(cadastrado[code].catadores.cpf) == 11) {

		} else {
			limpa();
			printf("\n\n| CPF Invalido! Insira a quantidade de numeros corretos.\n");
			pausa();
			return;
		}

		for (int i = 0; i < code; i++) {
			if (strcmp(cadastrado[code].catadores.cpf, cadastrado[i].catadores.cpf) == 0) {
				limpa();
				pausa();
				printf("| CPF ja foi cadastrado! Cadastro cancelado.\n");
				limpa();
				return;
			}
		}

		printf("| Confirmar cadastro ( 0- Cancelar | 1- Confirmar )");
		scanf("%i", &validacao);

		if(validacao == 0) {
			limpa();
			printf("| Cadastro Cancelado!  \n");
			pausa();
			return;
		}

	} while(validacao !=1 );

	printf("//==================================================//\n\n");
	printf("| Insira um Usuario: \n");
	buffed();
	gets(cadastrado[code].usuario);

	printf("| Insira uma Senha: \n");
	buffed();
	gets(cadastrado[code].senha);

	cadastrado[code].catadores.saldo = 0.0;

	printf("//==================================================//\n\n");
	printf("| 	Cadastro realizado com sucesso!\n\n");
	printf("//==================================================//\n");
	pausa();

	code++;
	numCatadores++;
}

int validador(Cadastro cadastrado[], char *testeUsuario, char *testeSenha) {
	for (int i = 0; i < code; i++) {
		if (strcmp(testeUsuario, cadastrado[i].usuario) == 0 && strcmp(testeSenha, cadastrado[i].senha) == 0) {
			return 1;
		}
	}
	return 0;
}


void cadastrarMaterial(Cadastro *cadastrado, int posicao) {
	if (materialQuantidade >= MAXMATERIAL) {
		limpa();
		printf("| Capacidade maxima de material! ");
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
			strcpy(novoMaterial.tipo, "Aluminio");
			break;
		case 5:
			strcpy(novoMaterial.tipo, "Plastico");
			break;
		default:
			printf("Informaçao invalida!\n");
			pausa();
			return;
	}

	printf("| Quantos Kg voce tem do material? ");
	scanf("%f", &novoMaterial.quantidade[0]);
	buffed();

	printf("| Digite o preco por kg: ");
	scanf("%f", &novoMaterial.preco[0]);
	buffed();

	strcpy(novoMaterial.cpfCatador, cadastrado[posicao].catadores.cpf);
	materiais[materialQuantidade++] = novoMaterial;

	printf("| Material cadastrado com sucesso!\n");
	pausa();
}

int validadorPosicao(Cadastro cadastrado[], char *testeUsuario, char *testeSenha) {
	int posicao;

	for (int i = 0; i < code; i++) {
		if (strcmp(testeUsuario, cadastrado[i].usuario) == 0 && strcmp(testeSenha, cadastrado[i].senha) == 0) {
			return posicao = i;
		}
	}
	return 0;
}

void loginCatador(Cadastro cadastrado[]) {
	char testeUsuario[50];
	char testeSenha[20];
	int opcao, posicao;
	float kg;
	do {
		printf("//=================( LOGIN CATADOR )=================//\n");
		printf("|\n");

		printf("| Usuario:\n");
		buffed();
		gets(testeUsuario);
		printf("|\n");

		printf("| Senha:\n");
		gets(testeSenha);
		printf("|\n");
		printf("//===================================================//\n");

		posicao = validadorPosicao(cadastrado, testeUsuario, testeSenha);

		if (validador(cadastrado, testeUsuario, testeSenha) == 1) {
			printf("| Login bem-sucedido! Bem-vindo, %s.\n", testeUsuario);
			pausa();
			do {
				limpa();
				printf("//=================( RECICLA SOFT )=================//\n");
				printf("| Nome: %s \n", cadastrado[posicao].catadores.nome);
				printf("| CPF: %s \n", cadastrado[posicao].catadores.cpf);
				printf("| Localizacao (Atual): %s \n", cadastrado[posicao].catadores.local);
				for (int i = 0; i < code; i++) {
					if (strcmp(testeUsuario, cadastrado[i].usuario) == 0) {
						printf("| Saldo atual: R$ %.2f\n", cadastrado[i].catadores.saldo);
					}
				}

				printf("___________________________\n");

				printf("|(1) Cadastre seu material\n\n");
				printf("|(0) Voltar\n\n");

				printf("//==================================================//\n");
				printf("Escolha uma opcao: ");
				scanf("%i", &opcao);
				buffed();
				printf("//==================================================//\n");
				pausa();
				limpa();

				switch (opcao) {
					case 1:
						printf("//=================(Escolha Material)=================//\n");
						cadastrarMaterial(cadastrado, posicao);
						break;

					case 0:
						printf("Voltando...\n");
						return;

					default:
						printf("Opcao invalida!\n");
						pausa();
				}
			} while (opcao != 0) ;
		} else {
			printf("Usuario ou senha incorretos. Tente novamente.\n");
		}
	} while (1);
}


void menuCatador(Cadastro cadastrado[]) {
	int n;
	do {
		limpa();
		printf("//===================( Catadores )==================//\n");
		printf("|\n");
		printf("| (1) - Cadastro \n");
		printf("| (2) - Login \n\n");
		printf("| (0) - Voltar \n");
		printf("|\n");
		printf("//==================================================//\n");
		printf("Escolha uma opcao: ");
		scanf("%i", &n);
		buffed();
		printf("//==================================================//\n");
		switch(n) {
			case 1: 
				cadastroCatador(cadastrado);
				break;

			case 2:
				loginCatador(cadastrado);
				break;

			case 0: 
				limpa();
				pausa();
				return;

			default:
				limpa();
				printf("| Escolha Invalida!");
				pausa ();
		}
	} while (n != 0);
}

void listarCatadores(Cadastro cadastrado[]) {
	limpa();
	printf(":\n");
	printf("//======================( Lista dos Catadores )=====================//\n");

	for (int i = 1; i < code; i++) {
		printf("ID: %d\n", i);
		printf("Nome: %s\n", cadastrado[i].catadores.nome);
		printf("Localizacao: %s\n", cadastrado[i].catadores.local);
		printf("Saldo: R$%.2f\n", cadastrado[i].catadores.saldo);
		printf("CPF: %s\n", cadastrado[i].catadores.cpf);
		printf("//==================================================//\n");

	}
	pausa();
}

void menuADM(Cadastro cadastrado[]) {
	int escolha;
	do {
		printf("//======================( ADM )=====================//\n");
		printf("\n");

		printf("MATERIAIS:\n");
		printf("___________________________\n");
		printf("|1- Estoque\n");
		printf("\n");

		printf("AREA DE CADASTRO\n");
		printf("___________________________\n");
		printf("|2- Lista de Materiais\n");
		printf("\n");

		printf("AREA DOS CATADORES\n");
		printf("___________________________\n");
		printf("|3- Listar Catadores \n");
		printf("\n");

		printf("AREA DOS PAGAMENTO\n");
		printf("___________________________\n");
		printf("|4- Comprar material \n");

		printf("\n");
		printf("___________________________\n");
		printf("|0- Menu inicial");
		printf("\n");
		printf("//==================================================//\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &escolha);
		buffed();
		limpa();
		pausa();

		switch (escolha) {
			case 1: 
				estoqueMaterial();
				break;

			case 2: 
				ListarMaterial();
				pausa();
				break;

			case 3:
				listarCatadores(cadastrado);
				break;
			case 4:
				comprarMaterial(cadastrado);
				break;
			case 0:
				printf("___________________________________\n");
				printf("| Voltando para o menu inicial...\n");
				pausa();
				return;

			default:
				printf("___________________________________\n");
				printf("| Opção Invalida!");
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
		printf("| Usuario:\n");
		buffed();
		gets(testeUsuario);

		printf("|\n");

		printf("| Senha:\n");
		gets(testeSenha);

		printf("|\n");
		printf("//==================================================//\n");
		limpa();
		if (strcmp(testeUsuario, cadastrado[0].usuario) == 0 && strcmp(testeSenha, cadastrado[0].senha) == 0) {
			printf("| Login bem-sucedido! Bem-vindo, %s.\n", testeUsuario);
			pausa();
			limpa();
			menuADM(cadastrado);
			return;
		} else {
			limpa();
			printf("| Usuario ou senha incorretos. Tente novamente.\n");
			pausa();
		}
	} while (1);
}

void menuInicial(Cadastro cadastrado[]) {
	int n;
	do {
		limpa();
		printf("//=================( RECICLA SOFT )=================//\n");
		printf("\n");
		printf("| (1) - Catador \n");
		printf("| (2) - Administrador\n\n");
		printf("| (0) - Sair\n");
		printf("\n");
		printf("//==================================================//\n");
		printf("|Escolha uma opcao: ");
		scanf("%d", &n);
		buffed();
		printf("//==================================================//\n");
		limpa();

		switch(n) {
			case 1: 
				menuCatador(cadastrado);
				break;

			case 2: 
				loginAdmin(cadastrado);
				break;

			case 0:
				salvarDados(cadastrado);
				limpa();
				printf("\n\n| Encerrando o sistema ............");
				pausa();
				exit(1);
				break;

			default:
				printf("Escolha Invalida!");
		}
	} while (n != 0);
}

int main() {
	setlocale(LC_ALL, "Portuguese");

	Cadastro cadastrado[TAM] = {{"senai", "senha"}};
	carregarDados(cadastrado);

	menuInicial(cadastrado);
	return 0;
}