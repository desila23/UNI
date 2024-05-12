>[!tip] CONOSCENZA PRELIMINARE
>Quando vedi scritto, ad esempio, $\Delta {s_i}$ non spaventarti per la $i$, quella serve per indicare in generale dei numeri.
>Mi spiego meglio.
>Quell'$\Delta {s_i}$ è uguale a $\Delta {s_1}$, $\Delta {s_2}$, $\Delta {s_3}$ e così via, quindi la $i$ viene messa per indicare che al suo posto poi andranno messi dei numeri.

Una curva $C$, che inizia in $A$ e finisce in $B$, è immersa in campo gravitazionale. Approssimiamo tale curva con una serie di segmenti consecutivi orientati (le frecce rosse) di lunghezza $\Delta s_i$. 
QUESTI SEGMENTI POSSONO ANCHE NON AVERE LA STESSA LUNGHEZZA.

Prendiamo adesso in considerazione un generico segmento tra quelli che vedi in figura. Associamo a tale segmento un vettore $\Delta \vec{s_i}$ che ha le seguenti caratteristiche: 
- modulo pari alla lunghezza del segmento,
- direzione e verso secondo quanto scelto (li scegli tu generalmente all'inizio). 
Quindi a ogni segmento $\Delta s_i$ è associato un vettore $\Delta \vec{s_i}$. 

Scelto un punto $P_i$ a caso individuiamo il vettore $\vec g_i$ del campo vettoriale passante per quel punto (NELL'IMMAGINE ABBIAMO SCELTO IL PUNTO $A$ E IL VETTORE $\vec g_i$ È LA FRECCIA IN BASSO).

![[Pasted image 20240512224441.png|390]]

Determiniamo il prodotto scalare
$$\vec g_{i} \cdot \Delta \vec s_i$$
Tale operazione viene effettuata per ognuno dei segmenti con cui abbiamo approssimato la curva. 

Determiniamo il prodotto scalare di tutti i prodotti scalari cioè
$$
\vec{g}_1 \cdot \Delta \vec{s}_1 + \vec{g}_2 \cdot \Delta \vec{s}_2 + \ldots + \vec{g}_i \cdot \Delta \vec{s}_{i} + \ldots + \vec{g}_n \cdot \Delta \vec{s}_n
$$
tale somma si indica con il simbolo $\Gamma_{A\to{B} \space \text {lungo} \space C} \space (\vec{g})$ quindi:
$$
\Gamma_{A\to{B} \space \text {lungo} \space C} \space (\vec{g})= \vec{g}_1 \cdot \Delta \vec{s}_1 + \vec{g}_2 \cdot \Delta \vec{s}_2 + \ldots + \vec{g}_i \cdot \Delta \vec{s}_{i} + \ldots + \vec{g}_n \cdot \Delta \vec{s}_n
$$
Usando una simbologia più compatta si scrive
$$
\Gamma_{A\to{B} \space \text {lungo} \space C} \space (\vec{g})= \sum_{i=1}^n \vec{g}_i \cdot \Delta \vec{s}_i
$$
e si legge "sommatoria per i che va da 1 a n di $\vec{g}_i$ prodotto scalare $\Delta \vec{s}_i$".

>[!tip] SPIEGAZIONE DELLA SOMMATORIA
>La sommatoria è un modo più carino per scrivere tante somme insieme (infatti la "forma compatta" è più bella di quella originale).
>Nella sommatoria abbiamo il valore in basso (in questo caso $i$) che va da un punto che scegliamo noi (in questo caso 1) fino ad un valore non meglio definito (in questo caso n). Se vedi la $i$ si trova sotto $g$ e sotto $\Delta \vec s$, questo vuol dire che devi riprendere la spiegazione che abbiamo visto all'inizio.

Supponiamo che un corpo di massa m si sposti da $A$ a $B$ lungo la curva $C$. Moltiplicando entrambi i membri della relazione precedente per la massa $m$ del corpo si ha:
$$
m \cdot \Gamma_{A\to{B} \space \text {lungo} \space C} \space (\vec{g}) = m \cdot \sum_{i=1}^n \vec{g}_i \cdot \Delta \vec{s}_i \space\Rightarrow\space m \cdot \Gamma_{A\to{B} \space \text {lungo} \space C} \space(\vec{g})=\sum_{i=1}^{n}m\cdot \vec{g}_i \cdot \Delta \vec{s}_i
$$
Poiché $\vec{F}_i = m \cdot \vec{g}_i$ si ha:
$$
m \cdot \Gamma_{A\to{B} \space \text {lungo} \space C} \space (\vec{g}) =\sum_{i=1}^n \vec{F}_i \cdot \Delta \vec{s}_i \space=\space W_{A\to{B} \space \text {lungo} \space C} \space\Rightarrow\space m \cdot \Gamma_{A\to{B} \space \text {lungo} \space C} \space (\vec{g}) =W_{A\to{B} \space \text {lungo} \space C}
$$
quindi
$$
\Gamma_{A\to{B} \space \text {lungo} \space C} \space (\vec{g}) \space=\space \frac{W_{A\to{B} \space \text {lungo} \space C}}{m}
$$
Cioè $\Gamma_{A\to{B} \space \text {lungo} \space C} \space (\vec{g})$ è il lavoro del campo per unità di massa durante l'intero percorso.


Per i campi gravitazionali si verifica sperimentalmente che il lavoro $W_{A\to{B} \space \text {lungo} \space C}$ non dipende dal percorso per andare da $A$ a $B$ ma dipende dalla posizione di $A$ e $B$ e quindi anche $\Gamma_{A\to{B} \space \text {lungo} \space C} \space (\vec{g})$ dipende solo dalla posizione di $A$ e $B$. Prese due curve $C_1$ e $C_2$ che uniscono $A$ a $B$ si ha:
$$\Gamma_{A\to{B} \space \text {lungo} \space C_1} \space (\vec{g}) = \Gamma_{A\to{B} \space \text {lungo} \space C_2} \space (\vec{g})$$

Si tratta di una proprietà molto importante perché esprime il fatto che il campo gravitazionale è conservativo; cioè:
$$\Gamma_{A \to B}\space (\vec{g}) \text{ non dipende dal percorso} \Leftrightarrow \text{campo conservativo}$$

# LA CIRCUITAZIONE DEL CAMPO GRAVITAZIONALE
Se la curva è chiusa $\Gamma_{A\to{B} \space \text {lungo} \space C} \space (\vec{g})$ viene chiamata circuitazione lungo la curva $C$ e si dimostra che essa ha un valore nullo. 
Questo è un modo equivalente per esprimere il fatto che il campo gravitazionale è conservativo; cioè:
$$\Gamma(\vec{g}) = 0 \Leftrightarrow \text{campo conservativo}$$
#### Dimostrazione 
Partendo da $A$ arriviamo a $B$ con due cammini qualsiasi (vedi figura), poiché il campo è conservativo si ha
$$\sum_{A \to B}^{(1)} \vec{g}_i \cdot \Delta \vec{s}_i = \sum_{A \to B}^{(2)} \vec{g}_i \cdot \Delta \vec{s}_i$$
$$\sum_{A \to B}^{(1)} \vec{g}_i \cdot \Delta \vec{s}_i - \sum_{A \to B}^{(2)} \vec{g}_i \cdot \Delta \vec{s}_i = 0$$

Poiché  $$\sum_{A \to B}^{(2)} \vec{g}_i \cdot \Delta \vec{s}_i = -\sum_{B \to A}^{(2)} \vec{g}_i \cdot \Delta \vec{s}_i$$si ha
$$\sum_{A \to B}^{(1)} \vec{g}_i \cdot \Delta \vec{s}_i + \sum_{B \to A}^{(2)} \vec{g}_i \cdot \Delta \vec{s}_i = 0$$
Cioè
$$\sum_{A \to A}^{(1)+(2)} \vec{g}_i \cdot \Delta \vec{s}_i = 0$$
quindi $$\Gamma(\vec{g}) = 0$$
![[Pasted image 20240512225852.png]]

# CARATTERISTICHE CAMPO GRAVITAZIONALE
Per quanto detto le caratteristiche fondamentali di un campo gravitazionale sono:
 - è un campo vettoriale; 
 - le sorgenti del campo gravitazionale sono le masse;
 - il flusso del campo gravitazionale attraverso una superficie chiusa è minore o uguale a zero ed è dato dalla seguente legge:   $$\Phi(\vec{g}) = -4\pi \space G \space{ m_{int.}}$$Legge di Gauss con $$G = 6.67 \cdot 10^{-11} \, \text{Nm}^2/\text{kg}^2$$dove $m_{int.}$ è la massa all'interno della superficie gaussiana.
- la circuitazione del campo gravitazionale è nulla, quindi$$\Gamma(\vec{g}) = 0$$cioè il campo gravitazionale è conservativo.

