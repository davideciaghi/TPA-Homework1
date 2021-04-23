#ifndef _GUIDA_PRISMATICA_H_

    #define _GUIDA_PRISMATICA_H_

    #include <iostream>

    /*
     *  Definzione della struttura per la guida prismatica
     * 
     *  @param lunghezza: lunghezza complessiva della barra della guida prismatica
     *  @param corsa: posizione relativa del glifo rispetto alla posizione iniziale
     *  
     *  @param pos_x: posizione orizzontale del centro della guida prismatica
     *  @param pos_y: posizione verticale del centro della guida prismatica
     *  
     *  @param incastri: oggetto GRect che contiene le informazioni per quanto riguarda le cerniere del sistema
     *  @param guida: oggetto GRect che contiene le informazioni per quanto riguarda la guida del componente
     * 
     *  @param spessore: spessore della guida prismatica
     *  @param alpha: inclinazione della guida rispetto all'orizzontale
     */
    struct Piston {
        
        float lunghezza;
        float corsa;

        float pos_x1;
        float pos_y1;
        float pos_x2;
        float pos_y2;

        float pos_cx;
        float pos_cy;

        float alt_1;
        float larg_1;

        float alt_2;
        float larg_2;        
    };


      struct Plate {
        
        float spessore;
        float lunghezza;
        float xC;
        float yC;
        float angle;    
    };



    
    /*
     * Funzione che inizializza una guida prismatica
     * 
     * @param posx: posizione orizzontale
     * @param posy: posizione verticale
     * @param lungh: lunghezza della guida prismatica che si vuole generare
     * @param corsa: corsa dell'elemento prismatico
     * @param dimx: dimensione orizzontale delle cerniere e dell'elemento prismatico
     * @param dimy: dimensione verticale delle cerniere dell'elemento prismatico
     * 
     */
    Piston * piston_init (float posx, float posy, float alt1, float larg1, float alt2, float larg);


    /*
     * Funzione che inizializza la piastra
     * 
     * @param posx: posizione orizzontale
     * @param posy: posizione verticale
     * @param lungh: lunghezza della guida prismatica che si vuole generare
     * @param corsa: corsa dell'elemento prismatico
     * @param dimx: dimensione orizzontale delle cerniere e dell'elemento prismatico
     * @param dimy: dimensione verticale delle cerniere dell'elemento prismatico
     * 
     */
    Plate * plate_init (float spess, float lung, Piston * mypiston1, Piston * mypiston2);


    void info_parti ( Piston * mypiston1, Piston * mypiston2, Plate * myplate );


#endif