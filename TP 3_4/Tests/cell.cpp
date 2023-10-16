#include "cell.h"

Cell::Cell() {};

Cell::Cell(int x, int y): x(x), y(y) {};

Cell::Cell(int x, int y, int s): x(x), y(y), steps(s) {};

int Cell::getX() const {
    return x;
}

int Cell::getY() const {
    return y;
}

int Cell::getSteps() const {
    return steps;
}

bool Cell::isInside(int n) const {
    if (x >= 1 && x <= n && y >= 1 && y <= n)
        return true;
    return false;
}