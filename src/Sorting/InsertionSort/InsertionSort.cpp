#include "InsertionSort.hpp"

namespace Algo {

    void InsertionSort( std::vector<unsigned int> &arr, std::shared_ptr<Renderer> renderer ) {

        for ( int i = 1; i < arr.size(); i++ ) {
            renderer->Prepare( arr );
            renderer->Update();

            for ( int j = i; j > 0 && arr.at( j - 1 ) > arr.at( j ); j-- ) {

                Swap( arr, j, j - 1 );
            }
        }
    }

    void Swap( std::vector<unsigned int> &arr, int i, int j ) {
        unsigned int temp = arr.at( j );
        arr.at( j ) = arr.at( i );
        arr.at( i ) = temp;
    }
} // namespace Algo
