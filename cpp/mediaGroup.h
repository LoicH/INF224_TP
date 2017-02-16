#pragma once
#include "media.h"
#include <list>

class MediaGroup: public list<MediaPtr>
{
	private:
		string mg_name;
	public:
		MediaGroup() { 
			cout << "MediaGroup object created" << endl;
			mg_name = "Default Group";
			}
			
		MediaGroup(string name){
			cout << "MediaGroup object created" << endl;
			mg_name = name;
		}
		
		void setName(string name){
			mg_name = name;
			}
		
		string getName() {
			return mg_name;
		}
		
		void printAll(){
			cout << "Group " << getName() << " { "<< endl;
			MediaGroup::iterator it = this->begin();
			for(; it != this->end(); it++){
				cout << "- " ;
				(*it)->print(cout);
			}
			cout << "}" << endl;
		}
	
};

typedef shared_ptr<MediaGroup> MediaGrpPtr;

