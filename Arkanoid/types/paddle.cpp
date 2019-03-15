#include "stdafx.h"

Paddle::Paddle( float mX, float mY )
{
    mShape.setPosition ( mX, mY                                  );
    mShape.setSize     ( { kPaddleWidth, kPaddleHeight }         );
    mShape.setFillColor( sf::Color::Red                          );
    mShape.setOrigin   ( kPaddleWidth / 2.f, kPaddleHeight / 2.f );
}

void Paddle::update()
{
    mShape.move( mVelocity );

    if( ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Left ) )
     && ( left() > 0                                            ) )
    {
        mVelocity.x = -kPaddleVelocity;
    }
    else if( ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Right ) )
          && ( right() < kWindowWidth                                 ) )
    {
        mVelocity.x = kPaddleVelocity;
    }
    else
    {
        mVelocity.x = 0;
    }
}

const sf::RectangleShape* const Paddle::getShape() const
{
    return &mShape;
}

float Paddle::x() const
{
    return mShape.getPosition().x;
}

float Paddle::y() const
{
    return mShape.getPosition().y;
}

float Paddle::left() const
{
    return x() - mShape.getSize().x / 2.f;
}

float Paddle::right() const
{
    return x() + mShape.getSize().x / 2.f;
}

float Paddle::top() const
{
    return y() - mShape.getSize().y / 2.f;
}

float Paddle::bottom() const
{
    return y() + mShape.getSize().y / 2.f;
}