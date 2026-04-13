// =============================================================================
// CT17: Graph Representations & Traversals — Demo Driver
// =============================================================================
//
// Builds a small social network graph and demonstrates BFS/DFS traversals.
//
//     Alice --- Bob --- Dave
//       |       |
//     Carol --- Eve
//

#include "Graph.h"
#include <iostream>

int main() {

    // =============================================================================
    // Section 1: Build a Graph
    // =============================================================================
    //
    // ! DISCUSSION: Building the graph edge by edge.
    //   - add_edge creates vertices automatically if they don't exist
    //   - undirected: add_edge("Alice", "Bob") means Alice knows Bob AND Bob knows Alice
    //
    std::cout << "=== Section 1: Build a Graph ===" << std::endl;

    Graph g;
    g.add_edge("Alice", "Bob");
    g.add_edge("Alice", "Carol");
    g.add_edge("Bob", "Dave");
    g.add_edge("Bob", "Eve");
    g.add_edge("Carol", "Eve");

    std::cout << "Vertices: " << g.vertex_count() << std::endl;  // 5
    std::cout << "Edges: " << g.edge_count() << std::endl;        // 5
    std::cout << std::endl;

    std::cout << "Adjacency List:" << std::endl;
    g.print();
    std::cout << std::endl;

    // =============================================================================
    // Section 2: Queries
    // =============================================================================
    //
    // ! DISCUSSION: Edge and vertex lookup.
    //   - has_vertex: O(1) average (hash map lookup)
    //   - has_edge: O(degree) — scan the neighbor list
    //
    std::cout << "=== Section 2: Queries ===" << std::endl;

    std::cout << "has_vertex(Alice): " << (g.has_vertex("Alice") ? "true" : "false") << std::endl;
    std::cout << "has_vertex(Frank): " << (g.has_vertex("Frank") ? "true" : "false") << std::endl;
    std::cout << "has_edge(Alice, Bob): " << (g.has_edge("Alice", "Bob") ? "true" : "false") << std::endl;
    std::cout << "has_edge(Alice, Dave): " << (g.has_edge("Alice", "Dave") ? "true" : "false") << std::endl;

    std::cout << "Alice's neighbors: ";
    for (const auto& n : g.neighbors("Alice")) {
        std::cout << n << " ";
    }
    std::cout << std::endl << std::endl; // NOOO DON'T USE std::endl USE '\n'!!!

    // =============================================================================
    // Section 3: BFS
    // =============================================================================
    //
    // ! DISCUSSION: BFS visits vertices level by level.
    //   - starting from Alice: first Alice (distance 0), then Bob, Carol
    //     (distance 1), then Dave, Eve (distance 2)
    //   - uses a QUEUE — first in, first out
    //
    std::cout << "=== Section 3: BFS from Alice ===" << std::endl;

    auto bfs_result = g.bfs("Alice");
    std::cout << "BFS order: ";
    for (const auto& v : bfs_result) {
        std::cout << v << " ";
    }
    std::cout << std::endl << std::endl;

    // =============================================================================
    // Section 4: DFS
    // =============================================================================
    //
    // ! DISCUSSION: DFS explores one path as deep as possible before backtracking.
    //   - starting from Alice: might visit Alice -> Bob -> Dave -> Eve -> Carol
    //     (or a different order depending on neighbor list order)
    //   - uses a STACK — last in, first out
    //
    std::cout << "=== Section 4: DFS from Alice ===" << std::endl;

    auto dfs_result = g.dfs("Alice");
    std::cout << "DFS order: ";
    for (const auto& v : dfs_result) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    return 0;
}
