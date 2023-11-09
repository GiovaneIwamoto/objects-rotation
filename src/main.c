#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "world/window.h"
#include "world/shader.h"
#include "cglm/cglm.h"
#include "cglm/call.h"

int main()
{
  createWindow();
  struct Shader shaderCube = createShader("res/shaders/main.vs", "res/shaders/main.fs");
  struct Shader shaderPyramid = createShader("res/shaders/main.vs", "res/shaders/main.fs");
  struct Shader shaderPrism = createShader("res/shaders/main.vs", "res/shaders/main.fs");

  float vertexCube[] = {
      // CUBE FRONT
      0.3, -0.8, -0.3, 0.01961f, 0.23529f, 0.36863f,
      0.8, -0.8, -0.3, 0.01961f, 0.23529f, 0.36863f,
      0.8, -0.35, -0.3, 0.01961f, 0.23529f, 0.36863f,
      0.3, -0.35, -0.3, 0.01961f, 0.23529f, 0.36863f,

      // CUBE RIGHT
      0.8, -0.8, -0.3, 0.98039f, 0.65098f, 1.00000f,
      0.8, -0.8, -0.8, 0.98039f, 0.65098f, 1.00000f,
      0.8, -0.35, -0.3, 0.98039f, 0.65098f, 1.00000f,
      0.8, -0.35, -0.8, 0.98039f, 0.65098f, 1.00000f,

      // CUBE BACK
      0.3, -0.8, -0.8, 0.63922f, 0.08627f, 0.12941f,
      0.8, -0.8, -0.8, 0.63922f, 0.08627f, 0.12941f,
      0.8, -0.35, -0.8, 0.63922f, 0.08627f, 0.12941f,
      0.3, -0.35, -0.8, 0.63922f, 0.08627f, 0.12941f,

      // CUBE LEFT
      0.3, -0.8, -0.3, 0.43529f, 0.45098f, 0.18431f,
      0.3, -0.8, -0.8, 0.43529f, 0.45098f, 0.18431f,
      0.3, -0.35, -0.3, 0.43529f, 0.45098f, 0.18431f,
      0.3, -0.35, -0.8, 0.43529f, 0.45098f, 0.18431f,

      // CUBE TOP
      0.8, -0.35, -0.3, 0.94510f, 0.82745f, 0.00784f,
      0.8, -0.35, -0.8, 0.94510f, 0.82745f, 0.00784f,
      0.3, -0.35, -0.3, 0.94510f, 0.82745f, 0.00784f,
      0.3, -0.35, -0.8, 0.94510f, 0.82745f, 0.00784f,

      // CUBE BASE
      0.8, -0.8, -0.3, 0.63529f, 0.98039f, 0.63922f,
      0.8, -0.8, -0.8, 0.63529f, 0.98039f, 0.63922f,
      0.3, -0.8, -0.3, 0.63529f, 0.98039f, 0.63922f,
      0.3, -0.8, -0.8, 0.63529f, 0.98039f, 0.63922f, //
  };

  float vertexPyramid[] = {
      // PYRAMID BASE
      -0.8, -0.25, 0.0, 0.59608f, 0.14902f, 0.28627f,
      -0.3, -0.25, 0.0, 0.59608f, 0.14902f, 0.28627f,
      -0.3, -0.25, -0.5, 0.59608f, 0.14902f, 0.28627f,
      -0.8, -0.25, -0.5, 0.59608f, 0.14902f, 0.28627f,

      // PYRAMID FRONT
      -0.8, -0.25, 0.0, 0.48627f, 0.51765f, 0.51373f,
      -0.3, -0.25, 0.0, 0.48627f, 0.51765f, 0.51373f,
      -0.55, 0.25, -0.25, 0.48627f, 0.51765f, 0.51373f,

      // PYRAMID RIGHT
      -0.3, -0.25, 0.0, 1.00000f, 0.64706f, 0.64706f,
      -0.3, -0.25, -0.5, 1.00000f, 0.64706f, 0.64706f,
      -0.55, 0.25, -0.25, 1.00000f, 0.64706f, 0.64706f,

      // PYRAMID BACK
      -0.8, -0.25, -0.5, 0.37647f, 0.69804f, 0.89804f,
      -0.3, -0.25, -0.5, 0.37647f, 0.69804f, 0.89804f,
      -0.55, 0.25, -0.25, 0.37647f, 0.69804f, 0.89804f,

      // PYRAMID LEFT
      -0.8, -0.25, 0.0, 0.96863f, 0.92549f, 0.34902f,
      -0.8, -0.25, -0.5, 0.96863f, 0.92549f, 0.34902f,
      -0.55, 0.25, -0.25, 0.96863f, 0.92549f, 0.34902f, //
  };

  float vertexPrism[] = {
      // HEXAGONAL PRISM BASE
      -0.125, 0.35, -0.125, 1.00000f, 0.51373f, 0.43922f,
      0.125, 0.35, -0.125, 1.00000f, 0.51373f, 0.43922f,
      0.25, 0.35, 0.0, 1.00000f, 0.51373f, 0.43922f,
      0.125, 0.35, 0.125, 1.00000f, 0.51373f, 0.43922f,
      -0.125, 0.35, 0.125, 1.00000f, 0.51373f, 0.43922f,
      -0.25, 0.35, 0.0, 1.00000f, 0.51373f, 0.43922f,

      // HEXAGONAL PRISM TOP
      -0.125, 0.8, -0.125, 0.00000f, 0.69412f, 0.69020f,
      0.125, 0.8, -0.125, 0.00000f, 0.69412f, 0.69020f,
      0.25, 0.8, 0.0, 0.00000f, 0.69412f, 0.69020f,
      0.125, 0.8, 0.125, 0.00000f, 0.69412f, 0.69020f,
      -0.125, 0.8, 0.125, 0.00000f, 0.69412f, 0.69020f,
      -0.25, 0.8, 0.0, 0.00000f, 0.69412f, 0.69020f,

      // HEXAGONAL PRISM FRONT
      -0.125, 0.35, -0.125, 0.30588f, 0.10196f, 0.23922f,
      0.125, 0.35, -0.125, 0.30588f, 0.10196f, 0.23922f,
      -0.125, 0.8, -0.125, 0.30588f, 0.10196f, 0.23922f,
      0.125, 0.8, -0.125, 0.30588f, 0.10196f, 0.23922f,

      // HEXAGONAL PRISM RIGHT FRONT
      0.125, 0.35, -0.125, 0.81176f, 0.93333f, 0.81961f,
      0.25, 0.35, 0.0, 0.81176f, 0.93333f, 0.81961f,
      0.125, 0.8, -0.125, 0.81176f, 0.93333f, 0.81961f,
      0.25, 0.8, 0.0, 0.81176f, 0.93333f, 0.81961f,

      // HEXAGONAL PRISM RIGHT BACK
      0.25, 0.35, 0.0, 1.00000f, 0.15294f, 0.40784f,
      0.125, 0.35, 0.125, 1.00000f, 0.15294f, 0.40784f,
      0.25, 0.8, 0.0, 1.00000f, 0.15294f, 0.40784f,
      0.125, 0.8, 0.125, 1.00000f, 0.15294f, 0.40784f,

      // HEXAGONAL PRISM BACK
      0.125, 0.35, 0.125, 0.01961f, 0.87843f, 0.91373f,
      -0.125, 0.35, 0.125, 0.01961f, 0.87843f, 0.91373f,
      0.125, 0.8, 0.125, 0.01961f, 0.87843f, 0.91373f,
      -0.125, 0.8, 0.125, 0.01961f, 0.87843f, 0.91373f,

      // HEXAGONAL PRISM LEFT BACK
      -0.125, 0.35, 0.125, 0.11373f, 0.77647f, 0.56471f,
      -0.25, 0.35, 0.0, 0.11373f, 0.77647f, 0.56471f,
      -0.125, 0.8, 0.125, 0.11373f, 0.77647f, 0.56471f,
      -0.25, 0.8, 0.0, 0.11373f, 0.77647f, 0.56471f,

      // HEXAGONAL PRISM LEFT FRONT
      -0.25, 0.35, 0.0, 0.89020f, 0.25882f, 0.20392f,
      -0.125, 0.35, -0.125, 0.89020f, 0.25882f, 0.20392f,
      -0.25, 0.8, 0.0, 0.89020f, 0.25882f, 0.20392f,
      -0.125, 0.8, -0.125, 0.89020f, 0.25882f, 0.20392f, //
  };

  unsigned int indexCube[] = {
      0, 1, 2, 2, 3, 0,       // CUBE FRONT
      8, 9, 10, 8, 10, 11,    // CUBE BACK
      12, 13, 14, 13, 14, 15, // CUBE LEFT
      4, 5, 6, 5, 6, 7,       // CUBE RIGHT
      16, 17, 18, 17, 18, 19, // CUBE TOP
      20, 21, 22, 21, 22, 23, // CUBE BASE
  };

  unsigned int indexPyramid[] = {
      (24 - 24), (25 - 24), (26 - 24), (26 - 24), (27 - 24), (24 - 24), // PYRAMID BASE
      (28 - 24), (29 - 24), (30 - 24),                                  // PYRAMID FRONT
      (31 - 24), (32 - 24), (33 - 24),                                  // PYRAMID RIGHT
      (34 - 24), (35 - 24), (36 - 24),                                  // PYRAMID BACK
      (37 - 24), (38 - 24), (39 - 24),                                  // PYRAMID LEFT
  };

  unsigned int indexPrism[] = {
      (40 - 40), (41 - 40), (43 - 40), (40 - 40), (43 - 40), (44 - 40), (41 - 40), (42 - 40), (43 - 40), (40 - 40), (44 - 40), (45 - 40), // HEXAGONAL PRISM BASE
      (46 - 40), (47 - 40), (49 - 40), (46 - 40), (49 - 40), (50 - 40), (47 - 40), (48 - 40), (49 - 40), (46 - 40), (50 - 40), (51 - 40), // HEXAGONAL PRISM TOP
      (52 - 40), (53 - 40), (55 - 40), (52 - 40), (55 - 40), (54 - 40),                                                                   // HEXAGONAL PRISM FRONT
      (56 - 40), (57 - 40), (59 - 40), (56 - 40), (58 - 40), (59 - 40),                                                                   // HEXAGONAL PRISM RIGHT FRONT
      (60 - 40), (61 - 40), (63 - 40), (60 - 40), (62 - 40), (63 - 40),                                                                   // HEXAGONAL PRISM RIGHT BACK
      (64 - 40), (65 - 40), (67 - 40), (64 - 40), (66 - 40), (67 - 40),                                                                   // HEXAGONAL PRISM BACK
      (68 - 40), (69 - 40), (71 - 40), (68 - 40), (70 - 40), (71 - 40),                                                                   // HEXAGONAL PRISM LEFT BACK
      (72 - 40), (73 - 40), (75 - 40), (72 - 40), (74 - 40), (75 - 40),                                                                   // HEXAGONAL PRISM LEFT FRONT
  };

  // CUBE
  unsigned int VBOCube, VAOCube, EBOCube;
  glGenVertexArrays(1, &VAOCube);
  glGenBuffers(1, &VBOCube);
  glGenBuffers(1, &EBOCube);

  glBindVertexArray(VAOCube);

  glBindBuffer(GL_ARRAY_BUFFER, VBOCube);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertexCube), vertexCube, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOCube);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexCube), indexCube, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  // PYRAMID
  unsigned int VBOPyramid, VAOPyramid, EBOPyramid;
  glGenVertexArrays(1, &VAOPyramid);
  glGenBuffers(1, &VBOPyramid);
  glGenBuffers(1, &EBOPyramid);

  glBindVertexArray(VAOPyramid);

  glBindBuffer(GL_ARRAY_BUFFER, VBOPyramid);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPyramid), vertexPyramid, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOPyramid);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexPyramid), indexPyramid, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  // HEXAGONAL PRISM
  unsigned int VBOPrism, VAOPrism, EBOPrism;
  glGenVertexArrays(1, &VAOPrism);
  glGenBuffers(1, &VBOPrism);
  glGenBuffers(1, &EBOPrism);

  glBindVertexArray(VAOPrism);

  glBindBuffer(GL_ARRAY_BUFFER, VBOPrism);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPrism), vertexPrism, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOPrism);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexPrism), indexPrism, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  useShader(shaderCube);
  useShader(shaderPyramid);
  useShader(shaderPrism);

  while (!glfwWindowShouldClose(window.self))
  {
    updateWindow();

    mat4 viewCube = GLM_MAT4_IDENTITY_INIT;
    glm_translate(viewCube, (vec3){0.0f, -0.1f, -2.0f});

    mat4 projectionCube = GLM_MAT4_IDENTITY_INIT;
    glm_perspective(glm_rad(45.0f), 800.0f / 800.0f, 0.1f, 10.0f, projectionCube);

    // Rotation matrix around the Y-axis
    mat4 model = GLM_MAT4_IDENTITY_INIT;
    float angle = 0.25 * glfwGetTime();
    glm_translate(model, (vec3){0.55f, 0.0f, -0.55f});
    glm_rotate(model, angle, (vec3){0.0f, 1.0f, 0.0f});
    glm_translate(model, (vec3){-0.55f, 0.0f, 0.55f});

    // Model matrix to shader
    setShaderMat4(shaderCube, "model", model);
    setShaderMat4(shaderCube, "view", viewCube);
    setShaderMat4(shaderCube, "projection", projectionCube);

    glBindVertexArray(VAOCube);
    glDrawElements(GL_TRIANGLES, (36 + 18), GL_UNSIGNED_INT, 0);

    mat4 viewPyramid = GLM_MAT4_IDENTITY_INIT;
    glm_translate(viewPyramid, (vec3){0.0f, 0.0f, -3.0f});

    mat4 projectionPyramid = GLM_MAT4_IDENTITY_INIT;
    glm_perspective(glm_rad(45.0f), 800.0f / 800.0f, 0.1f, 10.0f, projectionPyramid);

    mat4 model2 = GLM_MAT4_IDENTITY_INIT;
    float angle2 = 0.75 * glfwGetTime();
    glm_translate(model2, (vec3){-0.55f, 0.0f, -0.25f});
    glm_rotate(model2, angle2, (vec3){0.0f, 1.0f, 0.0f});
    glm_translate(model2, (vec3){0.55f, 0.0f, 0.25f});

    // Model matrix to shader
    setShaderMat4(shaderPyramid, "model", model2);
    setShaderMat4(shaderPyramid, "view", viewPyramid);
    setShaderMat4(shaderPyramid, "projection", projectionPyramid);

    glBindVertexArray(VAOPyramid);
    glDrawElements(GL_TRIANGLES, (36 + 18), GL_UNSIGNED_INT, 0);

    mat4 viewPrism = GLM_MAT4_IDENTITY_INIT;
    glm_translate(viewPrism, (vec3){0.0f, 0.0f, -4.0f});

    mat4 projectionPrism = GLM_MAT4_IDENTITY_INIT;
    glm_perspective(glm_rad(45.0f), 800.0f / 800.0f, 0.1f, 10.0f, projectionPrism);

    mat4 model3 = GLM_MAT4_IDENTITY_INIT;
    float angle3 = glfwGetTime();
    glm_rotate(model3, angle3, (vec3){0.0f, 1.0f, 0.0f});

    // Model matrix to shader
    setShaderMat4(shaderPrism, "model", model3);
    setShaderMat4(shaderPrism, "view", viewPrism);
    setShaderMat4(shaderPrism, "projection", projectionPrism);

    glBindVertexArray(VAOPrism);
    glDrawElements(GL_TRIANGLES, (60), GL_UNSIGNED_INT, 0);

    glfwSwapBuffers(window.self);
    glfwPollEvents();
  }

  glDeleteVertexArrays(1, &VAOCube);
  glDeleteBuffers(1, &VBOCube);
  glDeleteBuffers(1, &EBOCube);

  glDeleteVertexArrays(1, &VAOPyramid);
  glDeleteBuffers(1, &VBOPyramid);
  glDeleteBuffers(1, &EBOPyramid);

  glDeleteVertexArrays(1, &VAOPrism);
  glDeleteBuffers(1, &VBOPrism);
  glDeleteBuffers(1, &EBOPrism);

  terminateWindow();

  return 0;
}
