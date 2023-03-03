#ifndef ___SPHERE_H
#define ___SPHERE_H

#include <glad/glad.h>
#include <glm/mat4x4.hpp>

#include <vector>

#include "Loader.h"

class Sphere
{
public:
	Sphere();
	Sphere(float rad, GLuint sl, GLuint st);
	~Sphere();

	void setup(float* verts, float* norms, unsigned int* el);
	void draw();
	int getVertexArrayHandle();

	GLuint VAO, VBO_position, VBO_normal, IBO;

private:
	GLuint nVerts, elements;
	float radius;
	GLuint slices, stacks;

	void generateVerts(float *, float *, float *, GLuint *);
};


#endif