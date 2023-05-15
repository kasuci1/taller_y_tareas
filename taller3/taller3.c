#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[20];
    int note1;
    int note2;
    int note3;
    float prom;
}student[20];

student stu;

void fill_struct();
void direct_sort(float prom_vec[],int cont,int index_vec[]);
void matrix_print(float prom_vec[],int cont, int index_vec[]);


void matrix_print(float prom_vec[],int cont, int index_vec[]){
    int search=cont-1,i;
    printf("-----reformating Matrix Print!----");
    printf("\n");
    for(i=0;i<cont;i++){
        printf("%i %s %.2f\t",i,stu[search].name,prom_vec[search]);
        printf("\n");
        search=search-1;
    }
    printf("----------------------------------");
}

void direct_sort(float prom_vec[],int cont,int index_vec[]){        
   
   int actually,j,smallest,aux;


    for(actually=0;actually<cont;actually++){                                         
        smallest=actually;                                                       
        for(j=actually+1;j<cont;j++){                                            
            if(prom_vec[j]<prom_vec[smallest]){
                smallest=j;
            }
        }
        aux=prom_vec[actually];
        prom_vec[actually]=prom_vec[smallest];
        prom_vec[smallest]=aux;
        
        aux=index_vec[actually];
        index_vec[actually]=index_vec[smallest];  
        index_vec[smallest]=aux;                        
    }                                                            
                                                                
}



void fill_vect(float prom_vec[20],int index_vec[20]){

    FILE *arch;
    char temp[100];
    int cont=0,i;
    arch=fopen("student_notes.txt","r");
    
    if(arch==NULL){
        printf("cant open file");
        exit(1);
    }
    while(!feof(arch)){
        fgets(temp,100,arch);
        cont++;
    }
    fclose(arch);

    for(i=0;i<cont;i++){
        index_vec[i]=i;
        prom_vec[i]=stu[i].prom;
    }
    direct_sort(prom_vec,cont,index_vec);
    printf("----------Sort search index scanning!---------");
    printf("\n");
    for(i=0;i<cont;i++){
        printf(" %i \t",index_vec[i]);
        
    }
    printf("V_index!");
    printf("\n");
    for(i=0;i<cont;i++){
        printf("%.2f \t",prom_vec[i]);
    }
    printf("V_prom!");
    printf("\n");

}


void fill_struct(){
    FILE *arch;
    int i=0,cont=0;
    char temp[100];
    arch=fopen("student_notes.txt","r");
    if(arch==NULL){
        printf("cant open file");
        exit(1);
    }
    while(!feof(arch)){
        fgets(temp,100,arch);
        cont++;
    }
    rewind(arch);
    while(!feof(arch)){
        fscanf(arch,"%s %i %i %i",stu[i].name,&stu[i].note1,&stu[i].note2,&stu[i].note3);
        i++;
    }
    for(i=0;i<cont;i++){
        stu[i].prom=(stu[i].note1+stu[i].note2+stu[i].note3)/3;
    }
    printf("----------------Struct upload!-----------------------");
    printf("\n");
    for(i=0;i<cont;i++){
        printf("NAME: %s NOTE1: %i NOTE2: %i NOTE3: %i PROM: %.2f\n",stu[i].name,stu[i].note1,stu[i].note2,stu[i].note3,stu[i].prom);
    }
    printf("\n");
    fclose(arch);

}







int main(){
    float prom_vec[20];
    int index_vec[20],cont=0;
    char temp[100];
    FILE *arch;
    arch=fopen("student_notes.txt","r");
    if(arch==NULL){
        printf("cant open file");
        exit(1);
    }
    while(!feof(arch)){
        fgets(temp,100,arch);
        cont++;
    }
    fclose(arch);
    fill_struct();
    fill_vect(prom_vec,index_vec);
    matrix_print(prom_vec,cont,index_vec);



    return 0;
}