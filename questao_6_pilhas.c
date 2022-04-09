#include<stdio.h>
#include<stdlib.h>

 

void push (int valor);      // insere elementos no topo da pilha
int pop(void);             // remove elementos da pilha
int tamanhoPilha(void);    // retorna a quantidade de elementos da pilha
int elementoTopo(void);     // retorna elemento que esta no topo da pilha
void vazia(void);            // mostra se a pilha esta vazia

int pilha[10];              // criando pilha estatica
int pos = 0;                // variavel que controla o topo

// inserindo elementos
void push(int valor){
    if(pos >=10){           // verifica se a pilha esta cheia
        printf("\nA pilha esta cheia");
    }
    else 
        pilha[pos] = valor;
        pos++;
    return;
}

// remove elementos
int pop(void){ 
    int rem = --pos;        // pega a posição do elemento no topo
    int pegarValorTopo = pilha[rem];
    pilha[rem] = 0;
    return(pegarValorTopo);  
}

// mostra o tamanho da pilha
int tamanhoPilha(void){
    return pos;
}

// mostra o elemento no topo da pilha
int elementoTopo(void){
    int aux = pos;
    aux = aux-1;
    return pilha[aux];
}

void vazia(){
    if(pos == 0){
        printf("\n A pilha esta vazia");
    }
    else 
    printf("\n Pilha nao vazia");
}

int main(){

printf("Inserindo elementos na pilha... ");
push(14);
push(20);
push(-1);
push(7);

int i;

printf("\nApresentando os Elementos da pilha...");
for (i = 9; i >=0; i--){
    printf("\n %d",pilha[i]);
}

printf("\n Removendo elementos da pilha...");

printf("\n Elemento removido: %d",pop());

printf("\nApresentando os Elementos da pilha...");
for (i = 9; i >=0; i--){
    printf("\n %d",pilha[i]);
}

printf("\n Elemento removido: %d",pop());

printf("\nApresentando os Elementos da pilha...");
for (i = 9; i >=0; i--){
    printf("\n %d",pilha[i]);
}

printf("\n Elemento removido: %d",pop());

printf("\nApresentando os Elementos da pilha...");
for (i = 9; i >=0; i--){
    printf("\n %d",pilha[i]);
}

printf("\n Elemento removido: %d",pop());

printf("\nApresentando os Elementos da pilha...");
for (i = 9; i >=0; i--){
    printf("\n %d",pilha[i]);
}

vazia();

printf("\n Adicionando novos elementos na pilha....");

push(8);
push(5);
push(-10);

printf("\nApresentando os Elementos da pilha...");
for (i = 9; i >=0; i--){
    printf("\n %d",pilha[i]);
}

printf("\n O elemento que esta no topo eh: %d",elementoTopo());

printf("\n O tamanho da pilha eh: %d", tamanhoPilha());

return 0;

}

