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
      printf("%c",(op_t)arv->dado);
      arv_imprime_pre_ordem(arv->esq);
      arv_imprime_pre_ordem(arv->dir);
   }
}

arv_t* arv_cria_vazia(void){
   return NULL;
}
