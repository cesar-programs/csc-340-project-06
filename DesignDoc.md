# DesignDoc for `simulateOneStep` Functions, Team 21 - Avinh Huynh, Randolf Uy, and Cesar A. Herrera

## Overview

The `simulateOneStep` functions are responsible for simulating a single step in the environment for different types of
organisms.
These functions handle the movement, interaction, and state changes of organisms such as predators and prey within a
simulated world.

## Input

- **World State**: The current state of the world, which includes the grid or space where organisms live, and the
  positions of all organisms.
- **Organism State**: The current state of the organism, including its position, how long it has lived, and any other
  relevant attributes.

## Output

- **Updated World State**: The state of the world after the simulation step, including updated positions and states of
  all organisms.
- **Updated Organism State**: The state of the organism after the simulation step, reflecting any changes due to
  movement, interaction, or state transitions.

## Algorithm

The `simulateOneStep` function follows these general steps:

1. **Check Surroundings**: Determine the organisms and empty spaces around current organism (up, down, left, right).
2. **Decide Action**: Based on the type of organism (predator or prey) and its current state, decide the action to
   take (move, eat, reproduce, etc.).
3. **Execute Action**:
    - **Move**: Update the position of the organism within the world.
    - **Interact**: If the organism interacts with another (e.g., predator eats prey), update the state.
    - **Breed/Die**: If conditions are met, create a new organism in the world or remove an organism (death).
4. **Update State**: Modify the organism's state to reflect changes due to the action taken (e.g., increase hunger,
   increase age, decrease hunger).
5. **Return Updated States**: Provide the updated world and organism states for the next simulation step.

### Detailed Algorithm for Predator

1. **Check Surroundings**:
    - Look for prey in adjacent cells.
    - Identify empty cells for potential movement.
2. **Decide Action**:
    - If prey is found, move to the prey's cell and eat it.
    - If no prey is found, move to a random adjacent empty cell.
3. **Execute Action**:
    - **Move**: Update the predator's position.
    - **Eat**: Set starvation counter to zero and remove the prey from the world.
    - **Reproduce**: If conditions are met (lived 8 rounds), create a new predator.
4. **Update State**: Increase age (or reset if just reproduced), increase or decrease hunger.
5. **Return Updated States**: Provide the new world state and predator state.

### Detailed Algorithm for Prey

1. **Check Surroundings**:
    - Identify empty cells for potential movement.
2. **Decide Action**:
    - Move to a random adjacent empty cell.
3. **Execute Action**:
    - **Move**: Update the prey's position.
    - **Reproduce**: If conditions are met (lived 3 rounds), create a new prey.
4. **Update State**: Increase age if lived.
5. **Return Updated States**: Provide the new world state and prey state.

## Time Complexity Analysis

### Predator `simulateOneStep`

1. **Check Surroundings**: O(1) - The number of surrounding cells is constant (up, down, left, right = 4 cells).
2. **Decide Action**: O(1) - Decisions are made based on a fixed number of conditions and actions.
3. **Execute Action**:
    - **Move**: O(1) - Updating the position of the organism is a constant time operation.
    - **Eat**: O(1) - Eating and updating the state of a single prey is constant time.
    - **Reproduce**: O(1) - Checking the condition and potentially adding a new predator is a constant time operation.
4. **Update State**: O(1) - Updating the age and hunger is a constant time operation.
5. **Return Updated States**: O(1) - Returning the updated states is a constant time operation.

**Total Time Complexity for Predator `simulateOneStep`: O(1)**

### Prey `simulateOneStep`

1. **Check Surroundings**: O(1) - The number of surrounding cells is constant (up, down, left, right = 4 cells).
2. **Decide Action**: O(1) - Decisions are made based on a fixed number of conditions and actions.
3. **Execute Action**:
    - **Move**: O(1) - Updating the position of the organism is a constant time operation.
    - **Reproduce**: O(1) - Checking the condition and potentially adding a new prey is a constant time operation.
4. **Update State**: O(1) - Updating the age is a constant time operation.
5. **Return Updated States**: O(1) - Returning the updated states is a constant time operation.

**Total Time Complexity for Prey `simulateOneStep`: O(1)**

### World `simulateOneStep`

O(n + m + WORLDSIZE^2)

Where:

n = number of predators
m = number of preys
WORLDSIZE = dimensions of the world grid
