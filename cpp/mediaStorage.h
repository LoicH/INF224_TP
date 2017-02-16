#pragma once

#include "media.h"
#include "mediaGroup.h"
#include "photo.h"
#include "film.h"
#include "video.h"

#include <map>

class MediaStorage{
	private:
		typedef map<string, MediaPtr> MediaMap;
		typedef map<string, MediaGrpPtr> GrpMap;
		static MediaMap ms_mediaMap;
		static GrpMap ms_grpMap;
		
	public:
	
		static void init(){
			MediaMap ms_mediaMap;
			GrpMap ms_grpMap;
		}
		
		static void insertMedia(MediaPtr m){
			string name = m->getName();
			if(find(name) != nullptr){
				ms_mediaMap[name] = m;
			}
			else {
				cout << "Cannot insert media \"" << name << "\":"<< endl;
				cout << "\tError: object already present" << endl;
			}
		}
		
		static MediaPtr find(string srch){
			map<string, MediaPtr>::iterator it = ms_mediaMap.find(srch);
			if(it != ms_mediaMap.end()){
				return it->second;
			}
			else{
				return nullptr;
			}
		}
		
		static void printAll(){
			MediaMap::iterator  it;
			for(it = ms_mediaMap.begin(); it != ms_mediaMap.end(); it++){
				cout << "Object " << it->first << ": ";
				it->second->print(cout);
			}
		}
		
		static PhotoPtr newPhoto(string name, string path){
			MediaPtr result = find(name);
			if (result == nullptr){
				PhotoPtr p = make_shared<Photo>(name, path);
				insertMedia((MediaPtr) p);
				return p;
			} else {
				cout << "Cannot create photo \"" << name << "\"" << endl;
				cout << "\tError: object already present" <<endl;
				cout << "\t";
				result->print(cout);
				return nullptr;
			}
		}
				
		
	
};

