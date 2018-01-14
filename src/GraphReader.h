//
// Created by Michał Dziewulski on 13.01.2018.
//

#ifndef GRAPHISOMORPHISM_GRAPHREADER_H
#define GRAPHISOMORPHISM_GRAPHREADER_H

#include <fstream>
#include <memory>
#include <string>

#include "Graph.h"

namespace graph {

class GraphReader {
 public:
  GraphReader() = default;
  ~GraphReader() = default;
  bool Read(std::string filename, std::shared_ptr<Graph> &graph);

 private:
  std::fstream file_;
};

} // namespace graph

#endif //GRAPHISOMORPHISM_GRAPHREADER_H
