#ifndef LIVELLA

    #define LIVELLA

    #include <iostream>

    /*
     *  Introduzione ai parametri dei cilindri:
     * 
     *  @param pos_x1: posizione x del cilindro esterno
     *  @param pos_y1: posizione y del cilindro esterno
     *  
     *  @param pos_x2: posizione x del cilindro interno
     *  @param pos_y2: posizione x del cilindro interno
     *  
     *  @param pos_cx: posizione x della coppia rotoidale
     *  @param pos_cy: posizione y della coppia rotoidale
     * 
     *  @param alt_1: altezza del cilindro esterno
     *  @param larg_1: larghezza del cilindro esterno
     *  
     *  @param alt_2: altezza del cilindro interno
     *  @param larg_2: larghezza del cilindro interno
     * 
     */
    struct Piston {
    
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

    /*
     *  Introduzione ai parametri della piastra:
     * 
     *  @param pos_x: posizione x della piastra
     *  @param pos_y: posizione y della piastra
     *  
     *  @param spessore: spessore della piastra
     *  @param lunghezza: lunghezza della piastra
     *  
     *  @param angle: angolo di inclinazione della piastra
     * 
     */
    struct Plate {
        
        float pos_x;
        float pos_y;
        float spessore;
        float lunghezza;
        float angle;    
    };

    struct Param {

        int arr[10];
    };

    
    /*
     * Funzione che inizializza il pistone
     * 
     *  @param posx1: posizione x del cilindro esterno
     *  @param posy1: posizione y del cilindro esterno
     * 
     *  @param alt1: altezza del cilindro esterno
     *  @param larg1: larghezza del cilindro esterno
     *  
     *  @param alt2: altezza del cilindro interno
     *  @param larg2: larghezza del cilindro interno
     * 
     */
    Piston * piston_init (float posx, float posy, float alt1, float larg1, float alt2, float larg2);


    /*
     * Funzione che inizializza la piastra
     * 
     * @param spess: spessore della piastra
     * @param lung: lunghezza della piastra
     * 
     */
    Plate * plate_init (float spess, float lung, Piston * mypiston1, Piston * mypiston2);


    /*
     * Funzione inserimento parametri
     * 
     */
    Param *parameters_init();


    // Funzione che stampa i parametri dei componenti
    void info_parti ( Piston * mypiston1, Piston * mypiston2, Plate * myplate );


    // Funzione per la creeazione del file .svg
    void livella_to_svg (Piston * mypiston1, Piston * mypiston2, Plate * myplate, std::string fileName );


    // Funzione stringa per implementazione del file svg.
    std::string livella_to_ParamSVG ( Piston * mypiston1, Piston * mypiston2, Plate * myplate );


    // Funzione cancellazione 
    void livella_destroy(Piston * mypiston1, Piston * mypiston2, Plate * myplate, Param * myparam);


    

#endif