#pragma once

class ShapeHelper
{
public:
    static bool isIntersecting( i2DShape& aShape1, i2DShape& aShape2 );
    static void testCollision( Paddle& aPaddle, Ball& aBall );
    static void testCollision( Brick& aBrick, Ball& aBall );

private:
    ShapeHelper() = delete;
};
