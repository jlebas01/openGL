//
// Created by jlebas01 on 21/03/2020.
//

#ifndef INTERPOLLATION_SPHERE_HPP
#define INTERPOLLATION_SPHERE_HPP


#include <vector>
#include <iostream>
#include <cmath>
#include <utility>

#include <GL/glew.h>
#include <glm/gtc/constants.hpp>

#include <object/Vertex.hpp>




namespace object {

    class Sphere {

    private:
        static constexpr GLuint VERTEX_ATTR_POSITION = 0;
        static constexpr GLuint VERTEX_ATTR_NORMAL = 1;
        static constexpr GLuint VERTEX_ATTR_TEXTURE = 2;

    private:
        const float PI = glm::pi<float>();
        std::vector<Vertex> vertices;
        GLboolean modified;
        GLuint64 longitude;
        GLuint64 latitude;
        GLfloat rayon;
        glm::vec<3, GLfloat> center;
        GLfloat rayonMax;


        GLuint vbo = 0;
        GLuint vao = 0;

        void fillBuffer();


    public:

        Sphere(GLuint64 longitude, GLuint64 latitude, GLfloat rayon = 1.0f, glm::vec3 center ={0.0f, 0.0f, 0.0f}, GLfloat rayorMax = 2.0f);

        ~Sphere();

        void buildVertices();

        [[nodiscard]] const Vertex *data() const;


        [[nodiscard]] GLsizei getVertexCount() const;

        GLuint getVao();

        void update();

        void render() const;

        void dilator(GLfloat scale);

        void setMaxRayor(GLfloat rayorMax);

        bool checkRayor();

        void blade();

        glm::vec3 getCenter();

        void translator(GLfloat x, GLfloat y, GLfloat z);

        void interpolator(Sphere sphere2, GLfloat alpha);


        void getSphere();
    };
}

#endif //INTERPOLLATION_SPHERE_HPP
