#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
//prototipos

void modulo_consultar();
void modulo_ingresar();
void modulo_modificar();
void modulo_eliminar();
void vaciar(char temp[]);
void parameter_changer(int valor, int cont);
void eliminator(int valor);
void file_upload();
void menu();
void direct_sort( int vector_matriz[],int cont,int indice_vec_sueldo[]);
//---------------------------------------------------
//estructura de carga
typedef struct{

    int cedula;
    char nombre[30];
    char departamento[20];
    char cargo[20];
    char fecha[20];
    int sueldo;
//-----------------------------
}trabajadores[20];
trabajadores trab;
//procedimientos
//eliminador procedimiento que recibe el valor del indice del objetivo en funcion del mismo se aisla al objetivo del resto de los datos para su manipulacion y eliminacion.
void eliminator(int valor){
    FILE *archivo;
    char temp[100],date_fired[100];
    int cont=0,desicion,i;
    archivo=fopen("trabajadores1.txt","r");
    while(!feof(archivo)){                  //se recorre el archivo de entrada para verificar cuantos objetivos hay hasta fin de archivo
        fgets(temp,100,archivo);            //se guarda en un vector temporal solo para mover el cursor has EOL
        cont++;                             // contador que lleva la cuenta de objetivos

    }

    fclose(archivo);                        //se cierrra archivo
    vaciar(date_fired);                      //se vacia el vector que va a recibir una copia de la fecha de eliminacion de objetivo
    printf("esta es la informacion del objetivo\n");
    printf("CEDULA: %i NOMBRE: %s DEPARTAMENTO: %s CARGO: %s FECHA: %s SUELDO: %i",trab[valor].cedula,trab[valor].nombre,trab[valor].departamento,trab[valor].cargo,trab[valor].fecha,trab[valor].sueldo);
    printf("\n");
    printf("esta seguro que desea retirar de sus funciones para con la empresa al trabajador %i",trab[valor].cedula);
    printf("\n");               //se hace la pregunta para validar la eliminacion
    printf("1.-SI / 2.-NO\n");
    scanf("%i",&desicion);
    if(desicion==1){
        archivo=fopen("extrabajadores.txt","w");                                        //crea documento extrabajadores.txt
        printf("ingrese la opcion del motivo de despido\n");
        printf("1.-traslado / 2.-renuncia / 3.-despido / 4.-otro\n");
        scanf("%i",&desicion);                                                          //
        switch(desicion){                                                               //estructura que decide segun la decision el criterio de eliminacion 
            case 1:                                                                     //del objetivo
                printf("ingrese la fecha de traslado con formato dd/mm/aa\n");          //
                scanf("%s",&date_fired);                                                                                //
                strcpy(temp,"traslado");                                                                                //
                                                                                                                        //
                break;                                                                                                  //
            case 2:                                                                                                     //
                printf("ingrese la fecha de renuncia con formato dd/mm/aa\n");                                          //
                scanf("%s",&date_fired);                                                                                 //
                strcpy(temp,"renuncia");                                                                                //
                break;                                                                                                  //
            case 3:                                                                                                     //
                printf("ingrese la fecha de despido con formato dd/mm/aa\n");   
                scanf("%s",&date_fired);                                        //
                strcpy(temp,"despido");                                                                                 //
                break;                                                                                                  //
            case 4:                                                                                                     //
                printf("ingrese la fecha de remocion con formato dd/mm/aa\n");  
                scanf("%s",&date_fired);                                        //
                strcpy(temp,"otro");                                                                                    //
                break;                                                              //--------------------------------------------------------------------------
        }                                                                           //esto empieza a escribir los datos del objetivo eliminado en 
        fputs("(",archivo);                                                         //extrabajadores.txt  line 78-145
        fputs(temp,archivo);    
        fputs(")",archivo);
        fputs(" ",archivo);
        vaciar(temp);
        sprintf(temp,"%i",trab[valor].cedula);
        fputs(temp,archivo);
        fputs(" ",archivo);
        fputs(trab[valor].nombre,archivo);
        fputs(" ",archivo);
        fputs(trab[valor].departamento,archivo);
        fputs(" ",archivo);
        fputs(trab[valor].cargo,archivo);
        fputs(" ",archivo);
        fputs(trab[valor].fecha,archivo);
        fputs(" ",archivo);
        vaciar(temp);
        sprintf(temp,"%i",trab[valor].sueldo);
        fputs(temp,archivo);
        fputs(" ",archivo);
        fputs("fired at",archivo);
        fputs("(",archivo);
        fputs(date_fired,archivo);
        fputs(")",archivo);
        fputs("\n",archivo);
    }
    fclose(archivo);                                    //cierre de archivo extrabajadores.txt
    remove("trabajadores1.txt");                          ////proceso que escribe los datos actualizados en el archivo de entrada trabajadores.txt
    archivo=fopen("trabajadores1.txt","w");                //apertura de archivo de entrada
    for(i=0;i<valor-1;i++){                                //proceso que escribe los datos actualizados en el archivo de entrada sin incluir al eliminado
        sprintf(temp,"%i",trab[i].cedula);
        fputs(temp,archivo);
        fputs(" ",archivo);
        vaciar(temp);
        fputs(trab[i].nombre,archivo);
        fputs(" ",archivo);
        fputs(trab[i].departamento,archivo);
        fputs(" ",archivo);
        fputs(trab[i].cargo,archivo);
        fputs(" ",archivo);
        fputs(trab[i].fecha,archivo);
        fputs(" ",archivo);
        sprintf(temp,"%i",trab[i].sueldo);
        fputs(temp,archivo);
        fputs("\n",archivo);
    }
    if(valor+1<cont){                       //frontera de eliminacion que excluye al objetivo eliminado para dar paso a la escritura del resto de datos
                                            //si y solo si el objetivo aislado no es el ultimo en el archivo de entrada.
        for(i=valor+1;i<cont;i++){              
                                                //proceso que escribe la actualizacion de datos en archivo de entrada segun la frontera de aislamineto
            sprintf(temp,"%i",trab[i].cedula);
            fputs(temp,archivo);
            fputs(" ",archivo);
            vaciar(temp);
            fputs(trab[i].nombre,archivo);
            fputs(" ",archivo);
            fputs(trab[i].departamento,archivo);
            fputs(" ",archivo);
            fputs(trab[i].cargo,archivo);
            fputs(" ",archivo);
            fputs(trab[i].fecha,archivo);
            fputs(" ",archivo);
            sprintf(temp,"%i",trab[i].sueldo);
            fputs(temp,archivo);
            fputs("\n",archivo);
        }

    }
}

void paramenter_changer(int valor, int cont){                       //parameter changer
    int caso,aux,i,save_sueldo=0;
    char temp[100],save_cargo[100],save_depa[100],save_fecha[100];
    FILE *archivo;
                                                                        //modificador de parametros a conveniencia segun lo que se requiera
    printf("que parametro desea modificar\n");                          //en el modelos de seleccion de cambios 
    printf("1.-Departamento / 2.-Cargo / 3.-fecha / 4.-sueldo\n");
    vaciar(temp);
    scanf("%i",&caso);
    switch(caso){
        case 1:             
            printf("ingrese el numero del nuevo departamento\n");
            printf("1:RRHH / 2:consultoria / 3:diseno / 4:produccion / 5:desarrollador / 6:Distribucion :-");
            scanf("%d",&i);
                switch(i){                                  //todo se pone en modelos switch evitar error 505!
                    case 1:
                        strcpy(temp,"RRHH");
                        break;
                    case 2:
                        strcpy(temp,"Consultoria");
                        break;
                    case 3:
                        strcpy(temp,"Diseno");                          //estructura que carga las comparaciones para luego comparar
                        break;
                    case 4:
                        strcpy(temp,"Produccion");
                    break;
                    case 5:
                        strcpy(temp,"Calidad");
                        break;
                    case 6:
                        strcpy(temp,"Distribucion");
                        break;
                }
            strcpy(trab[valor].departamento,temp);
            break;
        case 2:
            printf("ingrese el numero del nuevo cargo\n");                     //estructura de seleccion de cambios de atributos del archivo de entrada
            printf("1:Gerente / 2:Supervisor / 3:Analista / 4:Disenador / 5:Desarrollador / 6:Auditor:- ");
            scanf("%d",&i); 
            switch(i){
                case 1:
                    strcpy(temp,"Gerente");
                    break;
                case 2:
                    strcpy(temp,"Supervisor");
                    break;
                case 3:
                    strcpy(temp,"Analista");
                    break;                          //otra consulta de comparacion pero con estructura para los cargos
                case 4:
                    strcpy(temp,"Disenador");
                break;
                case 5:
                    strcpy(temp,"Desarrollador");
                    break;
                case 6:
                    strcpy(temp,"Auditor");
                    break;
            }
            strcpy(trab[valor].cargo,temp);
            break;
        case 3:
            printf("ingrese la nueva fecha dd/mm/aa \n");;
            scanf("%s",&temp);
            strcpy(trab[valor].fecha,temp);
            break;
        case 4:
            printf("ingrese el nuevo sueldo\n");
            scanf("%i",&aux);
            trab[valor].sueldo=aux;
            break;
    }
    vaciar(temp);         //llenar cadena con void prepararla para recirbir los datos de cambio de atributos
    vaciar(save_cargo);     //save cargo cadena que obtiene el atributo de carga origina
    vaciar(save_depa);      //save depa ||  ||  ||
    vaciar(save_fecha);     //save fecha  ||    ||  ||                                                         //esto es un parche que resuelve una issue cada vez q un atributo
    strcpy(save_cargo,trab[valor].cargo);                                                                       //se actualizaba los otros se borraban 
    strcpy(save_depa,trab[valor].departamento);                                                                 //seguro se resuelve de alguna forma
    strcpy(save_fecha,trab[valor].fecha);                                                                      //pero de momento sigamos la filosofia de microsoft
    save_sueldo=trab[valor].sueldo;                                                                             //parches y mas parches xD!
    printf("%s %s %s %i\n",save_depa,save_cargo,save_fecha,save_sueldo);                                        //verifica que el parche fix!
    remove("trabajadores1.txt");                          //borra archivo de entrada
    archivo=fopen("trabajadores1.txt","w");              //lo prepara para el update
    for(i=0;i<cont;i++){                                    
        sprintf(temp,"%i",trab[i].cedula);
        fputs(temp,archivo);
        fputs(" ",archivo);
        vaciar(temp);
        fputs(trab[i].nombre,archivo);
        fputs(" ",archivo);
        fputs(trab[i].departamento,archivo);          //proceso que actualiza el archivo de entrada con los nuevos atributos
        fputs(" ",archivo);
        fputs(trab[i].cargo,archivo);
        fputs(" ",archivo);
        fputs(trab[i].fecha,archivo);
        fputs(" ",archivo);
        sprintf(temp,"%i",trab[i].sueldo);
        fputs(temp,archivo);
        fputs("\n",archivo);
    }
    vaciar(temp);
    sprintf(temp,"%i",trab[cont].cedula);
    fputs(temp,archivo);
    fputs(" ",archivo);
    fputs(trab[cont].nombre,archivo);
    fputs(" ",archivo);
    fputs(trab[cont].departamento,archivo);          //proceso que actualiza el archivo de entrada con los nuevos atributos
    fputs(" ",archivo);
    fputs(trab[cont].cargo,archivo);
    fputs(" ",archivo);
    fputs(trab[cont].fecha,archivo);
    fputs(" ",archivo);
    vaciar(temp);
    sprintf(temp,"%i",trab[cont].sueldo);
    fputs(temp,archivo);

}

void direct_sort(int vector_matriz[],int cont,int indice_vec_sueldo[]){         //is another sort algorithm xD!
    int actual,j,smallest,aux;
    for(actual=0;actual<cont;actual++){                                         //algoritmo de ordenamiento para identificar al los q ganan mas q los otros 
        smallest=actual;                                                        //trabajadores con modificaciion de rastreo para llevar el rastro original
        for(j=actual+1;j<cont;j++){                                             //segun su posicion en el archivo y asi poder localizarlos en el struct
            if(vector_matriz[j]<vector_matriz[smallest]){
                smallest=j;
            }
        }
        aux=vector_matriz[actual];
        vector_matriz[actual]=vector_matriz[smallest];
        vector_matriz[smallest]=aux;
        
        aux=indice_vec_sueldo[actual];
        indice_vec_sueldo[actual]=indice_vec_sueldo[smallest];  //analisis q relaciona los datos organizados sin que pierdan la posicion original del archivo
        indice_vec_sueldo[smallest]=aux;                        //es decir se les otorga un vector identificador de indice original
    }                                                            //asi q cuando sorted se puede saber a que linea pertenecian originalmente
                                                                    //y con ese indice en un ciclo poder rastrearlos dentro del struct
}
void modulo_eliminar(){                                             //modulo de eliminacion
    FILE *archivo;
    char temp[100];
    int cont=0,cedu,i=0,j,pass=1,decision;
    archivo=fopen("trabajadores1.txt","r");
    while(!feof(archivo)){                                      
        fgets(temp,100,archivo);
        cont++;
    }
    fclose(archivo);

    printf("ingrese la cedula del trabajador\n");
    scanf("%i",&cedu);
    while(pass==1){
        if(trab[i].cedula==cedu){                                       //verifica que la cedula sea valida
            pass=0;
            eliminator(i);
        }
        else{
            i++;

            if(i==cont){
                printf("la CI indicada no esta asociada a ningun trabajador de la empresa\n");
                printf("desea rectificar? 1.-SI/ 2.-NO\n");
                scanf("%i",&decision);
                if(decision==1){
                    printf("ingrese la cedula del trabajador\n");
                    scanf("%i",&cedu);
                    i=0;
                }
                else{
                    pass=0;
                            
                }
            }
        }
        if(decision==1){
            eliminator(i);          //cast! eliminator!!!!!!
        }
        else{
            //DUh!              //Duh! is Duh!?????
        }
    }



}



void modulo_modificar(){                    //modulo de modificacion
    FILE *archivo;
    char temp[100];
    int cont=0,cedu,i,j,pass=1,decision;
    archivo=fopen("trabajadores1.txt","r+");
    while(!feof(archivo)){
        fgets(temp,100,archivo);
        cont++;
    }                           //modulo censillo toda la magia nace de parameter changer que es quien hace el trabajo heavy de llevar las modificaciones
    fclose(archivo);                            
    printf("ingrese la cedula del trabajador\n");
    scanf("%i",&cedu);
    while(pass==1){
        if(trab[i].cedula==cedu){ 
            pass=0;
            printf("trabajador objetivo.- CEDULA: %i NOMBRE: %s DEPARTAMENTO: %s CARGO: %s SUELDO: %i",trab[i].cedula,trab[i].nombre,trab[i].departamento,trab[i].cargo,trab[i].sueldo);
            printf("\n");
            paramenter_changer(i,cont-1);
        }                                       //is another DNI verificator more!!!!
        else{
            i++;
            if(i==cont){
                printf("la CI indicada no esta asociada a ningun trabajador de la empresa\n");
                printf("desea rectificar? 1.-SI/ 2.-NO\t");
                scanf("%i",&decision);
                if(decision==1){
                    printf("ingrese la cedula del trabajador\n");
                    scanf("%i",&cedu);
                    i=0;
                }
                else{
                    pass=0;
                            
                }
            }
        }
    }
}






void modulo_consultar(){                                   //modulo de consulta
    int i=0,j,valor,valor2,bandera=1,cont=0,aux=0,desicion,flag=1;
    FILE *archivo;
    FILE *deparchivo;                                       //creacion de receptores nuevos archivos de salida
    FILE *cargochivo;
    char temp[100],tempaux[100],auxc;
    int vec_sueldo[100], indice_vec_sueldo[100];

    deparchivo=fopen("departamento.txt","a");   //se abre en append para escrbir al final de archivo
    if(deparchivo==NULL){
        printf("cant open file deparchivo\n");
        exit(1);
    }
    cargochivo=fopen("cargo.txt","a");
    if(cargochivo==NULL){
        printf("cant open file cargo chivo\n");
        exit(1);
    }

    archivo=fopen("trabajadores1.txt","r");  //archivo de entrada principal
    if(archivo==NULL){
        printf("cant open file\n");
        exit(1);
    }
    while(!feof(archivo)){
        fgets(temp,100,archivo);    //esto se usa para actualziar el registro seguro de vida contra modulo agregar
        cont++;                     //es importante mantener el struct actualizado en primer lugar en todo momento
    }
    vaciar(temp);           //preparar vectores de recepcion para nueva data
    vaciar(tempaux);
        printf("que tipo de consulta desea realizar\n");
        printf("1.-por cedula / 2.-por departamento / 3.-por cargo\n");
        scanf("%d",&valor);
        switch(valor){    
            case 1:                                                             //estructura de consulta para el update de la nueva data
                printf("ingrese el numero de cedula a consultar\n");
                scanf("%d",&valor);
                printf("\n");
                while(bandera==1){
                    if(valor==trab[i].cedula){          ///check de consulta exitosa por cedula 
                        printf("--------------consulta exitosa datos del consultado-----------------\n");
                        printf("CEDULA: %i NOMBRE: %s DEPARTAMENTO: %s CARGO: %s FECHA: %s SUELDO:%i\n",trab[i].cedula,trab[i].nombre,trab[i].departamento,trab[i].cargo,trab[i].fecha,trab[i].sueldo);
                        printf("--------------------------------------------------------------------\n");
                        bandera=0;
                    }
                    else{
                        i++;                                    //is another DNI verificator more
                        if(i==cont){                
                            printf("la CI indicada no esta asociada a ningun trabajador de la empresa\n");
                            printf("desea rectificar 1.-SI / 2.-NO\n");
                            scanf("%i",&desicion);
                            if(desicion==1){

                                printf("ingrese el numero de cedula a consultar\n");
                                scanf("%i",&valor);
                                i=0;
                            }
                            else{
                                bandera=0;
                            }
                        }
                    }
                }
                fclose(archivo);
                fclose(deparchivo);                                 //cierrre de archivos reset puntero
                fclose(cargochivo);
                break;
            case 2:
                printf("ingrese el numero de departamento a consultar\n");      //seccion de consulta pro departamento
                printf("1:RRHH / 2:consultoria / 3:diseno / 4:produccion / 5:desarrollador / 6:auditor :-");
                scanf("%d",&valor); 
                switch(valor){
                    case 1:
                        strcpy(temp,"RRHH");
                        break;
                    case 2:
                        strcpy(temp,"Consultoria");
                        break;
                    case 3:
                        strcpy(temp,"Diseno");                          //estructura que carga las comparaciones para luego comparar
                        break;
                    case 4:
                        strcpy(temp,"Produccion");
                    break;
                    case 5:
                        strcpy(temp,"Calidad");
                        break;
                    case 6:
                        strcpy(temp,"Distribucion");
                        break;
                }
                for(i=0;i<cont;i++){
                    if(strcmp(temp,trab[i].departamento)==0){            //comparacion en funcion de la estructura anterior                                      
                        aux++;
                        printf("el sueldo devengado por el trabajador %s es %i\n",trab[i].nombre,trab[i].sueldo);
                        sprintf(tempaux,"%i",trab[i].cedula);
                        fputs(tempaux,deparchivo);
                        fputs(" ",deparchivo);
                        vaciar(tempaux);
                        strcpy(tempaux,trab[i].nombre);
                        fputs(tempaux,deparchivo);                              //estructura de comparacion y carga de nuevos para actualzar departamento.txt de salida
                        fputs(" ",deparchivo);
                        vaciar(tempaux);  
                        fputs("(",deparchivo);                      
                        strcpy(tempaux,trab[i].departamento);                                 
                        fputs(tempaux,deparchivo);
                        fputs(")",deparchivo);
                        fputs(" ",deparchivo);
                        vaciar(tempaux);
                        strcpy(tempaux,trab[i].cargo);
                        fputs(tempaux,deparchivo);
                        fputs(" ",deparchivo);
                        vaciar(tempaux);
                        strcpy(tempaux,trab[i].fecha);
                        fputs(tempaux,deparchivo);
                        fputs(" ",deparchivo);
                        vaciar(tempaux);
                        sprintf(tempaux,"%i",trab[i].sueldo);
                        fputs(tempaux,deparchivo);
                        fputs(" ",deparchivo);
                        fputs("\n",deparchivo);
                        vaciar(tempaux);   
                    }
                }                   ///check de consulta por departamento exitosa
                printf("el numero de trabajadores del departamento %s es %i\n",temp,aux);
                fclose(archivo);
                fclose(deparchivo);
                fclose(cargochivo);
                break;
            case 3:
                printf("ingrese el numero del cargo a consultar\n");    //seccion de consulta por cargo
                printf("1:Gerente / 2:Supervisor / 3:Analista / 4:Disenador / 5:Desarrollador / 6:Auditor .- ");
                scanf("%d",&valor); 
                switch(valor){
                    case 1:
                        strcpy(temp,"Gerente");
                        break;
                    case 2:
                        strcpy(temp,"Supervisor");
                        break;
                    case 3:
                        strcpy(temp,"Analista");
                        break;                          //otra consulta de comparacion pero con estructura para los cargos
                    case 4:
                        strcpy(temp,"Disenador");
                    break;
                    case 5:
                        strcpy(temp,"Desarrollador");
                        break;
                    case 6:
                        strcpy(temp,"Auditor");
                        break;
                } 
                for(i=0;i<cont;i++){    //estructura que se encarga de localizar el cargo sin quick sort modder esto no seria posible
                    if(strcmp(temp,trab[i].cargo)==0){                                                   
                        aux++;
                        printf("el sueldo devengado por el trabajador %s es %i \n",trab[i].nombre,trab[i].sueldo);
                        sprintf(tempaux,"%i",trab[i].cedula);
                        fputs(tempaux,cargochivo);
                        fputs(" ",cargochivo);
                        vaciar(tempaux);
                        strcpy(tempaux,trab[i].nombre);
                        fputs(tempaux,cargochivo);
                        fputs(" ",cargochivo);
                        vaciar(tempaux);                        
                        strcpy(tempaux,trab[i].departamento);                              
                        fputs(tempaux,cargochivo);
                        fputs(" ",cargochivo);
                        vaciar(tempaux); 
                        fputs("(",cargochivo);               //estructura que actualiza cargo.txt de salida
                        strcpy(tempaux,trab[i].cargo);
                        fputs(tempaux,cargochivo);
                        fputs(")",cargochivo);
                        fputs(" ",cargochivo);
                        vaciar(tempaux);
                        strcpy(tempaux,trab[i].fecha);
                        fputs(tempaux,cargochivo);
                        fputs(" ",cargochivo);
                        vaciar(tempaux);
                        sprintf(tempaux,"%i",trab[i].sueldo);
                        fputs(tempaux,cargochivo);
                        fputs(" ",cargochivo);
                        fputs("\n",cargochivo);
                        vaciar(tempaux);   
                    }
                }       //check de cargo exitoso
                printf("el numero de trabajadores del cargo %s es %i\n",temp,aux);
                fclose(archivo);
                fclose(deparchivo);
                fclose(cargochivo);
            break;
        }
    

    aux=0;
    for(i=0;i<cont;i++){
        vec_sueldo[i]=trab[i].sueldo;
        indice_vec_sueldo[i]=aux;
        aux++;
        printf("%i\t",trab[i].sueldo);
        
    }
    printf("trab");
    printf("\n");
    for(i=0;i<cont;i++){
        printf("%i\t",indice_vec_sueldo[i]);
    }
    printf("indice");
    printf("\n");
    direct_sort(vec_sueldo,cont,indice_vec_sueldo);     //usando el analisis de los pesos en sort aca se muestran 
    for(i=0;i<cont;i++){                                //y se organizan los trabajadores de mayor a menor sueldo
        printf("%i\t",vec_sueldo[i]);
    }
    printf("vec");
    printf("\n");
    for(i=0;i<cont;i++){
        printf("%i\t",indice_vec_sueldo[i]);
    }
    printf("indiceSort");
    printf("\n");
    printf("los trabajadores que tiene de mayor a menor sueldo repectivamente son \n");
    j=cont-1;
    for(i=0;i<cont;i++){
        aux=indice_vec_sueldo[j];               //analisis del rastreador de datos en struct pero organizados. como las cookies pero mas primitivas !
        j=j-1;
        printf("NOMBRE: %s SUELDO:%i \n",trab[aux].nombre,trab[aux].sueldo);
    }
    fclose(archivo);
    fclose(deparchivo);
    fclose(cargochivo);


}

void modulo_ingresar(){         //modulo de ingreso
    int n,valor,i;              //ingresa datos de trabajadores nuevos y actualiza trabajadores.txt archivo de entrada matriz
    char temp[100];
    FILE *archivo;
    archivo=fopen("trabajadores1.txt","a");
    if(archivo==NULL){
        printf("cant open file\n");
        exit(1);
    }
    printf("cuantos empleados desea ingresar\n");
    scanf("%d",&n);

    for(i=0;i<n;i++){               //sugerencia probar ingresando solo 1 empleado nuevo da flojera llenar esos datos xD a mano
        
        printf("ingrese la cedula del nuevo empleado\n");
        scanf("%i",&valor);
        vaciar(temp);
        fputs("\n",archivo);
        itoa(valor,temp,10);
        fputs(temp,archivo);
        fputs(" ",archivo);
        printf("ingrese el primer nombre del nuevo empleado\n");
        vaciar(temp);
        scanf("%s",temp);
        fputs(temp,archivo);
        printf("el empleado tiene segundo nombre? 1.-si / 2.-no\n");    //estructura que permite la carga de datos nuevo en trabajadores.txt
        scanf("%d",&valor);
        switch(valor){
            case 1:
                vaciar(temp);
                fputs("_",archivo);
                printf("ingrese el segundo nombre del empleado\n");
                scanf("%s",temp);
                fputs(temp,archivo);
                fputs(" ",archivo);
                vaciar(temp);
                break;
            default:
                fputs(" ",archivo);
                break;
        }
        printf("ingrese la opcion que corresponte al  departamento del nuevo empleado\n");
        printf("1.RRHH / 2.Consultoria / 3.Diseño / 4.Produccion / 5.Calidad / 6.Distribucion\n");
        printf("ingrese una opcion del 1 al 6 :\n");
        scanf("%d",&valor);
        switch(valor){
            case 1:
            vaciar(temp);
                strcpy(temp,"RRHH");
                break;
            case 2:
                vaciar(temp);
                strcpy(temp,"Consultoria");
                break;
            case 3:
                vaciar(temp);
                strcpy(temp,"Diseno");
                break;
            case 4:
                vaciar(temp);
                strcpy(temp,"Produccion");
                break;
            case 5:
                vaciar(temp);
                strcpy(temp,"Calidad");
                break;
            case 6:
                vaciar(temp);
                strcpy(temp,"Distribucion");
                break;
            default:
                break;  
        }
        fputs(temp,archivo);
        fputs(" ",archivo);
        vaciar(temp);
        printf("ingrese la opcion que corresponte al  cargo del nuevo empleado\n");
        printf("1.Gerente / 2.Supervisor / 3.Analista / 4.Diseñador / 5.Desarrollador / 6.Auditor\n");
        printf("ingrese una opcion del 1 al 6 :\n");
        scanf("%d",&valor);
        switch(valor){
            case 1:
            vaciar(temp);
                strcpy(temp,"Gerente");
                break;
            case 2:
                vaciar(temp);
                strcpy(temp,"Supervisor");
                break;
            case 3:
                vaciar(temp);
                strcpy(temp,"Analista");
                break;
            case 4:
                vaciar(temp);
                strcpy(temp,"Disenador");
                break;
            case 5:
                vaciar(temp);
                strcpy(temp,"Desarrollador");
                break;
            case 6:
                vaciar(temp);
                strcpy(temp,"Auditor");
                break;
            default:
                break;  
        }

        fputs(temp,archivo);
        fputs(" ",archivo);
        vaciar(temp);
        printf("ingrese la fecha de contrato\n");
        printf("use el siguiente formato dd/mm/aa\n");
        scanf("%s",temp);
        fputs(temp,archivo);
        fputs(" ",archivo);
        vaciar(temp);
        printf("ingrese el sueldo a devengar del nuevo empleado\n");
        scanf("%d",&valor);
        itoa(valor,temp,10);
        fputs(temp,archivo);

    }
    fclose(archivo);
    file_upload();
    



}


void menu(){
    int opcion;
    int flag=1;
    while(flag==1){
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
                break;                      //el menu que permite la seleccion de la magia simple 
            case 3:                         //ojala el codigo en back de esos proc fuera igual de simple e.e!
                modulo_modificar();
                break;
            case 4:
                modulo_eliminar();
                break;
            default:
                exit(1);
                break;
        }
        printf("desea realizar alguna otra operacion?? 1.-SI / 2.-NO ");
        scanf("%i",&opcion);
        if(opcion!=1){
            flag=2;
        }
        else{
            system("cls");
            file_upload();
        }
    }

}



void vaciar(char temp[]){       //el rey de todos los proc el mas usado sin el todo seria un desastre
                                //permite iniciar cadenas vacias y limpias libres de bug buffer !
    int i;
    for(i=0;i<100;i++){
        temp[i]='\0';
    }
}

void file_upload(){     //proc principal  preparador de carga

    char temp[100],temp2[50];
    int dimension,cont=0,control=0,i,j,k=0,aux;
    FILE *archivo;
    archivo=fopen("trabajadores1.txt","r");
    if(archivo==NULL){
        printf("cant open file\n");
        exit(1);
    }
    while(!feof(archivo)){
        fgets(temp,100,archivo);
        cont++;
    }
    rewind(archivo);

        for(i=0;i<cont;i++){
            fscanf(archivo,"%i %s %s %s %s %i",&trab[i].cedula,&trab[i].nombre,&trab[i].departamento,&trab[i].cargo,&trab[i].fecha,&trab[i].sueldo);
        }
                                            //carga y muetras de datos en estructura principal para manipulacion
        for(i=0;i<cont;i++){
            printf("%i %s %s %s %s %i\n",trab[i].cedula,trab[i].nombre,trab[i].departamento,trab[i].cargo,trab[i].fecha,trab[i].sueldo);
        }
   
   fclose(archivo);
}



int main(){
   file_upload();
    menu();
   // free(trab);

    return 0;
}
//ir a la linea 781 y cambia cls por clear dont panic si llega a fallar :v!