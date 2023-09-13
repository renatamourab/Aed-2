#include <stdio.h>
#include <stdlib.h>

int Busca(int*, int, int, int, int);

 int main(){
  int qnt, ini= 0;
  int *num;
  int busca;
  int cont, result;

  scanf("%d" ,&qnt);
  num = (int*) malloc(qnt * sizeof(int));
  for(cont=0; cont<qnt; cont++){
    scanf("%d" ,&num[cont]);
  }
  scanf("%d" ,&busca);

  result= Busca(num, busca, 0, qnt-1, 0);
  
 if(result!=-1){
   printf("%d", result);
 }else{
   printf("%d nao foi encontrado",busca);
 }
   return 0;
 }

int Busca(int *num, int busca, int ini, int fim, int cont1){
  int i = (ini + fim)/2;
  if(num[i] == busca){
    //printf("\nnúmero q ta parando: %i\n",num[i]);
    return (cont1);
  }
  if(ini>fim){
    return -1;
  }
  cont1++;
  if(num[i]< busca){
    //printf("\n num[i]:%i ,num[i]< busca:ini = %d,fim= %d \n",num[i],ini,fim);
   
    return Busca( num,  busca,  i+1, fim, cont1);
  } else{
    //printf("\n num[i]:%i, num[i]> busca:ini = %d,fim= %d \n",num[i],ini,fim);
   
    return Busca( num,  busca,  ini, i-1, cont1);
  }
}