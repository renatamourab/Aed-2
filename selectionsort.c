#include <stdio.h>
#include <stdlib.h>
 
void selection_sort(int, int*);
int Verificar (int*, int*, int);
 
int main(){
  int cont, qnt, *mic, *poten, result;
  //mic= microoganismos, poten=potencia, qnt= quantidade, result= resultado
 
  scanf("%d",&qnt);  
 
  mic = (int*) malloc(qnt * sizeof(int));
  //poten = (int*) malloc(qnt * sizeof(int));
 
  for(cont=0; cont<qnt; cont++){
    scanf("%d", &mic[cont]);
  }
  
  /*for(cont=0; cont<qnt; cont++){
    scanf("%d", &poten[cont]);
  }*/
  selection_sort(qnt, mic);
  for(cont=0; cont<qnt; cont++){
    printf("%d: %d\n", (cont+1),mic[cont]);
  }
  //selection_sort(qnt, poten);
  //result=Verificar(mic,poten,qnt);
  if(result==1){
    printf("sim");
  }else{ 
    printf("nao");
  }
  return 0;
}
 
void selection_sort(int qnt, int *vetor){
  int menor, cont, aux, i;
 
  for(cont=0; cont<(qnt-1); cont++){
    for(aux=(cont+1);aux<(qnt); aux++){
      if(vetor[cont]>vetor[aux]){
        menor= vetor[aux];
        vetor[aux]= vetor[cont];
        vetor[cont] = menor;
        /*for(i=0; i<qnt; i++){
          printf("%d: %d\n", i,vetor[i]);
        }
        printf("\n");*/
      }
    }
  }
 
  return;
}
 
int Verificar(int *mic, int *poten, int qnt){
  int cont, ver=0;
 
  for(cont=0; cont<qnt; cont++){
    if(poten[cont]<=mic[cont]){
      return 0;
    }
  }
  return 1;
}