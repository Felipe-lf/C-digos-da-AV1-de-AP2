#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct notaFiscal{
    int id;                 //Indentificador do produto
    int qtdProduto;        //Quantidade do produto
    char produto[20];    //Nome do produto
    struct notaFiscal *prox;    //Ponteiro para o proximo
    struct notaFiscal *anter;   //ponteiro para o anterior
};

//função de adicionar elementos

void adicionar(struct notaFiscal **p, int i, int qtd, char pdto[20]){

    struct notaFiscal *aux;

    if (*p == NULL){                //se estiver vazia adcione um element0
        *p = (struct notaFiscal *)malloc(sizeof(struct notaFiscal));    // alocando espaço na memoria

        if (*p == NULL){                                                    // se houver erro de alocação pare o programa
            printf("\nErro de alocacao de memoria");
            exit(1);
        }
        // se não houver erro, armazene os dados na lista

        (*p) -> id = i;
        (*p) -> qtdProduto = qtd;
        strcpy((*p) -> produto, pdto);
        (*p) -> prox = NULL;
        (*p) -> anter = NULL;

    } else {                            //quando ja houverem elementos na lista
        aux = *p;                       // copia a lista atual para não perder os dados

        (*p) -> prox = (struct notaFiscal *)malloc(sizeof(struct notaFiscal));        // alocando espaço na memoria

        if (*p == NULL){                                                    
            printf("\nErro de alocacao de memoria");
            exit(1);
        }

        *p = (*p) ->prox;
        (*p) -> prox = NULL;
        (*p) -> anter = aux;
        (*p) -> id = i;
        (*p) -> qtdProduto = qtd;
        strcpy((*p) -> produto, pdto);
    }


}

//função de remover elementos

void delete (struct notaFiscal **p){
    
    struct notaFiscal *anter;
    struct notaFiscal *prox;

    // salva os ponetiros

    anter = (*p) -> anter;
    anter = (*p) -> prox;
    free(p);
    *p = NULL;
    *p = anter;
    (*p) -> prox = prox;

    //contrla a remoção no final da lista

    if (prox != NULL){
        *p = (*p) -> prox;
        (*p) -> anter = anter;
    }


}

//verifica os elementos anteriores da lista

struct notaFiscal *anter(struct notaFiscal *p){
if (p->anter != NULL){
        return p->anter;
    }
    return NULL;
}

//retorna o fim da lista

struct notaFiscal *prox(struct notaFiscal *p){
    if (p->prox != NULL){
        return p->prox;
    }
    return NULL;
}

//consulta os elementos da lista

void info(struct notaFiscal *p){
    printf("\nID: %d\n",p->id);
    printf("\nQuantidade: %d\n",p->qtdProduto);
    printf("\nProduto: %s\n",p->produto);
}

//interface do sistema

void cantinaDaUfersa(){

    printf("------------------------------------\n");
    printf("-------- Cantina da UFERSA ---------\n");
    printf("------------------------------------\n");
    printf("------- SISTEMA DE COMPRAS ---------\n");
    printf("------------------------------------\n");
    printf("-- ID ----- PRODUTO ------ PRECO ---\n");
    printf("-- 1 -- Suco de Caju ---- R$ 1.50 --\n");
    printf("-- 2 -- Suco de Acerola - R$ 1.50 --\n");
    printf("-- 3 -- Coxinha --------- R$ 2.00 --\n");
    printf("-- 4 -- Pastel ---------- R$ 2.50 --\n");
    printf("-- 5 -- Bolo de Laranja - R$ 3.00 --\n");
    printf("-- 6 -- Bolo de Chocolate R$ 4.00 --\n");
    printf("------------------------------------\n");
    printf("----------- OPERACOES --------------\n");
    printf("------------------------------------\n");
    printf("-- 1. Selecionar Produto -----------\n");
    printf("-- 2. Cancelar Compra --------------\n");
    printf("-- 3. Listar Produtos --------------\n");
    printf("-- 4. Finalizar Compra -------------\n");
    printf("-- 5. Sair -------------------------\n");

}

int main(){

    int i;
    struct notaFiscal *p;    //lista vazia
    p = NULL;

    int op;         //identificador das operações
    int it = 0;     // contar a quantidade de produtos adicionados na lista
    int ident;      // identificador
    int qtdp;       // quantidade de produtos
    char pd[20];    //nome do produto

    do {
        cantinaDaUfersa();
        printf("\nQual operacao deseja realizar?\n");
        scanf("%d",&op);

        if (op == 1){

            system("cls");
            cantinaDaUfersa();
            printf("\nSelecione o produto que voce deseja comprar:\n");
            printf("\nDigite o ID do produto: \n");
            scanf("%d",&ident);
            printf("\nDigite a quantidade do produto: \n");
            scanf("%d",&qtdp);

            if (ident == 1){
                strcpy(pd,"Suco de Caju");
            } else if (ident == 2){
                strcpy(pd,"Suco de Acerola");
            } else if (ident == 3){
                strcpy(pd,"Coxinha");
            } else if (ident == 4){
                strcpy(pd,"Pastel");
            } else if (ident == 5){
                strcpy(pd,"Bolo de Laranja");
            } else if (ident == 6){
                strcpy(pd,"Bolo de Chocolate");
            } 

            adicionar(&p, ident, qtdp, pd);
            printf("\nProduto adcionado na lista.\n.\nPressione ENTER para voltar.\n");
            system("pause");
            system("cls");

            it++;

        } else if (op == 2) {
            if(it > 0){                         //se houverem produtos é posível cancelar
                
                for(i = 0; i < (it -1); i++){
                    p = anter(p);
                }

                for(i = 0; i < (it -1); i++){
                    p = prox(p);
                    delete(&p);
                }

                printf("\n--------------------------------------------\n");
                printf("\n--- Dados Removidos da Lista de Compras! ---\n");
                printf("----------------------------------------------\n");

                it = 0;             // não existem elementos na lista

                printf("\nObrigado e ate a proxima!\n");
                printf("\nPressione ENTER para voltar!\n");
                system("pause");
                system("cls");

            } else{
                system("cls");
                printf("\nSua lista de compras esta vazia :(\n");
            }
        } else if (op == 3) {
            
            if(it > 0){
                system("cls");
                printf("\n---------------------------\n");
                printf("\n------- Nota Fiscal -------\n");
                printf("\n---------------------------\n");

                for(i = 0; i < (it -1); i++){
                    p = anter(p);
                }

                info(p);
                printf("\n---------------------------\n");

                for(i = 0; i < (it -1); i++){
                    p = prox(p);
                    info(p);
                    printf("\n---------------------------\n");
                }

                printf("\nPressione ENTER para sair!\n");
                system("pause");
                system("cls");

            } else {
                system("cls");
                printf("\nSua lista de compras esta vazia :(\n");
            }


        } else if (op == 4) {

            float total = 0.0;       //calcula o valor total

            if (it > 0){
                
                system("cls");
                printf("\n---------------------------\n");
                printf("\n------- Nota Fiscal -------\n");
                printf("\n---------------------------\n");

                for(i = 0; i < (it -1); i++){
                    p = anter(p);
                }

                info(p);

                if (p->id == 1){
                    printf("Preco: R$ %.2f\n",1.5*(p->qtdProduto));
                    total += 1.5*(p->qtdProduto);
                } else if (p->id == 2){
                    printf("Preco: R$ %.2f\n",1.5*(p->qtdProduto));
                    total += 1.5*(p->qtdProduto);
                } else if (p->id == 3){
                    printf("Preco: R$ %.2f\n",2.0*(p->qtdProduto));
                    total += 2.0*(p->qtdProduto);
                } else if (p->id == 4){
                    printf("Preco: R$ %.2f\n",2.5*(p->qtdProduto));
                    total += 2.5*(p->qtdProduto);
                } else if (p->id == 5){
                    printf("Preco: R$ %.2f\n",3.0*(p->qtdProduto));
                    total += 3.0*(p->qtdProduto);
                } else if (p->id == 6){
                    printf("Preco: R$ %.2f\n",4.0*(p->qtdProduto));
                    total += 4.0*(p->qtdProduto);
                } 

                printf("\n---------------------------\n");

                for(i = 0; i < (it -1); i++){
                    p = prox(p);
                    info(p);

                if (p->id == 1){
                    printf("Preco: R$ %.2f\n",1.5*(p->qtdProduto));
                    total += 1.5*(p->qtdProduto);
                } else if (p->id == 2){
                    printf("Preco: R$ %.2f\n",1.5*(p->qtdProduto));
                    total += 1.5*(p->qtdProduto);
                } else if (p->id == 3){
                    printf("Preco: R$ %.2f\n",2.0*(p->qtdProduto));
                    total += 2.0*(p->qtdProduto);
                } else if (p->id == 4){
                    printf("Preco: R$ %.2f\n",2.5*(p->qtdProduto));
                    total += 2.5*(p->qtdProduto);
                } else if (p->id == 5){
                    printf("Preco: R$ %.2f\n",3.0*(p->qtdProduto));
                    total += 3.0*(p->qtdProduto);
                } else if (p->id == 6){
                    printf("Preco: R$ %.2f\n",4.0*(p->qtdProduto));
                    total += 4.0*(p->qtdProduto);
                } 

                printf("\n---------------------------\n");

                }

                printf("\nTotal: R$ %.2f\n",total);

                printf("\n---------------------------\n");

                op = 5;

                printf("\nPressione ENTER para voltar!\n");
                system("pause");                        
                system("cls"); 


            } else {
                system("cls");
                printf("\nSua lista de compras esta vazia :(\n");
            }

        } else if (op == 5) {
            printf("\nObrigado e volte sempre!\n");
            printf("\nPressione ENTER para sair!\n");
            system("pause");                        //Pausa a execução do programa
            system("cls");                          //Limpa os dados da tela
        } else {
            printf("\nOpção invalida. Tente novamente!\n");
            printf("\nPressione ENTER para voltar\n");
            system("pause");
        }

    } while (op != 5);
    

    return 0;
}