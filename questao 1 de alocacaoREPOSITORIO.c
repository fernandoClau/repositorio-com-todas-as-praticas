#include<stdio.h>
#include<stdlib.h>


int main(){
int n, i;
int pocen;
float pocensim, pocensim_m; 

printf("informe a quantidade de pessoas para responder o questionario: ");
scanf("%d", &n);
 char *vetor = (char*)malloc(n*sizeof(char)); 
for (i=0; i< n; i++){
printf("informe o seu sexo M/F");
scanf(" %c", &vetor[i]);
switch(vetor[i]){
   case 'f':
printf(" Voce gostou do produto 1-sim ou 2-nao: ");
scanf(" %d", &pocen);
if(pocen == 1){
pocensim++;
}
break;
case  'm':
printf(" Voce gostou do produto sim ou nao: ");
scanf("%d", &pocen);
if(pocen == 1){
pocensim_m++;
}
break;
}

}
 printf("porcentage de mulher que digitou sim:  \t %f.\n", pocensim/100);
 printf("porcentage de homem que digitou sim:  \t %f.", pocensim_m/100);

    return 0;
}

