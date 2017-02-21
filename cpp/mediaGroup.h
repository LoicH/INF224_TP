#pragma once
#include "media.h"
#include <list>

/** List of different medias */

class MediaGroup: public list<MediaPtr>
{
	private:
		/** Name of the group */
		string mg_name;
		
		/**
		 * Used to log output.
		 * @param c: the string to print. Should not contain newlines
		 */
		void println(string c) const;
		
	public:
		/** 
		 * Default constructor
		 */
		MediaGroup();
			
		/**
		 * Creates a new group and sets the name.
		 */
		MediaGroup(string name);
		
		/** 
		 * Sets the name of the group
		 */
		void setName(string name);
		
		/** 
		 * Returns the name of the group
		 */
		string getName();
		
		/**
		 * Print all media stored in the group to the standard output
		 */
		void printAll();
		
		/** 
		 * Returns a human-readable representation of the group
		 */
		string toString();
	
};

typedef shared_ptr<MediaGroup> MediaGrpPtr;

