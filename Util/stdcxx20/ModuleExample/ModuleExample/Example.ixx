// Example.ixx
export module Example;

#define ANSWER 42

namespace Example_NS
{
    int fn_internal(void) {
        return ANSWER;
    }

    export int fn(void) {
        return fn_internal();
    }
}
