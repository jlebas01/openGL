#pragma once
#include <math.h>
#include <GL/glew.h>
#include "glm.hpp"

namespace glimac{


class TrackBallCamera{
    private :
        float m_fDistance = 0;
        float m_fAngleX = 0;
        float m_fAngleY = 0;
    public :
    TrackBallCamera(){};
    TrackBallCamera(float dist, float aX, float aY): m_fDistance(dist), m_fAngleX(aX), m_fAngleY(aY){}
    
    void moveFront(float delta){
        m_fDistance = m_fDistance - delta;
    }
    
    void rotateLeft(float degrees){
        m_fAngleX = m_fAngleX + degrees;
    }
    
    void rotateUp(float degrees){
        m_fAngleY = m_fAngleY - degrees;
    }
    
    float radian(float angle) const {
        return angle/180 * M_PI;
    }
    
    void reset(){
        m_fDistance = 0;
        m_fAngleX = 0;
        m_fAngleY = 0;
    }
    
    glm::mat4 getViewMatrix() const {
        
        glm::mat4 viewMatrix = glm::translate(glm::mat4(1.f), glm::vec3(0, 0, -m_fDistance));
        viewMatrix = glm::rotate(viewMatrix, m_fAngleX, glm::vec3(0, 1, 0));
        viewMatrix = glm::rotate(viewMatrix, m_fAngleY, glm::vec3(1, 0, 0));
        return viewMatrix;
    }
    

};
}
