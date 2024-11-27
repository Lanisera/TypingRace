#include "camera/camera.h"
#include "vector/vector2.h"

void Camera::set_size(const Vector2& size)
{
	this->size = size;
}

void Camera::set_position(const Vector2& position)
{
	this->position = position;
}

const Vector2& Camera::get_size() const
{
	return size;
}

const Vector2& Camera::get_position() const
{
	return position;
}

void Camera::look_at(const Vector2& target)
{
	position.x = target.x - size.x / 2;
	position.y = target.y - size.y / 2;
}
