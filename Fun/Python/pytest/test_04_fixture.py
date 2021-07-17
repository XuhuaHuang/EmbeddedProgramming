# pytest fixtures: explicit, modular, scalable
# simple example of fixture in pytest
# Author: Xuhua Huang
#
# Last updated: July 16, 2021
# Created on: July 16, 2021
#

"""
Think of a test is being broken down into 4 steps
Arrange:    preparing everything for our test
Act:        singular, state-changing action that kicks off the behavior we want to test
Assert:     look at that resulting state and check if it looks how we’d expect after the dust has settled
Cleanup:    where the test picks up after itself
"""

import pytest
import typing


class Fruit:
    def __init__(self, name):
        self.name: str = name if name is not None else ""
        self.cubed: bool = False

    def __eq__(self, other):
        return self.name == other.name

    def cube(self) -> None:
        self.cubed: bool = True


class FruitSalad:
    def __init__(self, *fruit_bowl):
        self.fruit = fruit_bowl
        self._cube_fruit()

    def _cube_fruit(self) -> None:
        for fruit in self.fruit:
            fruit.cube()


@pytest.fixture
def my_fruit() -> Fruit:
    return Fruit("Apple")


# Arrange
@pytest.fixture
def fruit_basket(my_fruit: Fruit) -> list[Fruit]:
    return [Fruit("Banana"), my_fruit]


def test_my_fruit_in_basket(my_fruit, fruit_basket):
    """
    Run this test individually with the following command:
    python -m pytest [OPTIONAL: -q] test_04_fixture.py::test_my_fruit_in_basket
    """
    assert my_fruit in fruit_basket


# Arrange
@pytest.fixture
def fruit_bowl() -> list[Fruit]:
    return [Fruit("apple"), Fruit("banana")]


def test_fruit_salad(fruit_bowl):
    """
    Run this test individually with the following command:
    python -m pytest [OPTIONAL: -q] test_04_fixture.py::test_fruit_salad
    """
    # Act
    fruit_salad = FruitSalad(*fruit_bowl)

    # Assert
    assert all(fruit.cubed for fruit in fruit_salad.fruit)


"""
TODO: Autouse fixtures (fixtures you don’t have to request)
https://docs.pytest.org/en/6.2.x/fixture.html#autouse-fixtures-fixtures-you-don-t-have-to-request
"""
