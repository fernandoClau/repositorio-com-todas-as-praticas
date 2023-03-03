#include<stdio.h>
#include<stdlib.h>
/* nessa parte fasso a implementacao da estrutura struct e logo enseguida renomeio*/
typedef struct funcionario{
	char nome[50];
	float salario;
	int identificador; 
	char cargo[50];
}Funcionario;
/* aqui fasso uma fuçao para que o usuario possa preencher os campos de acordo com o que é pedido */
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
/* aqui fasso um outra funçao onde vai analisa cada salario informado e compara qual é o maior e menor salario*/
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
/*nesse trecho vai imprimir para usuario as informaçoes que ele digitou */
void imprima(Funcionario *campo, int n){
    int i;
    for (i = 0; i < n; i++) {
        printf("nome\t identificador\t salario\t cargo\n");
	printf("%s\t %d\t %f\t %s\n", campo[i].nome, campo[i].identificador, campo[i].salario, campo[i].cargo);
	}
}
/*nessa fuçao permite que o usuario possa altera seu salario se ele desejar */
void altera(Funcionario * campo){
 float novo_salario;
 printf("informe seu novo salario: ");
 scanf("%f", &novo_salario);
 campo->salario=novo_salario;
 }

/*na funcao principal fasso a chamada de todas as funçoes e pergunto ao usuario se ele deseja altera seu salario*/
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
