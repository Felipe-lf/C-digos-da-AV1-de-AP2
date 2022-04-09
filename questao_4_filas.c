#include<stdio.h>
#include<stdlib.h>

#define TAMANHO_DA_FILA 100

//Estrutura da fila
struct fila {
    int itens[TAMANHO_DA_FILA];
    int frente;
    int atras;
};

// verifica se a fila esta vazia
int verificaFilaVazia(struct fila *pq){
    if(pq -> frente != pq -> atras){
        return 0;
    }
    else
        return 1;
}

// insere intens na fila
void inserirItem(struct fila *pq, int x){

    if(pq -> atras+1 >= TAMANHO_DA_FILA){
        printf("\n Fila esta cheia!");
        exit(1);
    }
    else
        pq -> itens[pq -> atras++] = x;

}

// retorna o tamanho da fila
int tamanho(struct fila *pq){
    return pq -> atras;
}

// consulta o proximo item a ser acessado na fila
int proximo(struct fila *pq){
    return pq -> itens[0];
}

// Remove elementos de uma fila
int removeItem(struct fila *pq){
    int x, i;

    if(verificaFilaVazia(pq)){
        printf("\n Fila vazia, nao eh possivel remover itens");
        exit(1);
    }

    x = proximo(pq);

    for (i = 0; i < tamanho(pq); i++){
        pq -> itens[i] = pq -> itens[i+1];
    }

    pq -> atras--;

    return x;

}

// esvazia a fila
void esvaziarFila(struct fila *pq){
    int tam = tamanho(pq);
    int i;

    printf("\nEsvaziando fila...");

    for(i = 0; i < tam; i++){
        printf("\nItem %d removido da fila.", removeItem(pq));
    }
}

int main(){
    //criação de uma fila vazia

    struct fila nossaFila;
    nossaFila.frente = 0; // inicio da fila
    nossaFila.atras = 0;  // fim da fila

    inserirItem(&nossaFila,30); // testa inserir item
    inserirItem(&nossaFila,1);
    inserirItem(&nossaFila,3);
    inserirItem(&nossaFila,6);
    printf("\n item 0 da fila: %d",nossaFila.itens[0]);
    printf("\n item 1 da fila: %d",nossaFila.itens[1]);
    printf("\n item 2 da fila: %d",nossaFila.itens[2]);
    printf("\n item 3 da fila: %d",nossaFila.itens[4]);

    printf("\n Valor resultante: %d", verificaFilaVazia(&nossaFila)); // testa se a função fila vazia esta correta

    printf("\n Tamanho da fila: %d",tamanho(&nossaFila)); // testa a função que retorna o tamanho da fila

    printf("\n Proximo a ser atendido: %d",proximo(&nossaFila)); // testa a função referente ao proximo elemento a ser atendido

    printf("\n O elemento removido foi: %d",removeItem(&nossaFila)); // testa a função de remoção de item

    printf("\n item 0 da fila: %d",nossaFila.itens[0]);
    printf("\n item 1 da fila: %d",nossaFila.itens[1]);
    printf("\n item 2 da fila: %d",nossaFila.itens[2]);

    printf("\n Tamanho da fila: %d",tamanho(&nossaFila));

    printf("\n Proximo a ser atendido: %d",proximo(&nossaFila));

    esvaziarFila(&nossaFila);

    printf("\n Valor resultante: %d", verificaFilaVazia(&nossaFila));
    printf("\n Tamanho da fila: %d",tamanho(&nossaFila));
    
    return 0;
}