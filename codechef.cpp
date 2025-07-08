#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        
        vector<long long> A(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        
        function<int(int)> find = [&](int x) -> int {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };
        
        long long totalCost = 0;
        
        for (int bit = 0; bit < 30; bit++) {
            long long L = 1LL << bit;
            
            // Group cities by their root parent that have this bit
            map<int, vector<int>> groups;
            for (int i = 0; i < n; i++) {
                if (A[i] & L) {
                    groups[find(i)].push_back(i);
                }
            }
            
            // Connect different components that can be connected with this bit
            vector<int> roots;
            for (auto& [root, cities] : groups) {
                roots.push_back(root);
            }
            
            for (int i = 0; i < roots.size(); i++) {
                for (int j = i + 1; j < roots.size(); j++) {
                    int root1 = roots[i], root2 = roots[j];
                    if (find(root1) != find(root2)) {
                        // Check if any city from group1 can connect to any city from group2
                        bool canConnect = false;
                        for (int u : groups[root1]) {
                            for (int v : groups[root2]) {
                                if ((A[u] & A[v] & L) == L) {
                                    canConnect = true;
                                    break;
                                }
                            }
                            if (canConnect) break;
                        }
                        
                        if (canConnect) {
                            parent[find(root2)] = find(root1);
                            totalCost += L;
                            break;  // Only one connection per bit per component pair
                        }
                    }
                }
            }
        }
        
        // Check connectivity
        set<int> components;
        for (int i = 0; i < n; i++) {
            components.insert(find(i));
        }
        
        cout << (components.size() == 1 ? totalCost : -1) << "\n";
    }
    
    return 0;
}