#include "Graph.h"

using NOLG = NonOrientationalListGraph;
using OMG = OrientationalMatrixGraph;

NOLG::NonOrientationalListGraph(size_t vertexCount) : graph(vertexCount) {};

size_t NOLG::size() const {
    return graph.size();
}

void NOLG::AddEdge(Vertex from, Vertex to) {
    graph.at(from).push_back(to);
    graph.at(to).push_back(from);
}

const std::vector<Vertex>& NOLG::GetAdj(Vertex v) const {
    return graph.at(v);
}


//homemade

OMG::OrientationalMatrixGraph(size_t vertexCount) : graph(vertexCount, std::vector<Vertex> (vertexCount, 0)) {};

size_t OMG::size() const {
    return graph.size();
}

void OMG::AddEdge(Vertex from, Vertex to) {
    if (from == to)
        graph.at(from).at(to) = -1;
    else {
        graph.at(from).at(to) = -1;
        graph.at(to).at(from) = 1;
    }
}

const std::vector<Vertex>& OMG::GetAdj(Vertex v) const {
	std::vector<Vertex>* adges = new std::vector<Vertex>;;
	for (Vertex i = 0; i < graph.size(); ++i)
		if (graph.at(v).at(i) == -1)
			adges->push_back(i);
	return *adges;
}

