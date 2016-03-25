//////////////////////////////////////////////////////////////////////////////
//
//  scene.cc
//
//  The source file for scene setup
//
//  Project         : RayChess
//  Name            : Chong Guo
//  Student ID      : 301295753
//  SFU username    : armourg
//  Instructor      : Thomas Shermer
//  TA              : Luwei Yang
//
//  Created by Armour on 3/15/2016
//  Copyright (c) 2016 Armour. All rights reserved.
//
//////////////////////////////////////////////////////////////////////////////

#include "scene.h"

extern raychess::Object *scene;
extern glm::vec3 background_color;
extern glm::vec3 light;
extern glm::vec3 light_ambient;
extern glm::vec3 light_diffuse;
extern glm::vec3 light_specular;
extern glm::vec3 global_ambient;
extern int chessboard_on;
extern float decay_a;
extern float decay_b;
extern float decay_c;

namespace raychess {

//
// Function: SetUpDefaultScene
// ---------------------------
//
//   This function set up the default scene
//
//   Parameters:
//       void
//
//   Returns:
//       void
//

void SetUpDefaultScene(void) {

    // index
    int index = 0;

    // Set background color
    background_color.r = 0.50f;
    background_color.g = 0.05f;
    background_color.b = 0.80f;

    // Set up global ambient color
    global_ambient.r = 0.2f;
    global_ambient.g = 0.2f;
    global_ambient.b = 0.2f;

    // Set up light
    light.x = -2.0f;
    light.y = 5.0f;
    light.z = 1.0f;
    light_ambient.r = 0.1f;
    light_ambient.g = 0.1f;
    light_ambient.b = 0.1f;
    light_diffuse.r = 1.0f;
    light_diffuse.g = 1.0f;
    light_diffuse.b = 1.0f;
    light_specular.r = 1.0f;
    light_specular.g = 1.0f;
    light_specular.b = 1.0f;

    // Set up decay parameters
    decay_a = 0.5f;
    decay_b = 0.3f;
    decay_c = 0.0f;

    // Sphere 1
    glm::vec3 sphere1_center = {1.5f, -0.2f, -3.2f};
    glm::vec3 sphere1_ambient = {0.7f, 0.7f, 0.7f};
    glm::vec3 sphere1_diffuse = {0.1f, 0.5f, 0.8f};
    glm::vec3 sphere1_specular = {1.0f, 1.0f, 1.0f};
    float sphere1_radius = 1.23f;
    float sphere1_shininess = 10;
    float sphere1_reflectance = 0.4f;
    float sphere1_refractance = 0.4f;
    float sphere1_reflect_ratio = 1.52f;
    scene = AddSphere(scene, sphere1_center, sphere1_radius, sphere1_ambient, sphere1_diffuse, sphere1_specular,
                      sphere1_shininess, sphere1_reflectance, sphere1_refractance, sphere1_reflect_ratio, ++index);

    // Sphere 2
    glm::vec3 sphere2_center = {-1.5f, 0.0f, -3.5f};
    glm::vec3 sphere2_ambient = {0.6f, 0.6f, 0.6f};
    glm::vec3 sphere2_diffuse = {1.0f, 0.0f, 0.25f};
    glm::vec3 sphere2_specular = {1.0f, 1.0f, 1.0f};
    float sphere2_radius = 1.5f;
    float sphere2_shininess = 6;
    float sphere2_reflectance = 0.3f;
    float sphere2_refractance = 0.3f;
    float sphere2_reflect_ratio = 1.52f;
    scene = AddSphere(scene, sphere2_center, sphere2_radius, sphere2_ambient, sphere2_diffuse, sphere2_specular,
                      sphere2_shininess, sphere2_reflectance, sphere2_refractance, sphere2_reflect_ratio, ++index);

    // Sphere 3
    glm::vec3 sphere3_center = {-0.35f, 1.75f, -2.25f};
    glm::vec3 sphere3_ambient = {0.2f, 0.2f, 0.2f};
    glm::vec3 sphere3_diffuse = {0.0f, 1.0f, 0.25f};
    glm::vec3 sphere3_specular = {0.0f, 1.0f, 0.0f};
    float sphere3_radius = 0.5f;
    float sphere3_shininess = 30;
    float sphere3_reflectance = 0.3f;
    float sphere3_refractance = 0.3f;
    float sphere3_reflect_ratio = 1.52f;
    scene = AddSphere(scene, sphere3_center, sphere3_radius, sphere3_ambient, sphere3_diffuse, sphere3_specular,
                      sphere3_shininess, sphere3_reflectance, sphere3_refractance, sphere3_reflect_ratio, ++index);

    // Chessboard with many triangles
    if (chessboard_on) {
        glm::vec3 v1, v2, v3, v4;
        float triangle_shininess = 30.0f;
        float triangle_reflectance = 1.0f;
        float triangle_refractance = 0.0f;
        float triangle_reflect_ratio = 1.00f;
        float width = libconsts::kChessBoardGridWidth;
        glm::vec3 offset = libconsts::kChessBoardOffset;
        for (int i = 0; i < libconsts::kChessBoardWidth; i++) {
            for (int j = 0; j < libconsts::kChessBoardHeight; j++) {
                glm::vec3 color = (i + j) % 2 == 0? libconsts::kColorBlack: libconsts::kColorWhite;
                v1 = {i * width + 0.0f, 0.0f, j * width + 0.0f};
                v2 = {i * width + width, 0.0f, j * width + 0.0f};
                v3 = {i * width + 0.0f, 0.0f, j * width + width};
                v4 = {i * width + width, 0.0f, j * width + width};
                scene = AddTriangle(scene, v1 + offset, v3 + offset, v2 + offset, color, color, color, triangle_shininess,
                                    triangle_reflectance, triangle_refractance, triangle_reflect_ratio, ++index);
                scene = AddTriangle(scene, v2 + offset, v3 + offset, v4 + offset, color, color, color, triangle_shininess,
                                    triangle_reflectance, triangle_refractance, triangle_reflect_ratio, ++index);
            }
        }
    }
}

//
// Function: SetUpUserScene
// ---------------------------
//
//   This function set up my own scene
//
//   Parameters:
//       void
//
//   Returns:
//       void
//

void SetUpUserScene(void) {
    //TODO: add my own scene
}

}  // namespace raychess
