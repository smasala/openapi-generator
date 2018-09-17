#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "apiClient.h"
#include "cJSON.h"
#include "list.h"
#include "user.h"

#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
	do { \
		char dst[64]; \
		snprintf(dst, 64, "%ld", (long int) (src)); \
	} while(0)

// Create user
//
// This can only be done by the logged in user.
//
void *UserAPI_createUser(apiClient_t *apiClient, user_t *user) {
	list_t *localVarQueryParameters = list_create();
	list_t *localVarHeaderParameters = list_create();
	list_t *localVarFormParameters = list_create();
	char *localVarBodyParameters;

	// create the path
	char *localVarPath = malloc(MAX_BUFFER_LENGTH);
	snprintf(localVarPath, MAX_BUFFER_LENGTH, "/user");




	// JSON HTTP Request - user
	// string
	cJSON *UserJSONObject;
	UserJSONObject = user_convertToJSON(user);
	localVarBodyParameters = cJSON_Print(UserJSONObject);




	apiClient_invoke(apiClient,
	                 "user",
	                 localVarPath,
	                 localVarQueryParameters,
	                 localVarHeaderParameters,
	                 localVarFormParameters,
	                 localVarBodyParameters,
	                 "POST");

	// free(apiClient->dataReceived);
	// free(localVarPath);
	// free(localVarBodyParameters);
	// cJSON_Delete(UserJSONObject);
}

// Creates list of users with given input array
//
void *UserAPI_createUsersWithArrayInput(apiClient_t *apiClient, list_t *user) {
	list_t *localVarQueryParameters = list_create();
	list_t *localVarHeaderParameters = list_create();
	list_t *localVarFormParameters = list_create();
	char *localVarBodyParameters;

	// create the path
	char *localVarPath = malloc(MAX_BUFFER_LENGTH);
	snprintf(localVarPath, MAX_BUFFER_LENGTH, "/user/createWithArray");




	// JSON HTTP Request - user
	// notstring
	localVarQueryParameters = user;
	// list_t *userItem = list_create();
	// list_ForEach(userItem, user) {
	// list_addElement(localVarQueryParameters,userItem);
	// }




	apiClient_invoke(apiClient,
	                 "user",
	                 localVarPath,
	                 localVarQueryParameters,
	                 localVarHeaderParameters,
	                 localVarFormParameters,
	                 localVarBodyParameters,
	                 "POST");

	// free(apiClient->dataReceived);
	// free(localVarPath);
	// free(localVarBodyParameters);
	// cJSON_Delete(UserJSONObject);
}

// Creates list of users with given input array
//
void *UserAPI_createUsersWithListInput(apiClient_t *apiClient, list_t *user) {
	list_t *localVarQueryParameters = list_create();
	list_t *localVarHeaderParameters = list_create();
	list_t *localVarFormParameters = list_create();
	char *localVarBodyParameters;

	// create the path
	char *localVarPath = malloc(MAX_BUFFER_LENGTH);
	snprintf(localVarPath, MAX_BUFFER_LENGTH, "/user/createWithList");




	// JSON HTTP Request - user
	// notstring
	localVarQueryParameters = user;
	// list_t *userItem = list_create();
	// list_ForEach(userItem, user) {
	// list_addElement(localVarQueryParameters,userItem);
	// }




	apiClient_invoke(apiClient,
	                 "user",
	                 localVarPath,
	                 localVarQueryParameters,
	                 localVarHeaderParameters,
	                 localVarFormParameters,
	                 localVarBodyParameters,
	                 "POST");

	// free(apiClient->dataReceived);
	// free(localVarPath);
	// free(localVarBodyParameters);
	// cJSON_Delete(UserJSONObject);
}

// Delete user
//
// This can only be done by the logged in user.
//
void *UserAPI_deleteUser(apiClient_t *apiClient, char *username) {
	list_t *localVarQueryParameters = list_create();
	list_t *localVarHeaderParameters = list_create();
	list_t *localVarFormParameters = list_create();
	char *localVarBodyParameters;

	// create the path
	char *localVarPath = malloc(MAX_BUFFER_LENGTH);
	snprintf(localVarPath, MAX_BUFFER_LENGTH, "/user/{username}");

	// TODO path parameter Username (username) not yet supported
	// TODO base path = http://petstore.swagger.io/v2


	char *baseNameModToReplace = malloc(strlen(username) + 2); // baseNameMod free not yet implemented
	snprintf(baseNameModToReplace,
	         strlen(username) + 3,
	         "%s%s%s",
	         "{",
	         "username",
	         "}");
	char *baseNameMod = malloc(strlen(username) + 2); // baseNameMod free not yet implemented
	snprintf(baseNameMod, strlen(username) + 3, "%s%s%s", "{", username,
	         "}");
	localVarPath = strReplace(localVarPath, baseNameModToReplace, username);
	// localVarPath = "username";







	apiClient_invoke(apiClient,
	                 "user",
	                 localVarPath,
	                 localVarQueryParameters,
	                 localVarHeaderParameters,
	                 localVarFormParameters,
	                 localVarBodyParameters,
	                 "DELETE");

	// free(apiClient->dataReceived);
	// free(localVarPath);
	// free(username);
}

// Get user by user name
//
user_t *UserAPI_getUserByName(apiClient_t *apiClient, char *username) {
	list_t *localVarQueryParameters = list_create();
	list_t *localVarHeaderParameters = list_create();
	list_t *localVarFormParameters = list_create();
	char *localVarBodyParameters;

	// create the path
	char *localVarPath = malloc(MAX_BUFFER_LENGTH);
	snprintf(localVarPath, MAX_BUFFER_LENGTH, "/user/{username}");

	// TODO path parameter Username (username) not yet supported
	// TODO base path = http://petstore.swagger.io/v2


	char *baseNameModToReplace = malloc(strlen(username) + 2); // baseNameMod free not yet implemented
	snprintf(baseNameModToReplace,
	         strlen(username) + 3,
	         "%s%s%s",
	         "{",
	         "username",
	         "}");
	char *baseNameMod = malloc(strlen(username) + 2); // baseNameMod free not yet implemented
	snprintf(baseNameMod, strlen(username) + 3, "%s%s%s", "{", username,
	         "}");
	localVarPath = strReplace(localVarPath, baseNameModToReplace, username);
	// localVarPath = "username";







	apiClient_invoke(apiClient,
	                 "user",
	                 localVarPath,
	                 localVarQueryParameters,
	                 localVarHeaderParameters,
	                 localVarFormParameters,
	                 localVarBodyParameters,
	                 "GET");

	// free(apiClient->dataReceived);
	// free(localVarPath);
	// free(username);

	// nonprimitive return type
	user_t *localVaruser = user_parseFromJSON(apiClient->dataReceived);
	if(localVaruser == NULL) {
		return 0;
	} else {
		// cJSON *jsonObject = User_convertToJSON(localVaruser);
		// cJSON_Delete(jsonObject);
	}

	return localVaruser;
}

// Logs user into the system
//
char *UserAPI_loginUser(apiClient_t *apiClient, char *username,
                        char *password) {
	list_t *localVarQueryParameters = list_create();
	list_t *localVarHeaderParameters = list_create();
	list_t *localVarFormParameters = list_create();
	char *localVarBodyParameters;

	// create the path
	char *localVarPath = malloc(MAX_BUFFER_LENGTH);
	snprintf(localVarPath, MAX_BUFFER_LENGTH, "/user/login");



	// TODO query parameters
	// query parameter Username (username) not yet supported
	// char *usernameQuery = malloc(MAX_BUFFER_LENGTH);
	if(username) {
		// string
		list_addElement(localVarQueryParameters, username);
	}
	// TODO query parameters
	// query parameter Password (password) not yet supported
	// char *passwordQuery = malloc(MAX_BUFFER_LENGTH);
	if(password) {
		// string
		list_addElement(localVarQueryParameters, password);
	}




	apiClient_invoke(apiClient,
	                 "user",
	                 localVarPath,
	                 localVarQueryParameters,
	                 localVarHeaderParameters,
	                 localVarFormParameters,
	                 localVarBodyParameters,
	                 "GET");

	// free(apiClient->dataReceived);
	// free(localVarPath);
	// free(username);
	// free(password);

	// primitive reutrn type
}

// Logs out current logged in user session
//
void *UserAPI_logoutUser(apiClient_t *apiClient) {
	list_t *localVarQueryParameters = list_create();
	list_t *localVarHeaderParameters = list_create();
	list_t *localVarFormParameters = list_create();
	char *localVarBodyParameters;

	// create the path
	char *localVarPath = malloc(MAX_BUFFER_LENGTH);
	snprintf(localVarPath, MAX_BUFFER_LENGTH, "/user/logout");







	apiClient_invoke(apiClient,
	                 "user",
	                 localVarPath,
	                 localVarQueryParameters,
	                 localVarHeaderParameters,
	                 localVarFormParameters,
	                 localVarBodyParameters,
	                 "GET");

	// free(apiClient->dataReceived);
	// free(localVarPath);
}

// Updated user
//
// This can only be done by the logged in user.
//
void *UserAPI_updateUser(apiClient_t *apiClient, char *username, user_t *user) {
	list_t *localVarQueryParameters = list_create();
	list_t *localVarHeaderParameters = list_create();
	list_t *localVarFormParameters = list_create();
	char *localVarBodyParameters;

	// create the path
	char *localVarPath = malloc(MAX_BUFFER_LENGTH);
	snprintf(localVarPath, MAX_BUFFER_LENGTH, "/user/{username}");

	// TODO path parameter Username (username) not yet supported
	// TODO base path = http://petstore.swagger.io/v2


	char *baseNameModToReplace = malloc(strlen(username) + 2); // baseNameMod free not yet implemented
	snprintf(baseNameModToReplace,
	         strlen(username) + 3,
	         "%s%s%s",
	         "{",
	         "username",
	         "}");
	char *baseNameMod = malloc(strlen(username) + 2); // baseNameMod free not yet implemented
	snprintf(baseNameMod, strlen(username) + 3, "%s%s%s", "{", username,
	         "}");
	localVarPath = strReplace(localVarPath, baseNameModToReplace, username);
	// localVarPath = "username";




	// JSON HTTP Request - user
	// string
	cJSON *UserJSONObject;
	UserJSONObject = user_convertToJSON(user);
	localVarBodyParameters = cJSON_Print(UserJSONObject);




	apiClient_invoke(apiClient,
	                 "user",
	                 localVarPath,
	                 localVarQueryParameters,
	                 localVarHeaderParameters,
	                 localVarFormParameters,
	                 localVarBodyParameters,
	                 "PUT");

	// free(apiClient->dataReceived);
	// free(localVarPath);
	// free(localVarBodyParameters);
	// cJSON_Delete(UserJSONObject);
	// free(localVarBodyParameters);
	// cJSON_Delete(UserJSONObject);
}
