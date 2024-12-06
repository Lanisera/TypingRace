#include "path/path.h"
#include "vector/vector2.h"
#include <cmath>
#include <vector>
#include <iostream>

Path::Path(const std::vector<Vector2>& list)
{
	point_list.push_back(list[0]);

	for (size_t i = 1; i < list.size(); i++)
	{
		int size = std::ceil((list[i] - list[i - 1]).length() / 80);
		Vector2 direction = (list[i] - list[i - 1]).normalize();

		for (int j = 1; j <= size; j++)
			point_list.push_back(list[i - 1] + direction * j * 80);
	}

	// for (auto& temp : point_list)
	//	std::cerr << temp.x << " " << temp.y << std::endl;
}

int Path::get_idx_at_progress(double progress) const
{
	if (progress <= 0) return 0;
	if (progress >= 1) return point_list.size() - 1;

	return (int)std::ceil((double)(progress * (point_list.size() - 1)));
}

Vector2 Path::get_position_at_progress(double progress) const
{
	if (progress <= 0) return point_list.front();
	if (progress >= 1) return point_list.back();

	int idx = get_idx_at_progress(progress);
	double offset = (double)(idx - (double)(progress * (point_list.size() - 1)));
	
	Vector2 direction = (point_list[idx - 1] - point_list[idx]).normalize();
	return point_list[idx] + direction * 80 * offset;
}

const Path::PointList& Path::get_point_list() const 
{
	return point_list;
}
