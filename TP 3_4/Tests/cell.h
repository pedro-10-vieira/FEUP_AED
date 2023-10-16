#ifndef CELL_H
#define CELL_H

class Cell {
    int x, y;
    int steps;
public:
    Cell();
    Cell(int x, int y);
    Cell(int x, int y, int s);
    int getX() const;
    int getY() const;
    int getSteps() const;
    bool isInside(int n) const;
};

#endif //CELL_H
