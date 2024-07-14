if __name__ == '__main__':
    n = int(input())
    student_marks = {}
    for _ in range(n):
        name, *line = input().split()
        scores = list(map(float, line))
        student_marks[name] = scores
    query_name = input()
    
    total = 0
    for marks in student_marks[query_name]:
        total = total + marks
        
    average = "{:.2f}".format(total/3)
    
    print(average)