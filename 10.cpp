

//Prim’s Algorithm 

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int>pii;

int prims(int vertex, int edge, int graph[][3])  {
    vector<pii> adj[vertex+1];
    for (int i = 0; i<edge; i++) {
        int u=graph[i][0];
        int v=graph[i][1];
        int wt=graph[i][2];
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    vector<bool> visited(vertex+1,false);
    priority_queue<pii, vector<pii>, greater<pii>>pq;
    int sum=0;
    pq.push({0, 0});   		//order: weight>>vertex cz, minheap wrt weight
    
    while(!pq.empty()) {
        auto p = pq.top(); 	// p is a pair now
        pq.pop();
        int wt=p.first; 		 //weight of edge
        int vertex=p.second; 		  //vertex value
        if(visited[vertex]==true)
            continue;
      
        visited[vertex]=true;
        sum+=wt;
       
       for(auto node:adj[vertex]) {   //for every node in adj[vertex]
            int vt=node.first;
            int wt=node.second;
         if(visited[vt] == false)
		        pq.push({wt, vt}); 
        }
    }
    return sum;

}



int main()
{
    int graph[][3] = {{0, 1, 5},
                      {1, 2, 3},
                      {0, 2, 1}};
    int weight=prims(3,3, graph);
    
    
    int edges = sizeof(graph) / sizeof(graph[0]);
    cout<<endl<<endl<<"edge      weight"<<endl;
    
    for (int i = 0; i<edges; i++)
        cout<<graph[i][0]<<"---"<<graph[i][1]<<"\t\t"<<graph[i][2]<<endl;
    
    cout<<endl<<endl<<endl<<"Weight of minimum spanning tree="<<weight<<endl;
    return 0;   
}













//knapsack problem
#include <bits/stdc++.h>
using namespace std;


void print_array(vector<int>& result){
    for (int item : result)
        cout << item << "\t";
    cout << endl;
}


vector<int> knapSack(int capacity, vector<int> wt, vector<int> val, int n)
{
    vector<vector<int> > K(n + 1, vector<int>(capacity + 1));
    vector<int> items;

    //main part
    for (int i = 0; i <= n; i++) 
        for (int w = 0; w <= capacity; w++)  {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (w >= wt[i - 1])
                K[i][w] = max(  (val[i-1]+ K[i-1][w-wt[i-1]]) , K[i-1][w]  );   //this is given formula
            else
                K[i][w] = K[i - 1][w];
        }

    //K[n][capacity] has max profit now
    
    cout<<"-----------------------------\nMax profit =  "<<K[n][capacity]<<endl;

    int w = capacity;
    for (int i = n; i > 0 && w > 0; i--)
        if (K[i][w] != K[i - 1][w]) {
            items.push_back(i); 
            w -= wt[i - 1];
        }
    return items;
}


int main(){
    vector<int> profit = { 6, 10, 12, 7, 5 };
    vector<int> weight = { 3, 4, 5, 2, 1 };
    int capacity = 10;
    int n = sizeof(profit) / sizeof(profit[0]);

    cout<<"Profit =  ";
    print_array(profit);
    cout<<"Weight =  ";
    print_array(weight);
    cout<<"Capacity = "<<capacity<<endl;
    
    vector<int>result= knapSack(capacity, weight, profit, n); 
    
    cout<<"Items =  ";
    print_array(result);
    return 0;
}
