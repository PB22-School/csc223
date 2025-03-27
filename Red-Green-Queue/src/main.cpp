#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <iostream>
#include "RGThings.h"
using namespace std;

TEST_CASE("Can insert RGTPair (and check if empty correctly)") {

    RGThing red;
    red.color = Color::RED;
    
    RGThing green;
    red.color = Color::GREEN;

    RGThings rgQueue;
    CHECK(rgQueue.empty() == true);

    rgQueue.insert(red);
    CHECK(rgQueue.empty() == false);
    
}