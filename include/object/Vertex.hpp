//
// Created by jlebas01 on 21/03/2020.
//

#ifndef INTERPOLLATION_VERTEX_HPP
#define INTERPOLLATION_VERTEX_HPP

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>



namespace object {

    struct Vertex {
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec2 texture;

        Vertex() = default;

        Vertex(const glm::vec3 &position, const glm::vec3 &normal, const glm::vec2 &texture);
    };
}

#endif //INTERPOLLATION_VERTEX_HPP
