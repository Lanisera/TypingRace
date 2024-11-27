#pragma once

#include "vector/vector2.h"

class Camera
{
public:
	Camera() = default;

	~Camera() = default;

	void set_size(const Vector2& size);

	void set_position(const Vector2& position);

	const Vector2& get_size() const;

	const Vector2& get_position() const;

	void look_at(const Vector2& target);

private:
	Vector2 size;
	Vector2 position;
};
