#include "mediaGroup.h"



/**
 * Used to log output.
 * @param c: the string to print. Should not contain newlines
 */
void MediaGroup::println(string c) const{
	printf("[%s:%d] ", __FILE__, __LINE__);
	cout << c << endl;
}

MediaGroup::MediaGroup() { 
	mg_name = "Default Group";
	println("Media Group \"" + mg_name + "\" created");
	}
	
MediaGroup::MediaGroup(string name){
	mg_name = name;
	println("Media Group \"" + mg_name + "\" created");
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

string MediaGroup::toString(){
	string response = "Group " + getName() + " { ";
	MediaGroup::iterator it = this->begin();
	for(; it != this->end(); it++){
		response += (*it)->toString() + "|";
	}
	response += "}";
	return response;
}
