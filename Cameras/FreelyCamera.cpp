#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "include/Program.hpp"
#include "include/FilePath.hpp"
#include "include/glm.hpp"
#include "include/Image.hpp"
#include "include/Sphere.hpp"
#include "include/FreelyCamera.h"
#include <iostream>
#include <glm/gtc/random.hpp>
#include <vector>
#define M_PI 3.1415926535897932384626433832795
#pragma GL_SILENCE_DEPRECATION

using namespace glimac;
using namespace glm;

#undef main

struct EarthProgram {
    Program m_Program;
    
    GLint uMVPMatrix;
    GLint uMVMatrix;
    GLint uNormalMatrix;
    GLint uTexture;
    GLint uTexture2;
    std::unique_ptr<Image> img_texEarth = loadImage("../../../OpenGL-Proper/assets/textures/EarthMap.jpg");
    std::unique_ptr<Image> img_texCloud = loadImage("../../../OpenGL-Proper/assets/textures/CloudMap.jpg");
    
    EarthProgram():
    m_Program(loadProgram("../../../OpenGL-Proper/shaders/3D.vs.glsl",
    "../../../OpenGL-Proper/shaders/multiTex3D.fs.glsl")) {
        uMVPMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
        uMVMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
        uNormalMatrix = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");
        uTexture = glGetUniformLocation(m_Program.getGLId(), "uTexture");
        uTexture2 = glGetUniformLocation(m_Program.getGLId(), "uTexture2");
    }
};

struct MoonProgram {
    Program m_Program;
    
    GLint uMVPMatrix;
    GLint uMVMatrix;
    GLint uNormalMatrix;
    GLint uTexture;
    std::unique_ptr<Image> img_texMoon = loadImage("../../../OpenGL-Proper/assets/textures/MoonMap.jpg");
    
    MoonProgram():
    m_Program(loadProgram("../../../OpenGL-Proper/shaders/3D.vs.glsl",
    "../../../OpenGL-Proper/shaders/tex3D.fs.glsl")) {
        uMVPMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
        uMVMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
        uNormalMatrix = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");
        uTexture = glGetUniformLocation(m_Program.getGLId(), "uTexture");
    }
};

struct Objects_Context{
    FreelyCamera camera;
};

mat3 translate(float tx, float ty){
    return mat3(vec3(1, 0, 0), vec3(0, 1, 0), vec3(tx, ty, 1));
}

mat3 scale(float sx, float sy){
    return mat3(vec3(sx, 0, 0), vec3(0, sy, 0), vec3(0, 0, 1));
}

mat3 rotate(float a){
    return mat3(vec3(cos(a), -sin(a), 0), vec3(sin(a), cos(a), 0), vec3(0, 0, 1));
}

void bindTexture(GLuint &tex, std::unique_ptr<Image> &img_tex){
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,img_tex -> getWidth(),img_tex -> getHeight(),0,GL_RGBA,GL_FLOAT,img_tex -> getPixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void bindTexture2(GLuint &tex, std::unique_ptr<Image> &img_tex, GLenum texture){
    glActiveTexture(texture);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,img_tex -> getWidth(),img_tex -> getHeight(),0,GL_RGBA,GL_FLOAT,img_tex -> getPixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void test(std::unique_ptr<int> &a){
    std::cout << *a.get() << std::endl;
}

void test2(std::vector<std::unique_ptr<int>> &n){
    std::for_each(n.begin(), n.end(), [](std::unique_ptr<int> &num){std::cout << *num.get() << "\n" ;});
}

void key_callback(GLFWwindow * window, int key, int sancode, int action, int mods){
    //FreelyCamera *camera = static_cast<FreelyCamera>(glfwGetWindowUserPointer(camera));
    std::cout << "callback" << std::endl;
    if(key == GLFW_KEY_Z){
        std::cout << "Z" << std::endl;
    }
}


int main(int argc, char** argv) {
    // Initialize glfw
    if (!glfwInit())
    {
        std::cerr << "Failed in initialization GLFW" << std::endl;
        return -1;
    }
    
    //Hint the GL version to use
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    //Create the window
    const int windowWidth = 600;
    const int windowHeight = 600;
    GLFWwindow* windowManager = glfwCreateWindow(windowWidth, windowHeight, "Earth", NULL, NULL);
    if (!windowManager)
    {
        std::cerr << "Failed in create Windows" << std::endl;
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(windowManager);
    
    // Initialize glew for OpenGL3+ support
    glewExperimental = GL_TRUE;
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }
   
    
    //INITIALIZATION
    Objects_Context objects;
    
    glfwSetWindowUserPointer(windowManager, &objects);
    
    auto window_callback_context = [](GLFWwindow * w, int key, int sancode, int action, int mods){
        Objects_Context* camera_ptr = (Objects_Context*)glfwGetWindowUserPointer(w);
        /*if(action == GLFW_RELEASE){
            camera_ptr -> camera.reset();
            return;
        }*/
        switch(key){
            case 87 : //Z
            {camera_ptr -> camera.moveFront(0.5f);
                break;
            }
            case 83 : //S
            {camera_ptr -> camera.moveFront(-0.5f);
                break;
            }
            case 65 : //Q
            {camera_ptr -> camera.moveLeft(0.5f);
                break;
            }
            case 68 : //D
            {camera_ptr -> camera.moveLeft(-0.5f);
                break;
            }
            case 265 : //pageUp
            {camera_ptr -> camera.rotateUp(5.f);
                break;
            }
            case 264 : //pageDown
            {camera_ptr -> camera.rotateUp(-5.f);
                break;
            }
            case 262 : //pageRight
            {camera_ptr -> camera.rotateLeft(-5.f);
                break;
            }
            case 263 : //pageLeft
            {camera_ptr -> camera.rotateLeft(5.f);
                break;
            }
        }
    };
    
    //glfwSetWindowCloseCallback(windowManager, window_callback_context);
    glfwSetKeyCallback(windowManager, window_callback_context);
    
    Sphere sphere(1,32,16);
    //FreelyCamera camera;
    objects.camera = FreelyCamera();
    EarthProgram earthProgram;
    MoonProgram moonProgram;
    

    //glfwSetKeyCallback(windowManager, key_callback);
    /*----------------------VBO-------------------------*/
    
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    
    glBufferData(GL_ARRAY_BUFFER, sphere.getVertexCount() * sizeof(ShapeVertex), sphere.getDataPointer(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    /*----------------------VAO-------------------------*/
    
    GLuint vao;
    
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    
    const GLuint aVertexPosition = 3;
    const GLuint aVertexNormal = 8;
    const GLuint aVertexTexCoords = 11;
    
    glEnableVertexAttribArray(aVertexPosition);
    glEnableVertexAttribArray(aVertexNormal);
    glEnableVertexAttribArray(aVertexTexCoords);
    
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(aVertexPosition,
                          3, GL_FLOAT, GL_FALSE,
                          sizeof(ShapeVertex), (const GLvoid *) offsetof(ShapeVertex, position));
    
    glVertexAttribPointer(aVertexNormal,
                          3, GL_FLOAT, GL_FALSE,
                          sizeof(ShapeVertex), (const GLvoid *) offsetof(ShapeVertex, normal));
    
    glVertexAttribPointer(aVertexTexCoords,
                          2, GL_FLOAT, GL_FALSE,
                          sizeof(ShapeVertex), (const GLvoid *) offsetof(ShapeVertex, texCoords));
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    
    /*--------------------Matrix-------------------------*/
    
    glEnable(GL_DEPTH_TEST);
    
  
    
    std::vector<vec3> rotations(32);
    for_each(rotations.begin(), rotations.end(), [](vec3 &coords){coords = glm::sphericalRand((float)glfwGetTime());} );
    
    std::vector<vec3> positions(32);
    for_each(positions.begin(), positions.end(), [](vec3 &coords){coords = glm::sphericalRand((float)glfwGetTime()*2.5f);} );
    GLuint tex_names[2];
    glGenTextures(2, tex_names);
    
    
    glm::mat4 ProjMatrix =glm::perspective(glm::radians(70.f), (float)(windowWidth/windowHeight), 0.1f, 100.f);
    glm::mat4 earthMVMatrix;
    
    while (!glfwWindowShouldClose(windowManager)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glfwPollEvents();

        /*-----------------------S1--------------------------*/
        earthProgram.m_Program.use();
        glUniform1i(earthProgram.uTexture, 0);
        glUniform1i(earthProgram.uTexture2, 1);
        
        glm::mat4 viewMatrix = objects.camera.getViewMatrix();
        earthMVMatrix = glm::rotate(viewMatrix, (float)glfwGetTime(), glm::vec3(0, 1, 0));
       
        
        glUniformMatrix4fv(earthProgram.uMVMatrix, 1, GL_FALSE, glm::value_ptr(earthMVMatrix));
        glUniformMatrix4fv(earthProgram.uNormalMatrix, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(earthMVMatrix))));
        glUniformMatrix4fv(earthProgram.uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * earthMVMatrix));
        
        bindTexture2(tex_names[0], earthProgram.img_texEarth, GL_TEXTURE0);
        bindTexture2(tex_names[1], earthProgram.img_texCloud, GL_TEXTURE1);
    
        
        /*-----------------------S1--------------------------*/
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, 0);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, 0);
        glBindVertexArray(0);
        glfwSwapBuffers(windowManager);
    }
    
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
    //glDeleteTextures(1, &texture);
    
    glfwDestroyWindow(windowManager);
    glfwTerminate();
    
    return EXIT_SUCCESS;
}
