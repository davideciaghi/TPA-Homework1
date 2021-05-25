#include "catch2/catch2.hpp"
#include "Livella.h"
#include "guida.h"
#include "machine.h"



TEST_CASE("machine_init should succed", "[Machine]") {

    Machine * mymachine = machine_init(100,500,400,150,50,20,30,70,30,500);

    REQUIRE(mymachine != NULL);
    REQUIRE(mymachine->livella != NULL);

    machine_destroy(mymachine);
}