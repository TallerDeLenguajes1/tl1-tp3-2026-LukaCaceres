#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarPersonas(char **personas)
{
    for (int i = 0; i < 5; i++)
    {
        puts(personas[i]);
    }
}

void buscarNombrePorId(char **personas)
{
    int id;

    printf("\nIngrese un id: ");
    scanf("%d", &id);
    fflush(stdin); 

    if (id < 0 || id >= 5)
    {
        printf("no se encontro el valor buscado");
    }
    else
    {
        puts(personas[id]);
    }
}

int buscarNombrePorPalabra(char **personas, char *palabra)
{
    int coincidencia = -1;
    int i = 0;
    while (i < 5 && coincidencia == -1)
    {
        if (strstr(personas[i], palabra) != NULL)
        {
            coincidencia = i;
        }
        i++;
    }
    return coincidencia;
}

int main()
{
    char buff[5][50];
    char *personas[5];
    char *keyword;
    int indiceEncontrado;
    int opcion;

    // Ingresar nombres
    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese un nombre: ");
        gets(buff[i]); // ✔ queda

        personas[i] = (char *)malloc(strlen(buff[i]) + 1);
        strcpy(personas[i], buff[i]);
    }

    

    // Mostrar nombres
    mostrarPersonas(personas);
    
    

    printf("\n -------------------------------------------------------\n");
    printf("\n 1) Buscar usuario por ID");
    printf("\n 2) Buscar usuario por Palabra Clave");
    printf("\n -------------------------------------------------------\n");
    scanf("%d", &opcion);
    fflush(stdin); 

    

    switch (opcion)
    {
    case 1:
        buscarNombrePorId(personas);
        break;

    case 2:
        printf("\ningrese la palabra clave: ");
        gets(buff[0]); 

        keyword = (char *)malloc(strlen(buff[0]) + 1);
        strcpy(keyword, buff[0]);

        indiceEncontrado = buscarNombrePorPalabra(personas, keyword);

        if (indiceEncontrado != -1)
        {
            printf("\nEl nombre encontrado es: ");
            puts(personas[indiceEncontrado]);
        }
        else
        {
            printf("\nLa palabra clave no se encuentra entre los nombres ingresados");
        }

        free(keyword);
        break;

    default:
        printf("opcion no valida");
        break;
    }

    // liberar memoria
    for (int i = 0; i < 5; i++)
    {
        free(personas[i]);
    }

    return 0;
}