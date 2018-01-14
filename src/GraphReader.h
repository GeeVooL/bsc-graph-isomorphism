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
  std::shared_ptr<Graph> Read(std::string filename);

 private:
  std::fstream file_;
};

} // namespace graph

#endif //GRAPHISOMORPHISM_GRAPHREADER_H
