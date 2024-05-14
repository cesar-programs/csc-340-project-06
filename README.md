# CSC 340 Project 06

## Overview

This is the final group project for the CSC 340 course in Spring 2024. The goal for this programming project is to simulate an oversimplified predator-prey ecosystem. 
Specifically, this ecosystem contains only two organisms, one being the prey and the other the predator.

## Group Members

- Randolf Uy  
- Avinh Huynh  
- Cesar A. Herrera  

## Project Description

Zoomies and Swoopies live in a world composed of a 30 x 30 grid of cells. 
Only one critter may occupy a cell at a time. 
The grid is enclosed, so a critter is not allowed to move off the edges of the world. 
Time is simulated in time steps. Each critter performs some action at every time step. 


## TODO

- [ ] Create a class hierarchy with the base class Organism and two derived classes, Zoomie and Swoopie.
- [ ] Initialize the small world with 5 Swoopies and 100 Zoomies.
- [ ] After each time step, prompt the user to press Enter to move to the next time step.

## Finished
- World Tasks: getAt(), setAt()
- Organism Tasks: Initializer, checkPeripheral(), getType()
- Zoomies Tasks: getType()
- Swoopies Tasks: getType()

## Description
We have a 30x30 grid of cells. Each cell can be empty, contain a Zoomie, or contain a Swoopie.  
    - The world is enclosed, so a critter is not allowed to move off the edges of the world.  
    - Time is simulated in time steps. Each critter performs some action at every time step.  

Perception: 

- Philosophy: Streamlining of action based on perception.  
- Each critter can perform 1 action each turn.  
  - This means that we have to update the perception of each critter before they perform their action.  
  - Why Perception? Perception makes it easier to determine what actions are valid or invalid based on the surrounding.  
    - For example, a critter cannot move to a cell that is already occupied by another critter.  
    - For example, a critter cannot move to a cell that is outside the world.  
        
Perception Psuedo Code:  

- For each critter in the world:  
    - Check the cells surrounding the critter.  
      - Update the critter's perception based on the cells surrounding it.  
      - Perform the critter's action.  

The turn is complete once all organisms in the grid are able to perform their action, world is updated, and perceptions are updated.
    
