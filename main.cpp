#include "include/Intal.h"
#include "include/get_time.h"

using namespace std;

void test_add() {

	struct timespec requestStart, requestEnd;

	string num1, num2;

	cin >> num1 >> num2;

	Intal n1( num1);
	Intal n2( num2);
	
	cout << (num1==num2);
	
	clock_gettime(CLOCK_REALTIME, &requestStart);

	cout << n1 + n2 << endl;

	clock_gettime(CLOCK_REALTIME, &requestEnd);

	cout << "Time: " << accum_time(requestStart, requestEnd);
}

void test_sub() {

	struct timespec requestStart, requestEnd;

	string num1, num2;

	cin >> num1 >> num2;

	Intal n1( num1);
	Intal n2( num2);

	clock_gettime(CLOCK_REALTIME, &requestStart);

	cout << n1 - n2 << endl;

	clock_gettime(CLOCK_REALTIME, &requestEnd);

	cout << "Time: " << accum_time(requestStart, requestEnd);
}

void test_mul() {

	struct timespec requestStart, requestEnd;

	string num1, num2;

	cin >> num1 >> num2;

	Intal n1( num1);
	Intal n2( num2);

	clock_gettime(CLOCK_REALTIME, &requestStart);

	cout << n1 * n2 << endl;

	clock_gettime(CLOCK_REALTIME, &requestEnd);

	cout << "Time: " << accum_time(requestStart, requestEnd);
}

void test_div() {

	struct timespec requestStart, requestEnd;

	string num1, num2;

	cin >> num1 >> num2;

	Intal n1( num1);
	Intal n2( num2);

	clock_gettime(CLOCK_REALTIME, &requestStart);

	cout << n1 / n2 << endl;

	clock_gettime(CLOCK_REALTIME, &requestEnd);

	cout << "Time: " << accum_time(requestStart, requestEnd);
}

void test_expo() {

	struct timespec requestStart, requestEnd;

	string num1, num2;

	cin >> num1 >> num2;

	Intal n1( num1);
	Intal n2( num2);

	clock_gettime(CLOCK_REALTIME, &requestStart);

	cout << (n1 ^ n2) << endl;

	clock_gettime(CLOCK_REALTIME, &requestEnd);

	cout << "Time: " << accum_time(requestStart, requestEnd);
}

void run_tests(char** args, int no_of_args) {
	int i = 0;
	for (i = 0; i < no_of_args; ++i) {
		if (args[i][1] == 'a')
			test_add();
		else if (args[i][1] == 's')
			test_sub();
		else if (args[i][1] == 'm')
			test_mul();
		else if (args[i][1] == 'd')
			test_div();
		else if (args[i][1] == 'e')
			test_expo();
		if (i != no_of_args - 1)
			printf("\n\n");
	}
}

int main(int argl, char** argv) {
	run_tests(argv + 1, argl - 1);

	return 0;
}
