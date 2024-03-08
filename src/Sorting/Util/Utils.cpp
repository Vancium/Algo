#include "Utils.hpp"

namespace Algo {

    void Swap( std::vector<unsigned int> &arr, int i, int j ) {
        unsigned int temp = arr.at( j );
        arr.at( j ) = arr.at( i );
        arr.at( i ) = temp;
    }
    bool LessThan( int a, int b ) {
        return a < b;
    }

    int Partition( std::vector<unsigned int> &arr, int lo, int hi ) {
        int i = lo;
        int j = hi + 1;
        unsigned int pivot = arr.at( lo );

        while ( true ) {
            while ( LessThan( arr.at( ++i ), pivot ) ) {
                if ( i == hi )
                    break;
            }
            while ( LessThan( pivot, arr.at( --j ) ) ) {
                if ( j == lo )
                    break;
            }
            if ( i >= j )
                break;
            Swap( arr, i, j );
        }
        Swap( arr, lo, j );
        return j;
    }
} // namespace Algo
