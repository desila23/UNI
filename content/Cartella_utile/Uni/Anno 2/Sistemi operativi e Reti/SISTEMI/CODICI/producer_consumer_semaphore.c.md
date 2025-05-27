### Funzionamento
Vogliamo implementare il classico problema produttore-consumatore, in cui
- il produttore "produce" dei dati e li inserisce in un buffer condiviso
- il consumatore "preleva" i dati e li consuma.


### Codice
```c
#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

#define N 10  /* numero di posti nel buffer */
#define TRUE 1

/* Dichiarazione dei semafori */
sem_t mutex;  // Semaforo per l'accesso esclusivo alla regione critica
sem_t empty;  // Semaforo per contare i posti vuoti nel buffer
sem_t full;   // Semaforo per contare i posti pieni nel buffer

int buffer[N];  // Buffer condiviso tra produttore e consumatore
int in = 0;  // Indice dove inserire il prossimo elemento nel buffer



/* Funzioni helper per utilizzare i semafori */
void down(sem_t *sem) {
    sem_wait(sem);
}

void up(sem_t *sem) {
    sem_post(sem);
}

/* Funzione per inserire un elemento nel buffer */
void insert_item() {
	int item = rand() % 100;  // Genera un elemento casuale
	printf("\nInserisco %d in posizione %d\n", item, (in + 1)); 
    buffer[in] = item;  // Inserisce l'elemento nel buffer
    in++;  // Incrementa l'indice
}

/* Funzione per rimuovere un elemento dal buffer */
void remove_item() {
	printf("%i", in);  // '%i' indica più precisamente un intero
    int item = buffer[in - 1];  // prendo l'ultimo elemento inserito (in - 1)
    printf("\nPrelevo %d da posizione %d\n", item, in);
    in--;  // Decrementa l'indice e indica che c'è una posizione disponibile in più
}

/* Funzione per stampare il contenuto del buffer */
void print_buffer(){
	for(int i=0; i<in; i++){
		printf("%d ", buffer[i]);
    }
    printf("\n");
}


/* Funzione eseguita dal thread del produttore */
void *producer(void *arg) {
	while (TRUE) {
		down(&empty);  // controlla se ci sono posti disponibili (se >0 va avanti)
		down(&mutex);  // se ci sono posti liberi, preleva il `mutex`
		
		insert_item();  // inserisce l'item
		print_buffer(); // stampa il contenuto del buffer
		
		up(&mutex); // rilascia il 'mutex' 
		up(&full);  // segnala che c'è il posto vuoto in meno nel buffer
	}
}

/* Funzione eseguita dal thread del consumatore */
void *consumer(void *arg) {
	while (TRUE) {
		down(&full);  // controlla se ci sono posti disponibili (se >0 va avanti)
		down(&mutex);  // se ci sono posti pieni, preleva il `mutex`
		
		remove_item();  // rimuove un elemento dal buffer
		print_buffer();  // stampa il contenuto del buffer
		
		up(&mutex);  // rilascia il 'mutex'
		up(&empty);  // segnala che c'è un posto vuoto in più nel buffer
	}
}
/*
RICORDA SEMPRE che un `down(&CAZZI)` è sbloccato da un `up(&CAZZI)`.
*/


int main() {
    pthread_t prod, cons;  // Dichiarazione dei thread
	
    // Inizializzazione dei semafori
    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, N);
    sem_init(&full, 0, 0);
	
    // Creazione dei thread
    pthread_create(&prod, NULL, producer, NULL); // sintassi vista in 'thread.c'
    pthread_create(&cons, NULL, consumer, NULL); // sintassi vista in 'thread.c'
    
    // Attesa della terminazione dei thread
    pthread_join(prod, NULL);  // sintassi vista in 'thread.c'
    pthread_join(cons, NULL);  // sintassi vista in 'thread.c'
	
    // Distruzione dei semafori
    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
	
    return 0;
}
```


### Spiegazione
##### Prendere o rilasciare il `mutex`
Funzioni che servono per rilasciare/prendere il `mutex`
```c
void down(sem_t *sem) {  // passo come argomento un semaforo
    sem_wait(sem);
}

void up(sem_t *sem) {   // passo come argomento un semaforo
    sem_post(sem);
}
```
Il `down`, se il valore del semaforo è $>0$, porta il valore del semaforo a 0 e indica che quel semaforo è stato preso.
L'`up`, se il valore del semaforo è $0$, porta il valore a 1 e indica che il semaforo è stato rilasciato.

##### Cose strane nel `produceitem()`
```c
printf("\nInserisco %d in posizione %d\n", item, (in + 1));
```
Perché `(in + 1)`? Per far capire all'utente medio, la posizione "0" è strana.

###### Inizializzazione dei semafori
```c
sem_init(&mutex, 0, 1);
sem_init(&empty, 0, N);
sem_init(&full, 0, 0);

// Sintassi
int sem_init(sem_t *sem, int pshared, unsigned int value);
```
- `sem_t *sem` è il puntatore al semaforo che voglio inizializzare
	
- `int pshared` specifica se il semaforo è condiviso tra **thread** o **processi**
	- `0` = il semaforo è condiviso tra thread dello stesso processo
	- `1` (o altri valore maggiori di 1) = il semaforo è condiviso tra processi diversi
	
- `unsigned int value` è il valore iniziale del semaforo