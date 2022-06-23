#ifndef GEOLOCATIONREQUEST_H_
#define GEOLOCATIONREQUEST_H_


#include <iostream>
#include <string>
#include <cstring>
#include "cJSON.h"
#include <curl/curl.h>

#define GEO_API_BASE_URL "https://www.googleapis.com/geolocation/v1/geolocate?key="
#define GEO_API_KEY "AIzaSyCQazo5RZeYDiLV-hHe6r5vI3Hm1Jv3I3A"
#define GEO_API_REQUEST_URL GEO_API_BASE_URL GEO_API_KEY

class GeoLocationRequest
{
private:
    struct MemoryStruct
    {
       char *memory;
       size_t size;
    };

    static size_t writeMemoryCallback(void *contents,
	                                  size_t size,
									  size_t nmemb,
									  void *userp);
    
public:
    void getLocation(char *jsonPayload);
    void printLocationInfo(char *response);
};

#endif // GEOLOCATIONREQUEST_H_