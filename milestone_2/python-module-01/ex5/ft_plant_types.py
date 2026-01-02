#!/usr/bin/env python3

"""
Exercise 5: Specialized Plant Types
Create different types of plants with unique characteristics using inheritance.
"""


class Plant:
    """Base plant class with common features."""
    
    def __init__(self, name, height, age):
        """Initialize a plant with name, height, and age."""
        self.name = name
        self.height = height
        self.age = age


class Flower(Plant):
    """A flowering plant with color and bloom capability."""
    
    def __init__(self, name, height, age, color):
        """Initialize a flower using parent class and add color."""
        super().__init__(name, height, age)
        self.color = color
    
    def bloom(self):
        """Make the flower bloom."""
        print(f"{self.name} is blooming beautifully!")
    
    def __str__(self):
        """String representation of the flower."""
        return f"{self.name} (Flower): {self.height}cm, {self.age} days, {self.color} color"


class Tree(Plant):
    """A tree with trunk diameter and shade production."""
    
    def __init__(self, name, height, age, trunk_diameter):
        """Initialize a tree using parent class and add trunk diameter."""
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter
    
    def produce_shade(self):
        """Calculate and display shade area."""
        # Simple calculation: shade area based on height and trunk diameter
        shade_area = (self.height / 10) * (self.trunk_diameter / 10)
        print(f"{self.name} provides {shade_area:.0f} square meters of shade")
    
    def __str__(self):
        """String representation of the tree."""
        return f"{self.name} (Tree): {self.height}cm, {self.age} days, {self.trunk_diameter}cm diameter"


class Vegetable(Plant):
    """A vegetable with harvest season and nutritional value."""
    
    def __init__(self, name, height, age, harvest_season, nutritional_value):
        """Initialize a vegetable using parent class and add harvest info."""
        super().__init__(name, height, age)
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value
    
    def __str__(self):
        """String representation of the vegetable."""
        return f"{self.name} (Vegetable): {self.height}cm, {self.age} days, {self.harvest_season} harvest"
    
    def display_nutrition(self):
        """Display nutritional information."""
        print(f"{self.name} is rich in {self.nutritional_value}")


def ft_plant_types():
    """Main function demonstrating specialized plant types."""
    print("=== Garden Plant Types ===")
    
    # Create flowers
    rose = Flower("Rose", 25, 30, "red")
    tulip = Flower("Tulip", 20, 15, "yellow")
    
    # Create trees
    oak = Tree("Oak", 500, 1825, 50)
    maple = Tree("Maple", 300, 1095, 30)
    
    # Create vegetables
    tomato = Vegetable("Tomato", 80, 90, "summer", "vitamin C")
    carrot = Vegetable("Carrot", 15, 60, "fall", "beta-carotene")
    
    # Display all plants
    print(rose)
    rose.bloom()
    
    print(oak)
    oak.produce_shade()
    
    print(tomato)
    tomato.display_nutrition()


if __name__ == "__main__":
    ft_plant_types()
