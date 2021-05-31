/**
 * @file checker.cc
 *
 */

#include "checker.h"

Checker::Checker() {}
Checker::~Checker() {}

void Checker::Check(const Graph& data, const Graph& query,
	const Embedding& embedding) {
	size_t Nq = query.GetNumVertices();
	bool correct = true;
	Vertex v;
	for (size_t i = 0; i < embedding.num(); i++) {
		for (Vertex u = 0; u < Nq; u++) {
			for (Vertex v = u + 1; v < Nq; v++) {
				//std::cout << i << " " << u << " " << v << "\n";
				//std::cout << embedding.image(i, u) << " " << embedding.image(i, v) << "\n";
				if (embedding.image(i, u) == embedding.image(i, v)) { 
					correct = false; 
					break;
				}

			}
			if (!correct) break;

			v = embedding.image(i, u);
			//std::cout << data.GetLabel(v) << " " << query.GetLabel(u) << "\n";
			if (data.GetLabel(v) != query.GetLabel(u)) {
				correct = false;
				break;
			}

			for (size_t k = query.GetNeighborStartOffset(u); k < query.GetNeighborEndOffset(u); k++) {
				//std::cout << u << " " << query.GetNeighbor(k) << "\n";
				if (!data.IsNeighbor(embedding.image(i, u), embedding.image(i, query.GetNeighbor(k)))) {
					correct = false;
					break;
				}

			}
			if (!correct) break;

		}
		if (!correct) break;
	}

	std::cout << (correct ? "CORRECT" :"INCORRECT") << " "<< embedding.num()<< "\n";
}
