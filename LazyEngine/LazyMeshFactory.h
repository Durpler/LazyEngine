#ifndef LAZY_MESH_FACTORY_H
#define LAZY_MESH_FACTORY_H
#include "LazyStaticMesh.h"

namespace lazy
{
	/// <summary>
	/// Mesh factory to create primitives as well as load in certain file formats (glb, gltf2, fbx, obj...)
	/// NOTE: Meshes will be generated triangulated!
	/// </summary>
	class MeshFactory
	{
		static StaticMesh GenerateTriangle(float fScale = 1.0f);
	};
}

#endif 