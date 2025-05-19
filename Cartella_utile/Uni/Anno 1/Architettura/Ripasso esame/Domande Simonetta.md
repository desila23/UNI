# ARCHITETTURE DI CALCOLATORI
1) ==***Il teorema del campionamento assicura che l'approssimazione discreta di un segnale analogico a banda limitata, è senza perdita di informazione utile se...***== 
	Vengono presi due campioni ad una distanza molto breve. Noi sappiamo che proprio a livello fisico la perdita di dati è un fattore da tenere in considerazione quando si parla di trasmissione di segnali. Se vengono presi due segnali ad una distanza "considerevole" non si riesce a capire il reale andamento del segnale, perché appunto vengono persi dei dati importanti; se invece prendiamo due campioni in un lasso di tempo molto breve, e ripetiamo questa operazione per un quantitativo di volte che riteniamo sufficiente, potremmo ricostruire l'andamento del segnale nel modo quanto più fedele possibile (ovviamente non in modo perfetto).


2) ==***La macchina di von Neumann è composta da?***== 
	Memoria principale, ALU, unità di controllo e dispositivi di I/O. La macchina di VN fa parte della seconda generazione di computer (assieme alla macchina di Turing, il computer ENIAC) ed è stata la prima macchina al cui interno era presente una componente che noi oggi chiamiamo CPU (ALU + Unità di controllo). 
	Una classica macchina di VN è costituita da una serie di registri (da 1 a 32), che si collegano ai due registri di input dell'ALU che si occupano di trasmettere informazioni da registri ad ALU, dopo l'unità è presente il registro di output collegato poi ai registri iniziali. 
	La CPU può eseguire due tipologie di istruzioni:
	- registro-memoria, in cui il dato, presente inizialmente in memoria, viene caricato nei registri prima di poter essere utilizzato
	- registro-registro, in cui il dato è presente direttamente nei registri


3) ==***Quanti byte ci sono in 1 KB di memoria?***== 
	1 KB = 1024 BYTE


4) ==***Cosa sono il Program Counter e l'Instruction Register?***== 
	Si tratta dei due registri principali dell'ALU.
	- Il PC punta all'istruzione successiva 
	- Nell'IR è contenuta l'istruzione corrente 


5) ==***Da quanti passaggi si compone il ciclo fetch-decode-execute?***== 
	Si compone di 7 passaggi principali:
	1. Viene cercata l'istruzione puntata in precedenza dal PC e una volta trovata viene caricata nell'IR
	2. Viene aggiornato il PC, che punta ad un'altra nuova istruzione
	3. Si decodifica l'istruzione 
	4. Si verifica se l'istruzione necessita di un'altra informazione presente in memoria
	5. QUALORA servisse si cerca quell'informazione e si inserisce all'interno di un registro della CPU
	6. Si esegue l'istruzione
	7. Si ricomincia il ciclo


6) ==***Quali sono i principi di progettazione per i computer moderni?***== 
	Quando si progetta un computer al giorno d'oggi si deve tener contro di alcuni principi fondamentali:
	- Tutte le istruzioni devono essere svolte direttamente dall'HW, nel caso di architetture CISC (complex instruction set computer) le istruzioni possono essere divise in istruzioni più piccole
	- Le istruzioni devono avere lunghezza fissa ed essere corte, oltre a dover essere di tipologie molto simili
	- Solo le operazioni di LOAD e STORE devono poter accedere in memoria, questo perché esse accedono SOLO alla RAM.
	- Almeno 35 registri


7) ==***Un processore SIMD è costituito da?***== 
	Sono costituiti da un vasto numero di processori identici che svolgono le stesse istruzioni su dati differenti (super computer vettoriali)


8) ==***Per calcolare la distanza di Hamming tra due parole, quale operazione si deve utilizzare?***== 
	Si utilizza lo XOR bit a bit tra le due parole

9) ==***In un hard disk le prestazioni dipendono da?***== 
	Esistono 3 tipi tempi:
	- **Tempo di seek**: di circa 5/10 ms è il tempo che impiega la testina per posizionarsi nella parte giusta;
	- **Latenza rotazionale**: il disco deve girare per trovare l’informazione giusta con **rpm** (rotazioni-per-minuto) con latenza tra 3-6 ms;
	- **tempo di trasferimento**: tempo necessario per il passaggio dei dati al cervello della macchina con un tempo di 3,5/4 µs (micro-secondi). 


10) ==***In un CDROM un settore è costituito da quanti frame? Cosa contengono?*==** 
	Un settore è composto da 98 frame e i frame contengono tutti i simboli (pit e land) che vengono codificati in byte 


11) ==***Quali sono la principale differenza tra DVD e CD?==*** 


12) ==***Per quali valori di A e B l'uguaglianza A+B = A B è verificata?***== 
	Questa uguaglianza è verificata solamente se A=B, questo perché A+B darà 0 se entrambi sono 0 e darà uno se sono entrambi 1 (ovviamente l'or da uno anche quando uno dei due sono 1), allo stesso modo l'AND


13) ***==Quando si può utilizzare un multiplexer per realizzare una qualsiasi funzione logica?==*** 
	Quando utilizzo in input le due porte logiche universali, ossia NAND E NOR.


14) ***==Un decoder è un circuito combinatorio che può essere utilizzato per?==*** 
	Per abilitare l'uscita corrispondente alla codifica decimale del valore binario dato in input.


15) ==***In un circuito digitale è possibile collegare due uscite insieme?==*** 
	Di norma io non posso collegare due uscita MA utilizzando il buffer three state oppure una porta NOR si.


16) ***==Elencare le caratteristiche delle ROM==*** 
	È la memoria NON volatile, ossia la memoria principale che rimane anche dopo lo spegnimento del dispositivo. È saldata in memoria


17) ==***Per incrementare la larghezza di banda di un bus occorre?***== 
	Si potrebbe ampliare la dimensione del bus pur sacrificando spazio disponibile, oppure aumento la velocità del ciclo di clock.


18) ==***In un Pentium 4 i principali segnali di risposta del bus sono?***== 
	Sono dei pin che usa il bus slave per comunicare con il bus master
	- **RS**#, contiene il codice di stato, ovvero un codice che mostra lo stato corrente della CPU o del processo che sta eseguento
	- **TRDY**#, indica che lo slave è pronto ad accettare dati dal master
	- **BNR**#, asserisce uno stato di attesa quando il dispositivo indirizzato non può rispondere


19) ***==Descrivere lo schema adottato dalla CPU UltraSPARC III per la gestione della cache***== 
	L'ultra Sparc utilizza un approccio con due memorie cache, ossia le memorie in cui vengono inseriti i dati utilizzati recentemente dalla CPU.
	La prima chace è interna e i dati sono ordinati secondo una gerarchia di importanza, mentre la seconda è esterna e sono presenti tutti quei i dati che per mancanza di spazio non sono potuti rientrare nella prima con l'unica differenza che qui non è presente alcuna gerarchia.


20) ==***Descrivere l'integrato 8051==*** 
	È uno dei microcontrollori più diffusi. Un micro controllore è un circuito integrato che viene utilizzato per svolgere dei semplici e veloci compiti al posto della CPU.
	L'8051 ha 32 linee di I/O e 40 pin, tra cui i più importanti sono
	- A, che specifica quale indirizzo è necessario per poter svolgere una certa istruzione
	- D, che specifica il tipo di dato richiesto
	- RD, abilità la lettura
	- WR, abilita la scrittura
	- ALE, che controlla che sul bus indirizzi ci sia l'indirizzo corretto
	- PSEN, che si asserisce quando viene utilizzata una memoria esterna
	- EA, che può abilitare l'utilizzo di una memoria esterna, e può essere
		- ALTO, permette l'utilizzo di memoria sia interna che esterna
		- BASSO, permette l'utilizzo solo della esterna


21) ==***Descrivere il memory-mapped I/O***== 
	Quando si parla di memory-mapped si fa riferimento al modo in cui i dispositivi di I/O ESTERNI vengono rilevati. Abbiamo due modi:
	- Port-mapped, in cui i dispositivi vengono visti come memorie esterne e quindi hanno una loro memoria principale (es. stampanti)
	- Memory-mapped, in cui i dispositivi sono riconosciuti come componente aggiuntiva della memoria principale e quindi condividono gli stessi indirizzi della memoria del dispositivo (es. hard disk esterno)

22) **Microistruzioni del MIC 1***
	Il MIR contiene la microistruzione corrente, che viene divisa in tante piccole componenti:
	- Addr, contiene l'indirizzo della potenziale prossima microistruzione
	- JAM, determina come viene eseguita la prossima microistruzione
	- ALU, determina che tipo di operazione deve eseguire la ALU
	- C, abilità la scrittura dal BUS C ai registri indicati
	- Mem, determina eventuali accessi in memoria
	- B, abilita la scrittura dai registri indicati al BUS B


# SISTEMI OPERATIVI
22) ==Quali funzioni ha un Sistema Operativo?== 
	Il SO ha la funzione di fare da tramite tra l'HW e la GUI, ossia la guest unit interface. Il sistema operativo si occupa di gestire tutte quelle risorse HW che possono essere utilizzate dalla GUI.
	Tra le funzioni abbiamo i sistemi di sheduling e di gestione della memoria.

23) ==In un Sistema Operativo le principali astrazioni sono?== 
	Astrazioni di tutte le componenti HW, tipo astrazione memoria, I/O, processi con i thread, shell e protezione dei dati

24) ==Un processo è un concetto chiave presente in ogni Sistema Operativo, si può definire come?== 
	Il processo è definito come un'istanza di un programma in esecuzione, con i riferimenti al PC, stack, registri e variabili.

28) ==In quale circostanza sono creati nuovi processi? E in quale altra termina un processo?== 
	Il processo viene creato all'avvio di un programma, per via dell'utente o di altre caratteristiche; termina a causa di un errore o quando termina tutte le task.

29) ==Quali sono gli stati di un processo?== 
	I processi possono trovarsi in 3 stati principali:
	- Attesa, quando il processo attende una risorsa presente in memoria
	- Pronto, quando il processo ha tutte le risorse necessarie ma non può ancora essere avviato (tipo perché c'è un processo con più priorità)
	- Esecuzione, quando il processo sta venendo eseguito

31) ==Quando accade una corsa critica?== 
	Accade quando più processi o thread tentano di accedere alla stessa risorsa.

32) ==In un ambiente concorrente per evitare le corse critiche si possono definire delle condizioni, quali?== 
	Mutex e semafori binari.

33) ==In quale circostanza è conveniente avviare lo scheduling?== 
	Quando si hanno più processi e si devono gestire nella maniera più adeguata.

34) ==Gli algoritmi di scheduling posso essere divisi in due categorie, quali?== 
	Non preemptive, quando il processo viene avviato e lasciato in esecuzione finché non finisce.
	Preemptive, quando il processo può essere interrotto.

35) ==Quali sono gli algoritmi di scheduling nei sistemi batch?== 
	Un sistema in cui non abbiamo quasi per nulla interazione con l'utente
	First come first served
	Shortest job first
	Shortest remaining time next

36) ==Supponendo di disporre dei seguenti tempi di esecuzione T0, T1, T2 e T3 nell'algoritmo shortest process next con tecnica di aging, quale sarà la stima per T4?== 
	$\frac {T_{3}} {2}$  + $\frac {T_{2}} {4}$  + $\frac {T_{1}} {8}$ + $\frac {T_{0}} {8}$    

37) ==Per consentire a più applicazioni di essere in memoria allo stesso tempo senza interferire devono essere risolti due problemi, quali?== 
	La non astrazione e la non paginazione 

39) ==Qual è la struttura di una riga della tabella delle pagine?== 
	Numero di frame
	Bit di presenza/assenza
	Flag R e M

41) ==Nell'algoritmo Not Recently Used (NRU) la classe 0 è..== 
	Un indicatore che indica che la pagina non è stata referenziata.

42) ==Quando il sistema operativo non è coinvolto con la paginazione?== 
	Quando non abbiamo astrazione.

43) ==I programmatori sanno che tecnica di gestione della memoria (paginazione o segmentazione) è utilizzata?== 
	IPOTETICAMENTE si.

44) ==Perché è stata inventata la paginazione?== 
	Per semplificare la gestione dei processi presenti nella RAM

45) ==Perché è stata inventata la segmentazione?== 
	Per necessità.

55) ==Quali sono le principali categorie di dispositivi di I/O?== 
	Input: tastiera, mouse, fotocamera
	output: monitor, stampante e altoparlante
	input e output: modem e hard disk

56) ==Quali sono gli svantaggi del port-mapped I/O?== 
	Lo svantaggio qui può essere che i dispositivi sono visti come memorie esterne e quindi possono derivare problemi di velocità (i dispositivi di I/O sono più lenti) e di priorità.

57) ==Quali sono gli svantaggi del memory-mapped I/O?== 
	Occupa e consuma memoria RAM, è difficile da implementare

60) ==Quali sono le tecniche di gestione degli I/O?== 
	Si possono usare delle interfacce PIO, ad esempio il controllore 8255A, che comunica con la CPU. 

62) ==Quali sono i fattori che compromettono il tempo necessario a leggere o scrivere un blocco del disco?== 
	I tempi di seek, latenza rotazionale e trasferimento dei dati.

64) ==In un computer con un clock di 10 GHz che distanza possono percorrere i segnali elettrici?== 
	

65) ==Per incrementare drasticamente le performance di un calcolatore che architetture occorre progettare?== 
	Le istruzioni devono essere eseguite dall'HW e quindi in caso di istruzioni CISC si può dividere l'istruzione in piccole microistruzioni
	Le istruzioni devono essere della stessa lunghezza e corte
	Solo LOAD e STORE possono accedere in memoria
	Più pipeline, aumentare il ciclo ci clock.

66) ==In un'architettura UMA con rete di commutazione a più stadi di tipo omega con n CPU, n memorie and log2n stadi, con n/2 switch per stadio, complessivamente di quanti switch abbiamo bisogno?== 
	n/2 log2n

68) ==Quali sono gli approcci per il Sistema Operativo adottati dai multiprocessori?== 
	Utilizzando algoritmi di scheduling

69) ==Qual è un potenziale problema in un algoritmo di scheduling a condivisione del tempo su un multiprocessore?== 
	Il fatto che tutte le CPU vogliano accedere al vettore contenente i processi, quindi si presenta una corsa critica.

70) ==Che cosa si intende per diametro in un multicomputer?== 
	Percorso più lungo tra i nodi.

72) ==Qual è il vantaggio di utilizzare un'architettura di multicomputer ad ipercubo?== 
	È scalabile e il diametro è log2n

73) ==Quali sono i vantaggi della virtualizzazione?== 
	Tramite le instanze garantiamo sicurezza, non dobbiamo preoccuparci di eventuali problemi all'HW.