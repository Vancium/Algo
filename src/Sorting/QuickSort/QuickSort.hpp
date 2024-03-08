#pragma once

#include <memory>
#include <vector>
#include "../../Renderer/Renderer.hpp"

namespace Algo {
    void QuickSort( std::vector<unsigned int> &vec, int lo, int hi, std::shared_ptr<Renderer> renderer );
}
