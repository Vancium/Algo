#pragma once

#include "../../Renderer/Renderer.hpp"

#include <memory>
#include <vector>

namespace Algo {
    void SelectionSort( std::vector<unsigned int> &arr, std::shared_ptr<Renderer> renderer );
}
