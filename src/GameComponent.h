#pragma once

class GameComponent {
public:
    virtual ~GameComponent() {}
    virtual void drawFrame(char matrix[20][10]) = 0;
};
