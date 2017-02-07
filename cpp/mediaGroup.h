#pragma once
#include "media.h"
#include <list>

class MediaGroup: public list<Media *>
{
	public:
		MediaGroup() { cout << "MediaGroup object created" << endl;}
	
};
