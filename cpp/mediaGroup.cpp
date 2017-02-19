#include "mediaGroup.h"



/**
 * Used to log output.
 * @param c: the string to print. Should not contain newlines
 */
void MediaGroup::println(string c){
	printf("[%s:%d] ", __FILE__, __LINE__);
	cout << c << endl;
}

MediaGroup::MediaGroup() { 
	println("MediaGroup object created");
	mg_name = "Default Group";
	}
	
MediaGroup::MediaGroup(string name){
	println("MediaGroup object created");
	mg_name = name;
}

void MediaGroup::setName(string name){
	mg_name = name;
	}

string MediaGroup::getName() {
	return mg_name;
}

void MediaGroup::printAll(){
	println("Group " + getName() + " { ");
	MediaGroup::iterator it = this->begin();
	for(; it != this->end(); it++){
		printf("[%s:%d] ", __FILE__, __LINE__);
		cout << "- " ;
		(*it)->print(cout);
	}
	println("}");
}

