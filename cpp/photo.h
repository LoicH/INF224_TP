#pragma once
#include "media.h"

class Photo : public Media{
	private:
		float p_latitude;
		float p_longitude;
		
		void println(string c){
			printf("[%s:%d] ", __FILE__, __LINE__);
			cout << c << endl;
		}
		
	public:
		Photo() : Media(){
			//~ println("Photo object created from nothing");
		}
		Photo(const string name, const string pathName) : Media(name, pathName){
			//~ println("Photo object " + name + " created from " + pathName) ;
		}
		
		virtual ~Photo() {
			//~ println("Deleting Photo object \"" + m_name + "\"");
		}

		
		void play() const{
			system(("ristretto " + m_path).c_str());
		}
		
		void setLatitude(const float lat) {p_latitude = lat;}
		
		float getLatitude() const {return p_latitude;}
		
		void setLongitude(const float longi) {p_longitude = longi;}
		
		float getLongitude() const {return p_longitude;}
		
};

typedef shared_ptr<Photo> PhotoPtr;
