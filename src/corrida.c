#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "corrida.h"


pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t corrida_cond = PTHREAD_COND_INITIALIZER; 
int corrida_em_andamento = 1;
int vencedor = -1;


void* corrida(void* arg) {
    Carro* carro = (Carro*)arg;

    while (corrida_em_andamento) {
        pthread_mutex_lock(&mutex);

        if (vencedor != -1) {
            pthread_mutex_unlock(&mutex);
            break;
        }

        carro->voltas_completas++;
        printf("Carro %d completou a volta %d\n", carro->id, carro->voltas_completas);

        if (carro->voltas_completas >= VOLTAS && vencedor == -1) {
            vencedor = carro->id;
            corrida_em_andamento = 0;
            printf("Carro %d venceu a corrida!\n", carro->id);
            pthread_cond_broadcast(&corrida_cond); 
        }

        pthread_mutex_unlock(&mutex);

        usleep((rand() % 100 + 50) * 1000);
    }

    return NULL;
}

// Inicializa os dados da corrida
void inicializar_corrida() {
    srand(time(NULL));
    corrida_em_andamento = 1;
    vencedor = -1;
}

// Cria uma thread para cada carro
void iniciar_carro(Carro* carro) {
    pthread_t thread;
    pthread_create(&thread, NULL, corrida, (void*)carro);
    pthread_detach(thread);
}

// Destroi recursos alocados para a corrida
void destruir_corrida() {
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&corrida_cond); // Destroi a variável de condição
}
