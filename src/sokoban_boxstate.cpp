#include "sokoban_boxstate.h"
#include <iostream>
#include <bitset>
#include <iomanip>

using namespace Sokoban;
using namespace std;

size_t BoxState::box_count;
const ZobristHash<MAX_TILE_COUNT, boxhash_t> BoxState::zhash = {};

boxhash_t BoxState::hash() const {
    boxhash_t result = zhash.hash<>(box_positions, box_count);
    result ^= zhash.hash(player_position);

    /* cout << "BP: "; */
    /* for (size_t i = 0; i < box_count; i++) { */
    /*     cout << setw(2) << box_positions[i] << ' '; */
    /* } */
    /* cout << bitset<64>(result) << endl; */
    return result;
}