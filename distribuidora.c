#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Producto{
    int productoId;
    int cantidad; //1-10
    char *tipo;
    float precioUnitario; //10-100
}Producto;

typedef struct Cliente{
    int clienteId;
    char *nombre;
    int cantidad;
    Producto *productos;
}Cliente;

void cargarProductos(Producto *productos, int cant){
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    for(int i=0; i<cant;i++){
        productos[i].productoId = i;
        productos[i].cantidad = 1 + rand() % 10;
        //aqui buff es puntero en vez de char buff[50] porque tiposproductos es una array de puntero, entonces si quiero copiar a buff este tmb debe ser puntero
        char *buff = TiposProductos[rand()%5];//pongo el tipo en una variable auxiliar
        productos[i].tipo = malloc(sizeof(char)*(strlen(buff)+1)); //asigno en memoria
        strcpy(productos[i].tipo, buff);//copio desde la auxiliar al campo de la estructura
        productos[i].precioUnitario = 1+rand() % (100-10+1);
    }
}

void cargarClientes(Cliente * clientes, int cant){
    char buff[50];
    for(int i=0; i<cant;i++){
        clientes[i].clienteId = i;
        printf("\nIngrese el nombre del cliente numero %d: ", i+1);
        gets(buff);//guardo en variable auxiliar
        int len = strlen(buff) + 1;
        clientes[i].nombre = (char *) malloc(sizeof(char)*len);//asigno memoria en base al tamanio
        strcpy(clientes[i].nombre, buff);//copio de la auxiliar al elemento
        clientes[i].cantidad = 1 + rand() % 5;
        clientes[i].productos = (Producto*)malloc(sizeof(Producto)*clientes[i].cantidad);
        cargarProductos(clientes[i].productos, clientes[i].cantidad);
    }
}

float costoTotal(Cliente *clientes, int indice){
    float costos[clientes[indice].cantidad];
    float total=0;
    printf("\nEl cliente %d tiene %d productos distintos.", indice+1, clientes[indice].cantidad);
    for(int i=0;i<clientes[indice].cantidad; i++){
        costos[i]=clientes[indice].productos[i].precioUnitario*clientes[indice].productos[i].cantidad;
        printf("\nEl costo total del producto numero %d es: %f",i+1, costos[i]);
        total = total + costos[i];
    }
    return total;
    
    
}


int main(){
    int cantClientes, indice;
    float costoProductos;
    Cliente * clientes;
    printf("\n-----------------------");
    printf("\nIngrese la cantidad de clientes: ");
    scanf("%d", &cantClientes);
    printf("\n-----------------------");
    
    while(cantClientes>5){
        printf("La cantidad de clientes debe ser menor o igual a 5. Ingrese nuevamente: ");
        scanf("%d", &cantClientes);
    }
    fflush(stdin);
    clientes = (Cliente *) malloc(sizeof(Cliente) * cantClientes); //asigno espacio en memoria para esa cantidad
    
    printf("\n ---------------------Comenzando Carga de cleintes-----------------");
    cargarClientes(clientes, cantClientes);
    printf("\n ---------------------Carga finalizada-----------------");

    printf("\n ---------------------Elija un numero de cliente para ver el costo de sus productos-----------------");
    printf("\nCliente numero: ");
    scanf("%d", &indice);
    costoProductos=costoTotal(clientes, indice-1);
    printf("\nEl costo total de los productos es: %f", costoProductos);
    return 0;
}