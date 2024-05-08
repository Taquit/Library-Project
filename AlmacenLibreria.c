
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 25
#define MAX_ALMACENES 5
#define MAX_ARTICULOS 50

void printAlmacenes(int ubi, int id[][MAX_ARTICULOS], char titulo[][MAX_ARTICULOS][MAX_LENGTH], char author[][MAX_ARTICULOS][MAX_LENGTH], float precio[][MAX_ARTICULOS], int existencia[][MAX_ARTICULOS], int preorden[][MAX_ARTICULOS], int tipo[][MAX_ARTICULOS], int almacenvec[MAX_ARTICULOS],int idvec[MAX_ARTICULOS]) {
    printf("%-5s | %-25s | %-25s | %-10s | %-12s | %-15s | %-20s \n",
           "ID", "Titulo", "Autor", "Precio", "Existencia",
           "Punto de reorden", "Tipo");
    for (int i = 0; i < ubi; i++) {
        printf("%-5i | %-25s | %-25s | %-10.2f | %-12i | %-16i | ", id[almacenvec[i]][idvec[i]], titulo[almacenvec[i]][idvec[i]], author[almacenvec[i]][idvec[i]], precio[almacenvec[i]][idvec[i]], existencia[almacenvec[i]][idvec[i]], preorden[almacenvec[i]][idvec[i]]);
        //Agregar que imprima almacen

        switch (tipo[almacenvec[i]][idvec[i]]) {
            case 1:
                printf("Pasta dura\n");
                break;
            case 2:
                printf("Pasta blanda\n");
                break;
            case 3:
                printf("Audio libro\n");
                break;
            case 4:
                printf("E-Book\n");
                break;
            default:
                printf("Desconocido\n");
                break;
        }
        switch (almacenvec[i]) {
            case 0:
                printf("Puebla\n");
                break;
            case 1:
                printf("CDMX\n");
                break;
            default:
                printf("Desconocido\n");
                break;
        }
    }
}
void printAutoresLibros(int ubi, int id[][MAX_ARTICULOS], char titulo[MAX_ALMACENES][MAX_ARTICULOS][MAX_LENGTH], char author[MAX_ALMACENES][MAX_ARTICULOS][MAX_LENGTH], float precio[][MAX_ARTICULOS], int existencia[][MAX_ARTICULOS], int preorden[][MAX_ARTICULOS], int tipo[][MAX_ARTICULOS], int opt2, const int idvec[MAX_ARTICULOS]){
    printf("%-5s | %-25s | %-25s | %-10s | %-12s | %-15s | %-20s \\n",
           "ID", "Titulo", "Autor", "Precio", "Existencia",
           "Punto de reorden", "Tipo");
    for (int i = 0; i < ubi; i++) {
        printf("%-5i | %-25s | %-25s | %-10.2f | %-12i | %-16i | ", id[opt2 - 1][idvec[i]], titulo[opt2 - 1][idvec[i]], author[opt2 - 1][idvec[i]], precio[opt2 - 1][idvec[i]], existencia[opt2 - 1][idvec[i]], preorden[opt2 - 1][idvec[i]]);

        switch (tipo[opt2 - 1][idvec[i]]) {
            case 1:
                printf("Pasta dura\n");
                break;
            case 2:
                printf("Pasta blanda\n");
                break;
            case 3:
                printf("Audio libro\n");
                break;
            case 4:
                printf("E-Book\n");
                break;
            default:
                printf("Desconocido\n");
                break;
        }
    }
}
void serchprintID(int opt2, int idtemp, int id[][MAX_ARTICULOS],int num_articulos[], char titulo[MAX_ALMACENES][MAX_ARTICULOS][MAX_LENGTH], char author[MAX_ALMACENES][MAX_ARTICULOS][MAX_LENGTH], float precio[][MAX_ARTICULOS], int existencia[][MAX_ARTICULOS], int preorden[][MAX_ARTICULOS], int tipo[][MAX_ARTICULOS],int bandera){
    if (num_articulos[opt2 - 1] != 0) {
        for (int i = 0; i < num_articulos[opt2 - 1]; ++i) {
            if (idtemp == id[opt2 - 1][i]) {
                bandera = 1;
            }
        }
        if (bandera == 1) {
            printf("%-5s | %-25s | %-25s | %-10s | %-12s | %-15s | %-20s \n",
                   "ID", "Titulo", "Autor", "Precio", "Existencia",
                   "Punto de reorden", "Tipo");

            printf("%-5i | %-25s | %-25s | %-10.2f | %-12i | %-16i | ",
                   id[opt2 - 1][idtemp - 1],
                   titulo[opt2 - 1][idtemp - 1],
                   author[opt2 - 1][idtemp - 1],
                   precio[opt2 - 1][idtemp - 1],
                   existencia[opt2 - 1][idtemp - 1],
                   preorden[opt2 - 1][idtemp - 1]);

            switch (tipo[opt2 - 1][idtemp - 1]) {
                case 1:
                    printf("Pasta dura\n");
                    break;
                case 2:
                    printf("Pasta blanda\n");
                    break;
                case 3:
                    printf("Audio libro\n");
                    break;
                case 4:
                    printf("E-Book\n");
                    break;
                default:
                    printf("Desconocido\n");
                    break;
            }
        } else {
            printf("El ID del libro no existe\n");
        }

    } else {
        printf("El almacen esa vacio\n");
    }
}

int main(){
    //Variables basura
    int bandera=0,idtemp,ubi=0,idvec[MAX_ARTICULOS],almacenvec[MAX_ARTICULOS];
    char trytitulo[MAX_LENGTH];
    //Variables para Switch cases
    int opt1=0,opt2=0,opt3=0,opt4=0;
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
    existencia[0][0] = 5;
    maximo[0][0] = 50;
    pedido[0][0] = 0;
    tipo[0][0] = 1;
    precio[0][0] = 15.99;
    strcpy(titulo[0][0], "GOT");
    strcpy(author[0][0], "Autor1");

    id[0][1] = 2;
    preorden[0][1] = 20;
    existencia[0][1] = 10;
    maximo[0][1] = 50;
    pedido[0][1] = 0;
    tipo[0][1] = 2;
    precio[0][1] = 19.99;
    strcpy(titulo[0][1], "HarryPT");
    strcpy(author[0][1], "Autor1");

    id[0][2] = 3;
    preorden[0][2] = 20;
    existencia[0][2] = 10;
    maximo[0][2] = 50;
    pedido[0][2] = 0;
    tipo[0][2] = 4;
    precio[0][2] = 29.99;
    strcpy(titulo[0][2], "HarryPT");
    strcpy(author[0][2], "Autor2");

    // Incrementar el contador de artículos para el almacén de Puebla
    num_articulos[0] = 3;

    // Inicialización de los datos de los libros para CDMX
    id[1][0] = 1;
    preorden[1][0] = 200;
    existencia[1][0] = 70;
    maximo[1][0] = 120;
    pedido[1][0] = 25;
    tipo[1][0] = 1;
    precio[1][0] = 12.99;
    strcpy(titulo[1][0], "GOT");
    strcpy(author[1][0], "Autor CDMX 1");

    id[1][1] = 2;
    preorden[1][1] = 300;
    existencia[1][1] = 80;
    maximo[1][1] = 120;
    pedido[1][1] = 25;
    tipo[1][1] = 1;
    precio[1][1] = 122.99;
    strcpy(titulo[1][1], "Libro CDMX 1");
    strcpy(author[1][1], "Autor CDMX 2");

    // Incrementar el contador de artículos para el almacén de CDMX
    num_articulos[1] = 2;


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
                            case 2:
                                do {
                                    if(opt2==1){
                                        printf("-----ALMACEN PUEBLA-----\n");
                                    }
                                    if(opt2==2){
                                        printf("-----ALMACEN CDMX-----\n");
                                    }
                                    printf("1)Altas\n2)Ventas \n3)Listar/Buscar\n4)Modificaciones\n5)Reabastecer\n6)Regresar al menu anterior\nEliga opcion:");
                                    scanf("%i",&opt3);
                                    int encontrado = 0;
                                    switch (opt3) {
                                        case 1:
                                            printf("\n\n-----Bienvenido al menu de altas-----\n");
                                            printf("\nIngrese el nombre del libro:");
                                            fflush(stdin); // Limpiar el búfer de entrada
                                            fgets(titulo[opt2-1][num_articulos[opt2-1]], sizeof(titulo[opt2-1][num_articulos[opt2-1]]), stdin);
                                            if (titulo[opt2-1][num_articulos[opt2-1]][strlen(titulo[opt2-1][num_articulos[opt2-1]]) - 1] == '\n') { //Limpiar el ultimo caracter ingresado
                                                titulo[opt2-1][num_articulos[opt2-1]][strlen(titulo[opt2-1][num_articulos[opt2-1]]) - 1] = '\0';
                                            }
                                            printf("\nIngrese el nombre del autor:");
                                            fgets(author[opt2-1][num_articulos[opt2-1]], sizeof(author[0][num_articulos[0]]), stdin);
                                            if (author[opt2-1][num_articulos[opt2-1]][strlen(author[opt2-1][num_articulos[opt2-1]]) - 1] == '\n') { //Limpiar el ultimo caracter ingresado
                                                author[opt2-1][num_articulos[opt2-1]][strlen(author[opt2-1][num_articulos[opt2-1]]) - 1] = '\0';
                                            }
                                            printf("\nIngrese el numero que corresponda al tipo de tapa:\n1.-Pasta Dura\n2.-Pasta Blanda\n3.-Audio libro\n4.-e-book\nOpcion:");
                                            scanf("%d", &tipo[opt2-1][num_articulos[opt2-1]]);
                                            printf("\nIngrese el precio:");
                                            scanf("%f", &precio[opt2-1][num_articulos[opt2-1]]);
                                            printf("\nIngrese la existencia:");
                                            scanf("%d", &existencia[opt2-1][num_articulos[opt2-1]]);
                                            printf("\nIngrese el punto de reorden:");
                                            scanf("%d", &preorden[opt2-1][num_articulos[opt2-1]]);
                                            printf("\nIngrese el maximo:");
                                            scanf("%d", &maximo[opt2-1][num_articulos[opt2-1]]);
                                            id[opt2-1][num_articulos[opt2-1]]=num_articulos[opt2-1]+1;
                                            num_articulos[opt2-1]++;
                                            printf("\n-----Alta exitosa-----\n\n");
                                            break;
                                        case 2:
                                            printf("\n\n-----Ventas-----\n");
                                            int idVenta, cantidadVenta;
                                            printf("Ingrese el ID del producto que desea vender: ");
                                            scanf("%d", &idVenta);
                                            printf("Ingrese la cantidad que desea vender: ");
                                            scanf("%d", &cantidadVenta);
                                            // Verificar si el producto está en el inventario
                                            for (int i = 0; i < num_articulos[opt2 - 1]; i++)
                                            {
                                                if (idVenta == id[opt2 - 1][i])
                                                {
                                                    encontrado = 1;
                                                    if (existencia[opt2 - 1][i] >= cantidadVenta)
                                                    {
                                                        // Actualizar la existencia del producto
                                                        existencia[opt2 - 1][i] -= cantidadVenta;
                                                        printf("Venta realizada correctamente.\n");
                                                    }
                                                    else
                                                    {
                                                        printf("No hay suficiente cantidad en el inventario.\n");
                                                    }
                                                    // No hay salto aquí
                                                }
                                            }
                                            if (!encontrado)
                                            {
                                                printf("El ID del producto no existe en el inventario.\n");
                                            }
                                            break;
                                        case 3:
                                            do {
                                                printf("\n-----Listar/Buscar-----\n");
                                                printf("1)Listar todo\n2)Buscar por ID\n3)Buscar por nombre de libro\n4)Buscar por autor\n5)Buscar en todos los almacenes\n6)Salir\nEliga opcion:");
                                                scanf("%i",&opt4);
                                                switch (opt4) {
                                                    case 1:
                                                        printf("\n-----Listar Todo-----\n");
                                                        if (num_articulos[opt2 - 1] != 0) {
                                                            printf("%-5s | %-25s | %-25s | %-10s | %-12s | %-15s | %-20s \n",
                                                                   "ID", "Titulo", "Autor", "Precio", "Existencia",
                                                                   "Punto de reorden", "Tipo");
                                                            for (int i = 0; i < num_articulos[opt2 - 1]; i += 10) {
                                                                int end = (i + 10 < num_articulos[opt2 - 1]) ? i + 10
                                                                                                             : num_articulos[
                                                                                  opt2 - 1];
                                                                for (int j = i; j < end; j++) {//ID: %i|Titulo: %s|Author: %s|Precio: %.2f|Existencia: %i|Punto de reorden: %i|Tipo:%-5i | %-25s | %-25s | %-10.2f | %-12i | %-15i |
                                                                    printf("%-5i | %-25s | %-25s | %-10.2f | %-12i | %-16i | ",
                                                                           id[opt2 - 1][j], titulo[opt2 - 1][j], author[opt2 - 1][j], precio[opt2 - 1][j],
                                                                           existencia[opt2 - 1][j], preorden[opt2 - 1][j]);

                                                                    switch (tipo[opt2 - 1][j]) {
                                                                        case 1:
                                                                            printf("Pasta dura\n");
                                                                            break;
                                                                        case 2:
                                                                            printf("Pasta blanda\n");
                                                                            break;
                                                                        case 3:
                                                                            printf("Audio libro\n");
                                                                            break;
                                                                        case 4:
                                                                            printf("E-Book\n");
                                                                            break;
                                                                        default:
                                                                            printf("Tipo desconocido\n");
                                                                            break;
                                                                    }
                                                                }
                                                                if (end < num_articulos[opt2 - 1]) {
                                                                    printf("Presione Enter para ver mas productos...\n");
                                                                    fflush(stdin);
                                                                    while (getchar() != '\n');
                                                                }
                                                            }
                                                        } else {
                                                            printf("El almacen esta vacio\n");
                                                        }
                                                        break;
                                                    case 2:
                                                        bandera = 0;
                                                        printf("-----Buscar por ID-----\n");
                                                        printf("Ingrese el ID del producto que dese bsucar:");
                                                        scanf("%i", &idtemp);
                                                        serchprintID(opt2, idtemp, id,num_articulos, titulo,author,precio, existencia,preorden,tipo,bandera);

                                                        break;
                                                    case 3:
                                                        bandera = 0;
                                                        ubi = 0;
                                                        //limpiarVector(idvec, MAX_ARTICULOS, 0);
                                                        printf("-----Buscar por nombre de libro-----\n");
                                                        printf("Ingrese el nombre del libro que dese buscar:");
                                                        fflush(stdin);
                                                        fgets(trytitulo, sizeof(trytitulo), stdin);
                                                        if (trytitulo[strlen(trytitulo) - 1] ==
                                                            '\n') { //Limpiar el ultimo caracter ingresado
                                                            trytitulo[strlen(trytitulo) - 1] = '\0';
                                                        }

                                                        for (int i = 0; i < num_articulos[opt2 - 1]; ++i) {
                                                            if (strcmp(trytitulo, titulo[opt2 - 1][i]) == 0) {
                                                                bandera = 1;
                                                                idvec[ubi++] = i;

                                                            }
                                                        }

                                                        if (bandera != 0) {
                                                            printAutoresLibros(ubi, id, titulo, author, precio, existencia, preorden, tipo, opt2, idvec);
                                                        } else {
                                                            printf("No lo tenemos\n");
                                                        }
                                                        break;
                                                    case 4:
                                                        bandera = 0;
                                                        ubi = 0;
                                                        //limpiarVector(idvec, MAX_ARTICULOS, 0);
                                                        printf("-----Buscar por autor-----\n");
                                                        printf("Ingrese el nombre del autor que dese buscar:");
                                                        fflush(stdin);
                                                        fgets(trytitulo, sizeof(trytitulo), stdin);
                                                        if (trytitulo[strlen(trytitulo) - 1] ==
                                                            '\n') { //Limpiar el ultimo caracter ingresado
                                                            trytitulo[strlen(trytitulo) - 1] = '\0';
                                                        }
                                                        for (int i = 0; i < num_articulos[opt2 - 1]; ++i) {
                                                            if (strcmp(trytitulo, author[opt2 - 1][i]) == 0) {
                                                                bandera = 1;
                                                                idvec[ubi] = i;

                                                                ubi++;
                                                            }
                                                        }

                                                        if (bandera != 0) {
                                                            printAutoresLibros(ubi, id, titulo, author, precio, existencia, preorden, tipo, opt2, idvec);
                                                        } else {
                                                            printf("No lo tenemos\n");
                                                        }
                                                        break;
                                                    case 5:
                                                        bandera = 0;
                                                        ubi = 0;
                                                        printf("----Buscar en todos los almacenes-----\n");
                                                        printf("Ingresa autor o titulo del libro:");
                                                        fflush(stdin);
                                                        fgets(trytitulo, sizeof(trytitulo), stdin);
                                                        if (trytitulo[strlen(trytitulo) - 1] ==
                                                            '\n') { //Limpiar el ultimo caracter ingresado
                                                            trytitulo[strlen(trytitulo) - 1] = '\0';
                                                        }
                                                        for (int i = 0; i < MAX_ALMACENES; ++i) {
                                                            for (int j = 0; j < num_articulos[i]; ++j) {
                                                                if (strcmp(trytitulo, author[i][j]) == 0||strcmp(trytitulo, titulo[i][j])==0) {
                                                                    bandera = 1;
                                                                    idvec[ubi] = j;
                                                                    almacenvec[ubi]=i;
                                                                    ubi++;
                                                                }
                                                            }
                                                        }
                                                        if (bandera != 0) {
                                                            printAlmacenes(ubi, id, titulo, author, precio, existencia, preorden, tipo, almacenvec,idvec);

                                                        } else {
                                                            printf("No lo tenemos\n");
                                                        }
                                                        break;
                                                    case 6:
                                                        printf("Saliendo del menu 3...\n");
                                                        break;
                                                    default:
                                                        printf("<----->Ingresaste una opcion incorrecta<----->\n");
                                                        break;
                                                }
                                            } while (opt4!=6);
                                            break;
                                        case 4:
                                            printf("-----Modificaciones-----\n");
                                            break;
                                        case 5:
                                            printf("-----Reabastecer-----\n");
                                            int	maybe = 0,existencia_temp;
                                            bandera=0;
                                            for (int i = 0;i< num_articulos[opt2 - 1]; i++) {

                                                if (existencia[opt2 - 1][i] < preorden[opt2 - 1][i]) {
                                                    bandera = 1;
                                                    idvec[ubi] = i;
                                                    ubi++;
                                                }
                                            }
                                            if (bandera == 1){

                                                for (int i = 0;i < ubi; i++){
                                                    existencia_temp = maximo[opt2-1][i]-existencia[opt2-1][i];
                                                    printf("ID: %i|Titulo: %s|Existencia: %i| \n", id[opt2-1][i], titulo[opt2-1][i], existencia_temp);
                                                    printf("Quieres reabastecer?\n 1. Si\n 2. No\n");
                                                    printf("Elegir opcion:");
                                                    scanf("%i", &maybe);
                                                    if(maybe == 1){
                                                        existencia[opt2-1][i] = existencia_temp + existencia[opt2-1][i];
                                                        printf("Si se reabastecio\n");
                                                    }else{
                                                        printf("No se reabastecio\n");
                                                    }

                                                }

                                            }else{
                                                printf("No hay nada que reabastecer\n");
                                            }




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
                            case 3:
                                printf("-----Regresar al menu anterior-----\n");
                                break;
                            default:
                                printf("<----->Ingresaste una opcion incorrecta<----->\n");
                                break;

                        }
                    } while (opt2!=3);

                    break;
                case 2:
                    printf("Estas saliendo del progrma...\n");
                    break;
                default:
                    printf("<----->Ingresaste una opcion incorrecta<----->\n");
                    break;
            }
        } while (opt1!=2);
    return 0;
}
