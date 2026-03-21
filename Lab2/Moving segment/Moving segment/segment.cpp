#include "segment.h"
#include<stdexcept>
namespace segment
{
	Segment::Segment() = default;

	Segment::Segment(geometry::GeometricVector start)
	{
		_body.emplace(start);
	}

	Segment::Segment(std::initializer_list<geometry::GeometricVector> init)
	{
		_body.emplace(init);
	}

	void Segment::move(Direction dir)
	{
		check_size();
	}

	void Segment::check_size()
	{
		if (_body.size() <= 0)
			throw std::invalid_argument("length must be positive.");
	}
}

