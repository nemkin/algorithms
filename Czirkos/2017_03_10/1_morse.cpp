#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Morse {
	
	int index = 0;
	Morse* leftkid=NULL;
	Morse* rightkid=NULL;

	int leftkidi=0;
	int rightkidi=0;

	char c;
	string m;
	
	Morse(){}
	Morse(char c, string m):c(c),m(m){}
	
	char operator[] (int i) {
		if(i<m.length()) return m[i];
		return ' ';
	}

	bool operator == (const Morse &a) const {
		return (this->c == a.c);
	}

} Morse;

bool inorder (Morse a, Morse b) {
	int i=0;
	while(a[i]==b[i]) ++i;

	if(a.c == b.c) return false;
	
	if(a[i]=='.') return true;
	if(a[i]==' ' && b[i]=='-') return true;
	
	return false;
}

bool preorder (Morse a, Morse b) {
	int i=0;
	while(a[i]==b[i]) ++i;

	if(a.c == b.c) return false;
	
	if(a[i]==' ') return true;
	if(a[i]=='.' && b[i]=='-') return true;
	
	return false;
}

Morse morse_data[] = {
    { ' ', ""},
    { 'A', ".-" },
    { 'B', "-..." },
    { 'C', "-.-." },
    { 'D', "-.." },
    { 'E', "." },
    { 'F', "..-." },
    { 'G', "--." },
    { 'H', "...." },
    { 'I', ".." },
    { 'J', ".---" },
    { 'K', "-.-" },
    { 'L', ".-.." },
    { 'M', "--" },
    { 'N', "-." },
    { 'O', "---" },
    { 'P', ".--." },
    { 'Q', "--.-" },
    { 'R', ".-." },
    { 'S', "..." },
    { 'T', "-" },
    { 'U', "..-" },
    { 'V', "...-" },
    { 'W', ".--" },
    { 'X', "-..-" },
    { 'Y', "-.--" },
    { 'Z', "--.." },
    { '0', "-----" },
    { '1', ".----" },
    { '2', "..---" },
    { '3', "...--" },
    { '4', "....-" },
    { '5', "....." },
    { '6', "-...." },
    { '7', "--..." },
    { '8', "---.." },
    { '9', "----." }
};

Morse* index(Morse *begin, Morse* end) {
	
	if(end<begin) return NULL;
	
	if(end==begin) return begin;
	
	sort(begin,end,preorder);
	Morse c = *begin;
	sort(begin,end,inorder);
	Morse* parent = find(begin,end,c);
	
	parent->leftkid=index(begin,parent-1);
	parent->rightkid=index(parent+1,end);

	return parent;
}

void print(Morse* parent) {
	if(parent==NULL) return;


	cout<<"{ "<<parent->c<<", ";

	if(parent->leftkid==NULL) cout<<" ";
	else cout<<parent->leftkid->index;
	
	cout<<", ";

	if(parent->rightkid==NULL) cout<<" ";
	else cout<<parent->rightkid->index;

	cout<<" }"<<endl;
	
	print(parent->leftkid);
	print(parent->rightkid);
}

int main () {
	
	//for(int i=0; i<37; ++i) {
	//	morse_data[i].index=i;
	//}
	
	//sort(morse_data, morse_data+37, inorder);

	//for(int i=0; i<37; ++i) {
	//	cout<<morse_data[i].index<<" "<<morse_data[i].c<<endl;
	//}
	
	//Morse* root = index(morse_data, morse_data+37);
	//print(root);

	Morse new_data[3*3*3*3*3];
	for(int i=0; i<37; ++i) {
		int index = 0;
		for(int j=0; j<5; ++j) {
			index*=3;
			switch(morse_data[i][j]) {
				case ' ': index+=0; break;
				case '.': index+=1; break;
				case '-': index+=2; break;
			}
		}
		new_data[index]=morse_data[i];
		new_data[index].leftkidi=index+1*pow(3,5-morse_data[i].m.length());
		new_data[index].rightkidi=index+2*pow(3,5-morse_data[i].m.length());
	}

	for(int i=0; i<3*3*3*3*3; ++i) {
		cout<<new_data[i].c<<" "<<new_data[i].leftkidi<<" "<<new_data[i].rightkidi<<endl;
	}	

	return 0;
}
