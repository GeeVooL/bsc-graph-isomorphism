//
// Created by Michał Dziewulski on 13.01.2018.
//

#include "GraphReader.h"

namespace graph {

bool GraphReader::Read(std::string filename, std::shared_ptr<Graph> &graph) {
  // Open file
  file_.open(filename, std::ios::in);

  if (!file_.is_open())
    return false;

  // Read values
  size_t size;
  file_ >> size;

  graph.reset(new Graph(size));

  size_t first, second;

  while (file_ >> first >> second)
    if(!graph->AddEdge(first, second)) {
      graph.reset();
      return false;
    }

  file_.close();
  return true;
}

} // namespace graph