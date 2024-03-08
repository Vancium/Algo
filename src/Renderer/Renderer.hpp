#pragma once
#include <SDL2/SDL.h>
#include <vector>

namespace Algo {

    struct Theme {
        SDL_Color background;
        SDL_Color bar;
        SDL_Color gridLines;
    };
    class Renderer {
      public:
        Renderer( SDL_Window *window );
        ~Renderer();

        void Prepare( std::vector<unsigned int> &arr );
        void Update();

      private:
        // Rendering Functions
        void RenderBackground();
        void RenderAxes();

        void RenderContainer( std::vector<unsigned int> &vec );

      private:
        SDL_Renderer *mRendererInstance;
        int mWidth;
        int mHeight;

        Theme mTheme;
    };
} // namespace Algo
