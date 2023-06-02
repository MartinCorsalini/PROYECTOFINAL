#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

typedef struct
{
    char calle[30];
    int altura;
    int piso;
    int dpto;
} direccion;

typedef struct
{
    direccion domicilio;
    char estado[20];             //disponible o no.
    int precio;
    char fechaIngreso[11];
    char ventaAlquiler[30];     // se alquila o se vende.
    int cantAmbientes;
    int mtsTotales;
    char zona[50];          // donde se encuentra ubicado.
    char descripInmueble;   // una pequeña descripcion.
} inmueble;

/// Prototipados

void muestraUnaPropiedad(inmueble casa);
void cargaDatosInmuebles(char propiedades[]);
void muestraPropiedad(char casa[]);

int main()
{
    char seguir;

    printf("Desea ingresar un inmueble? \n");
    fflush(stdin);
    scanf("%c", &seguir);

    while ( seguir == 's')
    {
        //Cargar Inmuebles
        cargaDatosInmuebles("Propiedades1.info");
    }


    //Mostrarlos
    muestraPropiedad("Propiedades1.info");

    return 0;
}



void cargaDatosInmuebles(char propiedades[])
{
    inmueble datos;
    FILE *archi;
    char eleccion='s';

    archi=fopen(propiedades,"ab");

    if(archi!= NULL)
    {
        while(eleccion=='s')
        {

            printf("Ingrese los datos del inmueble.\n");

            ///DOMICILIO
            // calle
            printf("Calle.\n");
            fflush(stdin);
            gets(datos.domicilio.calle);

            // altura
            printf("Ingrese la altura.\n");
            scanf("%d",&datos.domicilio.altura);

            // piso
            printf("Ingrese el piso.\n");
            scanf("%d",&datos.domicilio.piso);

            // Departamento
            printf("Ingrese el departamento.\n");
            scanf("%c",&datos.domicilio.dpto);

            ///OTROS DATOS
            //Estado
            printf("Ingrese el estado del inmueble.\n");
            fflush(stdin);
            gets(datos.estado);

            // Precio
            printf("Ingrese el precio en pesos $.\n");
            scanf("%d",&datos.precio);

            // Fecha de ingreso
            printf("Ingrese la fecha de ingreso.\n");
            scanf("%d",&datos.precio);

            // Venta o alquiler?
            printf("Indique si es para venta o alquiler.\n");
            fflush(stdin);
            gets(datos.ventaAlquiler);

            // Cantidad de ambientes
            printf("Ingrese la cantidad de ambientes.\n");
            scanf("%d",&datos.cantAmbientes);

            // Metros cuadrados
            printf("Ingrese los metros cuadrados totales.\n");
            scanf("%d",&datos.mtsTotales);

            // Zona
            printf("Ingrese la zona donde se encuentra ubicado.\n");
            fflush(stdin);
            gets(datos.zona);

            // Descripcion
            printf("Ingrese una breve descripcion del inmueble.\n");
            fflush(stdin);
            gets(datos.descripInmueble);

            //Cargamos la info al archivo
            fwrite(&datos,sizeof(datos),1,archi);

            //Seguir?
            printf("¿Quiere agregar otro inmueble? S/N \n");
            fflush(stdin);
            scanf("%c",&eleccion);
            system("cls");

        }
        fclose(archi);
    }

}

void muestraPropiedad(char casa[])
{
    FILE *archi= fopen(casa,"rb");
    inmueble datos;

    if(archi)
    {
        while(fread(&datos,sizeof(inmueble),1,archi)>0);
        {
            muestraUnaPropiedad(datos);
        }
    }

    fclose(archi);
}

void muestraUnaPropiedad(inmueble casa)
{
    printf("Calle--------------------: %s \n",casa.domicilio.calle);
    printf("Altura-------------------: %i \n",casa.domicilio.altura);
    printf("Piso---------------------: %i \n",casa.domicilio.piso);
    printf("Departamento-------------: %c \n",casa.domicilio.dpto);
    printf("Estado del inmueble------: %s \n",casa.estado);
    printf("Precio en pesos----------: %d \n",casa.precio);
    printf("Fecha de ingreso---------: %d \n",casa.fechaIngreso);
    printf("Venta o Alquiler---------: %s \n",casa.ventaAlquiler);
    printf("Cantidad de ambientes----: %i \n",casa.cantAmbientes);
    printf("Metros cuadrados---------: %i \n",casa.mtsTotales);
    printf("Ubicacion----------------: %s \n",casa.zona);
    printf("Descripcion--------------: %s \n",casa.descripInmueble);
}

void verificacion ()
{
    if()


}
