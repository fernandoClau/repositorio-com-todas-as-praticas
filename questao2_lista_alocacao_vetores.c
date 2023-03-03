#include<stdio.h>
#include<stdlib.h>

/*na funçao int main eu fasso uma alocaçao dinamica de um vetor de alunos e solicito a quantidade de questoes */
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
/*logo em segida eu fasso um vetor de respostas e fasso o analise se foi alocado com sucesso*/
char * resposta = (char*)malloc(n*sizeof(char));
if(resposta==NULL){
    printf("erro!");
    exit(1);
}
/*fasso tambem uma alocacao dinmica de gabarito e solicito o gabarito das questoes */
char * gabarito = (char*)malloc(n*sizeof(char));
if(gabarito==NULL){
    printf("erro!");
    exit(1);
} /*nessa parte eu fasso o processo de comparaçao onde ira ser analisado a resposta de cada aluno com o gabrito das questoes*/
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
      } /*nessa parte eu mostro o aluno e anota do aluno e fasso m calculo pra saber a porcentagem de alunos com nota acima de 6*/
      printf("aluno %d nota %.1f\t \n", i, aluno[i]);
      
    }
printf("a porcentagem de alunos com nota acima de 6: %f ", (p/100)*100);
/*aqui eu fasso a liberaçao de cada vetor */
free(resposta);
    free(gabarito);
    free(aluno);
    return 0;
}