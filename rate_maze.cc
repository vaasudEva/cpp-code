#include <iostream>
#include <utility>
#include <cstring>

using namespace std;

#define X 1000

enum Route { UP, DOWN, LEFT, RIGHT, END };

using Cell = pair<int, int>;

bool isLast(int i, int j, int mR, int mC)
{ return i == mR-1 && j == mC-1; }

bool hasPath(int m[X][X], int i, int j)
{ return m[i][j] == 1; }

bool isValid(int i, int j, int mR, int mC)
{ return !(i < 0 || i >= mR || j < 0 || j >= mC); }

Cell getNext(int i, int j, Route r)
{
  switch (r) {
  case UP: return make_pair(i-1, j);
  case DOWN: return make_pair(i+1, j);
  case LEFT: return make_pair(i, j-1);
  case RIGHT: return make_pair(i, j+1);
  default: return make_pair(-1, -1);
  }
}

bool generateSolution(int m[X][X], int s[X][X], int i, int j, int mR, int mC)
{
  s[i][j] = 1;
  if (isLast(i, j, mR, mC)) return true;
  
  bool foundPath = false;
  for (Route r = UP; r < END; r = Route(int(r) + 1)) {
    auto nextCell = getNext(i, j, r);
    int ni = nextCell.first, nj = nextCell.second;
    if (isValid(ni, nj, mR, mC) &&
        hasPath(m, ni, nj) &&
        s[ni][nj] == 0)
      foundPath = generateSolution(m, s, ni, nj, mR, mC);
    if (foundPath) break;
   }
   // Reached Dead end; unset this cell in solution matrix
   if (!foundPath) s[i][j] = 0;
   return foundPath;
 }
 
 void generateSolution(int m[X][X], int s[X][X], int mR, int mC)
 {
   generateSolution(m, s, 0, 0, mR, mC);
 }
