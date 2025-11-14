#include<iostream>
using namespace std;
#define Maxsize 10
typedef struct Node {
	int data;
	int next;
}Linklist[Maxsize];
bool Initlist(Linklist& L) {
	L[0].next = -1;
	return true;
}

int main() {
	Linklist a;
	return 0;
}