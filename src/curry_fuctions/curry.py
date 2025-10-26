def curry(func, arity):
    if not isinstance(arity, int):
        raise TypeError(f"Expected arity type: int, received {type(arity).__name__}")

    if arity < 0:
        raise ValueError(f"Expected arity >= 0, received {arity}")

    def collect_args(collected_args):
        def wrapper(next_arg):
            if len(collected_args) + 1 > arity:
                raise TypeError(f"""Too many arguments. Expected {arity},
                    got {len(collected_args) + 1}""")
                
            new_args = collected_args + (next_arg,)
            
            if len(new_args) == arity:
                return func(*new_args)
            else:
                return collect_args(new_args)
        return wrapper
    
    return collect_args(())

def uncurry(func, arity):
    if not isinstance(arity, int):
        raise TypeError(f"Expected arity type: int, received {type(arity).__name__}")

    if arity < 0:
        raise ValueError(f"Expected arity >= 0, received {arity}")

    def wrapper(*args):
        if len(args) != arity:
            raise TypeError(f"Expected {arity} arguments, got {len(args)}")

        result = func
        for arg in args:
            result = result(arg)
        return result
    return wrapper

