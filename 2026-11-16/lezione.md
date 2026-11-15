# Lezione 2026-11-16 — Ripasso: scriviamo Jump insieme

Un gioco nel terminale: una rana 🐸 salta (barra spaziatrice) gli oggetti che arrivano da destra.

Il gioco si costruisce **tutti insieme**, un pezzo alla volta: i gruppi propongono, discutono tra loro e
dettano; il docente scrive il codice al proiettore. Ogni gruppo (2–3 persone, un computer) lo scrive in parallelo.

## Scaletta

| Ora | Cosa |
|---|---|
| 12:30 | Lista degli argomenti di C fatti finora; mostro il gioco; si formano i gruppi |
| 12:40 | Alla lavagna: come si disegna nel terminale, e la libreria `gioco.h` |
| 12:55 | Fase 1 e Fase 2 |
| 13:15 | Pausa |
| 13:25 | Tappe 0–4: il gioco funziona |
| 14:10 | Pausa |
| 14:20 | Tappe 5–7: funzioni, struct, numeri casuali |
| 14:50 | Chiusura (tappe 8 e 9 se c'è tempo, altrimenti a casa) |

## Inizio (10 min)

1. **Cosa sapete fare in C?** La classe detta, il docente scrive alla lavagna, in colonne:
   variabili e `const` · `if` e `switch` · cicli · funzioni · array e stringhe · `struct` · `rand`.
   La lista resta lì per tutta la lezione: si mette una spunta ogni volta che il gioco usa una voce.
2. Un volontario gioca a `jump_9_vite`: "alla fine della giornata lo avremo scritto noi".
3. Si formano i gruppi: 2–3 persone, un computer.

## Alla lavagna: lo schermo e `gioco.h` (15 min)

1. **Lo schermo è una griglia** di righe e caselle. `printf` scrive dall'alto in basso: la riga più alta si
   stampa per prima, per questo il ciclo delle righe va da 7 a 1.
2. **Un'animazione è una serie di fotogrammi**, come un cartone animato: pulisco, disegno, aspetto un attimo,
   ricomincio. Con 80 millisecondi di pausa sono circa 12 fotogrammi al secondo.
3. **Un'emoji è larga due caratteri**: 30 caselle sono 60 colonne, e una casella vuota sono due spazi.
4. **La tastiera**: `scanf` aspetta Invio, e il gioco si fermerebbe a ogni fotogramma.
   Serve una funzione che guardi se c'è un tasto e vada avanti.

Queste cose le fa la libreria `gioco.h` (vedi `gioco.md`): funzioni già scritte, da usare come `printf`
senza sapere come sono fatte.

```c
inizia_gioco(60, 10);   // prepara il terminale (una volta, all'inizio):
                        // se è più piccolo di 60 colonne x 10 righe, esce con un messaggio
tasto_premuto();        // il tasto premuto, oppure 0 se non c'è: non aspetta!
pulisci_schermo();      // da chiamare prima di ridisegnare: il nuovo disegno copre il vecchio
aspetta(millisecondi);  // mette in pausa il programma
fine_gioco();           // rimette a posto il terminale (una volta, alla fine)
```

Domande di controllo: cosa succede se tolgo `aspetta`? (va troppo veloce) E se tolgo `pulisci_schermo`?
(ogni disegno finisce sotto il precedente e lo schermo scorre)

## Fase 1: quali sono le componenti logiche? (10 min)

Vietate le keyword del C. Ogni gruppo risponde a una domanda, gli altri completano.

1. Cosa succede in **un singolo fotogramma**, passo per passo?
   - pulisco lo schermo, aggiorno giocatore e oggetto, leggo la tastiera, controllo lo scontro, disegno, aspetto un attimo
2. Cosa **non cambia mai** durante il gioco?
   - le misure dello schermo, la colonna della rana, i simboli, quanto è alto e quanto dura il salto
3. Cosa deve **ricordare** il programma?
   - il numero del fotogramma, l'altezza della rana, quando è partito il salto, dov'è l'oggetto, i punti
4. Cosa **si ripete**? Sapete in anticipo quante volte?
   - i fotogrammi: no; le righe e le colonne del disegno: sì
5. **Quando finisce** la partita, e cosa può **andare storto**?
   - quando la rana tocca l'oggetto, o con `q`; saltare mentre si è già in aria; l'oggetto che esce dallo schermo;
     il gioco che si ferma ad aspettare un tasto

## Fase 2: quale costrutto C serve? (10 min)

I gruppi collegano ogni pezzo logico a una voce della lista alla lavagna.

| Pezzo logico | Costrutto C | Perché |
|---|---|---|
| Cose che non cambiano | variabili `const`, in cima | si cambiano in un posto solo |
| Ripetere i fotogrammi | `while` | non so quante volte |
| Disegnare lo schermo | due `for` annidati | 7 righe, 30 caselle |
| Cosa c'è in una casella | `if` / `else if` / `else` | rana, oggetto o vuoto |
| Contare il tempo | un contatore `frame` | +1 a ogni giro |
| Il salto dura un po' | ricordo `frame_salto` | confronto con `frame` |
| Saltare solo da terra | `if` con `&&` | due condizioni insieme |
| Fine partita | condizione del `while`, `break` | esco dal ciclo |
| Disegno e scontro | funzioni | il `main` resta corto |
| Giocatore e oggetto | `struct` | variabili che stanno insieme |
| Tre oggetti | array di `struct` + `for` | stesso codice per tutti |
| Oggetti sempre diversi | `rand()` | numeri casuali |
| Leggere un tasto senza fermarsi | `tasto_premuto()` di `gioco.h` | `scanf` aspetta Invio |

## Le tappe (circa 10 min l'una)

Ogni tappa ha tre momenti:

1. **Domanda** (3 min): ogni gruppo risponde su carta, senza codice.
2. **Proposte** (3 min): un gruppo dà la sua risposta; gli altri la completano o cercano un caso in cui non funziona.
   Si sceglie insieme la soluzione. A ogni tappa propone un gruppo diverso.
3. **Codice** (4 min): il docente scrive al proiettore quello che dettano i gruppi; i gruppi lo scrivono sul
   loro computer, si compila e si prova. Se qualcosa non va, l'errore lo cercano tutti.

Chi resta indietro riparte dal file della tappa precedente.

| N. | Cosa aggiungiamo | Domanda | File |
|---|---|---|---|
| 0 | Impostazioni in cima, disegno della rana a terra, contatore dei fotogrammi | Cosa non cambia mai? Quante righe disegna `for (riga = 7; riga > 0; riga--)`? | `jump_0_template.c` |
| 1 | Con `q` si esce | Perché non va bene `scanf`? | `jump_1_input_utente.c` |
| 2 | L'oggetto va verso sinistra; quando esce rientra e si fa un punto | Cosa deve succedere quando l'oggetto arriva alla colonna 0? | `jump_2_oggetto.c` |
| 3 | Con lo spazio la rana salta | Premo lo spazio al fotogramma 10: in quali fotogrammi la rana è in aria? E se metto `>=` al posto di `>`? | `jump_3_salto.c` |
| 4 | Se la rana tocca l'oggetto la partita finisce | `&&` oppure `\|\|`? Prima scrivete la condizione a parole | `jump_4_scontro.c` |
| 5 | Disegno e scontro diventano due funzioni | Cosa deve sapere `disegna`? Le impostazioni come le vede? | `jump_5_funzioni.c` |
| 6 | `Giocatore` e `Oggetto` come `struct`; tre oggetti in un array; ogni oggetto superato dà i suoi punti | Quali variabili stanno insieme? Cosa distingue un oggetto dall'altro? | `jump_6_struct.c` |
| 7 | Ogni oggetto che entra è di un tipo a caso, da 12 a 19 caselle dietro l'ultimo | Che valori dà `rand() % 3`? E `12 + rand() % 8`? Come trovo l'oggetto più a destra? | `jump_7_casuale.c` |
| 8 | Oggetti volanti: sotto si passa senza saltare | Cosa serve sapere in più di un oggetto che vola? | `jump_8_volanti.c` |
| 9 | Tre vite: un nemico ne toglie una, la stella ⭐ presa al volo ne dà una (al massimo 4) | Cosa cambia nella condizione del `while`? Quale membro aggiungo alla `struct` per non distinguere la stella con un `if`? | `jump_9_vite.c` |

La tappa 6 è la più lunga: se il tempo stringe, la 7 si fa in fretta e la 8 e la 9 diventano sfide per casa.

### Risposte

- **Tappa 0**: 7 righe, da 7 a 1 (la riga 0 è il pavimento). Molti rispondono 6.
- **Tappa 3**: in aria dal fotogramma 10 al 15, cioè 6 fotogrammi: al 16 vale `16 - 10 > 5` e la rana torna a terra.
  Con `>=` sarebbero 5.
- **Tappa 5**: una funzione non vede le variabili del `main` (le regole di visibilità). Le impostazioni si spostano
  **fuori da ogni funzione**: così le vedono tutte. `righe` resta nel `main`, perché fuori da una funzione
  non si può calcolare da altre variabili.
- **Tappa 7**: perché non scegliere la colonna a caso e basta? Perché la distanza tra gli oggetti cambierebbe
  a ogni giro e, dopo un po', due oggetti finirebbero attaccati. Il nuovo oggetto entra dietro a quello più a
  destra: si cerca il **massimo** delle colonne (`colonna_ultimo`).
- **Tappa 9**: `while (vite > 0)` al posto di `while (!collisione)`. Ogni oggetto ha un membro `vite`
  (-1 per i nemici, +1 per la stella): quando la rana lo tocca, `vite = vite + oggetti[i].vite`, poi al massimo 4.
  Chi è stato toccato sparisce: altrimenti, al giro dopo, darebbe anche i punti.

Gli oggetti (nella tappa 6 sono i primi tre, fissi; dalla 7 vengono scelti a caso; nella 8 si aggiungono
quelli volanti; nella 9 la stella e la colonna "Vite"):

| Nome | Simbolo | Quota | Altezza | Punti | Vite |
|---|---|---|---|---|---|
| Fungo | 🍄 | 1 | 1 | 1 | -1 |
| Cactus | 🌵 | 1 | 2 | 2 | -1 |
| Albero | 🌲 | 1 | 3 | 3 | -1 |
| Ape | 🐝 | 5 | 1 | 2 | -1 |
| Fantasma | 👻 | 4 | 3 | 3 | -1 |
| Stella | ⭐ | 4 | 3 | 0 | +1 |

La quota è la riga più bassa dell'oggetto: un oggetto occupa le righe da `quota` a `quota + altezza - 1`.
La rana a terra (riga 1) passa sotto agli oggetti volanti; se salta (riga 5), li colpisce.

## Facoltativo: un salto più realistico

Nella tappa 3 la rana sale di colpo alla riga 5 e ci resta. Per chi vuole: al posto di `frame_salto`, una **velocità**.

```c
int velocita = 0; // positiva = sale, negativa = scende

// a ogni fotogramma:
if (tasto == tasto_salto && altezza_corrente == altezza_giocatore)
{
  velocita = 3;
}

altezza_corrente = altezza_corrente + velocita; // la velocità cambia l'altezza
if (altezza_corrente > altezza_giocatore)
{
  velocita = velocita - 1;                      // la gravità cambia la velocità
}
else
{
  altezza_corrente = altezza_giocatore;
  velocita = 0;
}
```

Domanda: con velocità iniziale 3, che altezze ottengo? 4, 6, 7, 7, 6, 4, 1: una parabola, come un sasso lanciato in alto.

## Chiusura (10 min)

- Ripassare le spunte sulla lavagna: cosa abbiamo usato, e dove?
- Ogni gruppo dice il punto più difficile della giornata.
- Sfide per casa:
  - il gioco accelera quando i punti aumentano;
  - chiedere il nome del giocatore e salutarlo a fine partita;
  - ricordare il record su più partite, con un `do-while`.
