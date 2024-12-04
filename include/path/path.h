#pragma once

#include "vector/vector2.h"
#include <vector>
class Path
{
public:
	using PointList = std::vector<Vector2>;
public:
	Path(const std::vector<Vector2>& point_list);

	~Path() = default;

	int get_idx_at_progress(double progress) const;

	Vector2 get_position_at_progress(double progress) const;

	const PointList& get_point_list() const;

private:
	PointList point_list;
};
