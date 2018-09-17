#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "apiClient.h"
#include "cJSON.h"
#include "api_response.h"
#include "pet.h"

#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
	do { \
		char dst[64]; \
		snprintf(dst, 64, "%ld", (long int) (src)); \
	} while(0)

// Add a new pet to the store
//
void *PetAPI_addPet(apiClient_t *apiClient, pet_t *pet) {
	list_t *localVarQueryParameters = list_create();
	list_t *localVarHeaderParameters = list_create();
	list_t *localVarFormParameters = list_create();
	char *localVarBodyParameters;

	// create the path
	char *localVarPath = malloc(MAX_BUFFER_LENGTH);
	snprintf(localVarPath, MAX_BUFFER_LENGTH, "/pet");




	// JSON HTTP Request - pet
	// string
	cJSON *PetJSONObject;
	PetJSONObject = pet_convertToJSON(pet);
	localVarBodyParameters = cJSON_Print(PetJSONObject);




	apiClient_invoke(apiClient,
	                 "pet",
	                 localVarPath,
	                 localVarQueryParameters,
	                 localVarHeaderParameters,
	                 localVarFormParameters,
	                 localVarBodyParameters,
	                 "POST");

	// free(apiClient->dataReceived);
	// free(localVarPath);
	// free(localVarBodyParameters);
	// cJSON_Delete(PetJSONObject);
}

// Deletes a pet
//
void *PetAPI_deletePet(apiClient_t *apiClient, long petId, char *api_key) {
	list_t *localVarQueryParameters = list_create();
	list_t *localVarHeaderParameters = list_create();
	list_t *localVarFormParameters = list_create();
	char *localVarBodyParameters;

	// create the path
	char *localVarPath = malloc(MAX_BUFFER_LENGTH);
	snprintf(localVarPath, MAX_BUFFER_LENGTH, "/pet/{petId}");

	// TODO path parameter PetId (petId) not yet supported
	// TODO base path = http://petstore.swagger.io/v2


	char *baseNameModToReplace = malloc(sizeof(petId) + 3); // baseNameMod free not yet implemented
	snprintf(baseNameModToReplace,
	         strlen("petId") + 3,
	         "%s%s%s",
	         "{",
	         "petId",
	         "}");
	char *baseNameMod = malloc(sizeof(petId) + 2); // baseNameMod free not yet implemented
	snprintf(baseNameMod, sizeof(petId) + 3, "%s%li%s", "{", petId, "}");
	char buff[64];
	intToStr(buf, petId);
	localVarPath = strReplace(localVarPath, baseNameModToReplace, buff);
	// localVarPath = buff;


	// TODO header parameters
	// header parameter ApiKey (api_key) not yet supported
	if(api_key) {
		list_addElement(localVarHeaderParameters, api_key);
	}





	apiClient_invoke(apiClient,
	                 "pet",
	                 localVarPath,
	                 localVarQueryParameters,
	                 localVarHeaderParameters,
	                 localVarFormParameters,
	                 localVarBodyParameters,
	                 "DELETE");

	// free(apiClient->dataReceived);
	// free(localVarPath);
	// free(api_key);
}

// Finds Pets by status
//
// Multiple status values can be provided with comma separated strings
//
list_t *PetAPI_findPetsByStatus(apiClient_t *apiClient, list_t *status) {
	list_t *localVarQueryParameters = list_create();
	list_t *localVarHeaderParameters = list_create();
	list_t *localVarFormParameters = list_create();
	char *localVarBodyParameters;

	// create the path
	char *localVarPath = malloc(MAX_BUFFER_LENGTH);
	snprintf(localVarPath, MAX_BUFFER_LENGTH, "/pet/findByStatus");



	// TODO query parameters
	// query parameter Status (status) not yet supported
	// char *statusQuery = malloc(MAX_BUFFER_LENGTH);
	if(status) {
		// notstring
		localVarQueryParameters = status;
		// list_t *statusItem = list_create();
		// list_ForEach(statusItem, status) {
		// list_addElement(localVarQueryParameters,statusItem);
		// }
	}




	apiClient_invoke(apiClient,
	                 "pet",
	                 localVarPath,
	                 localVarQueryParameters,
	                 localVarHeaderParameters,
	                 localVarFormParameters,
	                 localVarBodyParameters,
	                 "GET");

	// free(apiClient->dataReceived);
	// free(localVarPath);

	cJSON *Pet;
	cJSON *PetAPIJSON = cJSON_Parse(apiClient->dataReceived);
	// cJSON *PetJSON = cJSON_GetObjectItemCaseSensitive(PetAPIJSON, "Pet");
	if(!cJSON_IsArray(PetAPIJSON)) {
		return 0; // primitive container
	}
	list_t *PetList = list_create();

	cJSON_ArrayForEach(Pet, PetAPIJSON)
	{
		if(!cJSON_IsObject(Pet)) {
			return 0;
		}
		char *JSONToChar = cJSON_Print(Pet);
		list_addElement(PetList, JSONToChar);
	}
	return PetList;
}

// Finds Pets by tags
//
// Multiple tags can be provided with comma separated strings. Use tag1, tag2, tag3 for testing.
//
list_t *PetAPI_findPetsByTags(apiClient_t *apiClient, list_t *tags) {
	list_t *localVarQueryParameters = list_create();
	list_t *localVarHeaderParameters = list_create();
	list_t *localVarFormParameters = list_create();
	char *localVarBodyParameters;

	// create the path
	char *localVarPath = malloc(MAX_BUFFER_LENGTH);
	snprintf(localVarPath, MAX_BUFFER_LENGTH, "/pet/findByTags");



	// TODO query parameters
	// query parameter Tags (tags) not yet supported
	// char *tagsQuery = malloc(MAX_BUFFER_LENGTH);
	if(tags) {
		// notstring
		localVarQueryParameters = tags;
		// list_t *tagsItem = list_create();
		// list_ForEach(tagsItem, tags) {
		// list_addElement(localVarQueryParameters,tagsItem);
		// }
	}




	apiClient_invoke(apiClient,
	                 "pet",
	                 localVarPath,
	                 localVarQueryParameters,
	                 localVarHeaderParameters,
	                 localVarFormParameters,
	                 localVarBodyParameters,
	                 "GET");

	// free(apiClient->dataReceived);
	// free(localVarPath);

	cJSON *Pet;
	cJSON *PetAPIJSON = cJSON_Parse(apiClient->dataReceived);
	// cJSON *PetJSON = cJSON_GetObjectItemCaseSensitive(PetAPIJSON, "Pet");
	if(!cJSON_IsArray(PetAPIJSON)) {
		return 0; // primitive container
	}
	list_t *PetList = list_create();

	cJSON_ArrayForEach(Pet, PetAPIJSON)
	{
		if(!cJSON_IsObject(Pet)) {
			return 0;
		}
		char *JSONToChar = cJSON_Print(Pet);
		list_addElement(PetList, JSONToChar);
	}
	return PetList;
}

// Find pet by ID
//
// Returns a single pet
//
pet_t *PetAPI_getPetById(apiClient_t *apiClient, long petId) {
	list_t *localVarQueryParameters = list_create();
	list_t *localVarHeaderParameters = list_create();
	list_t *localVarFormParameters = list_create();
	char *localVarBodyParameters;

	// create the path
	char *localVarPath = malloc(MAX_BUFFER_LENGTH);
	snprintf(localVarPath, MAX_BUFFER_LENGTH, "/pet/{petId}");

	// TODO path parameter PetId (petId) not yet supported
	// TODO base path = http://petstore.swagger.io/v2


	char *baseNameModToReplace = malloc(sizeof(petId) + 3); // baseNameMod free not yet implemented
	snprintf(baseNameModToReplace,
	         strlen("petId") + 3,
	         "%s%s%s",
	         "{",
	         "petId",
	         "}");
	char *baseNameMod = malloc(sizeof(petId) + 2); // baseNameMod free not yet implemented
	snprintf(baseNameMod, sizeof(petId) + 3, "%s%li%s", "{", petId, "}");
	char buff[64];
	intToStr(buf, petId);
	localVarPath = strReplace(localVarPath, baseNameModToReplace, buff);
	// localVarPath = buff;







	apiClient_invoke(apiClient,
	                 "pet",
	                 localVarPath,
	                 localVarQueryParameters,
	                 localVarHeaderParameters,
	                 localVarFormParameters,
	                 localVarBodyParameters,
	                 "GET");

	// free(apiClient->dataReceived);
	// free(localVarPath);

	// nonprimitive return type
	pet_t *localVarpet = pet_parseFromJSON(apiClient->dataReceived);
	if(localVarpet == NULL) {
		return 0;
	} else {
		// cJSON *jsonObject = Pet_convertToJSON(localVarpet);
		// cJSON_Delete(jsonObject);
	}

	return localVarpet;
}

// Update an existing pet
//
void *PetAPI_updatePet(apiClient_t *apiClient, pet_t *pet) {
	list_t *localVarQueryParameters = list_create();
	list_t *localVarHeaderParameters = list_create();
	list_t *localVarFormParameters = list_create();
	char *localVarBodyParameters;

	// create the path
	char *localVarPath = malloc(MAX_BUFFER_LENGTH);
	snprintf(localVarPath, MAX_BUFFER_LENGTH, "/pet");




	// JSON HTTP Request - pet
	// string
	cJSON *PetJSONObject;
	PetJSONObject = pet_convertToJSON(pet);
	localVarBodyParameters = cJSON_Print(PetJSONObject);




	apiClient_invoke(apiClient,
	                 "pet",
	                 localVarPath,
	                 localVarQueryParameters,
	                 localVarHeaderParameters,
	                 localVarFormParameters,
	                 localVarBodyParameters,
	                 "PUT");

	// free(apiClient->dataReceived);
	// free(localVarPath);
	// free(localVarBodyParameters);
	// cJSON_Delete(PetJSONObject);
}

// Updates a pet in the store with form data
//
void *PetAPI_updatePetWithForm(apiClient_t	*apiClient,
                               long		petId,
                               char		*name,
                               char		*status) {
	list_t *localVarQueryParameters = list_create();
	list_t *localVarHeaderParameters = list_create();
	list_t *localVarFormParameters = list_create();
	char *localVarBodyParameters;

	// create the path
	char *localVarPath = malloc(MAX_BUFFER_LENGTH);
	snprintf(localVarPath, MAX_BUFFER_LENGTH, "/pet/{petId}");

	// TODO path parameter PetId (petId) not yet supported
	// TODO base path = http://petstore.swagger.io/v2


	char *baseNameModToReplace = malloc(sizeof(petId) + 3); // baseNameMod free not yet implemented
	snprintf(baseNameModToReplace,
	         strlen("petId") + 3,
	         "%s%s%s",
	         "{",
	         "petId",
	         "}");
	char *baseNameMod = malloc(sizeof(petId) + 2); // baseNameMod free not yet implemented
	snprintf(baseNameMod, sizeof(petId) + 3, "%s%li%s", "{", petId, "}");
	char buff[64];
	intToStr(buf, petId);
	localVarPath = strReplace(localVarPath, baseNameModToReplace, buff);
	// localVarPath = buff;




	// TODO form parameters
	// form parameter Name (name) not yet supported
	if(name) {
		list_addElement(localVarFormParameters, name); // String
	}


	// TODO form parameters
	// form parameter Status (status) not yet supported
	if(status) {
		list_addElement(localVarFormParameters, status); // String
	}





	apiClient_invoke(apiClient,
	                 "pet",
	                 localVarPath,
	                 localVarQueryParameters,
	                 localVarHeaderParameters,
	                 localVarFormParameters,
	                 localVarBodyParameters,
	                 "POST");

	// free(apiClient->dataReceived);
	// free(localVarPath);
	// free(name);
	// free(status);
}

// uploads an image
//
api_response_t *PetAPI_uploadFile(apiClient_t	*apiClient,
                                  long		petId,
                                  char		*additionalMetadata,
                                  FILE		file) {
	list_t *localVarQueryParameters = list_create();
	list_t *localVarHeaderParameters = list_create();
	list_t *localVarFormParameters = list_create();
	char *localVarBodyParameters;

	// create the path
	char *localVarPath = malloc(MAX_BUFFER_LENGTH);
	snprintf(localVarPath, MAX_BUFFER_LENGTH, "/pet/{petId}/uploadImage");

	// TODO path parameter PetId (petId) not yet supported
	// TODO base path = http://petstore.swagger.io/v2


	char *baseNameModToReplace = malloc(sizeof(petId) + 3); // baseNameMod free not yet implemented
	snprintf(baseNameModToReplace,
	         strlen("petId") + 3,
	         "%s%s%s",
	         "{",
	         "petId",
	         "}");
	char *baseNameMod = malloc(sizeof(petId) + 2); // baseNameMod free not yet implemented
	snprintf(baseNameMod, sizeof(petId) + 3, "%s%li%s", "{", petId, "}");
	char buff[64];
	intToStr(buf, petId);
	localVarPath = strReplace(localVarPath, baseNameModToReplace, buff);
	// localVarPath = buff;




	// TODO form parameters
	// form parameter AdditionalMetadata (additionalMetadata) not yet supported
	if(additionalMetadata) {
		list_addElement(localVarFormParameters, additionalMetadata); // String
	}


	// TODO form parameters
	// form parameter File (file) not yet supported
	// if (file && *file != NULL)
	{
		// list_addElement(localVarFormParameters,file); //notstring
	}





	apiClient_invoke(apiClient,
	                 "pet",
	                 localVarPath,
	                 localVarQueryParameters,
	                 localVarHeaderParameters,
	                 localVarFormParameters,
	                 localVarBodyParameters,
	                 "POST");

	// free(apiClient->dataReceived);
	// free(localVarPath);
	// free(additionalMetadata);

	// nonprimitive return type
	api_response_t *localVarapi_response = api_response_parseFromJSON(
		apiClient->dataReceived);
	if(localVarapi_response == NULL) {
		return 0;
	} else {
		// cJSON *jsonObject = Pet_convertToJSON(localVarapi_response);
		// cJSON_Delete(jsonObject);
	}

	return localVarapi_response;
}
