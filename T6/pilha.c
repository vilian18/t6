#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define TAM_PILHA 30

pilha_t* pilha_cria(void){
   pilha_t* p= (pilha_t*)memo_aloca(sizeof(pilha_t));
   p->arv= (arv_t*)memo_aloca(TAM_PILHA*sizeof(arv_t));
   p->N=0;
   return p;
}

void pilha_destroi(pilha_t* p){
   memo_libera(p);
}

bool pilha_vazia(pilha_t* p){
   if(p->N==0)
      return true;
   return false;
}

void pilha_insere(pilha_t* p, arv_t* arv){
   p->arv[p->N]= arv;
   p->N++;
}

arv_t* pilha_remove(pilha_t p){
   if(!pilha_vazia(p)){
      arv_t* arv_= (arv_t*)memo_aloca(sizeof(arv_t));
      arv_= p->arv[p->N-1];
      p->N--;
      return arv_;
   }
}

bool pilha_valida(pilha_t p){
   return (p!=NULL);
}



