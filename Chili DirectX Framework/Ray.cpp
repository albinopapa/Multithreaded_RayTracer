#include "Ray.h"



Ray::Ray()
{}

Ray::Ray( const Vec3 &Orig, const Vec3 &Dir )
	:
	origin(Orig),
	direction(Dir)
{}


Ray::~Ray()
{}
