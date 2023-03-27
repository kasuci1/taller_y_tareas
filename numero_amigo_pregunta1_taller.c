#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void verificador(int numA,  int numB);

void verificador(int numA, int numB){
    int i,sumador1,sumador2;
    sumador1=0;
    sumador2=0;
    for(i=1;i<numA;i++){
        if(numA%i==0){
           sumador1=sumador1+i;
        }
        
    }

    for(i=1;i<numB;i++){
        if(numB%i==0){
            sumador2=sumador2+i;
        }
    }
    if((sumador1==numB)&&(sumador2==numA)){
        printf("son amigos\n");

    }
    else{
        printf("no son amigos\n");
    }


} 

int main(){
    int n1,n2;
    printf("ingrese dos numeros \n");
    printf("ingrese el primer numero\n");
    scanf("%d",&n1);
    printf("ingrese el segundo numero\n");
    scanf("%d",&n2);
    verificador(n1,n2);



    return 0;

}