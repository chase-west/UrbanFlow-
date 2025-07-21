#include <string>
#include <iostream>
#include <vector>


using namespace std; 
class Cell
{
	int x, y; // x,y location for cell
	string cellType; 

	public:
	Cell() = default;

	public:
		Cell(int x, int y, string cellType) {
			this->x = x;
			this->y = y; 
			this->cellType = cellType;
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
					grid[i][j] = Cell(i, j, "test");
					NumOfCells++;
				}
			}
		}


		void showGrid()
		{
			int rows = grid.size();
			int columns = grid[0].size();

			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					cout << "[-]";
				}
				cout << endl;
			}
		}
};
