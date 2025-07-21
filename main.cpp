#include "Vehicle.cpp"
#include <iostream>
#include "grid.cpp"
#include <random>


// generate Vehicles to put on the grid
void createVehicles(int amount)
{
    // place the vehicles on the grid

}

int main()
{
    // define all the variables needed for the grid
    Grid grid; 
    int rows = 10;
    int columns = 10;
    int availableSpots = 4; // how many empty spots should there be for movement
    int maxCars = 20; 


    grid.generateGrid(rows, columns);

    // create random amount robot cars to drive around
    try {
        random_device rd; 
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(1, maxCars + 1);
        int carAmount = distrib(gen);
        if (grid.NumOfCells >= carAmount - availableSpots)
        {
            createVehicles(distrib(gen));
        }
        else 
        {
            throw(carAmount);
        }
    }
    catch (int carAmount)
    {
        cout << "Too many cars (" << carAmount << ") for this grid!" << endl;;
    }

    grid.showGrid();

}

