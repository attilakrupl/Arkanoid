#include "stdafx.h"

bool ShapeHelper::isIntersecting( i2DShape& aShape1, i2DShape& aShape2 )
{
    return aShape1.right()  >= aShape2.left()
        && aShape1.left()   <= aShape2.right()
        && aShape1.bottom() >= aShape2.top()
        && aShape1.top()    <= aShape2.bottom();
}

void ShapeHelper::testCollision( Paddle& aPaddle, Ball& aBall )
{
    if( !isIntersecting( aPaddle, aBall ) )
    {
        return;
    }

    sf::Vector2f lVelocity;

    lVelocity.y = -kBallVelocity;

    if( aBall.x() < aPaddle.x() )
    {
        lVelocity.x = -kBallVelocity;
    }
    else
    {
        lVelocity.x = kBallVelocity;
    }

    aBall.setVelocity( lVelocity );
}