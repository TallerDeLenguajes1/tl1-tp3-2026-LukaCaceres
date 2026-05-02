#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
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
    char *  Personas[5];
    int tam = 0;
    for(int i=0; i<5;i++){
        printf("Ingrese un nombre");
        gets(buff[i]);
        tam = strlen(buff[i]);
        Personas[i]= (char *) malloc(sizeof(char)*(tam+1)); //asigno espacio en memoria para personas[i]
        strcpy(Personas[i], buff[i]); //copio a personas[i] lo que estaba en buff[i]
        getchar(); 
    }
    for(int i=0; i<5;i++){
        puts(Personas[i]);
    }

    for(int i=0; i<5;i++){
        free(Personas[i]);
    }


    return 0;
}
