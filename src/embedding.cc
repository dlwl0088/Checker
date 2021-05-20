/**
 * @file embedding.cc
 *
 */

#include "embedding.h"

Embedding::Embedding(const std::string& filename) {
    std::ifstream fin(filename);

    if (!fin.is_open()) {
        std::cout << "Embedding file " << filename << " not found!\n";
        exit(EXIT_FAILURE);
    }

    char type;
    size_t num_query_vertices;
    size_t i = 0;

    fin >> type >> num_query_vertices;
    embd_.clear();
    while (fin >> type) {
        if (type == 'a') {
            Vertex v;
            embd_.push_back(std::vector<Vertex>(num_query_vertices));
            embd_[i].clear();
            for (Vertex u = 0; u < num_query_vertices; u++) {            
                fin >> v;
                embd_[i].push_back(v);
            }
        i++;
        }
    }

    n = i;

    fin.close();
}

Embedding::~Embedding() {}
