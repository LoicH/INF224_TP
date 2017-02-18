#pragma once
#include "video.h"
#include <cstring>

class MediaStorage;

class Film : public Video{	
	private:
		/*! The length of each chapter, in seconds */
		unsigned int* f_chapters; 
		
		/*! Number of chapters. I use -1 to know if 
			f_chapters was initialized. */
		int f_length = -1; 
		
		/**
		 * Used to log output.
		 * @param c: the string to print. Should not contain newlines
		 */
		void println(const string c) const;
		
		/** 
		 * Simple constructor
		 */
		Film();
		
		/**
		 * Creates a new object and sets name and path.
		 * @param name: the name of the object. Must be unique.
		 * @param pathName: the path to the object (relative or absolute).
		 */
		Film(const string, const string);
		
		
		// Only MediaStorage can create new Film objects
		friend MediaStorage;
		
	public:
		
		/**
		 * Destroys the object and its members.
		 */
		~Film() ;
		
		/**
		* Sets the length and number of chapters.
		* @param chapters: the length of each chapter in seconds
		* @param length: the number of chapters
		*/
		void setChapters(const unsigned int chapters[], const int length);
		
		/**
		 * Returns the number of chapters and the array of chapters
		 * @param destination a pointer to the destination array
		 * @returns the number of chapters
		 */
		int getChapters(unsigned int * destination) const;
		
		/**
		 * Returns the number of chapters
		 */
		int getNumberChapters() const;
		
		
		/**
		 * Prints each chapter and its length.
		 */
		void printChapters() const;
		
		
		
};


