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
		
		static void println(const string c) {
			printf("[%s:%d] ", __FILE__, __LINE__);
			cout << c << endl;
		}
		
		
		static void insertMedia(MediaPtr m){
			string name = m->getName();
			if(findMedia(name) == nullptr){
				ms_mediaMap[name] = m;
			}
			else {
				println("Cannot insert media \"" + name + "\":");
				println("\tError: object already present" );
			}
		}
		
		static void insertMediaGrp(MediaGrpPtr mg){
			string name = mg->getName();
			if(findMediaGrp(name) == nullptr){
				ms_grpMap[name] = mg;
			}
			else {
				println("Cannot insert group \"" + name + "\":");
				println("\tError: object already present" );
			}
		}
		
		
	public:		
		
		static MediaPtr findMedia(string srch){
			map<string, MediaPtr>::iterator it = ms_mediaMap.find(srch);
			if(it != ms_mediaMap.end()){
				return it->second;
			}
			else{
				return nullptr;
			}
		}
		
		static MediaGrpPtr findMediaGrp(string srch){
			map<string, MediaGrpPtr>::iterator it = ms_grpMap.find(srch);
			if(it != ms_grpMap.end()){
				return it->second;
			}
			else{
				return nullptr;
			}
		}
		
		static void printAllMedia(){
			println("Printing media stored:");
			MediaMap::iterator  it;
			for(it = ms_mediaMap.begin(); it != ms_mediaMap.end(); it++){
				println("Object " + it->first + ": ");
				it->second->print(cout);
			}
		}
		
		static void printAllGrp(){
			println("Printing groups stored:");
			GrpMap::iterator  it;
			for(it = ms_grpMap.begin(); it != ms_grpMap.end(); it++){
				it->second->printAll();
			}
		}
		
		static PhotoPtr newPhoto(string name, string path){
			MediaPtr result = findMedia(name);
			if (result == nullptr){
				PhotoPtr p = make_shared<Photo>(name, path);
				insertMedia((MediaPtr) p);
				return p;
			} else {
				println("Cannot create photo \"" + name + "\"" );
				println("\tError: object already present");
				result->print(cout);
				return nullptr;
			}
		}
		
		static VideoPtr newVideo(string name, string path){
			MediaPtr result = findMedia(name);
			if (result == nullptr){
				VideoPtr p = make_shared<Video>(name, path);
				insertMedia((MediaPtr) p);
				return p;
			} else {
				println("Cannot create video \"" + name + "\"" );
				println("\tError: object already present: ");
				result->print(cout);
				return nullptr;
			}
		}
		
		static FilmPtr newFilm(string name, string path){
			MediaPtr result = findMedia(name);
			if (result == nullptr){
				FilmPtr p = make_shared<Film>(name, path);
				insertMedia((MediaPtr) p);
				return p;
			} else {
				println("Cannot create film \"" + name + "\"" );
				println("\tError: object already present");
				result->print(cout);
				return nullptr;
			}
		}
		
		static MediaGrpPtr newMediaGrp(string name){
			MediaGrpPtr result = findMediaGrp(name);
			if (result == nullptr){
				MediaGrpPtr p = make_shared<MediaGroup>(name);
				insertMediaGrp(p);
				return p;
			} else {
				println("Cannot create media group \"" + name + "\"" );
				println("\tError: object already present");
				return nullptr;
			}
		}		
		
	
};

