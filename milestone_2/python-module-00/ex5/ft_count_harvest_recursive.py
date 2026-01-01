def ft_helper(n, days):
    if(n > 1):
        ft_helper(n-1, days)
    print(f"Day {n}")

def ft_count_harvest_recursive():
    days = int(input("Days until harvest: "))
    ft_helper(days, days)
    print("Harvest time!")

ft_count_harvest_recursive()
