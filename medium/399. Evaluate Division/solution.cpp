// https://leetcode.com/problems/evaluate-division
// medium
// #array, #string, #depth-first-search, #breadth-first-search, #union-find, #graph, #shortest-path

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>


class Solution {
    struct Edge{
        std::string source;
        std::string dest;
        double w;
    };
public:
    std::vector<double> calcEquation(std::vector<std::vector<std::string>>& equations,
                                     std::vector<double>& values,
                                     std::vector<std::vector<std::string>>& queries) {
        // we'll create a graph for the equations to help navigate the queries
        // given a query, we can then find the shortest path between the two
        // varaibles. If no path can be found, the variables are disconnected
        // and the query cannot be satsifed.
        // Otherwise, walk the path, multiply the factor appropriately
        // let's create a disjoint set 

        // graph creation
        std::unordered_map<std::string, std::vector<Edge>*> graph;
        for(int i = 0; i < equations.size(); ++i){
            std::vector<std::string>& eq = equations[i];
            // add edge to graph
            auto node1_it = graph.find(eq[0]);
            auto node2_it = graph.find(eq[1]);
            if(node1_it == graph.end()){
                //create node
                graph[eq[0]] = new std::vector<Edge>;
                node1_it = graph.find(eq[0]);
            }
            if(node2_it == graph.end()){
                // node already exist, add edge
                graph[eq[1]] = new std::vector<Edge>;
                node2_it = graph.find(eq[1]);
            }
            // add edges
            (*node1_it).second->push_back(Edge{eq[0], eq[1], values[i]});
            (*node2_it).second->push_back(Edge{eq[1], eq[0], 1.0/values[i]});
        }

        // depth first search to find connecting path
        std::vector<double> eval;
        for (auto q: queries){
            std::unordered_map<std::string, Edge*> visited;
            std::stack<Edge*> dfs;

            if (graph.find(q[0]) == graph.end() || graph.find(q[1]) == graph.end()) eval.push_back(-1.0);
            else if (q[0] == q[1]) eval.push_back(1.0);
            else{
                // push initial edges
                for(int i = 0; i< graph[q[0]]->size(); ++i){
                    Edge* e = &((*graph[q[0]])[i]);
                    dfs.push(e);
                }
                visited[q[0]] = nullptr;

                Edge* current = nullptr;
                Edge* found = nullptr;

                while (!dfs.empty()){
                    current = dfs.top(); dfs.pop();
                    visited[current->dest] = current;
                    if (current->dest == q[1]) {
                        found = current;
                        break;}
                    
                    for(int i = 0; i< graph[current->dest]->size(); ++i){
                        Edge* e = &((*graph[current->dest])[i]);
                        if (visited.find(e->dest) == visited.end()){
                            dfs.push(e);
                        }
                    }
                }

                double res = -1.0;
                if (found != nullptr){
                // navigate the visited hash map to accumulate result
                    res = current->w;
                    while(current->source != q[0]){
                        current = visited[current->source];
                        res *= current->w;
                    }
                }
                eval.push_back(res);

                // cleanup
                visited.clear();
                while(!dfs.empty())
                    dfs.pop();
            }
        }
        return eval;
    }
};

int main (int argc, char *argv[]) {
    std::vector<std::vector<std::string>> equations = {{"a", "b"}, {"b", "c"}};
    std::vector<double> values = {2.0, 3.0};
    std::vector<std::vector<std::string>> queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    for (double d: Solution().calcEquation(equations, values, queries))
        std::cout << d << std::endl;
    return 0;
}
