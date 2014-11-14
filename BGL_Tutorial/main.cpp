#include <iostream>
#include <memory>

#include <boost/graph/adjacency_list.hpp>

using namespace boost;
using namespace std;
int main(int argc, char *argv[])
{
    // Working with C++11
    auto helloLoop = [] () { for (auto i: {1,2,3,4}) cout << "Hello, World\n";};
    helloLoop();

    // Working with Boost Graph Library
    typedef  adjacency_list< vecS,  vecS,  bidirectionalS> Graph;
    enum { A, B, C, D, E };
    const int num_vertices = 5;
    typedef pair<int, int> Edge;
    Edge edge_array[] =
    { Edge(A,B), Edge(A,D), Edge(C,A), Edge(D,C),
      Edge(C,E), Edge(B,D), Edge(D,E) };

    // Creating a graph
    const int num_edges = sizeof(edge_array)/sizeof(edge_array[0]);
    Graph g(num_vertices);
    //Graph g(edge_array, edge_array + num_edges, num_vertices);

    for (int i = 0; i < num_edges; ++i)
       add_edge(edge_array[i].first, edge_array[i].second, g);

    // Accessing the vertex set
    typedef  property_map<Graph,  vertex_index_t>::type IndexMap;
    IndexMap index =  get( vertex_index, g);

    cout << "vertices(g) = ";
    typedef graph_traits<Graph>::vertex_iterator vertex_iter;
    typedef graph_traits<Graph>::vertex_descriptor vertex_desc;
    for_each(vertices(g).first, vertices(g).second, [&] (vertex_desc vertex) { cout << index[vertex] << " ";});
    cout << endl;

    // Accessing the edge set
    cout << "edges(g) = ";
    graph_traits<Graph>::edge_iterator edge_iter, edge_iter_end;
    for (tie(edge_iter, edge_iter_end) = edges(g); edge_iter != edge_iter_end; ++edge_iter)
        cout << "(" << index[source(*edge_iter, g)] << "," << index[target(*edge_iter,g)] << ") ";
    cout << endl;

    // The adjacency structure
    typedef graph_traits<Graph>::edge_descriptor edge_desc;
    for_each(vertices(g).first, vertices(g).second, [&] (vertex_desc vertex) {
        cout << "out-edges: ";
        for_each(out_edges(vertex, g).first, out_edges(vertex,g).second, [&] (edge_desc e) {
            cout << "(" << index[source(e, g)] << "," << index[target(e,g)] << ") ";
        });
        cout << endl << "in-edges: ";
        for_each(in_edges(vertex, g).first, in_edges(vertex,g).second, [&] (edge_desc e) {
            cout << "(" << index[source(e, g)] << "," << index[target(e,g)] << ") ";
        });
        cout << endl;
    });

    // The adjacent vertices
    typedef graph_traits<Graph>::adjacency_iterator adjac_iter, adjac_iter;
    for_each(vertices(g).first, vertices(g).second, [&] (vertex_desc vertex) {
        cout << "adjacent vertices: ";
        for_each(adjacent_vertices(vertex, g).first, adjacent_vertices(vertex,g).second, [&] (vertex_desc e) {
            cout << index[e] << " ";
        });
        cout << endl;
    });

    return 0;

}
