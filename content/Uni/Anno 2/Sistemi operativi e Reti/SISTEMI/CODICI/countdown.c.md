### Descrizione
Programma in C che stampa una sequenza di numeri in ordine decrescente da 20 a 1, aspettando un intervallo di tempo casuale tra una stampa e l'altra (0-2 secondi). 
Alla fine, stampa la scritta `BYE`.

### Codice
```c
#include <stdio.h>     // Libreria standard per input/output (printf, fflush, ecc.)
#include <unistd.h>    // Contiene funzioni per interagire con SO (es. sleep)
#include <stdlib.h>    // Include funzioni utili come srand() e rand()
#include <time.h>      // Necessaria per lavorare con il tempo (es. time())


int main() {
    // Inizializza il generatore di numeri casuali
    srand(time(NULL));
	
    for (int i = 20; i >= 1; i--) {
        printf("%d\n", i);
        fflush(stdout);  // Assicura che l'output venga visualizzato 
                         // immediatamente
	
        // Dormi per un tempo casuale tra 0 e 2 secondi
        sleep(rand() % 3);
    }
	
    printf("\nBYE\n");
    fflush(stdout);  // garantisce che "BYE" venga sempre stampato, 
                     // indipendentemente dal comportamento del buffering
	
    return 0;
}
```
### Output
![[coutdown.mp4]]

### Spiegazione
```c
srand(time(NULL));
```
- `srand` inizializza il generatore di numeri casuali e garantisce che ogni esecuzione del programma generi numeri casuali diversi (serve a `rand()`)
- `time(NULL)` restituisce il numero di secondi trascorsi dall'1 gennaio 1970 (bohhhh)


```c
for (int i = 20; i >= 1; i--) {
    printf("%d\n", i);
    fflush(stdout); 
	
    sleep(rand() % 3);
}
```
Stampa il valore di `i`
- `fflush(stdout)` garantisce che il buffer di output venga svuotato immediatamente, così i numeri vengano mostrati subito sullo schermo (`stdout`).
	
- `rand()` è il generatore di numeri pseudo-casuali e si basa su un algoritmo deterministico e ha bisogno di un "seme"
	- SENZA `srand()` il "seme" sempre lo stesso (generalmente 1, dettato dal compilatore)
	- CON `srand()` il "seme" cambia ogni volta
	
	`rand() % 3` prende il valore generato da `rand` e lo divide per 3, i possibili output sono
	- 0, se il numero è divisibile per 3
	- 1, se il resto della divisione è 1
	- 2, se il resto delle divisione è 2
	
- `sleep()` "interrompe" il `for` per il tempo definito da `rand() % 3`
