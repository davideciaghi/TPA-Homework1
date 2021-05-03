#ifndef MACHINE

    #define MACHINE

    #include <iostream>
    #include "Livella.h"
    #include "guida.h"


    /*
     * Definizione struct di collegamento tra la livella e la guida prismatica
     * 
     * @param posx: coordinata x del centro della guida prismatica
     * @param posy: coordinata y del centro della guida prismatica
     * @param est: lunghezza totale della guida prismatica
     * @param corsa: corsa della guida prismatica 
     * 
     */ 
    struct Connection {

        float posx;
        float posy;
        float est;
        float corsa;

    };


    /*
     * Definizione della struct Machine
     *
     */ 
    struct Machine {

        Livella * livella;
        GuidaPrismatica * guida;
        Connection * aggancio;

    };



    /*
     * Funzione di inizializzazione della machine
     * 
     *  @param livella: istanza della struct Livella
     *  @param aggancio: istanza della struct Connection
     *  @param guida: istanza della struct GuidaPrismatica
     * 
     *  @funz livella_init from Livella.h per inizializzare la livella
     *  @funz guida_init from guida.h per inizializzare la guida prismatica
     * 
     *  @return machine: ritorna l'istanza machine
     * 
     */
    Machine * machine_init(float posx1, float posx2, float posy, float alt1, float larg1, float larg2, float altS, float altD, float spess, float lung);


    /*
     * Funzione che definisce i principali parametri di posizionamento della guida prismatica sulla piastra della livella
     * 
     * @param posx: coordinata x del centro della guida prismatica
     * @param posy: coordinata y del centro della guida prismatica
     * @param est: lunghezza totale della guida prismatica
     * @param corsa: corsa della guida prismatica 
     * 
     * @return conn: ritorna l'istnza conn
     * 
     */ 
    Connection * aggancio_init(Machine * machine);



    /*
     * Funzione che realizza il file svg
     * 
     * @param livellaMac: istanza della machine dalla quale prelevare i parametri
     * @param fileName: nome del fine svg dato dall'utente
     * @param measures: carattere di scelta per le misure all'interno del file svg
     * 
     */ 
    void machine_to_svg(Machine * livellaMac, std::string fileName, char measures);


    /*
     * Funzione che implementa nel file svg la livella e la guida
     * 
     * @param livellaMac: istanza della machine dalla quale prelevare i parametri
     * @param measures: carattere di scelta per le misure all'interno del file svg
     * 
     * @funz livella_to_ParamSVG from Livella.h
     * @funz livella_to_MeasureSVG from Livella.h
     * 
     * @return str: stringa contenente il codice del file svg finale
     * 
     */ 
    std::string machine_to_ParamSVG(Machine * livellaMac, char measures);


    /*
     * Funzione che implementa nel file svg la guida ruotata secondo la piastra della livella
     * 
     * @param livellaMac: istanza della machine dalla quale prelevare i parametri
     * @param measures: carattere di scelta per le misure all'interno del file svg
     * 
     * @funz guida_to_SVGstring from guida.h
     * 
     * @return str: stringa contenente il codice del file svg della rotazione della guida
     * 
     */ 
    std::string rotated_guida(Machine * livellaMac, bool measures);


    /*
     * Funzione che stampa i parametri della machine
     * 
     * @param livellaMac: istanza della machine dalla quale prelevare i parametri
     * 
     * @funz info_parti from Livella.h
     * @funz guida_visualizza_info from guida.h
     * 
     */ 
    void machine_print_info(Machine * livellaMac);

#endif