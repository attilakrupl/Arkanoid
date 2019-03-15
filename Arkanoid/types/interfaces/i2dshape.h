#pragma once

class i2DShape
{
public:
    virtual void       update()   = 0;

public:
    virtual float x() const = 0;
    virtual float y() const = 0;

public:
    virtual float top()    const = 0;
    virtual float bottom() const = 0;
    virtual float left()   const = 0;
    virtual float right()  const = 0;
};