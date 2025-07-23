#include "Vehicle.h"
#include <iostream>
#include "grid.cpp"
#include <random>
#include <queue>

using namespace std;


// store vehicles when making them 
vector<Vehicle*> vehicles;

// generate Vehicles to put on the grid
void createVehicles(int amount, Grid &grid, int rows, int columns)
{
    // generate random amount of vehicles bounded by the rows and columns
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> rowDistrib(0, rows - 1);
    uniform_int_distribution<> colDistrib(0, columns - 1);

    // place the vehicles on the grid
    for (int i = 0; i < amount; i++)
    {
        int row = 0;
        int column = 0;
        do
        {
            row = rowDistrib(gen);
            column = rowDistrib(gen);
        } 
        while (grid.getCell(row, column).isOccupied());

        Vehicle *v = new Vehicle();

        vehicles.emplace_back(v);

        grid.placeVehicle(v, row, column);
    }
}

void pathFind(Grid &grid, Vehicle &vehicle, int targetRow, int targetColumn)
{
    bool usingDijkstra = true;
    // this is gonna be a ima try and figure it out alg

    auto loc = vehicle.getLocation();
    int currentRow = loc.first;
    int currentColumn = loc.second;

    if (currentRow == targetRow && currentColumn == targetColumn) // base case 
    {
        cout << "Already at target area!" << endl;
        grid.getCell(currentRow, currentColumn).setVehicle(nullptr);
        grid.showGrid();
    }

    if (usingDijkstra)
    {
        
    }
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
    try
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(1, maxCars + 1);
        int carAmount = distrib(gen);
        if (grid.NumOfCells >= carAmount - availableSpots)
        {
            createVehicles(carAmount, grid, rows, columns);
        }
        else
        {
            throw(carAmount);
        }
    }
    catch (int carAmount)
    {
        cout << "Too many cars (" << carAmount << ") for this grid!" << endl;
        ;
    }

    grid.showGrid();

    // get user's target grid space (where should the cars go to?)
    int targetRow = 0;
    int targetColumn = 0;

    cout << "Enter the row of where you want the cars to go to." << endl;
    cin >> targetRow;

    cout << "Enter the row of where you want the cars to go to." << endl;
    cin >> targetColumn;
    for (int i = 0; i < vehicles.size(); i++)
    {
        pathFind(grid, *vehicles[i], targetRow, targetColumn);
    }
}
