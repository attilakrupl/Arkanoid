#pragma once

class Paddle : public i2DShape
{
private:
    sf::RectangleShape mShape;
    sf::Vector2f       mVelocity;

public:
    Paddle( float mX, float mY );

public:
    const sf::RectangleShape* const getShape() const;

public:
    virtual void                    update()         override;

public:
    virtual float x() const override;
    virtual float y() const override;

public:
    virtual float top()    const override;
    virtual float bottom() const override;
    virtual float left()   const override;
    virtual float right()  const override;
};