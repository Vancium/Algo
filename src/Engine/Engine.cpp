#include "Engine.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <vector>
#include "../Sorting/Sorting.hpp"

namespace Algo {

    Engine::Engine( std::string name, unsigned int width, unsigned int height )
        : mWidth( width ), mHeight( height ) {
        if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) {
            std::cout << "Could not initialize SDL" << std::endl;
        }

        mWindow = SDL_CreateWindow( name.c_str(), SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED, width, height,
                                    SDL_WINDOW_SHOWN );
        if ( !mWindow ) {
            std::cout << "Could not create SDL renderer" << std::endl;
        }

        mRenderer = std::shared_ptr<Renderer>( new Renderer( mWindow ) );

        mRunning = true;
        GenerateRandomSequence();
    }

    void Engine::GenerateRandomSequence() {

        mArray.clear();

        srand( time( nullptr ) );

        for ( int i = 0; i < 1000; i++ ) {

            int j = rand() % 30 + 1;
            mArray.push_back( j );
        }
    }

    void Engine::PollEvents() {
        SDL_Event e;
        while ( SDL_PollEvent( &e ) ) {

            switch ( e.type ) {
                case SDL_QUIT: {
                    mRunning = false;
                    break;
                }
                case SDL_KEYDOWN: {
                    KEYS[ e.key.keysym.sym ] = true;
                    break;
                }
                case SDL_KEYUP: {
                    KEYS[ e.key.keysym.sym ] = false;
                    break;
                }
            }
        }
    }

    void Engine::HandleEvents() {
        if ( KEYS[ SDLK_m ] ) {
            Sort( MERGE_SORT );
        }
        if ( KEYS[ SDLK_i ] ) {
            InsertionSort( mArray, mRenderer );
        }
        if ( KEYS[ SDLK_r ] ) {
            GenerateRandomSequence();
        }
    }

    void Engine::Sort( SortAlgorithm algo ) {

        switch ( algo ) {
            case MERGE_SORT: {
                MergeSort( mArray, 0, mArray.size() - 1, mRenderer );
                break;
            }
        }
    }

    void Engine::Run() {
        while ( mRunning ) {
            PollEvents();

            HandleEvents();
            mRenderer->Prepare( mArray );
            mRenderer->Update();
        }
    }

    Engine::~Engine() {
        SDL_DestroyWindow( mWindow );

        SDL_Quit();
    }
} // namespace Algo
