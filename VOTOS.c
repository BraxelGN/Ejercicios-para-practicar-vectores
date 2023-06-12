#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_VOTOS 100
/*
Se desea realizar una aplicación para unas elecciones de gobernador.
El sistema será utilizado por cada votante para registrar su elección.
El programa tiene un menú con las siguientes opciones:
1 – Votar.
2 – Mostrar resultados.
3 – Salir.

Al iniciar el programa, el presidente de mesa deberá ingresar su usuario (alfanumérico 10 posiciones) y clave (numérica). Hacer la validación de clave correspondiente.
Crear una función menú, que ingrese opción y devuelva la misma al programa principal.
Opción 1 – Votar.
Ingresar por teclado los datos de una votación: DNI (valor entero) y Candidato Elegido (valor char). Los candidatos son:
	‘A’ – Ironman.
	‘B’ – Capitan America.
	‘C’ – Hulk.

Llamar a una función que tenga como parámetros los datos ingresados por teclado y dos vectores y guarde dichos datos en los dos vectores respectivamente.

Opción 2 – El programa debe mostrar el candidato ganador.
Llamar a una función que reciba los 2 vectores armados en la opción 1 como parámetros y calcule el candidato ganador.
Nota: para calcular el candidato ganador hay que contar cuántos votos tiene cada uno y el candidato de máxima cantidad de votos será el ganador.
La función deberá devolver al programa principal el candidato ganador.
En el programa principal se debe mostrar el candidato ganador (letra y nombre).
Utilizar aritmética de punteros.

Opción 3 – Salir

No se pueden utilizar variables globales.  Mostrar por pantalla de forma clara y prolija.*/
void validarUsuario(char *user, int password){
    int s=0;
    printf("INGRESE NOMBRE DE USUARIO: ");
    fflush(stdin);
    scanf("%s",user);
    do{
        printf("\nINGRESE CONTRASE%cA: ",165);
        scanf("%d",&password);
        if(s==1){
            printf("CONTRASE%cA INCORRECTA\n",165);
        }
        s=1;
    }while(password!=1234);
}
void registrarVoto(int *p_DNI, char *p_VOTO, int voto){
    int dni;
    char opcVoto;
    printf("REGISTRANDO VOTO...\n\n");
    printf("INGRESE SU DNI: ");
    scanf("%d",&dni);
    printf("\nA QUE CANDIDATO VA A VOTAR?:");
    printf("\n A. IRON MAN\n B. CAPITAN AMERICA \n C. HULK");
    printf("\nINGRESE SU OPCION: ");
    fflush(stdin);
    scanf("%c",&opcVoto);
    *(p_DNI+voto)=dni;
    *(p_VOTO+voto)=opcVoto;

    printf("VOTO REGISTRADO!\n\n");
}

void calcularGanador(int *p_DNI,char *p_VOTO,int votos, char *p_candidatoGanador){
    system("cls");
    int i;
    printf("CALCULANDO GANADOR...\n\n");
    int candA=0,candB=0,candC=0;

    for(i=0;i<votos;i++){
        if(*(p_VOTO+i)=='a'){
            candA++;
        }
        else if(*(p_VOTO+i)=='b'){
            candB++;
        }
        else if(*(p_VOTO+i)=='c'){
            candC++;
        }
        else{

        }
    }

    if(candA>candB && candA>candC){
        *p_candidatoGanador = 'a';
    }
    else if(candB > candA && candB >candC){
        *p_candidatoGanador = 'b';
    }
    else if(candC>candA && candC>candB)
    {
        *p_candidatoGanador ='c';
    }
    else{
        printf("TODAVIA NO HAY UN GANADOR...\n\n");
    }
}
int main()
{
    int opcion,password,cantVoto=0;
    int DNI[MAX_VOTOS];
    char voto[MAX_VOTOS],usuario[10],candidatoGanador;
    validarUsuario(&usuario,password);
    system("cls");
    do
    {
        system("cls");
        printf("BIENVENIDO PRESIDENTE %s",&usuario);
        printf("\n\nELECCIONES\n\nMENU");
        printf("\n1. VOTAR\n");
        if(cantVoto>0)
        printf("2. MOSTRAR RESULTADOS\n");
        printf("3. SALIR\n");
        printf("\n Seleccione una opcion: ");
        scanf("%d",&opcion);

        switch(opcion){
        case 1:
            registrarVoto(DNI,voto,cantVoto);
            cantVoto++;
            break;
        case 2:
            calcularGanador(DNI,voto,cantVoto,&candidatoGanador);
            printf("GANADOR DE LA CONTIENDA: ");
            printf("\n\nGANADOR CANDIDATO %c ",candidatoGanador);
            switch(candidatoGanador){
            case 'a':
                printf("IRON MAN\n ");
                break;
            case 'b':
                printf("CAPITAN AMERICA\n");
                break;
            case 'c':
                printf("HULK\n");
                break;
            }
            printf("\n");
            system("pause");
            break;
            case 3:
                printf("\n\nSALIENDO DEL PROGRAMA...");
                break;
            default:
                printf("OPCION INCORRECTA...  INGRESE UNA OPCION VALIDA");
                break;
        }

    }while(opcion!=3);
    return 0;
}
