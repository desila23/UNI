### Funzionamento
Il classico funzionamento del produttore-consumatore ma il buffer non è un array ma una variabile che cambia valore ogni volta che il produttore produce un numero.

### Codice
```c
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 10  /* Quantità di numeri da produrre */

/* Dichiarazione di mutex e variabili condizionali */
pthread_mutex_t the_mutex;
pthread_cond_t condc, condp; // Usate per segnalare tra produttore e consumatore 

int buffer = 0;  /* Buffer utilizzato tra produttore e consumatore */


/* Funzione del produttore */
void *producer(void *ptr) {
    int i;
    for (i = 1; i <= MAX; i++) {
        pthread_mutex_lock(&the_mutex);  // Ottiene l'accesso esclusivo al buffer 
		
        /*
        NOTA: La ragione per cui viene utilizzato un ciclo while invece di un 
        semplice if è legata alla necessità di gestire le cosiddette "false 
        sveglie" (spurious wakeups) che possono accadere con pthread_cond_wait. 
        Ci assicuriamo che ogni volta che il thread viene svegliato, 
        ricontrolli effettivamente la condizione.
        */
        while (buffer != 0) {
            pthread_cond_wait(&condp, &the_mutex);
        }
		
        buffer = i;  /* Inserisce l'elemento nel buffer */
        printf("Producing:\t%d\n", i);
        sleep(rand()%2);  /* simulo una produzione più realistica */
        pthread_cond_signal(&condc);  /* Sveglia il consumatore */
        pthread_mutex_unlock(&the_mutex);  /* Rilascia l'accesso al buffer */
    }
	
    pthread_exit(0);  /* se tutto è andato bene termino senza errori */
}

/* Funzione del consumatore */
void *consumer(void *ptr) {
    int i;
    for (i = 1; i <= MAX; i++) {
        pthread_mutex_lock(&the_mutex);  // Ottiene l'accesso esclusivo al buffer
		
        while (buffer == 0) {  /* come il while sopra */ 
            pthread_cond_wait(&condc, &the_mutex);
        }
		
        printf("Consuming:\t%d\n", i); /* simulo l'atto di consumatione */
        buffer = 0;  /* Preleva un elemento dal buffer e lo reinizializza */
        sleep(rand()%2);
        pthread_cond_signal(&condp);  /* Sveglia il produttore */
        pthread_mutex_unlock(&the_mutex);  /* Rilascia l'accesso al buffer */
    }
	
    pthread_exit(0);
}


int main(int argc, char **argv) {
    pthread_t pro, con;  /* Threads del produttore e consumatore */
	
    /* Inizializzazione di mutex e variabili condizionali */
    pthread_mutex_init(&the_mutex, NULL);
    pthread_cond_init(&condc, NULL);
    pthread_cond_init(&condp, NULL);
	
    /* Creazione dei threads */
    pthread_create(&con, NULL, consumer, NULL);
    pthread_create(&pro, NULL, producer, NULL);
	
    /* Attesa che i threads completino l'esecuzione */
    pthread_join(pro, NULL);
    pthread_join(con, NULL);
	
    /* Pulizia e distruzione di mutex e variabili condizionali */
    pthread_cond_destroy(&condc);
    pthread_cond_destroy(&condp);
    pthread_mutex_destroy(&the_mutex);
	
    return 0;
}

```


### Spiegazione
##### Tipi strani
```c
pthread_mutex_t the_mutex;
pthread_cond_t condc, condp;  
```
`pthread_mutex_t` indica che la variabile è un mutex.
`pthread_cond_t` sostituisce le variabili `empty` e `full`, serve per comunicare tra produttore e consumatore.

##### Funzioni strane
```c
pthread_mutex_lock(&the_mutex);
```
Una funzione specifica della libreria `pthread` che serve per bloccare la variabile inizializzata come "mutex".

##### While particolari
```c
while (buffer != 0) {
    pthread_cond_wait(&condp, &the_mutex);
}
```
Il produttore si mette in attesa di un segnale `condp` dal consumatore e rilascia il mutex (`the_mutex`), permettendo al consumatore di lavorare.


##### Inizializzazioni più specifiche
```c
pthread_mutex_init(&the_mutex, NULL);
pthread_cond_init(&condc, NULL);
pthread_cond_init(&condp, NULL);

// Sintassi
int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);
int pthread_cond_init(pthread_cond_t *cond, const pthread_condattr_t *attr);
```
Queste sono funzioni più specifiche che servono per inizializzare sia il `mutex` che le `condizioni`, E NEGLI ARGOMENTI DEVO PASSARE MENO INFORMAZIONI PERCHÉ LA FUNZIONE È SPECIFICA.
Il secondo parametro `const pthread_mutexattr_t *attr` sono i classici attributi ma a noi non servono e mettiamo `NULL`

>[!tip] DIFFERENZE CON ALTRE INIZIALIZZAZIONI
>In [[content/Cartella_utile/Uni/Anno 2/Sistemi operativi e Reti/SISTEMI/CODICI/producer_consumer_semaphore.c]] e in [[content/Cartella_utile/Uni/Anno 2/Sistemi operativi e Reti/SISTEMI/CODICI/reader_writer_semaphore.c]]si utilizzavano queste funzioni
>```c
>sem_init(&mutex, 0, 1);
>sem_init(&empty, 0, N);
>sem_init(&full, 0, 0);
>sem_init(&db, 0, 1);
>```
>Perché andavamo a creare semafori generici e poi li inizializzavamo come `mutex`, `condition` ecc.
