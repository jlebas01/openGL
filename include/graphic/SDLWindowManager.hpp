#pragma once

#include <cstdint>
#include <SDL/SDL.h>
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <GL/glew.h>

namespace graphic {

class SDLWindowManager {
public:
    SDLWindowManager(uint32_t width, uint32_t height, const char* title);

    ~SDLWindowManager();

    bool pollEvent(SDL_Event& e);

    [[nodiscard]] bool isKeyPressed(SDLKey key) const;

    // button can SDL_BUTTON_LEFT, SDL_BUTTON_RIGHT and SDL_BUTTON_MIDDLE
    [[nodiscard]] bool isMouseButtonPressed(uint32_t button) const;

    [[nodiscard]] glm::ivec2 getMousePosition() const;

    void swapBuffers();

    // Return the time in seconds
    [[nodiscard]] float getTime() const;
};

}
