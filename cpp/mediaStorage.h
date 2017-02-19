#pragma once

#include "media.h"
#include "mediaGroup.h"
#include "photo.h"
#include "film.h"
#include "video.h"

#include <map>


typedef map<string, MediaPtr> MediaMap;
typedef map<string, MediaGrpPtr> GrpMap;

class MediaStorage{
	private:
		static MediaMap ms_mediaMap;
		static GrpMap ms_grpMap;
		
		static void println(const string c);		
		static void insertMedia(MediaPtr m);		
		static void insertMediaGrp(MediaGrpPtr mg);
		
	public:		
			
		static MediaPtr findMedia(string srch);		
		static MediaGrpPtr findMediaGrp(string srch);
				
		static void playMedia(const string name);		
		static void printMedia(const string name);		
		static void printGroup(const string name);		
		static void printAllMedia();		
		static void printAllGrp();		
		
		static shared_ptr<Photo> newPhoto(string name, string path);		
		static shared_ptr<Video> newVideo(string name, string path);		
		static shared_ptr<Film>  newFilm (string name, string path);		
		static MediaGrpPtr newMediaGrp(string name);
		
		static void removeMedia(string name);
		static void removeGroup(string name);
		
		static string handleRequest(string request);
		
		static MediaPtr fromString(string serialized);

};

