# OpenGL 3D
## Description
Student project of OpenGL, using OpenGL3.
<br/>
<br/>
The goal of the project is to make an avatar with cylinders.
# Dependencies
```SDL
OpenGL3
GLEW 
```
# Build
Needs dependencies to work.
In the root project :
```shell script
cd cmake-build-debug
cmake ..
make
```
# How to run it
In cmake-build-debug
```shell script
./opengl
```
# Notes
Currently, there is only a run as default.
<br/>`yellow sphere` is the cylinder avatar
<br/> If you want change parameter, you could update Main.cpp at these lines :
```C++
/* Set the cylinder 1 */
object::Cylinder cylinder = object::Cylinder(1.0f, 2.0f, 100);
```
# Author
* Jérémie LE BASTARD
