#include "stdafx.h"

int main( int argc, char** argv )
{
    Ball             lBall  { kWindowWidth / 2, kWindowHeight / 2         };
    Paddle           lPaddle{ kWindowWidth / 2, kWindowHeight - 50        };
    sf::RenderWindow lWindow{ { kWindowWidth, kWindowHeight }, "Arkanoid" };

    lWindow.setFramerateLimit( 30 );

    while( true )
    {
        lWindow.clear( sf::Color::Black );
        if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Escape ) )
        {
            break;
        }

        ShapeHelper::testCollision( lPaddle, lBall );

        lBall.update();
        lPaddle.update();

        lWindow.draw( *lBall.getShape()   );
        lWindow.draw( *lPaddle.getShape() );

        lWindow.display();
    }
    return 0;
}