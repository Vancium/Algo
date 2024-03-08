
#include <vector>
#include "../../Renderer/Renderer.hpp"

namespace Algo {
    void MergeSort( std::vector<unsigned int> &arr, const int begin, const int end, std::shared_ptr<Renderer> renderer );
    void Merge( std::vector<unsigned int> &arr, int left, int mid, int right, std::shared_ptr<Renderer> renderer );
} // namespace Algo
