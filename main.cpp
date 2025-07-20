#include "Vehicle.cpp"
#include <iostream>
#include "grid.cpp"


int main()
{
    // define all the variables needed for the grid
    Grid grid; 
    int rows = 2;
    int columns = 4;

    grid.generateGrid(rows, columns);

    // generate Vehicles to put on the grid
    Vehicle AICar;

    AICar.setLocation(1, 3);


    grid.showGrid();

}

