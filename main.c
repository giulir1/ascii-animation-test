#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  // Para usar sleep()

#define FRAME_DELAY 200000 // Delay entre frames en segundos
#define MAX_LINE_LENGTH 256

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    int in_frame = 0; // Variable para saber si estamos dentro de un frame

    // Abre el archivo en modo lectura
    file = fopen("image2.txt", "r");
    if (file == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    // Lee y muestra los frames
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        if (strcmp(line, "START\n") == 0) {
            in_frame = 1; // Comenzamos un nuevo frame
            system("clear"); // Limpiar pantalla
        } else if (strcmp(line, "END\n") == 0) {
            in_frame = 0; // Terminamos el frame actual
            usleep(FRAME_DELAY); // Esperamos entre frames
        } else if (in_frame) {
            // Si estamos dentro de un frame, imprimimos las líneas
            printf("%s", line);
        }
    }

    // Cierra el archivo
    fclose(file);

    return 0;
}