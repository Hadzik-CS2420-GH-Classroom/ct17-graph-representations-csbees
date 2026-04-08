// =============================================================================
// CT17: Graph Representations & Traversals — Implementation
// =============================================================================
//
// Adjacency list implementation using unordered_map<string, vector<string>>.
// Undirected graph: every edge is stored in both directions.
//

#include "Graph.h"
#include <iostream>
#include <algorithm>

// =============================================================================
// 1. Constructor
// =============================================================================

Graph::Graph() = default;

// =============================================================================
// 2. add_vertex / add_edge
// =============================================================================

// ---------------------------------------------------------------------------
// add_vertex() — add a vertex if it doesn't exist
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: images/cpp_diagrams.md #1 — idempotent insertion with find()/end()
//
// ! DISCUSSION: How add_vertex works.
//   - check if the key already exists in the map
//   - if not, insert it with an empty neighbor list
//   - if it exists, do nothing (safe to call multiple times)
//
void Graph::add_vertex(const std::string& vertex) {
    // TO-DO: insert vertex into adj_list_ if not already present
    if (adj_list_.find(vertex) != adj_list_.end()) return;

    // add
    adj_list_[vertex] = {};
}

// ---------------------------------------------------------------------------
// add_edge() — add an undirected edge between two vertices
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: images/cpp_diagrams.md #2 — undirected edge adds to both lists
//
// ! DISCUSSION: Undirected means both directions.
//   - add_edge("A", "B") adds B to A's neighbor list AND A to B's neighbor list
//   - if either vertex doesn't exist yet, create it first
//   - this is why edge_count needs to divide by 2
//
void Graph::add_edge(const std::string& from, const std::string& to) {
    // TO-DO: ensure both vertices exist, then add each to the other's neighbor list
    add_vertex(from);
    add_vertex(to);

    adj_list_.at(from).push_back(to);
    adj_list_.at(to).push_back(from);

}

// =============================================================================
// 3. Queries
// =============================================================================

bool Graph::has_vertex(const std::string& vertex) const {
    // TO-DO: check if vertex exists as a key in adj_list_
    return (adj_list_.find(vertex) != adj_list_.end());
}

bool Graph::has_edge(const std::string& from, const std::string& to) const {
    // TO-DO: check if 'to' appears in from's neighbor list

    auto it = adj_list_.find(from);
    if (it == adj_list_.end()) return false;

    const auto& nbrs = it->second;
    return std::find(nbrs.begin(), nbrs.end(), to) != nbrs.end();
}

int Graph::vertex_count() const {
    // TO-DO: return number of keys in adj_list_
    return static_cast<int>(adj_list_.size());
}

int Graph::edge_count() const {
    // TO-DO: sum all neighbor list sizes, divide by 2 (undirected)
    int total = 0;
    for (const auto& [v, n] : adj_list_)
    {
        total += static_cast<int>(n.size());
    }
    return total / 2;
}

std::vector<std::string> Graph::neighbors(const std::string& vertex) const {
    // TO-DO: return the neighbor list for vertex (empty vector if not found)
    auto it = adj_list_.find(vertex);
    if (it == adj_list_.end())
        return {};
    return it->second;
}

// =============================================================================
// 4. BFS — Breadth-First Search
// =============================================================================
//
// ? SEE DIAGRAM: images/cpp_diagrams.md #8 — BFS with queue, level by level
//
// ! DISCUSSION: BFS algorithm.
//   - use a QUEUE (FIFO) — process vertices in the order they were discovered
//   - use a VISITED set — prevent revisiting vertices (graphs can have cycles!)
//   - start: enqueue the start vertex, mark it visited
//   - loop: dequeue front, add to result, enqueue all unvisited neighbors
//   - result: vertices in level-order (closest first)
//
// ! DISCUSSION: BFS finds shortest paths in unweighted graphs.
//   - because it visits all vertices at distance 1 before distance 2,
//     distance 2 before distance 3, etc.
//   - this is why BFS is used in GPS navigation (unweighted) and social
//     network "degrees of separation"
//
std::vector<std::string> Graph::bfs(const std::string& start) const {
    std::vector<std::string> result;
    // TODO: implement BFS using a queue and visited set

    std::vector<std::string> r;
    if (!has_vertex(start)) return r;

    std::queue<std::string> q;
    std::unordered_set<std::string> v;

    q.push(start);
    v.insert(start);

    while (!q.empty())
    {
        auto current = q.front(); q.pop();
        q.pop();
        result.push_back(current);
        for (const  std::string& neighbor : neighbors(current))
        {

        } break;
    }

    return result;
}

// =============================================================================
// 5. DFS — Depth-First Search
// =============================================================================
//
// ? SEE DIAGRAM: images/cpp_diagrams.md #9 — DFS with stack, exploring deep first
//
// ! DISCUSSION: DFS algorithm.
//   - use a STACK (LIFO) — always explore the most recently discovered vertex
//   - use a VISITED set — prevent revisiting vertices
//   - start: push the start vertex
//   - loop: pop top, if not visited mark it and push all unvisited neighbors
//   - result: vertices in depth-first order (deep paths first)
//
// ! DISCUSSION: DFS vs BFS — when to use which.
//   - BFS: shortest path, level-order, "how far is X from Y?"
//   - DFS: cycle detection, topological sort, maze solving, "is there a path?"
//   - both visit every reachable vertex exactly once: O(V + E)
//
std::vector<std::string> Graph::dfs(const std::string& start) const {
    std::vector<std::string> result;
    // TODO: implement DFS using a stack and visited set
    return result;
}

// =============================================================================
// 6. print — display adjacency list
// =============================================================================

void Graph::print() const {
    for (const auto& [vertex, neighbors] : adj_list_) {
        std::cout << vertex << ": ";
        for (size_t i = 0; i < neighbors.size(); ++i) {
            if (i > 0) std::cout << ", ";
            std::cout << neighbors[i];
        }
        std::cout << std::endl;
    }
}
