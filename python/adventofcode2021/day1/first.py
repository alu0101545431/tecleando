def DepthCounter(input_file):
    depth_list = input_file.readlines()
    last_depth = 0
    counter = 0
    for depth in depth_list:
        if depth > last_depth:
            ++counter
        last_depth = depth
    
    print(f'The amount of times the depth increased is: {depth}')

    
