// single src shortest path in undirected graph with no negetive weight cycle

// using priority queue TC: O(E*logV)
vector <int> dijkstra(int v, vector<vector<int>> adj[], int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> explore;
    vector<int> dist(v, 1e9);
    dist[s] = 0;
    explore.push({0, s});

    while(explore.size()){
        int d = explore.top().first, node = explore.top().second;
        explore.pop();

        for(auto edge : adj[node]){
            int adjNode = edge[0], edgeWeight = edge[1];
            if(d + edgeWeight < dist[adjNode]){
                dist[adjNode] = d + edgeWeight;
                explore.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}


//using set TC same as above 
vector <int> dijkstra(int v, vector<vector<int>> adj[], int s)
{
    set<pair<int, int>> explore;
    vector<int> dist(v, 1e9);
    dist[s] = 0;
    explore.insert({0, s});

    while(explore.size()){
        auto it = *(explore.begin());
        int d = it.first, node = it.second;
        explore.erase({d, node});

        for(auto edge : adj[node]){
            int adjNode = edge[0], edgeWeight = edge[1];
            if(d + edgeWeight < dist[adjNode]){
                if(dist[adjNode] != 1e9) explore.erase({dist[adjNode], adjNode});
                dist[adjNode] = d + edgeWeight;
                explore.insert({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
 }
