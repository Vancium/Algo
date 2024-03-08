#include "MergeSort.hpp"
#include <vector>
#include <iostream>

namespace Algo {
    void MergeSort( std::vector<unsigned int> &arr, const int begin, const int end, std::shared_ptr<Renderer> renderer ) {
        if ( begin >= end ) {
            return;
        }

        int mid = begin + ( end - begin ) / 2;
        MergeSort( arr, begin, mid, renderer );
        MergeSort( arr, mid + 1, end, renderer );
        Merge( arr, begin, mid, end, renderer );
    }

    void Merge( std::vector<unsigned int> &arr, int left, int mid, int right, std::shared_ptr<Renderer> renderer ) {
        renderer->Prepare( arr );
        renderer->Update();
        std::vector<unsigned int> subArrOne;
        std::vector<unsigned int> subArrTwo;

        int subArrOneLength = mid - left + 1;
        int subArrTwoLength = right - mid;

        // Copy data to temp vectors
        for ( int i = 0; i < subArrOneLength; i++ ) {
            subArrOne.emplace_back( i ) = arr.at( left + i );
        }

        for ( int j = 0; j < subArrTwoLength; j++ ) {
            subArrTwo.emplace_back( j ) = arr.at( mid + 1 + j );
        }

        int indexOne = 0, indexTwo = 0;
        int mergeIndex = left;

        // Merge temp arrays
        while ( indexOne < subArrOneLength && indexTwo < subArrTwoLength ) {

            if ( subArrOne.at( indexOne ) <= subArrTwo.at( indexTwo ) ) {
                arr.at( mergeIndex ) = subArrOne.at( indexOne );
                indexOne++;
            } else {
                arr.at( mergeIndex ) = subArrTwo.at( indexTwo );
                indexTwo++;
            }
            mergeIndex++;
        }

        // Copy remaining elements from right array if any
        while ( indexOne < subArrOneLength ) {
            arr.at( mergeIndex ) = subArrOne.at( indexOne );
            indexOne++;
            mergeIndex++;
        }

        while ( indexTwo < subArrTwoLength ) {
            arr.at( mergeIndex ) = subArrTwo.at( indexTwo );
            indexTwo++;
            mergeIndex++;
        }
    }
} // namespace Algo
