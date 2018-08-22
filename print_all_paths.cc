#include<bits/stdc++.h>
using namespace std;
const size_t X = 1000;

using Cell = pair<int, int>;
using Path = vector<int>;

bool isValidCell(Cell c, int mR, int mC)
{
	return c.first < 0 || c.first >= mR ||
      		c.second < 0 || c.second >= mC ? false : true;
}

bool isDestinationCell(Cell c, int mR, int mC)
{
	return c.first == mR-1 && c.second == mC-1;  
}

void getAllMatrixPaths(int m[X][X], Cell c, int rows, int cols,
                       Path &path, vector<Path> &allPaths)
{
  	if (!isValidCell(c, rows, cols))	return;
	
  	path.push_back(m[c.first][c.second]);
  
  	if (isDestinationCell(c, rows, cols)) {
		allPaths.push_back(path);
      	path.pop_back();
      	return;		
    }
  
  	// Visit DOWN neighbour first
  	getAllMatrixPaths(m, make_pair(c.first+1, c.second), rows, cols, path, allPaths);
  	// Visit RIGHT neighbour
  	getAllMatrixPaths(m, make_pair(c.first, c.second+1), rows, cols, path, allPaths);
	path.pop_back();
}

void getAllMatrixPaths(int m[X][X], Cell c, int rows, int cols, vector<Path> &all_paths)
{
  	Path path {};
	getAllMatrixPaths(m, c, rows, cols, path, all_paths);  
}

void printAllMatrixPaths(int m[X][X], int r, int c)
{
  	vector<Path> allPaths {};
	getAllMatrixPaths(m, make_pair(0, 0), r, c, allPaths);
  	for (auto path : allPaths) {
    	for (auto cell : path)
			cout << cell << " ";
      	cout << endl;
    }
}


int main()
{

    int cells[X][X] = {
                        { 1, 2, 3, 4, 5 },
                        { 2, 3, 4, 5, 6 },
                        { 3, 4, 5, 6, 7 },
                        { 4, 5, 6, 7, 8 }
                    };
    printAllMatrixPaths(cells, 4, 5);

    return 0;
}
