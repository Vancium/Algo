#include "Engine.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <random>
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
        InitializeContainer();
        Shuffle();
    }

    void Engine::InitializeContainer() {
        mArray.clear();
        for ( int i = 1; i < 1000; i++ ) {
            mArray.push_back( i );
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
                default:
                    break;
            }
        }
    }

    void Engine::Shuffle() {
        auto rd = std::random_device{};
        auto rng = std::default_random_engine{ rd() };
        std::shuffle( std::begin( mArray ), std::end( mArray ), rng );
    }

    void Engine::HandleEvents() {

        if ( KEYS[ SDLK_ESCAPE ] ) {
            mRunning = false;
        }
        if ( KEYS[ SDLK_m ] ) {
            Sort( MERGE_SORT );
        }
        if ( KEYS[ SDLK_i ] ) {
            Sort( INSERTION_SORT );
        }
        if ( KEYS[ SDLK_c ] ) {
            Sort( SHELL_SORT );
        }
        if ( KEYS[ SDLK_q ] ) {
            Sort( QUICK_SORT );
        }
        if ( KEYS[ SDLK_r ] ) {
            InitializeContainer();
            Shuffle();
        }

        if ( KEYS[ SDLK_s ] ) {
            Sort( SELECTION_SORT );
        }
    }

    void Engine::Sort( SortAlgorithm algo ) {

        switch ( algo ) {
            case MERGE_SORT: {
                MergeSort( mArray, 0, mArray.size() - 1, mRenderer );
                break;
            }
            case INSERTION_SORT: {
                InsertionSort( mArray, mRenderer );
                break;
            }
            case SELECTION_SORT: {
                SelectionSort( mArray, mRenderer );
                break;
            }
            case SHELL_SORT: {
                ShellSort( mArray, mRenderer );
                break;
            }
            case QUICK_SORT: {
                QuickSort( mArray, 0, mArray.size() - 1, mRenderer );
            }
            default:
                break;
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
