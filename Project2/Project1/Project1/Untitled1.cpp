#include <iostream>
#include <ctime>

using namespace std;

int main() {
//   time_t now = time(0);
//   //tm *ltm = localtime(&now);
//   struct tm *ltm;
//	localtime_s(ltm, &now);
//   cout << "Year" << 1900+ ltm->tm_year<<endl;
//   cout << "Month: "<< 1 + ltm->tm_mon<< endl;
//   cout << "Day: "<<  ltm->tm_mday << endl;
 time_t rawtime;
    tm timeinfo;
    errno_t result = localtime_s(&timeinfo, &rawtime);
    cout << "Current local time and date: " << asctime_s(&timeinfo, &rawtime) << endl;
}
