#pragma once
#include "media.h"
#include <list>

class MediaGroup: public list<MediaPtr>
{
	private:
		string mg_name;
		
		void println(string c){
			printf("[%s:%d] ", __FILE__, __LINE__);
			cout << c << endl;
		}
		
	public:
		MediaGroup() { 
			println("MediaGroup object created");
			mg_name = "Default Group";
			}
			
		MediaGroup(string name){
			println("MediaGroup object created");
			mg_name = name;
		}
		
		void setName(string name){
			mg_name = name;
			}
		
		string getName() {
			return mg_name;
		}
		
		void printAll(){
			println("Group " + getName() + " { ");
			MediaGroup::iterator it = this->begin();
			for(; it != this->end(); it++){
				printf("[%s:%d] ", __FILE__, __LINE__);
				cout << "- " ;
				(*it)->print(cout);
			}
			println("}");
		}
	
};

typedef shared_ptr<MediaGroup> MediaGrpPtr;

