//
// Created by jlebas01 on 15/01/2020.
//

#include <iostream>
#include <GL/glew.h>
#include <graphic/SDLWindowManager.hpp>
#include <object/Sphere.hpp>
#include <object/Cylinder.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/random.hpp>
#include <glm/gtc/matrix_transform.hpp> //translate, rotate, scale, perspective
#include <glm/gtc/type_ptr.hpp> // value_ptr
#include <unistd.h>
#include <iostream>
#include <tool/Program.hpp>
#include <camera/Camera.hpp>
//#include <glimac/Program.hpp>
//#include <glimac/FilePath.hpp>


int main(int argc, char *argv[]) {

    // Initialize SDL and open a window
    int window_width = 1200;
    int window_height = 1200;
    graphic::SDLWindowManager windowManager(window_width, window_height, "OpenGL");
    // windowManager(width, height, title)

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if (GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    //INITIALIZATION

    /*----------------------SHADER-----------------------*/

    tool::Program program = tool::loadProgram("../shaders/3D.vs.glsl",
                                              "../shaders/normal2.fs.glsl");
    program.use();


    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    object::Cylinder cylinder = object::Cylinder(1.0f, 2.0f, 100);

    /*--------------------Matrix-------------------------*/

    GLint indexMVPMatrix = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
    GLint indexMVMatrix = glGetUniformLocation(program.getGLId(), "uMVMatrix");
    GLint indexNormalMatrix = glGetUniformLocation(program.getGLId(), "uNormalMatrix");

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glShadeModel(GL_SMOOTH);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    glm::mat4 ProjMatrix;
    glm::mat4 MVMatrix;
    glm::mat4 NormalMatrix;
    glm::mat4 MVPMatrix;

    bool done = false;

    sphere.update();
    camera::Camera camera{};
    camera.setProjMatrix(70.0f, window_width, window_height);
    camera.setPosition(0.0f, 0.0f, 5.0f);
    camera.setAngle(0.0f, 0.0f);
    // Application loop:
    while (!done) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // Event loop:
        SDL_Event e;
        while (windowManager.pollEvent(e)) {
            if (windowManager.isKeyPressed(SDLK_UP)) {
                camera.moveForward(0.2f);
            }
            if (windowManager.isKeyPressed(SDLK_DOWN)) {
                camera.moveForward(-0.2f);
            }
            if (windowManager.isKeyPressed(SDLK_LEFT)) {
                camera.moveLeft(0.2f);
            }
            if (windowManager.isKeyPressed(SDLK_RIGHT)) {
                camera.moveLeft(-0.2f);
            }
            if (windowManager.isKeyPressed(SDLK_SPACE)) {
                camera.moveLeft(0.2f);
            }
            if (windowManager.isKeyPressed(SDLK_LCTRL)) {
                camera.moveLeft(-0.2f);
            }
            if (e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
        }

        if (windowManager.isMouseButtonPressed(SDL_BUTTON_LEFT)) {
            glm::ivec2 lastmousePos;
            SDL_GetRelativeMouseState(&lastmousePos.x, &lastmousePos.y);
            camera.rotateLeft(-0.2f * lastmousePos.x);
            camera.rotateUp(-0.2f * lastmousePos.y);
        }


        glDisable(GL_CULL_FACE);

        MVMatrix = camera.getViewMatrix();
        MVPMatrix = camera.getProjMatrix() * MVMatrix;
        NormalMatrix = glm::transpose(glm::inverse(MVMatrix));

        glUniformMatrix4fv(indexMVPMatrix, 1, GL_FALSE, value_ptr(MVPMatrix));
        glUniformMatrix4fv(indexMVMatrix, 1, GL_FALSE, value_ptr(MVMatrix));
        glUniformMatrix4fv(indexNormalMatrix, 1, GL_FALSE, value_ptr(NormalMatrix));

        cylinder.update();
        cylinder.render();

        // Update the display with double buffering
        windowManager.swapBuffers();
    }
    std::exit(EXIT_SUCCESS);
}
