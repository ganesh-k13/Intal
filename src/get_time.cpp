#include "../include/get_time.h" 

using namespace std;

double accum_time(struct timespec requestStart, struct timespec requestEnd) {
	
	return ((requestEnd.tv_sec - requestStart.tv_sec)) * 1000 +
			(( requestEnd.tv_nsec - requestStart.tv_nsec ) / MILLION);
}
