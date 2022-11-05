//that no two adjacent vertices of graph are coloured with same colour.

bool isSafe(bool graph[101][101], int V, int color[], int node, int col){
    for(int i = 0; i < V; i++){
        if(i != node && graph[node][i] == 1 && color[i] == col) return false;
    }
    return true;
}

bool solve(bool graph[101][101], int m, int V, int color[], int node){
    if(node == V) return true;
    
    for(int i = 1; i <= m; i++){
        if(isSafe(graph, V, color, node, i)){
            color[node] = i;
            if(solve(graph, m, V, color, node+1)) return true;
            color[node] = 0;
        }
    }
    
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    int color[V] = {0};
    
    return solve(graph, m, V, color, 0);
}
