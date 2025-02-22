#include <windows.h>
#include <stdio.h>

int main() {
    GEOID geoId = GetUserGeoID(GEOCLASS_NATION);
    if (geoId == GEOID_NOT_AVAILABLE) {
        printf("Unable to retrieve the region information.\n");
        return 1;
    }

    WCHAR regionName[100];
    int result = GetGeoInfoW(geoId, GEO_FRIENDLYNAME, regionName, sizeof(regionName) / sizeof(WCHAR), 0);
    if (result == 0) {
        printf("Unable to retrieve the region name.\n");
        return 1;
    }

    wprintf(L"Region: %s\n", regionName);
    return 0;
}