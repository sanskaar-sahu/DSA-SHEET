/**
 Given a sorted dictionary of an alien language having N words and K starting alphabets of a standard dictionary. 
 Find the order of characters in the alien language.
 There may be multiple valid orders for a particular test case, thus you 
may return any valid order as a string. The output will be True if the order returned by the function is correct, else False denoting an incorrect order. If the given arrangement of words is inconsistent with any possible letter ordering, return an empty string "".


Example 1

Input: N = 5, K = 4, dict = ["baa","abcd","abca","cab","cad"]
Output: b d a c

Explanation: 
We will analyze every consecutive pair to find out the order of the characters.
The pair “baa” and “abcd” suggests ‘b’ appears before ‘a’ in the alien dictionary.
The pair “abcd” and “abca” suggests ‘d’ appears before ‘a’ in the alien dictionary.
The pair “abca” and “cab” suggests ‘a’ appears before ‘c’ in the alien dictionary.
The pair “cab” and “cad” suggests ‘b’ appears before ‘d’ in the alien dictionary.
So, [‘b’, ‘d’, ‘a’, ‘c’] is a valid ordering.
 */


class Solution {
public:

    string topo(vector<int> adj[], int K) {
        vector<int> indeg(K, 0);

        // Calculate indegree
        for (int i = 0; i < K; i++) {
            for (auto it : adj[i]) {
                indeg[it]++;
            }
        }

        // Queue for BFS
        queue<int> q;
        for (int i = 0; i < K; i++) {
            if (indeg[i] == 0)
                q.push(i);
        }

        string res;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            res.push_back(char(node + 'a'));

            for (auto it : adj[node]) {
                indeg[it]--;
                if (indeg[it] == 0)
                    q.push(it);
            }
        }

        // Cycle check
        if (res.length() < K)
            return "";

        return res;
    }

    string findOrder(string dict[], int N, int K) {

        vector<int> adj[K];

        // Build graph
        for (int i = 0; i < N - 1; i++) {
            string s1 = dict[i];
            string s2 = dict[i + 1];

            int len = min(s1.length(), s2.length());

            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }

        return topo(adj, K);
    }
};
