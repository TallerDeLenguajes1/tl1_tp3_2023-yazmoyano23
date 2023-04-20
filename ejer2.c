#include <stdio.h>
#include<stdlib.h>
#include<time.h>


int main(){

    float ganancias[5][12];
    float suma = 0, promedio = 0;
    srand(time(NULL));

    for (int i = 0; i < 5; i++)
    {
       for (int j = 0; j < 12; j++)
       {
            ganancias[i][j] = rand() %  40001 + 10000 ;
            printf("%.2f ", ganancias[i][j]);
       }

       printf("\n");
    }


    //Promedio por año   
    for (int i = 0; i < 5; i++)
    {
       for (int j = 0; j < 12; j++)
       {
            suma = suma + ganancias[i][j];
       }

       promedio = suma / 12;
       printf("\nPromedio Anio %d: %.2f", i+1, promedio);
       suma = 0;
    }

    //Maxima y minima ganancia 
    int max_i = 0, max_j = 0, min_i = 0, min_j = 0;

    for (int i = 0; i < 5; i++)
    {
       for (int j = 0; j < 12; j++)
       {
            if (ganancias[i][j] > ganancias[max_i][max_j])
            {
                max_i = i;
                max_j = j;
            }

            if (ganancias[i][j] < ganancias[min_i][min_j])
            {
                min_i = i;
                min_j = j;
            }
            
       }

    }

    printf("\nMaxima ganancia: %.2f", ganancias[max_i][max_j]);
    printf("\nMinima ganancia: %.2f", ganancias[min_i][min_j]);

    return 0;
}