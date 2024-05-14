#include "Prey.h"

Prey::Prey()
{
    // Initialize Prey-specific attributes here, if they exist
}

Prey::Prey(World *world, int x, int y) : Organism(world, x, y)
{
    // Additional initialization for Prey-specific attributes here, if they exist
}

Prey::~Prey()
{
    // Destruction/cleanup logic specific to Prey goes here, if needed
}

// Breed. If a Prey survives for three time steps,
// then at the end of the time step (that is, after moving) the Prey will breed.
// This is simulated by creating a new Prey in an adjacent (up, down, left, or right) cell that is empty.
// If there is no empty cell available, then no breeding occurs. 
// Once an offspring is produced,  a Prey cannot produce an offspring until three more time steps have elapsed.
void Prey::breed()
{
    // Implementation of Prey's breeding logic here
}

// Move. At every time step, randomly try to move up, down, left, or right. 
// If the neighboring cell in the selected direction is occupied or would
// move the Prey off the grid, then the Prey stays in the current cell.
void Prey::move()
{
    // Implementation of Prey's movement logic here
}

int Prey::getType()
{
    // Return Prey-specific type identifier here
    return 1;
}

bool Prey::starve()
{
    // Implementation of Prey's starvation logic here, if needed
    // If Prey does not starve (since it's prey), this method might not be necessary and can even be removed
}
