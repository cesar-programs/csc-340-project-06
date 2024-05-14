#include "Predator.h"

Predator::Predator()
{
    // Initialize Predator-specific attributes here, if any
}

Predator::Predator(World *world, int x, int y) : Organism(world, x, y)
{
    // Additional initialization for Predator-specific attributes here, if any
}

Predator::~Predator()
{
    // Destruction/cleanup logic specific to Predator goes here, if any
}

// Breed. If a Predator survives for eight time steps,
// then at the end of the time step it will spawn off a new Predator in the same manner as the Prey.
void Predator::breed()
{
    // Implementation of Predator's breeding logic here
}

// Move. Every time step, if there is an adjacent Prey (up, down, left, or right),
// then the Predator will move to that cell and eat the Prey.
// Otherwise, the Predator moves according to the same rules as the Zoomies.
// Note that a Predator cannot eat other Swoopies.
void Predator::move()
{
    // Implementation of Predator's movement logic here
}

int Predator::getType()
{
    // Return Predator-specific type identifier here
    return 2;
}

// Starve. If a Predator has not eaten a Prey within the last three time steps,
// then at the end of the third time step it will starve and die. 
// The Predator should then be removed from the grid of cells.
bool Predator::starve()
{

    // Implementation of Predator's starvation logic here
}

