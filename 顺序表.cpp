#include<iostream>
using namespace std;
#define Initsize 10
typedef struct {
	int* data;
	int maxsize;
	int length;
}Sqlist;
void Initlist(Sqlist &L) {
	L.data = (int*)malloc(Initsize * sizeof(int));
	L.length = 0;
	L.maxsize = Initsize;
}
bool Insertlist(Sqlist& L, int e, int s) {
	if (e < 1 || e >= L.maxsize || e>L.length + 1) {
		return false;
	}
	for (int i = L.length; i >= e; i--) {
		L.data[i] = L.data[i - 1];
	}
	L.data[e - 1] = s;
	L.length++;
	return true;
}
bool Listdelete(Sqlist& L, int i, int& e) {
	if (i<1 || i>L.length) {
		return false;
	}
	e = L.data[i - 1];
	for (int j = i; j < L.length; j++) {
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	return true;
	    
}
void Showlist(Sqlist L) {
	for (int i = 0; i < L.length; i++) {
		cout << L.data[i] << endl;
	}
}
bool Getelem(Sqlist& L, int i) {
	if (i<1 || i>L.length) {
		return false;
	}
	cout << L.data[i - 1] << endl;
	return true;
}
int main() {
	Sqlist L;
	Initlist(L);
	Insertlist(L, 1, 5);
	Insertlist(L, 2, 10);
	Insertlist(L, 3, 2);
	Showlist(L);
	int e = -1;
	if (Listdelete(L, 3, e)) {
		cout << "Delete Element:" << e << endl;
	}
	else {
		cout << "Delete Failed" << endl;
	}
	Showlist(L);
	Getelem(L, 2);
	return 0;
}