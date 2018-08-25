#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

#define ROWS    100
#define COLS    100

using Cell = pair<int, int>;

Cell  printRight(int a[][COLS], int i, int j, int rows, int cols, int pass, size_t &nVisited);
Cell  printDown(int a[][COLS], int i, int j, int rows, int cols, int pass, size_t &nVisited);
Cell  printLeft(int a[][COLS], int i, int j, int rows, int cols, int pass, size_t &nVisited);
Cell  printUp(int a[][COLS], int i, int j, int rows, int cols, int pass, size_t &nVisited);

void printSpirally(int matrix[][COLS], int rows, int cols)
{
  size_t nVisited = 0;

  for (int pass = 1, i = 0, j = 0; nVisited < size_t(rows*cols); pass++, i++, j++) {
    auto lastCell = printRight(matrix, i, j, rows, cols, pass, nVisited);
    if (nVisited >= rows*cols)	break;
    
    lastCell = printDown(matrix, lastCell.first+1, lastCell.second, rows, cols, pass, nVisited);
	if (nVisited >= rows*cols)	break;
    
    lastCell = printLeft(matrix, lastCell.first, lastCell.second-1, rows, cols, pass, nVisited);
    if (nVisited >= rows*cols)	break;
    
    lastCell = printUp(matrix, lastCell.first-1, lastCell.second, rows, cols, pass, nVisited);
    if (nVisited >= rows*cols)	break;
  }
  //cout << "nVisited: " << nVisited << endl;
}

Cell printRight(int matrix[][COLS], int i, int j, int rows, int cols, int pass, size_t &nVisited)
{
  auto count = cols - (pass-1)*2;
  //cerr << i << ", " << j << "cols: " << cols << ", count" << count << endl;

  while (count--) {
    cout << matrix[i][j++];
    nVisited++;
    if (nVisited == size_t(rows*cols)) cout << endl;
    else cout << ", ";
  }
  //cout << " R nVisited: " << nVisited << endl;
  return make_pair(i, j-1); // last cell visited
}

Cell printDown(int matrix[][COLS], int i, int j, int rows, int cols, int pass, size_t &nVisited)
{
  auto count = pass == 1 ? rows-1 : rows-1-pass;

  while (count--) {
    cout << matrix[i++][j];
    nVisited++;
    if (nVisited == size_t(rows*cols)) cout << endl;
    else cout << ", ";
  }
//  cout << " D nVisited: " << nVisited << endl;
  return make_pair(i-1, j); // last cell visited
}

Cell printLeft(int matrix[][COLS], int i, int j, int rows, int cols, int pass, size_t &nVisited)
{
  auto count = pass == 1 ? cols-1 : cols-1-pass;

  while (count--) {
    cout << matrix[i][j--];
	nVisited++;
    if (nVisited == size_t(rows*cols)) cout << endl;
    else cout << ", ";
  }
//  cout << " L nVisited: " << nVisited << endl;
  return make_pair(i, j+1); // last cell visited
}

Cell printUp(int matrix[][COLS], int i, int j, int rows, int cols, int pass, size_t &nVisited)
{
  auto count = pass == 1 ? rows-2 : rows-2-pass;

  while (count--) {
    cout << matrix[i--][j];
    nVisited++;
    if (nVisited == size_t(rows*cols)) cout << endl;
    else cout << ", ";
  }
//  cout << " U nVisited: " << nVisited << endl;
  return make_pair(i+1, j); // last cell visited
}
