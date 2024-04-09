### Argomenti

- Dominio digitale e analogico
- Linguaggi, livelli e macchine virtuali
- Evoluzione delle architetture di computer
- Tipologie di computer
- Storia della famiglia intel
- Unità metriche

### Analogico
Tutto ciò che è tangibile:
- Le info intorno a noi sono analogiche, suoni, colori, tatto…
- Le informazioni di memoria venivano memorizzate in modo analogico(vinile)

### Digitale

- Informazioni vengono codificate attraverso dei valori discreti

> I valori discreti possono dare gli stessi dati dei valori continui(analogici)?
> 
> ## Teorema del campionamento
> 
> Quei campioni se vengono selezionati in un intervallo breve quando ricostruiamo il segnale non perdiamo informazioni, tipo il ping nei giochi

# Conversioni tra domini

![](https://likingaxis.github.io/UNI/UNI/UTILITY/WhatsApp-Image-2024-03-05-at-16.30.08.jpeg)

### Il computer è una macchina elettronica digitale in grado di risolvere problemi attraverso un insieme di istruzioni assegnate (il programma)

- Il calcolatore usa 0 e 1
- Il calcolatore ha una **CPU**

# il problema della distanza concettuale

Il calcolatore è composto da **layer** fino a quando non raggiunge un livello che è comprensibile dall’essere umano, macchine e linguaggi via via più sofisticati tra layer e layer ![](https://likingaxis.github.io/UNI/UNI/UTILITY/Screen-Shot-2024-03-05-at-11.21.25.png)

> Tip
> 
> L=linguaggio M=macchina

- **Traduzione**:
    - un modo per eseguire un programma scritto in L1 è sostituire ogni istruzione di L1 in L0 e viene definita traduzione
    - il programma L1 è tradotto nel linguaggio L0 e funziona esclusivamente su quella determinata M
    - L1 può essere eliminato una volta che viene tradotto in L0
- **Interpretazione**:
    - quando hai un programma in L0 che accetta input da L1, le istruzioni verranno eseguite man mano e ci sarà un interprete che le cambierà
    - L1 e L0 sono entrambi utili perché vengono usati allo stesso tempo

# La Cipolla

Si crea uno schema a cipolla con una gerarchia di linguaggi astratti e macchine virtuali corrispondenti ogni programma del livello n deve essere tradotto per il livello n-1 

![](https://likingaxis.github.io/UNI/UNI/UTILITY/Pasted-image-20240305121402.png)

## Architettura multilivello attuale

5. **Linguaggi ad alto livello**: c++, java e altri;
4. **Linguaggio assemblativo** che usano i programmatori(assembly);
3. È un **mix di istruzioni** che vengono eseguite o dal microprogramma o dal sistema operativo, una sorta di ponte tra i due;
2. **Microprogramma**, controlla le operazioni nel percorso dei dati e le interpreta;
1. **Micro-architettura**, la memoria locale è fatta di collezioni di 8-32 registri, quest’ultimi sono connessi all’ALU attraverso un percorso dati(data path)
0. Parte fisica, porte logiche e i registri(combo di porte logiche)

- Livelli 4 e 5 sono del programmatore;
- Livelli da 0 a 3 linguaggio macchina;
![](https://likingaxis.github.io/UNI/UNI/UTILITY/Screen-Shot-2024-03-05-at-11.39.27.png)

> Cos'è l'**ALU**?
> 
> ALU(arithmetic logic unit) esegue le operazioni aritmetiche e logiche

## Differenza tra Hardware e Software
- Hardware tangibile
- Software intangibile, astratto

Hw e Sw sono logicamente equivalenti qualsiasi operazione fatta dal software può essere svolta dal’Hw e viceversa

# Un po’ di storia:

- 1940 i primi computer digitali con solo due livelli, ISA e livello logico digitale
- 1951 si passò a computer a 3 livelli
- 1960 invenzione sistema operativo un software in grado di gestire l’hardware
- 1970 utilizzo di micro-codice permise la creazione di istruzioni più efficienti per programmare

# Le varie generazioni di computer:

## Computer di generazione zero:

Erano meccanici:
- **Macchina di Pascal**, svolgeva somme e sottrazioni
- **Macchina di Leibniz**, svolgeva moltiplicazioni e divisioni
- **Macchina analitica di Babbage**, legge e scrive dati nelle schede perforate tipo con delle matrici, con fori attraverso un foto-diodo che con le luci indicava 0 e 1
- **Primi computer a relè** con mark 1 e mark 2, con i segnali elettrici che indicano 0 e 1

## Prima generazione:

- **Computer Colossus** utilizzato da turing a valvole termoioniche 1945
- **Macchina di Von Neumann** IAS ha una ALU che usa il registro accumulatore per fare le operazioni, memoria, CU(control unit), input e output

## Seconda generazione:

Uso di transistor digitali e non analogici:
- **TX-0 e PDP-1**, sfruttavano i bus che, insieme ai transistor, formano una vera e propria architettura “moderna”, con comunicazione multipla
- **Omnibus**, primo pc che usava il bus

### Cosa è il bus?

Si tratta di un **insieme di linee condivise tra i vari componenti del calcolatore** permette di far comunicare ogni componente direttamente da un unico flusso ![](https://likingaxis.github.io/UNI/UNI/UTILITY/Screen-Shot-2024-03-05-at-14.19.47.png)

Condividere un unico bus rende le macchine scalabili al posto di fare un intreccio. Si va incontro ad un corto circuito perché bisogna sincronizzare le comunicazioni: se due componenti parlano allo stesso tempo si fotte tutto **ESPLODEE AIUTOOOO!!!!!!** perché si mixano delle tensioni diverse(concetto master-slave)

## Terza generazione:

- Circuiti integrati 1965-1980 ibm system/360, pdp-11

## Quarta generazione:

- (Very large scale integration) 1980-? con tecnologia VLSI si stampano milioni di transistor su un singolo chip / IBM pc, apple Lisa intel 8080 8088 80386, arrivano alle case di tutti con floppy disk

## Quinta generazione:

- Computer invisibili in elettrodomestici, orologi, carte di credito, giocattoli

# Legge di Moore

> Il numero dei transistor nei componenti raddoppia ogni 18 mesi fino agli anni 2000 poi per problemi di surriscaldamento, consumi e altro non è più attuale questa legge

![](https://likingaxis.github.io/UNI/UNI/UTILITY/Screen-Shot-2024-03-05-at-14.25.09.png)

> Per risolvere il problema si decise di fare più core con architetture multi core più cpu insieme.
> **Più core ≠ più potenza** perché dipende:
> - da come lo gestisce il SO;
> - dalla sincronizzazione tra questi core

# Tipologie di computer

- **Computer usa e getta**: chip all’interno di cartoline di auguri che hanno un basso costo (chip RFID)
- **Micro-controllori**: computer che non sono elaboratori(elettrodomestici, giocattoli)
- **Dispositivi mobili e da gioco**: macchine con capacità grafiche e sonore, non espandibili e non programmabili dall’utente
- **Personal computer**: macchine destinate all’informatica individuale
- **Server**: computer potentissimi che si connettono alla rete con alta velocità e sono, mono o multi-processore dotate di hard disk capienti
- **Cluster**: insieme di server connessi insieme da reti
- **Mainframe** : computer un tempo super potente ormai obsoleto usato da banche e inail

# La storia di intel

Nel 1968 costruì il primo chip 4004 in silicio. 
La frequenza non è sempre indice di velocità soprattutto su architetture diverse.

## Ogni chip ha una memoria, a che serve?

È una memoria molto veloce che memorizza elementi vicini ad uno specifico **??????** che ci serve così da raggiungerlo in fretta; se ripeto un’istruzione e la ho nella memoria della CPU andrà più veloce una memoria per ogni singolo core. 

>N.B.
>**Più potenza significa più tensione e più calore difficile da smaltire**

# Le unità metriche

Per i dati si usa base due (binaria).
**1kb** di memoria contiene **1024 Byte** NON 1000 Byte

![](https://likingaxis.github.io/UNI/UNI/UTILITY/Screen-Shot-2024-03-05-at-16.42.54.png) esercizi sul suo libro che si possono fare:
- esercizi sui sistemi di enumerazione
- algebra di boole
- sistemi di emning bho

## Stack pila architettura dei livelli

- **Livello astratto**: hai una visione astratta attraverso una sintesi di quello che c’è sotto (guidi la macchina con volante frizione ecc...);
- **Information hiding**(interfaccia): quando applichi il metodo passi i parametri ma non vedi l’algoritmo
