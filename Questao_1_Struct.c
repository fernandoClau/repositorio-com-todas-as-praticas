#include<stdio.h>
#include<stdlib.h>

typedef struct funcionario{
	char nome[50];
	float salario;
	int identificador; 
	char cargo[50];
}Funcionario;

void preenche(Funcionario *campo){
    int n;
    printf("Quantas funcionarios deseja cadastrar?\n ");
    scanf("%d", &n);
    
    int i;
    for (i = 0; i < n; i++) {
	scanf(" %[^\n]s", &campo[i].nome);
	printf("digite a o identificador: ");
	scanf("%d", &campo[i].identificador);
	printf("informe seu salario: ");
	scanf("%f", &campo[i].salario );
		printf("informe seu cargo: ");
	scanf(" %[^\n]s", &campo[i].cargo);
    float maiorsalario=0, menorsalario=0;
    char maiors, menors;

    if(campo->salario>maiorsalario){
        maiorsalario=campo->salario;
        maiors=campo->cargo;

    }else{
        menorsalario=campo->salario;
        menors=campo->cargo;
    }
}
}

void imprima(Funcionario *campo, float maiorsalario, float menorsalario, char maiors, char menors){
	printf("%s\t %d\t %f\t %s\n", campo->nome, campo->identificador, campo->salario, campo->cargo);
    printf("cargo  e salario da pessoa com maior salario: %f \t %s", maiorsalario, maiors);
    printf("cargo e salario da pessoa com menor salario: %f \t %s", menorsalario, menors);
	}
void altera(Funcionario * campo){
 float novo_salario;
 printf("informe seu novo salario: ");
 scanf("%f", &novo_salario);
 campo->salario=novo_salario;
 
}
void maiorsalario_(Funcionario *campo){
    float maior;
}	
int main(void){
int c;
   
  Funcionario pessoa;

    
	preenche(&pessoa);
    printf("deseja altera o salario 1 - sim 2 - nao");
    scanf("%d", &c);
    if(c==1){
        altera(&pessoa);
        imprima(&pessoa);
    }
	return 0;
}