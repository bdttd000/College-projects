import random

def number_of_sections(l):
    return pow(2, l) - 1

def distance(start, end):
    return abs(end-start)

def get_step(start, end, l):
    return distance(start, end)/number_of_sections(l)

def get_coord(x, start, end, l):
    return x*(get_step(start, end, l))+start

def decimal_to_binary(l):
    return "{0:0"+str(l)+"b}"

def create_binary(x, l):
    return decimal_to_binary(l).format(x)

def nearest_point(x, start, end, l):
    temp = int(distance(start, x) / get_step(start, end, l))
    if distance(start, x) - temp * get_step(start, end, l) > get_step(start, end, l) / 2:
        temp += 1
    return temp

def code(a, b, c, d, l):
    first_point = random.uniform(a, b)
    second_point = random.uniform(c, d)
    print(f'Drawn point (x:{first_point}, y:{second_point})')
    first_point_nearest = nearest_point(first_point, a, b, l)
    second_point_nearest = nearest_point(second_point, c, d, l)
    print(f'Found point (x: {get_coord(first_point_nearest, a, b, l)}, y: {get_coord(second_point_nearest, c, d, l)})')
    print(f'Found point (binary): {decimal_to_binary(l).format(first_point_nearest)+decimal_to_binary(l).format(second_point_nearest)}')

def decode(a, b, c, d, l):
    first_point = random.randint(0, pow(2, l) - 1)
    second_point = random.randint(0, pow(2, l) - 1)
    first_point_binary = create_binary(first_point, l)
    second_point_binary = create_binary(second_point, l)
    print(f'Wylosowany łańcuch binarny: {first_point_binary+second_point_binary}')
    print(f'Znaleziony punkt: (x: {get_coord(first_point, a, b, l)}, y: {get_coord(second_point, c, d, l)})')

def print_menu():
    print("Choose one:")
    print("1: Code")
    print("2: Decode")
    print("3: Finish")

def main():

    print("Insert ends of rages for x and y ([a, b]x[c, d]) and length of binary form l")
    a = float(input("Insert a: "))
    b = float(input("Insert b: "))
    c = float(input("Insert c: "))
    d = float(input("Insert d: "))
    l = int(input("Insert l: "))

    while 1:
        print("\n")
        print_menu()
        o = input("Insert number: ")
        print("\n")

        if o == '1':
            print("1 - Code")
            code(a, b, c, d, l)
        elif o == '2':
            print("2 - Decode")
            decode(a, b, c, d, l)
        else:
            print("Finish")
            return
        input("Press anything to continue...")

if __name__ == "__main__":
    main()
