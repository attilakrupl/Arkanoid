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

    sf::RenderWindow lWindow{ { kWindowWidth, kWindowHeight }, "Arkanoid" };
    lWindow.setFramerateLimit( 30 );

    while( true )
    {
        lWindow.clear( sf::Color::Black );
        if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Escape ) )
        {
            break;
        }

        lBall.update();
        lPaddle.update();
        ShapeHelper::testCollision( lPaddle, lBall );

        lWindow.draw( *lBall.getShape()   );
        lWindow.draw( *lPaddle.getShape() );
        for( Brick lBrick : lBricks )
        {
            lWindow.draw( *lBrick.getShape() );
        }

        lWindow.display();
    }
    return 0;
}