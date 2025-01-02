#include <stdio.h>
#include <stdlib.h>

struct lista {
    int num;
    int marcado;
    struct lista* next;
};

int addNode(struct lista** l, int newnode){
    struct lista* novo = (struct lista*)malloc(sizeof(struct lista));
    novo->num = newnode;
    novo->marcado = 0;
    novo->next = NULL;

    if(*l == NULL){
        *l = novo;
        return 1;
    }
    struct lista* atual = *l;
    while(atual->next != NULL){
        atual = atual->next;
    }
    atual->next = novo;
    return 1;
}

int marcarNode(struct lista** l, int x){
    int pos = 1;
    struct lista* atual = *l;

    while((atual != NULL && atual->num != x) || atual->marcado == 1){
        atual = atual->next;
        pos++;
    }
    if(atual != NULL){
        atual->marcado = 1;
    }
    //imprimir(*l);
    return pos;
}

void imprimir(struct lista* l){
    struct lista* atual = l;
    printf("\n");
    while(atual != NULL){
        printf("%d[%d] ", atual->num, atual->marcado);
        atual = atual->next;
    }
    printf("\n");
}

int maxTeams(int a, int b, int c){
    if(a<=b && a<=c){
        return a;
    } else {
        if(b<=a && b<=c){
            return b;
        } else {
            if(c<=a && c<=b){
                return c;
            }
        }
    }
}

int main(){
    int n;
    int i;

    scanf("%d", &n);
    struct lista* l = NULL;
    int valor;

    int programingChildren = 0;
    int mathChildren = 0;
    int phChildren = 0;

    for(i=0; i<n; i++){
        scanf("%d", &valor);
        if(valor == 1){
            programingChildren++;
        }
        if(valor == 2){
            mathChildren++;
        }
        if(valor == 3){
            phChildren++;
        }
        addNode(&l,valor);
    }
    int maxteams = maxTeams(programingChildren, mathChildren, phChildren);
    //imprimir(l);
    printf("%d\n", maxteams);
    for(i=0; i<maxteams; i++){
        printf("%d ", marcarNode(&l, 1));
        printf("%d ", marcarNode(&l, 2));
        printf("%d\n", marcarNode(&l, 3));
    }
    return(0);
}
