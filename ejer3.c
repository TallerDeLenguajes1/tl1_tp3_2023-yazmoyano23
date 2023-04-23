/*
    Escriba un programa que solicite 5 nombres, los cargue en un vector de punteros char y una
    vez cargados los liste por pantalla (Todo implementando reserva dinámica de memoria) (Lea
    las notas 1 y 2)
*/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){
    char *nombres[5]; //Arreglo de punteros
    char *buff; //variable auxiliar
    char *nombre;

    for (int i = 0; i < 5; i++)
    {
        buff = (char *) malloc(100 * sizeof(char));
        printf("\nIngrese un nombre: ");
        gets(buff);

        nombre = (char *) malloc( (strlen(buff) + 1) * sizeof(char) ); //Pos
        strcpy(nombre,buff);

        nombres[i] = nombre;

    }

    printf("\n------Nombres-----\n");
    for (int i = 0; i < 5; i++)
    {
        puts(nombres[i]);
    }
    
    free(buff);
    free(nombre);

    return 0;
}