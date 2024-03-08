#pragma once

#include "../../Renderer/Renderer.hpp"
#include <memory>
#include <vector>

namespace Algo {
    void InsertionSort( std::vector<unsigned int> &arr, std::shared_ptr<Renderer> renderer );

} // namespace Algo
