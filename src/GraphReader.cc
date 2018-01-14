//
// Created by Michał Dziewulski on 13.01.2018.
//

#include "GraphReader.h"

namespace graph {

std::shared_ptr<Graph> GraphReader::Read(std::string filename) {
  // Open file
  file_.open(filename, std::ios::in);

  if (!file_.is_open())
    return false;

  // Read values
  // TODO: Check if input is correct
  size_t size;
  file_ >> size;

  std::shared_ptr<Graph> graph(new Graph(size));

  size_t first, second;

  while (file_ >> first >> second)
    graph->AddEdge(first, second);

  return graph;
}

} // namespace graph