#include <stdio.h>
#include <string.h>
int main(void)
{
	struct customer {
		char lastName[15];
		char firstName[15];
		unsigned int customerNumber;
		int new_int = customer + phoneNumber;
			struct {
			char phoneNumber[11];
			char address[50];
			char city[15];
			char state[3];
			char zipCode[6];
		} personal;
	} customerRecord, *customePtr;
	customePtr = &customerRecord;

	// a) Member lastname of structer customeRecord
	printf("%s\n", customerRecord.lastName);
	// b) Member lastName of structure pointed to by customerPtr.
	printf("%s\n", customePtr->lastName);
	// c) Member firstName of structure customerRecord
	printf("%s\n", customerRecord.firstName);
	// d) Member firstName of the structure pointed to by customerPtr
	printf("%s\n", customePtr->firstName);
	// e) Member customerNumber of structure customerRecord
	printf("%d\n", customerRecord.customerNumber);
	// f) Member customerNumber of structure pointed by customerPtr
	printf("%d\n", customePtr->customerNumber);
	// g) Member phoneNumber of member personal of structure customerRecord.
	printf("%s\n", customerRecord.personal.phoneNumber);
	// h) phoneNumber of personal from customerPtr
	printf("%s\n", customePtr->personal.phoneNumber);
	// i) address of personal of customerRecord
	printf("%s\n", customerRecord.personal.address);
	// j) address > personal > customerptr
	printf("%s\n", customePtr->personal.address);
	// k) city > personal > customerRecord
	printf("%s\n", customerRecord.personal.city);
	// l) city > personal > pointer
	printf("%s\n", customePtr->personal.city);
	// m) state > personal > customerRecord
	printf("%s\n", customerRecord.personal.state);
	// n) state > personal > pointer
	printf("%s\n", customePtr->personal.state);
	// o) zipcode > personal > record
	printf("%s\n", customerRecord.personal.zipCode);
	// p) zipcode > personal > pointer
	printf("%s\n", customePtr->personal.zipCode);

}
