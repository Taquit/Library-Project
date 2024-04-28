
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 25
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
    int id[26],preorden[26],existencia[26],maximo[26],pedido[26],total=0;
    float precio[26];
    char titulo[26][MAX_LENGTH],author[26],tipo[26];

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
                        printf("1)Almacen 1\n2)Almacen x\n)Salir\nEliga opcion:");
                        scanf("%i",&opt2);
                        switch (opt2) {
                            case 1:
                                do {
                                    printf("1)Altas\n2)Venetas x\n3)Listar\n4)Modificaciones\n5)Reabastecer\n6)Salir\nEliga opcion:");
                                    scanf("%i",&opt3);
                                    switch (opt2) {
                                        case 1:
                                            printf("-----Altas-----");
                                            break;
                                        case 2:
                                            printf("-----Venetas-----");
                                            break;
                                        case 3:
                                            printf("-----Listar-----");
                                            break;
                                        case 4:
                                            printf("-----Modificaciones-----");
                                            break;
                                        case 5:
                                            printf("-----Reabastecer-----");
                                            break;
                                        case 6:
                                            printf("Saliendo al menu principal...");
                                            break;
                                        default:
                                            printf("<----->Ingresaste una opcion incorrecta<----->\n");
                                            break;
                                    }
                                } while (opt3!=6);
                                break;
                            case 2:
                                printf("-----Vnetas-----");
                                break;
                            case 3:
                                printf("-----Listar-----");
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