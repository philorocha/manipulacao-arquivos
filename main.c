#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produto {
    char codigo[5];
    char descricao[100];
    float valor;
    int quantidade;
    struct Produto *proximo;
} Produto;

void adicionarProduto(Produto produto) {
    FILE *db = fopen("produtos.bin", "ab");

    if (!db) {
        printf("Não foi possível carregar o arquivo produtos.bin\n");
        EXIT_FAILURE;
    }

    fwrite(&produto, sizeof(Produto), 1, db);

    fclose(db);
}

int main()
{
    Produto p;

    strcpy(p.codigo, "1");
    strcpy(p.descricao, "IPhone 6");
    p.valor = 1250;
    p.quantidade = 4;

    adicionarProduto(p);
    return 0;
}