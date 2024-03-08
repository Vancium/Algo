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
#include <numeric>
#include <vector>

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

        mRenderer = std::unique_ptr<Renderer>( new Renderer( mWindow ) );

        mRunning = true;
        GenerateRandomSequence();
    }

    void Engine::GenerateRandomSequence() {

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
                    MergeSort( 0, mArray.size() - 1 );
                    break;
                }
            }
        }
    }

    void Engine::Merge( int left, int mid, int right ) {

        mRenderer->Prepare( mArray );
        mRenderer->Update();
        std::cout << "Merging" << std::endl;
        std::vector<unsigned int> subArrOne;
        std::vector<unsigned int> subArrTwo;

        int subArrOneLength = mid - left + 1;
        int subArrTwoLength = right - mid;

        // Copy data to temp vectors
        for ( int i = 0; i < subArrOneLength; i++ ) {
            subArrOne.emplace_back( i ) = mArray.at( left + i );
        }

        for ( int j = 0; j < subArrTwoLength; j++ ) {
            subArrTwo.emplace_back( j ) = mArray.at( mid + 1 + j );
        }

        int indexOne = 0, indexTwo = 0;
        int mergeIndex = left;

        // Merge temp arrays
        while ( indexOne < subArrOneLength && indexTwo < subArrTwoLength ) {

            if ( subArrOne.at( indexOne ) <= subArrTwo.at( indexTwo ) ) {
                mArray.at( mergeIndex ) = subArrOne.at( indexOne );
                indexOne++;
            } else {
                mArray.at( mergeIndex ) = subArrTwo.at( indexTwo );
                indexTwo++;
            }
            mergeIndex++;
        }

        // Copy remaining elements from right array if any
        while ( indexOne < subArrOneLength ) {
            mArray.at( mergeIndex ) = subArrOne.at( indexOne );
            indexOne++;
            mergeIndex++;
        }

        while ( indexTwo < subArrTwoLength ) {
            mArray.at( mergeIndex ) = subArrTwo.at( indexTwo );
            indexTwo++;
            mergeIndex++;
        }
    }

    void Engine::MergeSort( const int begin, const int end ) {
        if ( begin >= end ) {
            return;
        }

        int mid = begin + ( end - begin ) / 2;
        MergeSort( begin, mid );
        MergeSort( mid + 1, end );
        Merge( begin, mid, end );
    }

    void Engine::Sort( SortAlgorithm algo ) {
        std::cout << "Sorting" << std::endl;

        switch ( algo ) {
            case MERGE_SORT: {
                MergeSort( 0, mArray.size() - 1 );
                break;
            }
        }
    }

    void Engine::Run() {
        while ( mRunning ) {
            PollEvents();
            mRenderer->Prepare( mArray );
            mRenderer->Update();
        }
    }

    Engine::~Engine() {
        SDL_DestroyWindow( mWindow );

        SDL_Quit();
    }
} // namespace Algo
