#include <iostream>
using namespace std;

int main() {
	int test, num;
	cin >> test;
	for (int i=0; i<test; i++) {
		cin >> num;
		if(num%6==0) {
			cout << "Y" << endl;
		} else {
			cout << "N" << endl;
		}
	}
	return 0;
}