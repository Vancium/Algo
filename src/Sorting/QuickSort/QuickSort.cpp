#include "QuickSort.hpp"
#include "../Util/Utils.hpp"

namespace Algo {
    void QuickSort( std::vector<unsigned int> &vec, int lo, int hi, std::shared_ptr<Renderer> renderer ) {
        if ( hi <= lo )
            return;
        int j = Partition( vec, lo, hi );
        QuickSort( vec, lo, j - 1, renderer );
        QuickSort( vec, j + 1, hi, renderer );
    }
} // namespace Algo
