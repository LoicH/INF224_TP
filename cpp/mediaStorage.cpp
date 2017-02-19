#include "mediaStorage.h"
#include <sstream>

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
		throw runtime_error("Error: Object \""+name+"\" already present");
	}
}

void MediaStorage::insertMediaGrp(MediaGrpPtr mg){
	string name = mg->getName();
	if(findMediaGrp(name) == nullptr){
		ms_grpMap[name] = mg;
	}
	else {
		throw runtime_error("Error: Group \""+name+"\" already present");
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
		string err = "Cannot play " + name + ", object not found.";
		println(err);
		throw runtime_error("Error: "+err);
	}
}

void MediaStorage::printMedia(const string name){
	MediaPtr result = findMedia(name);
	if(result != nullptr){
		result->print(cout);
	} else{
		string err = "Cannot print " + name + ", object not found.";
		println(err);
		throw runtime_error("Error: "+err);
	}
}

void MediaStorage::printGroup(const string name){
	MediaGrpPtr result = findMediaGrp(name);
	if(result != nullptr){
		result->printAll();
	} else {
		string err = "Cannot print " + name + ", group not found.";
		println(err);
		throw runtime_error("Error: "+err);
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
	try {
		shared_ptr<Photo> p(new Photo(name, path));
		insertMedia((MediaPtr) p);
		return p;
	} catch(exception const& e) {
		string err = "Cannot create photo \"" + name + "\"" ;
		println(err);
		println(e.what());
		throw runtime_error("Error: "+err);
	}
}

shared_ptr<Video> MediaStorage::newVideo(string name, string path){
	try {
		shared_ptr<Video> p(new Video(name, path));
		insertMedia((MediaPtr) p);
		return p;
	}  catch(exception const& e) {
		string err = "Cannot create video \"" + name + "\"" ;
		println(err);
		println(e.what());
		throw runtime_error("Error: "+err);
	}
}

shared_ptr<Film> MediaStorage::newFilm(string name, string path){
	try {
		shared_ptr<Film> p(new Film(name, path));
		insertMedia((MediaPtr) p);
		return p;
	}  catch(exception const& e) {
		string err = "Cannot create film \"" + name + "\"" ;
		println(err);
		println(e.what());
		throw runtime_error("Error: "+err);
	}
}

MediaGrpPtr MediaStorage::newMediaGrp(string name){
	try {
		MediaGrpPtr p = make_shared<MediaGroup>(name);
		insertMediaGrp(p);
		return p;
	} catch(exception const& e) {
		string err = "Cannot create group \"" + name + "\"" ;
		println(err);
		println(e.what());
		throw runtime_error("Error: "+err);
	}
}	


void MediaStorage::removeMedia(string name){
	MediaPtr result = findMedia(name);
	if (result != nullptr){
		GrpMap::iterator  grpIt;
		for(grpIt = ms_grpMap.begin(); grpIt != ms_grpMap.end(); grpIt++){
			grpIt->second->remove(result);
		}
		ms_mediaMap.erase(name);
		result.reset();
	} else {
		string err = "Error: Cannot remove media \""+name+"\": not found";
		throw runtime_error(err);
	}
}

void MediaStorage::removeGroup(string name){
	MediaGrpPtr result = findMediaGrp(name);
	if (result != nullptr){
		ms_grpMap.erase(name);
		result.reset();
	} else {
		string err = "Error: Cannot remove group \""+name+"\": not found";
		throw runtime_error(err);
	}
}



string MediaStorage::handleRequest(string request){
	stringstream ss;
    ss.str(request);
    string command;
    getline(ss, command, ' ');
    
    string response;
    
    if(command == "print"){
		string name;
		getline(ss, name, ' ');
		//Searching for a media first
		MediaPtr result = findMedia(name);
		if(result != nullptr){
			response = result->toString();
		} else {
			//Then searching for a group
			MediaGrpPtr result = findMediaGrp(name);
			if(result != nullptr){
				response = result->toString();
			}
			else {
				response = "Error: not found";
			}
		}
	}
	else if (command == "play") { 
		string name;
		getline(ss, name, ' ');
		MediaPtr result = findMedia(name);
		if(result != nullptr){
			result->play();
		} else {
			response = "Error: not found";
		}
	}
	else {
		response = "Error: command not recognized";
	}
		
	return response;
}

MediaPtr MediaStorage::fromString(string serialized){
	stringstream ss;
    ss.str(serialized);
    string className;
    getline(ss, className, ',');
    if(className == "Photo"){
		shared_ptr<Photo> p(new Photo(serialized));
		insertMedia((MediaPtr) p);
		return p;
	} else if (className == "Video"){
		shared_ptr<Video> p(new Video(serialized));
		insertMedia((MediaPtr) p);
		return p;
	} else if (className == "Film"){
		shared_ptr<Film> p(new Film(serialized));
		insertMedia((MediaPtr) p);
		return p;
	}
	else {
		string err = "Error: input badly formatted: "+ serialized;
		throw runtime_error(err);
	}
	
}

// Initializing members:
MediaMap MediaStorage::ms_mediaMap = MediaMap();
GrpMap MediaStorage::ms_grpMap = GrpMap();

