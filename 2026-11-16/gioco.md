# gioco.h — una libreria per i giochi nel terminale

`gioco.h` è una **libreria**: un file con cinque funzioni già scritte, pronte da usare.
Come per `printf` (che sta nella libreria `stdio.h`), non serve sapere come sono fatte dentro.

Basta mettere `gioco.h` nella stessa cartella del programma e includerlo:

```c
#include "gioco.h"
```

## Le cinque funzioni

| Funzione | Cosa fa |
|---|---|
| `inizia_gioco(colonne, righe);` | Prepara il terminale. Si chiama **una volta**, all'inizio. Se la finestra è più piccola di `colonne` x `righe`, stampa un messaggio ed esce. |
| `tasto_premuto()` | Restituisce il tasto premuto (per esempio `'q'` o `' '`), oppure `0` se non è stato premuto niente. **Non aspetta**: il gioco continua a girare. |
| `pulisci_schermo();` | Si chiama prima di ridisegnare: il nuovo disegno copre quello vecchio, invece di finirgli sotto. |
| `aspetta(millisecondi);` | Mette in pausa il programma: `aspetta(80)` vuol dire circa 12 fotogrammi al secondo. |
| `fine_gioco();` | Rimette a posto il terminale. Si chiama **una volta**, alla fine. |

## Lo schema di ogni gioco

```c
#include <stdio.h>
#include <stdbool.h>
#include "gioco.h"

int main()
{
  inizia_gioco(60, 10);

  while (true)               // un giro = un fotogramma
  {
    char tasto = tasto_premuto();
    if (tasto == 'q')
    {
      break;
    }

    // ... aggiorno le variabili del gioco ...

    pulisci_schermo();
    // ... disegno con printf ...

    aspetta(80);
  }

  fine_gioco();
  return 0;
}
```

Ogni giro del `while` fa sempre le stesse cose: leggo il tasto, aggiorno il gioco, ridisegno e aspetto un attimo.

## Perché serve

- `scanf` e `getchar` **aspettano Invio**: il gioco si fermerebbe a ogni fotogramma. `tasto_premuto` invece guarda solo se c'è un tasto e va avanti.
- Normalmente il terminale mostra i tasti premuti. Durante il gioco non li mostra, e il cursore è nascosto.
- Senza `pulisci_schermo` ogni disegno finirebbe sotto quello precedente e lo schermo scorrerebbe.

## Da sapere

- **Le emoji sono larghe due caratteri.** Per questo una casella vuota si stampa con due spazi (`"  "`), e uno schermo di 30 caselle chiede 60 colonne.
- **Il gioco non parte?** La finestra del terminale è troppo piccola: allargarla e riprovare.
- **Il terminale è rimasto "strano"?** Per esempio i tasti non si vedono più: scrivere `reset` e premere Invio.
- Ctrl+C ferma il gioco e rimette a posto il terminale da solo.
- Funziona su macOS e Linux. Su Windows c'è una versione apposta, ma non è stata provata.
