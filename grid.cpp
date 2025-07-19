#include <string>
#include <iostream>
#include <vector>


using namespace std; 
class Cell
{
	int x, y; // x,y location for cell
	string cellType; 

	public:
		Cell(int x, int y, string cellType) {
			this->x = x;
			this->y = y;
			this->cellType = cellType;
		}


};

class Grid
{
	public : 
		void generateGrid(int rows, int columns) // get rows and columns in order to create max grid size
		{

			vector<vector<Cell>> grid;

			grid.resize(rows);

			for (int i = 0; i < rows; i++)
			{
				grid[i].resize(columns);

				for (int j = 0; j < columns; j++)
				{
					grid[i][j] = Cell(i, j, "test");
				}
			}
		}
};
