#include <stdio.h>
#include <stdlib.h>
void registrarCorredores(int* numeros, char* categorias, int* cantCorredores)
{
    int numero;
    char categoria;

    printf("INGRESE EL NUMERO DE PECHERA (0 PARA SALIR): ");
    scanf("%d",&numero);
    while(*cantCorredores<100 && numero!=0)
    {
        fflush(stdin);
        printf("INGRESE LA CATEGORIA (A-E)");
        scanf("%c",&categoria);
        fflush(stdin);

        numeros[*cantCorredores] = numero;
        categorias[*cantCorredores]= categoria;
        *cantCorredores+=1;

        printf("INGRESE EL NUMERO DE PECHERA (0 PARA SALIR): ");
        scanf("%d",&numero);
    }
}

void calcularGanadores(int* numeros, char* categorias, int cantCorredores){
char categoriasGanadores[5] = {'A','B','C','D','E'};
int ganadores [5]={0};
    for(int i=0;i<cantCorredores;i++)
    {
        for(int j=0;j<5;j++){
            if(categorias[i]==categoriasGanadores[j]){
                if(ganadores[5]==0){
                    ganadores[j] = numeros[i];
                }
            }
        }
    }

    for(int i = 0; i<5;i++){
        printf("CATEGORIA %c - GANADOR: ", categoriasGanadores[i]);
        printf("%d\n",ganadores[i]);
    }
}
int main()
{
    int opcion, cantCorredores=0;
    int numPechera[100];
    char catCorredor[100];

    do
    {
        printf("---SISTEMA DE COMPETENCIAS DE ATLETISMO---\n\n");
        printf("1. REGISTRAR CORREDORES QUE LLEGARON A LA META\n");
        printf("2. CALCULAR LOS GANADORES DE CADA CATEGORIA\n");
        printf("3. SALIR\n");
        printf("\n INGRESE UNA OPCION: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            registrarCorredores(numPechera,catCorredor,&cantCorredores);
            break;
        case 2:
            calcularGanadores(numPechera,catCorredor,cantCorredores);
            break;
        case 3:
            printf("SALIENDO DEL PROGRAMA...\n");
            break;
        default:
            printf("NO SE RECONOCE EL COMANDO. VUELVA A INGRESAR UNA OPCION VALIDA...\n");
            break;
        }

    }
    while(opcion!=3);
    return 0;
}
