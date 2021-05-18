/**
 * @file embedding.h
 *
 */

#ifndef EMBEDDING_H_
#define EMBEDDING_H_

#include "common.h"

class Embedding {
public:
	explicit Embedding(const std::string& filename);
	~Embedding();

	inline Vertex image(size_t i,Vertex u) const;
	inline size_t Embedding::num() const;

private:
	std::vector<std::vector<Vertex>> embd_;
	size_t n;
};

/**
 * @brief Returns the image of the i th embedding for the input vertex
 *
 * @param i embedding number.
 * @param u query vertex id.
 * @return Vertex
 */
inline Vertex Embedding::image(size_t i,Vertex u) const {
	return embd_[i][u];
}

/**
 * @brief Returns the number of embeddings
 *
 * @return size_t
 */
inline size_t Embedding::num() const { return n; }

#endif  // EMBEDDING_H_
