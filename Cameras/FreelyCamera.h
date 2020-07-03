#pragma once
#include <GL/glew.h>
#include "glm.hpp"
#include <iostream>

# define M_PI 3.14159265358979323846  /* pi */


namespace glimac{


class FreelyCamera{
    private :
    
    glm::vec3 m_Position;
    float m_fPhi;
    float m_fTheta;
    glm::vec3 m_FrontVector;
    glm::vec3 m_LeftVector;
    glm::vec3 m_UpVector ;
    
    public :
    FreelyCamera(float phi = M_PI, float theta = 0, glm::vec3 pos = glm::vec3(0,0,0) ):m_fPhi(phi), m_fTheta(theta), m_Position(pos){
        computeDirectionVectors();
    }
    
    void computeDirectionVectors(){
        m_FrontVector = glm::vec3( (glm::cos(m_fTheta) * glm::sin(m_fPhi)), glm::sin(m_fTheta), glm::cos(m_fTheta) * glm::cos(m_fPhi));
        m_LeftVector = glm::vec3(glm::sin(m_fPhi + (M_PI/2.f)), 0, glm::cos(m_fPhi + (M_PI/2.f)));
        m_UpVector = glm::cross(m_FrontVector, m_LeftVector);
    }
    
    void moveLeft(float t){m_Position += t * m_LeftVector; computeDirectionVectors();}
    void moveFront(float t){m_Position += t * m_FrontVector; computeDirectionVectors();}
    void rotateLeft(float degrees){m_fPhi += radian(degrees); computeDirectionVectors();}
    void rotateUp(float degrees){m_fTheta += radian(degrees); computeDirectionVectors();}
    
    float radian(float angle) const { return (angle * M_PI) /180;}
    
    glm::mat4 getViewMatrix() const {
        glm::mat4 viewMatrix = glm::lookAt(m_Position, m_FrontVector + m_Position, m_UpVector);
        return viewMatrix;
    }
    
};
}
