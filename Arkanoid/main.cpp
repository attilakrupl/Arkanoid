#include <SFML/Window.hpp> 
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

constexpr unsigned int kWindowHeight{ 600  };
constexpr unsigned int kWindowWidth { 800  };
constexpr float        kBallRadius  { 10.f };
constexpr float        kBallVelocity{ 3.f };

struct Ball
{
    CircleShape lShape;
    Vector2f lVelocity{ -kBallVelocity, -kBallVelocity };

    Ball( float mX, float mY )
    {
        lShape.setPosition ( mX, mY                   );
        lShape.setRadius   ( kBallRadius              );
        lShape.setFillColor( Color::Red               );
        lShape.setOrigin   ( kBallRadius, kBallRadius );
    }

    void update()
    {
        lShape.move( lVelocity );
    }
};

int main( int argc, char** argv )
{
    Ball lBall{ kWindowWidth/2, kWindowHeight/2 };

    RenderWindow lWindow{ { kWindowWidth, kWindowHeight }, "Arkanoid" };
    lWindow.setFramerateLimit( 60 );

    while( true )
    {
        lWindow.clear( Color::Black );
        if( Keyboard::isKeyPressed( Keyboard::Key::Escape ) )
        {
            break;
        }

        lBall.update();

        lWindow.draw( lBall.lShape );
        lWindow.display();
    }
    return 0;
}