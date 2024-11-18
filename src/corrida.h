#ifndef CORRIDA_H
#define CORRIDA_H

#include <pthread.h>

// Constantes
#define NUM_CARROS 5
#define VOLTAS 50

// Estrutura para representar um carro
typedef struct {
    int id;             
    int voltas_completas; 
} Carro;


extern pthread_mutex_t mutex;
extern pthread_cond_t corrida_cond;
extern int corrida_em_andamento;
extern int vencedor;

void inicializar_corrida();
void iniciar_carro(Carro* carro);
void destruir_corrida();

#endif
