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
    char *  Cadenas[5];
    int tam = 0;
    for(int i=0; i<5;i++){
        printf("Ingrese un nombre");
        gets(buff[i]);
        tam = strlen(buff[i]);
        Cadenas[i]= (char *) malloc(sizeof(char)*tam+1);
        getchar(); 
    }
    for(int i=0; i<5;i++){
        puts(Cadenas[i]);
    }


    return 0;
}
