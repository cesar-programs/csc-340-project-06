#include "Zoomie.h"

Zoomie::Zoomie()
{
    // Initialize Zoomie-specific attributes here, if they exist
}

Zoomie::Zoomie(World *world, int x, int y) : Organism(world, x, y)
{
    // Additional initialization for Zoomie-specific attributes here, if they exist
}

Zoomie::~Zoomie()
{
    // Destruction/cleanup logic specific to Zoomie goes here, if needed
}

// Breed. If a Zoomie survives for three time steps, 
// then at the end of the time step (that is, after moving) the Zoomie will breed. 
// This is simulated by creating a new Zoomie in an adjacent (up, down, left, or right) cell that is empty. 
// If there is no empty cell available, then no breeding occurs. 
// Once an offspring is produced,  a Zoomie cannot produce an offspring until three more time steps have elapsed.
void Zoomie::breed()
{
    // Implementation of Zoomie's breeding logic here
}

// Move. At every time step, randomly try to move up, down, left, or right. 
// If the neighboring cell in the selected direction is occupied or would
// move the Zoomie off the grid, then the Zoomie stays in the current cell.
void Zoomie::move()
{
    // Implementation of Zoomie's movement logic here
}

int Zoomie::getType()
{
    // Return Zoomie-specific type identifier here
    return 1;
}

bool Zoomie::starve()
{
    // Implementation of Zoomie's starvation logic here, if needed
    // If Zoomie does not starve (since it's prey), this method might not be necessary and can even be removed 
}
