#include <vector>
using namespace std;

class Trechode {
public:
    void dfs(int node, vector<vector<int>>& adjMatrix, vector<int>& minActivity, vector<int>& serverWeight,
             int& disconnectCount, int currentActivity, vector<bool>& visited) {
        visited[node] = true;
        if (currentActivity > minActivity[node]) {
            disconnectCount++;
            return;
        }
        for (int child = 0; child < adjMatrix[node].size(); ++child) {
            if (adjMatrix[node][child] != 0 && !visited[child]) {
                int newActivity = currentActivity + adjMatrix[node][child];
                dfs(child, adjMatrix, minActivity, serverWeight, disconnectCount, newActivity, visited);
            }
        }
    }

    int getMinServers(int serverNodes, vector<int>& serverFrom, vector<int>& serverTo, vector<int>& serverWeight, vector<int>& minActivity) {
        vector<vector<int>> adjMatrix(serverNodes, vector<int>(serverNodes, 0));
        for (size_t i = 0; i < serverFrom.size(); ++i) {
            int from = serverFrom[i] - 1;
            int to = serverTo[i] - 1;
            adjMatrix[from][to] = serverWeight[i];
        }

        int disconnectCount = 0;
        vector<bool> visited(serverNodes, false);
        dfs(0, adjMatrix, minActivity, serverWeight, disconnectCount, 0, visited);

        return disconnectCount;
    }
};
