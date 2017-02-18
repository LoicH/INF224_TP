#pragma once
#include "media.h"


class MediaStorage;


class Photo : public Media{
	private:
		float p_latitude;
		float p_longitude;
		
		/**
		 * Used to log output.
		 * @param c: the string to print. Should not contain newlines
		 */
		void println(string c);
		
		
		Photo();
		Photo(const string name, const string pathName);
		
		
		// Only MediaStorage can create new Film objects
		friend MediaStorage;

		
	public:
		~Photo();

		
		void play() const;
		
		void setLatitude(const float lat);
		
		float getLatitude() const;
		
		void setLongitude(const float longi);
		
		float getLongitude() const;
		
};

typedef shared_ptr<Photo> PhotoPtr;
