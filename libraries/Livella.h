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
        
        float pos_cxS;
        float pos_cyS;
        float pos_cxD;
        float pos_cyD;
        float pos_x;
        float pos_y;
        float spessore;
        float lunghezza;
        float angle;    
    };

    struct Livella {

        Piston * mypiston1;
        Piston * mypiston2;
        Plate * myplate;

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
    Plate * plate_init (float spess, float lung, float posx1, float posx2, float posy, float alt1, float larg1, float altS, float altD, float larg2);

    
    
    Livella * livella_init(float posx1, float posx2, float posy, float alt1, float larg1, float larg2, float altS, float altD, float spess, float lung);



    void piston_set_pos(Livella * mylivella);
    void piston_set_alt(Livella * mylivella);
    void piston_set_larg1(Livella * mylivella);
    void piston_set_alt1(Livella * mylivella);
    void piston_set_alt2(Livella * mylivella);
    void piston_set_larg2(Livella * mylivella);
    void plate_set_spessore(Livella * mylivella);
    void plate_set_lunghezza(Livella * mylivella);

    int param_control(Livella * mylivella);

    int device_control(Livella * mylivella);


    // Funzione che stampa i parametri dei componenti
    void info_parti ( Livella * mylivella );


    // Funzione per la creeazione del file .svg
    void livella_to_svg (Livella * mylivella, std::string fileName, char measures);


    // Funzione stringa per implementazione del file svg.
    std::string livella_to_ParamSVG ( Livella * mylivella);


    // Funzione stringa per implementazione delle misure nel file svg.
    std::string livella_to_MeasureSVG ( Livella * mylivella);


    // Funzione cancellazione 
    void livella_destroy(Livella * mylivella);


    

#endif