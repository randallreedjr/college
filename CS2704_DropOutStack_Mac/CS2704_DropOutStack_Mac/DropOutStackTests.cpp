#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.h"
#include "DropOutStack.h"

TEST_CASE("Pushing into zero capacity stack errors") {
    DropOutStack b;
    Item element = 0;
    b.push(element);
    REQUIRE(b.getError()==STACK_OVERFLOW);
}