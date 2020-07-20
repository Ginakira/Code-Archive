def People(name="HCZ", age=20, height=0.0, *args, **kwargs):
    print("%s is %d year old, and %s m" % (name, age, height))
    print("Args : %s" % str(args))
    print("Keyword args : %s" % str(kwargs))


def People2(*args):
    print(args)


print("All default params")
People()

print("Age - normal params")
People(name="Hello kitty", height=12.3)

print("*args")
People("haizeix", 1, 55, 44, "hello world")

print("*kwargs")
People("haizeix", 1, 55, 44, "hello world", default_value=123, value2="important")
