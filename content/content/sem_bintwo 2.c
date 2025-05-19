#include <string.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

#define BUFFER_SIZE 7
#define READERS 5

sem_t mutex;  // Protezione delle variabili globali
sem_t bf;     // Accesso esclusivo al buffer
sem_t leggi;  // Permette ai reader di leggere
sem_t scrivi; // Permette al writer di scrivere

int ciclo = 1;
int indice_pari = 0;
int indice_dispari = 1;
int lettori = 0;

void down(sem_t *sem) {
    sem_wait(sem);
}

void up(sem_t *sem) {
    sem_post(sem);
}

void *writer(void *buffer) {
    int pari = 2;
    int dispari = 51;
    int *buffer_vero = (int *)buffer;

    while (pari <= 52 && dispari <= 101) {
		down(&scrivi);
		
		down(&bf);
		
		buffer_vero[indice_pari] = pari;
		buffer_vero[indice_dispari] = dispari;
		
		up(&bf);
		
		down(&mutex);
		
		pari = pari + 2;
		dispari = dispari + 2;
		
		if (pari > 50){
			ciclo = 0;
		}
		
		up(&mutex);
		
		up(&leggi);
														
	}
	pthread_exit(NULL);
}

void *reader(void *buffer) {
    int *buffer_vero = (int *)buffer;

    while (1) {
		down(&leggi);
		
		lettori ++;
		
		down(&mutex);
		if (ciclo == 0){
			up(&mutex);
			up(&leggi);
			up(&scrivi);
			break;
		}
		if (lettori == 1 ){
			down(&bf);
		}
		up(&mutex);
		
		int somma = buffer_vero[indice_pari] + buffer_vero[indice_dispari];
		printf("Somma calcolata: %d (pari: %d, dispari: %d)\n", somma, buffer_vero[indice_pari], buffer_vero[indice_dispari]);
		
		down(&mutex);
		
		indice_pari = (indice_pari + 2)%BUFFER_SIZE;
		indice_dispari = (indice_dispari + 2)%BUFFER_SIZE;
		
		lettori --;
		
		up(&bf);
		
		up(&mutex);
		
		up(&scrivi);
    }
	pthread_exit(NULL);	
}

int main() {
    int buffer[BUFFER_SIZE];
    for (int i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] = 0;
    }

    pthread_t rd[READERS];
    pthread_t wr;

    sem_init(&mutex, 0, 1);
    sem_init(&bf, 0, 1);
    sem_init(&leggi, 0, 0);  // Inizializzato a 0: i reader devono attendere
    sem_init(&scrivi, 0, 1); // Inizializzato a 1: il writer può iniziare

    pthread_create(&wr, NULL, writer, (void *)buffer);
    for (int i = 0; i < READERS; i++) {
        pthread_create(&rd[i], NULL, reader, (void *)buffer);
    }

    pthread_join(wr, NULL);
    for (int i = 0; i < READERS; i++) {
        pthread_join(rd[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&bf);
    sem_destroy(&leggi);
    sem_destroy(&scrivi);

}
