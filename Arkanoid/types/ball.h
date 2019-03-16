#pragma once

class Ball : public i2DShape
{
private:
    sf::CircleShape mShape;
    sf::Vector2f    mVelocity{ -kBallVelocity, -kBallVelocity };

public:
    Ball( float mX, float mY );

public:
    void                         setVelocity( sf::Vector2f aVelocity );
    const sf::Vector2f*    const getVelocity() const;
    const sf::CircleShape* const getShape() const ;

public:
    virtual void update() override;

public:
    virtual float x() const override;
    virtual float y() const override;

public:
    virtual float top()    const override;
    virtual float bottom() const override;
    virtual float left()   const override;
    virtual float right()  const override;
};
