#include<stdio.h>
#include<stdlib.h>

typedef struct funcionario{
	char nome[50];
	float salario;
	int identificador; 
	char cargo[50];
}Funcionario;

void preenche(Funcionario *campo, int n){
    int i;
    for (i = 0; i < n; i++) {
    printf("informe seu nome: ");
	scanf(" %[^\n]s", &campo[i].nome);
	printf("digite a o identificador: ");
	scanf("%d", &campo[i].identificador);
	printf("informe seu salario: ");
	scanf("%f", &campo[i].salario );
		printf("informe seu cargo: ");
	scanf(" %[^\n]s", &campo[i].cargo); 
}
}
  void maiormenorsalario(Funcionario *campo, int n){
    int i; 
    float maiorsalario=0, menorsalario=0, aux=0;
char maiors, menors;
    for (i=0; i<n; i++){
        if(campo[i].salario>maiorsalario){
            maiorsalario=campo[i].salario;
            maiors=campo[i].cargo;
        }else {
            aux=campo[i].salario;
        }if(campo[i].salario<aux){
            menorsalario=campo[i].salario;
            menors=campo[i].cargo;
        }
    }
    printf("o maior salario: %f\t cargo: %c\n", maiorsalario, maiors);
    printf("o menor salario: %f\t cargo: %c", menorsalario, menors);
  } 
void imprima(Funcionario *campo, int n){
    int i;
    for (i = 0; i < n; i++) {
        printf("nome\t identificador\t salario\t cargo\n");
	printf("%s\t %d\t %f\t %s\n", campo[i].nome, campo[i].identificador, campo[i].salario, campo[i].cargo);
	}
}
void altera(Funcionario * campo){
 float novo_salario;
 printf("informe seu novo salario: ");
 scanf("%f", &novo_salario);
 campo->salario=novo_salario;
 }
int main(void){
int c;
  Funcionario pessoa;
 int n;
    printf("Quantas funcionarios deseja cadastrar?\n ");
    scanf("%d", &n);
	preenche(&pessoa, n);
    printf("deseja altera o salario 1 - sim 2 - nao ");
    scanf("%d", &c);
    if(c==1){
        altera(&pessoa);
    }
    imprima(&pessoa, n); 
    maiormenorsalario(&pessoa, n);
	return 0;
}