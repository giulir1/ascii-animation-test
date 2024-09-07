#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char ch;

    // Abre el archivo en modo lectura
    file = fopen("image.txt", "r");
    if (file == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    // Lee el archivo caracter por caracter y lo imprime en pantalla
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    // Cierra el archivo
    fclose(file);

    return 0;
}
