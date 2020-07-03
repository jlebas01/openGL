//
// Created by jeremie on 02/07/2020.
//



#ifndef OPENGL_CYLINDER_H
#define OPENGL_CYLINDER_H

#include <iostream>
#include <cmath>
#include <utility>
#include <vector>

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/gtx/io.hpp>
#include <glm/gtc/random.hpp>

#include <object/Vertex.hpp>

namespace object {
    class Cylinder {

    private:

        static constexpr GLuint VERTEX_ATTR_POSITION = 0;
        static constexpr GLuint VERTEX_ATTR_NORMAL = 1;
        static constexpr GLuint VERTEX_ATTR_TEXTURE = 2;

        // memeber vars
        float radius{};
        float height{};
        int slices{};                        // # of slices         // # of stacks

        std::vector<Vertex> vertices;
        GLuint vbo = 0;
        GLuint vao = 0;


        // member functions
        void clearBuffer();

    public:

        explicit Cylinder(float baseRadius, float height, int sectors);

        ~Cylinder();

        void set(float _baseRadius, float _height, int _sectors);


        // debug
        void printSelf() const;

        void update();

        void fillBuffer();

        void render() const;

        void buildVertices();
    };
}
#endif
