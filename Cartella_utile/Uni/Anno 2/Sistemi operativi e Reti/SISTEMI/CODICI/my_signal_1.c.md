### Funzionamento
Programma che utilizza un **signal handler** per gestire il segnale `SIGINT`, che è inviato al processo quando premi **CTRL+C**.


### Codice
```c
#include <stdio.h>    // Per funzioni di input/output come `printf`
#include <stdlib.h>   // Per funzioni di utilità come `exit`
#include <signal.h>   // Per la gestione dei segnali
#include <unistd.h>   // Per funzioni come `sleep`
#include <string.h>   // Per strsignal()


// Funziona di gestore dei segnali
void signalHandler(int signum) {
    printf("Interrupt signal %d received which is %s\n", signum, 
           strsignal(signum));
    // cleanup and terminate program
    exit(signum);
}


int main() {
    // register signal SIGINT and signal handler
    signal(SIGINT, signalHandler); // CTRL+C
	
    while(1) {
        printf("Going to sleep...\n");
        sleep(1);
    }
	
    return 0; // questa riga non verrà mai raggiunta a causa del ciclo while(1)
}
```


### Spiegazione
##### Gestore dei segnali
```c
void signalHandler(int signum) {
    printf("Interrupt signal %d received which is %s\n", signum, 
           strsignal(signum));
    // cleanup and terminate program
    exit(signum);
}
```
- `signum` è il numero del segnale ricevuto (ad esempio, `SIGINT` è tipicamente il numero `2`)
- `strsignal(signum)` restituisce una descrizione leggibile del segnale (ad esempio, `"Interrupt"` per `SIGINT`)
- `exit(signum)` termina L'INTERO programma restituendo il numero del segnale come codice d'uscita


##### Registrazione del Signal Handler
```c
signal(SIGINT, signalHandler);
```
Registra la funzione `signalHandler` come gestore del segnale `SIGINT` (segnale del `CTRL + C`).
In pratica dice "Tu, `signalHandler`, sei incaricato di gestire `SIGINT`".


##### Ciclo infinito
```c
while(1) {
    printf("Going to sleep...\n");
    sleep(1);
}
```
Il codice stampa "Going to sleep..." ogni secondo (`sleep(1)`) finché non premi `CTRL + C`.


>[!tip] RICORDA
>Prima metto i segnali/allarmi e come gestirli, così vengono salvati in memoria quando si verificano.
>POI metto il codice effettivo.