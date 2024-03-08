#include "Renderer.hpp"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include <vector>

namespace Algo {
    Renderer::Renderer( SDL_Window *window ) {
        mRendererInstance = SDL_CreateRenderer(
            window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );

        if ( !mRendererInstance ) {
            std::cout << "Could not create SDL Renderer" << std::endl;
            exit( 1 );
        }

        mTheme = { .background = { 22, 22, 22, 255 },
                   .bar = { 255, 255, 255, 255 },
                   .gridLines = { 88, 88, 88, 255 } };

        SDL_GetWindowSize( window, &mWidth, &mHeight );
    }

    Renderer::~Renderer() { SDL_DestroyRenderer( mRendererInstance ); }

    void Renderer::RenderBackground() {
        SDL_SetRenderDrawColor( mRendererInstance, mTheme.background.r,
                                mTheme.background.g, mTheme.background.b,
                                mTheme.background.a );

        SDL_RenderClear( mRendererInstance );
    }

    void Renderer::RenderAxes() {
        SDL_SetRenderDrawColor( mRendererInstance, mTheme.gridLines.r, mTheme.gridLines.g, mTheme.gridLines.b, mTheme.gridLines.a );

        int xOffset, yOffset;

        xOffset = mWidth / 10;
        yOffset = mHeight / 10;

        // Horizonal Axis
        SDL_RenderDrawLine( mRendererInstance, xOffset, mHeight - yOffset,
                            mWidth - xOffset, mHeight - yOffset );

        // Vertical Axis
        SDL_RenderDrawLine( mRendererInstance, xOffset, yOffset, xOffset,
                            mHeight - yOffset );
    }

    void Renderer::RenderContainer( std::vector<unsigned int> &vec ) {

        SDL_SetRenderDrawColor( mRendererInstance, mTheme.bar.r, mTheme.bar.g, mTheme.bar.b, mTheme.bar.a );

        int xOffset = mWidth / 10;
        int yOffset = mHeight / 10;
        int verticalAxisWidth = mWidth - ( xOffset * 2 );

        int spacing = verticalAxisWidth / vec.size();

        for ( int i = 0; i < vec.size(); i++ ) {
            int width = verticalAxisWidth / vec.size();

            if ( vec.size() < 25 )
                width = 10;

            SDL_Rect bar;
            bar.x = xOffset + spacing * i;
            bar.y = mHeight - yOffset - vec.at( i ) * 20;
            bar.w = width;
            bar.h = vec.at( i ) * 20;

            SDL_RenderDrawRect( mRendererInstance, &bar );
        }
    }

    /**
     *  SDL_Rect r = { .x = xOffset + spacing * i,
                               .y = (int)mHeight - yOffset -
                                    (int)arrayToSort.at( i ) * 20,
                               .w = 10,
                               .h = (int)arrayToSort.at( i ) * 20 };
     *
     * **/

    void Renderer::Prepare( std::vector<unsigned int> &arr ) {
        RenderBackground();
        RenderAxes();
        RenderContainer( arr );
    }

    void Renderer::Update() { SDL_RenderPresent( mRendererInstance ); }

} // namespace Algo
