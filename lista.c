#include <stdlib.h>
#include "lista.h"

void inicializa_lista(Lista *ap_lista)
{
  No *noCabeca = (No *)malloc(sizeof(No));

  *ap_lista = noCabeca;

  noCabeca->prox = noCabeca;

  noCabeca->antec = noCabeca;
}

void insere_inicio(Lista ap_lista, TipoDado valor)
{
  No *novo = (No *)malloc(sizeof(No));

  novo->valor = valor;
  novo->prox = ap_lista->prox;
  novo->antec = ap_lista;
  ap_lista->prox->antec = novo;
  ap_lista->prox = novo;
}

void insere_fim(Lista ap_lista, TipoDado valor)
{
  No *novo = (No *)malloc(sizeof(No));

  novo->prox = ap_lista;
  novo->antec = ap_lista->antec;
  ap_lista->antec->prox = novo;
  ap_lista->antec = novo;
  novo->valor = valor;
}

void imprime(Lista lista)
{
  No *ap_atual;

  ap_atual = lista->prox;

  printf("[");
  while (ap_atual != lista)
  {
    printf("(%d,%d)", ap_atual->valor.grau, ap_atual->valor.coef);
    if (ap_atual->prox != lista)
    {
      printf(",");
    }
    ap_atual = ap_atual->prox;
  }
  printf("]\n");
}
TipoDado remove_fim(Lista ap_lista)
{
  No *aux;
  aux = ap_lista->antec;
  TipoDado valor;

  if (ap_lista->prox != ap_lista)
  {

    aux->antec->prox = ap_lista;
    ap_lista->antec = aux->antec;
    valor = aux->valor;

    free(aux);

    return valor;
  }

  return ap_lista->valor;
}

TipoDado remove_inicio(Lista ap_lista)
{
  No *aux;
  aux = ap_lista->prox;
  TipoDado valor;

  if (ap_lista->prox != ap_lista)
  {

    aux->prox->antec = ap_lista;
    aux->antec->prox = aux->prox;
    valor = aux->valor;

    free(aux);
  }

  return valor;
}

int remove_ocorrencias(Lista ap_lista, TipoDado valor)
{
  No *aux;
  No *remove;

  aux = ap_lista->prox;
  int contador = 0;

  if (ap_lista->prox == ap_lista)
  {
    return contador;
  }
  else
  {
    while (aux->prox != ap_lista->prox)
    {
      if (aux->valor.coef == valor.coef && aux->valor.grau == valor.grau)
      {
        aux->prox->antec = aux->antec;
        aux->antec->prox = aux->prox;

        remove = aux->prox;

        free(aux);

        aux = remove;

        contador++;

        continue;
      }
      aux = aux->prox;
    }
  }

  return contador;
}
int busca(Lista lista, TipoDado valor)
{
  int contador = 0;

  No *aux = lista->prox;

  while (aux != lista)
  {

    if (aux->valor.coef == valor.coef && aux->valor.grau == valor.grau)
    {
      return contador;
    }

    aux = aux->prox;
    contador++;
  }

  return -1;
}

int coeficiente_do_grau(Lista lista, int grau)
{
  No *aux = lista->prox;

  while (aux != lista)
  {
    if (aux->valor.grau == grau)
    {
      return aux->valor.coef;
    }
    aux = aux->prox;
  }

  return 0;
}

void desaloca_lista(Lista *ap_lista)
{
  No *aux = (*ap_lista)->antec;

  while (aux != *ap_lista)
  {
    (*ap_lista)->antec = (*ap_lista)->antec->antec;

    free(aux);

    aux = (*ap_lista)->antec;
  }

  free(*ap_lista);
}
