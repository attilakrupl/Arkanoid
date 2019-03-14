#include <SFML/Window.hpp> 
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

constexpr unsigned int kWindowHeight  { 600  };
constexpr unsigned int kWindowWidth   { 800  };
constexpr float        kBallRadius    { 10.f };
constexpr float        kBallVelocity  { 8.f  };
constexpr float        kPaddleWidth   { 90.f };
constexpr float        kPaddleHeight  { 20.f };
constexpr float        kPaddleVelocity{ 8.f  };

struct Ball
{
    CircleShape mShape;
    Vector2f lVelocity{ -kBallVelocity, -kBallVelocity };

    Ball( float mX, float mY )
    {
        mShape.setPosition ( mX, mY                   );
        mShape.setRadius   ( kBallRadius              );
        mShape.setFillColor( Color::Red               );
        mShape.setOrigin   ( kBallRadius, kBallRadius );
    }

    void update()
    {
        mShape.move( lVelocity );

        if ( left() < 0 )
        {
            lVelocity.x = kBallVelocity;
        }
        else if ( right() > kWindowWidth )
        {
            lVelocity.x = -kBallVelocity;
        }

        if ( top() < 0 )
        {
            lVelocity.y = kBallVelocity;
        }
        else if ( bottom() > kWindowHeight )
        {
            lVelocity.y = -kBallVelocity;
        }
    }

    float x()
    {
        return mShape.getPosition().x;
    }

    float y()
    {
        return mShape.getPosition().y;
    }

    float left()
    {
        return x() - mShape.getRadius();
    }

    float right()
    {
        return x() + mShape.getRadius();
    }

    float top()
    {
        return y() - mShape.getRadius();
    }

    float bottom()
    {
        return y() + mShape.getRadius();
    }

};

struct Paddle
{
    RectangleShape mShape;
    Vector2f       mVelocity;

    Paddle( float mX, float mY )
    {
        mShape.setPosition ( mX, mY                                  );
        mShape.setSize     ( { kPaddleWidth, kPaddleHeight }         );
        mShape.setFillColor( Color::Red                              );
        mShape.setOrigin   ( kPaddleWidth / 2.f, kPaddleHeight / 2.f );
    }

    void update()
    {
        mShape.move( mVelocity );

        if ( ( Keyboard::isKeyPressed( Keyboard::Key::Left ) )
          && ( left() > 0                                  ) )
        {
            mVelocity.x = -kPaddleVelocity;
        }
        else if ( ( Keyboard::isKeyPressed( Keyboard::Key::Right ) )
               && ( right() < kWindowWidth ) )
        {
            mVelocity.x = kPaddleVelocity;
        }
        else
        {
            mVelocity.x = 0;
        }
    }

    float x()
    {
        return mShape.getPosition().x;
    }

    float y()
    {
        return mShape.getPosition().y;
    }

    float left()
    {
        return x() - mShape.getSize().x / 2.f;
    }

    float right()
    {
        return x() + mShape.getSize().x / 2.f;
    }

    float top()
    {
        return y() - mShape.getSize().y / 2.f;
    }

    float bottom()
    {
        return y() + mShape.getSize().y / 2.f;
    }

};

template<typename T1, typename T2>
bool isIntersecting( T1& aA, T2& aB )
{
    return aA.right()  >= aB.left()
        && aA.left()   <= aB.right()
        && aA.bottom() >= aB.top()
        && aA.top()    <= aB.bottom();
}

void testCollision( Paddle& aPaddle, Ball& aBall )
{
    if ( !isIntersecting( aPaddle, aBall ) )
    {
        return;
    }

    aBall.lVelocity.y = -kBallVelocity;

    if( aBall.x() < aPaddle.x() )
    {
        aBall.lVelocity.x = -kBallVelocity;
    }
    else
    {
        aBall.lVelocity.x = kBallVelocity;
    }
}

int main( int argc, char** argv )
{
    Ball         lBall  { kWindowWidth / 2, kWindowHeight / 2         };
    Paddle       lPaddle{ kWindowWidth / 2, kWindowHeight - 50        };
    RenderWindow lWindow{ { kWindowWidth, kWindowHeight }, "Arkanoid" };

    lWindow.setFramerateLimit( 30 );

    while( true )
    {
        lWindow.clear( Color::Black );
        if( Keyboard::isKeyPressed( Keyboard::Key::Escape ) )
        {
            break;
        }

        lBall.update();
        lPaddle.update();

        lWindow.draw( lBall.mShape   );
        lWindow.draw( lPaddle.mShape );

        lWindow.display();
    }
    return 0;
}