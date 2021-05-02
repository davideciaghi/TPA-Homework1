#ifndef MACHINE

    #define MACHINE

    #include <iostream>
    #include "Livella.h"
    #include "guida.h"



      struct Connection {

        float posx;
        float posy;
        float est;
        float corsa;

    };


    struct Machine {

        float pos_x1;
        float pos_x2;
        float pos_y;
        float alt_1;
        float larg_1;
        float alt_sx;
        float alt_dx;
        float spessore;
        float lunghezza;

        Livella * livella;
        GuidaPrismatica * guida;
        Connection * aggancio;


    };


  


    
    Machine * machine_init(float posx1, float posx2, float posy, float alt1, float larg1, float larg2, float altS, float altD, float spess, float lung);

    Connection * aggancio_init(Machine * machine);



#endif