#ifndef BASE_MESH_H
#define BASE_MESH_H

//lazy
#include "LazyStructs.h"

// std
#include <vector>
namespace lazy
{
	class BaseMesh
	{
	public: 
		BaseMesh(); 
		~BaseMesh(); 

		std::vector<Vertex3D> m_VertexBuffer; 
		std::vector<Index3D> m_IndexBuffer; 
		std::vector<Vertex3D> m_NormalBuffer;
	};
}
#endif
