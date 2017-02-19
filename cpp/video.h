#pragma once

#include "media.h"

class MediaStorage;

class Video : public Media{
	private:
		unsigned int v_length; /*! Length in seconds */
		
		/**
		 * Used to log output.
		 * @param c: the string to print. Should not contain newlines
		 */
		void println(string c);
		
		
		// Only MediaStorage can create new Film objects
		friend MediaStorage;
		
	protected:
		Video();
		Video(const string name, const string pathName);
		
		
		
	public:
		
		virtual ~Video();
		
		void play() const;
		
		string toString() const;
	
};

typedef shared_ptr<Video> VideoPtr;
