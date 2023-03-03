#include<stdio.h>
#include<stdlib.h>

/*nessa parte crio um tipo estruturado com o comando struct para pessoa*/
typedef struct pessoa{
  char nome [50];
  int idade;
  int documento;

}Pessoa;
/*fiz uma funçao para preencher os campos da struct pessoa*/
void preencher(Pessoa *vetor){
    printf("informe o seu nome\n");
    scanf(" %[^\n]s", &vetor->nome);
    printf("informe sua idade \n");
    scanf("%d", &vetor->idade);
    printf("informe o numero do seu documento: ");
    scanf("%d", &vetor->documento);
   
}
/*fiz uma outra funçao para imprimir o que esta armazendo nos campos da struct pessoa fornecido pelo usuario */
void imprimir (Pessoa *vetor){
printf(" nome: %s \n Idade: %d\n documento: %d\n" , vetor->nome, vetor->idade, vetor->documento); 
}
/*no int main fasso a chamada de todas as funçoes e tambem fasso uma alocaçao dinamica de vetor do tipo pessoa */
int main(){
    int n;
    printf("informe quantas pessoas deseja cadastra: ");
scanf("%d", &n);
    Pessoa *vetor = (Pessoa*) malloc(n* sizeof(Pessoa));
    if(vetor == NULL){
    printf("erro");
    exit(1);
    }
    int i;
     for(i=0; i < n ; i++){
    preencher(&vetor[i]);
     }
      int a,maior=0,menor=0;  
int b;
    for (b=0; b < n ; b++){
   if(vetor[b].idade > maior){
        maior = vetor[b].idade;
   }else{
        menor= vetor[b].idade;
    }
    if(vetor[b].idade < menor){
    menor= vetor[b].idade;
        } 
    }
    for(a = 0; a< n; a++){
    imprimir(&vetor[a]);   
}
         printf("maior: %d\n menor: %d", maior, menor);
free(vetor);
    return 0;
}