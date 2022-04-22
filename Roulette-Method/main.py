import random
import math


def fitness(x, y):
    return 20 + x**2 + y**2 - 10 * (math.cos(2 * math.pi * x) + math.cos(2 * math.pi * y))


def roulette(population):
    fitness_results = [fitness(x, y) for x, y in population]
    return random.choices(population, weights=fitness_results, k=pop)


def main():
    population = [(random.uniform(-5.12, 5.12), random.uniform(-5.12, 5.12)) for _ in range(pop)]
    print("Wygenerowana populacja: ", population)
    population = roulette(population)
    print("Populacja po zastosowaniu metody ruletki: ", population)


pop = int(input("Podaj zmienną liczebności populacji (pop): "))
if pop > 0:
    main()
else:
    print("Podano niepoprawna wartosc")
