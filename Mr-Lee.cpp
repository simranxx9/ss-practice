#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g = {
    {9, 9, 2, 9, 5},
    {6, 3, 5, 1, 5},
    {1, 8, 3, 3, 3},
    {6, 0, 9, 6, 8},
    {6, 6, 9, 4, 8}
};

int dp[1000][1000];

int rec(vector<vector<pair<int, int>>> &graph, int n, int visited, int cost, int currentNode, int numOfNodesVisited) {
    

    if(dp[currentNode][visited] != -1) return dp[currentNode][visited];
    
    if(numOfNodesVisited == n-1) {
        if(g[currentNode][0]) return cost + g[currentNode][0];
    }
    
    int ans = INT_MAX;
    
    for(pair<int, int> p: graph[currentNode]) {
        if(!(visited & (1<<p.first))) {
            ans = min(ans, rec(graph, n, (visited | (1<<(p.first))), cost + p.second, p.first, numOfNodesVisited + 1));
        }
    } 
    
    return dp[currentNode][visited] = ans;
}


int main() {
    int n = 5;
    
    int visited = 0;
    memset(dp, -1, sizeof(dp));
    
    vector<vector<pair<int, int>>> graph(n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(g[i][j]) graph[i].push_back({j, g[i][j]});
        }
    }  
    int ans = rec(graph, n, visited, 0, 0, 0);
    
    cout << "ANS " << ans;
    return 0;
}
