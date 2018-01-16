//
// Created by Michał Dziewulski on 09.01.2018.
//

#include "Graph.h"

#include <algorithm>

namespace graph {

// class Graph
// public:
Graph::Graph(size_t size) : size_(size), edges_(0) {
  for (size_t i = 0; i < size; ++i)
    vertexes_.push_back(std::shared_ptr<Vertex>(new Vertex(i)));
}

bool Graph::AddEdge(size_t first_id, size_t second_id) {
  if (first_id >= size_ || second_id >= size_)
    return false;

  // Check validity only once so method won't return false if adding loop edge, i.e. (1, 1)
  if (!vertexes_[first_id]->AddNeighbour(vertexes_[second_id]))
    return false;
  vertexes_[second_id]->AddNeighbour(vertexes_[first_id]);

  ++edges_;
  return true;
}

bool Graph::AreIsomorphic(Graph& other, std::vector<size_t> &ids) {
  // Compare sizes
  if (this->size_ != other.size_)
    return false;

  // Compare edges count
  if (this->edges_ != other.edges_)
    return false;

  // Compare degree sequences
  if (!this->CompareDegreeSequences(other))
    return false;

  // Fill ids vector with initial set {0, 1, 2, ..., size_ - 1}
  for (size_t i = 0; i < size_; ++i) {
    ids.push_back(i);
  }

  // Permute vertexes' ids and do a complex comparison of vertexes and their neighbours
  do {
    other.LoadNewIds(ids);
    if (this->CompareVertexes(other))
      return true;
  } while (std::next_permutation(ids.begin(), ids.end()));

  return true;
}

size_t Graph::Size() const {
  return size_;
}

size_t Graph::GetEdgesCount() const {
  return edges_;
}

// private:
bool Graph::CompareDegreeSequences(Graph &other) {
  std::vector<size_t> org_degrees;
  std::vector<size_t> oth_degrees;

  // We assume they have equal size at this point
  for (size_t i = 0; i < size_; ++i) {
    org_degrees.push_back(this->vertexes_[i]->GetDegree());
    oth_degrees.push_back(other.vertexes_[i]->GetDegree());
  }

  std::sort(org_degrees.begin(), org_degrees.end());
  std::sort(oth_degrees.begin(), oth_degrees.end());

  return org_degrees == oth_degrees;
}

bool Graph::CompareVertexes(Graph &other) {
  // We assume they have equal size at this point
  for (size_t i = 0; i < size_; ++i) {
    size_t valid_id = other.vertexes_[i]->GetId();
    if (!vertexes_[valid_id]->Compare(*other.vertexes_[i]))
      return false;
  }

  return true;
}
void Graph::LoadNewIds(std::vector<size_t> &new_ids) {
  for (size_t i = 0; i < size_; ++i)
    vertexes_[i]->SetId(new_ids[i]);
}

// class Graph::Vertex
Graph::Vertex::Vertex(size_t id) : degree_(0), id_(id) {}

bool Graph::Vertex::AddNeighbour(std::shared_ptr<Graph::Vertex> neighbour) {
  if (std::find(neighbours_.begin(), neighbours_.end(), neighbour) != neighbours_.end())
    return false;

  neighbours_.push_back(neighbour);
  ++degree_;
  return true;
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
size_t Graph::Vertex::GetDegree() const {
  return degree_;
}
size_t Graph::Vertex::GetId() const {
  return id_;
}
void Graph::Vertex::SetId(size_t id_) {
  Vertex::id_ = id_;
}

} // namespace graph