#include "stdafx.h"

int main( int argc, char** argv )
{
    Ball               lBall  { kWindowWidth / 2, kWindowHeight / 2         };
    Paddle             lPaddle{ kWindowWidth / 2, kWindowHeight - 50        };
    std::vector<Brick> lBricks;

    for( unsigned int iX = 0; iX < kCountBlocksX; ++iX )
    {
        for( unsigned int iY = 0; iY < kCountBlocksY; ++iY )
        {
            lBricks.emplace_back( ( iX + 1 ) * ( kBlockWidth + 3  ) + 22,
                                  ( iY + 2 ) * ( kBlockHeight + 3 ) );
        }
    }

    sf::RenderWindow lWindow{ sf::VideoMode{ kWindowWidth, kWindowHeight }, "Arkanoid" };
    lWindow.setFramerateLimit( 30 );
    sf::Event lEvent;

    while( lWindow.isOpen() )
    {
        auto lStart = std::chrono::system_clock::now();

        while( true )
        {
            bool isWindowEvent = lWindow.pollEvent( lEvent );
            if ( isWindowEvent 
              && lEvent.type == sf::Event::Closed )
            {
                lWindow.close();
                break;
            }
            if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Escape ) )
            {
                lWindow.close();
                break;
            }

            lWindow.clear( sf::Color::Black );

            lBall.update();
            lPaddle.update();

            ShapeHelper::testCollision( lPaddle, lBall );
            for( Brick& lBrick : lBricks )
            {
                ShapeHelper::testCollision( lBrick, lBall );
            }

            lBricks.erase( remove_if( begin( lBricks )
                , end( lBricks )
                , []( const Brick& lBrick )
                {
                    const bool lIsBrickDestroyed = lBrick.getDestroyed();
                    return lIsBrickDestroyed;
                } )
                , end( lBricks ) );

            lWindow.draw( *lBall.getShape() );
            lWindow.draw( *lPaddle.getShape() );
            for( Brick& lBrick : lBricks )
            {
                lWindow.draw( *lBrick.getShape() );
            }

            lWindow.display();
        }
        auto lEnd = std::chrono::system_clock::now();
        std::chrono::duration<double> lDiff = lEnd - lStart;
        std::cout << "Time of one iteration: " << lDiff.count() << " s\n";
    }
    return EXIT_SUCCESS;
}