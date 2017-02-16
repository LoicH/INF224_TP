#pragma once
#include "media.h"

class Photo : public Media{
	private:
		float p_latitude;
		float p_longitude;
		
	public:
		Photo() : Media(){
			//~ cout << "Photo object created from nothing" << endl;
		}
		Photo(const string name, const string pathName) : Media(name, pathName){
			//~ cout << "Photo object " << name << " created from " << pathName << endl ;
		}
		
		virtual ~Photo() {
			//~ cout << "Deleting Photo object ";
			cout << "\"" << m_name << "\"" << endl;
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
