#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definici�n de un nodo en el mapa
typedef struct Nodo {
    char nombre[50];
    struct Nodo *opciones[3];  // Hasta 3 opciones de caminos por nodo
} Nodo;

// Funci�n para crear un nodo
Nodo* crearNodo(char nombre[]) {
    Nodo *nuevoNodo = (Nodo*) malloc(sizeof(Nodo));
    strcpy(nuevoNodo->nombre, nombre);
    for (int i = 0; i < 3; i++) {
        nuevoNodo->opciones[i] = NULL;
    }
    return nuevoNodo;
}

// Funci�n para recorrer el mapa con m�ltiples opciones
void mostrarOpciones(Nodo *inicio) {
    Nodo *actual = inicio;
    while (actual != NULL) {
        printf("Ubicaci�n actual: %s\n", actual->nombre);
        printf("Opciones disponibles:\n");
        
        int opcionesDisponibles = 0;
        for (int i = 0; i < 3; i++) {
            if (actual->opciones[i] != NULL) {
                printf("%d. Ir a %s\n", i + 1, actual->opciones[i]->nombre);
                opcionesDisponibles++;
            }
        }
        printf("0. Salir del mapa\n");

        // Validaci�n de entrada del usuario
        int opcion;
        do {
            printf("Seleccione una opci�n: ");
            scanf("%d", &opcion);
            if (opcion == 0) {
                printf("Saliendo del mapa...\n");
                return;
            } else if (opcion > 0 && opcion <= opcionesDisponibles) {
                actual = actual->opciones[opcion - 1];
                break;
            } else {
                printf("Opci�n no v�lida. Intente de nuevo.\n");
            }
        } while (1);
    }
}

// Funci�n principal
int main() {
    // Creaci�n de nodos (lugares)
    Nodo *elDorado = crearNodo("El Dorado");
    Nodo *uip = crearNodo("Universidad Interamericana de Panam� (UIP)");
    Nodo *isae = crearNodo("Universidad ISAE");
    Nodo *usma = crearNodo("Universidad Santa Mar�a La Antigua (USMA)");
    Nodo *uLatina = crearNodo("Universidad Latina de Panam� (U LATINA)");
    Nodo *centennial = crearNodo("Centennial");
    Nodo *utp = crearNodo("Universidad Tecnol�gica de Panam� (UTP)");
    Nodo *up = crearNodo("Universidad de Panam� (UP)");
    Nodo *sanMiguelito = crearNodo("San Miguelito");

    // Enlace entre nodos con opciones de caminos
    elDorado->opciones[0] = uip;               // Camino desde El Dorado
    uip->opciones[0] = isae;                   // Camino desde UIP
    isae->opciones[0] = usma;                  // Camino desde ISAE
    usma->opciones[0] = uLatina;               // Camino desde USMA
    uLatina->opciones[0] = utp;                // Camino principal desde U Latina
    uLatina->opciones[1] = centennial;         // Camino alternativo desde U Latina a Centennial
    centennial->opciones[0] = utp;             // Camino de regreso de Centennial a UTP
    utp->opciones[0] = up;                     // Camino desde UTP
    up->opciones[0] = sanMiguelito;            // Camino desde UP hasta San Miguelito

    // Men� interactivo para mostrar el mapa
    printf("Bienvenido al mapa de puntos de inter�s de Panam�.\n");
    mostrarOpciones(elDorado);

    // Liberaci�n de memoria
    free(elDorado);
    free(uip);
    free(isae);
    free(usma);
    free(uLatina);
    free(centennial);
    free(utp);
    free(up);
    free(sanMiguelito);

    return 0;
}

