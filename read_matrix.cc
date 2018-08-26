
#include <iostream>
#include <vector>

using namespace std;

using Row = vector<int>;

void print(const vector<Row> &matrix);

vector<Row> readMatrix(int rows, int cols)
{
  vector<Row> matrix;

  for (int r = 0; r < rows; r++) {
    matrix.push_back({0, });
    for (int c = 0, item; c < cols; c++) {
      cin >> item;
      if (c == 0) matrix[r].pop_back();
      matrix[r].push_back(item);
    }
  }
  print(matrix);

  return matrix;
}

void print(const vector<Row> &matrix)
{
  for (auto row : matrix) {
    for (auto item : row)
      cout << item << " ";
    cout << endl;
  }
}
