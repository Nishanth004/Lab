//Dijkstra's algorithm

#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

typedef pair<int, int> pii;
int V; 
vector<pii> *adj;

void addEdge(int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}
//  format after execution
// adj[0]:{(1, 4), (7, 8)}
// adj[1]:{(0, 4), (2, 8), (7, 11)}

void shortestPath(int src) {
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    vector<int> dist(V, INF);

    pq.push({0, src});  //order: weight>>vertex cz, minheap wrt weight
    dist[src] = 0;

    while (!pq.empty()) {
        int vertex = pq.top().second;
        pq.pop();
      
        for (auto node : adj[vertex])  {  	//for every node in adj[vertex]
            int vt = node.first;  
            int weight = node.second;
          
            if (dist[vt] > dist[vertex] + weight)  //if old distance is greater than new distance
            {   
                dist[vt] = dist[vertex] + weight;
                pq.push({dist[vt], vt});
            }
        }
    }

    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d--> %d  =  %d\n",src, i, dist[i]);
}

int main() 
{
    V = 9;
    adj = new vector<pii>[V];
    addEdge(0, 1, 4);  //vertex1, vertex2, weight
    addEdge(0, 7, 8);
    addEdge(1, 2, 8);
    addEdge(1, 7, 11);
    addEdge(2, 3, 7);
    addEdge(2, 8, 2);
    addEdge(2, 5, 4);
    addEdge(3, 4, 9);
    addEdge(3, 5, 14);
    addEdge(4, 5, 10);
    addEdge(5, 6, 2);
    addEdge(6, 7, 1);
    addEdge(6, 8, 6);
    addEdge(7, 8, 7);

    shortestPath(0);
    return 0;
}
