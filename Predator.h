/**
 * @file Predator.h
 * @brief Defines the Predator class, a type of Organism and a predator in the World grid.
 *
 * @class Predator
 *
 * @details Predator is a concrete implementation of the Organism class. It populates the World grid
 * and follows a specific set of rules for movement, breeding, and starvation - reflecting its behavior as a predator.
 */

#include "Organism.h"
#include <vector>

class Predator : public Organism
{
public:
	Predator();
	Predator(World *world, int x, int y);
	~Predator();

	// Implementing Organism's pure virtual functions
	virtual void breed() override;
	virtual void move() override;
	virtual int getType() override;
	virtual bool starve() override;
	
	// You can add more Predator-specific methods here if needed

protected:
	// Predator-specific variables can go here, if any
	int starveTicks;
};
