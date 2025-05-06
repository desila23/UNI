## 1. Tipo di funzione obiettivo

- Se è **minimizzazione**, cambia il segno → diventa **massimizzazione**. 
	- in pratica $min$ -> $- max$ (e tutti i segni cambiati)
- Se è già **massimizzazione**, lascia tutto così.

---

## 2. Tipo di vincolo (porta tutto a $=$)

Per ogni vincolo:
- Se è $\geq$, aggiungi la variabile di ***surplus*** e sottraila alla fine.
- Se è $=$, lascialo così:
- Se è $\leq$, aggiungi la variabile di ***slack*** e sommala alla fine.

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
- vincoli **tutti $=$**,
- variabili **tutte $\geq 0$**.


