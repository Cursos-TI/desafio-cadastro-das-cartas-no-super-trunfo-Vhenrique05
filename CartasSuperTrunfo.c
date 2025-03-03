///
/// Feito em 17/02/2025 por Vitor Henrique (VHenrique05@utlook.com)
///

#include <locale.h>
#include <stdio.h>

// define uma estrutura base para as informações das cartas
typedef struct {
	char estado; // Estado da Carta
	char codigo[4]; // Código da Carta (A01, A02, B01, B02)
	char nome_da_cidade[45]; // Nome da Cidade
	unsigned long int populacao; // População Total da Cidade
	float area_km2; // Área da Cidade em km²
	float PIB; // PIB da Cidade
	int pontos_turisticos; // Quantidade de Pontos Turísticos que a Cidade possúi
} Carta;

// Usado para armazenar as informações das cartas
Carta carta_um;
Carta carta_dois;

// função para calcular a densidade populacional da carta:
float calcular_densidade_populacional(const Carta carta) {
	// como a variável "população" é do tipo int,
	// eu converto ela para float diretamente:
	return ((float)carta.populacao / carta.area_km2);
}

// função para calcular o PIB per capita da carta:
float calcular_PIB_per_capita(const Carta carta) {
	return (carta.PIB / (float)carta.populacao);
}

float calcular_super_poder(const Carta carta) {
	return (
		(float)carta.populacao + carta.area_km2
		+ carta.PIB + (float)carta.pontos_turisticos
		+ (1 / calcular_densidade_populacional(carta))
		+ calcular_PIB_per_capita(carta)
	);
}

Carta criar_carta() {
	// cria uma variável para as informações da carta, usando a estrutura "Card"
	Carta carta;

	printf("\nInsira o Estado da Cidade:\n>> ");
	scanf("%c", &carta.estado);

	printf("\nInsira o código da Carta:\n>> ");
	scanf("%4s", &carta.codigo); // lê apenas 4 caracteres

	printf("\nInsira o nome da Cidade:\n>> ");
	scanf("%40s", &carta.nome_da_cidade); // lê até 40 caracteres

	printf("\nInsira a População da Cidade:\n>> ");
	scanf("%ld", &carta.populacao);

	printf("\nInsira a Área da Cidade (em km²):\n>> ");
	scanf("%f", &carta.area_km2);

	printf("\nInsira o PIB da Cidade:\n>> ");
	scanf("%f", &carta.PIB);

	printf("\nInsira a Quantidade de Pontos Turísticos, que a Cidade possúi:\n>> ");
	scanf("%d", &carta.pontos_turisticos);

	printf("\n############################\n");
	printf("Confira as Informações: \n");
	printf(" * Estado:                     %c\n", carta.estado);
	printf(" * Código:                     %s\n", carta.codigo);
	printf(" * Nome:                       %s\n", carta.nome_da_cidade);
	printf(" * População:                  %ld Habitantes\n", carta.populacao);
	printf(" * Estado:                     %.2f km²\n", carta.area_km2);
	printf(" * PIB:                        %.2f Bilhões de Reais\n", carta.PIB);
	printf(" * Qnt. de Pontos Turísticos:  %d\n", carta.pontos_turisticos);
	printf("############################\n");

	return carta;
}

void mostrar_dados() {
	printf("Confira todas as informações registradas: \n\n");

	// eu uso o printf com o argumento "%.2f" para imprimir apenas os 2 dígitos decimais

	// para otimizar o código, eu calculo as informações aqui:
	float densidade_populacional_um = calcular_densidade_populacional(carta_um);
	float densidade_populacional_dois = calcular_densidade_populacional(carta_dois);

	float pib_per_capita_um = calcular_PIB_per_capita(carta_um);
	float pib_per_capita_dois = calcular_PIB_per_capita(carta_dois);

	float super_poder_um = calcular_super_poder(carta_um);
	float super_poder_dois = calcular_super_poder(carta_dois);

	printf("########### Carta 1 ###########\n");
	printf(" * Estado:                     %c\n", carta_um.estado);
	printf(" * Código:                     %s\n", carta_um.codigo);
	printf(" * Nome:                       %s\n", carta_um.nome_da_cidade);
	printf(" * População:                  %ld Habitantes\n", carta_um.populacao);
	printf(" * Estado:                     %.2f km²\n", carta_um.area_km2);
	printf(" * PIB:                        %.2f Bilhões de Reais\n", carta_um.PIB);
	printf(" * Qnt. de Pontos Turísticos:  %d\n", carta_um.pontos_turisticos);
	printf(" * Densidade Populacional:     %.2f\n", densidade_populacional_um);
	printf(" * PIB per Capita:             %.2f\n", calcular_PIB_per_capita(carta_um));
	printf(" * Super Poder:                %.2f\n", calcular_super_poder(carta_um));

	printf("\n");
	printf("########### Carta 2 ###########\n");
	printf(" * Estado:                     %c\n", carta_dois.estado);
	printf(" * Código:                     %s\n", carta_dois.codigo);
	printf(" * Nome:                       %s\n", carta_dois.nome_da_cidade);
	printf(" * População:                  %ld Habitantes\n", carta_dois.populacao);
	printf(" * Estado:                     %.2f km²\n", carta_dois.area_km2);
	printf(" * PIB:                        %.2f Bilhões de Reais\n", carta_dois.PIB);
	printf(" * Qnt. de Pontos Turísticos:  %d\n", carta_dois.pontos_turisticos);
	printf(" * Densidade Populacional:     %.2f\n", densidade_populacional_dois);
	printf(" * PIB per Capita:             %.2f\n", calcular_PIB_per_capita(carta_dois));
	printf(" * Super Poder:                %.2f\n", calcular_super_poder(carta_dois));
	printf("\n");

	printf("######### Comparações #########\n");
	printf(" 2 - Empate entre as Cartas\n");
	printf(" 1 - Primeira Carta Vence\n");
	printf(" 0 - Segunda Carta Vence\n");

	// Aqui verifica se os valores da Carta são diferentes:
	// Então checa qual deles é maior (retornando 1 ou 0),
	// exceto no caso da Densidade Demográfica, que verifica o menor.
	// Senão: ele retorna 2 (para empate)
	printf(" * População:                  %d\n", carta_um.populacao != carta_dois.populacao ? carta_um.populacao > carta_dois.populacao : 2);
	printf(" * Estado:                     %d\n", carta_um.area_km2 != carta_dois.area_km2 ? carta_um.area_km2 > carta_dois.area_km2 : 2);
	printf(" * PIB:                        %d\n", carta_um.PIB != carta_dois.PIB ? carta_um.PIB > carta_dois.PIB : 2);
	printf(" * Qnt. de Pontos Turísticos:  %d\n", carta_um.pontos_turisticos != carta_dois.pontos_turisticos ? carta_um.pontos_turisticos > carta_dois.pontos_turisticos : 2);
	printf(" * Densidade Populacional:     %d\n", densidade_populacional_um != densidade_populacional_dois ? densidade_populacional_um < densidade_populacional_dois : 2);
	printf(" * PIB per Capita:             %d\n", pib_per_capita_um != pib_per_capita_dois ? pib_per_capita_um > pib_per_capita_dois : 2);
	printf(" * Super Poder:                %d\n", super_poder_um != super_poder_dois ? super_poder_um > super_poder_dois : 2);
}

int main(void) {
	setlocale(LC_ALL, "portuguese");

	printf("Bem vindo ao Super Trunfo - Países!\n");
	printf("Insira as informações pedidas para funcionar!\n");

	// usa a função para ler os dados das cartas
	// e salvar seus valores nas variáveis:
	carta_um = criar_carta();
	carta_dois = criar_carta();

	// chama a função para mostrar os dados salvos:
	mostrar_dados();

	printf("Fechando o programa...\n");

	return 0;
}
