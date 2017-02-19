#pragma once
#include "media.h"
#include <list>

class MediaGroup: public list<MediaPtr>
{
	private:
		string mg_name;
		
		/**
		 * Used to log output.
		 * @param c: the string to print. Should not contain newlines
		 */
		void println(string c) const;
		
	public:
		MediaGroup();
			
		MediaGroup(string name);
		
		void setName(string name);
		
		string getName();
		
		void printAll();
		
		string toString();
	
};

typedef shared_ptr<MediaGroup> MediaGrpPtr;

