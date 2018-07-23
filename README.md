# SunshineUnreal

These files comprise the code that I wrote for this project and are uploaded here for demonstration purposes, rather than providing the project solution in full.


ABOUT:

This project is a C++ Unreal Engine remake of the hubworld from the Gamecube game 'Super Mario Sunshine'; a third-person 3D platformer. The player explores the area looking for collectables, and cleans up messes with a watergun.

The project is currently in early development. The player actions are yet to be implemented, but classes are in place to ensure that the appropriate action method is chosen. This is dependent on the key the player presses and the state that the player character is in. For example: the space bar is bound to the jump action when the player character is walking, is bound to the 'swim up' action when the player character is swimming, and does nothing (bound to a dummy action) when the player is in midair.

I'm working on a parallel implementation of this project in Unity/C#, where the Gamecube models and animations can be more easily imported and tested. A screenshot from the Unity version is included.



PLAYER CLASSES:

MarioController - tracks the player character's condition, instantiates the input management classes, and will send events to the player state machine.



INPUT MANAGEMENT:

MarioFSM - a state machine for the player character. The states correspond to the various movement modes the player character has, and will transition based on events (such as collisions or inputs). Parallel states will track the camera mode and the player character's condition.

InputManagerComponent - holds an InputSet for each movement state the player can be in. Swaps out the 'current' set when the player character's state changes.

InputSetComponent - holds a set of possible inputs. Each input is linked via a function pointer to a PlayerAction method.

PlayerActions - holds methods for all actions the player can take.



NON-PLAYER CLASSES:

FluddComponent - tracks the water level of the player's watergun.

KillPlaneController - destructs any non-player actors that collide with the killplane. If the player hits the plane, they're teleported back to the game map.

DestroyBySpray - destroys its actor upon collision with a water-component actor (used on paint decals).

ShrinkOverTime - shrinks its actor over time and destructs it when below a certain size (used on water splashes).



