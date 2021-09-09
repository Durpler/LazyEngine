#ifndef LAZY_STATIC_MESH_H
#define LAZY_STATIC_MESH_H
#include "BaseMesh.h"

namespace lazy
{
	class StaticMesh : public BaseMesh
	{
	public: 
		StaticMesh() = default; 
		~StaticMesh() = default; 

		// TODO: add texture support
	};

}
#endif