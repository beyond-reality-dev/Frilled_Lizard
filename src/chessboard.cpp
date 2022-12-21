#include "main.h"
#include "chessboard.hpp"

// Diagram of the chessboard squares:

/*
A1 A2 A3 A4 A5 A6
B1 B2 B3 B4 B5 B6
C1 C2 C3 C4 C5 C6
D1 D2 D3 D4 D5 D6
E1 E2 E3 E4 E5 E6  
F1 F2 F3 F4 F5 F6
*/

// Set the values of the chessboard squares.
void set_squares() {
    
    A1 = {0.5_tile, 5.5_tile};
    A2 = {0.5_tile, 4.5_tile};
    A3 = {0.5_tile, 3.5_tile};
    A4 = {0.5_tile, 2.5_tile};
    A5 = {0.5_tile, 1.5_tile};
    A6 = {0.5_tile, 0.5_tile};
    B1 = {1.5_tile, 5.5_tile};
    B2 = {1.5_tile, 4.5_tile};
    B3 = {1.5_tile, 3.5_tile};
    B4 = {1.5_tile, 2.5_tile};
    B5 = {1.5_tile, 1.5_tile};
    B6 = {1.5_tile, 0.5_tile};
    C1 = {2.5_tile, 5.5_tile};
    C2 = {2.5_tile, 4.5_tile};
    C3 = {2.5_tile, 3.5_tile};
    C4 = {2.5_tile, 2.5_tile};
    C5 = {2.5_tile, 1.5_tile};
    C6 = {2.5_tile, 0.5_tile};
    D1 = {3.5_tile, 5.5_tile};
    D2 = {3.5_tile, 4.5_tile};
    D3 = {3.5_tile, 3.5_tile};
    D4 = {3.5_tile, 2.5_tile};
    D5 = {3.5_tile, 1.5_tile};
    D6 = {3.5_tile, 0.5_tile};
    E1 = {4.5_tile, 5.5_tile};
    E2 = {4.5_tile, 4.5_tile};
    E3 = {4.5_tile, 3.5_tile};
    E4 = {4.5_tile, 2.5_tile};
    E5 = {4.5_tile, 1.5_tile};
    E6 = {4.5_tile, 0.5_tile};
    F1 = {5.5_tile, 5.5_tile};
    F2 = {5.5_tile, 4.5_tile};
    F3 = {5.5_tile, 3.5_tile};
    F4 = {5.5_tile, 2.5_tile};
    F5 = {5.5_tile, 1.5_tile};
    F6 = {5.5_tile, 0.5_tile};

}