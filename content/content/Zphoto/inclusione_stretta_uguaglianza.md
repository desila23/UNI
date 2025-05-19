## ✅ Inclusione stretta e uguaglianza tra classi di complessità

---

### 🔴 L’unica inclusione stretta conosciuta: Gerarchia temporale

#### 📌 Teorema 6.15 (Gerarchia temporale)
Se $f(n)$ è time-constructible e 
$$
\lim_{n \to \infty} \frac{g(n) \log g(n)}{f(n)} = 0,
$$
allora:
$$
\text{DTIME}[g(n)] \subsetneq \text{DTIME}[f(n)]
$$

✅ Significato:
- Esiste un linguaggio $L$ che è **decidibile in tempo** $f(n)$ ma **non** in $g(n)$.
- Quindi $\text{DTIME}[f(n)]$ è **strettamente più potente** di $\text{DTIME}[g(n)]$.

---

#### 🔹 Conseguenza importante: Teorema 6.18
$$
\text{P} \subsetneq \text{EXPTIME}
$$

✔️ Questa è **l’unica inclusione stretta dimostrata** tra classi standard.
Tutte le altre inclusioni (come $\text{P} \subseteq \text{NP}$) sono ancora **improprie**.

---

### 🟣 L’unica uguaglianza dimostrata: determinismo = non determinismo nello spazio

#### 📌 Teorema 6.19
$$
\text{PSPACE} = \text{NPSPACE}
$$

🎯 Significato:
- Ogni linguaggio che può essere **accettato** da una macchina **non deterministica** con spazio polinomiale,
- Può essere anche **deciso** da una macchina **deterministica** con spazio polinomiale.

✔️ È un caso raro: nello spazio, determinismo e non determinismo **sono equivalenti** in potenza computazionale.

---

### 🧠 Conclusione

- ✅ Unica inclusione stretta conosciuta: $\text{P} \subsetneq \text{EXPTIME}$
- ✅ Unica uguaglianza nota: $\text{PSPACE} = \text{NPSPACE}$
- ❓ Tutte le altre relazioni (P vs NP, NP vs PSPACE...) restano **aperte**!
