#include "ShellSort.hpp"
#include "../Util/Utils.hpp"

namespace Algo {
    void ShellSort( std::vector<unsigned int> &vec, std::shared_ptr<Renderer> renderer ) {
        int len = vec.size();
        int h = 1;
        while ( h < len / 3 ) {
            h = 3 * h + 1;
        }
        while ( h >= 1 ) {
            renderer->Prepare( vec );
            renderer->Update();

            for ( int i = h; i < len; i++ ) {
                for ( int j = i; j >= h && LessThan( vec.at( j ), vec.at( j - h ) ); j -= h ) {
                    Swap( vec, j, j - h );
                }
            }
            h = h / 3;
        }
    }
} // namespace Algo
