//
// Created by Michał Dziewulski on 08.01.2018.
//
#include <iostream>

#include "Graph.h"
#include "GraphReader.h"

int main(int argc, char *argv[]) {
  using namespace graph;

  if (argc < 3) {
    std::cerr << "Error: Missing arguments" << std::endl;
    return -1;
  }

  GraphReader reader;
  std::shared_ptr<Graph> first;
  std::shared_ptr<Graph> second;

  if (!reader.Read(argv[1], first)) {
    std::cerr << "Error: Failed reading first file" << std::endl;
    return -1;
  }
  if (!reader.Read(argv[2], second)) {
    std::cerr << "Error: Failed reading second file" << std::endl;
    return -1;
  }

  std::vector<size_t> ids;
  if (first->AreIsomorphic(*second, ids)) {
    std::cout << "Isomorphic" << std::endl;
    for (size_t i = 0; i < ids.size(); ++i)
      std::cout << i << "->" << ids[i] << std::endl;
  } else {
    std::cout << "Nonisomorphic" << std::endl;
  }

}