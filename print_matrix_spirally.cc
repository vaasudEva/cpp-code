/*
 * Print Matrix Spirally
 * Author: Shakthi Prashanth <m.shakthi.prashanth@gmail.com>
 * Date: 25/08/2018
*/


#include <iostream>
#include <utility>
#include <vector>

using namespace std;

using Row = vector<int>;
using Cell = pair<int, int>;

vector<Row>   readMatrix(int rows, int cols); // Linked to read_matrix.cc

Cell          printRight(const vector<Row> &matrix, int i, int j, int pass, size_t &nVisited);
Cell          printDown(const vector<Row> &matrix, int i, int j, int pass, size_t &nVisited);
Cell          printLeft(const vector<Row> &matrix, int i, int j, int pass, size_t &nVisited);
Cell          printUp(const vector<Row> &matrix, int i, int j, int pass, size_t &nVisited);

void printSpirally(const vector<Row> &matrix)
{
  size_t nVisited = 0;
  auto rows = matrix.size(), cols = matrix[0].size();

  for (int pass = 1, i = 0, j = 0; nVisited < rows*cols; pass++, i++, j++) {
    auto lastCell = printRight(matrix, i, j, pass, nVisited);
    lastCell = printDown(matrix, lastCell.first+1, lastCell.second, pass, nVisited);
    lastCell = printLeft(matrix, lastCell.first, lastCell.second-1, pass, nVisited);
    lastCell = printUp(matrix, lastCell.first-1, lastCell.second, pass, nVisited);
  }
  //cout << "nVisited: " << nVisited << endl;
}

Cell printRight(const vector<Row> &matrix, int i, int j, int pass, size_t &nVisited)
{
  auto cols = matrix[i].size();
  auto count = cols - (pass-1)*2;
  cerr << i << ", " << j << "cols: " << cols << ", count" << count << endl;

  while (count--) {
    cout << matrix[i][j++];
    if (count == 0) cout << endl;
    else cout << ", ";
    nVisited++;
  }
  //cout << " R nVisited: " << nVisited << endl;
  return make_pair(i, j-1); // last cell visited
}

Cell printDown(const vector<Row> &matrix, int i, int j, int pass, size_t &nVisited)
{
  auto rows = matrix.size();
  auto count = pass == 1 ? rows-1 : rows-1-pass;

  while (count--) {
    cout << matrix[i++][j];
    if (count == 0) cout << endl;
    else cout << ", ";
    nVisited++;
  }
//  cout << " D nVisited: " << nVisited << endl;
  return make_pair(i-1, j); // last cell visited
}

Cell printLeft(const vector<Row> &matrix, int i, int j, int pass, size_t &nVisited)
{
  auto cols = matrix[i].size();
  auto count = pass == 1 ? cols-1 : cols-1-pass;

  while (count--) {
    cout << matrix[i][j--];
    if (count == 0) cout << endl;
    else cout << ", ";
    nVisited++;
  }
//  cout << " L nVisited: " << nVisited << endl;
  return make_pair(i, j+1); // last cell visited
}

Cell printUp(const vector<Row> &matrix, int i, int j, int pass, size_t &nVisited)
{
  auto rows = matrix.size();
  auto count = pass == 1 ? rows-2 : rows-2-pass;

  while (count--) {
    cout << matrix[i--][j];
    if (count == 0) cout << endl;
    else cout << ", ";
    nVisited++;
  }
//  cout << " U nVisited: " << nVisited << endl;
  return make_pair(i+1, j); // last cell visited
}

int main()
{
  cout << "Enter matrix size: rows, cols" << endl;

  pair<int, int> size;
  cin >> size.first >> size.second;

  cout << "Enter elements of matrix[" << size.first << "][" << size.second << "]" << endl;
  auto matrix = readMatrix(size.first, size.second);
  cout << "Read matrix" << endl;
  printSpirally(matrix);
}

