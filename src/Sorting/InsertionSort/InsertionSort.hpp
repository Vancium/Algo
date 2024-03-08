#pragma once

#include "../../Renderer/Renderer.hpp"
#include <memory>
#include <vector>

namespace Algo {
    void InsertionSort( std::vector<unsigned int> &arr, std::shared_ptr<Renderer> renderer );

    void Swap( std::vector<unsigned int> &arr, int i, int j );
} // namespace Algo
