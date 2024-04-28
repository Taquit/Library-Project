
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 25
#define MAX_ALMACENES 5
#define MAX_ARTICULOS 50

int main(){
    //Variables basura
    int bandera=0;
    //Variables para Switch cases
    int opt1=0,opt2=0,opt3=0;
    //Usuario y Contraseña
    char user[][MAX_LENGTH]={"Ruben03","Other user"};
    char password[][MAX_LENGTH]={"Gato123","Other pass"};
    char trypassword[MAX_LENGTH];
    char tryuser[MAX_LENGTH];
    //Vectores
    char nombreAlmacenes[MAX_ALMACENES][MAX_LENGTH]={"Puebla", "CDMX"};
    int id[MAX_ALMACENES][MAX_ARTICULOS];
    int preorden[MAX_ALMACENES][MAX_ARTICULOS];
    int existencia[MAX_ALMACENES][MAX_ARTICULOS];
    int maximo[MAX_ALMACENES][MAX_ARTICULOS];
    int pedido[MAX_ALMACENES][MAX_ARTICULOS];
    int num_articulos[MAX_ALMACENES] = {0};
    int tipo[MAX_ALMACENES][MAX_ARTICULOS];//Tipo 1=Pasta dura 2=Blandos 3=Audio Libro 4=E-Book
    float precio[MAX_ALMACENES][MAX_ARTICULOS];
    char titulo[MAX_ALMACENES][MAX_ARTICULOS][MAX_LENGTH],author[MAX_ALMACENES][MAX_ARTICULOS][MAX_LENGTH];

    // Inicialización de los datos de los libros para Puebla
    id[0][0] = 1;
    preorden[0][0] = 20;
    existencia[0][0] = 10;
    maximo[0][0] = 50;
    pedido[0][0] = 0;
    tipo[0][0] = 1;
    precio[0][0] = 15.99;
    strcpy(titulo[0][0], "Libro Puebla 1");
    strcpy(author[0][0], "Autor Puebla 1");

    id[0][1] = 2;
    preorden[0][1] = 20;
    existencia[0][1] = 10;
    maximo[0][1] = 50;
    pedido[0][1] = 0;
    tipo[0][1] = 2;
    precio[0][1] = 19.99;
    strcpy(titulo[0][1], "Libro Puebla 2");
    strcpy(author[0][1], "Autor Puebla 2");

    // Incrementar el contador de artículos para el almacén de Puebla
    num_articulos[0] = 2;

    // Inicialización de los datos de los libros para CDMX
    id[1][0] = 1;
    preorden[1][0] = 200;
    existencia[1][0] = 70;
    maximo[1][0] = 120;
    pedido[1][0] = 25;
    tipo[1][0] = 1;
    precio[1][0] = 12.99;
    strcpy(titulo[1][0], "Libro CDMX 1");
    strcpy(author[1][0], "Autor CDMX 1");

    // Incrementar el contador de artículos para el almacén de CDMX
    num_articulos[1] = 1;


        do {
            printf("1)Iinciar sesion\n2)Salir del almacen\nEliga opcion:");
            scanf("%i",&opt1);
            switch (opt1) {
                case 1:
                    printf("User:");
                    fflush(stdin); // Limpiar el búfer de entrada
                    fgets(tryuser, sizeof(tryuser), stdin);
                    if (tryuser[strlen(tryuser) - 1] == '\n') { //Limpiar el ultimo caracter ingresado
                        tryuser[strlen(tryuser) - 1] = '\0';
                    }
                    printf("Password:");

                    fflush(stdin);// Limpiar el búfer de entrada
                    fgets(trypassword, sizeof(trypassword), stdin);
                    if (trypassword[strlen(trypassword) - 1] == '\n') { //Limpiar el ultimo caracter ingresado
                        trypassword[strlen(trypassword) - 1] = '\0';
                    }
                    for (int i = 0; i < sizeof (user); ++i) {
                        if(strcmp(trypassword, password[i]) == 0 && strcmp(tryuser, user[i]) == 0 ){
                            bandera=1;
                            break;
                        }
                    }
                    if(bandera==0){
                        printf("La password o user son incorrectos\n");
                        break;
                    }
                    do {
                        printf("-----ELIGA ALMACEN-----\n1)Almacen Pubela\n2)Almacen CDMX\n3)Regresar al menu anterior\nEliga opcion:");
                        scanf("%i",&opt2);
                        switch (opt2) {
                            case 1:
                                printf("-----ELIGA OPCION-----\n-----ALMACEN PUEBLA-----\n");

                                do {
                                    printf("1)Altas\n2)Venetas x\n3)Listar\n4)Modificaciones\n5)Reabastecer\n6)Regresar al menu anterior\nEliga opcion:");
                                    scanf("%i",&opt3);
                                    switch (opt3) {
                                        case 1:
                                            printf("-----Altas-----\n");
                                            break;
                                        case 2:
                                            printf("-----Venetas-----\n");
                                            break;
                                        case 3:
                                            printf("-----Listar/Buscar-----\n");
                                            break;
                                        case 4:
                                            printf("-----Modificaciones-----\n");
                                            break;
                                        case 5:
                                            printf("-----Reabastecer-----\n");
                                            break;
                                        case 6:
                                            printf("Regresando al menu anterior\n");
                                            break;
                                        default:
                                            printf("<----->Ingresaste una opcion incorrecta<----->\n");
                                            break;
                                    }
                                } while (opt3!=6);
                                break;
                            case 2:
                                printf("-----Almacen CDMX-----\n");
                                break;
                            case 3:
                                printf("-----Regresar al menu anterior-----\n");
                                break;
                            default:
                                printf("<----->Ingresaste una opcion incorrecta<----->\n");
                                break;

                        }
                    } while (opt2!=1);

                    break;
                case 2:
                    printf("Estas saliendo del progrma...");
                    break;
                default:
                    printf("<----->Ingresaste una opcion incorrecta<----->\n");
                    break;
            }
        } while (opt1!=2);
    return 0;
}