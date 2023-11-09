# OBJECTS ROTATION

### **OVERVIEW**

Selected objects include a cube, pyramid, and hexagonal prism for ease of triangular composition. Positions of each vertex were manually defined and calculated. A vector of indices was used to determine vertices constituting each triangle for object formation. Each object has an exclusive VBO, VAO, and EBO for improved manipulation.

Animation was achieved by rotating the created objects around the Y-axis. GLM was utilized to translate the object to the origin, then rotate it, and finally return it to its original position. A matrix generated through GLM is passed to the vertex shader to execute the rotation.

### **CODE**

Having described the vertices and formed triangles, VBOs, VAOs, and EBOs were created for each scene object. The 3 first values of the coordinate vectors reference object vertices, and the subsequent 3 values represent RGB color values for each vertex.

Following this, shader usage for each object was indicated using the _useShader()_ function from the Replit template. With vertices, colors, triangle formation, and shader usage defined, the loop draws the desired objects on the screen until the window is closed.

Within the loop, each scene object undergoes perspective projection using _glm_translate_ and _glm_perspective_. A rotation matrix is then created for Y-axis animation, involving translation to the origin, Y-axis rotation, and repositioning. These matrices responsible for perspective projection and rotation animation are passed to their respective shaders through _setShaderMat4()_.

To showcase object independence, different rotation speeds were assigned. The cube rotates at ¼ the speed of the prism, and the pyramid rotates at ¾ the speed of the prism.

Distinct rotation matrices were required for each object due to varying rotation speeds. This led to the creation of separate shader instances for each object. Despite having identical code, shaders receive unique matrices for each object.

### **AUTHOR**

- Giovane Hashinokuti Iwamoto - Computer Science student at UFMS - Brazil - MS
- Alexandre Diniz de Souza - Computer Science student at UFMS - Brazil - MS
- Leandro José Gonçalves Pereira - Computer Science student at UFMS - Brazil - MS

I am always open to receiving constructive criticism and suggestions for improvement in my developed code. I believe that feedback is an essential part of the learning and growth process, and I am eager to learn from others and make my code the best it can be. Whether it's a minor tweak or a major overhaul, I am willing to consider all suggestions and implement the changes that will benefit my code and its users.
