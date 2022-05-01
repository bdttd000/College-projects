import random
import math

# ZMIENNE
print("Podaj końce przedziałów określoności dla x , y ([a, b]x[c, d]) oraz długość ciągu binarnego dla współrzędnej l")
a = float(input("Podaj wartość zmiennej a: "))
b = float(input("Podaj wartość zmiennej b: "))
c = float(input("Podaj wartość zmiennej c: "))
d = float(input("Podaj wartość zmiennej d: "))
l = int(input("Podaj wartość zmiennej l: "))
it_max = int(input("Podaj maksymalną liczbę iteracji: "))
p_mut = float(input("Podaj prawdopodobieństwo mutacji: "))
p_cros = float(input("Podaj prawdopodobieństwo krzyżowania: "))
pop = int(input("Podaj liczebność populacji: "))


# METODA SIATKI BINARNEJ
def distance(start, end):
    return abs(end-start)


def number_of_sections():
    return pow(2, l) - 1


def get_step_x():
    return distance(a, b)/number_of_sections()


def get_step_y():
    return distance(c, d)/number_of_sections()


def decimal_to_binary():
    return "{0:0"+str(l)+"b}"


def nearest_point_x(x):
    temp = int(distance(a, x)/get_step_x())
    if distance(a, temp) - temp * get_step_x() > get_step_x() / 2:
        temp += 1
    return temp


def nearest_point_y(x):
    temp = int(distance(c, x)/get_step_y())
    if distance(c, temp) - temp * get_step_y() > get_step_y() / 2:
        temp += 1
    return temp


def to_float(num, a, b):
    return a + int(num, 2) * (b-a)/(2**len(num)-1)


def code(population):
    for i in range(len(population)):
        temp_x = population[i][0]
        temp_y = population[i][1]
        first_point_nearest = nearest_point_x(temp_x)
        second_point_nearest = nearest_point_y(temp_y)
        coded = decimal_to_binary().format(first_point_nearest)+decimal_to_binary().format(second_point_nearest)
        population[i] = coded


def decode(population):
    for i in range(len(population)):
        number = population[i]
        temp_x = to_float(number[:len(number)//2], a, b)
        temp_y = to_float(number[len(number)//2:], c, d)
        decoded = [temp_x, temp_y]
        population[i] = decoded


# METODA RULETKI
def population(pop):
    return [(random.uniform(a, b), random.uniform(c, d)) for _ in range(pop)]


def fitness(x, y):
    return 20 + x**2 + y**2 - 10 * (math.cos(2 * math.pi * x) + math.cos(2 * math.pi * y))


def roulette(popul):
    field = [fitness(x, y) for x, y in popul]
    return random.choices(popul, weights=field, k=len(popul))


# ALOGORYTM GENETYCZNY
def mutate(p):
    temp = random.randint(0, len(p) - 1)
    mutation = "1"
    if p[temp] == "1":
        mutation = "0"
    return p[:temp] + mutation + p[temp + 1:]


def crossover():
    global population
    if pop > 2:
        temp = random.sample(range(pop - 1), 2)
    else:
        temp = [0, 1]
    point = random.randint(0, len(population[0]) - 1)
    temp_2 = population[temp[0]][point:]
    population[temp[0]] = population[temp[0]][:point] + population[temp[1]][point:]
    population[temp[1]] = population[temp[1]][:point] + temp_2


population = population(pop)
print("\nWylosowana populacja: ", population)


def main():
    global population
    for it in range(it_max):
        population = roulette(population)
        code(population)
        for p in range(len(population)):
            if random.random() < p_mut:
                population[p] = mutate(population[p])
        crossover()
        decode(population)
        print("Populacja po", it+1, "iteracji: ", population)
    pass


if __name__ == "__main__":
    main()
