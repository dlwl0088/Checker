/**
 * @file main.cc
 *
 */

#include "embedding.h"
#include "common.h"
#include "graph.h"
#include "checker.h"


int main(int argc, char* argv[]) {
  if (argc < 4) {
    std::cerr << "Usage: ./program <data graph file> <query graph file> "
                 "<embedding file>\n";
    return EXIT_FAILURE;
  }

  std::string data_file_name = argv[1];
  std::string query_file_name = argv[2];
  std::string embedding_file_name = argv[3];

  Graph data(data_file_name);
  Graph query(query_file_name, true);
  Embedding embedding(embedding_file_name);

  Checker checker;

  checker.Check(data, query, embedding);

  return EXIT_SUCCESS;
}
