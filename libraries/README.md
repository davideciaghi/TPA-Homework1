# Descrizione libreria: Livella.h

La libreria Livella.h contiene diverse funzioni atte alla creazione di un file formato .svg al fine di realizzare una struttura inclinata controllata mediante l'estensione di due pistoni posizionati alle estremità.

## Descrizione delle funzioni implementate:


#### `livella_init`
Funzione di inserimento dei parametri.


#### `piston_init`
Inizializzazione dell'istanza del pistone. Come parametri riceve:
* `posx1`: posizione x del cilindro esterno
* `posy`: posizione y del cilindro esterno
* `alt1`: ezza del cilindro esterno
* `larg1`: larghezza del cilindro esterno
* `alt2`: altezza del cilindro interno
* `larg2`: larghezza del cilindro interno


#### `plate_init`
Inizializzazione dell'istanza della piastra. Come parametri riceve:
* `spess`: spessore della piastra
* `lung`: lunghezza della piastra
* `posx1`: posizione x del pisone di sinistra
* `posx2`: posizione x del pistone di destra
* `posy`: posizione y del cilindro esterno
* `alt1`: ezza del cilindro esterno
* `larg1`: larghezza del cilindro esterno
* `altS`: estensione del pistone di sinistra
* `altD`: estensione del pistone di destra
* `larg2`: larghezza del cilindro interno

#### `param_control`
Funzione che controlla che i parametri inseriti siano valori positivi e non nulli. Qualora fosse necessario viene chiamata una delle funzioni _set_ chepermette di modificare il parametro.

#### `device_control`
Funzione che controlla che i parametri inseriti siano coerenti con il device che si vuole creare. Qualora fosse necessario viene chiamata una delle funzioni _set_ chepermette di modificare il parametro.

#### `piston_seto_pos`
Funzione che permette di cambiare la posizione del secondo pistone.

#### `piston_set_alt`
Funzione che permette di cambiare l'altezza dei cilindri esterni.

#### `piston_set_larg1`
Funzione che permette di cambiare la larghezza dei cilindri esterni.

#### `piston_set_alt1`
Funzione che permette di cambiare l'estensione del primo pistone.

#### `piston_set_alt2`
Funzione che permette di cambiare l'estensione del secondo pistone

#### `piston_set_larg2`
Funzione che permette di cambiare la larghezza dei due cilindri interni.

#### `plate_set_spessore`
Funzione che permette di cambiare lo spessore della piastra.

#### `plate_set_lunghezza`
Funzione che permette di cambiare la lunghezza della piastra.

#### `info_parti`
La funzione stampa sul terminal tutti parametri caratteristici del device.

#### `livella_to_svg`
Dato il nome del file dall'utente, la funzione realizza il file .svg

#### `livella_to_ParamSVG_to_svg`
Funzione che restituisce la stringa di codice svg per la realizzazione del file

#### `livella_to_MeasureSVG_to_svg`
Funzione che permette di implementare le misure all'interno del file svg

#### `livella_destroy`
Funzione cancellazione struct e istanze

