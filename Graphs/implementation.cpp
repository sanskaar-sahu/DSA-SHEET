#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> list;  

public:
    Graph(int v) {
        this->V = v;
        list.resize(v); 
    }

    void addEdge(int n1, int n2) {
        list[n1].push_back(n2);
        list[n2].push_back(n1);
    }

    void printList() {
        for (int i = 0; i < V; i++) {
            cout << i << " : ";
            for (int j : list[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

// Sample usage
int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printList();

    return 0;
}
