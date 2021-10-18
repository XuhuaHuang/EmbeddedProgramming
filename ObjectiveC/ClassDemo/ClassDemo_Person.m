/* Provide basic demonstration of the Object-oriented perspective.
 * Definition of a class Person with getter and setter.
 *
 * Xuhua Huang
 * October 2021
 * 
 * gcc -I "C:\GNUstep\GNUstep\System\Library\Headers"\
 * -L "C:\GNUstep\GNUstep\System\Library\Libraries"\
 * -o person ClassDemo_Person.m -lobjc \
 * -lgnustep-base -fconstant-string-class=NSConstantString
 */

#import <Foundation/Foundation.h>

/* Person Class Declaration */
@interface Person : NSObject
{
    int _age;
} // end protected member attribute wrapper

/* Prototype of member functions. */
- (void) setAge:(int) age;
- (int) age;
- (void) print;

@end // end class declaration

/* Person Class Implementation */
@implementation Person

- (void) setAge: (int) age {
    self->_age = age;
}

- (int) age {
    return self->_age;
}

- (void) print {
    NSLog(@"This person is of age %d", self.age);
    // self.age syntax equates to calling the getter for the object
    // in this case, self->age()
}

@end

int main(int argc, const char* argv[])
{
    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];

    Person* p = [[Person alloc] init];
    [p setAge: 20]; // equates to: p->setAge(20) in C++.
    [p print];      // equates to: p->print() in C++.

    int p_age = [p age];
    NSLog(@"Testing Person::age() member function.\nThis person is of age %d", p_age);

    [pool drain];
    return 0;
}
