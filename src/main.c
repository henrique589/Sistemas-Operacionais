#include <stdio.h>
#include <unistd.h>
#include "corrida.h"

int main() {
    Carro carros[NUM_CARROS];

    inicializar_corrida();

    // Inicializa os dados dos carros e inicia as threads
    for (int i = 0; i < NUM_CARROS; i++) {
        carros[i].id = i + 1;
        carros[i].voltas_completas = 0;
        iniciar_carro(&carros[i]);
    }

    // Aguarda o fim da corrida
    while (1) {
        pthread_mutex_lock(&mutex);
        if (!corrida_em_andamento) {
            pthread_mutex_unlock(&mutex);
            break;
        }
        pthread_mutex_unlock(&mutex);
        usleep(100 * 1000); 
    }

    printf("Corrida encerrada! Carro vencedor: %d\n", vencedor);

    destruir_corrida();

    return 0;
}
