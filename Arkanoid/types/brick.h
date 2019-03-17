#pragma once

class Brick : public i2DShape
{
private:
    sf::RectangleShape mShape;
    bool               mDestroyed{ false };

public:
    Brick( float aX, float aY );

public:
    const sf::RectangleShape* const getShape()     const;
    const bool                      getDestroyed() const;
          void                      setDestroyed( bool aIsDestroyed );

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
