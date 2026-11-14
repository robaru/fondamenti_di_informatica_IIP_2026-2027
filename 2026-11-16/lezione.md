# Lezione 2026-11-16 — Ripasso: scriviamo Jump

Un gioco nel terminale: una rana 🐸 salta (barra spaziatrice) gli oggetti che arrivano da destra.
Si lavora in **gruppi di 2–3, un computer per gruppo**: uno scrive, l'altro legge la missione e controlla.
Ci si scambia a ogni missione.

## Scaletta

| Ora | Cosa | Chi lavora |
|---|---|---|
| 12:30 | Un volontario gioca a `jump_8_volanti`; si formano i gruppi | tutti |
| 12:40 | Ripasso alla lavagna | gruppi |
| 12:55 | Fase 1 e Fase 2 | gruppi, poi confronto |
| 13:15 | Pausa | |
| 13:25 | Missioni 1–4: il gioco funziona | gruppi |
| 14:10 | Pausa | |
| 14:20 | Missioni 5–7: funzioni, struct, numeri casuali | gruppi |
| 14:50 | Chiusura (missioni 8 e 9 per chi ha finito, o per casa) | gruppi |

## Ripasso alla lavagna (15 min)

1. Tre minuti, senza appunti: ogni gruppo scrive tutto quello che sa fare in C.
2. A turno, ogni gruppo detta una voce alla lavagna, finché non ce ne sono più.
3. Aggiungere un esempio di una riga solo dove manca qualcosa.

Colonne della lavagna: variabili e tipi · `if` e `switch` · cicli · funzioni · array e stringhe · `struct` · `rand`.

La lavagna resta lì per tutta la lezione: si mette una spunta ogni volta che una missione usa una voce.

## Fase 1: quali sono le componenti logiche? (10 min)

Vietate le keyword del C.

1. Cosa succede in **un singolo fotogramma**, passo per passo?
   - leggo la tastiera, sposto giocatore e oggetto, disegno, controllo lo scontro, aspetto un attimo
2. Cosa deve **ricordare** il programma?
   - altezza e velocità del giocatore, posizione dell'oggetto, punti
3. Cosa **si ripete**? Sapete in anticipo quante volte?
   - i fotogrammi: no; le righe e le colonne del disegno: sì
4. **Quando finisce** la partita?
   - quando il giocatore tocca l'oggetto, oppure quando si preme `q`
5. Cosa può **andare storto**?
   - saltare mentre si è già in aria; l'oggetto che esce dallo schermo; il gioco che si ferma ad aspettare un tasto

## Fase 2: quale costrutto C serve? (10 min)

I gruppi collegano ogni pezzo logico a una voce della lavagna.

| Pezzo logico | Costrutto C | Perché |
|---|---|---|
| Ripetere i fotogrammi | `while` | non so quante volte |
| Disegnare lo schermo | due `for` annidati | 7 righe, 30 caselle |
| Cosa c'è in una casella | `if` / `else if` / `else` | rana, oggetto o vuoto |
| Altezza, velocità, punti | variabili `int` | cambiano a ogni fotogramma |
| Saltare solo da terra | `if` con `&&` | due condizioni insieme |
| Fine partita | `if` + `break` | esco dal ciclo |
| Disegno e scontro | funzioni | il `main` resta corto |
| Giocatore e oggetto | `struct` | variabili che stanno insieme |
| Nome e simbolo dell'oggetto | stringhe dentro la `struct` | un'emoji non sta in un `char` |
| Tre oggetti | array di `struct` + `for` | stesso codice per tutti |
| Ultimo oggetto superato | stringa + `strcpy` | una stringa non si copia con `=` |
| Oggetti sempre diversi | `rand()` | numeri casuali |
| Dove entra il nuovo oggetto | massimo di un array | dietro all'oggetto più a destra |
| Oggetti volanti | un membro in più: `quota` | sotto si passa senza saltare |
| Leggere un tasto | ??? | `scanf` aspetta Invio! |

L'ultima riga porta a `gioco.h`: funzioni già scritte, da usare come `printf` senza sapere come sono fatte.

```c
inizia_gioco(60, 10);   // prepara il terminale (una volta, all'inizio):
                        // se è più piccolo di 60 colonne x 10 righe, esce con un messaggio
tasto_premuto();        // il tasto premuto, oppure 0 se non c'è: non aspetta!
torna_in_alto();        // riporta il cursore in alto, per ridisegnare
aspetta(millisecondi);  // mette in pausa il programma
fine_gioco();           // rimette a posto il terminale (una volta, alla fine)
```

Perché 60 colonne se lo schermo ha 30 caselle? Ogni emoji è larga **due** caratteri: per questo una casella vuota si stampa con due spazi.

## Le missioni (circa 10 min l'una)

Ogni missione: **domanda** (2 min, il gruppo risponde prima di vedere il codice), **codice** (6 min), **confronto** (2 min, un gruppo mostra la soluzione).
Chi resta indietro riparte dal file della missione precedente.

| N. | Missione | Domanda | File |
|---|---|---|---|
| 1 | Disegnare il giocatore a terra, uscire con `q` | `for` o `while` per i fotogrammi? E per le colonne? | `jump_1_disegno.c` |
| 2 | L'oggetto va verso sinistra; quando esce rientra e si fa un punto | Cosa deve succedere quando l'oggetto arriva alla colonna 0? | `jump_2_oggetto.c` |
| 3 | Con lo spazio il giocatore salta | Su carta: velocità iniziale 3, ogni fotogramma cala di 1. Che altezze ottengo? | `jump_3_salto.c` |
| 4 | Se il giocatore tocca l'oggetto la partita finisce | `&&` oppure `\|\|`? Prima scrivete la condizione a parole | `jump_4_scontro.c` |
| 5 | Spostare disegno e scontro in due funzioni | Cosa deve sapere `disegna`? Può cambiare `punti`? | `jump_5_funzioni.c` |
| 6 | `Giocatore` e `Oggetto` come `struct`; tre oggetti diversi in un array; ogni oggetto superato dà i suoi punti | Quali variabili stanno insieme? Cosa distingue un oggetto dall'altro? | `jump_6_struct.c` |
| 7 | Ogni oggetto che entra è di un tipo a caso, da 12 a 19 caselle dietro all'ultimo | Che valori può dare `rand() % 3`? E `12 + rand() % 8`? Come trovo l'oggetto più a destra? | `jump_7_casuale.c` |
| 8 | Oggetti volanti: sotto si passa senza saltare | Cosa serve sapere in più di un oggetto che vola? | `jump_8_volanti.c` |
| 9 | Tre vite, come in Super Mario: un nemico che colpisce toglie una vita; la stella ⭐, presa al volo, ne dà una (al massimo 4) | Cosa cambia nella condizione del `while`? Quale membro aggiungo alla `struct` per non dover distinguere la stella con un `if`? | `jump_9_vite.c` |

Chi guida:

- **Missione 1**: è nuova (ciclo del gioco, `gioco.h`). La scrive il docente, i gruppi seguono.
- **Missioni 2, 3, 4, 7 e 8**: prima provano i gruppi.
- **Missioni 5 e 6**: si riscrive insieme, con le proposte dei gruppi.

Risposta della missione 3: altezze 3, 5, 6, 6, 5, 3, 0. È una parabola: moto uniformemente accelerato.

Risposta della missione 7: perché non scegliere la colonna a caso e basta? Perché la distanza tra gli oggetti
cambierebbe a ogni giro e, dopo un po', due oggetti finirebbero attaccati. Il nuovo oggetto entra quindi
dietro a quello più a destra: si cerca il **massimo** delle colonne (`colonna_ultimo`).

Gli oggetti (nella missione 6 sono i primi tre, fissi; dalla 7 vengono scelti a caso; nella 8 si aggiungono
quelli volanti; nella 9 la stella e la colonna "Vite"):

| Nome | Simbolo | Quota | Altezza | Punti | Vite |
|---|---|---|---|---|---|
| Fungo | 🍄 | 0 | 1 | 1 | -1 |
| Cactus | 🌵 | 0 | 2 | 2 | -1 |
| Albero | 🌲 | 0 | 3 | 3 | -1 |
| Ape | 🐝 | 3 | 1 | 2 | -1 |
| Fantasma | 👻 | 3 | 3 | 3 | -1 |
| Stella | ⭐ | 3 | 3 | 0 | +1 |

La quota è la riga più bassa dell'oggetto: un oggetto occupa le righe da `quota` a `quota + altezza - 1`.
La rana a terra passa sotto agli oggetti volanti; se salta, li colpisce.

La missione 6 è la più lunga: se il tempo stringe, la 7 e la 8 diventano sfide per casa. La 9 è un bonus.

Risposta della missione 9: `while (vite > 0)` al posto di `while (!colpito)`. Ogni oggetto ha un membro
`vite` (-1 per i nemici, +1 per la stella): quando la rana lo tocca, `vite = vite + oggetti[i].vite`, poi al massimo 4.
Chi è stato toccato sparisce: altrimenti, al giro dopo, verrebbe contato come superato e darebbe anche i punti.

## Chiusura (10 min)

- Ripassare le spunte sulla lavagna: cosa abbiamo usato, e dove?
- Ogni gruppo dice il punto in cui si è bloccato.
- Sfide per chi finisce prima, o per casa:
  - il gioco accelera quando i punti aumentano;
  - chiedere il nome del giocatore e salutarlo a fine partita;
  - ricordare il record su più partite, con un `do-while`.
