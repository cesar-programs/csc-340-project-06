#include "Prey.h"

#include <cstdlib>
#include <cmath>
#include <utility>
#include <vector>

Prey::Prey()
{
    // Initialize Prey-specific attributes here, if they exist
}

Prey::Prey(World *world, int x, int y) : Organism(world, x, y)
{
    Prey::breedUpperBound = 3;
    world->setAt(x, y, this);
    world->pushPrey(this);
}

Prey::~Prey()
{
    std::cout << "Prey getting eaten at (" << this->x << ", " << this->y << ")!" << std::endl;
    world->setAt(this->x, this->y, nullptr);
    world->removePrey(this);
}

// Breed. If a Prey survives for three time steps,
// then at the end of the time step (that is, after moving) the Prey will breed.
// This is simulated by creating a new Prey in an adjacent (up, down, left, or right) cell that is empty.
// If there is no empty cell available, then no breeding occurs. 
// Once an offspring is produced,  a Prey cannot produce an offspring until three more time steps have elapsed.
void Prey::breed()
{
    std::vector<std::pair<int, int>> adjacentCells = {
        std::make_pair(this->x, this->y + 1),
        std::make_pair(this->x, this->y - 1),
        std::make_pair(this->x + 1, this->y),
        std::make_pair(this->x - 1, this->y)
    };

    while (breedTicks >= 3) {

        int random = rand() % adjacentCells.size();
        int newX = adjacentCells[random].first;
        int newY = adjacentCells[random].second;

        if (newX >= 0 
                && newX < world->WORLDSIZE 
                && newY >= 0 
                && newY < world->WORLDSIZE
                && world->getAt(newX, newY) == nullptr) {
            world->setAt(newX, newY, new Prey(world, newX, newY));
            breedTicks = 0;
            return;
        } else {
            adjacentCells[random] = adjacentCells[adjacentCells.size() - 1];
            adjacentCells.pop_back();

            if (adjacentCells.size() == 0) {
                breedTicks = 0;
                return;
            }
        }
    }

    breedTicks++;
}

// Move. At every time step, randomly try to move up, down, left, or right. 
// If the neighboring cell in the selected direction is occupied or would
// move the Prey off the grid, then the Prey stays in the current cell.
void Prey::move()
{
    Organism::move();
}

int Prey::getType()
{
    return 1;
}

bool Prey::starve()
{
    return false;
}