#include "main.h"
#include "config.hpp"
#include "chessboard.hpp"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {

    // Configure the chessboard.
    set_squares();

}