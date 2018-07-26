
#include <stdio.h>

typedef struct Address {
	const char* name;
	int number;
	const char* street;
	const char* town;
	char state[2];
	const char* zip; 
} Address;

void print_addr(Address* p) {
	cout << p->name << '\n'
		<< p->number << ' ' << p->street << '\n'
		<< p->town << '\n'
		<< p->state[0] << p->state[1] << ' ' << p->zip << '\n';
}

void f() {
	Address jd;
	jd.name = "Jim Dandy";
	jd.number = 61;
	printf("%s\n", jd.name);
}

int main() {
	Address jd = {
		"Jim Dandy",
		61, "South St",
		"New Providence",
		{'N', 'J'}, "07974"
	};
	printf("%d\n", jd.number);
	print_addr(&jd);

	return 0;
}