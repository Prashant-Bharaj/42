#!/usr/bin/env python3

"""
Exercise 3: Plant Factory
Streamline the plant creation process and initialize them properly.
"""


class Plant:
    """A plant with name, height, and age."""
    
    def __init__(self, name, height, age):
        """Initialize a plant with name, starting height, and starting age."""
        self.name = name
        self.height = height
        self.age = age
    
    def __str__(self):
        """String representation of the plant."""
        return f"{self.name} ({self.height}cm, {self.age} days)"


def ft_plant_factory():
    """Main function demonstrating plant factory creation."""
    print("=== Plant Factory Output ===")
    
    # Create plants with different characteristics
    plants = [
        Plant("Rose", 25, 30),
        Plant("Oak", 200, 365),
        Plant("Cactus", 5, 90),
        Plant("Sunflower", 80, 45),
        Plant("Fern", 15, 120)
    ]
    
    # Display all created plants
    for plant in plants:
        print(f"Created: {plant}")
    
    # Show total count
    print(f"Total plants created: {len(plants)}")


if __name__ == "__main__":
    ft_plant_factory()
