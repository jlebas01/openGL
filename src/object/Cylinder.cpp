//
// Created by jeremie on 02/07/2020.
//


#include <cmath>
#include <vector>
#include <object/Cylinder.hpp>

namespace object {

    Cylinder::Cylinder(float baseRadius, float height, int sectors) {
        set(baseRadius, height, sectors);
        glGenBuffers(1, &this->vbo);
        glGenVertexArrays(1, &this->vao);
    }

    Cylinder::~Cylinder() {
        glDeleteBuffers(1, &this->vbo);
        glDeleteVertexArrays(1, &this->vao);
    }


    void Cylinder::set(float _baseRadius,float _height, int _sectors) {
        this->radius = _baseRadius;
        this->height = _height;
        this->slices = _sectors;
    }

    void Cylinder::printSelf() const {
        std::cout << "===== Cylinder =====\n"
                  << "        Height: " << height << "\n"
                  << "  Sector Count: " << slices << "\n"
                  << " Vertices size: " << vertices.size() << "\n" << std::endl;

    }

    void Cylinder::clearBuffer() {
        std::vector<Vertex>().swap(vertices);
    }

    void Cylinder::buildVertices() {

        GLfloat x, y, z, t;

        std::vector<Vertex> Top;
        std::vector<Vertex> Bot;
        std::vector<Vertex> CenterTop;
        std::vector<Vertex> CenterBot;
        const auto PI = glm::pi<float>();
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec2 texture;

        GLfloat angular = (2.0f * PI) / static_cast<GLfloat>(slices);


        for (int j = 0; j <= slices; j++) {
            t = 1.0f - (float) j / static_cast<GLfloat>(slices);   // top-to-bottom

            x = glm::cos(angular * static_cast<GLfloat>(j));
            y = glm::sin(angular * static_cast<GLfloat>(j));
            z = -height / 2;

            position = {x * this->radius, y * this->radius, z};
            normal = {x, y, 0.0f};
            texture = {(j / slices), t};
            Top.emplace_back(Vertex(position, normal, texture));

            position = {0.0f, 0.0f, z};
            normal = {0.0f, 0.0f, 0.0f};
            texture = {(j / slices), t};
            CenterTop.emplace_back(Vertex(position, normal, texture));

            z = height / 2;

            position = {x * this->radius, y * this->radius, z};
            normal = {x, y, 0.0f};
            texture = {(j / slices), t};
            Bot.emplace_back(Vertex(position, normal, texture));

            position = {0.0f, 0.0f, z};
            normal = {0.0f, 0.0f, 0.0f};
            texture = {(j / slices), t};
            CenterBot.emplace_back(position, normal, texture);
        }

        for (int j = 0; j < slices; j++) {
            this->vertices.push_back(Top[j]);
            this->vertices.push_back(Top[j + 1]);
            this->vertices.push_back(CenterTop[j]);
            this->vertices.push_back(Bot[j]);
            this->vertices.push_back(Bot[j + 1]);
            this->vertices.push_back(CenterBot[j]);

            this->vertices.push_back(Top[j]);
            this->vertices.push_back(Bot[j]);
            this->vertices.push_back(Bot[j + 1]);

            this->vertices.push_back(Top[j]);
            this->vertices.push_back(Top[j + 1]);
            this->vertices.push_back(Bot[j + 1]);

        }

    }


    void Cylinder::update() {
        clearBuffer();
        buildVertices();
        fillBuffer();
    }

    void Cylinder::fillBuffer() {

        // Set the VBO
        glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * this->vertices.size(), this->vertices.data(), GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        // Set the VAO
        glBindVertexArray(this->vao);
        glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
        glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
        glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);
        glEnableVertexAttribArray(VERTEX_ATTR_TEXTURE);
        glVertexAttribPointer(
                VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                reinterpret_cast<const GLvoid *>(offsetof(Vertex, position))
        );
        glVertexAttribPointer(
                VERTEX_ATTR_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                reinterpret_cast<const GLvoid *>(offsetof(Vertex, normal))
        );
        glVertexAttribPointer(
                VERTEX_ATTR_TEXTURE, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                reinterpret_cast<const GLvoid *>(offsetof(Vertex, texture))
        );
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

    }


    void Cylinder::render() const {
        glBindVertexArray(this->vao);
        glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(this->vertices.size()));
        glBindVertexArray(0);
    }


}