# **TRACCE DI ESERCIZI IN C PER SISTEMI OPERATIVI**

---

## **PROCESSI**

### **ESERCIZIO 1**
Creare un programma che legge un file e conta le occorrenze di una parola nel seguente modo:
- Il primo processo legge dall’inizio alla metà e conta le occorrenze della parola.
- Il secondo processo legge dalla metà fino alla fine e conta le occorrenze della parola.
- Inviano poi il numero di occorrenze al processo padre, il quale le somma e le stampa a video.

>[!success]  [[content/Uni/Anno 2/Sistemi operativi e Reti/SISTEMI/PREPARAZIONE ESAME/PROCESSI/1. Conta_occorrenze_da_file|PROCESSI CHE LEGGONO OCCORRENZE FILE]]


---

### **ESERCIZIO 2**
Generare due processi figli che comunicano con il padre:
- Uno dei processi genera numeri casuali `[0-100]` ed invia al padre solo i numeri pari.
- L’altro processo genera numeri casuali `[0-100]` ed invia al padre solo i numeri dispari.
- Il padre fa la loro somma e quando la somma > 190, termina l’esecuzione dei figli.

>[!success] [[content/Uni/Anno 2/Sistemi operativi e Reti/SISTEMI/PREPARAZIONE ESAME/PROCESSI/2. Figli-PariDispari + Padre = 190|NUMERI GENERATI DA P1 E P2]]

---

### **ESERCIZIO 3**
Un processo padre genera due processi figli:
- Il primo processo figlio invia al padre un numero casuale da `0` a `100`.
- Il padre legge questo numero, lo moltiplica per un `k` casuale e lo manda al secondo figlio.
- Il secondo figlio legge il numero inviato dal padre e lo stampa a video.

>[!success] [[content/Uni/Anno 2/Sistemi operativi e Reti/SISTEMI/PREPARAZIONE ESAME/PROCESSI/3. Figlio1_estrae_Padre_moltiplica_Figlio2_stampa|NUMERO GENERATO DA P1, MOLTIPLICATO DAL PADRE, STAMPATO DA P2]]

---

### **ESERCIZIO 4**
Due processi leggono dallo stesso file che si trova all’interno di una directory (es. `/data/f.txt`):
- **Alternativa**: Usare `dirent` e `readdir` per leggere all’interno della directory e controllare se il file esiste o meno.
	- Controllare che il file sia in modalità lettura, altrimenti restituire errore.
- **Alternativa**: Invece di restituire un errore, cambiare i permessi al file con `chmod`.
	- Il primo processo legge dall’inizio del file fino a metà.
	- Il secondo processo legge dalla metà in poi.
	- I figli mandano il contenuto al padre.
	- Il padre lo stampa nel seguente formato: `[PID_FIGLIO] -> TESTO`.

---

### **ESERCIZIO 5**
Scrivere un programma che esegue la moltiplicazione tra matrici 3x3 usando la programmazione parallela:
- Il primo processo figlio computa la prima colonna.
- Il secondo processo figlio computa la seconda colonna.
- Il processo padre computa la terza colonna, riceve dai figli i due vettori colonna computati, compone la matrice finale e la stampa.

>[!success] [[content/Uni/Anno 2/Sistemi operativi e Reti/SISTEMI/PREPARAZIONE ESAME/PROCESSI/5. Moltiplicazione tra matrici|MOLTIPLICAZIONE TRA MATRICI]]

---

### **ESERCIZIO 6**
Generare due processi figli che comunicano con il padre:
- Uno dei processi genera numeri casuali `[0-50]` ed invia al padre solo i numeri multipli di `3`.
- L’altro processo genera numeri casuali `[51-100]` ed invia al padre solo i numeri multipli di `2`.
- Il padre stampa i numeri ricevuti ed esegue la loro somma quando la somma > `130`.

>[!success] [[content/Uni/Anno 2/Sistemi operativi e Reti/SISTEMI/PREPARAZIONE ESAME/PROCESSI/6. Somma_maggiore_130|SOMMA MAGGIORE 130]]

---

### **ESERCIZIO 7**
Scrivere un programma C che crea un processo figlio:
- Il padre legge un numero casuale e lo invia al figlio attraverso una pipe.
- Il figlio fa il quadrato del numero e lo invia nuovamente al padre solo se il quadrato è pari, attraverso la pipe.
- Il padre legge il numero e lo stampa.

>[!success] [[content/Uni/Anno 2/Sistemi operativi e Reti/SISTEMI/PREPARAZIONE ESAME/PROCESSI/7. Quadrato_pari|QUADRATO PARI]]

---

### **ESERCIZIO 8**
Scrivere un programma C che svolge le seguenti richieste:
- Un processo padre genera due processi figli. Ciascun processo inizializza un proprio array di `N` interi.
- Il primo processo invia al processo padre solo i numeri in posizioni pari, e il secondo processo solo i numeri in posizioni dispari.
- Il padre riceve questi numeri e li scrive in un array di `N` interi, mettendo in posizioni pari i numeri ricevuti dal primo figlio, e in posizioni dispari i numeri ricevuti dal secondo figlio.
- Il padre stampa l’array e calcola il max e il min.

>[!success] [[content/Uni/Anno 2/Sistemi operativi e Reti/SISTEMI/PREPARAZIONE ESAME/PROCESSI/8. Array posizioni|POSIZIONI IN UN ARRAY]]

---

### **ESERCIZIO 9**
Implementare un programma che utilizzi `fork` e pipe per la comunicazione tra processi:
- Il programma crea un file di testo e poi due processi figli.
- Un processo figlio scrive una sequenza di numeri interi pari nel file.
- L’altro processo figlio scrive una sequenza di numeri interi dispari nello stesso file.
- Il processo padre legge i dati dal file e li stampa a video.

>[!success] [[content/Uni/Anno 2/Sistemi operativi e Reti/SISTEMI/PREPARAZIONE ESAME/PROCESSI/9. Numeri in un file|NUMERI PASSATI AD UN FILE]]

---

## **THREAD**

### **MUTEX**

---

### **ESERCIZIO 1**
Scrivere un programma C che segue le seguenti specifiche:
- Il programma crea un buffer come array di `11` numeri interi, inizializzati a zero.
- Genera tre thread:
    - Il primo thread sceglie casualmente una cella del buffer e vi scrive il numero `+1`.
    - Il secondo thread sceglie casualmente una cella del buffer e vi scrive il numero `-1`.
    - Il terzo thread controlla se tutte le celle del buffer sono state inizializzate. In caso positivo, determina se il numero di celle contenenti `+1` è maggiore di quelle con `-1` e termina tutti i thread.
    - Mentre un thread accede al buffer, nessun altro deve accedervi. Ogni thread attende un tempo random tra `0` e `3` secondi. 

>[!success] [[content/Uni/Anno 2/Sistemi operativi e Reti/SISTEMI/PREPARAZIONE ESAME/MUTEX/1. Array con +1 e -1|ARRAY CON +1 E -1]]

---

### **ESERCIZIO 2**
Scrivere un programma con tre thread che risolvono il seguente problema:
- Un buffer di `n` elementi inizializzato a `-1` viene riempito nel seguente modo:
    - Il primo thread aggiunge nelle posizioni pari del buffer un numero casuale da `0` a `100`.
    - Il secondo thread aggiunge nelle posizioni dispari del buffer un numero casuale da `100` a `200`.
    - Il terzo thread modifica il buffer nel seguente modo:
        - `buff[0] = buff[0]`
        - `buff[1] = buff[1] + buff[0]`
        - `buff[2] = buff[1] + buff[2]`
- Utilizzare la mutua esclusione.

---

### **ESERCIZIO 3**
Scrivere un programma in C con tre thread che operano su due array di dimensione `N` inizialmente a `0`:
- Il primo thread scrive in un array `A` numeri casuali tra `1` e `150`, in posizioni randomiche.
- Il secondo thread scrive in un array `B` numeri casuali tra `150` e `300`, in posizioni randomiche.
- Il terzo thread calcola:
    - Il massimo e il minimo in `A` e `B`.
    - `max{max(A), max(B)}` e `min{min(A), min(B)}`.

---

## **SEMAFORI**

---

### **ESERCIZIO 1**
Due thread:
- Il produttore inserisce numeri pari da `0` a `100` in posizioni pari e numeri dispari da `100` a `200` in posizioni dispari in un buffer di `N` elementi inizializzato a `-1`.
- Il consumatore legge dal buffer un numero pari e uno dispari, li somma e stampa la somma.

---

### **ESERCIZIO 2**
Scrivere un programma in C che, data una stringa di `N` caratteri, crea `N/2` thread che stampano ciascuno un carattere della stringa in maiuscolo. Usare semafori binari o mutex.

---

### **ESERCIZIO 3**
Sei thread: uno scrittore e cinque lettori.
- Lo scrittore scrive su un buffer numeri dispari da `0` a `50` nelle posizioni pari e numeri pari da `50` a `100` nelle posizioni dispari.
- I lettori leggono coppie di numeri (pari, dispari), li sommano e stampano i risultati.