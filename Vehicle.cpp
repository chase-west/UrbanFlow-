#include <utility>
using namespace std; 
class Vehicle 
{
  private:
    int row;
    int column; 

  public:
    void setLocation(int row, int column)
    {
      this->row = row;
      this->column = column;
    }

    pair <int, int> getLocation()
    {
      return {row, column};
    }
};