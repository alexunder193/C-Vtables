#include <iostream>
#include <cstdlib>

using namespace std;

class FirstFather { 
	public:
      int a;
      int b;
      virtual void printMessage1() {
		  cout << "FirstFather printMessage1 method.\n"; 
	  }
	  virtual void printMessage2() {
		  cout << "FirstFather printMessage2 method.\n"; 
	  }
}; 
  
class SecondFather { 
	public:
      int c;
      int d;
      virtual void printMessage3() {
		  cout << "SecondFather printMessage3 method.\n"; 
	  }
	  virtual void printMessage4() {
		  cout << "SecondFather printMessage4 method.\n"; 
	  }
}; 
  
class Child: public FirstFather, public SecondFather {	
	public:
      int e;
      int f;
	  void printMessage1() {
		cout << "Child printMessage1 method.\n"; 
	  }
	  
	  virtual void printMessage5() {
        cout << "Child printMessage5 method.\n" << endl;
      }
}; 


int main(int argc,char *argv[]) {
	FirstFather* firstFather = new FirstFather();
	firstFather->a = 1;
	firstFather->b = 2;
	
	SecondFather* secondFather = new SecondFather();
	secondFather->c = 3;
	secondFather->d = 4;
	
	Child *child = new Child();
	child->e = 5;
	child->f = 6;

	cout << "FirstFather Layout" << endl;
	cout << "------------------" << endl;
	cout << "Address of FirstFather base: " << ((int*)firstFather) <<endl;
	cout << "FirstFather Vtable address: " << ((int*)firstFather)[0] << endl;
    cout << "Address of a field: " << ((int*)firstFather + 2) <<endl;
    cout << "value of a field: " << ((int*)firstFather)[2] << endl;
    cout << "Address of a field: " << ((int*)firstFather + 3) <<endl;
    cout << "value of b field: " << ((int*)firstFather)[3] << endl;
    
    cout << "\nFirstFather VTable" << endl;
    cout << "------------------" << endl;
    int *firstFatherVPtr = *(int **) firstFather;
    cout << "In position 0 of Vtable call virtual printMessage1()" << endl;
    ((void (*)()) (*(firstFatherVPtr)))();
    cout << "In position 1 of Vtable call virtual printMessage2()" << endl;
    ((void (*)()) (*(firstFatherVPtr + 2)))();
    
    
	cout << "\nSecondFather Layout" << endl;
	cout << "------------------" << endl;
	cout << "Address of SecondFather base: " << ((int*)secondFather) <<endl;
	cout << "SecondFather Vtable address: " << ((int*)secondFather)[0] << endl;
    cout << "Address of c field: " << ((int*)secondFather + 2) <<endl;
    cout << "value of c field: " << ((int*)secondFather)[2] << endl;
    cout << "Address of d field: " << ((int*)secondFather + 3) <<endl;
    cout << "value of d field: " << ((int*)secondFather)[3] << endl;
    
    cout << "\nSecondFather VTable" << endl;
    cout << "------------------" << endl;
    int *secondFatherVPtr = *(int **) secondFather;
    cout << "In position 0 of Vtable call virtual printMessage3()" << endl;
    ((void (*)()) (*(secondFatherVPtr)))();
    cout << "In position 1 of Vtable call virtual printMessage4()" << endl;
    ((void (*)()) (*(secondFatherVPtr + 2)))();
    
    cout << "\nChild VTable" << endl;
    cout << "------------------" << endl;
    int *childVPtr = *((int **) child);
    ((void (*)()) (*(childVPtr)))();
    ((void (*)()) (*(childVPtr + 2)))();
    ((void (*)()) (*(childVPtr + 4)))();
    
    int *childVPtr1 = *((int **) child + 2);
    ((void (*)()) (*(childVPtr1)))();
    ((void (*)()) (*(childVPtr1 + 2)))();

	return 0;
	
	
}
