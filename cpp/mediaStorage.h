#pragma once

#include "media.h"
#include <map>

class MediaStorage{
	private:
		typedef map<string, MediaPtr> MediaMap;
		typedef map<string, MediaGrpPtr> GrpMap;
		static MediaMap ms_mediaMap;
		static GrpMap ms_grpMap;
		
	public:
		static void insertMedia(MediaPtr m){
			if(find(m->getName()) != nullptr){
				ms_mediaMap[m->getName()] = m;
			}
			else {
				cout << "Error: object already present" << endl;
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
		
	
};

