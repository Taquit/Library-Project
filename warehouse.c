#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LENGTH 25
#define MAX_ALMACENES 5
#define MAX_ARTICULOS 50
void convertirMayusculas(char *cadena)
{
    int i;
    for (i = 0; cadena[i]; i++)
    {
        cadena[i] = toupper(cadena[i]);
    }
}
void printAlmacenes(int ubi, int id[][MAX_ARTICULOS], char titulo[][MAX_ARTICULOS][MAX_LENGTH], char author[][MAX_ARTICULOS][MAX_LENGTH], float precio[][MAX_ARTICULOS], int existencia[][MAX_ARTICULOS], int preorden[][MAX_ARTICULOS], int tipo[][MAX_ARTICULOS], int almacenvec[MAX_ARTICULOS], int idvec[MAX_ARTICULOS])
{
    printf("%-5s | %-25s | %-25s | %-10s | %-12s | %-15s | %-20s|%-20s \n",
           "ID", "Title", "Author", "Price", "Existence",
           "Reorder point", "Type", "Warehouse");
    for (int i = 0; i < ubi; i++)
    {
        printf("%-5i | %-25s | %-25s | %-10.2f | %-12i | %-16i | ", id[almacenvec[i]][idvec[i]], titulo[almacenvec[i]][idvec[i]], author[almacenvec[i]][idvec[i]], precio[almacenvec[i]][idvec[i]], existencia[almacenvec[i]][idvec[i]], preorden[almacenvec[i]][idvec[i]]);
        // Agregar que imprima almacen

        switch (tipo[almacenvec[i]][idvec[i]])
        {
        case 1:
            printf("%-20s |", "Hardcover");
            break;
        case 2:
            printf("%-20s |", "Paperback");
            break;
        case 3:
            printf("%-20s |", "Audiobook");
            break;
        case 4:
            printf("%-20s |", "E-Book");
            break;
        default:
            printf("Unknown");
            break;
        }
        switch (almacenvec[i])
        {
        case 0:
            printf("Puebla\n");
            break;
        case 1:
            printf("Mexico City\n");
            break;
        default:
            printf("Unknown\n");
            break;
        }
    }
}
void printAutoresLibros(int ubi, int id[][MAX_ARTICULOS], char titulo[MAX_ALMACENES][MAX_ARTICULOS][MAX_LENGTH], char author[MAX_ALMACENES][MAX_ARTICULOS][MAX_LENGTH], float precio[][MAX_ARTICULOS], int existencia[][MAX_ARTICULOS], int preorden[][MAX_ARTICULOS], int tipo[][MAX_ARTICULOS], int opt2, const int idvec[MAX_ARTICULOS])
{
    printf("%-5s |%-25s |%-25s |%-10s |%-12s |%-15s |%-20s \n",
           "ID", "Title", "Author", "Price", "Existence",
           "Reorder point", "Type");
    for (int i = 0; i < ubi; i++)
    {
        printf("%-5i |%-25s |%-25s |%-10.2f |%-12i |%-15i | ", id[opt2 - 1][idvec[i]], titulo[opt2 - 1][idvec[i]], author[opt2 - 1][idvec[i]], precio[opt2 - 1][idvec[i]], existencia[opt2 - 1][idvec[i]], preorden[opt2 - 1][idvec[i]]);

        switch (tipo[opt2 - 1][idvec[i]])
        {
        case 1:
            printf("Hardcover\n");
            break;
        case 2:
            printf("Paperback\n");
            break;
        case 3:
            printf("Audiobook\n");
            break;
        case 4:
            printf("E-Book\n");
            break;
        default:
            printf("Unknown\n");
            break;
        }
    }
}
int serchprintID(int opt2, int idtemp, int id[][MAX_ARTICULOS], int num_articulos[], char titulo[MAX_ALMACENES][MAX_ARTICULOS][MAX_LENGTH], char author[MAX_ALMACENES][MAX_ARTICULOS][MAX_LENGTH], float precio[][MAX_ARTICULOS], int existencia[][MAX_ARTICULOS], int preorden[][MAX_ARTICULOS], int tipo[][MAX_ARTICULOS], int bandera)
{
    if (num_articulos[opt2 - 1] != 0)
    {
        for (int i = 0; i < num_articulos[opt2 - 1]; ++i)
        {
            if (idtemp == id[opt2 - 1][i])
            {
                bandera = 1;
            }
        }
        if (bandera == 1)
        {
            printf("%-5s |%-25s |%-25s |%-10s |%-12s |%-15s |%-20s \n", "ID", "Title", "Author", "Price", "Existence", "Reorder point", "Type");

            printf("%-5i |%-25s |%-25s |%-10.2f |%-12i |%-15i | ",
                   id[opt2 - 1][idtemp - 1],
                   titulo[opt2 - 1][idtemp - 1],
                   author[opt2 - 1][idtemp - 1],
                   precio[opt2 - 1][idtemp - 1],
                   existencia[opt2 - 1][idtemp - 1],
                   preorden[opt2 - 1][idtemp - 1]);

            switch (tipo[opt2 - 1][idtemp - 1])
            {
            case 1:
                printf("Hardcover\n");
                break;
            case 2:
                printf("Paperback\n");
                break;
            case 3:
                printf("Audiobook\n");
                break;
            case 4:
                printf("E-Book\n");
                break;
            default:
                printf("Unknown\n");
                break;
            }
        }
        else
        {
            printf("Book ID does not exist\n");
        }
    }
    else
    {
        printf("The warehouse is empty\n");
    }
    return bandera;
}

int main()
{
    // Variables basura
    int bandera = 0, idtemp, ubi = 0, idvec[MAX_ARTICULOS], almacenvec[MAX_ARTICULOS];
    char trytitulo[MAX_LENGTH];
    // Variables de Rodo
    int opc = 0, opp = 0, tipotemp = 0, tipod;
    // Variables para Switch cases
    int opt1 = 0, opt2 = 0, opt3 = 0, opt4 = 0;
    // Usuario y Contraseña
    char user[][MAX_LENGTH] = {"usuario123", "almacen123"};
    char password[][MAX_LENGTH] = {"usuario456", "almacen456"};
    char trypassword[MAX_LENGTH];
    char tryuser[MAX_LENGTH];
    // Vectores
    char nombreAlmacenes[MAX_ALMACENES][MAX_LENGTH] = {"Puebla", "Mexico City"};
    int id[MAX_ALMACENES][MAX_ARTICULOS];
    int preorden[MAX_ALMACENES][MAX_ARTICULOS];
    int existencia[MAX_ALMACENES][MAX_ARTICULOS];
    int maximo[MAX_ALMACENES][MAX_ARTICULOS];
    int pedido[MAX_ALMACENES][MAX_ARTICULOS];
    int num_articulos[MAX_ALMACENES] = {0};
    int tipo[MAX_ALMACENES][MAX_ARTICULOS]; // Tipo 1=Pasta dura 2=Blandos 3=Audio Libro 4=E-Book
    float precio[MAX_ALMACENES][MAX_ARTICULOS];
    char titulo[MAX_ALMACENES][MAX_ARTICULOS][MAX_LENGTH], author[MAX_ALMACENES][MAX_ARTICULOS][MAX_LENGTH];

    /////////// LIBRO DE PUEBLA
    // Libro 1
    id[0][0] = 1;
    preorden[0][0] = 15;
    existencia[0][0] = 10;
    maximo[0][0] = 30;
    pedido[0][0] = 0;
    tipo[0][0] = 1;
    precio[0][0] = 20.50;
    strcpy(titulo[0][0], "The Little Prince");
    strcpy(author[0][0], "ANTOINE DE SAINT");

    // Libro 2
    id[0][1] = 2;
    preorden[0][1] = 25;
    existencia[0][1] = 20;
    maximo[0][1] = 40;
    pedido[0][1] = 0;
    tipo[0][1] = 2;
    precio[0][1] = 15.75;
    strcpy(titulo[0][1], "1984");
    strcpy(author[0][1], "GEORGE ORWELL");

    // Libro 3
    id[0][2] = 3;
    preorden[0][2] = 30;
    existencia[0][2] = 15;
    maximo[0][2] = 50;
    pedido[0][2] = 0;
    tipo[0][2] = 3;
    precio[0][2] = 12.99;
    strcpy(titulo[0][2], "One Hundred Years of Solitude");
    strcpy(author[0][2], "GABRIEL GARCIA MARQUEZ");

    // Libro 4
    id[0][3] = 4;
    preorden[0][3] = 20;
    existencia[0][3] = 5;
    maximo[0][3] = 25;
    pedido[0][3] = 0;
    tipo[0][3] = 2;
    precio[0][3] = 18.50;
    strcpy(titulo[0][3], "To Kill a Mockingbird");
    strcpy(author[0][3], "HARPER LEE");

    // Libro 5
    id[0][4] = 5;
    preorden[0][4] = 10;
    existencia[0][4] = 8;
    maximo[0][4] = 20;
    pedido[0][4] = 0;
    tipo[0][4] = 4;
    precio[0][4] = 24.99;
    strcpy(titulo[0][4], "Pride and Prejudice");
    strcpy(author[0][4], "JANE AUSTEN");

    // Libro 6
    id[0][5] = 6;
    preorden[0][5] = 18;
    existencia[0][5] = 12;
    maximo[0][5] = 35;
    pedido[0][5] = 0;
    tipo[0][5] = 3;
    precio[0][5] = 21.00;
    strcpy(titulo[0][5], "Chronicle of a Death Foretold");
    strcpy(author[0][5], "GABRIEL GARCIA MARQUEZ");

    // Libro 7
    id[0][6] = 7;
    preorden[0][6] = 22;
    existencia[0][6] = 18;
    maximo[0][6] = 30;
    pedido[0][6] = 0;
    tipo[0][6] = 1;
    precio[0][6] = 16.75;
    strcpy(titulo[0][6], "The Hobbit");
    strcpy(author[0][6], "J.R.R TOLKIEN");

    // Libro 8
    id[0][7] = 8;
    preorden[0][7] = 28;
    existencia[0][7] = 25;
    maximo[0][7] = 40;
    pedido[0][7] = 0;
    tipo[0][7] = 4;
    precio[0][7] = 19.99;
    strcpy(titulo[0][7], "MOBY DICK");
    strcpy(author[0][7], "HERMAN MELVILLE");

    // Libro 9
    id[0][8] = 9;
    preorden[0][8] = 12;
    existencia[0][8] = 7;
    maximo[0][8] = 15;
    pedido[0][8] = 0;
    tipo[0][8] = 2;
    precio[0][8] = 23.25;
    strcpy(titulo[0][8], "TO KILL A MOCKINGBIRD");
    strcpy(author[0][8], "HARPER LEE");

    // Libro 10
    id[0][9] = 10;
    preorden[0][9] = 35;
    existencia[0][9] = 30;
    maximo[0][9] = 45;
    pedido[0][9] = 0;
    tipo[0][9] = 3;
    precio[0][9] = 17.50;
    strcpy(titulo[0][9], "THE GREAT GATSBY");
    strcpy(author[0][9], "F.SCOTT FITZGERALD");
    // Incrementar el contador de artículos para el almacén de Puebla
    num_articulos[0] = 10;

    /////////// LIBRO DE CDMX
    id[1][0] = 1;
    preorden[1][0] = 15;
    existencia[1][0] = 10;
    maximo[1][0] = 30;
    pedido[1][0] = 0;
    tipo[1][0] = 1;
    precio[1][0] = 20.50;
    strcpy(titulo[1][0], "The Little Prince");
    strcpy(author[1][0], "ANTOINE DE SAINT");

    id[1][1] = 2;
    preorden[1][1] = 25;
    existencia[1][1] = 15;
    maximo[1][1] = 40;
    pedido[1][1] = 0;
    tipo[1][1] = 1;
    precio[1][1] = 15.75;
    strcpy(titulo[1][1], "HP and the Philosopher's Stone");
    strcpy(author[1][1], "J.K. ROWLING");

    id[1][2] = 3;
    preorden[1][2] = 10;
    existencia[1][2] = 5;
    maximo[1][2] = 20;
    pedido[1][2] = 0;
    tipo[1][2] = 1;
    precio[1][2] = 18.99;
    strcpy(titulo[1][2], "Twilight");
    strcpy(author[1][2], "STEPHENIE ");

    id[1][3] = 4;
    preorden[1][3] = 20;
    existencia[1][3] = 12;
    maximo[1][3] = 25;
    pedido[1][3] = 0;
    tipo[1][3] = 1;
    precio[1][3] = 22.00;
    strcpy(titulo[1][3], "The Da Vinci Code");
    strcpy(author[1][3], "DAN BROWN");

    id[1][4] = 5;
    preorden[1][4] = 30;
    existencia[1][4] = 20;
    maximo[1][4] = 35;
    pedido[1][4] = 0;
    tipo[1][4] = 1;
    precio[1][4] = 19.95;
    strcpy(titulo[1][4], "1984");
    strcpy(author[1][4], "GEORGE ORWELL");

    id[1][5] = 6;
    preorden[1][5] = 18;
    existencia[1][5] = 8;
    maximo[1][5] = 22;
    pedido[1][5] = 0;
    tipo[1][5] = 1;
    precio[1][5] = 16.50;
    strcpy(titulo[1][5], "HUNGER GAMES");
    strcpy(author[1][5], "SUZANNE COLLINS");

    id[1][6] = 7;
    preorden[1][6] = 12;
    existencia[1][6] = 6;
    maximo[1][6] = 18;
    pedido[1][6] = 0;
    tipo[1][6] = 1;
    precio[1][6] = 21.25;
    strcpy(titulo[1][6], "One Hundred Years of Solitude");
    strcpy(author[1][6], "GABRIEL GARCIA MARQUEZ");

    id[1][7] = 8;
    preorden[1][7] = 8;
    existencia[1][7] = 4;
    maximo[1][7] = 15;
    pedido[1][7] = 0;
    tipo[1][7] = 1;
    precio[1][7] = 17.99;
    strcpy(titulo[1][7], "Fifty Shades of Grey");
    strcpy(author[1][7], "E.L. JAMES");

    id[1][8] = 9;
    preorden[1][8] = 22;
    existencia[1][8] = 18;
    maximo[1][8] = 28;
    pedido[1][8] = 0;
    tipo[1][8] = 1;
    precio[1][8] = 23.75;
    strcpy(titulo[1][8], "The Alchemist");
    strcpy(author[1][8], "PAULO COELHO");

    id[1][9] = 10;
    preorden[1][9] = 17;
    existencia[1][9] = 11;
    maximo[1][9] = 20;
    pedido[1][9] = 0;
    tipo[1][9] = 1;
    precio[1][9] = 20.99;
    strcpy(titulo[1][9], "The Shadow of the Wind");
    strcpy(author[1][9], "CARLOS RUIZ ZAFON");

    // Incrementar el contador de artículos para el almacén de CDMX
    num_articulos[1] = 10;

    do
    {
        printf("1) Log in\n2) Exit the warehouse\nChoose option:");
        scanf("%i", &opt1);
        switch (opt1)
        {
        case 1:
            printf("User:");
            fflush(stdin); // Limpiar el búfer de entrada
            fgets(tryuser, sizeof(tryuser), stdin);
            if (tryuser[strlen(tryuser) - 1] == '\n')
            { // Limpiar el ultimo caracter ingresado
                tryuser[strlen(tryuser) - 1] = '\0';
            }
            printf("Password:");

            fflush(stdin); // Limpiar el búfer de entrada
            fgets(trypassword, sizeof(trypassword), stdin);
            if (trypassword[strlen(trypassword) - 1] == '\n')
            { // Limpiar el ultimo caracter ingresado
                trypassword[strlen(trypassword) - 1] = '\0';
            }
            for (int i = 0; i < sizeof(user); ++i)
            {
                if (strcmp(trypassword, password[i]) == 0 && strcmp(tryuser, user[i]) == 0)
                {
                    bandera = 1;
                    break;
                }
            }
            if (bandera == 0)
            {
                printf("The password or username is incorrect.\n");
                break;
            }
            do
            {
                printf("-----CHOOSE WAREHOUSE-----\n1) Puebla Warehouse\n2) CDMX Warehouse\n3) Go back to login\nChoose option:");
                scanf("%i", &opt2);
                switch (opt2)
                {
                case 1:
                case 2:
                    do
                    {
                        if (opt2 == 1)
                        {
                            printf("-----PUEBLA WAREHOUSE-----\n");
                        }
                        if (opt2 == 2)
                        {
                            printf("-----CDMX WAREHOUSE-----\n");
                        }
                        printf("-----MAIN MENU-----\n1) Additions\n2) Sales\n3) List/Search\n4) Modifications\n5) Restock\n6) Removals\n7) Delete Product\n8) Go back to warehouse selection\n9) Exit program\nChoose option:");
                        scanf("%i", &opt3);
                        int encontrado = 0;
                        switch (opt3)
                        {
                        case 1:
                            printf("\n\n-----Welcome to the additions menu-----\n");
                            printf("\nEnter the name of the book:");
                            fflush(stdin); // Limpiar el búfer de entrada
                            fgets(titulo[opt2 - 1][num_articulos[opt2 - 1]], sizeof(titulo[opt2 - 1][num_articulos[opt2 - 1]]), stdin);
                            if (titulo[opt2 - 1][num_articulos[opt2 - 1]][strlen(titulo[opt2 - 1][num_articulos[opt2 - 1]]) - 1] == '\n')
                            { // Limpiar el ultimo caracter ingresado
                                titulo[opt2 - 1][num_articulos[opt2 - 1]][strlen(titulo[opt2 - 1][num_articulos[opt2 - 1]]) - 1] = '\0';
                            }
                            convertirMayusculas(titulo[opt2 - 1][num_articulos[opt2 - 1]]);
                            printf("\nEnter the name of the author:");
                            fgets(author[opt2 - 1][num_articulos[opt2 - 1]], sizeof(author[0][num_articulos[0]]), stdin);
                            if (author[opt2 - 1][num_articulos[opt2 - 1]][strlen(author[opt2 - 1][num_articulos[opt2 - 1]]) - 1] == '\n')
                            { // Limpiar el ultimo caracter ingresado
                                author[opt2 - 1][num_articulos[opt2 - 1]][strlen(author[opt2 - 1][num_articulos[opt2 - 1]]) - 1] = '\0';
                            }
                            convertirMayusculas(author[opt2 - 1][num_articulos[opt2 - 1]]);
                            printf("\nEnter the number corresponding to the type of cover:\n1. Hardcover\n2. Paperback\n3. Audiobook\n4. E-book\nOption:");
                            scanf("%d", &tipo[opt2 - 1][num_articulos[opt2 - 1]]);
                            tipotemp = tipo[opt2 - 1][num_articulos[opt2 - 1]];
                            if (tipotemp > 0 && tipotemp < 5)
                            {
                            }
                            else
                            {
                                printf("The entered value is not recognized. . .\nIt will be registered as unknown\n");
                            }
                            printf("\nEnter the price:");
                            scanf("%f", &precio[opt2 - 1][num_articulos[opt2 - 1]]);
                            printf("\nEnter the stock:");
                            scanf("%d", &existencia[opt2 - 1][num_articulos[opt2 - 1]]);
                            printf("\nEnter the reorder point:");
                            scanf("%d", &preorden[opt2 - 1][num_articulos[opt2 - 1]]);
                            printf("\nEnter the maximum:");
                            scanf("%d", &maximo[opt2 - 1][num_articulos[opt2 - 1]]);
                            id[opt2 - 1][num_articulos[opt2 - 1]] = num_articulos[opt2 - 1] + 1;
                            num_articulos[opt2 - 1]++;
                            printf("\n-----Successful addition-----\n\n");
                            printf("PRESS ENTER TO CONTINUE...");
                            fflush(stdin);
                            getchar();
                            break;
                        case 2:
                            printf("\n\n-----Sales-----\n");
                            int idVenta, cantidadVenta;
                            printf("Enter the ID of the product you want to sell: ");
                            scanf("%d", &idVenta);
                            printf("Enter the quantity you want to sell: ");
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
                                        printf("Sale completed successfully.\n");
                                    }
                                    else
                                    {
                                        printf("There is not enough quantity in the inventory.\n");
                                    }
                                    // No hay salto aquí
                                }
                            }
                            if (!encontrado)
                            {
                                printf("The product ID does not exist in the inventory.\n");
                            }
                            printf("PRESS ENTER TO CONTINUE...");
                            fflush(stdin);
                            getchar();
                            break;
                        case 3:
                            do
                            {
                                printf("\n-----List/Search-----\n");
                                printf("1) List all\n2) Search by ID\n3) Search by book name\n4) Search by author\n5) Search in all warehouses\n6) Go back to main menu\nChoose option:");
                                scanf("%i", &opt4);
                                switch (opt4)
                                {
                                case 1:
                                    printf("\n-----List All-----\n");
                                    if (num_articulos[opt2 - 1] != 0)
                                    {
                                        printf("%-5s | %-25s | %-25s | %-10s | %-12s | %-15s | %-20s \n",
                                               "ID", "Title", "Author", "Price", "Stock",
                                               "Reorder Point", "Type");
                                        for (int i = 0; i < num_articulos[opt2 - 1]; i += 10)
                                        {
                                            int end = (i + 10 < num_articulos[opt2 - 1]) ? i + 10
                                                                                         : num_articulos[opt2 - 1];
                                            for (int j = i; j < end; j++)
                                            { // ID: %i|Titulo: %s|Author: %s|Precio: %.2f|Existencia: %i|Punto de reorden: %i|Tipo:%-5i | %-25s | %-25s | %-10.2f | %-12i | %-15i |
                                                printf("%-5i | %-25s | %-25s | %-10.2f | %-12i | %-16i | ",
                                                       id[opt2 - 1][j], titulo[opt2 - 1][j], author[opt2 - 1][j], precio[opt2 - 1][j],
                                                       existencia[opt2 - 1][j], preorden[opt2 - 1][j]);

                                                switch (tipo[opt2 - 1][j])
                                                {
                                                case 1:
                                                    printf("Hardcover\n");
                                                    break;
                                                case 2:
                                                    printf("Paperback\n");
                                                    break;
                                                case 3:
                                                    printf("Audiobook\n");
                                                    break;
                                                case 4:
                                                    printf("E-Book\n");
                                                    break;
                                                default:
                                                    printf("Unknown type\n");
                                                    break;
                                                }
                                            }
                                            if (end < num_articulos[opt2 - 1])
                                            {
                                                printf("Press ENTER to see more products...\n");
                                                fflush(stdin);
                                                while (getchar() != '\n')
                                                    ;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        printf("The warehouse is empty\n");
                                    }
                                    printf("PRESS ENTER TO CONTINUE...");
                                    fflush(stdin);
                                    getchar();
                                    break;
                                case 2:
                                    bandera = 0;
                                    printf("-----Search by ID-----\n");
                                    printf("Enter the ID of the product you want to search for:");
                                    scanf("%i", &idtemp);
                                    serchprintID(opt2, idtemp, id, num_articulos, titulo, author, precio, existencia, preorden, tipo, bandera);
                                    printf("PRESS ENTER TO CONTINUE...");
                                    fflush(stdin);
                                    getchar();
                                    break;
                                case 3:
                                    bandera = 0;
                                    ubi = 0;
                                    // limpiarVector(idvec, MAX_ARTICULOS, 0);
                                    printf("-----Search by book name-----\n");
                                    printf("Enter the name of the book you want to search for:");
                                    fflush(stdin);
                                    fgets(trytitulo, sizeof(trytitulo), stdin);
                                    if (trytitulo[strlen(trytitulo) - 1] ==
                                        '\n')
                                    { // Limpiar el ultimo caracter ingresado
                                        trytitulo[strlen(trytitulo) - 1] = '\0';
                                    }
                                    convertirMayusculas(trytitulo);
                                    for (int i = 0; i < num_articulos[opt2 - 1]; ++i)
                                    {
                                        if (strcmp(trytitulo, titulo[opt2 - 1][i]) == 0)
                                        {
                                            bandera = 1;
                                            idvec[ubi++] = i;
                                        }
                                    }

                                    if (bandera != 0)
                                    {
                                        printAutoresLibros(ubi, id, titulo, author, precio, existencia, preorden, tipo, opt2, idvec);
                                    }
                                    else
                                    {
                                        printf("We don't have it\n");
                                    }
                                    printf("PRESS ENTER TO CONTINUE...");
                                    fflush(stdin);
                                    getchar();
                                    break;
                                case 4:
                                    bandera = 0;
                                    ubi = 0;
                                    // limpiarVector(idvec, MAX_ARTICULOS, 0);
                                    printf("-----Search by author-----\n");
                                    printf("Enter the name of the author you want to search for:");
                                    fflush(stdin);
                                    fgets(trytitulo, sizeof(trytitulo), stdin);
                                    if (trytitulo[strlen(trytitulo) - 1] ==
                                        '\n')
                                    { // Limpiar el ultimo caracter ingresado
                                        trytitulo[strlen(trytitulo) - 1] = '\0';
                                    }
                                    convertirMayusculas(trytitulo);
                                    for (int i = 0; i < num_articulos[opt2 - 1]; ++i)
                                    {
                                        if (strcmp(trytitulo, author[opt2 - 1][i]) == 0)
                                        {
                                            bandera = 1;
                                            idvec[ubi] = i;

                                            ubi++;
                                        }
                                    }

                                    if (bandera != 0)
                                    {
                                        printAutoresLibros(ubi, id, titulo, author, precio, existencia, preorden, tipo, opt2, idvec);
                                    }
                                    else
                                    {
                                        printf("We don't have it\n");
                                    }
                                    printf("PRESS ENTER TO CONTINUE...");
                                    fflush(stdin);
                                    getchar();
                                    break;
                                case 5:
                                    bandera = 0;
                                    ubi = 0;
                                    printf("----Search in all warehouses-----\n");
                                    printf("Enter the author or title of the book:");
                                    fflush(stdin);
                                    fgets(trytitulo, sizeof(trytitulo), stdin);
                                    if (trytitulo[strlen(trytitulo) - 1] ==
                                        '\n')
                                    { // Limpiar el ultimo caracter ingresado
                                        trytitulo[strlen(trytitulo) - 1] = '\0';
                                    }
                                    convertirMayusculas(trytitulo);
                                    for (int i = 0; i < MAX_ALMACENES; ++i)
                                    {
                                        for (int j = 0; j < num_articulos[i]; ++j)
                                        {
                                            if (strcmp(trytitulo, author[i][j]) == 0 || strcmp(trytitulo, titulo[i][j]) == 0)
                                            {
                                                bandera = 1;
                                                idvec[ubi] = j;
                                                almacenvec[ubi] = i;
                                                ubi++;
                                            }
                                        }
                                    }
                                    if (bandera != 0)
                                    {
                                        printAlmacenes(ubi, id, titulo, author, precio, existencia, preorden, tipo, almacenvec, idvec);
                                    }
                                    else
                                    {
                                        printf("We don't have it\n");
                                    }
                                    break;
                                case 6:
                                    printf("Returning to the main menu...\n");
                                    break;
                                default:
                                    printf("<----->You entered an incorrect option<----->\n");
                                    break;
                                }
                            } while (opt4 != 6);
                            printf("PRESS ENTER TO CONTINUE...");
                            fflush(stdin);
                            getchar();
                            break;
                        case 4:
                            printf("-----Modifications-----\n");
                            bandera = 0;
                            printf("Enter the ID of the book for modifications:");
                            scanf("%i", &idtemp);
                            serchprintID(opt2, idtemp, id, num_articulos, titulo, author, precio, existencia, preorden, tipo, bandera);
                            printf("What data do you want to change?\n1) Title\n2) Author\n3) Book type\n4) Price\n5) Stock\n6) Reorder point\n7) Go back to main menu\n");
                            printf("\tSelect an option: ");
                            scanf("%i", &opc);

                            switch (opc)
                            {
                            case 1:
                                printf("-----Change Title-----\n");
                                printf("Enter the title of the book:");
                                fflush(stdin);
                                fgets(titulo[opt2 - 1][idtemp - 1], sizeof(titulo[opt2 - 1][idtemp - 1]), stdin);
                                if (titulo[opt2 - 1][idtemp - 1][strlen(titulo[opt2 - 1][idtemp - 1]) - 1] == '\n')
                                {
                                    titulo[opt2 - 1][idtemp - 1][strlen(titulo[opt2 - 1][idtemp - 1]) - 1] = '\0';
                                }
                                convertirMayusculas(titulo[opt2 - 1][idtemp - 1]);
                                printf("\tChange successful\n");
                                break;

                            case 2:
                                printf("-----Change Author-----\n");
                                printf("Enter the author's name:");
                                fflush(stdin);
                                fgets(author[opt2 - 1][idtemp - 1], sizeof(author[opt2 - 1][idtemp - 1]), stdin);
                                if (author[opt2 - 1][idtemp - 1][strlen(author[opt2 - 1][idtemp - 1]) - 1] == '\n')
                                {
                                    author[opt2 - 1][idtemp - 1][strlen(author[opt2 - 1][idtemp - 1]) - 1] = '\0';
                                }
                                convertirMayusculas(author[opt2 - 1][idtemp - 1]);
                                printf("\tChange successful\n");
                                printf("PRESS ENTER TO CONTINUE...");
                                fflush(stdin);
                                getchar();
                                break;
                            case 3:
                                printf("-----Change type of cover-----\n");
                                tipod = tipo[opt2 - 1][idtemp - 1];
                                printf("Select the type of cover:\n1) Hardcover\n2) Paperback\n3) Audiobook\n4) E-book\n\tSelect an option:");
                                scanf("%i", &tipo[opt2 - 1][idtemp - 1]);
                                tipotemp = tipo[opt2 - 1][idtemp - 1];
                                if (tipotemp > 0 && tipotemp < 5)
                                {
                                    printf("\tChange successful\n");
                                }
                                else
                                {
                                    printf("The entered value is not recognized. . .\nThe value will not be changed\n");
                                    tipo[opt2 - 1][idtemp - 1] = tipod;
                                }
                                break;

                            case 4:
                                printf("-----Change Price----\n");
                                printf("Enter the price:");
                                scanf("%f", &precio[opt2 - 1][idtemp - 1]);
                                printf("\tChange successful\n");
                                break;

                            case 5:
                                printf("-----Change Inventory-----\n");
                                printf("Enter the inventory:");
                                scanf("%i", &existencia[opt2 - 1][idtemp - 1]);
                                printf("\tChange successful\n");
                                break;

                            case 6:
                                printf("-----Change Reorder Point-----\n");
                                printf("Enter the reorder point:");
                                scanf("%i", &preorden[opt2 - 1][idtemp - 1]);
                                printf("\tChange successful\n");
                                break;

                            case 7:
                                printf("-----Return to Main Menu-----\n");
                                printf("Returning. . .\n");
                                break;

                            default:
                                printf("<----->Select a valid option<----->\n");
                                break;
                            }
                            printf("PRESS ENTER TO CONTINUE...");
                            fflush(stdin);
                            getchar();
                            break;
                        case 5:
                            printf("-----Restock-----\n");
                            int maybe = 0, existencia_temp;
                            float totalPagar = 0;
                            bandera = 0, ubi = 0;
                            for (int i = 0; i < num_articulos[opt2 - 1]; i++)
                            {

                                if (existencia[opt2 - 1][i] < preorden[opt2 - 1][i])
                                {
                                    bandera = 1;
                                    idvec[ubi] = i;
                                    ubi++;
                                }
                            }

                            if (bandera == 1)
                            {
                                printf("%-5s | %-25s| %-10s| %-10s\n", "ID", "Title", "Order", "Cost");
                                for (int i = 0; i < ubi; i++)
                                {
                                    existencia_temp = maximo[opt2 - 1][idvec[i]] - existencia[opt2 - 1][idvec[i]];

                                    printf("%-5i | %-25s| %-10i| %-10.2f \n", id[opt2 - 1][idvec[i]], titulo[opt2 - 1][idvec[i]], existencia_temp, existencia_temp * precio[opt2 - 1][idvec[i]]);
                                    totalPagar = totalPagar + (precio[opt2 - 1][idvec[i]] * (existencia_temp));
                                }
                                printf("The total cost to restock everything is %.2f pesos\n1)Restock everything\n2)Restock by ID\nChoose an option:", totalPagar);
                                scanf("%i", &maybe);
                                switch (maybe)
                                {
                                case 1:
                                    for (int i = 0; i < ubi; ++i)
                                    {
                                        pedido[opt2 - 1][idvec[i]] = maximo[opt2 - 1][idvec[i]] - existencia[opt2 - 1][idvec[i]];
                                        existencia[opt2 - 1][idvec[i]] = pedido[opt2 - 1][idvec[i]] + existencia[opt2 - 1][idvec[i]];
                                    }
                                    printf("Restocked successfully\n");
                                    break;
                                case 2:
                                    printf("Ingrese ID:");
                                    scanf("%i", &idtemp);
                                    pedido[opt2 - 1][idtemp - 1] = maximo[opt2 - 1][idtemp - 1] - existencia[opt2 - 1][idtemp - 1];
                                    existencia[opt2 - 1][idtemp - 1] = pedido[opt2 - 1][idtemp - 1] + existencia[opt2 - 1][idtemp - 1];
                                    printf("Successfully restocked\n");
                                    break;
                                default:
                                    printf("------Invalid option-----");
                                    break;
                                }
                            }
                            else
                            {
                                printf("There is nothing to restock\n");
                            }
                            printf("PRESS ENTER TO CONTINUE...");
                            fflush(stdin);
                            getchar();
                            break;
                        case 6:
                            printf("-----Remove Items-----\n");
                            idVenta = 0, cantidadVenta = 0;
                            printf("Enter the ID of the product you want to remove: ");
                            scanf("%d", &idVenta);
                            printf("Enter the quantity you want to remove: ");
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
                                        printf("Item successfully removed.\n");
                                    }
                                    else
                                    {
                                        printf("The given quantity is greater than the quantity in stock.\n");
                                    }
                                    // No hay salto aquí
                                }
                            }
                            if (!encontrado)
                            {
                                printf("The product ID does not exist in the inventory.\n");
                            }
                            printf("PRESS ENTER TO CONTINUE...");
                            fflush(stdin);
                            getchar();
                            break;
                        case 7:
                            bandera = 0;
                            printf("\n-----Delete Product-----\n");
                            printf("Give me the ID of the item you want to delete:");
                            scanf("%i", &idtemp);
                            if (serchprintID(opt2, idtemp, id, num_articulos, titulo, author, precio, existencia, preorden, tipo, bandera) == 1)
                            {
                                if (existencia[opt2 - 1][idtemp - 1] <= 0)
                                {
                                    id[opt1 - 1][idtemp - 1] = id[opt2 - 1][(idtemp - 1) + 1];
                                    preorden[opt2 - 1][idtemp - 1] = preorden[opt2 - 1][(idtemp - 1) + 1];
                                    existencia[opt2 - 1][idtemp - 1] = existencia[opt2 - 1][(idtemp - 1) + 1];
                                    maximo[opt2 - 1][idtemp - 1] = maximo[opt2 - 1][(idtemp - 1) + 1];
                                    pedido[opt2 - 1][idtemp - 1] = pedido[opt2 - 1][(idtemp - 1) + 1];
                                    tipo[opt2 - 1][idtemp - 1] = tipo[opt2][(idtemp - 1) + 1];
                                    precio[opt2 - 1][idtemp - 1] = precio[opt2 - 1][(idtemp - 1) + 1];
                                    strcpy(titulo[opt2 - 1][idtemp - 1], titulo[opt2 - 1][(idtemp - 1) + 1]);
                                    strcpy(author[opt2 - 1][idtemp - 1], author[opt2 - 1][(idtemp - 1) + 1]);
                                    num_articulos[opt2 - 1]--;
                                    printf("Product deleted successfully\n");
                                }
                                else
                                {
                                    printf("You still have stock in the warehouse\nYou need to remove the product first\n");
                                }
                            }

                            printf("PRESS ENTER TO CONTINUE...");
                            fflush(stdin);
                            getchar();
                            break;
                        case 8:
                            printf("Returning to warehouse selection...\n");
                            break;
                        case 9:
                            printf("Exiting the program...");
                            return 0;
                        default:
                            printf("<----->You entered an invalid option<----->\n");
                            break;
                        }
                    } while (opt3 != 8);
                    break;
                case 3:
                    printf("-----Returning to login...-----\n");
                    break;
                default:
                    printf("<----->You entered an invalid option<----->\n");
                    break;
                }
            } while (opt2 != 3);

            break;
        case 2:
            printf("You are exiting the program...\n");
            break;
        default:
            printf("<----->You entered an invalid option<----->\n");
            break;
        }
    } while (opt1 != 2);
    return 0;
}
