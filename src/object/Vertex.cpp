//
// Created by jlebas01 on 21/03/2020.
//

#include <object/Vertex.hpp>


namespace object {

    Vertex::Vertex(const glm::vec3 &t_position, const glm::vec3 &t_normal, const glm::vec2 &t_texture) :
            position(t_position), normal(t_normal), texture(t_texture) {
    }
}