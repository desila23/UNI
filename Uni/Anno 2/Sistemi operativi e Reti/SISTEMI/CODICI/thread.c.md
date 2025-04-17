### Codice
```c
#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>

// Definisci una costante per il numero di thread da creare
#define NUMBER_OF_THREADS 10


// Funzione che verrà eseguita da ogni thread
void * print_hello_world(void * tid) {
	// Genera un numero casuale tra 0 e 4 (quanti secondi far dormire il thread)
	int r = rand()%5; 
	
	// Fa dormire il thread per un numero casuale di secondi 
	sleep(r);
	
	// Stampa un messaggio con l'ID del thread
	printf("Hello World. Greetings from thread %d\n", tid);
	
	// Termina il thread e restituisce NULL
	pthread_exit(NULL); 
}


int main(int arg, char* argv []) {
	// Dichiarazione di un array di thread
	pthread_t threads[NUMBER_OF_THREADS]; // pthread_t è tipo generics
	int status, i;
	
	// Ciclo per creare NUMBER_OF_THREADS thread
	for (i=0; i < NUMBER_OF_THREADS; i++) {
		
		// Crea un nuovo thread e assegna la funzione print_hello_world come 
        // funzione di avvio
		status = pthread_create(&threads[i], NULL, print_hello_world, (void * ) i);
		// RICORDA, la funzione `pthread_create` restituisce un valore
		
		if (status == 0){
			// Stampa l'ID del thread creato e il suo stato
			printf("Process %d created with status %d\n", i, status);
		}
		// Se ci sono problemi nella creazione del thread, stampa un messaggio di 
        // errore e termina il programma
		else{
			printf("Problems while creating process %d\n", i);			
			exit (-1);
		}
	}
	
	// Ciclo per attendere che tutti i thread terminino
	for (i=0; i < NUMBER_OF_THREADS; i++) {
		status = pthread_join(threads[i], NULL);
		// Anche qui restituisco un valore
		
		// Stampa l'ID del thread che ha terminato e il suo stato
		printf("Process %d terminated with status %d\n", i, status);
		
		// Se ci sono problemi nell'attesa del thread, stampa un messaggio di 
        // errore e termina il programma
		if (status != 0){
			printf("Problems while waiting for process %d\n", i);			
			exit (-1);
		}
	}
	
	// Termina il programma principale
	return 0; 
}
```


### Spiegazione
##### Cose strane nel primo `for`
Creazione dei thread.
```c
status = pthread_create(&threads[i], NULL, print_hello_world, (void * ) i);

// Sintassi originale
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
```
PARAMETRI
- **`pthread_t *thread`** puntatore a una variabile `pthread_t` dove verrà salvato l'identificatore del nuovo thread.
	- `&threads[i]`, nel nostro caso la posizione `i` nell'array
	
- `const pthread_attr_t *attr` puntatore a una struttura di attributi del thread
	- `NULL` usato per utilizzare gli attributi predefiniti
	
- `void *(*start_routine)(void *)` puntatore alla funzione che verrà eseguita dal thread
	- `print_hello_world` noi vogliamo eseguire la funzione che abbiamo creato
	
- `void *arg` puntatore a un dato passato come argomento alla funzione del thread
	- dato che noi vogliamo passare la posizione nell'array, che è di tipo `int`, usiamo il casting (`void *`) per farla diventare un puntatore a `void`


### Cose strane nel secondo `for`
Attesa di fine esecuzione dei thread.
```c
status = pthread_join(threads[i], NULL);

// Sintassi originale
int pthread_join(pthread_t thread, void **retval);
```
PARAMETRI
- **`pthread_t thread`** è l'identificatore del thread di cui si vuole attendere la terminazione.
	
- **`void **retval`** un puntatore a un puntatore dove verrà memorizzato il valore restituito dal thread.
	- Può essere `NULL` se non ti interessa recuperare il valore restituito dal thread.