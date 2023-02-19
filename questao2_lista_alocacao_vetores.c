#include<stdio.h>
#include<stdlib.h>


int main(){
int  i, n;
float p; 
float *aluno=(float*)malloc(10*sizeof(float));
if(aluno==NULL){
    printf("erro!");
    exit(1);
}

printf("informe a quantidade de questoes: ");
scanf("%d", &n);

char * resposta = (char*)malloc(n*sizeof(char));
if(resposta==NULL){
    printf("erro!");
    exit(1);
}
char * gabarito = (char*)malloc(n*sizeof(char));
if(gabarito==NULL){
    printf("erro!");
    exit(1);
}
for(i=0;i<n; i++){
    printf("informe o gabarito da questoes %d: ", i);
scanf(" %[^\n]s", &gabarito[i]);
}
int index;
for(i=0;i<10;i++){
for(index=0; index < n; index++){
    printf("resposta da questao %d do aluno %d: ", index, i);
scanf(" %[^\n]s", &resposta[index]);
    if(resposta[index]==gabarito[index]){
        aluno[i] = aluno[i]+ (10/n);
        if(aluno[i]>6){
            p++;
        }
    } 
      }
      printf("aluno %d nota %.1f\t \n", i, aluno[i]);
      
    }
printf("a porcentagem de alunos com nota acima de 6: %f ", (p/100)*100);
free(resposta);
    free(gabarito);
    free(aluno);
    return 0;
}