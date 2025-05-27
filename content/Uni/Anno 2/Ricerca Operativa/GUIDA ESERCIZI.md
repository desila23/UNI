## LISTA ESERCIZI
<<<<<<< HEAD
1. Un dato vettore può essere una base ammissibile?
2. Può esistere una soluzione di base ammissibile con $x_{2}$ e $x_{3}$ in base
3. Può esistere un vertice della regione ammissibile del problema con $x_{1}$ e $x_{2}$ strettamente positivi?
4. Può esistere una soluzione ottima con $x_{3}$ in base?
5. Può esistere una soluzione ottima con $x_{1}$ e $x_{2}$ strettamente positivi?
=======
1. Un dato vettore può essere una base ammissibile?  PISELLO
2. Può esistere una soluzione di base ammissibile con $x_{2}$ e $x_{3}$ in base
3. Può esistere un vertice della regione ammissibile del problema con $x_{1}$ e $x_{2}$ strettamente positivi? 
4. Può esistere una soluzione ottima con $x_{3}$ in base? 
5. Può esistere una soluzione ottima con $x_{1}$ e $x_{2}$ strettamente positivi? 
>>>>>>> origin/v4
6. Simplesso
7. Simplesso a 2 fasi
8. simplesso primale-duale a partire da una soluzione duale y
9. Verificare se le soluzioni del vettore dato sono ottime



---
### 1. Un dato vettore può essere una base ammissibile?
![[content/Zphoto/Pasted image 20250518151400.png]]
1) Prendo i ***vincoli ORIGINALI*** e sostituisco il ***vettore*** 
	- se i vincoli sono corretti -> proseguo oltre
	- se i vincoli NON sono corretti -> non può essere SBA -> fine
2) Faccio ***forma standard*** 
	- aggiungo slack/surplus
3) Sostituisco il vettore alla forma standard
	- trovo quanto valgono gli slack/surplus
4) Scrivo vettore finale
	- Vedo quanti vincoli avevo ORIGINARIAMENTE (`n`)
	- DEVO avere esattamente `n` variabili $\ne$ 0 nel vettore
		- le ho? è SBA
		- non le ho? non è SBA


### 2. Può esistere una soluzione di base ammissibile con $x_{2}$ e $x_{3}$ in base
![[content/Zphoto/Pasted image 20250518172033.png]]
1) Faccio forma standard
2) Metto $x_{2}$ e $x_{3}$ in base
	- ossia, pongo TUTTO tranne, $x_{2}$ e $x_{3}$, uguale a $0$ (e quindi cancello le variabili che non sono $x_{2}$ e $x_{3}$ dai vincoli)
3) Scrivo il sistema con i nuovi vincoli
4) Trovo il valore di $x_{2}$ e $x_{3}$
	- rispettano il dominio del problema originale -> Esiste soluzione ottima
	- non rispettano il dominio -> non esiste soluzione ammissibile


### 3. Può esistere un vertice della regione ammissibile del problema con $x_{1}$ e $x_{2}$ strettamente positivi?
![[content/Zphoto/Pasted image 20250518151410.png]]
1) Parto dalla ***forma standard*** (=)
2) Pongo <u>TUTTE</u> le variabili diverse da $x_{1}$ e $x_{2}$ UGUALI A 0
3) Risolvo il sistema ottenuto e trovo $x_{1}$ e $x_{2}$
	- $x_{1}$ e $x_{2}$ sono $>0$? 
		- **si -> esiste il vertice**
		- no -> non esiste il vertice


### 4. Può esistere una soluzione ottima con $x_{3}$ in base
![[content/Zphoto/Pasted image 20250518151416.png]]
1) Faccio il duale DIRETTAMENTE DAI VINCOLI ORIGINALI ![[content/Zphoto/Pasted image 20250517190624.png]]
2) Seleziono la riga che nel duale corrisponde a $x_{3}$ (quindi la terza riga)
3) vedo quanto vale $u_{i}$ (che io chiamerò $y_{i}$)
	- rispetta il dominio? (quello cerchiato in rosso)
		- **si -> esiste soluzione ottima**
		- no -> non esiste soluzione ottima

>[!problem] ATTENZIONE, potrei avere un vincolo con più di una $y_{i}$, tipo riga 1.
>In questo caso io devo applicare la complementarietà tra primale e duale, trovandomi i valori delle varie $y_{i}$ e poi eseguire il punto 3).
>Questa roba della complementarietà la vedi nell'esercizio 8.
 

### 5. Può esistere una soluzione ottima con $x_{1}$ e $x_{2}$ strettamente positivi?
![[content/Zphoto/Pasted image 20250518151431.png]]
1) Faccio il duale della formula ORIGINALE
2) Pongo i vincoli di $x_{1}$ e $x_{2}$ $> 0$, il resto $= 0$ (in pratica cancello tutti i vincoli tranne quelli di $x_{1}$ e $x_{2}$)
3) Trovo i valori di delle varie y
<<<<<<< HEAD
	- rispettano i domini del duale -> Esiste soluzione ammissibile
	- non rispettano i domini del duale -> Non esiste soluzione ammissibile
=======
	- rispettano i vincoli delle variabili -> Esiste soluzione ottima
	- non rispettano i vincoli delle variabili -> Non esiste soluzione ottima
>>>>>>> origin/v4


### 6. Simplesso
1) Forma standard
2) Metto tutto nel tableaux
	![[content/Zphoto/Pasted image 20250518154959.png|center|450]]
	- prendo il $\gamma_{i}$ di z più piccolo tra quelli $< 0$
	- Trovo il pivot (come nel tableaux del primale-duale)
	- Divido tutta la riga scelta per il pivot
		![[content/Zphoto/Pasted image 20250518155521.png]]
	- Cancello tutte le righe tranne
		- quella scelta
		- le righe che hanno nella colonna del pivot valore $=0$
		![[content/Zphoto/Pasted image 20250518155612.png]]
	- Per riscrivere le righe cancellate
		- parto dalla riga che voglio riscrivere
		- se voglio scrivere la `b` allora
			- prendo la `b` della riga in verde
			- la moltiplico per il valore (cambiato di segno) che si trova nella colonna verde e nella riga che voglio scrivere NEL TABLEAUX PRECEDENTE(es. riga `z`, prendo il suo valore originale di $x_{3}$ ($-(-5)$)) 
			- sommo questo valore con la casella del vecchio tableaux 
			- sostituisco questo valore nella corrispettiva casella nel tableaux nuovo
			![[content/Zphoto/Pasted image 20250518160057.png]]
3) Finito il tableaux controllo se TUTTI i $\gamma_{i}$ di `z` sono $\ge 0$
	- si -> fine simplesso e scrivo $B_{ot}$
	- no -> rifaccio di nuovo il tableaux PARTENDO DALL'ULTIMO TABLEAUX OTTENUTO


### 7. Simplesso a due fasi
>[!tip] Lo fai se devi sottrarre un ***surplus*** oppure se hai una base ***con più volte la stessa variabile***.
1) Forma standard
	- Trovo che la base non è ammissibile
2) FASE 1
	- riscrivo la forma standard aggiungendo `n` variabili artificiali quante sono le variabili in base "sbagliate" 
		- la funzione obiettivo sarà il ***min*** delle variabili artificiali con il - davanti  e sommate tra loro
		- aggiungo le variabili artificiali ai vincoli, sommate
	- scrivo il tableaux con le variabili artificiali
	- azzero le variabili artificiali
	- faccio simplesso
	- se arrivo ad avere che `z = 0` -> FASE 2
3) FASE 2
	- riscrivo l'ultimo tableaux ottenuto, togliendo le colonne delle variabili artificiali
	- se $\gamma < 0$ -> faccio simplesso
	- se $\gamma \ge 0$ -> fine -> scrivo $B_{ot}$


### 8. Eseguire primale-duale
1) Scrivo il ***primale*** (forma standard) 
	- ricorda di volerla portare sempre a ***min***
		- se la formula originale è ***max*** -> scrivi ***min*** e cambia <u>TUTTI</u> **i segni della funzione obiettivo**
2) Scrivo il ***duale*** del primale (vedi foto sopra)
3) Verifica ammissibilità duale
4) ITERAZIONE
	1) Scrivo le equazioni delle variabili
		- prendo i vincoli del duale
		- sposto il termine noto
		- pongo tutto $= 0$ 
		- metto il vincolo in una parantesi e moltiplico la variabile corrispondente
		
	2) Sostituisco il vettore dato dal prof 
		-  Se dentro la parentesi ho un valore $\ne 0$ -> $x_{i} = 0$
		- Se dentro la parentesi ho un valore $= 0$ -> non so quanto vale
		
	3) Faccio il ***primale ristretto***
		- parto dal primale
		- cancello tutte le variabili che prima ho trovato essere $= 0$
		- aggiungo tanti $a_{i}$ quante sono le variabili con le parentesi ($= 0$)
		
	4) Faccio il tableaux
		- scrivo l'equazione di `z`
		- scrivo l'equazione delle `a`
		
		- azzero le `a` sulla riga di `z` (sottraggo le righe)
		- controllo se ho qualche variabile sulla riga di `z` che è $\le 0$
			- se ce l'ho -> la porto in base
				- eseguo $min\{\frac {\beta_{i}} {\alpha_{i-entrante}} : \alpha_{i-entrante} > 0\}$ e trovo il pivot
				- divido tutta la riga per il pivot
				- scrivo la variabile in base
				- sottraggo la riga di `z` per la riga dove ho diviso $\alpha_{i}$
		- controllo quanto vale il valore di `z`
			- se $z^{*} = 0$ -> la base è ottima -> fine
			- se $z^{*} \le 0$ -> faccio il duale ristretto
		
	5) Faccio il duale del primale 
		- identico al duale ma le variabili che aggiungo sono $\pi_{i}$ 
		- prendo in considerazione le righe delle variabili che ho in base nell'ultimo tableaux
		- i valori che ho dopo il $\le$ corrispondono alle mie $\pi$
		
	6) Calcolo $y^{(1)} = y^{(0)} + \Theta \cdot \pi$ 
	7) Trovo il valore di $\Theta$
	8) Sostituisco $\Theta$ nel duale
	9) Faccio il grafico
		- Se ho tutti i vincoli $\le$ (oppure $\ge$), e quindi il grafico va tutto a sx (o tutto a dx) -> non ho soluzioni e il problema si dice illimitato -> fine
		- Se ho anche un solo vincolo diverso dagli altri -> scelgo il valora più piccolo MA NON POSSO PRENDERE I NEGATIVI
	10) Cambio base
	11) RIINIZIO L'ITERAZIONE


### 9. Verificare se le soluzioni del vettore dato sono ottime (applica complementarietà tra primale e duale)
1) Applico vettore ai vincoli ORIGINALI
	- i vincoli sono corretti? È ammissibile -> continuo
	- i vincono NON sono corretti? Non è ammissibile -> stop
2) Scrivo il duale partendo dai vincoli ORIGINALI
3) Creo due sistemi
	1) Sistema per le $y$, dove metto dentro le parentesi i vincoli originali con il termine noto spostato e pongo tutto uguale a 0
		- esempio $$y_{1}(-x_{1}+x_{2}+1)=0$$
		- ATTENZIONE: se un vincolo originale era un'uguaglianza ($=$) non lo devi inserire nel sistema
	2) Sistema per le x, dove faccio la stessa cosa del sistema di prima solo prendendo i vincoli del duale
		- ATTENZIONE: se un vincolo nel duale era un'uguaglianza lo riscrivo così com'è nel sistema
4) Mi trovo i vari valori delle y
	- se ho $y(0) = 0$ -> si dice ***satura***
	- se ho $y(\text{valore} \ne 0)$ = 0 -> allora $y = 0$ e posso usarla nel secondo sistema
5) Una volta trovati tutti i valori delle $y$ vedo se rispettano il dominio dei vincoli
	- Li rispettano -> verifico per dualità forte
	- Non li rispettano -> la soluzione non è ottima
6) Dualità forte
	- sostituisco i valori delle $x$ nella funzione obiettivo originale 
	- sostituisco i valori delle $y$ nella funzione obiettivo del duale
		- sono uguali -> è ottima
		- non sono uguali -> non è ottima