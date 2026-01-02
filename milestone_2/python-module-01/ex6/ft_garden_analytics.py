#!/usr/bin/env python3

"""
Exercise 6: Garden Analytics
Build a comprehensive garden data analytics platform with complex relationships.
"""


class Plant:
    """Base plant class."""
    
    def __init__(self, name, height):
        """Initialize a plant with name and height."""
        self.name = name
        self.height = height
    
    def grow(self):
        """Grow the plant by 1cm."""
        self.height += 1
        print(f"{self.name} grew 1cm")
    
    def __str__(self):
        """String representation of the plant."""
        return f"{self.name}: {self.height}cm"


class FloweringPlant(Plant):
    """A plant that can flower."""
    
    def __init__(self, name, height, color):
        """Initialize a flowering plant."""
        super().__init__(name, height)
        self.color = color
        self.is_blooming = True
    
    def __str__(self):
        """String representation of the flowering plant."""
        status = "blooming" if self.is_blooming else "not blooming"
        return f"{self.name}: {self.height}cm, {self.color} flowers ({status})"


class PrizeFlower(FloweringPlant):
    """A prize-winning flower with points."""
    
    def __init__(self, name, height, color, prize_points):
        """Initialize a prize flower."""
        super().__init__(name, height, color)
        self.prize_points = prize_points
    
    def __str__(self):
        """String representation of the prize flower."""
        base = super().__str__()
        return f"{base}, Prize points: {self.prize_points}"


class GardenManager:
    """Manages multiple gardens with analytics."""
    
    class GardenStats:
        """Nested class for calculating garden statistics."""
        
        @staticmethod
        def count_plant_types(plants):
            """Count different types of plants."""
            regular = sum(1 for p in plants if isinstance(p, Plant) and not isinstance(p, FloweringPlant))
            flowering = sum(1 for p in plants if isinstance(p, FloweringPlant) and not isinstance(p, PrizeFlower))
            prize = sum(1 for p in plants if isinstance(p, PrizeFlower))
            return regular, flowering, prize
        
        @staticmethod
        def calculate_total_growth(plants):
            """Calculate total growth (simplified - just count plants)."""
            return len(plants)
    
    _total_gardens = 0  # Class variable to track total gardens
    
    def __init__(self, owner_name):
        """Initialize a garden for an owner."""
        self.owner_name = owner_name
        self.plants = []
        self.initial_heights = {}  # Track initial heights for growth calculation
        GardenManager._total_gardens += 1
    
    def add_plant(self, plant):
        """Add a plant to the garden."""
        self.plants.append(plant)
        self.initial_heights[plant.name] = plant.height
        print(f"Added {plant.name} to {self.owner_name}'s garden")
    
    def grow_all(self):
        """Grow all plants in the garden."""
        print(f"{self.owner_name} is helping all plants grow...")
        for plant in self.plants:
            plant.grow()
    
    def generate_report(self):
        """Generate a comprehensive garden report."""
        print(f"=== {self.owner_name}'s Garden Report ===")
        print("Plants in garden:")
        for plant in self.plants:
            print(f"- {plant}")
        
        # Calculate statistics
        total_growth = sum(plant.height - self.initial_heights.get(plant.name, plant.height) 
                          for plant in self.plants)
        regular, flowering, prize = self.GardenStats.count_plant_types(self.plants)
        
        print(f"Plants added: {len(self.plants)}, Total growth: {total_growth}cm")
        print(f"Plant types: {regular} regular, {flowering} flowering, {prize} prize flowers")
    
    @staticmethod
    def validate_height(height):
        """Static method to validate plant height."""
        return height > 0
    
    @classmethod
    def create_garden_network(cls, gardens):
        """Class method to create a network of gardens and calculate scores."""
        print("Garden scores - ", end="")
        scores = []
        for garden in gardens:
            # Calculate garden score based on plants
            score = sum(plant.height for plant in garden.plants)
            scores.append(f"{garden.owner_name}: {score}")
        print(", ".join(scores))
        return gardens
    
    @classmethod
    def get_total_gardens(cls):
        """Get the total number of gardens managed."""
        return cls._total_gardens


def ft_garden_analytics():
    """Main function demonstrating garden analytics platform."""
    print("=== Garden Management System Demo ===")
    
    # Create gardens
    alice_garden = GardenManager("Alice")
    bob_garden = GardenManager("Bob")
    
    # Add plants to Alice's garden
    oak = Plant("Oak Tree", 100)
    rose = FloweringPlant("Rose", 25, "red")
    sunflower = PrizeFlower("Sunflower", 50, "yellow", 10)
    
    alice_garden.add_plant(oak)
    alice_garden.add_plant(rose)
    alice_garden.add_plant(sunflower)
    
    # Grow all plants
    alice_garden.grow_all()
    
    # Generate report
    alice_garden.generate_report()
    
    # Test height validation
    print(f"Height validation test: {GardenManager.validate_height(50)}")
    
    # Add plants to Bob's garden
    bob_garden.add_plant(Plant("Fern", 20))
    bob_garden.add_plant(FloweringPlant("Tulip", 15, "pink"))
    
    # Create garden network
    GardenManager.create_garden_network([alice_garden, bob_garden])
    
    # Show total gardens
    print(f"Total gardens managed: {GardenManager.get_total_gardens()}")


if __name__ == "__main__":
    ft_garden_analytics()
