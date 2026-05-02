#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarPersonas(char **personas){ //doble puntero porque es una lista de strings (array de array, y cada array es un puntero al primer elemento)->doble puntero
    for(int i=0; i<5;i++){
        puts(personas[i]);
    }
}

void buscarNombre(char **personas){
    int id;
    
    printf("\nIngrese un id: ");
    scanf("%d", &id);
    if(id < 0 || id >= 5){
        printf("no se encontro el valor buscado");
    }else{
        puts(personas[id]);
    }
}

int main()
{
    //codigo dado en clases
    /*char buff[50];
    scanf("%s", buff);
    int tam = strlen(buff); // no considera el caracter nulo por lo tanto devuelve 10
   
    char * Cadena;     
    Cadena = (char *) malloc (sizeof(char) * tam + 1); // Reserva de memoria para la cadena pero aumento 1 byte para el carcter nulo
    
    strcpy(Cadena, buff);  
    printf("%s",Cadena);
    
    getchar();  
    */

    char buff [5][50];
    char *  personas[5];
    int tam = 0;
    for(int i=0; i<5;i++){
        printf("Ingrese un nombre");
        gets(buff[i]);
        tam = strlen(buff[i]);
        personas[i]= (char *) malloc(sizeof(char)*(tam+1)); //asigno espacio en memoria para personas[i]
        strcpy(personas[i], buff[i]); //copio a personas[i] lo que estaba en buff[i]
        getchar(); 
    }
    
    mostrarPersonas(personas);
    buscarNombre(personas);

    for(int i=0; i<5;i++){
        free(personas[i]);
    }
    

    return 0;
}
