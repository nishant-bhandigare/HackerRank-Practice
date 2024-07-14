if __name__ == '__main__':
    N = int(input())
    
    my_list = []
    
    for i in range(0, N):
        
        command = input()
        command_list = command.split(" ")
        
        if command_list[0] == "insert":
            my_list.insert(int(command_list[1]), int(command_list[2]))
        elif command_list[0] == "print":
            print(my_list)
        elif command_list[0] == "remove":
            my_list.remove(int(command_list[1]))
        elif command_list[0] == "append":
            my_list.append(int(command_list[1]))
        elif command_list[0] == "sort":
            my_list.sort()
        elif command_list[0] == "pop":
            my_list.pop(len(my_list)-1)
        elif command_list[0] == "reverse":
            my_list.reverse()
