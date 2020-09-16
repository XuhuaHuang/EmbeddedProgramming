#include <iostream>
using namespace std;

typedef struct shape
{	
	string type;
	int length;
	int width;
	int radius;	

}SHAPE; // Through structure, a datatype named SHAPE is created

void initShape(SHAPE *shape);
void printShape(SHAPE s);
void setShape(SHAPE *s, string str, int l, int w, int r);

int main(void)
{
	SHAPE userShape;
	// variable "userShape" has the structure of shape
	// "userShape" is expected to contain information of type, l, w and r
	
	string type;
	int length;
	int width;
	int radius;
	
	cout << "\nInitializing..." << endl;
	
	initShape(&userShape); // initializing userShape
	printShape(userShape); // printing the initialized userShape
	
	
	cout << "\nEnter a type of ideal shape." << endl;
	cin >> type;
	
	cout << "Enter the length of the shape." << endl;
	cin >> length;
	
	cout << "Enter the width of the shape." << endl;
	cin >> width;
	
	cout << "Enter the ridus of the shape." << endl;
	cin >> radius;
	
	
	setShape(&userShape, type, length, width, radius); // not sending the type
	printShape(userShape); // verify the values have been changed

	
	return 0;
}


void initShape(SHAPE *s)
{
	s->type = "UNKNOWN";
	
	s->length = 0;
	s->width = 0;
	s->radius = 0;
}


void printShape(SHAPE s)
{
	cout << "\nThe specs of the ideal shape are listed as the following." << endl;
	cout << "The type of the shape is " << s.type << endl;
	cout << "The length of the shape is " << s.length << endl;
	cout << "The width of the shape is " << s.width << endl;
	cout << "The radius of the shape is " << s.radius << endl;
	cout << "List of specs end here." << endl;
}


void setShape(SHAPE *s, string str, int l, int w, int r) // receive with type
{
	s->type = str;
	
	s->length = l;
	s->width = w;
	s->radius = r;
}
