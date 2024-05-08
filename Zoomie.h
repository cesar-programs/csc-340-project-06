/**
 * @file Zoomie.h
 * @brief Defines the Zoomie class, a type of Organism and a prey in the World grid.
 *
 * @class Zoomie
 *
 * @details Zoomie is a concrete implementation of the Organism class. It populates the World grid 
 * and follows its own specific set of rules for movement and breeding - reflecting its behavior 
 * as prey in the ecosystem.
 */

#include "Organism.h"

class Zoomie : public Organism
{
public:
	Zoomie();
	Zoomie(World *world, int x, int y);
	virtual ~Zoomie();

	// Implementing Organism's pure virtual functions
	virtual void breed() override;
	virtual void move() override;
	virtual int getType() override;
	virtual bool starve() override;

	// You can add more Zoomie-specific methods here if needed

protected:
	// Zoomie-specific variables can go here, if any
};
