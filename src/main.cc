//
// Created by Michał Dziewulski on 08.01.2018.
//
#include <iostream>

#include "Graph.h"
#include "GraphReader.h"

namespace graph {

bool AreIsomorphic(std::shared_ptr<Graph> first, std::shared_ptr<Graph> second) {
  if (first->GetSize() != second->GetSize())
    return false;

  // TODO: Porownac ciag stopni wierzcholkow

  // TODO: Stworzyc kopie grafu second, permutowac go i porownywac z first

  return false;
}

} // namespace graph

int main(int argc, char *argv[]) {
  using namespace graph;

  if (argc < 3)
    std::cerr << "Error: Missing arguments" << std::endl;

  GraphReader reader;
  std::shared_ptr<Graph> first = reader.Read(argv[1]);
  std::shared_ptr<Graph> second = reader.Read(argv[2]);
}