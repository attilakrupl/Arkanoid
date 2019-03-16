#include "stdafx.h"

Brick::Brick( float aX, float aY )
{
    mShape.setPosition ( aX, aY                                );
    mShape.setSize     ( { kBlockWidth, kBlockHeight }         );
    mShape.setFillColor( sf::Color::Yellow                     );
    mShape.setOrigin   ( kBlockWidth / 2.f, kBlockHeight / 2.f );
}

const sf::RectangleShape* const Brick::getShape() const
{
    return &mShape;
}

void Brick::update()
{}

float Brick::x() const
{
    return mShape.getPosition().x;
}

float Brick::y() const
{
    return mShape.getPosition().y;
}

float Brick::left() const
{
    return x() - mShape.getSize().x / 2.f;
}

float Brick::right() const
{
    return x() + mShape.getSize().x / 2.f;
}

float Brick::top() const
{
    return y() - mShape.getSize().y / 2.f;
}

float Brick::bottom() const
{
    return y() + mShape.getSize().y / 2.f;
}