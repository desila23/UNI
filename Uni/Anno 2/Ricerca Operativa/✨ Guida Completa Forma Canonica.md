## 1. Tipo di funzione obiettivo

- Se è **minimizzazione**, cambia il segno → diventa **massimizzazione**. 
	- in pratica $min$ -> $- max$ (e tutti i segni cambiati)
- Se è già **massimizzazione**, lascia tutto così.

---

## 2. Tipo di vincolo

Per ogni vincolo:
- Se è $\geq$, moltiplica tutto per $−1$ → diventa $\leq$.
- Se è $=$, spezzalo in **due vincoli**:
    - uno $\leq$
    - uno $\geq$ (che poi moltiplichi per $−1$ per avere $\leq$)
- Se è $\leq$, lascia così.

---

## 3. Variabili non positive o libere

Controlla ogni variabile:
- Se è **libera** (può essere negativa o positiva), riscrivi: $$x = u - v \quad \text{con} \quad u, v \geq 0$$
- Se è **vincolata $\leq 0$**, riscrivi: $$x = -y \quad \text{con} \quad y \geq 0$$
- Se è già $\geq 0$, non fare nulla.


---

## 4. Sostituire

- Sostituisci tutte le variabili modificate **dentro la funzione obiettivo** e **nei vincoli**.


---

## 5. Scrivi il problema finale

Deve essere:
- una funzione di **massimizzazione**,
- vincoli **tutti $\leq$**,
- variabili **tutte $\geq 0$**.


---

## ESEMPI
#### Funzione obiettivo con $min$ e una variabile libera
![[Pasted image 20250428162956.png]]![[Pasted image 20250428163033.png]]

#### Funzione obiettivo con $max$, una variabile libera e una variabile $\leq 0$ 
![[Pasted image 20250428163111.png|center]]![[Pasted image 20250428163135.png|center]]