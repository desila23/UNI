### Funzionamento
Implementiamo il problema "scrittore/lettore"
- solo uno scrittore
- tanti lettore (possono accedere uno alla volta sul database ma possono leggere tutti insieme).

### Codice
```c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

#define TRUE 1
#define NUM_READERS 3  // Numero di lettori


sem_t mutex;  // Semaforo per l'accesso esclusivo a rc
sem_t db;     // Semaforo per l'accesso esclusivo al database
int rc = 0;   // Numero di processi che leggono o vogliono leggere



void down(sem_t *sem) {
    sem_wait(sem);
}

void up(sem_t *sem) {
    sem_post(sem);
}


void read_database() {
    printf("Leggendo dal database...\n");
    sleep(1); // Simulazione lettura dal database
}

void write_database() {
    printf("Scrivendo nel database...\n");
    sleep(1); // Simulazione scrittura nel database
}


void use_data_read() {
    printf("Utilizzando i dati letti...\n");
    sleep(1); // Simulazione dell'utilizzo dei dati
}

void think_up_data() {
    printf("Pensando ai dati da scrivere...\n");
    sleep(1); // Simulazione del processo di pensare ai dati
}


void *reader(void *arg) {
    while (TRUE) {
        down(&mutex);  // Ottiene accesso esclusivo a rc, in modo da non avere 
                       // interferenze da altri lettori
		
        rc++;  // Un lettore in più
		
        if (rc == 1) down(&db);  // Se è il primo lettore, blocca accesso al DB
		
        up(&mutex);  // Rilascia accesso esclusivo a rc 
		
        read_database();  // Legge dal database
		
        down(&mutex);  // Ottiene accesso esclusivo a rc, in modo da non avere 
                       // interferenze da altri lettori
		
        rc--;  // Un lettore in meno
		
        if (rc == 0) up(&db);  // Se è l'ultimo lettore, "sblocca" accesso al DB
		
        up(&mutex);  // Rilascia accesso esclusivo a rc
		
        use_data_read();  // Usa i dati letti (Nota: siamo fuori da zona critica)
    }
}

void *writer(void *arg) {
    while (TRUE) {
        think_up_data();  // Il processo "finge" di elaborare i dati da scrivere
		
        down(&db);  // Ottiene accesso esclusivo al database
		
        write_database();  // Scrive nel database
		
        up(&db);  // Rilascia accesso esclusivo
    }
}

int main() {
	// INIZIALIZZAZIONI VARIABILI LETTORI E SCRITTORI
    pthread_t readers[NUM_READERS], writer_thread;
	
	
	// INIZIALIZZAZIONE SEMAFORI
    sem_init(&mutex, 0, 1);
    sem_init(&db, 0, 1);
	
	
	// CREAZIONI DI LETTORI E SCRITTORE
    // Lettori
    for (int i = 0; i < NUM_READERS; i++) {
        pthread_create(&readers[i], NULL, reader, NULL);
    }
	
    // Scrittore
    pthread_create(&writer_thread, NULL, writer, NULL);
	
	
	// JOIN PER LETTORI E SCRITTORE
    // Lattori
    for (int i = 0; i < NUM_READERS; i++) {
        pthread_join(readers[i], NULL);
    }
	
    // Scrittore
    pthread_join(writer_thread, NULL);
	
	
	// DISTRUGGO I SEMAFORI
    sem_destroy(&mutex);
    sem_destroy(&db);
	
    return 0;
}
```