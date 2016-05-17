#include "Light.h"



PointLight::PointLight()
{}

PointLight::PointLight( Vec4 && Pos, Color C )
	:
	position(Pos),
	color(C)
{}


PointLight::~PointLight()
{}
