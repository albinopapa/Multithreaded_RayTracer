#include "Ray.h"



Ray::Ray()
{}

Ray::Ray( const Vec4 &Orig, const Vec4 &Dir )
	:
	origin(Orig),
	direction(Dir)
{}


Ray::~Ray()
{}
