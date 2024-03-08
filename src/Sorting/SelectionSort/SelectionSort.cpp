#include "SelectionSort.hpp"
#include "../Util/Utils.hpp"

namespace Algo {

    void SelectionSort( std::vector<unsigned int> &arr, std::shared_ptr<Renderer> renderer ) {
        for ( int i = 0; i < arr.size(); i++ ) {
            int min = i;

            for ( int j = i + 1; j < arr.size(); j++ ) {
                if ( LessThan( arr.at( j ), arr.at( min ) ) ) {
                    min = j;
                }
                Swap( arr, i, min );

                renderer->Prepare( arr );
                renderer->Update();
            }
        }
    }
} // namespace Algo
