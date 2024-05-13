 Il concetto di campo gravitazionale, introdotto da Faraday nel 1846, descrive uno spazio non neutro che agisce da mediatore delle forze tra masse. Diversamente dalla visione di Newton di un'azione a distanza senza intermediari, il campo gravitazionale viene visualizzato come una distribuzione di vettori di forza, definita operativamente attraverso l'uso di una massa esploratrice, per ogni punto dello spazio esaminato, e per ognuno di questi punti si definisce la forza
$\overrightarrow{F}$ che agiste sulla massa.

**FORMULA CAMPO GRAVITAZIONALE**:
$$\vec{g} = \frac{\vec{F}}{m_0}$$

### LINEE DI FORZA DI UN CAMPO GRAVITAZIONALE
Le linee di forza del campo gravitazionale, concepite per facilitare la visualizzazione della distribuzione del campo, sono curve che si orientano in base alla direzione e intensità del vettore di campo gravitazionale in ciascun punto, diventando più dense dove il campo è più intenso e meno dense dove è meno intenso. Importante è notare che queste linee non si incrociano mai.
Lo spostamento del punto è segnato come $\Delta s$.

  ![[Pasted image 20240512210026.png|300]]![[Pasted image 20240512210046.png|265]]

### Campo di una sfera con massa uniforme
Se con M indichiamo la massa della sfera ed r la distanza della massa esploratrice $m_0$ dal centro della sfera si ha:
$$F = G \frac{M \cdot m}{r^2} \quad \text{per } r \geq R
$$
poiché $g = \frac{F}{m_0}$ si trova:
$$g = G \frac{M}{r^2} \quad \text{per } r \geq R
$$
![[Pasted image 20240512210530.png| center | 300]]


# FLUSSO DEL CAMPO GRAVITAZIONALE
La dimostrazione che segue immaginatela e basta.
Una superficie aperta (senza bordi) $A$ è immersa in un campo gravitazionale. Ora "tagliamo" questa superficie in tanti piccoli rettangoli piani di area $\Delta a_i$ (fig. 11), ognuno indica quindi una parte della superficie originale. QUESTI RETTANGOLO POSSONO ANCHE NON AVERE TUTTI LE STESSE DIMENSIONI.
![[Pasted image 20240513194614.png|center|200]]

>[!example] UN PICCOLO ESEMPIO PER CAPIRE
>Immagina le corazze medievali del soldati, erano formate da tante piccole piastre di diverse dimensioni che poi componevano l'armatura vera e propria.

Ora stabiliamo a piacere un verso di percorrenza di queste superfici, e poi questo verso sarà anche quello della superficie più grande.
Prendiamo ora una qualsiasi superficie di area $\Delta a_i$ e associamo ad essa un vettore $\Delta \vec a_i$ con le seguenti caratteristiche:
- modulo (lunghezza) pari alla misura della superficie
- direzione perpendicolare alla superficie
- verso stabilito dalla regola della mano destra
Quindi ogni area avrà un vettore.
![[Pasted image 20240513201421.png|center|400]]


>[!tip] REGOLA DELLA MANO DESTRA
>Questa regola permette di determinare il verso del prodotto vettoriale $$\vec v \space \times \space \vec w$$ anch'esso un vettore.
>Per farlo si usano tre dita della mano destra, pollice, indice e medio, che vanno disposte nel modo seguente:
>- il pollice deve seguire il verso e la direzione di $\vec v$, ossia il primo vettore coinvolto nel prodotto vettoriale;
>- indice va in corrispondenza di $\vec w$, il secondo vettore del prodotto vettoriale
>- il medio va disposto perpendicolarmente al palmo della mano
>ll verso del dito medio coincide con il verso del prodotto vettoriale (nel nostro caso di  $\Delta \vec a_i$)
>
>![[Pasted image 20240513200952.png|center|400]]

Prendiamo ora un punto $P_{i} \in \Delta \vec a_i$ a caso (che si legge $P_i$ ***APPARTENTENTE*** ad $\Delta \vec a_i$).
Individuiamo il vettore $\vec g (P_i)$ del campo gravitazionale passante per quel punto e determiniamo il prodotto scalare: $$\vec g (P_{i)}\space \cdot \space \Delta \vec a_i$$
E tale operazione viene effettuata per ogni superficie piccola.
Si definisce ***flusso*** la somma di tutti i prodotti scalari tra i vettori aree $\Delta a_{i}$ ed i relativi vettori campo gravitazionale $\vec g (P_i)$, cioè:
$$\Phi_\Omega(\vec{g}) = \vec{g}(P_1) \cdot \Delta \vec{a}_1 + \vec{g}(P_2) \cdot \Delta \vec{a}_2 + \ldots + \vec{g}(P_n) \cdot \Delta \vec{a}_n
$$
che può essere scritto come:
$$\Phi_\Omega(\vec{g}) = \sum_{i=1}^n \vec{g}(P_i) \cdot \Delta \vec{a}_i
$$

La superficie non è chiusa, quindi si stabilisce che tutti i vettori superfici $\Delta \vec a_i$ siano orientati verso l'esterno.
Le superfici chiuse vengono chiamate anche ***guassiane***.


# LEGGE DI GAUSS
È una nuova formulazione della legge universale e trae grandi vantaggi da situazioni caratterizzate da una certa simmetria. Di fondamentale importanza nella legge di Gauss è una ipotetica superficie curva chiusa chiamata ***superficie gaussiana***. 
![[Pasted image 20240513202846.png|center|300]]

La legge di Gauss mette in relazione i campi su una superficie gaussiana con le masse racchiuse al suo interno. Essa afferma che il flusso è proporzionale alla somma delle masse presenti all’interno della superficie chiusa.
La sua formula matematica è:
$$\Phi_\Omega(\vec{g}) = -4\pi G m_{\text{int.}}$$
dove −4𝜋𝐺−4πG è la costante di proporzionalità.
Nella figura sotto riportata per entrambe le superfici è:
$$\Phi_\Omega(\vec{g}) = -4\pi G \cdot (3m) = -12\pi G$$
![[Pasted image 20240513203140.png||center|400]]
Quindi il flusso attraverso una superficie chiusa può essere determinato in due modi:
- 