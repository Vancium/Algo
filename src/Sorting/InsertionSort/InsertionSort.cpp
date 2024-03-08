#include "InsertionSort.hpp"

#include "../Util/Utils.hpp"

namespace Algo {

    void InsertionSort( std::vector<unsigned int> &arr, std::shared_ptr<Renderer> renderer ) {

        for ( int i = 1; i < arr.size(); i++ ) {
            renderer->Prepare( arr );
            renderer->Update();

            for ( int j = i; j > 0 && LessThan( arr.at( j ), arr.at( j - 1 ) ); j-- ) {

                Swap( arr, j, j - 1 );
            }
        }
    }

} // namespace Algo
