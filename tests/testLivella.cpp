#include "catch2/catch2.hpp"
#include "Livella.h"

TEST_CASE("Livella_init should succed", "[Livella]") {

    Livella * mylivella = livella_init(100,500,400,150,50,20,30,70,30,500);

    REQUIRE(mylivella != 0);
    REQUIRE(mylivella->mypiston1 != 0);
    REQUIRE(mylivella->mypiston2 != 0);
    REQUIRE(mylivella->myplate != 0);
}