# Descrizione libreria: Livella.h

La libreria Livella.h contiene diverse funzioni atte alla creazione di un file formato .svg al fine di realizzare una struttura inclinata controllata mediante l'estensione di due pistoni posizionati alle estremità.

## Descrizione delle funzioni implementate:


#### `parameters_init`
Funzione di controllo dei parametri secondo dei vincoli imposti.


#### `piston_init`
Inizializzazione dell'istanza del pistone. Come parametri riceve:
* `posx1`: posizione x del cilindro esterno
* `posy1`: posizione y del cilindro esterno
* `alt1`: ezza del cilindro esterno
* `larg1`: larghezza del cilindro esterno
* `alt2`: altezza del cilindro interno
* `larg2`: larghezza del cilindro interno


#### `plate_init`
Inizializzazione dell'istanza della piastra. Come parametri riceve:
* `spess`: spessore della piastra
* `lung`: lunghezza della piastra


#### `info_parti`
La funzione stampa sul terminal tutti parametri caratteristici del meccanismo.


#### `livella_to_svg`
Funzione per la creazione del file .svg


#### `livella_to_ParamSVG_to_svg`
Funzione per implementazione del file .svg


#### `livella_to_MeasureSVG_to_svg`
Funzione per l'inserimento delle misure nel file .svg


#### `livella_destroy`
Funzione che distrugge i puntatori creati alle struct `Piston` e `Plate`.

