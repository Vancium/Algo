#include <SDL2/SDL.h>
#include <memory>
#include <string>
#include <vector>
#include "../Renderer/Renderer.hpp"

namespace Algo {

    enum SortAlgorithm {
        MERGE_SORT,
        SELECTION_SORT,
        INSERTION_SORT,
        SHELL_SORT,
        QUICK_SORT
    };

    class Engine {
      public:
        Engine( std::string name, unsigned int height, unsigned int width );
        ~Engine();

        void Run();
        void PollEvents();
        void HandleEvents();

        void Sort( SortAlgorithm algo );

      private:
        void InitializeContainer();
        void Shuffle();
        void GenerateRandomSequence();

        SDL_Window *mWindow;
        bool mRunning;
        Theme mTheme;

        std::vector<unsigned int> mArray;
        unsigned int mWidth;
        unsigned int mHeight;
        std::shared_ptr<Renderer> mRenderer;

        bool KEYS[ 322 ];
    };
} // namespace Algo
