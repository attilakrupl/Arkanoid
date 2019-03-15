#include "stdafx.h"

Ball::Ball( float mX, float mY )
{
    mShape.setPosition ( mX, mY                   );
    mShape.setRadius   ( kBallRadius              );
    mShape.setFillColor( sf::Color::Red           );
    mShape.setOrigin   ( kBallRadius, kBallRadius );
}

const sf::Vector2f* const Ball::getVelocity() const
{
    return &mVelocity;
}

void Ball::setVelocity( sf::Vector2f aVelocity )
{
    mVelocity = aVelocity;
}

void Ball::update()
{
    mShape.move( mVelocity );

    if( left() < 0 )
    {
        mVelocity.x = kBallVelocity;
    }
    else if( right() > kWindowWidth )
    {
        mVelocity.x = -kBallVelocity;
    }

    if( top() < 0 )
    {
        mVelocity.y = kBallVelocity;
    }
    else if( bottom() > kWindowHeight )
    {
        mVelocity.y = -kBallVelocity;
    }
}

const sf::CircleShape* const Ball::getShape() const
{
    return &mShape;
}

float Ball::x() const
{
    return mShape.getPosition().x;
}

float Ball::y() const
{
    return mShape.getPosition().y;
}

float Ball::top() const
{
    return y() - mShape.getRadius();
}

float Ball::bottom() const
{
    return y() + mShape.getRadius();
}

float Ball::left() const
{
    return x() - mShape.getRadius();
}

float Ball::right() const
{
    return x() + mShape.getRadius();
}
