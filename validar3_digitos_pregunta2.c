#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void validador(int numeroA);

void validador(int numeroA){
    int i,acumulador,c1,c2,aux,contador,cociente,resto,vector[200];
    c1=0;
    c2=0;
    contador=0;
    do{
        cociente=numeroA/10;
        resto=numeroA%10;
        
        if(resto==3){
            c1+=1;
        }
       
        if(resto==5){
            c2+=1;
        }
       
        aux=cociente;
        numeroA=cociente;
        vector[contador]=resto;
        contador+=1;

    }while(cociente!=0);
    
    acumulador=0;
    contador=contador-1;
    if(contador==2){
        for(i=0;i<=2;i++){
            aux=vector[i]*pow(10,contador);
            contador=contador-1;
            acumulador=acumulador+aux;
        }
        printf("el numero invertido es %d \n",acumulador);

    }
    
    printf("cantidad de numeros 3 ingresados %d \n",c1);
    printf("cantidad de numeros 5 ingresados %d \n",c2);


}


int main(){
   
    int numero;
    printf("igrese un numero\n");
    scanf("%d",&numero);
    validador(numero);




    return 0;
}