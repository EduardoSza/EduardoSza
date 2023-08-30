#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int count_bits(unsigned int num) {
	int count = 0;
	while (num) {
		count++;
		num >>= 1;
	}
	return count;
}

void print_binary(unsigned int num, int n_bits) {
	for (int i = n_bits - 1; i >= 0; i--) {
		printf("%d", (num >> i) & 1);
		if (i % 4 == 0) printf(" ");
	}
	printf("\n");
}

int main() {
	unsigned int num1, num2, mask;
	int n_bits, op, n, dir;

	printf("Escolha a operação bitwise a ser realizada:\n");
	printf("1 - Complemento\n");
	printf("2 - E bit a bit (&)\n");
	printf("3 - OU bit a bit (|)\n");
	printf("4 - XOR bit a bit (^)\n");
	printf("5 - Extrair bits usando máscara bitwise\n");
	printf("6 - Preencher com 1s usando máscara bitwise\n");
	printf("7 - Inverter valores usando máscara bitwise\n");
	printf("8 - Shift de bits para esquerda ou direita\n");
	scanf("%d", &op);

	switch(op){
		case 1:
			printf("Digite o número sem sinal em hexadecimal: ");
			scanf("%x", &num1);

			n_bits = count_bits(num1);
			n_bits = (n_bits + 3) / 4 * 4; // arredonda para cima para o múltiplo de 4 mais próximo
			mask = (1 << n_bits) - 1;

			printf("Número original em binário: ");
			print_binary(num1, n_bits);

			printf("Complemento: ");
			num1 = ~num1 & mask;

			print_binary(num1, n_bits);

			printf("Resultado final em hexadecimal: 0x%X\n", num1);
			break;
		case 2:
		case 3:
		case 4:
			printf("Digite o primeiro número sem sinal em hexadecimal: ");
			scanf("%x", &num1);

			printf("Digite o segundo número sem sinal em hexadecimal: ");
			scanf("%x", &num2);

			n_bits = count_bits(num1 > num2 ? num1 : num2);
			n_bits = (n_bits + 3) / 4 * 4; // arredonda para cima para o múltiplo de 4 mais próximo

			printf("Primeiro número original em binário: ");
			print_binary(num1, n_bits);

			printf("Segundo número original em binário: ");
			print_binary(num2, n_bits);

			switch (op) {
				case 2:
					printf("E bit a bit (&): ");
					num1 &= num2;
					break;
				case 3:
					printf("OU bit a bit (|): ");
					num1 |= num2;
					break;
				case 4:
					printf("XOR bit a bit (^): ");
					num1 ^= num2;
					break;
				default:
					break;
			}

			print_binary(num1, n_bits);

			printf("Resultado final em hexadecimal: 0x%X\n", num1);
			break;
		case 5:
		case 6:
		case 7:
		case 8:
			printf("Digite o número sem sinal em hexadecimal: ");
			scanf("%x", &num1);

			n_bits = count_bits(num1);
			n_bits = (n_bits + 3) / 4 * 4; // arredonda para cima para o múltiplo de 4 mais próximo

			printf("Número original em binário: ");
			print_binary(num1, n_bits);

			printf("Digite o número de bits a serem movidos: ");
			scanf("%d", &n);

			mask = (1 << n) - 1;

			printf("Escolha se os bits serão movidos da direita (0) ou da esquerda (1): ");
			scanf("%d", &dir);

			switch(op){
				case 5:
					if (dir == 0) {
						printf("Bits extraídos da direita usando máscara bitwise: ");
						num1 &= ~mask;
					} else if (dir == 1) {
						printf("Bits extraídos da esquerda usando máscara bitwise: ");
						mask <<= n_bits - n;
						num1 &= ~mask;
					} else {
						printf("Direção inválida!\n");
						return EXIT_FAILURE;
					}
					break;
				case 6:
					if (dir == 0) {
						printf("Bits preenchidos com 1s da direita usando máscara bitwise: ");
						num1 |= mask;
					} else if (dir == 1) {
						printf("Bits preenchidos com 1s da esquerda usando máscara bitwise: ");
						mask <<= n_bits - n;
						num1 |= mask;
					} else {
						printf("Direção inválida!\n");
						return EXIT_FAILURE;
					}
					break;
				case 7:
					if (dir == 0) {
						printf("Valores dos bits invertidos da direita usando máscara bitwise: ");
						num1 ^= mask;
					} else if (dir == 1) {
						printf("Valores dos bits invertidos da esquerda usando máscara bitwise: ");
						mask <<= n_bits - n;
						num1 ^= mask;
					} else {
						printf("Direção inválida!\n");
						return EXIT_FAILURE;
					}
					break;
				case 8:
					if(dir==0){
						printf("\nShift dos bits para a direita:");
						num1>>=n;
						print_binary(num1,n_bits);
						printf("\nResultado final em hexadecimal: 0x%X\n",num2);
						break;
					}
					else if(dir==1){
						printf("\nShift dos bits para a esquerda:");
						num1<<=n;
						print_binary(num1,n_bits);
						printf("\nResultado final em hexadecimal: 0x%X\n",num2);
						break;
					}
				default:
					break;
			}

			print_binary(num1, n_bits);

			printf("Resultado final em hexadecimal: 0x%X\n", num1);
			break;

		default:
			printf("Operação inválida!\n");
			return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
