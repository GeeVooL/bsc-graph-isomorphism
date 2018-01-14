//
// Created by Michał Dziewulski on 09.01.2018.
//

#include "Graph.h"

namespace graph {

// class Graph
Graph::Graph(size_t size) : size_(size) {
  for (size_t i = 0; i < size; ++i)
    vertexes_.push_back(std::shared_ptr<Vertex>(new Vertex(i)));
}

void Graph::AddEdge(size_t first_id, size_t second_id) {
  vertexes_[first_id]->AddNeighbour(vertexes_[second_id]);
  vertexes_[second_id]->AddNeighbour(vertexes_[first_id]);
}

bool Graph::CompareVertexes(Graph &other) {
  for (size_t i = 0; i < size_; ++i) {
    if (!vertexes_[i]->Compare(*other.vertexes_[i]))
      return false;
  }

  return true;
}

size_t Graph::GetSize() const {
  return size_;
}

// class Graph::Vertex
Graph::Vertex::Vertex(size_t id) : degree_(0), id_(id) {}

void Graph::Vertex::AddNeighbour(std::shared_ptr<Graph::Vertex> neighbour) {
  neighbours_.push_back(neighbour);
  ++degree_;
}

bool Graph::Vertex::Compare(const Graph::Vertex &other) const {
  if (degree_ != other.degree_ ||
      id_ != other.id_)
    return false;

  std::vector<size_t> org_ids;
  for (const std::shared_ptr<Vertex> &ptr : neighbours_)
    org_ids.push_back(ptr->id_);
  std::sort(org_ids.begin(), org_ids.end());

  std::vector<size_t> oth_ids;
  for (const std::shared_ptr<Vertex> &ptr : neighbours_)
    oth_ids.push_back(ptr->id_);
  std::sort(oth_ids.begin(), oth_ids.end());

  return org_ids == oth_ids;
}

} // namespace graph