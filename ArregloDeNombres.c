#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarPersonas(char **personas){ //doble puntero porque es una lista de strings (array de array, y cada array es un puntero al primer elemento)->doble puntero
    for(int i=0; i<5;i++){
        puts(personas[i]);
    }
}

void buscarNombrePorId(char **personas){
    int id;
    
    printf("\nIngrese un id: ");
    scanf("%d", &id);
    if(id < 0 || id >= 5){
        printf("no se encontro el valor buscado");
    }else{
        puts(personas[id]);
    }
}

int  BuscaNombrePorPalabra(char **personas, char *palabra){
    int coincidencia = -1; 
    int i=0;
    while(i<5 && coincidencia==-1){
        if(strstr(personas[i], palabra)==NULL){
            i++;
        }
        else{
            coincidencia=i;
        }
    }
    return coincidencia;
}

int main()
{
    char buff [5][50];
    char *  personas[5];
    char *keyword;
    int indiceEncontrado;
    int tam = 0;

    //Ingresar nombres
    for(int i=0; i<5;i++){
        printf("Ingrese un nombre");
        gets(buff[i]);
        tam = strlen(buff[i]);
        personas[i]= (char *) malloc(sizeof(char)*(tam+1)); //asigno espacio en memoria para personas[i]
        strcpy(personas[i], buff[i]); //copio a personas[i] lo que estaba en buff[i]
        getchar(); 
    }
    
    //Mostrar nombres
    mostrarPersonas(personas);
    
    //Buscar por Palabra
    printf("\ningrese la palabra clave: ");
    gets(buff[0]);
    keyword = (char *) malloc(sizeof(char)*(strlen(buff[0])+1));
    strcpy(keyword, buff[0]);
    indiceEncontrado = buscarNombre(personas, keyword);
    if(indiceEncontrado!=-1){
        printf("\nEl nombre encontrado es: ");
        puts(personas[indiceEncontrado]);
    }else{
        printf("\nLa palabra clave no se encuentra entre los nombres ingresados");
    }
    
    //Buscar Por ID
    buscarNombrePorId(personas);

    for(int i=0; i<5;i++){
        free(personas[i]);
    }
    

    return 0;
}
