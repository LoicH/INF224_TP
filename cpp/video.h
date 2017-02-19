#pragma once

#include "media.h"

class MediaStorage;

class Video : public Media{
	private:
		
		
		/**
		 * Used to log output.
		 * @param c: the string to print. Should not contain newlines
		 */
		void println(string c) const;
		
		
		// Only MediaStorage can create new Film objects
		friend MediaStorage;
		
	protected:
		
		unsigned int v_length; /*! Length in seconds */
		
		Video();
		Video(const string name, const string pathName);
		Video(const string serialized);
	public:
		
		virtual ~Video();
		
		void setLength(const int length);
		
		void play() const;
		
		string toString() const;
		string serialize() const;
};

typedef shared_ptr<Video> VideoPtr;
