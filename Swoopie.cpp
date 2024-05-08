#include "Swoopie.h"

Swoopie::Swoopie()
{
    // Initialize Swoopie-specific attributes here, if any
}

Swoopie::Swoopie(World *world, int x, int y) : Organism(world, x, y)
{
    // Additional initialization for Swoopie-specific attributes here, if any
}

Swoopie::~Swoopie()
{
    // Destruction/cleanup logic specific to Swoopie goes here, if any
}

// Breed. If a Swoopie survives for eight time steps, 
// then at the end of the time step it will spawn off a new Swoopie in the same manner as the Zoomie.
void Swoopie::breed()
{
    // Implementation of Swoopie's breeding logic here
}

// Move. Every time step, if there is an adjacent Zoomie (up, down, left, or right), 
// then the Swoopie will move to that cell and eat the Zoomie. 
// Otherwise, the Swoopie moves according to the same rules as the Zoomies.
// Note that a Swoopie cannot eat other Swoopies.
void Swoopie::move()
{
    // Implementation of Swoopie's movement logic here
}

int Swoopie::getType()
{
    // Return Swoopie-specific type identifier here
}

// Starve. If a Swoopie has not eaten a Zoomie within the last three time steps, 
// then at the end of the third time step it will starve and die. 
// The Swoopie should then be removed from the grid of cells.
bool Swoopie::starve()
{
    // Implementation of Swoopie's starvation logic here
}
