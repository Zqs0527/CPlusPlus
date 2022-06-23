#include "GeolocationRequest.cpp"
#include "GeolocationWifiPoints.cpp"

int main()
{
	// find wifi access points
	GeolocationWifiPoints wifiAccess;
	wifiAccess.getWifiNetworks();
	char * jsonPayload = wifiAccess.buildRequestJSON();

	// request and display location info
	GeoLocationRequest request;
	request.getLocation(jsonPayload);

	return 0;
}