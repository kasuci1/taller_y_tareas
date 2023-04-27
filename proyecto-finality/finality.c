#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void modulo_consultar();
void vaciar(char temp[]);
void copiar(char temp[],int i , int estado);
void file_upload();
void menu();
void modulo_ingresar();


typedef struct{
    
    int  cedula;
    char *nombre;
    char *departamento;
    char *cargo;
    char *fecha;
    int sueldo;
    

}trabajadores;

trabajadores *trab;
//esta es la funcion que hay q consultar dirigirse a la linea 93
//los proc pueden trabajar por separados pero dependen del carga de datos en el struct !!precaucion no fastidiar al archivo trabajadores.txt !!
//cualquier nombre q aparezca en el archivo q suene conocido en la realidad es pura coincidencia todo es ficcion xDDD!!!!
void modulo_consultar(){
    int i=0,j,valor,bandera=1,cont=0,aux=0;
    FILE *archivo;
    FILE *deparchivo;
    FILE *cargochivo;
    char temp[100],tempaux[100],auxc;

    deparchivo=fopen("departamento.txt","r+");
    if(deparchivo==NULL){
        printf("cant open file deparchivo\n");
        exit(1);
    }
    cargochivo=fopen("cargo.txt","r+");
    if(cargochivo==NULL){
        printf("cant open file cargo chivo\n");
        exit(1);
    }

    archivo=fopen("trabajadores.txt","r");
    if(archivo==NULL){
        printf("cant open file\n");
        exit(1);
    }
    while(!feof(archivo)){
        fgets(temp,100,archivo);
        cont++;
    }
    vaciar(temp);//siempre limpio las cadenas para asegurar q no vengan con basura del buffer
    vaciar(tempaux);
    printf("que tipo de consulta desea realizar\n");
    printf("1.-por cedula / 2.-por departamento / 3.-por cargo\n");
    scanf("%d",&valor);
    switch(valor){    
        case 1:
            printf("ingrese el numero de cedula a consultar\n");
            scanf("%d",&valor);
            printf("\n");
            while(bandera==1){
                if(valor==trab[i].cedula){
                    printf("CEDULA: %i NOMBRE: %s DEPARTAMENTO: %s CARGO: %s FECHA: %s SUELDO:%i\n",trab[i].cedula,trab[i].nombre,trab[i].departamento,trab[i].cargo,trab[i].fecha,trab[i].sueldo);
                    bandera=0;
                }
                else{
                    i++;
                    if(i==cont){
                        printf("la CI indicada no esta asociada a ningun trabajador de la empresa\n");
                        bandera=0;
                    }
                }
            }
            fclose(archivo);
            fclose(deparchivo);
            fclose(cargochivo);
            break;
        case 2:
            printf("ingrese el numero de departamento a consultar\n");
            printf("1:RRHH / 2:consultoria / 3:diseño / 4:produccion / 5:desarrollador / 6:auditor");
            scanf("%d",&valor);
            switch(valor){
                case 1:
                       valor=strlen(trab[3].departamento); //para hacer la prueba estoy seguro q aca se guarda RRHH se lo paso a un string distinto se lo escribo manual y aun asi
                        printf("%i",valor);                 //no reconoce la igualdad debido que el archivo no dice la cantidad de trabajadores se asume q puede ser tan grande 
                                                            //como uno crea, se usa malloc sizeof para asignar dinamicamente las dimensiones del struct sera q eso influye en algo??
                   /* for(i=0;i<cont;i++){
                                    //aca es donde esta todo el peo 

                        strcpy(temp,"RRHH");    //hacer esto es valido si funciona affirmacion

                        if(temp==trab[i].departamento){/*esta es la comprobacion 
                            aux++;
                            printf("el sueldo devengado por el trabajador %i es %i",i,trab[i].sueldo);
                            itoa(trab[i].cedula,tempaux,10);
                            fputs(tempaux,deparchivo);
                            fputs("\t",deparchivo);
                            vaciar(tempaux);
                            strcpy(tempaux,trab[i].nombre);
                            fputs(tempaux,deparchivo);
                            fputs("\t",deparchivo);
                            vaciar(tempaux);                        //descomentar para probar !!!// si llega a funcionar el proyecto estaria listo en su 80% falta la documentacion
                            strcpy(tempaux,trab[i].departamento);                                  // menuda ladiya T_T!!!!!
                            fputs(tempaux,deparchivo);
                            fputs("\t",deparchivo);
                            vaciar(tempaux);
                            strcpy(tempaux,trab[i].cargo);
                            fputs(tempaux,deparchivo);
                            fputs("\t",deparchivo);
                            vaciar(tempaux);
                            strcpy(tempaux,trab[i].fecha);
                            fputs(tempaux,deparchivo);
                            fputs("\t",deparchivo);
                            vaciar(tempaux);
                            itoa(trab[i].sueldo,tempaux,10);
                            fputs(tempaux,deparchivo);
                            fputs("\t",deparchivo);
                            fputs("\n",deparchivo);
                            vaciar(tempaux);   
                        }
                    }
                     */
                    //printf("el numero de trabajadores del departamento %s es %i\n",temp,aux);
                    fclose(archivo);
                    fclose(deparchivo);
                    fclose(cargochivo);
                
                    break;
                
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
            }

            break;
        case 3:
            break;
    }

}

void modulo_ingresar(){
    int n,valor,i;
    char temp[100];
    FILE *archivo;
    archivo=fopen("trabajadores.txt","r+");
    if(archivo==NULL){
        printf("cant open file\n");
        exit(1);
    }
    while(!feof(archivo)){
        fgets(temp,100,archivo);
    }
    printf("cuantos empleados desea ingresar\n");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        
        printf("ingrese la cedula del nuevo empleado\n");
        scanf("%d",&valor);
        vaciar(temp);
        itoa(valor,temp,10);
        fputs("\n",archivo);
        fputs(temp,archivo);
        fputs("\t",archivo);
        printf("ingrese el primer nombre del nuevo empleado\n");
        vaciar(temp);
        scanf("%s",temp);
        fputs(temp,archivo);
        printf("el empleado tiene segundo nombre? 1.-si / 2.-no\n");
        scanf("%d",&valor);
        switch(valor){
            case 1:
                vaciar(temp);
                fputs(" ",archivo);
                printf("ingrese el segundo nombre del empleado\n");
                scanf("%s",temp);
                fputs(temp,archivo);
                fputs("\t",archivo);
                vaciar(temp);
                break;
            default:
                vaciar(temp);
                fputs("\t",archivo);
                break;
        }
        printf("ingrese el departamento del nuevo empleado\n");
        scanf("%s",temp);
        fputs(temp,archivo);
        fputs("\t",archivo);
        vaciar(temp);
        printf("ingrese el cargo del nuevo empleado\n");
        scanf("%s",temp);
        fputs(temp,archivo);
        fputs("\t",archivo);
        vaciar(temp);
        printf("ingrese la fecha de contrato\n");
        printf("use el siguiente formato dd/mm/aa\n");
        scanf("%s",temp);
        fputs(temp,archivo);
        fputs("\t",archivo);
        vaciar(temp);
        printf("ingrese el sueldo a devengar del nuevo empleado\n");
        scanf("%d",&valor);
        itoa(valor,temp,10);
        fputs(temp,archivo);
        fputs("\t",archivo);

    }
    fclose(archivo);



}


void menu(){
    int opcion;
    printf("FUTURE CORP Informatic Solution Menu de gestion\n");
    printf("que desea hacer?\n");
    printf("1.- ingresar / 2.- consultar / 3.- modificar / 4.- eliminar / 5.- salir\n");
    printf("ingrese una opcion and press enter :");
    scanf("%d",&opcion);
    switch(opcion){
        case 1:
            modulo_ingresar();
            break;
        case 2:
            modulo_consultar();
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            break;
    }

}



void vaciar(char temp[]){

    int i;
    for(i=0;i<100;i++){
        temp[i]='\0';
    }
}
void copiar(char temp[],int i, int estado ){
    int N;
        switch(estado){
            case 0:
                trab[i].cedula=atoi(temp);
                 /*N =strlen(temp)+1;
                trab[i].cedula=(char*)malloc(N*sizeof(char));
                if(trab[i].cedula==NULL){
                    printf("cant allocate\n");
                    exit(1);
            
                }
                strcpy(trab[i].cedula,temp);*/
                break;
            case 1:
                N =strlen(temp)+1;
                trab[i].nombre=(char*)malloc(N*sizeof(char));
                if(trab[i].nombre==NULL){
                    printf("cant allocate\n");
                    exit(1);
            
                }
                strcpy(trab[i].nombre,temp);
            break;
            case 2:
                N=strlen(temp)+1;
                trab[i].departamento=(char*)malloc(N*sizeof(char));
                if(trab[i].departamento==NULL){
                    printf("cant allocate\n");
                    exit(1);
                }
                strcpy(trab[i].departamento,temp);
                break;
            case 3:
                N=strlen(temp)+1;

                trab[i].cargo=(char*)malloc(N*sizeof(char));
                if(trab[i].cargo==NULL){
                    printf("cant allocate\n");
                    exit(1);
                }
                strcpy(trab[i].cargo,temp);
                break;
            case 4:
                N=strlen(temp)+1;
                trab[i].fecha=(char*)malloc(N*sizeof(char));
                if(trab[i].fecha==NULL){
                    printf("cant allocate\n");
                    exit(1);
                }
                strcpy(trab[i].fecha,temp);
                break;
            case 5:
            trab[i].sueldo=atoi(temp);
                break;
            default:
                break;
        }

           
}
void file_upload(){
    char temp[100],aux;
    int i,j,cont=0,control=0;
    FILE *archivo;
    archivo=fopen("trabajadores.txt","r");
    if(archivo==NULL){
        printf("cant open file\n");
        exit(1);
    }
    while(!feof(archivo)){
        fgets(temp,100,archivo);
        cont++;

    }
    rewind(archivo);
    trab=(trabajadores*)malloc(cont*sizeof(trabajadores));
    if(trab==NULL){
        printf("cant allocate\n");
        exit(1);
    }
    while(!feof(archivo)){
        aux=fgetc(archivo);
        if(aux!='\t'){
            temp[j]=aux;
            j++;
        }
        else{
            copiar(temp,i,control);
            control++;
            vaciar(temp);
            j=0;
            aux='\0';
            if(control>5){
                i++;
                control=0;
            }
        }
    }
    fclose(archivo);
  
        for(i=0;i<cont;i++){
            printf("CEDULA: %i NOMBRE: %s DEPARTAMENTO: %s CARGO: %s FECHA: %s SUELDO:%i\n",trab[i].cedula,trab[i].nombre,trab[i].departamento,trab[i].cargo,trab[i].fecha,trab[i].sueldo);
        }
 
  
}


int main(){
   file_upload();
    menu();
    free(trab);

    return 0;
}