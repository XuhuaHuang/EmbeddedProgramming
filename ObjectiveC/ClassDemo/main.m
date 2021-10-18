#import <Foundation/Foundation.h>
#import "Person.h"

int main(int argc, char* argv[])
{
    // @autoreleasepool {
    //     Person* p = [[Person alloc] init];
    //     [p print]; // calling Person::print() member function on object p
    // }
    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
    Person* p = [[Person alloc] init];
    [p print]; // calling Person::print() member function on object p
	[pool drain];

    return 0;
}
