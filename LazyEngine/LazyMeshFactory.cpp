#include "pch.h"
#include "LazyMeshFactory.h"
namespace lazy
{
	StaticMesh MeshFactory::GenerateTriangle(float fScale)
	{
		StaticMesh triangle;
		// simple triangle
		triangle.m_VertexBuffer =
		{
			{ -1.0, 0.0, 0.0 },
			{ 0.0,  0.0, 1.0 },
			{ 0.0,  1.0, 0.0 }
		}; 

		if (fScale != 1.0f)
		{
			for (auto it : triangle.m_VertexBuffer)
			{
				it.position = it.position * fScale; 
			}
		}

		triangle.m_IndexBuffer =
		{
			{1,2,3}
		};
		return triangle;
	}
}

