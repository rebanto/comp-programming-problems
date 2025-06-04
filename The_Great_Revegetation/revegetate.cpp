#include <fstream>
#include <vector>
#include <string>

using namespace std; 

int main() {
    ifstream fin("revegetate.in");
    ofstream fout("revegetate.out");

    int N, M;
    fin >> N >> M;

    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        fin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> pasture_grass_type(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        bool grass_type_taken[5] = {false}; 

        for (int neighbor : adj[i]) {
            grass_type_taken[pasture_grass_type[neighbor]] = true;
        }

        for (int type = 1; type <= 4; ++type) {
            if (!grass_type_taken[type]) {
                pasture_grass_type[i] = type;
                break;
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        fout << pasture_grass_type[i];
    }
    fout << '\n';

    return 0;
}