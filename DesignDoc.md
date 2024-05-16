# DesignDoc


## SimulateOneStep( ) Pseudocode

First, simulate the behavior of the Predators.

For each Predator:
1. Move
    - Check the adjacent cells for Prey
      - If Prey is found, 
        - Eat the Prey
          - Reset the Predator's starve tracker to 0
        - Move to the cell of the Prey
2. Breed
3. Starve

Next, simulate the behavior of the Prey.

For each Prey:
1. Move


