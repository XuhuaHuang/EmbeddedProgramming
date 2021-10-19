#import <Foundation/Foundation.h>

/* Class Person Declaration */
@interface Person : NSObject
{
    NSString* _name;
    int _age;
}
/* Atomic Member Data */
@property NSString* _name;
@property int _age;

- (void) print;
@end
// the @property decorator equates to the following:
// {
// @private int _age;
// }
//
// - (void) setAge: (int) age;
// - (int) age;

/* Implementation of Property */
/* Equivalence of individual get and set member function */
@implementation Person

@synthesize _age = age;
@synthesize _name = name;

- (void) print {
    NSLog(@"Person class, %s, %d years old.\n", self.name, self.age);
    return;
}
@end // implementation Person


/* Class Professor Declaration */
@interface Professor : Person
{
    int _cur_id;
    int _publications;
}
@property int _cur_id;
@property int _publications;

- (void) print;
@end

@implementation Professor

@synthesize _cur_id = cur_id;
@synthesize _publications = publications;

- (void) print {
    [super print];
    NSLog(@"Professor class, %s, %d years old, with %d publications.\n", self.name, self.age, self.publications);
    // Using `pointer._data_attribute` syntac to implictly call getter
    return;
}
@end // implementation Professor

/* Main Function */
int main(int argc, const char* argv[]) {

    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];

    Person* p = [[Person alloc] init];
    [p setName: (NSString)"Xuhua Huang"];
    [p setAge: 20]; // equates to: p->setAge(20) in C++.
    [p print];      // equates to: p->print() in C++.

    NSLog(@"-----------------------------------------------------------------");

    Professor* prof = [[Professor alloc] init];
    [prof setName: (NSString)"Charmaine Jirgens"];
    [prof setAge: 40];
    [prof setPublications: 15];
    [prof print];

    [pool drain];

    return 0;
}
