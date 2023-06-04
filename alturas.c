#include <stdio.h>
#include <string.h>
#include <math.h>

void ler_texto(char *buffer, int length) {
 fgets(buffer, length, stdin);
 strtok(buffer, "\n");
}

void limpar_entrada() {
 char c;
 while ((c = getchar()) != '\n' && c != EOF) {}
}

int main (){

    int n, i;

    printf("Quantas pessoas serao digitadas? ");
    scanf("%d", &n);

    int idade [n];
    double altura [n];
    char nome [n][50];

    for ( i = 0; i < n ; i++ ){
        printf("Dados da %da pessoa\n", i + 1);
        printf("Nome: ");
        limpar_entrada();
        ler_texto(nome[i], 50);
        printf("Idade: ");
        scanf("%d", &idade[i]);
        printf("Altura: ");
        scanf("%lf", &altura[i]);
    }

    double media, soma, perc;
    int menor;

    soma = 0;
    media = 0;
    menor = 0;

    for (i = 0; i < n; i++){
        if (idade[i] < 18 ){
            menor++;
        }
        soma = soma + altura[i];
    }

    perc =  ((double)menor * 100) / n;
    media = soma / n;

    printf("Altura media das pesosas e igual a %.2lfm\n", media);
    printf("O percentual de pessoas abaixo de 18 anos e igual a %.2lf\n", perc);
    printf("Segue a lista do menores de 18 anos\n");

    for (i = 0; i < n; i++){
        if (idade[i] < 18 ){
                printf("%s\n", nome[i]);
        }
    }
    return 0;
}
