#include "mediaStorage.h"


/**
 * Used to log output.
 * @param c: the string to print. Should not contain newlines
 */
void MediaStorage::println(const string c){
			printf("[%s:%d] ", __FILE__, __LINE__);
			cout << c << endl;
		}
		

void MediaStorage::insertMedia(MediaPtr m){
	string name = m->getName();
	if(findMedia(name) == nullptr){
		ms_mediaMap[name] = m;
	}
	else {
		println("Cannot insert media \"" + name + "\":");
		println("\tError: object already present" );
	}
}

void MediaStorage::insertMediaGrp(MediaGrpPtr mg){
	string name = mg->getName();
	if(findMediaGrp(name) == nullptr){
		ms_grpMap[name] = mg;
	}
	else {
		println("Cannot insert group \"" + name + "\":");
		println("\tError: object already present" );
	}
}


MediaPtr MediaStorage::findMedia(string srch){
	MediaMap::iterator it = ms_mediaMap.find(srch);
	if(it != ms_mediaMap.end()){
		return it->second;
	}
	else{
		return nullptr;
	}
}

MediaGrpPtr MediaStorage::findMediaGrp(string srch){
	GrpMap::iterator it = ms_grpMap.find(srch);
	if(it != ms_grpMap.end()){
		return it->second;
	}
	else{
		return nullptr;
	}
}

void MediaStorage::playMedia(const string name){
	MediaPtr result = findMedia(name);
	if(result != nullptr){
		result->play();
	} else{
		println("Media object " + name + " not found.");
	}
}

void MediaStorage::printMedia(const string name){
	MediaPtr result = findMedia(name);
	if(result != nullptr){
		result->print(cout);
	} else{
		println("Media object " + name + " not found.");
	}
}

void MediaStorage::printGroup(const string name){
	MediaGrpPtr result = findMediaGrp(name);
	if(result != nullptr){
		result->printAll();
	} else{
		println("Media object " + name + " not found.");
	}
}

void MediaStorage::printAllMedia(){
	println("Printing media stored:");
	MediaMap::iterator  it;
	for(it = ms_mediaMap.begin(); it != ms_mediaMap.end(); it++){
		println("Object " + it->first + ": ");
		it->second->print(cout);
	}
}

void MediaStorage::printAllGrp(){
	println("Printing groups stored:");
	GrpMap::iterator  it;
	for(it = ms_grpMap.begin(); it != ms_grpMap.end(); it++){
		it->second->printAll();
	}
}

shared_ptr<Photo> MediaStorage::newPhoto(string name, string path){
	MediaPtr result = findMedia(name);
	if (result == nullptr){
		shared_ptr<Photo> p(new Photo(name, path));
		insertMedia((MediaPtr) p);
		return p;
	} else {
		println("Cannot create photo \"" + name + "\"" );
		println("\tError: object already present");
		result->print(cout);
		return nullptr;
	}
}

shared_ptr<Video> MediaStorage::newVideo(string name, string path){
	MediaPtr result = findMedia(name);
	if (result == nullptr){
		shared_ptr<Video> p(new Video(name, path));
		insertMedia((MediaPtr) p);
		return p;
	} else {
		println("Cannot create video \"" + name + "\"" );
		println("\tError: object already present: ");
		result->print(cout);
		return nullptr;
	}
}

shared_ptr<Film> MediaStorage::newFilm(string name, string path){
	MediaPtr result = findMedia(name);
	if (result == nullptr){
		shared_ptr<Film> p(new Film(name, path));
		insertMedia((MediaPtr) p);
		return p;
	} else {
		println("Cannot create film \"" + name + "\"" );
		println("\tError: object already present");
		result->print(cout);
		return nullptr;
	}
}

MediaGrpPtr MediaStorage::newMediaGrp(string name){
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


void MediaStorage::removeMedia(string name){
	MediaMap::iterator mediaIt = ms_mediaMap.find(name);
	GrpMap::iterator  grpIt;
	for(grpIt = ms_grpMap.begin(); grpIt != ms_grpMap.end(); grpIt++){
		grpIt->second->remove(mediaIt->second);
	}
	ms_mediaMap.erase(mediaIt);

	
}


// Initializing members:
MediaMap MediaStorage::ms_mediaMap = MediaMap();
GrpMap MediaStorage::ms_grpMap = GrpMap();

