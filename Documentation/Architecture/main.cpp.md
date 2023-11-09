## include
- ##### std::vector
- ##### std::set
- std::string
- std::fstream
- std::iostream

- nlohmannJSON/json.hpp

- #### [[Pack.h]]

- #### [[trovaDominio.hpp]]
- #### [[spostaPacchi.hpp]]
- #### [[ordinamentoPacchi.hpp]]
- #### [[sceltaPacchiNesting.hpp]]
- #### [[ottimizzazione.hpp]]
---
### Variabili:
``` cpp
std::vector<Pack> input; //INPUT_MAIN: pacchi recuperati dalla lettura del fine json
std::vector<Pack*> nestedOutput; //pacchi "pallettizzati" da utilizzare nelle operazioni temporanee sul pallet corrente
std::vector<Pack*> notNestableOutput; //pacchi non pallettizzabili e che vanno messi su un pallet loro singolarmente
std::vector<Pack*> unNested; //pacchi non pallettizzati ma x le seconde iterazioni
std::vector<Pallet*> palletGroup; //OUTPUT_MAIN a fini di debug e testing: da capire come passare in output al resto del progetto i dati
```
---

### Organizzazione: 

1. Refactoring del codice di lettura del file json. 
2. Loop pallet (fino a quando non finiscono i pacchi in "input")
	1. esegue modulo "Ordinamento Input"
	2. esegue modulo "SceltaPacchiNesting"
	3. Nesting: scrivo il loop e ci faccio eseguire dentro i moduli di ALG1 e ALG2 + controllo e ottimizzazione 
		1. ALG1: il loop (e gestione dei suoi due output possibili) definito qui dentro, mentre ALG1_1 in modulo
		2. ALG2: definito in modulo suo
		3. Ottimizzazione (da capire come inputare a ALG1 il set di punti "bannati")
	4. Output pallet (aggiungo pallet a vettore "palletGroup")
3. Unione Nested Pallets con Pacchi non pallettizzati (sul loro personale pallet) 
4. Output pallet nestati
---
### Documentazione: 
* Questo algoritmo esegue il flusso del codice in maniera ordinata, gestendo tutti i diversi blocchi di codice tramite INPUT e OUTPUT ben definiti (no rougue variables).
* Nel main vanno definiti tutti i cicli principali dell'applicazione.
* Passare le variabili x riferimento

--- 

INPUT: posizione del file json
OUTPUT: json suddiviso a pallet e in pacchi con i singoli argomenti.

Struttura json output:

``` json
{
	{
		"nPallet1", {(float)dimX, (float)dimY},
		{
			{"codicePacco1", (float)posX, (float)posY, flagRotazione},
			{"codicePacco2", (float)posX, (float)posY, flagRotazione},
			{"codicePacco3", (float)posX, (float)posY, flagRotazione}
		}
	},
	{
		"nPallet2", {(float)dimX, (float)dimY},
		{
			{"codicePacco4", (float)posX, (float)posY, flagRotazione},
			{"codicePacco5", (float)posX, (float)posY, flagRotazione},
			{"codicePacco6", (float)posX, (float)posY, flagRotazione}
		}
	}
}
```