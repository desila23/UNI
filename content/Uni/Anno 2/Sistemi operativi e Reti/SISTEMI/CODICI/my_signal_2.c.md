### Funzionamento
Il codice inizia a stampare "I am running" e dopo 1 secondo (`alam(1)`), questo allarme viene gestito dall'`alarm_handler` che stamperà a schermo e chiuderà il programma con successo (`exit(0)`).

### Codice
```c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>  // Per strsignal()


void alarm_handler(int signal) {
    printf("In signal handler: caught signal %d which is %s!\n", signal, 
           strsignal(signal));
    exit(0);
}

int main(int argc, char **argv) {
    signal(SIGALRM, alarm_handler);
    alarm(1); // alarm will send signal after 1 sec
	
    while (1) {
        printf("I am running!\n");
    }
	
    return 0;
}
```


### Funzionamento
Identico a [[content/Uni/Anno 2/Sistemi operativi e Reti/SISTEMI/CODICI/my_signal_1.c]]

```c
alarm(1);
```
Non ho un segnale ma ho un allarme, che viene inviato in automatico dopo tot secondi (qui 1).

>[!tip] RICORDA
>Prima metto i segnali/allarmi e come gestirli, così vengono salvati in memoria quando si verificano.
>POI metto il codice effettivo.
