/**
 * Print graph with its adjacency vertices.
 * Author: Shakthi Prashanth <m.shakthi.prashanth@gmail.com>
 * Date: 09/Sep/2018
*/

#include <iostream>
#include <vector>

using namespace std;

ostream &operator<<(ostream &out, vector<vector<int>> &graph);

int main()
{
    size_t nTests;
    cin >> nTests;

    while (nTests--) {
        size_t nVertices, nEdges;
        cin >> nVertices >> nEdges;

        vector<vector<int>> graph;

		for (int vertex = 0; vertex < nVertices; vertex++)
     		graph.push_back({});

        for (int edge = 0; edge < nEdges; edge++) {
            int v0, v1;
            cin >> v0 >> v1;
          
            graph[v0].push_back(v1);
			graph[v1].push_back(v0);
        }

      	cout << graph << endl;
    }
  	return 0;
}

ostream &operator<<(ostream &out, vector<vector<int>> &graph)
{
	int idx = 0;
    for (auto edge : graph) {
    	cout << idx++ << " : ";
        for (auto v : edge)
        	cout << v << " ";
		cout << endl;
    }
  	return out; 
}
