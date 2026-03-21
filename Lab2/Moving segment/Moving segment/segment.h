#pragma once
#include "geometric_vector.h"
#include<queue>

namespace segment
{
	class Segment	
	{
	public:
		Segment();
		Segment(geometry::GeometricVector start);
		Segment(std::initializer_list<geometry::GeometricVector> init);

		enum class Direction
		{
			UP,
			DOWN,
			LEFT,
			RIGHT
		};

		void move(Direction dir);
		void grow();
		void shrink();

	private:
		std::queue<geometry::GeometricVector> _body;
		void check_size();
	};
}
