#!/usr/bin/env python3

"""
Exercise 4: Garden Security System
Create a secure system that protects and encapsulates sensitive data.
"""


class SecurePlant:
    """A plant with protected data that validates all changes."""
    
    def __init__(self, name):
        """Initialize a secure plant with a name."""
        self.name = name
        self.__height = 0  # Private attribute
        self.__age = 0      # Private attribute
    
    def set_height(self, height):
        """Set the plant height with validation."""
        if height < 0:
            print(f"Invalid operation attempted: height {height}cm [REJECTED]")
            print("Security: Negative height rejected")
            return False
        self.__height = height
        print(f"Height updated: {height}cm [OK]")
        return True
    
    def set_age(self, age):
        """Set the plant age with validation."""
        if age < 0:
            print(f"Invalid operation attempted: age {age} days [REJECTED]")
            print("Security: Negative age rejected")
            return False
        self.__age = age
        print(f"Age updated: {age} days [OK]")
        return True
    
    def get_height(self):
        """Get the plant height."""
        return self.__height
    
    def get_age(self):
        """Get the plant age."""
        return self.__age
    
    def __str__(self):
        """String representation of the plant."""
        return f"{self.name} ({self.get_height()}cm, {self.get_age()} days)"


def ft_garden_security():
    """Main function demonstrating garden security system."""
    print("=== Garden Security System ===")
    
    # Create a secure plant
    plant = SecurePlant("Rose")
    print(f"Plant created: {plant.name}")
    
    # Valid operations
    plant.set_height(25)
    plant.set_age(30)
    
    # Invalid operation - negative height
    plant.set_height(-5)
    
    # Display current state
    print(f"Current plant: {plant}")


if __name__ == "__main__":
    ft_garden_security()
