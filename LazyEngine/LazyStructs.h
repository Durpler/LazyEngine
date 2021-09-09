#ifndef LAZY_STRUCTS_H
#define LAZY_STRUCTS_H
#include <glm/glm.hpp>
// base uncolored 3d vertex struct
struct Vertex3D
{
	glm::vec3 position;
	inline Vertex3D(float px, float py, float pz)
	{
		position.x = px; 
		position.y = py; 
		position.z = pz; 
	}
	
};

// basic 3D Index struct (optional vec3<int>) -> triangulated
struct Index3D
{
	glm::u32vec3 set; 
	inline Index3D(uint32_t px, uint32_t py, uint32_t pz)
	{
		set.x = px; 
		set.y = py; 
		set.z = pz; 
	}
};


#endif
