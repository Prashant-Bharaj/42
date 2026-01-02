#!/usr/bin/env python3

"""
Exercise 2: Plant Growth
Track plant growth over time and calculate weekly growth.
"""


class Plant:
    """A plant that can grow over time."""
    
    def __init__(self, name, height, age):
        """Initialize a plant with name, height, and age."""
        self.name = name
        self.height = height
        self.age = age
    
    def grow(self, days=1):
        """Grow the plant by increasing height and age."""
        self.height += days
        self.age += days
    
    def __str__(self):
        """String representation of the plant."""
        return f"{self.name}: {self.height}cm, {self.age} days old"


def ft_plant_growth():
    """Main function demonstrating plant growth over time."""
    # Create a plant
    rose = Plant("Rose", 25, 30)
    
    # Day 1
    print("=== Day 1 ===")
    print(rose)
    
    # Grow for 6 more days (total 7 days)
    rose.grow(6)
    
    # Day 7
    print("=== Day 7 ===")
    print(rose)
    
    # Calculate growth this week
    initial_height = 25
    current_height = rose.height
    growth = current_height - initial_height
    print(f"Growth this week: +{growth}cm")


if __name__ == "__main__":
    ft_plant_growth()
