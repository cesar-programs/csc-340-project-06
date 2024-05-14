/**
 * @file Swoopie.h
 * @brief Defines the Swoopie class, a type of Organism and a predator in the World grid.
 *
 * @class Swoopie
 *
 * @details Swoopie is a concrete implementation of the Organism class. It populates the World grid 
 * and follows a specific set of rules for movement, breeding, and starvation - reflecting its behavior as a predator.
 */

#include "Organism.h"
#include <vector>

class Swoopie : public Organism
{
public:
	Swoopie();
	Swoopie(World *world, int x, int y);
	virtual ~Swoopie();

	// Implementing Organism's pure virtual functions
	virtual void breed() override;
	virtual void move() override;
	virtual int getType() override;
	virtual bool starve() override;
	
	// You can add more Swoopie-specific methods here if needed

protected:
	// Swoopie-specific variables can go here, if any

};
