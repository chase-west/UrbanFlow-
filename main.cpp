#include "Vehicle.h"
#include <iostream>
#include "grid.cpp"
#include <random>
#include <queue>

using namespace std;

// global size of grid 
const int rowSize = 10;
const int columnSize = 10;


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

bool isValid(bool visited[][columnSize], int row, int col, Grid &grid)
{ 
    if (row < 0 || col < 0)
    {
        return false; 
    }

    if (grid.getCell(row, col).isOccupied())
    {
        return false; 
    }

    return true; 
}

void pathFind(Grid &grid, Vehicle &vehicle, int targetRow, int targetColumn)
{
    bool BFS = true; // future implementation allow for diff algs i guess this is just for rn

    auto loc = vehicle.getLocation();
    int currentRow = loc.first;
    int currentColumn = loc.second;

    if (currentRow == targetRow && currentColumn == targetColumn) // base case 
    {
        cout << "Already at target area!" << endl;
        grid.getCell(currentRow, currentColumn).setVehicle(nullptr);
        grid.showGrid();
    }

    if (BFS)
    {
        // direction vectors
        int dRow[] = { -1, 0, 1, 0 };
        int dCol[] = { 0, 1, 0, -1 };
        
        bool visited[rowSize][columnSize]; // track visited cells
    
        queue<pair<int, int> > q; 
        q.push({currentRow, currentColumn});

        visited[currentRow][currentColumn] = true;

        while (!q.empty())
        {
            pair<int, int> cell = q.front();
            int x = cell.first;
            int y = cell.second;

            // update car position and output grid here!! 

            q.pop();

            // go to other cells
            for (int i = 0; i < 4; i++)
            {
                int adjX = x + dRow[i];
                int adjY = y + dCol[i];

                if(isValid(visited, adjX, adjY, grid))
                {
                    q.push({adjX, adjY});
                    visited[adjX][adjY] = true;


                    // update grid 
                    grid.getCell(x, y).setOccupied(false);
                    grid.getCell(adjX, adjY).setOccupied(true); 
                    grid.showGrid();  
                }
            }

            
        }

    }
}

int main()
{
    // define all the variables needed for the grid
    Grid grid;
    int availableSpots = 4; // how many empty spots should there be for movement
    int maxCars = 20;

    grid.generateGrid(rowSize, columnSize);

    // create random amount robot cars to drive around
    try
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(1, maxCars + 1);
        int carAmount = distrib(gen);
        if (grid.NumOfCells >= carAmount - availableSpots)
        {
            createVehicles(carAmount, grid, rowSize, columnSize);
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
