#include <stdio.h>
#include <stdlib.h>


void vaciar(char temp[]){
    int i;

    for(i=0;i<100;i++){
        temp[i]='\0';
    }

}


int main() {
    FILE  *archivo;
    char line[100],temp[100],letra;
    int flag=1,cantidad,i,j,caso,aux=0,aux1=0,aux2=0;
    float mat[10][3],categoria1=1,categoria2=1,categoria3=1;
    archivo=fopen("ventas.txt","r");
    i=0;
    while(!feof(archivo)){
        fscanf(archivo,"%f,%f,%f",&mat[i][0],&mat[i][1],&mat[i][2]);
        i++;

    }
    fclose(archivo);
    archivo=fopen("ventas_totales.txt","w");
    for(i=0;i<9;i++){
        for(j=0;j<3;j++){
            printf("%.2f\t",mat[i][j]);
        }
        printf("\n");
    }



    for(i=0;i<9;i++){
            caso=mat[i][0];
            switch(caso){
                case 1:
                    categoria1=mat[i][1]*mat[i][2];
                    categoria1=categoria1+aux;
                    aux=categoria1;
                    break;
                case 2:
                    categoria2=mat[i][1]*mat[i][2];
                    categoria2=categoria2+aux1;
                    aux1=categoria2;
                    break;
                case 3:
                    categoria3=mat[i][1]*mat[i][2];
                    categoria3=categoria3+aux2;
                    aux2=categoria3;
                    break;
            }
        
    }



    printf("categoria1: %.2f categoria2: %.2f categoria3: %.2f\n",categoria1,categoria2,categoria3);
    fputs("ventas totales por categoria",archivo);
    fputs("\n",archivo);
    fputs("categoria 1",archivo);
    fputs(" ",archivo);
    sprintf(temp,"%.2f",categoria1);
    fputs(temp,archivo);
    fputs("\n",archivo);
    //////////////////////////////
    fputs("categoria 2",archivo);
    fputs(" ",archivo);
    sprintf(temp,"%.2f",categoria2);
    fputs(temp,archivo);
    fputs("\n",archivo);
    ////////////////////////////
    fputs("categoria 3",archivo);
    fputs(" ",archivo);
    sprintf(temp,"%.2f",categoria3);
    fputs(temp,archivo);
    fputs("\n",archivo);

    return 0;
}