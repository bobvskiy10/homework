#ifndef __GRAPH_H__
#define __GRAPH_H__
#include <vector>
using Vertex = size_t;


class IGraph {
public:
    virtual ~IGraph()   {};
    virtual void AddEdge(Vertex from, Vertex to) = 0;
    virtual size_t size() const = 0;
    virtual const std::vector<Vertex>& GetAdj(Vertex v) const = 0;
};

class NonOrientationalListGraph : public IGraph {
private:
    std::vector<std::vector<Vertex> > graph;

public:
    NonOrientationalListGraph(size_t vertexCount);
    
    size_t size() const override; 
    
    void AddEdge(Vertex from, Vertex to) override; 
    const std::vector<Vertex>& GetAdj(Vertex v) const override; 
};




class OrientationalMatrixGraph : public IGraph {
private:
    std::vector<std::vector<Vertex> > graph;
    std::vector<Vertex> adges;
public:
    OrientationalMatrixGraph(size_t vertexCount);
    
    size_t size() const override; 
    
    void AddEdge(Vertex from, Vertex to) override; 
    const std::vector<Vertex>& GetAdj(Vertex v) const override; 
};

#endif //__GRAPH_H__    