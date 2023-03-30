#include <stdlib.h>
#include "lista.h"

void inicializa_lista(Lista * ap_lista)
{
    No *nocabeca = (No*)malloc(sizeof(No));

    *ap_lista = nocabeca;

    nocabeca->prox = nocabeca;
    nocabeca->antec = nocabeca;

}

void insere_fim(Lista ap_lista, TipoDado valor)
{
  No *novo = (No*)malloc(sizeof(No));

  
  novo->prox = ap_lista;
  novo->antec = ap_lista->antec;
  ap_lista->antec->prox = novo;
  ap_lista->antec = novo;
  novo->valor = valor;

}

void insere_inicio(Lista ap_lista, TipoDado valor)
{
  No* novo = (No*)malloc(sizeof(No));

  novo->prox = ap_lista->prox;
  novo->antec = ap_lista;
  novo->valor = valor;
  ap_lista->prox->antec = novo;
  ap_lista->prox=novo;

}

TipoDado remove_fim(Lista ap_lista)
{
    No *ap_atual = ap_lista->antec;
    TipoDado valor;
    
    if(ap_lista->prox != ap_lista)
    {
    valor = ap_atual->valor;
    ap_atual->antec->prox = ap_lista;
    ap_lista->antec = ap_atual->antec;

    free(ap_atual);
    }


    return valor;

}

TipoDado remove_inicio(Lista ap_lista)
{
  No *ap_atual = ap_lista->prox;
  TipoDado valor;

  ap_atual->prox->antec = ap_lista;
  ap_atual->antec->prox = ap_atual->prox;
  valor = ap_atual->valor;

  free(ap_atual);

  return valor;

}

int remove_ocorrencias(Lista ap_lista, TipoDado valor)
{
    No *ap_atual = ap_lista->prox;
    No *remove_ocorrencia;
    int contador = 0;
    
    if(ap_atual == ap_lista)
      return contador;

  while(ap_atual->prox != ap_lista->prox){
    if(ap_atual->valor.grau==valor.grau && ap_atual->valor.coef == valor.coef)
    {
      ap_atual->prox->antec = ap_atual->antec;
      ap_atual->antec->prox = ap_atual-> prox; 

      remove_ocorrencia = ap_atual->prox;
      free(ap_atual);

      ap_atual = remove_ocorrencia;
      contador++;

      continue;
    } 
  }
    ap_atual= ap_atual->prox;

  return contador;

}

int busca(Lista lista, TipoDado valor)
{}


int coeficiente_do_grau(Lista lista, int grau){}


void desaloca_lista(Lista *ap_lista){}



void imprime(Lista lista)
{
  No *ap_atual=lista->prox;

  printf("[");
  
  while(ap_atual != lista )
  {
    printf("(%d,%d)",ap_atual->valor.grau, ap_atual->valor.coef);
    if(ap_atual->prox != lista)
    printf(",");
    ap_atual=ap_atual->prox;

  }
  
  printf("]\n");

}