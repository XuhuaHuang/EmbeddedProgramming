def scope_test():
    def do_local():
        spam = "local spam"

    def do_nonlocal():
        nonlocal spam
        spam = "nonlocal spam"

    def do_global():
        global spam
        spam = "global spam"

    spam = "test spam"
    do_local()
    print("After local assignment:", spam)  # test spam
    do_nonlocal()
    print("After nonlocal assignment:", spam)  # nonlocal spam
    do_global()
    print("After global assignment:", spam)  # nonlocal spam


scope_test()
print("In global scope:", spam)  # global spam
