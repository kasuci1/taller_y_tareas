#include<stdio.h>
#include<stdlib.h>
#include<math.h>
  void factura_in_range(int *aprobado, float *factura);
  int pide_articulos();
  int pide_datos();

  int pide_datos(){
    int par_impar,cedula;
    printf("ingrese el numero de la ci del cliente\n");
    scanf("%d",&cedula);
    par_impar=cedula%10;
    par_impar=par_impar%2;
    return par_impar;

  }
 
  void factura_in_range(int *aprobado, float *factura){
    float total_factura;
    printf("ingrese la factura del cleinte\n");
    scanf("%f",&total_factura);
      
    if((total_factura>=1000.0)&&(total_factura<=5000.0)){
      *aprobado=1;
    }
    else{
      *aprobado=0;
    }
    *factura=total_factura;
  }


  int pide_articulos(){
    int label,contador,i,cant_articulos;
    contador=0;
   
    printf("ingrese la cantidad de articulos\n");
    scanf("%d",&cant_articulos);
      
    for(i=1;i<=cant_articulos;i++){
      printf("ingrese la etiqueta del articulo nro %d\n",i);
      printf("M=1, A=0, generic label=2\n");
      scanf("%d",&label);
        
      if(label==1||label==0){
        contador=contador+1;
      }
    }
    return contador;

  }
  
  

int main (){
  int par_impar,aprobado,cant_articulos,bandera,gana_3,gana_5,gif_win;
  int numero_cliente,porcentaje_ganadores,aux;
  bandera=1;
  numero_cliente=0;
  float monto_factura;
  gana_3=0;
  gana_5=0;
  aux=0;
    printf("iniciar concurso de toyLandiaC,A\n");
    while(bandera==1){
      numero_cliente=numero_cliente+1;
      par_impar=pide_datos();
      factura_in_range(&aprobado,&monto_factura);
      cant_articulos=pide_articulos();
      if(aprobado==1){
        if(cant_articulos>=3){
          if(par_impar==1){
            gana_3=gana_3+1;
          }
          else{
            gana_5=1;
          }
        }
      }
      if(monto_factura>aux){
        gif_win=numero_cliente;

      }
      aux=monto_factura;
      
      printf("desea ingresar otro cliente \n");
      printf("SI=1 ; NO =0");
      scanf("%d",&bandera);
    }
   
    porcentaje_ganadores=((gana_3+gana_5)*100)/numero_cliente;
    printf("porcentaje de ganadores %d , ganadores del 5 porciento %d ganadores del 3 porciento %d",porcentaje_ganadores,gana_5,gana_3);
    printf("\n");
    printf("el numero del cliente ganador de la gift es %d",gif_win);
  return 0;

}