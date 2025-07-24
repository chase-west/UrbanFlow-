#include <string>
#include <iostream>
#include <vector>
#include "Vehicle.h"
using namespace std; 
class Cell
{
	int x, y; // x,y location for cell
	unique_ptr<Vehicle> vehiclePtr;

	public:
	Cell() = default;

	public:
		Cell(int x, int y) {
			this->x = x;
			this->y = y; 
		}

		void setVehicle(Vehicle* v) { vehiclePtr = unique_ptr<Vehicle>(v); }
		Vehicle* getVehicle() const {return vehiclePtr.get(); }

		bool isOccupied()
		{
			if (vehiclePtr != nullptr)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
};

class Grid
{
	vector<vector<Cell>> grid; //define the 2d vector here so other methods can access 

	public : 
		int NumOfCells = 0;
		void generateGrid(int rows, int columns) // get rows and columns in order to create max grid size
		{
			grid.resize(rows);

			for (int i = 0; i < rows; i++)
			{
				grid[i].resize(columns);

				for (int j = 0; j < columns; j++)
				{
					grid[i][j] = Cell(i, j);
					NumOfCells++;
				}
			}
		}
		Cell& getCell(int row, int col)
		{
			return grid[row][col];
		}


		int getNumOfRows()
		{
			return grid.size();
		}

		int getNumOfColumns()
		{
			return grid[0].size(); 
		}


		void showGrid()
		{
			int rows = grid.size();
			int columns = grid[0].size();

			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					if (grid[i][j].isOccupied() == true)
					{
						cout << "[c]";
					}
					else 
					{
						cout << "[-]";
					}
				}
				cout << endl;
			}
		}


		void placeVehicle(Vehicle* vehicle, int row, int column)
		{
			vehicle->setLocation(row, column);
			grid[row][column].setVehicle(vehicle);
		}
};
