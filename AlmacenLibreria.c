
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 25
int main(){
    //Variables basura
    int bandera=0;
    //Variables para Switch cases
    int opt1=0,opt2=0;
    //Usuario y Contraseña
    char user[][MAX_LENGTH]={"Ruben03","Other user"};
    char password[][MAX_LENGTH]={"Gato123","Other pass"};
    char trypassword[MAX_LENGTH];
    char tryuser[MAX_LENGTH];

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
                    fflush(stdin); // Limpiar el búfer de entrada
                    fgets(trypassword, sizeof(trypassword), stdin);
                    if (trypassword[strlen(trypassword) - 1] == '\n') { //Limpiar el ultimo caracter ingresado
                        trypassword[strlen(trypassword) - 1] = '\0';
                    }
                    for (int i = 0; i < sizeof (user); ++i) {
                        if(strcmp(trypassword, password[i]) == 0 || strcmp(tryuser, user[i]) == 0 ){
                            bandera=1;
                            break;
                        }
                    }
                    if(bandera==0){
                        printf("La password o user son incorrectos\n");
                    } else{
                        printf("TODOO BIEENN\n");
                    }
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