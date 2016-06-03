#include "Light.h"



PointLight::PointLight()
{}

PointLight::PointLight( const Vec3 &Pos, const Color &C )
	:
	position(Pos),
	color(C)
{}


PointLight::~PointLight()
{}
