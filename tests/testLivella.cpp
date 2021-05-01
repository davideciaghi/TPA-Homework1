
#include "catch2/catch2.hpp"
#include "Livella.h"



TEST_CASE("Livella_init should succed", "[Livella]") {

    Livella * mylivella = livella_init(100,500,400,150,50,20,30,70,30,500);

    REQUIRE(mylivella != NULL);
    REQUIRE(mylivella->mypiston1 != NULL);
    REQUIRE(mylivella->mypiston2 != NULL);
    REQUIRE(mylivella->myplate != NULL);

    livella_destroy(mylivella);
}


TEST_CASE("piston_set_pos should set the x position of the second piston to 400", "[Livella]") {

    Livella * mylivella = livella_init(100,500,400,150,50,20,30,70,30,500);
    
    float param = 400;
    piston_set_pos(mylivella, param);

    REQUIRE(mylivella->mypiston2->pos_x1 == 400);

    livella_destroy(mylivella);
}

TEST_CASE("piston_set_alt should set the height of the pistons to 100", "[Livella]") {

    Livella * mylivella = livella_init(100,500,400,150,50,20,30,70,30,500);
    
    float param = 100;
    piston_set_alt(mylivella, param);

    REQUIRE(mylivella->mypiston1->alt_1 == 100);
    REQUIRE(mylivella->mypiston2->alt_1 == 100);

    livella_destroy(mylivella);
}

TEST_CASE("piston_set_larg1 should set the width of the pistons to 40", "[Livella]") {

    Livella * mylivella = livella_init(100,500,400,150,50,20,30,70,30,500);
    
    float param = 40;
    piston_set_larg1(mylivella, param);

    REQUIRE(mylivella->mypiston1->larg_1 == 40);
    REQUIRE(mylivella->mypiston2->larg_1 == 40);

    livella_destroy(mylivella);
}

TEST_CASE("piston_set_alt1 should set the extension of the first pistons to 50", "[Livella]") {

    Livella * mylivella = livella_init(100,500,400,150,50,20,30,70,30,500);
    
    float param = 50;
    piston_set_alt1(mylivella, param);

    REQUIRE(mylivella->mypiston1->alt_2 == 50);

    livella_destroy(mylivella);
}

TEST_CASE("piston_set_alt2 should set the extension of the first pistons to 50", "[Livella]") {

    Livella * mylivella = livella_init(100,500,400,150,50,20,30,70,30,500);
    
    float param = 50;
    piston_set_alt2(mylivella, param);

    REQUIRE(mylivella->mypiston2->alt_2 == 50);

    livella_destroy(mylivella);
}

TEST_CASE("piston_set_larg2 should set the width of the pistons rod to 50", "[Livella]") {

    Livella * mylivella = livella_init(100,500,400,150,50,20,30,70,30,500);
    
    float param = 25;
    piston_set_larg2(mylivella, param);

    REQUIRE(mylivella->mypiston1->larg_2 == 25);
    REQUIRE(mylivella->mypiston2->larg_2 == 25);

    livella_destroy(mylivella);
}

TEST_CASE("plate_set_spessore should set the height of the plate to 50", "[Livella]") {

    Livella * mylivella = livella_init(100,500,400,150,50,20,30,70,30,500);
    
    float param = 20;
    plate_set_spessore(mylivella, param);

    REQUIRE(mylivella->myplate->spessore == 20);

    livella_destroy(mylivella);
}

TEST_CASE("plate_set_lunghezza should set the length of the plate to 550", "[Livella]") {

    Livella * mylivella = livella_init(100,500,400,150,50,20,30,70,30,500);
    
    float param = 550;
    plate_set_lunghezza(mylivella, param);

    REQUIRE(mylivella->myplate->lunghezza == 550);

    livella_destroy(mylivella);
}