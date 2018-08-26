#include <bits/stdc++.h>
using namespace std;

#define MAX_R 1000
#define MAX_C 1000

using Cell = pair<int, int>;

int		cost	[MAX_R][MAX_C];
bool	visited	[MAX_R][MAX_C];

enum Route { LEFT = 0, STRAIGHT, RIGHT, END };

Cell getNext(int i, int j, Route route)
{
	switch (route) {
    case LEFT:
        return make_pair(i-1, j+1);
	case STRAIGHT:    
		return make_pair(i, j+1);
    case RIGHT:    
		return make_pair(i+1, j+1);
    default:
        return make_pair(-1, -1);
    }
}

bool isValid(Cell cell, int mR, int mC)
{
	//cout << "isValid: " << cell.first << ", " << cell.second << endl; 
	return (cell.first < 0 || cell.first >= mR || cell.second < 0 || cell.second >= mC) ? false : true;
}

bool isLast(Cell cell, int mR, int mC)
{
	return cell.first == mR-1 && cell.second == mC-1;
}

int minCostOfTollTravel(Cell cell, int mR, int mC)
{
  	// Validity check ignored here as it is done before coming here.
  	auto i = cell.first, j = cell.second;
  	visited[i][j] = true;
  
  	if (isLast(cell, mR, mC)) {
		//cout << i << ", " << j << ", cost: " << cost[i][j] << endl; 
    	return cost[i][j];
    }
  
  	int _cost[END] = { 0, }, idx = 0;
	for (Route r = LEFT; r < END; r = Route(int(r) + 1)) {
    	auto next = getNext(i, j, r);

      	if (isValid(next, mR, mC) &&
            !visited[next.first][next.second]) {
			//cout << i << ", " << j << ", Valid next: " << next.first << ", " << next.second << endl; 
        	_cost[idx++] = minCostOfTollTravel(next, mR, mC);
        }
    }
  	visited[i][j] = false;
  	auto minCost = cost[i][j] + min(_cost[0], min(_cost[1], _cost[2]));
  	//cout << i << ", " << j << ", min(" << _cost[0] << ", " << _cost[1]
  		//<< ", " << _cost[2] << "): " << minCost << endl; 
  	return minCost;
}

void reset(bool visited[][MAX_C])
{
	for (int r = 0; r < MAX_R; r++)
    	for (int c = 0; c < MAX_C; c++)
        	visited[r][c] = false;
}

int minCostOfTollTravel(int r, int c, int startLane)
{
  	reset(visited);
  	//cout << "startLane: " << startLane-1 << ", " << 0 << endl;
	return minCostOfTollTravel(make_pair(startLane-1, 0), r, c);
}
            
