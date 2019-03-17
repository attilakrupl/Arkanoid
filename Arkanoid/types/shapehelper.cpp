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
    lVelocity.x = ( aPaddle.getVelocity()->x * 2 / 3);

    if( aBall.x() < aPaddle.x() )
    {
        lVelocity.x += -kBallVelocity;
    }
    else
    {
        lVelocity.x += kBallVelocity;
    }

    aBall.setVelocity( lVelocity );
}

void ShapeHelper::testCollision( Brick& aBrick, Ball& aBall )
{
    if( !isIntersecting( aBrick, aBall ) )
    {
        return;
    }

    aBrick.setDestroyed( true );

    float lOverlapLeft  { aBall.right()   - aBrick.left() };
    float lOverlapRight { aBrick.right()  - aBall.left()  };
    float lOverlapTop   { aBall.bottom()  - aBrick.top()  };
    float lOverlapBottom{ aBrick.bottom() - aBall.top()   };

    bool lBallFromLeft( abs( lOverlapLeft ) < abs( lOverlapRight ) );
    bool lBallFromTop( abs( lOverlapTop ) < abs( lOverlapBottom ) );

    float lMinOverlapX{ lBallFromLeft ? lOverlapLeft : lOverlapRight };
    float lMinOverlapY{ lBallFromTop ? lOverlapTop : lOverlapBottom };

    const sf::Vector2f* const lBallVelocity = aBall.getVelocity();
          sf::Vector2f        lNewVelocity{ lBallVelocity->x, lBallVelocity->y };
    if( abs( lMinOverlapX ) < abs( lMinOverlapY ) )
    {
        lNewVelocity.x = lBallFromLeft ? -kBallVelocity : kBallVelocity;
    }
    else
    {
        lNewVelocity.y = lBallFromTop ? -kBallVelocity : kBallVelocity;
    }

    aBall.setVelocity( lNewVelocity );
}
