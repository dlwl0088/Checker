/**
 * @file checker.h
 *
 */

#ifndef CHECKER_H_
#define CHECKER_H_

#include "embedding.h"
#include "common.h"
#include "graph.h"

class Checker {
public:
	Checker();
	~Checker();

	void Check(const Graph& data, const Graph& query,
		const Embedding& embedding);

};

#endif  // CHECKER_H_
