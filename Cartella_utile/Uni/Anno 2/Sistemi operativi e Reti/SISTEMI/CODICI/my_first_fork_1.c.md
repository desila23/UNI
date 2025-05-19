```c
#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h> 

#define STDIN 0
#define STDOUT 1
#define PIPE_RD 0 
#define PIPE_WR 1


int main(){
	
	int pid, child_status;  
	
	pid = fork();
	
	if ((pid == 0) {  // se pid == 0, sono nel figlio
    	printf("I am the child and I see the PID %d\n", pid);
	} 
	else {  // se pid > 0, sono nel padre (ha l'ID del figlio)
		wait(&child_status); // Wait for child
		printf("I am the parent, I see the child's PID (%d) and the status (%d)\n", pid, child_status);
	}
}
```

### Spiegazione
```c
wait(&child_status);
```
Il padre si mette in attesa che un figlio termini e poi salva il processo del figlio in `childstatus`
- `0` = terminato con successo
- `<0`  = c'è stato un errore
Il `wait` ha questa sintassi `pid_t wait(int *status);`.
Questo valore poi lo userà nel `printf`.

