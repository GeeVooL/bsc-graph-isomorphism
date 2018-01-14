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
  bool AddEdge(size_t first_id, size_t second_id);
  bool AreIsomorphic(Graph& other, std::vector<size_t> &ids);
  size_t Size() const;
  size_t GetEdgesCount() const;

 private:
  class Vertex;
  std::vector<std::shared_ptr<Vertex>> vertexes_;
  size_t size_;
  size_t edges_;

  bool CompareDegreeSequences(Graph &other);
  bool CompareVertexes(Graph &other);
  void LoadNewIds(std::vector<size_t> &new_ids);
};

class Graph::Vertex {
 public:
  explicit Vertex(size_t id);
  bool AddNeighbour(std::shared_ptr<Vertex> neighbour);
  bool Compare(const Vertex &other) const;
  size_t GetDegree() const;
  size_t GetId() const;
  void SetId(size_t id_);

 private:
  std::vector<std::shared_ptr<Vertex>> neighbours_;
  size_t degree_;
  size_t id_;
};

} // namespace graph

#endif //GRAPHISOMORPHISM_GRAPH_H
