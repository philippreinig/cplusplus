// Task: write a program that handles interactions between planets, spaceships and deathstars
// Do this with unit tests.
// Step 1. Write a test framework: Write a function or macro "TEST" that takes a bool
//          and a string which describes what is being tested. It outputs whether the first argument is true.
//          See below for an example.
//          When the program ends a report should be displayed that shows how many tests have passed and failed.
// Step 2. Write Unit Tests for each class and functionality using the TEST construct.
// Step 3. Write the classes and functions until each unit test passes.
//         - write error, debug and status output.
//         - each function should have error logging as well as "in-game" output. ("Deathstar was destroyed")

// Note: Use exceptions and asserts where necessary / appropriate to test for programming and user errors.
// BONUS: Use macros to have TEST output the line number and filename as well on failure.
// BONUS: Visualise ship encounters with the console renderer.

// Classes: Target, Planet, Spaceship and Deathstar.
// Planet, Spaceship and Deathstar are all be targets.

// Target.
// Every Target has a position and name.
// Each target can be attacked and can explode
// Exploding cannot be triggered from outside the class. (only through receiving damage)
// Should have a stream out operator.
// Can be purely virtual (abstract).

// Planet
// Inherits from Target
// Can only be destroyed be Deathstars.
// Planets cannot attack

// Spaceship
// Inherits from Target
// Has a number of lasers
// Has shields (percentage)
// Can attack other targets
// When attacked, shields are damaged. When shields <= 0, it explodes.

// Deathstar
// Inherits from Spaceship
// Has far higher shields
// Can be damaged by spaceships with a 25% chance of exploding directly (without needing to get the shields to zero).
//        (- the reactor core can be hit through the exhaust vent. ;) )


#include <iostream>

/**
 * @brief Testing if condition is met and printing debug output to console accordingly
 * @param con the condition to be tested
 * @param dbg_out the debug output printed to the console
 */
bool TEST(bool con, std::string dbg_out){
    std::cout << (con ? "Passed: " : "Failed: ") << dbg_out << std::endl;
    return con;
}

int main()
{
    TEST(1 <= 2, "basic arithmetic");
    // output: passed: basic arithmetic
    TEST(1 != 1, "identity unequal comparison");
    // output: failed: identity comparison
}
// output: Passed 1 / 2 tests.
