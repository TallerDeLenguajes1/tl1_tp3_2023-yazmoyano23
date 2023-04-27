/*
Considere la siguiente situación: En una distribuidora necesita implementar la carga de
productos de sus preventistas, los cuales recolectan los productos que sus clientes van
necesitando. El sistema que se utiliza en la empresa es desarrollado por equipos de
programadores donde cada equipo se encarga de una tarea específica. Usted forma parte del
equipo de programación que se encargará de hacer el módulo para los preventistas:
Tareas:
Cada preventista puede visitar hasta 5 clientes, los cuales por cuestiones operativas solo
puede pedir hasta 10 productos
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} typedef Producto;

struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos //El tamaño de este arreglo depende de la variable
                        // “CantidadProductosAPedir”
} typedef Cliente;

//Funcioness
float totalDeUnProducto(Producto Estructura) ;

int main(){
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    int CantidadClientes;

    // i)
    Cliente *clientes;
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &CantidadClientes);
    
    clientes = (struct Cliente *)malloc(CantidadClientes * (sizeof(struct Cliente)));
    srand(time(NULL));
    // ii)
    for(int i = 0; i < CantidadClientes; i++) {
        clientes[i].ClienteID = i + 1;
        printf("Ingrese el nombre del cliente: ");
        fflush(stdin); //por ahi
        clientes[i].NombreCliente = (char *) malloc(100 * sizeof(char));
        gets(clientes[i].NombreCliente);
        clientes[i].CantidadProductosAPedir = rand() % 5 + 1;
        clientes[i].Productos = (Producto *)malloc(clientes[i].CantidadProductosAPedir * sizeof(Producto));
            for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
            {
                clientes[i].Productos[j].ProductoID =  j + 1;
                clientes[i].Productos[j].Cantidad = rand() % 10 + 1;
                clientes[i].Productos[j].TipoProducto = TiposProductos[rand() % 5];
                clientes[i].Productos[j].PrecioUnitario = rand() %  91 + 10 ;
            }
            
    }
    
    printf("-----------CLIENTES-----------\n");
    
    float total=0;

    for(int i = 0; i < CantidadClientes; i++) {
        printf("\nID: %d",clientes[i].ClienteID);
        printf("\nNombre: ");
        puts(clientes[i].NombreCliente);
        printf("Cant. produc: %d\n",clientes[i].CantidadProductosAPedir);
        printf("\n----PRODUCTOS-----\n");
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
            {
                printf("\nID del producto: %d", clientes[i].Productos[j].ProductoID);
                printf("\nCantidad de productos: %d", clientes[i].Productos[j].Cantidad);
                printf("\nTipo de producto: ");
                puts(clientes[i].Productos[j].TipoProducto);
                printf("Precio: %.2f \n", clientes[i].Productos[j].PrecioUnitario);
                total += totalDeUnProducto(clientes[i].Productos[j]);
            }
        free(clientes[i].Productos);
        printf("\nTotal a pagar: %f", total);
        printf("\n----------------------------------"
        );  
    }
    
    free(clientes);
    return 0;
}

float totalDeUnProducto(Producto estructura){
    float costo;
    costo = estructura.Cantidad * estructura.PrecioUnitario;
    return costo;
}

