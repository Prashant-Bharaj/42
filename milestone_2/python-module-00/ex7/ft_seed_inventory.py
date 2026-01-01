def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
    unit_str = f"{quantity} Unknown unit type"
    if(unit == "packets"):
        unit_str = f"{quantity} packets available"
    elif (unit == "grams"):
        unit_str = f"{quantity} grams total"
    elif(unit == "area"):
        unit_str = f"covers {quantity} square meters"
    print(f"{seed_type} seeds: {unit_str}")

ft_seed_inventory("he", 3, "grams")
ft_seed_inventory("area", 4, "area")
ft_seed_inventory("un", 2, "un")
