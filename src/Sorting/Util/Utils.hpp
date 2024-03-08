#pragma once
#include <vector>

namespace Algo {

    void Swap( std::vector<unsigned int> &arr, int i, int j );
    bool LessThan( int a, int b );
    int Partition( std::vector<unsigned int> &arr, int lo, int hi );
} // namespace Algo
