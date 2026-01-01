def ft_harvest_total():
    day = 0
    for i in range(1, 4):
        day += int(input(f"Day {i} harvest: "))
    print(f"Total harvest: {day}")

ft_harvest_total()
