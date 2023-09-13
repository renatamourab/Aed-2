#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

 struct ListaE{
  struct ListaE *prox;
  int item;
};

typedef struct ListaE TipoListaE;

typedef TipoListaE *TipoLista;

TipoLista Mergesort(TipoLista);
TipoLista Merge(TipoLista, TipoLista);
TipoLista Inicializa();
TipoLista Adiciona(TipoLista, TipoLista);
TipoLista Instacia(int);
TipoLista Inicializa();
TipoLista Insere(TipoLista, int);
TipoLista Acharmeio(TipoLista);
void Imprime(TipoLista);
TipoLista Merge_recursivo(TipoLista, TipoLista);


///////////////////////////////////////////////////////////////////

int Vazia(TipoLista lista){
  return lista==NULL;
}

TipoLista Inicializa(){
  return (NULL);
}

TipoLista Insere(TipoLista ponta,int dado){
  if(!Vazia(ponta)){
    ponta->prox= Insere( ponta->prox,  dado);
  }
  else{
    ponta = Instacia(dado);
  }
  return ponta;
}

TipoLista Instacia(int dado){
  TipoLista novoNo;
  novoNo= (TipoLista) malloc(sizeof(TipoListaE));
  novoNo->prox = NULL;
  novoNo->item = dado;
  
  return novoNo;
}

TipoLista Mergesort(TipoLista ponta){
  TipoLista a,b,cont,aux;
  
  if(ponta==NULL || ponta->prox==NULL){
    return ponta;
  }
  ////////
  cont = ponta;
  aux = cont->prox;

  while(aux!=NULL && aux-> prox!=NULL){
    cont= cont->prox;
    aux= aux->prox->prox;
  }
  ///////achar o meio cont=meio
  a= ponta;
  b=cont->prox; //vai ser outra ponta
  cont->prox = NULL;
  //a---meio---b
  //printf("\nmeio= %d,a = %d, b = %d\n",meio->item, a->item,b->item );
  a= Mergesort(a);
  b= Mergesort(b);
  //vai fazer uma lista com a e uma com b

  printf("\nenvio para o merge: a = %d, b = %d\n", a->item,b->item );
  //return Merge(a,b);
  return Merge_recursivo(a,b);
}
TipoLista Merge_recursivo(TipoLista a, TipoLista b){
  TipoLista listanova;

  if(a==NULL){
    printf("\n retorno para merge sort b= %d\n",b->item);
    return b; //se n tem nada no a, ou chegou no final
  }
  if(b==NULL){
    printf("\nretorno para merge sort a= %d\n",a->item);
    return a; //se n tem nada no b
  }
  
  if(a->item >= b->item){ 
    printf("\na=%d >= b=%d\n", a->item , b->item);
    listanova = b; //b menor então ele vai antes
    listanova->prox = Merge_recursivo(a, b->prox);
    //pula pro proximo b para comparar com o a
  }
  else{
    printf("\na=%d <= b=%d\n", a->item , b->item);
    listanova = a;
    listanova->prox = Merge_recursivo(a->prox,b);
  }
  return listanova;
}


TipoLista Merge(TipoLista a, TipoLista b){
  TipoLista listanova = Inicializa();
  //printf("entrou no merge\n");
  while(a!=NULL || b!=NULL){
   // printf("entrou no while\n");
    if(a->item < b->item){
      listanova= Insere(listanova, a->item);
      listanova= Insere(listanova, b->item);
      //printf("a=%d < b=%d\n", a->item , b->item);
      b = b->prox;
      a = a->prox;
      // printf("entrouu3\n");
    }
    else{
      listanova= Insere(listanova, b->item);
      listanova= Insere(listanova, a->item);
       //printf("a=%d > b=%d\n", a->item , b->item);
      a = a->prox;
      b = b->prox;
       //printf("entrouu4\n");
    }
    if( a == NULL && b!= NULL){
      listanova= Insere(listanova, b->item );
       //printf("a=NuLL, b=%dm\n", b->item);
      b = b->prox;
       //printf("entrouu5\n");
    }
    if(b == NULL && a!=NULL){
      listanova= Insere(listanova, a->item );
       //printf("a=%d , b=NULL\n", a->item);
      a = a->prox;
       //printf("entrouu6\n");
    }
  }
  return listanova;
}

TipoLista Acharmeio(TipoLista ponta){
  TipoLista cont,aux;
  cont = ponta;
  aux = cont->prox;

  while(aux!=NULL && aux-> prox!=NULL){
    cont= cont->prox;
    aux= aux->prox->prox;
  }
  return cont; //vai retornar o meio
}

void Imprime(TipoLista lista){
  if (!Vazia(lista)) {
    while (lista != NULL) {
      printf("%d ", lista->item);
      lista = lista->prox;
    }
  }
}

///////////////////////////////////////////////////////////////////
int main(){
  int cont, aux, qnt, *num;
  TipoLista ponta = Inicializa();
  
  scanf("%d", &qnt);
  num = (int*)malloc(qnt*sizeof(int));
  for(aux=0; aux<qnt; aux++){
    scanf("%i", &num[aux]);
    ponta = Insere(ponta, num[aux]);
  }
  ponta = Mergesort(ponta);
  cont = ceil(log2(qnt));
  printf("\n");
  Imprime(ponta);
  printf("\ncont =%d",cont);
  
  return 0;
}