#pragma once

#include "media.h"
#include "mediaGroup.h"
#include "photo.h"
#include "film.h"
#include "video.h"

#include <map>

/** Class handling the media creation */

typedef map<string, MediaPtr> MediaMap;
typedef map<string, MediaGrpPtr> GrpMap;

class MediaStorage{
	private:
		/** The hashtable <name, object> for media objects */
		static MediaMap ms_mediaMap;
		/** The hashtable <name, object> for groups of medias */
		static GrpMap ms_grpMap;
		
		/** Logs into the standard output */
		static void println(const string c);
		
		/** 
		 * Inserts a media object into the hash table
		 * @throws runtime_error If there is already an object
		 * with the same name.
		 */		
		static void insertMedia(MediaPtr m);	
		
		/** 
		 * Inserts a group object into the hash table
		 * @throws runtime_error If there is already a group
		 * with the same name.
		 */		
		static void insertMediaGrp(MediaGrpPtr mg);
		
	public:		
			
		/** Find a media by name
		 * @param srch The name of the searched media
		 * @returns a pointer to the object, or `nullptr`
		 * if nothing is found. 
		 */
		static MediaPtr findMedia(string srch);	
			
		/** Find a group by name
		 * @param srch The name of the searched group
		 * @returns a pointer to the group, or `nullptr`
		 * if nothing is found. 
		 */
		static MediaGrpPtr findMediaGrp(string srch);
				
		/** Play a media
		 * @param name The name of the media
		 * @throws runtime_error if the media is not found
		 */
		static void playMedia(const string name);
		
		/** Prints a human-readable representation of the media in
		 * the standard output
		 * @param name The name of the media
		 * @throws runtime_error if the media is not found
		 */		
		static void printMedia(const string name);
		
		/** Prints a human-readable representation of the group in
		 * the standard output
		 * @param name The name of the group
		 * @throws runtime_error if the group is not found
		 */			
		static void printGroup(const string name);	
		
		/** 
		 * Prints a human-readable representation of all the stored media
		 */			
		static void printAllMedia();		
		
		/** 
		 * Prints a human-readable representation of all the stored groups
		 */	
		static void printAllGrp();		
		
		/** Create a new photo
		 * @param name The name of the photo
		 * @param path The location of the file
		 * @returns a shared pointer to the object
		 * @throws runtime_error if there is already a media 
		 * object with the same name.
		 */
		static shared_ptr<Photo> newPhoto(string name, string path);
		
		/** Create a new video
		 * @param name The name of the video
		 * @param path The location of the file
		 * @returns a shared pointer to the object
		 * @throws runtime_error if there is already a media 
		 * object with the same name.
		 */		
		static shared_ptr<Video> newVideo(string name, string path);
		
		/** Create a new film
		 * @param name The name of the film
		 * @param path The location of the file
		 * @returns a shared pointer to the object
		 * @throws runtime_error if there is already a media 
		 * object with the same name.
		 */		
		static shared_ptr<Film>  newFilm (string name, string path);
		
		/** Create a new group of media
		 * @param name The name of the group
		 * @returns a shared pointer to the object
		 * @throws runtime_error if there is already a group
		 *  with the same name.
		 */		
		static MediaGrpPtr newMediaGrp(string name);
		
		/** Remove a media object
		 * @param name The name of the media
		 * @throws runtime_error if there is no stored 
		 * media with this name
		 */		
		static void removeMedia(string name);
		
		/** Remove a group object
		 * @param name The name of the group
		 * @throws runtime_error if there is no stored 
		 * group with this name
		 */	
		static void removeGroup(string name);
		
		/** Process a request from a client
		 * @param request A well formatted request.
		 * 
		 * e.g.: "print [name of media]" or "play [name of media]"
		 * @returns the response
		 */
		static string handleRequest(string request);
		
		/**
		 * Create a new object from a serialized representation
		 */
		static MediaPtr fromString(string serialized);

};

