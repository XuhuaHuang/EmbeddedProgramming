*Things to Remember*  
> Declare *public virtual destructor* __if and only if__ the base class implements at least one virtual function.  
  
> Use the right pair of constructor-destructor pair if class contains pointer member:  
  *new* with *delete*  
  *new []* (char* / string*) with *delete []*
