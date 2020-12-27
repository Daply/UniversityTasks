
## Lab Task No. 3

1. Create a SHIP class (ship). Include the following fields in the class description:<br>
• unique numeric identifier;
• name of the ship;
• displacement (in tons);
• type (sports, passenger, cargo, other); use an enumeration;
• the degree of deterioration of the ship;
• maximum value of the degree of deterioration of the ship;
• location of the ship (in port, on voyage, in dock); use an enumeration;
• date of arrival of the ship to the port from the voyage;
• date of arrival of the ship to the port from the dock;
  Fields: identifier, displacement, maximum value of the degree of deterioration of the ship and type cannot be changed after the object is created.<br>
  Implement:<br>
• default constructor that ensures the uniqueness of the identifier for the new object;
• a constructor that sets the values ​​of the class attributes and ensures the uniqueness of the identifier for the new object;
• a copy constructor that ensures the uniqueness of the identifier for a new object;
• get-methods for all attributes;
• set-methods for attributes: name of the ship, degree of deterioration, location of the ship, date of arrival of the ship to the port from the voyage, date of arrival of the ship to the port from repair;
• a function that outputs information about an object to a stream;
• a function that sends a ship on a voyage and receives as a parameter the date of the ship's return from the next voyage;
• a function that returns the ship to the port from the voyage; in this case, the degree of deterioration of the ship increases by a certain amount; if the maximum value of the degree of deterioration is exceeded, the ship must be sent to the dock for preventive maintenance;
• a function that sends a ship to the dock and receives as a parameter the date of the ship's return from the dock;
• a function that returns the ship to the port from the dock; in this case, the degree of deterioration of the ship must be set at a certain value;
• a friendly function of comparing the displacement of two ships for equality;

To test the performance of a class, write a test program in which constant and mutable class objects are created and all methods of the class are called. Provide in the class to handle all exceptions.

2. Create a PRG class - "role-playing character". Include the following fields in the class description:<br>
- a unique numeric identifier;
- character's name (*);
- condition (normal, weak, dead);
- race (human, gnome, elf, orc, dragon, ...) (*);
- gender (*);
- age;
- the current value of the character's health (non-negative value);
- the maximum value for the character's health (38);
An asterisk marks fields that do not change after character creation.<br>
The values ​​of the fields "state", "race" and "gender" are defined through the enum.<br>
Implement:<br>
• a constructor that sets the values ​​of immutable fields and ensures the uniqueness of the identifier for the new object; provide for the handling of all exceptional situations in the class.
• get-methods for all fields, except for the identifier;
• set-methods for changing the values ​​of those fields for which this is possible;
• output of information about the character to the output stream.
• loss of health by a character in the event of a battle with another character. When colliding with a character similar to himself, he loses 10 health units, when colliding with a character of another race, he loses 15 health units. If the percentage of the character's health becomes less than 10, the character automatically switches from the "healthy" state to the "weak" state. If the current health value is 0, the character automatically switches from any state to the "dead" state. A weakened or dead character cannot fight.
• replenishment of health by drinking a sip of living water. Each sip brings five units of health, but its amount cannot exceed the maximum value. If the percentage of the character's health becomes greater than or equal to 10, the character automatically switches from the "weak" state to the "healthy" state. A dead character cannot drink living water;
• comparison of characters by percentage of health (the ratio of the character's current health to the maximum amount of health);

To test the functionality of the PRG class, write a test program in which all the methods of the class are called. Provide in the class to handle all exceptions.