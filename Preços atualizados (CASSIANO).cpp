#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/*preços por kilos dos materiais*/
void Menu() {
	printf("|----MENU----|");
	printf("\n|1- Ouro     |");
	printf("\n|2- Cobre    |");
	printf("\n|3- Ferro    |");
	printf("\n|4- Aluminio |");
	printf("\n|5- Plastico |");
	printf("\n|6- Sair...  |");
	printf("\n|------------|");
	printf("\nDeseja escolher qual material?: ");
}
void opcao(int escolha) {
	float resultado = 0;
	float ouro = 115.56;
	float cobre = 40.95;
	float ferro = 5.20;
	float aluminio = 10.50; 
	float plastico = 2.75;
	float kg; 
	
	switch (escolha) {	
		case 1:
		printf("Quantidade em kg de Ouro:");
		scanf("%f", &kg);
		resultado = kg * ouro;
		printf("Valor: %.2f\n", resultado);
		break;
		
		case 2: 
		printf("Quantidade em kg de cobre:");
		scanf("%f", &kg);
		resultado = kg * cobre;
		printf("Valor: %.2f\n", resultado);
		break;
		
		case 3: 
		printf("Quantidade em kg de Ferro:");
		scanf("%f", &kg);
		resultado = kg * ferro;
		printf("Valor: %.2f\n", resultado);
		break;
		
		case 4: 
		printf("Quantidade em kg de Aluminio:");
		scanf("%f", &kg);
		resultado = kg * aluminio;
		printf("Valor: %.2f\n", resultado);
		break;
		
		case 5: 
		printf("Quantidade em kg de Plastico:");
		scanf("%f", &kg);
		resultado = kg * plastico;
		printf("Valor: %.2f\n", resultado);
		break;
		
		case 6:
			printf("Saindo...\n");
			
			default:
			printf("Opção invalida!\n");
			break;
	}
} 
	

int main () {
	setlocale(LC_ALL, "Portuguese");
	int escolha;
	
	
	do {
	Menu();
	scanf("%d", &escolha);
	if (escolha != 6) {
		opcao(escolha);
	}
	} while (escolha != 6);
}
