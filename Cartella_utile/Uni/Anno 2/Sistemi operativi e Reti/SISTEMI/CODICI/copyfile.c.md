### Descrizione
Questo programma copia un file di input in un file di output utilizzando **syscall di basso livello** per la gestione dei file. 
È progettato per essere eseguito da riga di comando e include un controllo errori di base e una reportistica minima.

### Codice
```c
#include <sys/types.h>  // supportàle syscall come "open", "read", "write"
#include <fcntl.h>  // dà definizioni per controllare i file ("O_RDONLY")
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define BUF_SIZE 4096   // Dimensione del buffer: 4096 byte
#define OUTPUT_MODE 0700    // Bit di protezione per file di output
                            // 0700 = RWX per il proprietario
#define TRUE 1


// Prototipo della funzione main secondo lo standard ANSI
int main(int argc, char *argv[]);


int main(int argc, char *argv[]) {
    int in_fd, out_fd;   // File descriptor per i file di input e output
    int rd_count, wt_count;  // Contatori per la lettura e scrittura
    char buffer[BUF_SIZE];   // Buffer per la lettura e scrittura dei dati
	
    // Controllo del numero di argomenti
    if (argc != 3) {
        // Stampa un messaggio di errore se il numero di argomenti non è corretto
        fprintf(stderr, "Errore di sintassi. Uso: %s input_file_path output_file_path\n", argv[0]);
        exit(1);   // con (1) indico che l'operazione NON È terminata con successo
    }
	
    // Apertura del file di input
    in_fd = open(argv[1], O_RDONLY);  // Apre il file di origine in sola lettura
    if (in_fd < 0) exit(2);  // Se non può aprirlo, esce {(2) = (1)}
	
    // Creazione del file di output
    // Nota: equivalenza tra
    // - creat(path, mode);
    // - open(path, O_WRONLY | O_CREAT | O_TRUNC, mode);
    
    out_fd = creat(argv[2], OUTPUT_MODE);  // Crea il file di destinazione
    if (out_fd < 0) exit(3);  // Se non può crearlo, esce
	
    // Ciclo di copia
    while (TRUE) {
        rd_count = read(in_fd, buffer, BUF_SIZE);  // Legge un blocco di dati
        if (rd_count <= 0) break;  // Se fine del file o errore, esce dal ciclo
		
        wt_count = write(out_fd, buffer, rd_count);  // Scrive i dati
        if (wt_count <= 0) exit(4);  // wt_count <= 0 è un errore
    }
	
    // Chiusura dei file
    close(in_fd);
    close(out_fd);
	
    if (rd_count == 0) exit(0);  // Nessun errore sull’ultima lettura
    else exit(5);  // Errore sull’ultima lettura/scrittura
	
	/*
	* - rd_count == 0 -> è uscito dal primo "if" nel "while" e tutto ok
	* - rd_count < 0 -> è uscito dal primo "if" nel "while" per un errore
	* - rd_count > 0 -> è uscito dal secondo "if" nel "while" per un errore
	*\
}
```

###### SPIEGAZIONE
Partiamo dalla sintassi che devo avere su CMD
```
NOME_PROGRAMMA FILE_ORIGINE FILE_DESTINAZIONE
```
Quindi io devo passare 
- 3 argomenti  -  `int argc = 3`
- Quali sono questi tre argomenti?  -  `char *argv[] = [PERCORSO_FILE, FILE_ORIGINE, FILE_DESTINAZIONE]`

>[!tip]- Esempio reale
>```
>programma input.txt output.txt
>```
>
>Posso mettere anche il percorso file
>```
>programma "C:\documenti\progetti\file_input.txt" "D:\risultati\output.txt"
>```

Dato che la sintassi richiede 3 argomenti, devo fare il controllo con l'if
```c
if (argc != 3)
```
Se non sono esattamente 3, stampa un errore (sul buffer degli errori `stderr`) e esce.


Apro il file di origine in sola lettura e gli assegno un **file descriptor**
```c
in_fd = open(argv[1], O_RDONLY);  
if (in_fd < 0) exit(2);
```
Se non riesce ad aprirlo, e quindi il file descriptor ha un valore minore di 0, esce (ricorda che in `exit` qualsiasi numero diverso da `0` da errore).


Creo il file di destinazione mettendo come permessi **0700** e gli assegno un file descriptor
```c
out_fd = creat(argv[2], OUTPUT_MODE);
if (out_fd < 0) exit(3);
```
Se non può crearlo, esce.


Effettiva funzione di copia
```c
while (TRUE) {
    rd_count = read(in_fd, buffer, BUF_SIZE);  
    if (rd_count <= 0) break;  
		
    wt_count = write(out_fd, buffer, rd_count);
    if (wt_count <= 0) exit(4);
}
```
- **Leggo i dati dal file di origine**
	La funzione `read` ha questa sintassi
	- file da dove leggere - `in_fd`
	- dove inserire i file letti - `buffer`
	- quanti dati deve inserire - `BUF_SIZE`
	Metto il numero effettivo di dati letti in `rd_count`
	Se arrivo alla fine del file oppure c'è un errore, esco dal `while`

- **Scrivo i dati sul file di destinazione**
	La funzione `write` ha questa sintassi
	- file su cui scrivere - `out_fd`
	- da dove leggere i dati - `buffer`
	- quanti dati inserire - `rd_count`
	Se il file originale fosse stato vuoto oppure se si fosse verificato un errore, esce

>[!tip]- Funzionamento pratico
>###### Caso 1: Buffer grande, file piccolo
>- **File di input**: `"CIAO"`
>- **`BUF_SIZE`**: 10
>
>1. Prima chiamata a **`read()`**:
  >  
>    - Prova a leggere fino a 10 byte.
>    - Il file contiene solo 4 byte ("CIAO"), quindi legge 4 byte.
>    - **`rd_count = 4`**.
>2. **`write()`**:
>    
>    - Scrive **4 byte** nel file di output.
>3. Seconda chiamata a **`read()`**:
>    
>    - Raggiunge la fine del file.
>    - **`rd_count = 0`**, il ciclo si interrompe.
>
>###### Caso 2: Buffer piccolo, file grande
>
>- **File di input**: `"CIAO MONDO"`
>- **`BUF_SIZE`**: 4
>
>1. Prima chiamata a **`read()`**:
>    
>    - Legge 4 byte: `"CIAO"`.
>    - **`rd_count = 4`**.
>2. **`write()`**:
>    
>    - Scrive **4 byte** nel file di output.
>3. Seconda chiamata a **`read()`**:
>    
>    - Legge altri 4 byte: `" MON"`.
>    - **`rd_count = 4`**.
>4. **`write()`**:
>    
>    - Scrive **4 byte** nel file di output.
>5. Terza chiamata a **`read()`**:
>    
>    - Legge i rimanenti 2 byte: `"DO"`.
>    - **`rd_count = 2`**.
>6. **`write()`**:
>    
>    - Scrive **2 byte** nel file di output.
>7. Quarta chiamata a **`read()`**:
>    
>    - **`rd_count = 0`**, il ciclo si interrompe.


>[!tip]- Tipi di exit
>   - `exit(1)`: Errore di sintassi (numero di argomenti errato).
>   - `exit(2)`: Errore nell'apertura del file di input.
>   - `exit(3)`: Errore nella creazione del file di output.
>   - `exit(4)`: Errore durante la scrittura.



