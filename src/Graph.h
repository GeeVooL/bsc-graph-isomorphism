//
// Created by Michał Dziewulski on 09.01.2018.
//

#ifndef GRAPHISOMORPHISM_GRAPH_H
#define GRAPHISOMORPHISM_GRAPH_H

#include <memory>
#include <vector>

namespace graph {

class Graph {
 public:
  explicit Graph(size_t size);
  ~Graph() = default;
  void AddEdge(size_t first_id, size_t second_id);
  bool CompareVertexes(Graph &other);
  size_t GetSize() const;

 private:
  class Vertex;
  std::vector<std::shared_ptr<Vertex>> vertexes_;
  size_t size_;
};

class Graph::Vertex {
 public:
  explicit Vertex(size_t id);
  void AddNeighbour(std::shared_ptr<Vertex> neighbour);
  bool Compare(const Vertex &other) const;

 private:
  std::vector<std::shared_ptr<Vertex>> neighbours_;
  size_t degree_;
  size_t id_;
};

} // namespace graph

#endif //GRAPHISOMORPHISM_GRAPH_H
