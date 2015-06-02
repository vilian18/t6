#include "arv.h"
#include "memo.h"
#include <stdlib.h>
#include <stdio.h>


arv_t* arv_cria(op_t op){
   arv_t* arv= (arv_t*)memo_aloca(sizeof(arv_t));
   arv->dado= op;
   return arv;
}

arv_t* arv_insere_esquerda(arv_t* arv, op_t op){
   arv_t* arv_esq= (arv_t*)memo_aloca(sizeof(arv_t));
   arv_esq->dado= op;
   arv->esq= arv_esq;
   return arv;
}

arv_t* arv_insere_direita(arv_t* arv, op_t op){
   arv_t* arv_dir=(arv_t*)memo_aloca(sizeof(arv_t));
   arv_dir->dado= op;
   arv->dir= arv_dir;
   return arv;
}

void arv_imprime_pre_ordem(arv_t* arv){
   if(arv!=NULL){
      if(arv->dado.tipo==OPERANDO)
         printf(" %g ",arv->dado.u.operando);
      else
         printf(" %c ", arv->dado.u.operador);
      arv_imprime_pre_ordem(arv->esq);
      arv_imprime_pre_ordem(arv->dir);
   }
}

void arv_imprime_em_ordem(arv_t* arv){
   if(arv!=NULL){
      arv_imprime_em_ordem(arv->esq);
      if(arv->dado.tipo==OPERANDO)
         printf(" %g ",arv->dado.u.operando);
      else
         printf(" %c ", arv->dado.u.operador);
      arv_imprime_em_ordem(arv->dir);
   }
}

void arv_imprime_pos_ordem(arv_t* arv){
   if(arv!=NULL){
      arv_imprime_pos_ordem(arv->esq);
      arv_imprime_pos_ordem(arv->dir);
      if(arv->dado.tipo==OPERANDO)
         printf(" %g ",arv->dado.u.operando);
      else
         printf(" %c ", arv->dado.u.operador);

   }
}


arv_t* arv_cria_vazia(void){
   return NULL;
}

void arv_destroi(arv_t* arv){
   free(arv);
}
