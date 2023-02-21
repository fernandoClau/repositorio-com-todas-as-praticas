#include <stdio.h>
#include <stdlib.h>

typedef union indice {
  float ira;
  float ig;
  float irt;
  }Indice;
   typedef enum bool{
ativo,
inativo, 
trancado, 
 }Bool;

 typedef struct aluno{
 char nome[30];
   int  matricula;
   char curso[30];
   Indice rend;
  Bool var;
 }Aluno;
  
  int main(void){
  Aluno pessoa;
  Indice rend;
  Bool var;
   int op;
      printf("informe seu nome: ");
      scanf(" %[^\n]s", pessoa.nome);
      printf("informe sua matricula: ");
      scanf("%d", &pessoa.matricula);
      printf("informe seu curso: ");
      scanf(" %[\n]s", pessoa.curso);
        printf("qual opcao de indce academico dejesa informar?\n IRA, IG, IRT:  ");
        scanf("%d", &op);
            switch (op)
            {
            case 1:
                  printf("informe seu rendimento IRA: ");
                    scanf("%f", &pessoa.rend.ira);
              break;
             case 2:
             printf("infor seu IG: ");
                scanf("%f", &pessoa.rend.ig);
              break;
              case 3:
               printf("informe seu seu IRT");
                  scanf("%f", &pessoa.rend.irt);
            }
 printf(" informe  1 - ativo \n 2 - inativo \n 3 - trancado ");
 scanf("%d", &pessoa.var);
 if(var == 0){
  printf(" nome: %s\n matricula: %d\n curso:\n IRA: %f\n IG: %f\n IRT: %f.  \n", pessoa.nome, pessoa.matricula, pessoa.curso, pessoa.rend.ira, pessoa.var);
    printf("alundo ativo");
 }
 if(var == 1){
  
  printf("nome: %s\n documento: %f\n situacao: %d\n ", pessoa.nome, pessoa.rend.ira, pessoa.var);
    printf("aluno inativo");
 }

 else{
  
  printf("nome: %s\n documento: %f\n situacao: %d \n", pessoa.nome, pessoa.rend.ira, pessoa.var);
    printf("aluno trancado");
 }
    return 0;
}