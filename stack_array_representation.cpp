#include <iostream>
  
using namespace std; 
  
#define CAPACITY 1000 
  
class mystack { 
    int top; 
  
public: 
    int arr[CAPACITY]; 
  
    mystack() 
	{ 
	top = -1; 
	} 
    bool push(char new_element); 
    char pop();  
    bool isEmpty(); 
}; 
  
bool mystack::push(char new_element) 
{ 
    if (top+1 >= CAPACITY) { 
        cout << "Stack Overflow"; 
        return false; 
    } 
    else { 
        arr[++top] = new_element;  
        return true; 
    } 
} 
  
char mystack::pop() 
{ 
    if (top == -1 ) { 
        cout << "Stack Underflow"; 
        return '$'; 
    } 
    else { 
        char x = arr[top--]; 
        return x; 
    } 
} 
  
bool mystack::isEmpty() 
{ 
    return (top < 0); 
} 
  
int main() 
{ 
    class mystack s; 
    s.push('a'); 
    s.push('b'); 
    s.push('c'); 
    cout << s.pop() << " Popped from stack\n"; 
  
    return 0; 
} 
