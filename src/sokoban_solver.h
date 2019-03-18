#ifndef SOKOBAN_SOLVER_H
#define SOKOBAN_SOLVER_H

#include <iosfwd>
#include "sokoban_board.h"
#include "sokoban_transposition_table.h"
#include "sokoban_transposition_graph.h"

namespace Sokoban
{

class Solver {
private:
    Solver(const Solver &) = delete;
    Solver(Solver &&) = delete;
    Solver & operator=(const Solver &) = delete;
    Solver & operator=(Solver &&) = delete;

    Board board;
    TranspositionTable ttable;
    TranspositionGraph tgraph;

public:
    Solver() = default;

    bool read_level_data(std::istream & stream);
    bool solve();
    void print_solution(std::ostream & stream) const;
};
}

#endif