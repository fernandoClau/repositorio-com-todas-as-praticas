#include<stdio.h>
#include<stdlib.h>

/*Primeiro fiz uma struct e a nomeei como aluno, dentro dela declarei 4 variáveis
mat para matricula, nome para o nome do aluno, notas para as notas do aluno, media para a soma das notas e a divisão delas pela quantidade
de notas*/
typedef struct aluno
{
    int mat;
    char nome[81];
    float notas[3];
    float media;
}Aluno;
/*Fiz uma struct e a nomeei como turma e coloquei 3 variáveis. ID para armazenar o id de uma turma, vagas para determinar quantas vagas 
numa turma há, e aluno essa variável serve para acessar a struct aluno.*/
typedef struct turma
{
    char id;
    int vagas;
    Aluno aluno[3];
}Turma;

/*Nesta função, vou acessar a struct turma para armazenar o id da turma, isso vai fazer com que se crie as turmas*/
void criar_turmas(Turma *turmas, int i){
    printf("Criando Turma...\n");
    printf("Digite o ID da turma: ");
    scanf(" %c", &turmas[i].id);
    printf("Turma Criada\n");
}
/*Nesta função vou acessar a struct turma e vou listar cada turma mostrando o id e quantas vagas há nelas*/
void listar_turmas(Turma *turmas, int i){
    int j;
    for (j = 0; j < i; j++)
    {
        printf("Turma: %c vagas: %d\n", turmas[j].id, 3-turmas[j].vagas);
    }
}
/*Nesta função peço os dados do aluno, pergunto primeiro o id da turma que ele quer se matricular
depois o "for" vai passar por cada vetor de turma e o if compara se naquele vetor tem o id da turma que o aluno deu
se não houver a turma o "else if" é acionado e mostra a mensagem "Turma não existe" 
O aluno vai digitar o nome e sua matricula*/
void dados_aluno(Turma *alunos, int a){
    int j, i=0, f=0;
    char turma;
    printf("Digite o ID da turma: \n");
    scanf("%s", &turma);
    for (j = 0; j < a; j++)
    {
        if (turma==alunos[j].id)
        {
            f=alunos[j].vagas;
            for ( i = f; i <= f; i++)
            {
                if(alunos[j].vagas<3)
                {
                    printf("Digite o nome do aluno: ");
                    scanf(" %s",(char *) &alunos[j].aluno[i].nome);
                    printf("Digite a matricula: ");
                    scanf("%d", &alunos[j].aluno[i].mat);                   
                    alunos[j].vagas++;
                }else
                {
                    printf("Nao ha mais vagas!\n");
                }
            } 
        }  
    }
    if (turma!=alunos[0].id && turma!=alunos[1].id && turma!=alunos[2].id)
        {
            printf("Turma nao existe!\n");
        }
}
/*Esta função zera as vagas*/
void vagas(Turma *vagas){
    int j;
    for (j = 0; j < 3; j++)
    {
        vagas[j].vagas = 0;
    }
}
/*Esta função zera a media e todas a notas*/
void media(Turma *media){
    int j, i, k;
    for (j = 0; j < 3; j++)
    {
        for (i = 0; i < 3; i++)
        {
            media[j].aluno[i].media = 0;
            for (k = 0; k < 3; k++)
            {
                media[j].aluno[i].notas[k] = 0;
            }
        }
    } 
}
/*Esta função vai pedir para informar as notas dos alunos, primeiro vai pedir o id e o "for" vai passar por cada vetor identificando os IDs
das turmas, o "if" vai identificar as turmas, após identificar vai pedir as notas dos alunos de uma determinada turma
na função a media vai receber a soma das notas de cada aluno*/
void notas(Turma *nota, int a){
    int i, j, f = 0, k;
    char turma;
    printf("Qual o ID da turma: ");
    scanf("%s", &turma);
    for (i = 0; i < a; i++)
    {
        if (turma==nota[i].id)
        {
            f = nota[i].vagas;
            for (k = 0; k < f; k++)
            {
                printf("Informe as notas do aluno: %s\n", (char *) nota[i].aluno[k].nome);
                for (j = 0; j < 3 ; j++)
                {   
                    printf("Informe a nota: ");
                    scanf("%f", &nota[i].aluno[k].notas[j]);
                    nota[i].aluno[k].media = nota[i].aluno[k].media + nota[i].aluno[k].notas[j];       
                }   
            }
        }
    }  
}
 /*Nesta função vai mostrar as informações de cada aluno numa determinada turma, vai pedir o id da turma e comparar com cada vetor que acessa
 o ID*/
void imprimir_aluno(Turma *nota, int a){
    int i, f = 0, k;
    char turma;
    printf("Qual o ID da turma: ");
    scanf("%s", &turma);
    for (i = 0; i < a; i++)
    {
        if (turma==nota[i].id)
        {
            f = nota[i].vagas;
            for (k = 0; k < f; k++)
            {
                printf("aluno: %s\n", (char *) nota[i].aluno[k].nome);
                printf("Nota: %.2f\n", nota[i].aluno[k].media / 3);
                printf("Matricula: %d\n", nota[i].aluno[k].mat);     
            }
        }
    }  
}
int main(){
/*declarei dinâmicamente o ponteiro classe do Turma*/
    int t, i=0, a=0;
    Turma *classe = (Turma *)calloc(3, sizeof(Turma));
    if (classe==NULL)
    {
        printf("ERRO!\n");
        exit(1);
    }
    /*Funçao vagas que vai zerar as vagas acessando a struct turma com o ponteiro classe*/
    vagas(classe);
    /*Função media que vai zerar as notas e media, acessando cada uma das struct com o ponteiro classe*/
    media(classe);

    printf("Bem-vindo ao Programa de Gerenciamento de Turmas!\nEste programa gerencia as turmas ofertadas, fornecendo as funcionalidades de matricula, lancamento de notas e listagem de alunos.\n");
    /*A função "do while vai servir para acessar o menu e cada numero do menu vai acessar as funçoes
    o programa termina quando t for igual a 6"*/
    do{
        printf("Menu:\n1 - Criar turmas\n2 - Listar turmas\n3 - Matricular aluno\n4 - Lancar notas\n5 - Listar alunos\n6 - Sair\n");
        scanf("%d", &t);
        if (t==1)
        {
           criar_turmas(classe, i); 
           i ++;
        }else if(t==2){
            listar_turmas(classe, i);
            a++;
        }else if (t==3)
        {
            dados_aluno(classe, i);
        }else if (t==4)
        {
            notas(classe, i);
        }else if (t==5)
        {
            imprimir_aluno(classe, i);      
        }else if (t==6)
        {
            printf("Obrigado por usar este programa!");
        }
    } while (t!=6);
    /*A função free vai liberar a memória alocada dinamicamente*/
    free(classe);
    return 0;
}