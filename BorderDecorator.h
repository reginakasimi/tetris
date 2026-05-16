#pragma once
#include "GameComponent.h"
#include <memory>


class BorderDecorator : public GameComponent {
private:
    std::unique_ptr<GameComponent> wrappedComponent; 

public:
    BorderDecorator(std::unique_ptr<GameComponent> component);
    void drawFrame(char matrix[20][10]) override;
};
