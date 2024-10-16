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
@interface Person : NSObject {
@private
    NSString* _name;
    int _age;
} // end protected member attribute wrapper
// by default, the access modifier is `protected`

/* Prototype of member functions. */
- (void) setName: (NSString*) name;
- (NSString*) name;
- (void) setAge:(int) age;
- (int) age;
- (void) print;

@end // end class declaration

/* Person Class Implementation */
@implementation Person

- (void) setName: (NSString*) name {
    self->_name = name;
}

- (NSString*) name {
    return self->_name;
}

- (void) setAge: (int) age {
    self->_age = age;
}

- (int) age {
    return self->_age;
}

- (void) print {
    NSLog(@"%s is of age %d", self.name, self.age);
    // self.age syntax equates to calling the getter for the object
    // in this case, self->age()
}

@end

int main(int argc, const char* argv[])
{
    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];

    Person* p = [[Person alloc] init];
    [p setName: (NSString*) "Xuhua Huang"];
    [p setAge: 20]; // equates to: p->setAge(20) in C++.
    [p print];      // equates to: p->print() in C++.

    int p_age = [p age];
    NSLog(@"Testing Person::age() member function.\nThis person is of age %d", p_age);

    [pool drain];
    return 0;
}
